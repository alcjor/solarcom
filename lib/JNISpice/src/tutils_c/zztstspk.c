/* zztstspk.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* $Procedure ZZTSTSPK ( Create an SPK file for use in testing) */
/* Subroutine */ int zztstspk_(char *file, ftnlen file_len)
{
    integer body;
    doublereal last, step;
    integer i__, n;
    char frame[32], segid[32];
    doublereal epoch, first;
    extern /* Subroutine */ int spkw05_(integer *, integer *, integer *, char 
	    *, doublereal *, doublereal *, char *, doublereal *, integer *, 
	    doublereal *, doublereal *, ftnlen, ftnlen), spkw08_(integer *, 
	    integer *, integer *, char *, doublereal *, doublereal *, char *, 
	    integer *, integer *, doublereal *, doublereal *, doublereal *, 
	    ftnlen, ftnlen), tstst_(integer *, doublereal *, char *, integer *
	    , doublereal *, integer *, doublereal *, ftnlen);
    doublereal gm;
    integer degree, handle;
    extern /* Subroutine */ int dafcls_(integer *), kilfil_(char *, ftnlen);
    integer center;
    extern /* Subroutine */ int frmnam_(integer *, char *, ftnlen), spcopn_(
	    char *, char *, integer *, ftnlen, ftnlen);
    doublereal states[12]	/* was [6][2] */;
    extern /* Subroutine */ int tststc_(integer *, integer *);
    integer ref;

/* $ Abstract */

/*     Create an SPK file that can be used for obtaining */
/*     states and testing code that makes use of the SPK system */

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
/*       SPK */

/* $ Declarations */
/* $ Brief_I/O */

/*      VARIABLE  I/O  DESCRIPTION */
/*      --------  ---  -------------------------------------------------- */
/*      FILE       I   The name of an SPK file to create. */

/* $ Detailed_Input */

/*     FILE        is the name of an SPK file to create for use in */
/*                 software testing.  This SPK is not a good model */
/*                 for the solar system. */

/*                 If the file specified already exists, the existing */
/*                 file is deleted and a new one created with the */
/*                 same name in its place. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*      None. */

/* $ Exceptions */

/*     1) If the specified file already exists, it is deleted and */
/*        replaced by the file created by this routine. */

/*    2) All other exceptions are diagnosed by routines in the call tree */
/*        of this routine. */

/* $ Files */

/*      This routine creates an SPK file with ephemeris information */
/*      for the following objects. */

/*           SUN */
/*              MERCURY */
/*                 MERCURY_BARYCENTER */
/*              VENUS_BARYCENTER */
/*                 VENUS */
/*              EARTH-MOON-BARYCENTER */
/*                 EARTH */
/*                    GOLDSTONE_TRACKING_STATION */
/*                    MADRID_TRACKING_STATION */
/*                    CANBERRA_TRACKING_STATION */
/*                    MOON */
/*                       SPACECRAFT_PHOENIX */
/*                       TRANQUILITY_BASE */
/*              MARS_BARYCENTER */
/*                 MARS */
/*                    PHOBOS */
/*                       PHOBOS_BASECAMP */
/*                    DEIMOS */
/*              JUPITER_BARYCENTER */
/*                 JUPITER */
/*                    IO */
/*                    EUROPA */
/*                    GANYMEDE */
/*                    CALLISTO */
/*              SATURN_BARYCENTER */
/*                 SATURN */

/*                    TITAN */
/*              URANUS_BARYCENTER */
/*                 URANUS */
/*                    OBERON */
/*                    ARIEL */
/*                    UMBRIEL */
/*                    TITANIA */
/*                    MIRANDA */
/*              NEPTUNE_BARYCENTER */
/*                 NEPTUNE */
/*                    TRITON */
/*                    NEREID */
/*              PLUTO_BARYCENTER */
/*                 PLUTO */
/*                    CHARON */


/* $ Particulars */

/*     This routine creates a "TOY" solar system model for use */
/*     in testing the SPICE ephemeris system. */

/*     The data in this file is "good" for the epochs */

/*        from 1980 JAN 1, 00:00:00.000 (ET) */
/*        to   2011 SEP 9, 01:46:40.000 (ET) */
/*        (a span of exactly 1 billion seconds). */


/*     If the input file already exists, it is deleted prior to the */
/*     creation of this file. */

/* $ Examples */

/*     The normal way to use this routine is shown below. */

/*     CALL ZZTSTSPK ( 'sstoy.bsp' ) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*      None. */

/* $ Author_and_Institution */

/*      W.L. Taber      (JPL) */

/* $ Version */

/* -    Test Utilities 1.0.1, 05-NOV-2007 (EDW) */

/*        Minor header edits. No affect on functionality. */

/* -    Test Utilities 1.0.0, 07-JAN-2006 (EDW) */

/*        Reimplementation of TSTSPK removing all code */
/*        except that needed to write the test SPK. */

/* -& */
/* $ Index_Entries */

/*     Create an SPK file for high-level software tests */

/* -& */

/*     Local Variables. */


/*     Wipe out any existing file with the target name.  Then open */
/*     a new SPC file for writing. */

    kilfil_(file, file_len);
    spcopn_(file, "TestUtilitySPK", &handle, file_len, (ftnlen)14);

/*     Now just construct the state information needed  to create */
/*     segments for all of the various objects that we are going */
/*     to simulate. */

    epoch = -189345600.f;
    i__ = 1;
    tststc_(&i__, &body);
    while(body != 0) {
	tstst_(&body, &epoch, segid, &ref, states, &center, &gm, (ftnlen)32);
	frmnam_(&ref, frame, (ftnlen)32);
	if (gm > 0.) {
	    first = -5e8;
	    last = 5e8;
	    n = 1;
	    spkw05_(&handle, &body, &center, frame, &first, &last, segid, &gm,
		     &n, states, &epoch, (ftnlen)32, (ftnlen)32);
	} else {
	    first = -5e8;
	    last = 5e8;
	    n = 2;
	    step = 1e9;
	    degree = 1;
	    states[6] = states[0];
	    states[7] = states[1];
	    states[8] = states[2];
	    states[9] = states[3];
	    states[10] = states[4];
	    states[11] = states[5];
	    spkw08_(&handle, &body, &center, frame, &first, &last, segid, &
		    degree, &n, states, &first, &step, (ftnlen)32, (ftnlen)32)
		    ;
	}
	++i__;
	tststc_(&i__, &body);
    }
    dafcls_(&handle);
    return 0;
} /* zztstspk_ */

