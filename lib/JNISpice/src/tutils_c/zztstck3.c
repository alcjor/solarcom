/* zztstck3.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* $Procedure ZZTSTCK3 (Create at test CK of type 3 and SCLK file) */
/* Subroutine */ int zztstck3_(char *ck, ftnlen ck_len)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_rnge(char *, integer, char *, integer);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int ckw03_(integer *, doublereal *, doublereal *, 
	    integer *, char *, logical *, char *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, ftnlen, 
	    ftnlen);
    doublereal tick[205];
    integer inst, i__, j;
    char segid[32];
    logical avflg;
    doublereal maxet;
    char error[80];
    integer nints;
    doublereal et;
    integer handle;
    extern /* Subroutine */ int dafcls_(integer *);
    doublereal tk, begtim;
    extern /* Subroutine */ int kilfil_(char *, ftnlen), shelld_(integer *, 
	    doublereal *);
    doublereal angvel[615]	/* was [3][205] */, endtim;
    integer nticks;
    extern /* Subroutine */ int tparse_(char *, doublereal *, char *, ftnlen, 
	    ftnlen), spcopn_(char *, char *, integer *, ftnlen, ftnlen), 
	    tstatd_(doublereal *, doublereal *, doublereal *);
    doublereal quatrn[820]	/* was [4][205] */, starts[1];
    extern /* Subroutine */ int m2q_(doublereal *, doublereal *);
    doublereal zeropt;
    char ref[32];
    doublereal rot[9]	/* was [3][3] */;

/* $ Abstract */

/*     Create a test type 03 C-kernel. */

/* $ Disclaimer */

/*     THIS SOFTWARE AND ANY RELATED MATERIALS WERE CREATED BY THE */
/*     CALIFORNIA INSTITUTE OF TECHNOLOGY (CALTECH) UNDER A U.S. */
/*     GOVERNMENT CONTRACT WITH THE NATIONAL AERONAUTICS AND SPACE */
/*     ADMINISTRATION (NASA). THE SOFTWARE IS TECHNOLOGY AND SOFTWARE */
/*     PUBLICLY AVAILABLE UNDER U.S. EXPORT LAWS AND IS PROVIDED "AS-IS" */
/*     TO THE RECIPIENT WITHOUT WARRANTY OF ANY KIND, INCLUDING ANY */
/*     WARRANTIES OF PERFORMANCE OR MERCHANTABILITY OR FITNESS FOR A */
/*     PARTICULAR USE OR PURPOSE (AS SET FORTH IN UNITED STATES UCC */
/*     SECTIONS 2312-2313) OR FOR ANY PURPOSE WHATSOEVER, FOR THE */
/*     SOFTWARE AND RELATED MATERIALS, HOWEVER USED. */

/*     IN NO EVENT SHALL CALTECH, ITS JET PROPULSION LABORATORY, OR NASA */
/*     BE LIABLE FOR ANY DAMAGES AND/OR COSTS, INCLUDING, BUT NOT */
/*     LIMITED TO, INCIDENTAL OR CONSEQUENTIAL DAMAGES OF ANY KIND, */
/*     INCLUDING ECONOMIC DAMAGE OR INJURY TO PROPERTY AND LOST PROFITS, */
/*     REGARDLESS OF WHETHER CALTECH, JPL, OR NASA BE ADVISED, HAVE */
/*     REASON TO KNOW, OR, IN FACT, SHALL KNOW OF THE POSSIBILITY. */

/*     RECIPIENT BEARS ALL RISK RELATING TO QUALITY AND PERFORMANCE OF */
/*     THE SOFTWARE AND ANY RELATED MATERIALS, AND AGREES TO INDEMNIFY */
/*     CALTECH AND NASA FOR ALL THIRD-PARTY CLAIMS RESULTING FROM THE */
/*     ACTIONS OF RECIPIENT IN THE USE OF THE SOFTWARE. */

/* $ Required_Reading */

/*      None. */

/* $ Keywords */

/*       TESTING */

/* $ Declarations */
/* $ Brief_I/O */

/*      VARIABLE  I/O  DESCRIPTION */
/*      --------  ---  -------------------------------------------------- */
/*      CK         I   The name of the C-kernel to create */

/* $ Detailed_Input */

/*      CK         is the name of a C-kernel to create. If a C-kernel of */
/*                 the same name already exists it is deleted. */

/* $ Detailed_Output */

/*   None. */

/* $ Parameters */

/*      None. */

/* $ Exceptions */

/*     None. */

/* $ Files */

/*      This routine creates a C-kernel with a three type 03 */
/*      segments.  See Particulars for more details. */

/* $ Particulars */

/*     This routine creates a CK for test purposes. Create the SCLK */
/*     corresponding to the CK with a ZZTSTSCLK call. */

/*     The C-kernel for the fictional objects with ID codes -9999, */
/*     -10000, and -10001 */

/*     The C-kernel contains a single segment for each of the */
/*     fictional objects.  These segments give continous attitude */
/*     over the time interval */
/*     from 1980 JAN 1, 00:00:00.000 (ET) */
/*     to   2011 SEP 9, 01:46:40.000 (ET) */
/*     (a span of exactly 1 billion seconds). */


