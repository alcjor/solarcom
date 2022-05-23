/* t_surfpv.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;
static integer c__9 = 9;
static doublereal c_b29 = 1.;

/* $Procedure T_SURFPV ( Surface intercept position and velocity ) */
/* Subroutine */ int t_surfpv__(doublereal *stvrtx, doublereal *stdir, 
	doublereal *a, doublereal *b, doublereal *c__, doublereal *stx, 
	logical *found)
{
    /* Initialized data */

    static char mssg[32*7] = "Axis A was nonpositive.         " "Axis B was "
	    "nonpositive.         " "Axes A and B were nonpositive.  " "Axis "
	    "C was nonpositive.         " "Axes A and C were nonpositive.  " 
	    "Axes B and C were nonpositive.  " "All three axes were nonposit"
	    "ive.";

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2];
    doublereal d__1, d__2, d__3;
    char ch__1[35];

    /* Builtin functions */
    integer s_rnge(char *, integer, char *, integer);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    doublereal diff;
    extern /* Subroutine */ int vhat_(doublereal *, doublereal *);
    doublereal mins;
    extern /* Subroutine */ int vscl_(doublereal *, doublereal *, doublereal *
	    );
    doublereal vpar[3];
    extern doublereal vdot_(doublereal *, doublereal *);
    extern /* Subroutine */ int vsub_(doublereal *, doublereal *, doublereal *
	    ), vequ_(doublereal *, doublereal *);
    doublereal s, u[3], v[3], x[3];
    extern /* Subroutine */ int chkin_(char *, ftnlen), errch_(char *, char *,
	     ftnlen, ftnlen), dvhat_(doublereal *, doublereal *);
    doublereal bound, level;
    extern doublereal dpmax_(void);
    doublereal vpmag, dvpar[3];
    extern /* Subroutine */ int errdp_(char *, doublereal *, ftnlen), vlcom_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);
    logical exter;
    doublereal xsdir[6];
    extern doublereal vnorm_(doublereal *);
    extern logical vzero_(doublereal *);
    extern /* Subroutine */ int vlcom3_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);
    doublereal ds, du[3], dv[3];
    extern /* Subroutine */ int cleard_(integer *, doublereal *);
    doublereal dx[3], maxmag, minrad, dvpmag, sclmat[9]	/* was [3][3] */;
    extern doublereal touchd_(doublereal *);
    doublereal sbound;
    extern /* Subroutine */ int sigerr_(char *, ftnlen), chkout_(char *, 
	    ftnlen);
    doublereal invmat[9]	/* was [3][3] */, dvperp[3];
    extern /* Subroutine */ int setmsg_(char *, ftnlen);
    doublereal uperpn[3], vperpn[3];
    extern logical return_(void);
    integer bad;
    doublereal vdu;
    extern /* Subroutine */ int mxv_(doublereal *, doublereal *, doublereal *)
	    ;
    doublereal ust[6];

/* $ Abstract */

/*     Find the state (position and velocity) of the surface intercept */
/*     defined by a specified ray, ray velocity, and ellipsoid. */

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

/*     ROTATION */
/*     SPK */
/*     TIME */

/* $ Keywords */

/*     FRAME */
/*     MATRIX */
/*     ROTATION */
/*     STATE */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     MARGIN     P   Margin used for numeric bounds. */
/*     STVRTX     I   State of ray's vertex. */
/*     STDIR      I   State of ray's direction vector. */
/*     A          I   Length of ellipsoid semi-axis along the x-axis. */
/*     B          I   Length of ellipsoid semi-axis along the y-axis. */
/*     C          I   Length of ellipsoid semi-axis along the z-axis. */
/*     STX        O   State of surface intercept. */
/*     FOUND      O   Flag indicating whether intercept state was found. */

/* $ Detailed_Input */

/*     STVRTX         is the state of a ray's vertex. The first three */
/*                    components of STVRTX are the vertex's x, y, and z */
/*                    position components; the vertex's x, y, and z */
/*                    velocity components follow. */

/*                    The reference frame relative to which STVRTX is */
/*                    specified has axes aligned with with those of a */
/*                    triaxial ellipsoid. See the description below of */
/*                    the arguments A, B, and C. */

/*                    The vertex may be inside or outside of this */
/*                    ellipsoid, but not on it. */

/*                    No assumption is made about the units of length */
/*                    and time, but these units must be consistent with */
/*                    those of the other inputs. */


