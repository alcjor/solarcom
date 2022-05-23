/* t_zzstelab.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static doublereal c_b5 = 1.;

/* $Procedure T_ZZSTELAB ( Test utility, alternate stellar aberration ) */
/* Subroutine */ int t_zzstelab__(logical *xmit, doublereal *accobs, 
	doublereal *vobs, doublereal *starg, doublereal *scorr, doublereal *
	dscorr)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    extern /* Subroutine */ int vadd_(doublereal *, doublereal *, doublereal *
	    );
    doublereal cphi, dphi, pmag, sphi;
    extern doublereal vdot_(doublereal *, doublereal *), vsep_(doublereal *, 
	    doublereal *);
    doublereal dvpu[3];
    extern /* Subroutine */ int vequ_(doublereal *, doublereal *);
    doublereal v[3], dpmag;
    extern /* Subroutine */ int dvhat_(doublereal *, doublereal *);
    doublereal vpmag;
    extern /* Subroutine */ int errdp_(char *, doublereal *, ftnlen), vlcom_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *), vperp_(doublereal *, doublereal *, doublereal *), 
	    unorm_(doublereal *, doublereal *, doublereal *);
    extern doublereal vnorm_(doublereal *);
    doublereal t1[3], t2[3], t3[3], t4[3];
    extern /* Subroutine */ int vlcom3_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);
    extern doublereal pi_(void);
    doublereal pu[3], vp[3];
    extern doublereal clight_(void);
    doublereal dvpmag;
    extern /* Subroutine */ int sigerr_(char *, ftnlen), setmsg_(char *, 
	    ftnlen);
    doublereal pustat[6], vpstat[6], vpusta[6];
    extern /* Subroutine */ int vminus_(doublereal *, doublereal *);
    doublereal acc[3];
    extern doublereal dpr_(void);
    doublereal sep, dpu[3], dvp[3], vpu[3];

/* $ Abstract */

/*     Return the stellar aberration offset vector and the time */
/*     derivative of this offset, using a different analytic */
/*     method from that used by ZZSTELAB. */

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
/*     XMIT       I   Reception/transmission flag. */
/*     ACCOBS     I   Observer acceleration relative to SSB. */
/*     VOBS       I   Observer velocity relative to to SSB. */
/*     STARG      I   State of target relative to observer. */
/*     SCORR      O   Stellar aberration correction for position. */
/*     DSCORR     O   Stellar aberration correction for velocity. */

/* $ Detailed_Input */

/*     XMIT        is a logical flag which is set to .TRUE. for the */
/*                 "transmission" case in which photons *depart* from */
/*                 the observer's location at an observation epoch ET */
/*                 and arrive at the target's location at the light-time */
/*                 corrected epoch ET+LT, where LT is the one-way light */
/*                 time between observer and target; XMIT is set to */
/*                 .FALSE. for "reception" case in which photons depart */
/*                 from the target's location at the light-time */
/*                 corrected epoch ET-LT and *arrive* at the observer's */
/*                 location at ET. */

/*                 Note that the observation epoch is not used in this */
/*                 routine. */

/*                 XMIT must be consistent with any light time */
/*                 corrections used for the input state STARG: if that */
/*                 state has been corrected for "reception" light time; */
/*                 XMIT must be .FALSE.; otherwise XMIT must be .TRUE. */

/*     ACCOBS      is the geometric acceleration of the observer */
/*                 relative to the solar system barycenter. Units are */
/*                 km/sec**2. ACCOBS must be expressed relative to */
/*                 an inertial reference frame. */

/*     VOBS        is the geometric velocity of the observer relative to */
/*                 the solar system barycenter. VOBS must be expressed */
/*                 relative to the same inertial reference frame as */
/*                 ACCOBS. Units are km/sec. */

/*     STARG       is the Cartesian state of the target relative to the */
/*                 observer. Normally STARG has been corrected for */
/*                 one-way light time, but this is not required. STARG */
/*                 must be expressed relative to the same inertial */
/*                 reference frame as ACCOBS. Components are */
/*                 (x, y, z, dx, dy, dz). Units are km and km/sec. */

/* $ Detailed_Output */

/*     SCORR       is the stellar aberration correction for the position */
/*                 component of STARG. Adding SCORR to this position */
/*                 vector produces the input observer-target position, */
/*                 corrected for stellar aberration. */

/*                 The reference frame of SCORR is the common frame */
/*                 relative to which the inputs ACCOBS, VOBS, and STARG */
/*                 are expressed. Units are km. */

/*     DSCORR      is the stellar aberration correction for the velocity */
/*                 component of STARG. Adding SCORR to this velocity */
/*                 vector produces the input observer-target velocity, */
/*                 corrected for stellar aberration. */

/*                 The reference frame of DSCORR is the common frame */
/*                 relative to which the inputs ACCOBS, VOBS, and STARG */
/*                 are expressed. Units are km/s. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If the angular separation of the input observer velocity */
/*        and observer-target position vectors is less than 1e-12 */
/*        radians, the error SPICE(DEGENERATECASE) will be signaled. */

/*     2) Loss of precision will occur for geometric cases in which */
/*        VOBS is nearly parallel to the position component of STARG, */
/*        but for which exception (1) doesn't apply. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine supports testing of the SPICELIB utility ZZSTELAB by */
/*     attempting to produce the same results via a different analytic */
/*     method. For all but near-degenerate cases---those in which the */
/*     stellar aberration rotation angle is nearly zero---the outputs */
/*     from this routine should be very close to those from ZZSTELAB: */
/*     relative errors of both position and velocity offsets should be */
/*     on the order of 1e-14 or better. */

