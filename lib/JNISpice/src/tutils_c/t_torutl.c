/* t_torutl.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static doublereal c_b10 = 1.;

/* $Procedure T_TORUTL ( Torus utility package ) */
/* Subroutine */ int t_torutl__0_(int n__, doublereal *r__, doublereal *
	center, doublereal *normal, doublereal *t, doublereal *curve, 
	doublereal *deriv, doublereal *twist)
{
    /* Initialized data */

    static doublereal savr = -1.;

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double cos(doublereal), sin(doublereal);

    /* Local variables */
    extern /* Subroutine */ int vequ_(doublereal *, doublereal *);
    static doublereal savx[3], savy[3];
    doublereal c__, s;
    extern /* Subroutine */ int frame_(doublereal *, doublereal *, doublereal 
	    *), chkin_(char *, ftnlen);
    doublereal theta;
    extern /* Subroutine */ int errdp_(char *, doublereal *, ftnlen), vlcom_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);
    extern doublereal twopi_(void);
    extern /* Subroutine */ int vlcom3_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *), sigerr_(char *, ftnlen), chkout_(char *, ftnlen);
    static doublereal savctr[3];
    extern /* Subroutine */ int setmsg_(char *, ftnlen);
    extern logical return_(void);

/* $ Abstract */

/*     Umbrella routine for entry points that provide a central curve */
/*     for a torus. */

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

/*     DSK */
/*     PLATE */
/*     UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Entry points */
/*     --------  ---  -------------------------------------------------- */
/*     R          I   T_TORSET */
/*     CENTER     I   T_TORSET */
/*     NORMAL     I   T_TORSET */
/*     T          I   T_TORCRV */
/*     CURVE      O   T_TORCRV */
/*     DERIV      O   T_TORCRV */
/*     TWIST      O   T_TORCRV */

/* $ Detailed_Input */

/*     See the entry points. */

/* $ Detailed_Output */

/*     See the entry points. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If this routine is called directly, the error */
/*         SPICE(BOGUSENTRY) is signaled. */


/*     See the entry points for descriptions of errors specific to those */
/*     routines. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This package contains two entry points: */

/*        T_TORSET {initialize central curve} */
/*        T_TORCRV {get curve and derivative} */

/*     These entry points are used by the test utility routine */

/*        T_TORUS */

/*     which is an entry point of */

/*        T_WRDSK2 */


/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 26-APR-2016 (NJB) */

/* -& */

/*     SPICELIB functions */


/*     Local variables */


/*     Saved variables */


/*     Initial values */

    /* Parameter adjustments */
    if (center) {
	}
    if (normal) {
	}
    if (curve) {
	}
    if (deriv) {
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_t_torcrv;
	case 2: goto L_t_torset;
	}

    chkin_("T_TORUTL", (ftnlen)8);
    sigerr_("SPICE(BOGUSENTRY)", (ftnlen)17);
    chkout_("T_TORUTL", (ftnlen)8);
    return 0;
/* $Procedure T_TORCRV ( Torus curve ) */

L_t_torcrv:
/* $ Abstract */

/*     Return a point on a parameterized central curve of */
/*     a torus; return the curve's derivative at this point */
/*     as well. Return a twist value of zero. */

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

/*     DSK */
/*     PLATE */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      T */
/*     DOUBLE PRECISION      CURVE ( 3 ) */
/*     DOUBLE PRECISION      DERIV ( 3 ) */
/*     DOUBLE PRECISION      TWIST */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     T          I   The curve parameter. Values are in [0, 1]. */
/*     CURVE      O   The value of the curve at T. */
/*     DERIV      O   The derivative of the curve with respect to T at T. */
/*     TWIST      O   The twist value at T; identically zero. */

/* $ Detailed_Input */

/*     T          is the value of the curve parameter. T is in the */
/*                closed interval [0, 1]. */

/* $ Detailed_Output */

/*     CURVE      is the value of the curve at T. */

/*     DERIV      is the value of the derivative of the curve with */
/*                respect to T, at T. */

/*     TWIST      is the twist at T; this value is always set to zero. */
/*                See Particulars. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If T is outside the interval [0, 1 ], the error */
/*         SPICE(VALUEOUTOFRANGE) is signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine defines a central curve a torus. */

/*     The argument list of this routine is compatible with the */
/*     requirements of the test utility routine */

/*        ZZPSTUBE */