/*     STDIR          is the state of the input ray's direction vector. */
/*                    The first three components of STDIR are a non-zero */
/*                    vector giving the x, y, and z components of the */
/*                    ray's direction; the direction vector's x, y, and */
/*                    z velocity components follow. */

/*                    STDIR is specified relative to the same reference */
/*                    frame as is STVRTX. */


/*     A, */
/*     B, */
/*     C              are, respectively, the lengths of a triaxial */
/*                    ellipsoid's semi-axes lying along the x, y, and */
/*                    z axes of the reference frame relative to which */
/*                    STVRTX and STDIR are specified. */

/* $ Detailed_Output */

/*     STX            is the state of the intercept of the input ray on */
/*                    the surface of the input ellipsoid. The first */
/*                    three components of STX are the intercept's x, y, */
/*                    and z position components; the intercept's x, y, */
/*                    and z velocity components follow. */

/*                    STX is specified relative to the same reference */
/*                    frame as are STVRTX and STDIR. */

/*                    STX is defined if and only if both the intercept */
/*                    and its velocity are computable, as indicated by */
/*                    the output argument FOUND. */


/*     FOUND          is a logical flag indicating whether STX is */
/*                    defined. FOUND is .TRUE. if and only if both the */
/*                    intercept and its velocity are computable. Note */
/*                    that in some cases the intercept may computable */
/*                    while the velocity is not; this can happen for */
/*                    near-tangency cases. */

/* $ Parameters */

/*     MARGIN         is a parameter used to derive numeric */
/*                    bounds: */

/*                       - The minimum allowed semi-axis length */
/*                         is MARGIN / DPMAX() */

/*                       - The maximum magnitude of dX/dt, */
/*                         where X is image of the surface */
/*                         intercept after the ellipsoid and */
/*                         ray are transformed so that */
/*                         the ellipsoid maps to the unit */
/*                         sphere, is MARGIN / DPMAX(). */

/*                       - The maximum magnitude of STX(4:6), */
/*                         the actual velocity of the surface */
/*                         intercept, is MARGIN / DPMAX(). */

/* $ Exceptions */

/*     1) If the input ray's direction vector is zero, the error */
/*        SPICE(ZEROVECTOR) is signaled. */

/*     2) If any input axis length is less than MARGIN / DPMAX(), */
/*        the error SPICE(BADAXISLENGTH) is signaled. */

/*     3) If the vertex of the ray is on the ellipsoid, */
/*        the error SPICE(INVALIDVERTEX) is signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine provides an alternative, analytic ray-ellipsoid */
/*     surface intercept state computation algorithm meant to duplicate */
/*     the results of the algorithm used in SURFPV. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 30-MAY-2008 (NJB) */

/* -& */
/* $ Index_Entries */

/*     state of surface intercept point on ellipsoid */
/*     surface intercept and velocity on ellipsoid */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     Saved variables */


/*     Initial values */

    if (return_()) {
	return 0;
    }
    chkin_("T_SURFPV", (ftnlen)8);

/*     No result has been found. */

    *found = FALSE_;

/*     Reject the direction vector if it's zero. */

    if (vzero_(stdir)) {
	setmsg_("Ray's direction vector was zero.", (ftnlen)32);
	sigerr_("SPICE(ZEROVECTOR)", (ftnlen)17);
	chkout_("T_SURFPV", (ftnlen)8);
	return 0;
    }

/*     Check the ellipsoid radii. */

    minrad = 100. / dpmax_();
    bad = 0;
    if (*a <= minrad) {
	++bad;
    }
    if (*b <= minrad) {
	bad += 2;
    }
    if (*c__ <= minrad) {
	bad += 4;
    }
    if (bad > 0) {
/* Writing concatenation */
	i__2[0] = 32, a__1[0] = mssg + (((i__1 = bad - 1) < 7 && 0 <= i__1 ? 
		i__1 : s_rnge("mssg", i__1, "t_surfpv__", (ftnlen)325)) << 5);
	i__2[1] = 3, a__1[1] = " ? ";
	s_cat(ch__1, a__1, i__2, &c__2, (ftnlen)35);
	setmsg_(ch__1, (ftnlen)35);
	errch_("?", "The A,B, and C axes were #, #, and # respectively.", (
		ftnlen)1, (ftnlen)50);
	errdp_("#", a, (ftnlen)1);
	errdp_("#", b, (ftnlen)1);
	errdp_("#", c__, (ftnlen)1);
	sigerr_("SPICE(BADAXISLENGTH)", (ftnlen)20);
	chkout_("T_SURFPV", (ftnlen)8);
	return 0;
    }