/*     The frames of the objects are */

/*     Object    Frame */
/*     -------   -------- */
/*     -9999     Galactic */
/*     -10000    FK5 */
/*     -10001    J2000 */

/*     All three objects rotate  at a rate of 1 radian per 10 million */
/*     seconds. The axis of rotation changes every 100 million seconds. */

/*     At various epochs the axes of the objects are exactly aligned */
/*     with their associated reference frame. */

/*     Object     Aligned with reference frame at epoch */
/*     ------     ------------------------------------- */
/*     -9999      Epoch of the J2000 frame */
/*     -10000     Epoch of J2000 */
/*     -10001     Epoch of J2000 */

/*     At the moment when the frames are aligned. The are rotating */
/*     around the direction (2, 1, 3) in their associated frames. */

/*     The C-kernel contains 606 attitude instances. */

/*     The attitude and angular velocity produced by the CK software */
/*     should very nearly duplicate the results returned by the test */
/*     routine TSTATD. */

/*     More specifically suppose we set up the arrays: */

/*        ID(1)     = -9999 */
/*        ID(2)     = -10000 */
/*        ID(3)     = -10001 */


/*        FRAME(1)  = 'GALACTIC' */
/*        FRAME(2)  = 'FK4' */
/*        FRAME(3)  = 'J2000' */


/*     Then the two methods of getting ROT and AV below should */
/*     produce results that agree to nearly roundoff. */

/*     Method 1. */

/*        CALL SCE2T ( -9, ET, TICK ) */
/*        CALL CKGPAV ( ID(I), TICK, 0.0D0, FRAME(I), ROT, AV, OUT, FND ) */

/*     Method 2. */

/*        CALL TSTATD ( ET , ROT, AV ) */

/* $ Examples */

/*     This is intended to be used in those instances when you */
/*     need a well defined C-kernel whose attitude can be accurately */
/*     predicted in advance. */

/*     The routine TSTATD returns the continuous attitude and angular */
/*     velocity of the C-kernel for all time.  As such it provides */
/*     a convenient method for testing the CK software for an individual */
/*     segment. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*      None. */

/* $ Author_and_Institution */

/*      W.L. Taber      (JPL) */
/*      E.D. Wright     (JPL) */

/* $ Version */

/* -    Test Utilities 1.0.1, 18-MAY-2010 (BVS) */

/*        Removed "C$" marker from text in the header. */

/* -    Test Utilities 1.0.0, 06-DEC-2006 (EDW) */

/*        Reimplementation of TSTCK3 removing all code */
/*        except that needed to write the test CK. */

/* -& */
/* $ Index_Entries */

/*     Create test CK. */

/* -& */

/*     Inline functions. */


/*     Local Variables. */


/*     Definitions of inline functions. */


/*     The first order of business is to wipe out any existing */
/*     files with the same name. */

    kilfil_(ck, ck_len);

/*     Next create the C-kernel. Recall the relationship between */
/*     ET and encoded SCLK ticks.  There are 10000 ticks/second. */
/*     The zero point of the clock is 1 Jan 1980 TDB. */

    tparse_("1 Jan 1980", &zeropt, error, (ftnlen)10, (ftnlen)80);
    maxet = zeropt + 1e9;
    et = 0.;
    j = 0;
    while(et > zeropt) {
	++j;
	tick[(i__1 = j - 1) < 205 && 0 <= i__1 ? i__1 : s_rnge("tick", i__1, 
		"zztstck3_", (ftnlen)260)] = (et - zeropt) * 1e4;
	++j;
	tick[(i__1 = j - 1) < 205 && 0 <= i__1 ? i__1 : s_rnge("tick", i__1, 
		"zztstck3_", (ftnlen)263)] = tick[(i__2 = j - 2) < 205 && 0 <=
		 i__2 ? i__2 : s_rnge("tick", i__2, "zztstck3_", (ftnlen)263)]
		 - 1.;
	et += -1e7;
    }
    ++j;
    tick[(i__1 = j - 1) < 205 && 0 <= i__1 ? i__1 : s_rnge("tick", i__1, 
	    "zztstck3_", (ftnlen)270)] = 0.;
    et = 1e7;
    while(et < maxet) {
	++j;
	tick[(i__1 = j - 1) < 205 && 0 <= i__1 ? i__1 : s_rnge("tick", i__1, 
		"zztstck3_", (ftnlen)278)] = (et - zeropt) * 1e4;
	++j;
	tick[(i__1 = j - 1) < 205 && 0 <= i__1 ? i__1 : s_rnge("tick", i__1, 
		"zztstck3_", (ftnlen)281)] = tick[(i__2 = j - 2) < 205 && 0 <=
		 i__2 ? i__2 : s_rnge("tick", i__2, "zztstck3_", (ftnlen)281)]
		 - 1.;
	et += 1e7;
    }
    ++j;
    tick[(i__1 = j - 1) < 205 && 0 <= i__1 ? i__1 : s_rnge("tick", i__1, 
	    "zztstck3_", (ftnlen)288)] = (maxet - zeropt) * 1e4;
    nticks = j;

