/* t_getsa.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;
static integer c__3 = 3;
static integer c__6 = 6;

/* $Procedure      T_GETSA ( Test utility, get stellar aberration ) */
/* Subroutine */ int t_getsa__(integer *targ, doublereal *et, char *ref, char 
	*abcorr, integer *obs, doublereal *pcorr, doublereal *dpcorr, ftnlen 
	ref_len, ftnlen abcorr_len)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_rnge(char *, integer, char *, integer);

    /* Local variables */
    extern /* Subroutine */ int vequ_(doublereal *, doublereal *);
    integer type__;
    logical xmit;
    extern /* Subroutine */ int mxvg_(doublereal *, doublereal *, integer *, 
	    integer *, doublereal *), zzstelab_(logical *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *);
    integer i__;
    extern /* Subroutine */ int zzprscor_(char *, logical *, ftnlen);
    doublereal t, delta;
    extern /* Subroutine */ int chkin_(char *, ftnlen), errch_(char *, char *,
	     ftnlen, ftnlen);
    logical found;
    doublereal state[6], ltssb, stobs[12]	/* was [6][2] */, xform[36]	
	    /* was [6][6] */, stctr[6];
    extern logical failed_(void);
    doublereal lt;
    integer center;
    logical attblk[6];
    extern /* Subroutine */ int namfrm_(char *, integer *, ftnlen), frinfo_(
	    integer *, integer *, integer *, integer *, logical *), spkgeo_(
	    integer *, doublereal *, char *, integer *, doublereal *, 
	    doublereal *, ftnlen);
    doublereal ltcent, dltctr, ssbobs[6];
    integer reqfrm;
    doublereal sastat[6], ltsign;
    integer typeid;
    extern /* Subroutine */ int qderiv_(integer *, doublereal *, doublereal *,
	     doublereal *, doublereal *), spkltc_(integer *, doublereal *, 
	    char *, char *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, ftnlen, ftnlen), setmsg_(char *, ftnlen), spkssb_(
	    integer *, doublereal *, char *, doublereal *, ftnlen), sigerr_(
	    char *, ftnlen);
    doublereal xstate[6];
    extern /* Subroutine */ int chkout_(char *, ftnlen), vsclip_(doublereal *,
	     doublereal *), sxform_(char *, char *, doublereal *, doublereal *
	    , ftnlen, ftnlen);
    doublereal acc[3], dlt;

/* $ Abstract */

/*     Return the stellar aberration offset vector and the time */
/*     derivative of this offset for specified SPKEZR inputs. */

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

/*     SPK */

/* $ Keywords */

/*     TEST */
/*     UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     TARG       I   Target body ID code. */
/*     ET         I   Epoch. */
/*     REF        I   Reference frame name. */
/*     ABCORR     I   Aberration correction. */
/*     OBS        I   Observer ID code. */
/*     PCORR      O   Stellar aberration offset. */
/*     DPCORR     O   Velocity of stellar aberration offset. */

/* $ Detailed_Input */

/*     TARG           is the NAIF ID code of the target body. */

/*     ET             is the time at which to evaluate the state vector */
/*                    with which the specified stellar aberration */
/*                    correction is associated. ET is expressed as */
/*                    seconds past J2000 TDB. */

/*     REF            is the reference frame in which to compute a state */
/*                    and corresponding stellar aberration correction. */

/*                    REF need not be inertial. */

/*     ABCORR         is an aberration correction specification */
/*                    string. Any value acceptable to SPKEZ */
/*                    may be used. */

/*     OBS            is the NAIF ID of the observer body. */

/* $ Detailed_Output */

/*     PCORR       is the stellar aberration correction for the position */
/*                 component of the state defined by the input */
/*                 arguments. Adding PCORR to this position vector */
/*                 produces the input observer-target position, */
/*                 corrected for stellar aberration. */

/*                 Units are km. */

/*     DPCORR      is the stellar aberration correction for the velocity */
/*                 component of the state defined by the input */
/*                 arguments. Adding DPCORR to this velocity vector */
/*                 produces the input observer-target velocity, */
/*                 corrected for stellar aberration. */