/*     Form the transformation matrix that maps the ellipsoid */
/*     to the unit sphere. */

    cleard_(&c__9, sclmat);
    sclmat[0] = 1. / *a;
    sclmat[4] = 1. / *b;
    sclmat[8] = 1. / *c__;

/*     Transform the input states using SCLMAT. Since SCLMAT is */
/*     a constant matrix, we can scale positions and velocities */
/*     individually. */

    mxv_(sclmat, stvrtx, v);
    mxv_(sclmat, &stvrtx[3], dv);
    mxv_(sclmat, stdir, xsdir);
    mxv_(sclmat, &stdir[3], &xsdir[3]);

/*     Reject the vertex if it's on the ellipsoid. */
/*     We check this by determining whether the transformed */
/*     vertex is on or in the unit sphere. */

/* Computing 2nd power */
    d__1 = v[0];
/* Computing 2nd power */
    d__2 = v[1];
/* Computing 2nd power */
    d__3 = v[2];
    level = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    if (level == 1.) {
	setmsg_("Ray's scaled vertex (# # #) has level surface parameter #. "
		"Vertex must not be on the ellipsoid.", (ftnlen)95);
	errdp_("#", v, (ftnlen)1);
	errdp_("#", &v[1], (ftnlen)1);
	errdp_("#", &v[2], (ftnlen)1);
	errdp_("#", &level, (ftnlen)1);
	sigerr_("SPICE(INVALIDVERTEX)", (ftnlen)20);
	chkout_("T_SURFPV", (ftnlen)8);
	return 0;
    }

/*     The vertex may be either outside or inside the ellipsoid. */
/*     Classify the cases based on the level surface upon which */
/*     the vertex lies. */

    exter = level > 1.;

/*     Map the direction state to the state of a unit vector. */

    dvhat_(xsdir, ust);
    vequ_(ust, u);
    vequ_(&ust[3], du);

/*     Find the component of V parallel to the unit ray direction */
/*     vector. If U is the direction vector and V is the ray's vertex, */
/*     then the component we seek is */

/*        VPAR = < V, U > U                                           (1) */

/*     and the time derivative of VPAR is */

/*        d(VPAR)/dt =     ( < dV/dt, U > + < V, dU/dt > ) U */
/*                      +  < V, U> * dU/dt                            (2) */

/*     Let VPERPN be the component of V perpendicular to U; */
/*     then */

/*        VPERPN = V - VPAR                                           (3) */

/*     and the time derivative DVPERP of VPERPN is */

/*        d(VPERPN)/dt = dV/dt - d(VPAR)/dt                           (4) */

/*     When the vertex is outside the unit sphere, if there is an */
/*     intercept X, the intercept is defined by */

/*        X = VPERPN  -  s * U                                        (5) */

/*     where */
/*                            2   1/2 */
/*        s = ( 1 - ||VPERPN||  )                                     (6) */

/*     and the velocity of X is */

/*        dX/dt = d(VPERPN)/dt  -  ds/dt * U  -  s * dU/dt            (7) */

/*     The time derivative DS of s is */

/*        ds/dt =  - (  ||VPERPN|| * d( ||VPERPN|| )/dt  ) / s        (8) */

/*     and the time derivative DVPMAG of ||VPERPN|| is */

/*        d( ||VPERPN|| )/dt = < d(VPERPN)/dt, VPERPN/||VPERPN|| >    (9) */

/*     If the vertex is inside the sphere, the sign of s is negated, */
/*     so for the interior vertex case we have */

/*        X     = VPERPN  +  s * U                                   (10) */

/*        dX/dt = d(VPERPN)/dt  +  ds/dt * U  +  s * dU/dt           (11) */

/*     For the interior case, we simply negate S and proceed as */
/*     in the exterior case. */

/*     We now compute the intermediate results required to */
/*     compute the velocity of X. */

/*     Start by computing the components of V parallel to and */
/*     perpendicular to U. We do this in-line because we'll re-use the */
/*     intermediate results. At this point we can check for the */
/*     exterior case where the ray points away from the target. */

    vdu = vdot_(v, u);
    if (exter) {
	if (vdu >= 0.) {

/*           The ray's vertex is outside the unit sphere and */
/*           the ray points into the half-space that doesn't */
/*           contain the sphere. */

	    chkout_("T_SURFPV", (ftnlen)8);
	    return 0;
	}
    }
    vscl_(&vdu, u, vpar);
    vsub_(v, vpar, vperpn);

