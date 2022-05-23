/* t_dcheb.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__25 = 25;

/* $Procedure      T_DCHEB ( Numeric derivative from Chebyshev fit ) */
/* Subroutine */ int t_dcheb__(D_fp func, doublereal *x, doublereal *delta, 
	integer *nterms, integer *nrtain, doublereal *f, doublereal *df)
{
    integer degp;
    doublereal left, work[25];
    extern /* Subroutine */ int chkin_(char *, ftnlen), errdp_(char *, 
	    doublereal *, ftnlen);
    doublereal right;
    extern logical failed_(void);
    extern /* Subroutine */ int chbfit_(D_fp, doublereal *, doublereal *, 
	    integer *, doublereal *, doublereal *);
    doublereal coeffs[25];
    extern /* Subroutine */ int chbint_(doublereal *, integer *, doublereal *,
	     doublereal *, doublereal *, doublereal *), sigerr_(char *, 
	    ftnlen), chkout_(char *, ftnlen), setmsg_(char *, ftnlen), 
	    errint_(char *, integer *, ftnlen);
    extern logical return_(void);
    doublereal x2s[2];

/* $ Abstract */

/*     Numerically estimate the derivative of a scalar function */
/*     at a specified point by fitting a Chebyshev expansion */
/*     to the function and differentiating the expansion. */

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

/*     None. */

/* $ Keywords */

/*     INTERPOLATION */
/*     MATH */
/*     POLYNOMIAL */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     MAXSIZ     P   Maximum number of terms in expansion. */
/*     FUNC       I   Function to be approximated. */
/*     X          I   Point at which to compute derivative. */
/*     DELTA      I   Half-width of domain of fit. */
/*     NTERMS     I   Number of terms in fitted expansion. */
/*     NRTAIN     I   Number of retained terms used for derivative. */
/*     F          O   Value of expansion at X. */
/*     DF         O   Derivative estimate at X. */

/* $ Detailed_Input */

/*     FUNC           is the function to be differentiated.  FUNC must */
/*                    accept a single, double precision input argument */
/*                    and must return a double precision value.  FUNC */
/*                    should be declared EXTERNAL in the caller of this */
/*                    routine. */


/*     X              is the point in the domain of FUNC at which the */
/*                    derivative of FUNC is to be estimated. */


/*     DELTA          is the half width of the interval over which */
/*                    FUNC is to be fitted by a Chebyshev expansion. */
/*                    The interval used is */

/*                       [ X - DELTA,  X + DELTA ] */


/*     NTERMS         is the number of terms in the Chebyshev expansion */
/*                    used to approximate FUNC. The degree of the */
/*                    expansion is NTERMS-1. */

/*     NRTAIN         is the number of retained terms in the Chebyshev */
/*                    expansion. These terms are used to compute the */
/*                    derivative estimate. NRTAIN should be at least 1 */
/*                    and cannot exceed NTERMS. */

/* $ Detailed_Output */

/*     F              is the result of evaluating the retained Chebyshev */
/*                    expansion at X. */


/*     DF             is the result of evaluating the derivative of the */
/*                    retained Chebyshev expansion at X. */


/* $ Parameters */

/*     MAXSIZ         is the maximum number of terms in the Chebyshev */
/*                    expansion. This is the maximum allowed value of */
/*                    NTERMS. */

/* $ Exceptions */

/*     1)  If NTERMS is less than 1 or greater than MAXSIZ, the error */
/*         SPICE(VALUEOUTOFRANGE) is signaled. */

/*     2)  If NRTAIN is less than 1 or greater than NTERMS, the error */
/*         SPICE(VALUEOUTOFRANGE) is signaled. */

/*     3)  If DELTA is not strictly positive the error */
/*         SPICE(VALUEOUTOFRANGE) is signaled. */

/*     4)  This routine does not attempt to ward off or diagnose */
/*         arithmetic overflows. */

/*     5)  See the routines CHBFIT and CHBINT for exceptions specific */
/*         to those routines. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine provides a numeric estimate of the derivative of */
/*     a function of one variable. The derivative is computed by */

/*        1) Fitting to the input function, over the interval */

/*              X - DELTA  :  X + DELTA */

/*           a Chebyshev expansion of a degree NTERMS-1. */

/*        2) Estimating the derivative of the function at X by */
/*           differentiating the first NRTAIN terms of the */
/*           expansion. */

/*     A heuristic comment: */

/*        It can be advantageous to use a large value of NTERMS together */
/*        with a smaller value of NRTAIN. The number of function samples */
/*        used to compute each Chebyshev coefficient is determined by */
/*        NTERMS (see the SUPPORT library routine CHBFIT for details). */
/*        Throwing away the higher-order terms of the expansion before */
/*        differentiating can remove noise from the function and improve */
/*        accuracy of the derivative estimate. */


/* $ Examples */

/*     See usage in the TSPICE routine T_DZZILU. */

/* $ Restrictions */

/*     1)  Maximum number of terms in the expansion is limited by the */
/*         parameter MAXSIZ. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 06-APR-2012 (NJB) */

/* -& */
/* $ Index_Entries */

/*     differentiate a Chebyshev expansion of a function */
/*     discrete derivative from Chebyshev fit */
/*     numeric derivative from Chebyshev fit */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */

    if (return_()) {
	return 0;
    }
    chkin_("T_DCHEB", (ftnlen)7);

/*     Check NTERMS. */

    if (*nterms < 1 || *nterms > 25) {
	setmsg_("NTERMS must be in the range 1:# but was #.", (ftnlen)42);
	errint_("#", &c__25, (ftnlen)1);
	errint_("#", nterms, (ftnlen)1);
	sigerr_("SPICE(VALUEOUTOFRANGE)", (ftnlen)22);
	chkout_("T_DCHEB", (ftnlen)7);
	return 0;
    }

/*     Check NRTAIN. */

    if (*nrtain < 1 || *nrtain > *nterms) {
	setmsg_("NRTAIN must be in the range 1:# but was #.", (ftnlen)42);
	errint_("#", nterms, (ftnlen)1);
	errint_("#", nrtain, (ftnlen)1);
	sigerr_("SPICE(VALUEOUTOFRANGE)", (ftnlen)22);
	chkout_("T_DCHEB", (ftnlen)7);
	return 0;
    }

/*     Check DELTA. */

    if (*delta <= 0.) {
	setmsg_("DELTA must be positive but was #.", (ftnlen)33);
	errdp_("#", delta, (ftnlen)1);
	sigerr_("SPICE(VALUEOUTOFRANGE)", (ftnlen)22);
	chkout_("T_DCHEB", (ftnlen)7);
	return 0;
    }

/*     Set domain bounds for Chebyshev fit: */

    left = *x - *delta;
    right = *x + *delta;

/*     Set transformation parameters: */

    x2s[0] = *x;
    x2s[1] = *delta;

/*     Fit N-term Cheby expansion to the input function on [LEFT, */
/*     RIGHT]. */

    chbfit_((D_fp)func, &left, &right, nterms, work, coeffs);
    if (failed_()) {
	chkout_("T_DCHEB", (ftnlen)7);
	return 0;
    }

/*     Find the first derivative of the expansion at X. */

    degp = *nrtain - 1;
    chbint_(coeffs, &degp, x2s, x, f, df);
    chkout_("T_DCHEB", (ftnlen)7);
    return 0;
} /* t_dcheb__ */