/* $ Examples */

/*     See the test family F_SPKCOR. */

/* $ Restrictions */

/*     1) This routine does not work for near-singular cases. */
/*        See exception (2) above. */

/* $ Literature_References */

/*     SPK Required Reading. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 30-DEC-2007 (NJB) */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     Reject inputs that define near-linearly dependent */
/*     observer-target position and SSB-observer velocity */
/*     vectors. */

    sep = vsep_(vobs, starg);
    if (sep < 1e-12 || pi_() - sep < 1e-12) {
	setmsg_("Angular separation of position and is # degrees: too close "
		"to parallel", (ftnlen)70);
	d__1 = dpr_() * sep;
	errdp_("#", &d__1, (ftnlen)1);
	sigerr_("SPICE(DEGENERATECASE)", (ftnlen)21);
	return 0;
    }

/*     Get local copies of the observer's velocity and */
/*     acceleration relative to the solar system barycenter. */
/*     Negate these if the computation is for the transmission */
/*     case. */

    if (*xmit) {
	vminus_(accobs, acc);
	vminus_(vobs, v);
    } else {
	vequ_(accobs, acc);
	vequ_(vobs, v);
    }

/*     Find the unit target observer-target position vector PU */
/*     and the magnitude of the position vector PMAG. */
/*     Find the time derivative of PU; call this DPU. */

    dvhat_(starg, pustat);
    vequ_(pustat, pu);
    vequ_(&pustat[3], dpu);

/*     Let PMAG be the norm of the observer-target position. */

    pmag = vnorm_(starg);

/*     Let DPMAG be the time derivative of PMAG. */

    dpmag = vdot_(&starg[3], pu);

/*     Find the component of the observer's velocity relative to the SSB */
/*     that is orthogonal to the observer-target position. Call this */
/*     component VP. Let VPMAG be the norm of VP. Let VPU be the unit */
/*     vector parallel to VP. */

    vperp_(v, starg, vp);
    unorm_(vp, vpu, &vpmag);

/*     Find the time derivative of VP. */

/*     This one requires a bit of an explanation: we define */
/*     VP by */

/*        VP  = V - <V,PU>PU */

/*     so, differentiating both sides, we have */

/*        DVP = dV/dt - ( <dV/dt,PU> + <V,dPU/dt> )*PU */
/*                    -   <V,PU> * dPU/dt */

/*            = ACC   - ( <ACC,PU> + <V,DPU> ) * PU */
/*                    -   <V,  PU> * DPU */

    d__1 = -(vdot_(acc, pu) + vdot_(v, dpu));
    d__2 = -vdot_(v, pu);
    vlcom3_(&c_b5, acc, &d__1, pu, &d__2, dpu, dvp);

/*     Find the time derivative DVPU of VPU. */

    vequ_(vp, vpstat);
    vequ_(dvp, &vpstat[3]);
    dvhat_(vpstat, vpusta);
    vequ_(&vpusta[3], dvpu);

/*     Find the sine and cosine of the correction angle PHI; */
/*     call these SPHI and CPHI respectively. Note that PHI */
/*     is close to zero for realistic geometries, so the */
/*     cosine is always positive. */

    sphi = vpmag / clight_();
/* Computing MAX */
    d__1 = 0., d__2 = 1 - sphi * sphi;
    cphi = sqrt((max(d__1,d__2)));

/*     Find the time derivative of VPMAG; call this DVPMAG. */

    dvpmag = vdot_(dvp, vpu);

/*     Find the time derivative of PHI; call this DPHI. */

    dphi = dvpmag / (clight_() * cphi);

/*     Find the stellar aberration correction offset: this */
/*     is the vector to be added to the observer-target */
/*     position to obtain the corrected position. */

/*     To compute this offset, we rotate the observer-target */
/*     position vector by PHI and subtract off the original */
/*     vector. The formula is */

/*        SCORR = PMAG * ( (cos(phi)-1)*PU + sin(phi)*VPU ) */


    d__1 = pmag * (cphi - 1.);
    d__2 = pmag * sphi;
    vlcom_(&d__1, pu, &d__2, vpu, scorr);

/*     Find the stellar aberration correction velocity offset: this is */
/*     the vector to be added to the observer-target velocity to obtain */
/*     the corrected position. */

/*     Differentiating the above formula for SCORR, we have */

/*        DSCORR = d(SCORR)/dt */

/*               =    PMAG *  (  - sin(phi)*d(phi)/dt * PU */
/*                               + ( cos(phi)-1 )     * DPU */
/*                               + cos(phi)*d(phi)/dt * VPU */
/*                               + sin(phi)           * DVPU ) */

/*                 +  DPMAG * ( (cos(phi)-1)*PU + sin(phi)*VPU ) */


    d__1 = -pmag * sphi * dphi;
    d__2 = pmag * (cphi - 1.);
    vlcom_(&d__1, pu, &d__2, dpu, t1);
    d__1 = pmag * cphi * dphi;
    d__2 = pmag * sphi;
    vlcom_(&d__1, vpu, &d__2, dvpu, t2);
    d__1 = dpmag * (cphi - 1.);
    d__2 = dpmag * sphi;
    vlcom_(&d__1, pu, &d__2, vpu, t3);
    vadd_(t1, t2, t4);
    vadd_(t4, t3, dscorr);

/*     SCORR and DSCORR have been set. */

    return 0;
} /* t_zzstelab__ */