/*     Decide whether we have an intercept. We actually exclude */
/*     the tangency case as well, since the intercept is not */
/*     differentiable there. */

    vpmag = vnorm_(vperpn);
    if (vpmag >= 1.) {

/*        There's no intercept, or the intercept is a tangency point. */

	chkout_("T_SURFPV", (ftnlen)8);
	return 0;
    }

/*     Compute DVPERP and DVPMAG. */

    d__1 = vdot_(dv, u) + vdot_(v, du);
    vlcom_(&d__1, u, &vdu, du, dvpar);
    vsub_(dv, dvpar, dvperp);
    vhat_(vperpn, uperpn);
    dvpmag = vdot_(dvperp, uperpn);

/*     We're still here, so compute the scale factor s. Use MIN for */
/*     safety here; we expect that VPMAG is less than 1. */

/* Computing MIN */
/* Computing 2nd power */
    d__3 = vpmag;
    d__1 = 1., d__2 = d__3 * d__3;
    s = sqrt(1. - min(d__1,d__2));

/*     For the interior case, S is negative. */

    if (! exter) {
	s = -s;
    }

/*     We're almost ready to compute ds/dt. However, this */
/*     computation, as well as the computation on the right */
/*     side of equation (7), can overflow. We must ensure that we */
/*     can compute dX/dt safely. Let DIFF be the maximum magnitude */
/*     that ds/dt can have, based on (7) and on our choice of */
/*     margin. */

    diff = dpmax_() / 100. - vnorm_(dvperp) - abs(s) * vnorm_(du);

/*     If DIFF is not positive, we have a very, very large rate of */
/*     change of the pointing direction. Reject this case. */

    if (diff <= 0.) {
	chkout_("T_SURFPV", (ftnlen)8);
	return 0;
    }

/*     Let BOUND be the upper bound we impose on the magnitude */
/*     of ds/dt. */

    bound = max(diff,1.);

/*     Now apply (8). If DVPMAG is greater than 1, we use it */
/*     in computing the minimum allowable magnitude of s. */

    if (dvpmag > 1.) {
	mins = dvpmag * .5 / bound;
    } else {
	mins = .5 / bound;
    }

/*     Don't compute the derivative if s is too small. */

    d__1 = abs(s);
    if (touchd_(&d__1) < touchd_(&mins)) {
	chkout_("T_SURFPV", (ftnlen)8);
	return 0;
    }

/*     If we got this far, X and dX/dt are computable. Start */
/*     by applying (5) to compute X. */

    d__1 = -s;
    vlcom_(&c_b29, vperpn, &d__1, u, x);

/*     Next compute ds/dt using */

/*        ds/dt =  - (  ||VPERPN|| * d( ||VPERPN|| )/dt  ) / s        (8) */

    ds = -vpmag * dvpmag / s;

/*     Now compute dX/dt using (7), which we copy below. */

/*        dX/dt = d(VPERPN)/dt  -  ds/dt * U  -  s * dU/dt            (7) */
    d__1 = -ds;
    d__2 = -s;
    vlcom3_(&c_b29, dvperp, &d__1, u, &d__2, du, dx);

/*     Check that we can safely invert the scale transformation. */

/* Computing MAX */
    d__1 = abs(*a), d__2 = abs(*b), d__1 = max(d__1,d__2), d__2 = abs(*c__);
    maxmag = max(d__1,d__2);
    if (maxmag > 1.) {
	sbound = dpmax_() / 100. / maxmag;
    } else {
	sbound = dpmax_() / 100.;
    }

/*     If either the intercept or the intercept velocity */
/*     have magnitude too large to allow scaling, return */
/*     here. */

    if (vnorm_(x) > sbound || vnorm_(dx) > sbound) {
	chkout_("T_SURFPV", (ftnlen)8);
	return 0;
    }

/*     Transform the intercept state back to the original */
/*     vector space. */

    cleard_(&c__9, invmat);
    invmat[0] = *a;
    invmat[4] = *b;
    invmat[8] = *c__;
    mxv_(invmat, x, stx);
    mxv_(invmat, dx, &stx[3]);
    *found = TRUE_;
    chkout_("T_SURFPV", (ftnlen)8);
    return 0;
} /* t_surfpv__ */

