/* t_spkchb.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__25 = 25;

/* $Procedure T_SPKCHB ( Test utility, fit SPK data with Chebys ) */
/* Subroutine */ int t_spkchb__(char *target, char *center, char *frame, 
	doublereal *first, doublereal *last, integer *npos, integer *nvel, 
	doublereal *work, doublereal *poscof, doublereal *velcof, ftnlen 
	target_len, ftnlen center_len, ftnlen frame_len)
{
    /* System generated locals */
    integer poscof_dim1, poscof_offset, velcof_dim1, velcof_offset, i__1;

    /* Builtin functions */
    integer s_rnge(char *, integer, char *, integer);

    /* Local variables */
    extern doublereal t_stcini__(integer *, char *, char *, integer *, ftnlen,
	     ftnlen);
    extern /* Subroutine */ int chkin_(char *, ftnlen), errch_(char *, char *,
	     ftnlen, ftnlen);
    logical found;
    extern /* Subroutine */ int bods2c_(char *, integer *, logical *, ftnlen),
	     chbfit_(D_fp, doublereal *, doublereal *, integer *, doublereal *
	    , doublereal *);
    integer centid, targid;
    extern doublereal t_getx__(), t_gety__(), t_getz__();
    doublereal retval;
    extern /* Subroutine */ int sigerr_(char *, ftnlen), chkout_(char *, 
	    ftnlen), setmsg_(char *, ftnlen), errint_(char *, integer *, 
	    ftnlen);
    extern logical return_(void);
    extern doublereal t_getdx__(), t_getdy__(), t_getdz__();

/* $ Abstract */

/*     Create Chebyshev expansions for the position and velocity */
/*     of an object whose ephemeris is given by SPK data. */

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

/*     CHEBYSHEV */
/*     FIT */
/*     POLYNOMIAL */
/*     SPK */
/*     TEST */
/*     UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     MAXSIZ     P   Maximum number of terms in expansion. */
/*     TARGET     I   Target body name. */
/*     CENTER     I   Center name. */
/*     FRAME      I   Frame name. */
/*     FIRST      I   Interval start time in seconds past J2000 TDB. */
/*     LAST       I   Interval stop time in seconds past J2000 TDB. */
/*     NPOS       I   Number of terms in position expansion. */
/*     NVEL       I   Number of terms in velocity expansion. */
/*     WORK      I-O  Workspace. */
/*     POSCOF     O   Chebyshev coefficients for position. */
/*     VELCOF     O   Chebyshev coefficients for velocity. */

/* $ Detailed_Input */

/*     TARGET         is the name of the target body. Chebyshev */
/*                    coefficients for the state of the target relative */
/*                    to the center, in the reference frame specified by */
/*                    FRAME, are computed by this routine. */

/*     CENTER         is the name of the center of motion. */

/*     FRAME          is the name of the reference frame in which to */
/*                    states are to be computed. */

/*     FIRST, */
/*     LAST           are the time bounds of the time interval over */
/*                    which the Chebyshev expansion is applicable. Times */
/*                    are expressed as seconds past J2000 TDB. */

/*     NPOS           is the number of terms in the position expansion. */
/*                    The degree of the expansion is NPOS-1. The maximum */
/*                    value of NPOS is limited by the parameter MAXSIZ. */

/*     NVEL           is the number of terms in the velocity expansion. */
/*                    The degree of the expansion is NVEL-1. The maximum */
/*                    value of NVEL is limited by the parameter MAXSIZ. */

/*     WORK           is a workspace array; this workspace is used by */
/*                    the Chebyshev fitter CHBFIT. The size of WORK must */
/*                    be at least */

/*                       MAX ( NPOS, NVEL )  +  1 */

/* $ Detailed_Output */

/*     WORK           is the workspace array, modified by this */
/*                    routine. */

/*     POSCOF         is a Chebyshev expansion of degree NPOS-1 for the */
/*                    position of TARGET with respect to CENTER, in the */
/*                    reference frame FRAME, over the time interval */
/*                    [FIRST, LAST]. */


/*     VELCOF         is the corresponding Chebyshev expansion */
/*                    for velocity. The degree is NVEL-1. */

/* $ Parameters */

/*     MAXSIZ is the maximum number of terms in either output */
/*     expansion. This parameter is declared in the support */
/*     library utility routine CHBFIT. */

/* $ Exceptions */

/*     1) If either the input target or center name cannot be mapped */
/*        to an ID code, the error SPICE(NOTRANSLATION) is signaled. */

/*     2) If either NPOS or NVEL is outside of the range 1:MAXSIZ, */
/*        the error SPICE(INVALIDCOUNT) is signaled. */

/*     3) Any exceptions that may be incurred by SPKEZ may be incurred */
/*        by this routine. */

/* $ Files */

/*     1) SPK data are required to provide the state of the target */
/*        relative to the center of motion over the time interval */
/*        [FIRST, LAST]. */

/* $ Particulars */

/*     This routine supports testing of Chebyshev-based SPK and PCK */
/*     code. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     1) The quality of the Chebyshev expansions produced by */
/*        this routine is dependent on the suitability of the */
/*        input data. Attempting to fit ephemerides over */
/*        excessively long time intervals will result in */
/*        useless outputs. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 26-NOV-2013 (NJB) */

/* -& */

/*     SPICELIB functions */


/*     Other functions */


/*     Local parameters */


/*     Local variables */

    /* Parameter adjustments */
    poscof_dim1 = *npos;
    poscof_offset = poscof_dim1 + 1;
    velcof_dim1 = *nvel;
    velcof_offset = velcof_dim1 + 1;

    /* Function Body */
    if (return_()) {
	return 0;
    }
    chkin_("T_SPKCHB", (ftnlen)8);
    bods2c_(target, &targid, &found, target_len);
    if (! found) {
	setmsg_("Target name # could not be translated to an ID code.", (
		ftnlen)52);
	errch_("#", target, (ftnlen)1, target_len);
	sigerr_("SPICE(NOTRANSLATION)", (ftnlen)20);
	chkout_("T_SPKCHB", (ftnlen)8);
	return 0;
    }
    bods2c_(center, &centid, &found, center_len);
    if (! found) {
	setmsg_("Center name # could not be translated to an ID code.", (
		ftnlen)52);
	errch_("#", center, (ftnlen)1, center_len);
	sigerr_("SPICE(NOTRANSLATION)", (ftnlen)20);
	chkout_("T_SPKCHB", (ftnlen)8);
	return 0;
    }
    if (*npos < 1 || *npos > 25) {
	setmsg_("Position coefficient count # must be in the range 1:# but w"
		"as #.", (ftnlen)64);
	errint_("#", &c__25, (ftnlen)1);
	errint_("#", npos, (ftnlen)1);
	sigerr_("SPICE(INVALIDCOUNT)", (ftnlen)19);
	chkout_("T_SPKCHB", (ftnlen)8);
	return 0;
    }
    if (*nvel < 1 || *nvel > 25) {
	setmsg_("Velocity coefficient count # must be in the range 1:# but w"
		"as #.", (ftnlen)64);
	errint_("#", &c__25, (ftnlen)1);
	errint_("#", nvel, (ftnlen)1);
	sigerr_("SPICE(INVALIDCOUNT)", (ftnlen)19);
	chkout_("T_SPKCHB", (ftnlen)8);
	return 0;
    }

/*     Initialize the state component functions. The returned */
/*     value is not used; the called function operates by */
/*     side effects. */

    retval = t_stcini__(&targid, frame, "NONE", &centid, frame_len, (ftnlen)4)
	    ;

/*     Fit the state vector components. */

    chbfit_((D_fp)t_getx__, first, last, npos, work, &poscof[(i__1 = 
	    poscof_dim1 + 1 - poscof_offset) < poscof_dim1 * 3 && 0 <= i__1 ? 
	    i__1 : s_rnge("poscof", i__1, "t_spkchb__", (ftnlen)284)]);
    chbfit_((D_fp)t_gety__, first, last, npos, work, &poscof[(i__1 = (
	    poscof_dim1 << 1) + 1 - poscof_offset) < poscof_dim1 * 3 && 0 <= 
	    i__1 ? i__1 : s_rnge("poscof", i__1, "t_spkchb__", (ftnlen)285)]);
    chbfit_((D_fp)t_getz__, first, last, npos, work, &poscof[(i__1 = 
	    poscof_dim1 * 3 + 1 - poscof_offset) < poscof_dim1 * 3 && 0 <= 
	    i__1 ? i__1 : s_rnge("poscof", i__1, "t_spkchb__", (ftnlen)286)]);
    chbfit_((D_fp)t_getdx__, first, last, nvel, work, &velcof[(i__1 = 
	    velcof_dim1 + 1 - velcof_offset) < velcof_dim1 * 3 && 0 <= i__1 ? 
	    i__1 : s_rnge("velcof", i__1, "t_spkchb__", (ftnlen)287)]);
    chbfit_((D_fp)t_getdy__, first, last, nvel, work, &velcof[(i__1 = (
	    velcof_dim1 << 1) + 1 - velcof_offset) < velcof_dim1 * 3 && 0 <= 
	    i__1 ? i__1 : s_rnge("velcof", i__1, "t_spkchb__", (ftnlen)288)]);
    chbfit_((D_fp)t_getdz__, first, last, nvel, work, &velcof[(i__1 = 
	    velcof_dim1 * 3 + 1 - velcof_offset) < velcof_dim1 * 3 && 0 <= 
	    i__1 ? i__1 : s_rnge("velcof", i__1, "t_spkchb__", (ftnlen)289)]);
    chkout_("T_SPKCHB", (ftnlen)8);
    return 0;
} /* t_spkchb__ */