/*                 Units are km/s. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any exceptions incurred by ZZPRSCOR may be incurred */
/*        by this routine. */

/*     2) Any exceptions incurred by SPKLTC may be incurred */
/*        by this routine. */

/*     3) Any exceptions incurred by ZZSTELAB may be incurred */
/*        by this routine. */

/* $ Files */

/*     See the Files section of the header of SPKEZ. */

/* $ Particulars */

/*     This routine mimics the aberration correction logic of SPKACS: the */
/*     acceleration of the observer with respect to the solar system */
/*     barycenter is computed, an optionally light time corrected state */
/*     is computed using SPKLTC, then this state and the acceleration of */
/*     the observer with respect to the solar system barycenter are used */
/*     as inputs to the stellar aberration correction computation. */

/* $ Examples */

/*     See the test utility package T_TRAJFN for usage */
/*     examples. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 29-DEC-2007 (NJB) */

/* -& */

/*     SPICELIB functions */

/* $ Abstract */

/*     Include file zzabcorr.inc */

/*     SPICE private file intended solely for the support of SPICE */
/*     routines.  Users should not include this file directly due */
/*     to the volatile nature of this file */

/*     The parameters below define the structure of an aberration */
/*     correction attribute block. */

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

/* $ Parameters */

/*     An aberration correction attribute block is an array of logical */
/*     flags indicating the attributes of the aberration correction */
/*     specified by an aberration correction string.  The attributes */
/*     are: */

/*        - Is the correction "geometric"? */

/*        - Is light time correction indicated? */

/*        - Is stellar aberration correction indicated? */

/*        - Is the light time correction of the "converged */
/*          Newtonian" variety? */

/*        - Is the correction for the transmission case? */

/*        - Is the correction relativistic? */

/*    The parameters defining the structure of the block are as */
/*    follows: */

/*       NABCOR    Number of aberration correction choices. */

/*       ABATSZ    Number of elements in the aberration correction */
/*                 block. */

/*       GEOIDX    Index in block of geometric correction flag. */

/*       LTIDX     Index of light time flag. */

/*       STLIDX    Index of stellar aberration flag. */

/*       CNVIDX    Index of converged Newtonian flag. */

/*       XMTIDX    Index of transmission flag. */

/*       RELIDX    Index of relativistic flag. */

/*    The following parameter is not required to define the block */
/*    structure, but it is convenient to include it here: */

/*       CORLEN    The maximum string length required by any aberration */
/*                 correction string */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 18-DEC-2004 (NJB) */

/* -& */
/*     Number of aberration correction choices: */


/*     Aberration correction attribute block size */
/*     (number of aberration correction attributes): */


/*     Indices of attributes within an aberration correction */
/*     attribute block: */


/*     Maximum length of an aberration correction string: */


/*     End of include file zzabcorr.inc */


/*     Local parameters */


/*     Local variables */

    chkin_("T_GETSA", (ftnlen)7);

/*     Compute the corrections in the J2000 frame. We'll */
/*     transform them later to the requested frame. */

    zzprscor_(abcorr, attblk, abcorr_len);
    xmit = attblk[4];
    delta = 1.;

/*     Determine the acceleration of the observer with */
/*     respect to the solar system barycenter at ET. */
/*     Use a quadratic estimate. */

    for (i__ = 1; i__ <= 2; ++i__) {
	t = *et + ((i__ << 1) - 3) * delta;
	spkgeo_(obs, &t, "J2000", &c__0, &stobs[(i__1 = i__ * 6 - 6) < 12 && 
		0 <= i__1 ? i__1 : s_rnge("stobs", i__1, "t_getsa__", (ftnlen)
		221)], &ltssb, (ftnlen)5);
    }
    qderiv_(&c__3, &stobs[3], &stobs[9], &delta, acc);

/*     Get the light-time corrected state of the target with respect */
/*     to the observer. Also get the geometric state of the observer */
/*     with respect to the solar system barycenter at ET. */

    spkssb_(obs, et, "J2000", ssbobs, (ftnlen)5);
    spkltc_(targ, et, "J2000", abcorr, ssbobs, state, &lt, &dlt, (ftnlen)5, 
	    abcorr_len);