/*     The output TWIST is provided because ZZPSTUBE requires it. (Twist */
/*     is used by ZZPSTUBE to orient cross sections of the tube it */
/*     creates.) */


/*     In a Cartesian coordinate system having the Z axis parallel to */
/*     NORMAL, and having an origin coincident with CENTER, the torus */
/*     is the set of points */

/*                                2   2  1/2  2     2           2 */
/*        { (x,y,z) : (  R  -  ( x + y  )    )  +  z   =  RCROSS  } */


/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 26-APR-2016 (NJB) */

/* -& */

/*     Use discovery check-in. */

    if (return_()) {
	return 0;
    }
    if (*t < 0. || *t > 1.) {
	chkin_("T_TORCRV", (ftnlen)8);
	setmsg_("Parameter T was # but must be in the range [0, 1].", (ftnlen)
		50);
	errdp_("#", t, (ftnlen)1);
	sigerr_("SPICE(VALUEOUTOFRANGE)", (ftnlen)22);
	chkout_("T_TORCRV", (ftnlen)8);
	return 0;
    }
    theta = *t * twopi_();
    c__ = savr * cos(theta);
    s = savr * sin(theta);
    vlcom3_(&c__, savx, &s, savy, &c_b10, savctr, curve);
    d__1 = -s;
    vlcom_(&d__1, savx, &c__, savy, deriv);
    *twist = 0.;
    return 0;
/* $Procedure T_TORSET ( Torus set-up ) */

L_t_torset:
/* $ Abstract */

/*     Perform set-up functions for the entry point T_TORCRV. */

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

/*     DSK */
/*     PLATE */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      R */
/*     DOUBLE PRECISION      CENTER ( 3 ) */
/*     DOUBLE PRECISION      NORMAL ( 3 ) */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     R          I   Radius of central curve. */
/*     CENTER     I   Center of a torus. */
/*     NORMAL     I   Normal vector to plane of central curve. */

/* $ Detailed_Input */

/*     R          is the radius of the central curve of a torus. */
/*                Each cross section is centered on this curve and */
/*                is normal to the derivative of the curve at the point */
/*                of intersection. */

/*     CENTER     is the center of the torus. The is the center of the */
/*                central curve of the torus. The line normal to the */
/*                plane of the central curve and passing through CENTER */
/*                is the axis of azimuthal symmetry of the torus. */

/*     NORMAL     is a vector normal to the plane containing the */
/*                central curve of the torus. */


/* $ Detailed_Output */

/*     None. This routine operates by side effects. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If an orthonormal basis having its +Z axis parallel to */
/*         NORMAL cannot be created, an error will be signaled by */
/*         a routine in the call tree of this routine. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine saves the values of the input arguments R and CENTER */
/*     so that they may be used by the entry point T_TORCRV. It */
/*     generates an orthonormal basis having its +Z axis parallel to */
/*     NORMAL. */

/*     In a Cartesian coordinate system having the Z axis parallel to */
/*     NORMAL, and having an origin coincident with CENTER, the torus */
/*     is the set of points */

/*                                2   2  1/2  2     2           2 */
/*        { (x,y,z) : (  R  -  ( x + y  )    )  +  z   =  RCROSS  } */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 26-APR-2016 (NJB) */

/* -& */
    if (return_()) {
	return 0;
    }
    chkin_("T_TORSET", (ftnlen)8);
    savr = *r__;
    vequ_(center, savctr);

/*     Generate basis vectors for the plane containing */
/*     the central curve of the torus. */

    frame_(normal, savx, savy);
    chkout_("T_TORSET", (ftnlen)8);
    return 0;
} /* t_torutl__ */

/* Subroutine */ int t_torutl__(doublereal *r__, doublereal *center, 
	doublereal *normal, doublereal *t, doublereal *curve, doublereal *
	deriv, doublereal *twist)
{
    return t_torutl__0_(0, r__, center, normal, t, curve, deriv, twist);
    }

/* Subroutine */ int t_torcrv__(doublereal *t, doublereal *curve, doublereal *
	deriv, doublereal *twist)
{
    return t_torutl__0_(1, (doublereal *)0, (doublereal *)0, (doublereal *)0, 
	    t, curve, deriv, twist);
    }

/* Subroutine */ int t_torset__(doublereal *r__, doublereal *center, 
	doublereal *normal)
{
    return t_torutl__0_(2, r__, center, normal, (doublereal *)0, (doublereal *
	    )0, (doublereal *)0, (doublereal *)0);
    }