/*     Sort the ticks. */

    shelld_(&nticks, tick);
    begtim = tick[0];
    endtim = tick[(i__1 = nticks - 1) < 205 && 0 <= i__1 ? i__1 : s_rnge(
	    "tick", i__1, "zztstck3_", (ftnlen)298)];
    inst = -9999;
    s_copy(ref, "GALACTIC", (ftnlen)32, (ftnlen)8);
    avflg = TRUE_;
    s_copy(segid, "Test Segment for object -9999", (ftnlen)32, (ftnlen)29);
    i__1 = nticks;
    for (i__ = 1; i__ <= i__1; ++i__) {
	tk = tick[(i__2 = i__ - 1) < 205 && 0 <= i__2 ? i__2 : s_rnge("tick", 
		i__2, "zztstck3_", (ftnlen)307)];
	et = zeropt + tk / 1e4;
	tstatd_(&et, rot, &angvel[(i__2 = i__ * 3 - 3) < 615 && 0 <= i__2 ? 
		i__2 : s_rnge("angvel", i__2, "zztstck3_", (ftnlen)309)]);
	m2q_(rot, &quatrn[(i__2 = (i__ << 2) - 4) < 820 && 0 <= i__2 ? i__2 : 
		s_rnge("quatrn", i__2, "zztstck3_", (ftnlen)310)]);
    }
    nints = 1;
    starts[0] = 0.;
    spcopn_(ck, "Test C-kernel", &handle, ck_len, (ftnlen)13);
    ckw03_(&handle, &begtim, &endtim, &inst, ref, &avflg, segid, &nticks, 
	    tick, quatrn, angvel, &nints, starts, (ftnlen)32, (ftnlen)32);

/*     Now create a second segment by simply taking that attitude */
/*     10 million seconds later than those for body -9999 */

    begtim = tick[0];
    endtim = tick[(i__1 = nticks - 1) < 205 && 0 <= i__1 ? i__1 : s_rnge(
	    "tick", i__1, "zztstck3_", (ftnlen)327)];
    inst = -10000;
    s_copy(ref, "FK4", (ftnlen)32, (ftnlen)3);
    avflg = TRUE_;
    s_copy(segid, "Object -10000", (ftnlen)32, (ftnlen)13);
    i__1 = nticks;
    for (i__ = 1; i__ <= i__1; ++i__) {
	tk = tick[(i__2 = i__ - 1) < 205 && 0 <= i__2 ? i__2 : s_rnge("tick", 
		i__2, "zztstck3_", (ftnlen)336)];
	et = zeropt + tk / 1e4;
	tstatd_(&et, rot, &angvel[(i__2 = i__ * 3 - 3) < 615 && 0 <= i__2 ? 
		i__2 : s_rnge("angvel", i__2, "zztstck3_", (ftnlen)338)]);
	m2q_(rot, &quatrn[(i__2 = (i__ << 2) - 4) < 820 && 0 <= i__2 ? i__2 : 
		s_rnge("quatrn", i__2, "zztstck3_", (ftnlen)339)]);
    }
    nints = 1;
    starts[0] = 0.;
    ckw03_(&handle, &begtim, &endtim, &inst, ref, &avflg, segid, &nticks, 
	    tick, quatrn, angvel, &nints, starts, (ftnlen)32, (ftnlen)32);

/*     Finally for the third segment take take the same attitudes */
/*     but 100 million seconds later than those for object -9999 */

    begtim = tick[0];
    endtim = tick[(i__1 = nticks - 1) < 205 && 0 <= i__1 ? i__1 : s_rnge(
	    "tick", i__1, "zztstck3_", (ftnlen)356)];
    inst = -10001;
    s_copy(ref, "J2000", (ftnlen)32, (ftnlen)5);
    avflg = TRUE_;
    s_copy(segid, "Test Segment for object -10001", (ftnlen)32, (ftnlen)30);
    i__1 = nticks;
    for (i__ = 1; i__ <= i__1; ++i__) {
	tk = tick[(i__2 = i__ - 1) < 205 && 0 <= i__2 ? i__2 : s_rnge("tick", 
		i__2, "zztstck3_", (ftnlen)365)];
	et = zeropt + tk / 1e4;
	tstatd_(&et, rot, &angvel[(i__2 = i__ * 3 - 3) < 615 && 0 <= i__2 ? 
		i__2 : s_rnge("angvel", i__2, "zztstck3_", (ftnlen)367)]);
	m2q_(rot, &quatrn[(i__2 = (i__ << 2) - 4) < 820 && 0 <= i__2 ? i__2 : 
		s_rnge("quatrn", i__2, "zztstck3_", (ftnlen)368)]);
    }
    nints = 1;
    starts[0] = 0.;
    ckw03_(&handle, &begtim, &endtim, &inst, ref, &avflg, segid, &nticks, 
	    tick, quatrn, angvel, &nints, starts, (ftnlen)32, (ftnlen)32);

/*     Finis. Safely close the DAF. */

    dafcls_(&handle);
    return 0;
} /* zztstck3_ */

