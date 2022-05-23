/* t_chbigr.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* $Procedure  T_CHBIGR ( Test utility: integrate Chebyshev expansion  ) */
/* Subroutine */ int t_chbigr__(integer *ndim, integer *degp, doublereal *cp, 
	doublereal *x2s, doublereal *x, doublereal *work, doublereal *p, 
	doublereal *itgrlp)
{
    /* System generated locals */
    integer cp_dim1, cp_dim2, cp_offset, work_dim1, work_offset, p_dim1, 
	    itgrlp_dim1, i__1, i__2, i__3, i__4, i__5, i__6, i__7, i__8;

    /* Builtin functions */
    integer s_rnge(char *, integer, char *, integer);

    /* Local variables */
    integer i__, n;
    doublereal x0, radius, midpnt;
    integer nterms;
    extern logical return_(void);
    integer dix;

/* $ Abstract */

/*     This is a test utility that provides an alternate method of */
/*     computation for Chebyshev expansion integration. */

/*     Evaluate an indefinite integral of a set of Chebyshev expansions */
/*     at a specified point. The constants of integration are selected */
/*     to make each integral zero at the abscissa value X2S(1). Return */
/*     the values of the input expansions as well. */

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

/*     CHEBYSHEV */
/*     EPHEMERIS */
/*     MATH */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     NDIM       I   Dimension of input vector-valued function. */
/*     DEGP       I   Degree of input Chebyshev expansions. */
/*     CP         I   Chebyshev coefficients of input expansions. */
/*     X2S        I   Transformation parameters. */
/*     X          I   Abscissa value of evaluation. */
/*     WORK      I/O  Workspace. */
/*     P          O   Vector-valued function at X. */
/*     ITGRLP     O   Vector-valued integral at X. */

/* $ Detailed_Input */

/*     NDIM       is the number of input expansions. */

/*     DEGP       is the degree of the input Chebyshev expansion. */

/*     CP         is an array containing the coefficients of the input */
/*                Chebyshev expansions. For the Jth dimension, the */
/*                coefficient of the Ith Chebyshev polynomial is */
/*                contained in element CP(I-1,J), for I = 1 : DEGP+1. */

/*     X2S        is an array containing the "transformation parameters" */
/*                of the domain of the expansion. Element X2S(1) */
/*                contains the midpoint of the interval on which the */
/*                input is defined; X2S(2) is one-half of the length of */
/*                this interval; this value is called the interval's */
/*                "radius." */

/*                The Jth input expansion defines a function f(X) on the */
/*                interval */

/*                   [ X2S(1)-X2S(2),  X2S(1)+X2S(2) ] */

/*                as follows: */

/*                   Define S = ( X - X2S(1) ) / X2S(2) */


/*                                  DEGP+1 */
/*                                  __ */
/*                                  \ */
/*                   f(X) = g(S)  = /  CP(k,J)  T   (S) */
/*                                  --           k-1 */
/*                                  k=1 */


/*     X          is the abscissa value at which the functions defined by */
/*                the input expansions and their integrals are to be */
/*                evaluated. Normally X should lie in the closed */
/*                interval */

/*                   [ X2S(1)-X2S(2),  X2S(1)+X2S(2) ] */

/*                See the Restrictions section below. */


/*     WORK       is a workspace array. WORK should be declared */
/*                with dimension (DEGP+2,2). */

/* $ Detailed_Output */

/*     WORK       is the workspace array, modified by this routine. */

/*     P          is an array containing the results of evaluating at X */
/*                the functions represented by the input expansions. The */
/*                Jth element of P is the expansion CP(*,J) evaluated at */
/*                S, where. */

/*                   S = ( X - X2S(1) ) / X2S(2) */

/*     ITGRLP     is an array containing the results of evaluating at X */
/*                the functions represented by the indefinite integrals */
/*                of the input expansions. */

/*                Constants of integration are chosen so that each */
/*                integral is zero at X = X2S(1). */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine provides an alternate algorithm for computing */
/*     the results produced by the SPICELIB routine CHBIGR. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 23-NOV-2013 (NJB) */

/* -& */
/* $ Index_Entries */


/*     integral of chebyshev_polynomial_expansion */
/*     integrate chebyshev_polynomial_expansion */

/* -& */

/*     SPICELIB functions */


/*     Local variables */

    /* Parameter adjustments */
    itgrlp_dim1 = *ndim;
    p_dim1 = *ndim;
    work_dim1 = *degp + 2;
    work_offset = work_dim1 + 1;
    cp_dim1 = *degp + 1;
    cp_dim2 = *ndim;
    cp_offset = cp_dim1 + 1;

    /* Function Body */
    if (return_()) {
	return 0;
    }
    nterms = *degp + 1;

/*     Transform the independent variable X to the interval */

/*        [-1, 1] */

/*     Call the result X0. */

    midpnt = x2s[0];
    radius = x2s[1];
    x0 = (*x - midpnt) / radius;

/*     Calculate the values of the Chebyshev polynomials */

/*        T  ... T */
/*         0      DEGP */

/*     at X0. Store these values in WORK(*,1). Also evaluate these */
/*     polynomials at 0 and store the values in WORK(*,2). */

    work[(i__1 = work_dim1 + 1 - work_offset) < work_dim1 << 1 && 0 <= i__1 ? 
	    i__1 : s_rnge("work", i__1, "t_chbigr__", (ftnlen)238)] = 1.;
    work[(i__1 = work_dim1 + 2 - work_offset) < work_dim1 << 1 && 0 <= i__1 ? 
	    i__1 : s_rnge("work", i__1, "t_chbigr__", (ftnlen)239)] = x0;
    work[(i__1 = (work_dim1 << 1) + 1 - work_offset) < work_dim1 << 1 && 0 <= 
	    i__1 ? i__1 : s_rnge("work", i__1, "t_chbigr__", (ftnlen)241)] = 
	    1.;
    work[(i__1 = (work_dim1 << 1) + 2 - work_offset) < work_dim1 << 1 && 0 <= 
	    i__1 ? i__1 : s_rnge("work", i__1, "t_chbigr__", (ftnlen)242)] = 
	    0.;
    i__1 = nterms + 1;
    for (i__ = 3; i__ <= i__1; ++i__) {

/*        Compute */

/*           T   ( X0 ) */
/*            I-1 */

/*        and */

/*           T */
/*            I-1 ( 0 ) */


	work[(i__2 = i__ + work_dim1 - work_offset) < work_dim1 << 1 && 0 <= 
		i__2 ? i__2 : s_rnge("work", i__2, "t_chbigr__", (ftnlen)259)]
		 = -work[(i__3 = i__ - 2 + work_dim1 - work_offset) < 
		work_dim1 << 1 && 0 <= i__3 ? i__3 : s_rnge("work", i__3, 
		"t_chbigr__", (ftnlen)259)] + x0 * 2 * work[(i__4 = i__ - 1 + 
		work_dim1 - work_offset) < work_dim1 << 1 && 0 <= i__4 ? i__4 
		: s_rnge("work", i__4, "t_chbigr__", (ftnlen)259)];
	work[(i__2 = i__ + (work_dim1 << 1) - work_offset) < work_dim1 << 1 &&
		 0 <= i__2 ? i__2 : s_rnge("work", i__2, "t_chbigr__", (
		ftnlen)261)] = -work[(i__3 = i__ - 2 + (work_dim1 << 1) - 
		work_offset) < work_dim1 << 1 && 0 <= i__3 ? i__3 : s_rnge(
		"work", i__3, "t_chbigr__", (ftnlen)261)];
    }

/*     Compute the definite integral for each expansion. Evaluate each */
/*     expansion as well. */

    i__1 = *ndim;
    for (dix = 1; dix <= i__1; ++dix) {
	itgrlp[(i__2 = dix - 1) < itgrlp_dim1 && 0 <= i__2 ? i__2 : s_rnge(
		"itgrlp", i__2, "t_chbigr__", (ftnlen)271)] = 0.;
	p[(i__2 = dix - 1) < p_dim1 && 0 <= i__2 ? i__2 : s_rnge("p", i__2, 
		"t_chbigr__", (ftnlen)272)] = 0.;

/*        The integrals of the remaining terms are obtained from the */
/*        formula */

/*                                     1             1 */
/*           [I (T )](x) =  (1/2) * ( --- T   (x) - --- T   (x) ) */
/*                n                   n+1  n+1      n-1  n-1 */

/*                                    1              1 */
/*                        - (1/2) * ( --- T   (0) - --- T   (0) ) */
/*                                    n+1  n+1      n-1  n-1 */


	for (i__ = nterms; i__ >= 3; --i__) {

/*           Add on the next term of the expansion. */

	    p[(i__2 = dix - 1) < p_dim1 && 0 <= i__2 ? i__2 : s_rnge("p", 
		    i__2, "t_chbigr__", (ftnlen)290)] = p[(i__3 = dix - 1) < 
		    p_dim1 && 0 <= i__3 ? i__3 : s_rnge("p", i__3, "t_chbigr"
		    "__", (ftnlen)290)] + cp[(i__4 = i__ + dix * cp_dim1 - 
		    cp_offset) < cp_dim1 * cp_dim2 && 0 <= i__4 ? i__4 : 
		    s_rnge("cp", i__4, "t_chbigr__", (ftnlen)290)] * work[(
		    i__5 = i__ + work_dim1 - work_offset) < work_dim1 << 1 && 
		    0 <= i__5 ? i__5 : s_rnge("work", i__5, "t_chbigr__", (
		    ftnlen)290)];

/*           Add on the next term of the integral. */

	    n = i__ - 1;
	    itgrlp[(i__2 = dix - 1) < itgrlp_dim1 && 0 <= i__2 ? i__2 : 
		    s_rnge("itgrlp", i__2, "t_chbigr__", (ftnlen)297)] = 
		    itgrlp[(i__3 = dix - 1) < itgrlp_dim1 && 0 <= i__3 ? i__3 
		    : s_rnge("itgrlp", i__3, "t_chbigr__", (ftnlen)297)] + cp[
		    (i__4 = i__ + dix * cp_dim1 - cp_offset) < cp_dim1 * 
		    cp_dim2 && 0 <= i__4 ? i__4 : s_rnge("cp", i__4, "t_chbi"
		    "gr__", (ftnlen)297)] * (.5 / (n + 1) * (work[(i__5 = n + 
		    2 + work_dim1 - work_offset) < work_dim1 << 1 && 0 <= 
		    i__5 ? i__5 : s_rnge("work", i__5, "t_chbigr__", (ftnlen)
		    297)] - work[(i__6 = n + 2 + (work_dim1 << 1) - 
		    work_offset) < work_dim1 << 1 && 0 <= i__6 ? i__6 : 
		    s_rnge("work", i__6, "t_chbigr__", (ftnlen)297)]) - .5 / (
		    n - 1) * (work[(i__7 = n + work_dim1 - work_offset) < 
		    work_dim1 << 1 && 0 <= i__7 ? i__7 : s_rnge("work", i__7, 
		    "t_chbigr__", (ftnlen)297)] - work[(i__8 = n + (work_dim1 
		    << 1) - work_offset) < work_dim1 << 1 && 0 <= i__8 ? i__8 
		    : s_rnge("work", i__8, "t_chbigr__", (ftnlen)297)]));
	}
	if (nterms >= 2) {

/*           Add on the first two terms of the expansion. */

	    p[(i__2 = dix - 1) < p_dim1 && 0 <= i__2 ? i__2 : s_rnge("p", 
		    i__2, "t_chbigr__", (ftnlen)310)] = p[(i__3 = dix - 1) < 
		    p_dim1 && 0 <= i__3 ? i__3 : s_rnge("p", i__3, "t_chbigr"
		    "__", (ftnlen)310)] + cp[(i__4 = dix * cp_dim1 + 1 - 
		    cp_offset) < cp_dim1 * cp_dim2 && 0 <= i__4 ? i__4 : 
		    s_rnge("cp", i__4, "t_chbigr__", (ftnlen)310)] + cp[(i__5 
		    = dix * cp_dim1 + 2 - cp_offset) < cp_dim1 * cp_dim2 && 0 
		    <= i__5 ? i__5 : s_rnge("cp", i__5, "t_chbigr__", (ftnlen)
		    310)] * x0;

/*           Add together the first two terms of the integral. */

	    itgrlp[(i__2 = dix - 1) < itgrlp_dim1 && 0 <= i__2 ? i__2 : 
		    s_rnge("itgrlp", i__2, "t_chbigr__", (ftnlen)315)] = 
		    itgrlp[(i__3 = dix - 1) < itgrlp_dim1 && 0 <= i__3 ? i__3 
		    : s_rnge("itgrlp", i__3, "t_chbigr__", (ftnlen)315)] + x0 
		    * (cp[(i__4 = dix * cp_dim1 + 1 - cp_offset) < cp_dim1 * 
		    cp_dim2 && 0 <= i__4 ? i__4 : s_rnge("cp", i__4, "t_chbi"
		    "gr__", (ftnlen)315)] + cp[(i__5 = dix * cp_dim1 + 2 - 
		    cp_offset) < cp_dim1 * cp_dim2 && 0 <= i__5 ? i__5 : 
		    s_rnge("cp", i__5, "t_chbigr__", (ftnlen)315)] * x0 / 2);
	} else {

/*           The integrand is constant. */

	    p[(i__2 = dix - 1) < p_dim1 && 0 <= i__2 ? i__2 : s_rnge("p", 
		    i__2, "t_chbigr__", (ftnlen)321)] = p[(i__3 = dix - 1) < 
		    p_dim1 && 0 <= i__3 ? i__3 : s_rnge("p", i__3, "t_chbigr"
		    "__", (ftnlen)321)] + cp[(i__4 = dix * cp_dim1 + 1 - 
		    cp_offset) < cp_dim1 * cp_dim2 && 0 <= i__4 ? i__4 : 
		    s_rnge("cp", i__4, "t_chbigr__", (ftnlen)321)];
	    itgrlp[(i__2 = dix - 1) < itgrlp_dim1 && 0 <= i__2 ? i__2 : 
		    s_rnge("itgrlp", i__2, "t_chbigr__", (ftnlen)323)] = 
		    itgrlp[(i__3 = dix - 1) < itgrlp_dim1 && 0 <= i__3 ? i__3 
		    : s_rnge("itgrlp", i__3, "t_chbigr__", (ftnlen)323)] + x0 
		    * cp[(i__4 = dix * cp_dim1 + 1 - cp_offset) < cp_dim1 * 
		    cp_dim2 && 0 <= i__4 ? i__4 : s_rnge("cp", i__4, "t_chbi"
		    "gr__", (ftnlen)323)];
	}
    }

/*     Scale the integral to account for the change of variables */
/*     (from the original domain to [1-,1]). */

    i__1 = *ndim;
    for (i__ = 1; i__ <= i__1; ++i__) {
	itgrlp[(i__2 = i__ - 1) < itgrlp_dim1 && 0 <= i__2 ? i__2 : s_rnge(
		"itgrlp", i__2, "t_chbigr__", (ftnlen)334)] = radius * itgrlp[
		(i__3 = i__ - 1) < itgrlp_dim1 && 0 <= i__3 ? i__3 : s_rnge(
		"itgrlp", i__3, "t_chbigr__", (ftnlen)334)];
    }
    return 0;
} /* t_chbigr__ */