/*     Get the stellar aberration correction and its time derivative. */
/*     Note that the input observer state relative to the solar system */
/*     barycenter was obtained from SPKLTC. */

    zzstelab_(&xmit, acc, &ssbobs[3], state, pcorr, dpcorr);

/*     Get the transformation from J2000 to the request frame. This */
/*     transformation should be evaluated at the light-time corrected */
/*     epoch associated with the center of the request frame. */

    namfrm_(ref, &reqfrm, ref_len);
    if (reqfrm == 0) {
	setmsg_("The requested output frame '#' is not recognized by the ref"
		"erence frame subsystem.  Please check that the appropriate k"
		"ernels have been loaded and that you have correctly entered "
		"the name of the output frame. ", (ftnlen)209);
	errch_("#", ref, (ftnlen)1, ref_len);
	sigerr_("SPICE(UNKNOWNFRAME)", (ftnlen)19);
	chkout_("T_GETSA", (ftnlen)7);
	return 0;
    }

/*     If we reach this point, FOUND will be .TRUE. after */
/*     the following call to FRINFO: */

    frinfo_(&reqfrm, &center, &type__, &typeid, &found);

/*     Get light time to the frame's center. */

    if (center == *obs) {
	ltcent = 0.;
	dltctr = 0.;
    } else if (center == *targ) {
	ltcent = lt;
	dltctr = dlt;
    } else {
	spkltc_(&center, et, "J2000", abcorr, ssbobs, stctr, &ltcent, &dltctr,
		 (ftnlen)5, abcorr_len);
    }

/*        If something went wrong (like we couldn't get the state of */
/*        the center relative to the observer) now it is time to quit. */

    if (failed_()) {
	chkout_("T_GETSA", (ftnlen)7);
	return 0;
    }

/*     If the aberration corrections are for transmission, make the sign */
/*     of the light time positive, since we wish to compute the */
/*     orientation of the non-inertial frame at an epoch later than ET */
/*     by the one-way light time. */

    if (xmit) {
	ltsign = 1.;
    } else {
	ltsign = -1.;
    }

/*     Look up the transformation from J2000 to REF at the light time */
/*     corrected epoch. */

    d__1 = *et + ltsign * ltcent;
    sxform_("J2000", ref, &d__1, xform, (ftnlen)5, ref_len);
    if (failed_()) {
	chkout_("T_GETSA", (ftnlen)7);
	return 0;
    }

/*     The frame rotation we wish to apply is of the form */

/*        R(t) */

/*     where */

/*        t = ET + LTSIGN*LTCENT(ET) */

/*     since the light time from the frame center to the */
/*     observer LTCENT is a function of ET. So */

/*                              | */
/*        d(R)/d(ET) = d(R)/d(t)|                  * (1 + d(t)/d(ET)) */
/*                              |t=ET+LTSIGN*LTCENT */


/*                              | */
/*                   = d(R)/d(t)|                  * (1 + LTSIGN*DLTCTR) */
/*                              |t=ET+LTSIGN*LTCENT */

/*     Scale the derivative block of the transformation to account */
/*     for the rate of change of light time. */

    for (i__ = 1; i__ <= 3; ++i__) {
	d__1 = ltsign * dltctr + 1.;
	vsclip_(&d__1, &xform[(i__1 = i__ * 6 - 3) < 36 && 0 <= i__1 ? i__1 : 
		s_rnge("xform", i__1, "t_getsa__", (ftnlen)348)]);
    }

/*     Now apply the transformation to the stellar aberration */
/*     correction position and velocity. We'll pack these */
/*     components together as a state to simplify the multiplication. */

    vequ_(pcorr, sastat);
    vequ_(dpcorr, &sastat[3]);
    mxvg_(xform, sastat, &c__6, &c__6, xstate);

/*     Now unpack the stellar aberration correction components. */

    vequ_(xstate, pcorr);
    vequ_(&xstate[3], dpcorr);
    chkout_("T_GETSA", (ftnlen)7);
    return 0;
} /* t_getsa__ */

