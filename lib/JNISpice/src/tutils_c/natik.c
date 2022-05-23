/* natik.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__3 = 3;
static doublereal c_b13 = 1.;
static doublereal c_b15 = -1.;
static integer c__14 = 14;

/* $Procedure   NATIK ( Create an IK for Nat's solar system ) */
/* Subroutine */ int natik_(char *ik, char *spk, char *pck, logical *loadik, 
	logical *keepik, ftnlen ik_len, ftnlen spk_len, ftnlen pck_len)
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    char ch__1[16];
    cllist cl__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rnge(char *, integer, char *, integer), f_clos(cllist *);

    /* Local variables */
    doublereal bvec[30]	/* was [3][10] */, limb[9], bnds[30]	/* was [3][10]
	     */;
    extern /* Subroutine */ int vhat_(doublereal *, doublereal *);
    integer inst, unit;
    extern /* Subroutine */ int vsub_(doublereal *, doublereal *, doublereal *
	    ), vequ_(doublereal *, doublereal *);
    integer i__, j, l, n, ixbcb;
    doublereal radii[3];
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    doublereal bsite[3];
    integer ixbsb, ixinb;
    extern /* Subroutine */ int repmc_(char *, char *, char *, char *, ftnlen,
	     ftnlen, ftnlen, ftnlen), repmd_(char *, char *, doublereal *, 
	    integer *, char *, ftnlen, ftnlen, ftnlen);
    integer ixine;
    extern /* Subroutine */ int repmi_(char *, char *, integer *, char *, 
	    ftnlen, ftnlen, ftnlen), vlcom_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    doublereal xform[9]	/* was [3][3] */, vtemp[3];
    extern /* Subroutine */ int el2cgv_(doublereal *, doublereal *, 
	    doublereal *, doublereal *), vlcom3_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);
    extern /* Character */ VOID begdat_(char *, ftnlen);
    integer nl, handle;
    extern /* Subroutine */ int edlimb_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    doublereal lt;
    integer nv;
    extern /* Subroutine */ int kilfil_(char *, ftnlen);
    char tx[80*100];
    doublereal center[3];
    extern /* Subroutine */ int bodvrd_(char *, char *, integer *, integer *, 
	    doublereal *, ftnlen, ftnlen), spklef_(char *, integer *, ftnlen);
    char insnam[36];
    extern /* Subroutine */ int tfiles_(char *, ftnlen), ldpool_(char *, 
	    ftnlen);
    doublereal smajor[3];
    extern /* Character */ VOID begtxt_(char *, ftnlen);
    extern /* Subroutine */ int spkuef_(integer *), chkout_(char *, ftnlen);
    doublereal sminor[3], et0;
    extern /* Subroutine */ int pxform_(char *, char *, doublereal *, 
	    doublereal *, ftnlen, ftnlen);
    doublereal viewpt[3];
    extern /* Subroutine */ int spkpos_(char *, doublereal *, char *, char *, 
	    char *, doublereal *, doublereal *, ftnlen, ftnlen, ftnlen, 
	    ftnlen), writln_(char *, integer *, ftnlen), vminus_(doublereal *,
	     doublereal *), txtopn_(char *, integer *, ftnlen);
    doublereal pos[3];
    extern /* Subroutine */ int mxv_(doublereal *, doublereal *, doublereal *)
	    ;

/* $ Abstract */

/*     Create and if appropriate load an IK for Nat's */
/*     solar system. */

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

/*     TESTING */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     IK         I   Name of the I-kernel to create. */
/*     SPK        I   Name of an existing Nat's solar system SPK. */
/*     PCK        I   Name of an existing Nat's solar system PCK. */
/*     LOADIK     I   Load the I-kernel if .TRUE. */
/*     KEEPIK     I   Keep the I-kernel if .TRUE., else delete it. */

/* $ Detailed_Input */

/*     IK          is the name of an IK to create and load if LOADIK is */
/*                 set to .TRUE. If an IK of the same name already */
/*                 exists, the existing file is deleted. */

/*     SPK         is the name of an existing Nat's solar system SPK. */
/*                 This SPK is required to define dynamic two-vector */
/*                 frames which require the positions of bodies Alpha */
/*                 and Beta with respect to the Sun. */

/*     PCK         is the name of an existing Nat's solar system PCK. */
/*                 This PCK is required to define dynamic two-vector */
/*                 frames which require the positions of bodies Alpha */
/*                 and Beta with respect to the Sun. */

/*     LOADIK      is a logical that indicates whether or not the IK */
/*                 file should be loaded after it is created.  If LOADIK */
/*                 has the value .TRUE. the IK is loaded after it is */
/*                 created.  Otherwise it is left un-opened. */

/*     KEEPIK      is a logical that indicates whether or not the IK */
/*                 file should be deleted after it is loaded.  If KEEPIK */
/*                 is .TRUE. the file is not deleted.  If KEEPIK is */
/*                 .FALSE. the file is deleted after it is loaded. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any I/O errors occurring in the creation of the IK file */
/*        will be signaled by routines in the call tree of this */
/*        routine. */

/*     Since this routine is normally used within the TSPICE system, */
/*     it's up the the caller to call CHCKXC to catch errors signaled by */
/*     this routine. */

/* $ Files */

/*     This routine creates an IK containing FOV specifications for four */
/*     "instruments." The instruments' frame and FOV specifications are */
/*     designed so that appearances of body Beta in the FOVs coincide */
/*     with transits of Beta across Alpha, thus yielding simple, */
/*     predictable */
/*     event timing. */

/*     The instruments' names are */

/*        ALPHA_CIRCLE_NONE */
/*        ALPHA_DIAMOND_NONE */
/*        ALPHA_ELLIPSE_NONE */
/*        ALPHA_RECTANGLE_NONE */

/*     The first component of each name is the body tracked by the */
/*     instrument's reference frame. */

/*     The second component is the FOV shape; each shape specifier */
/*     supported by GETFOV is supported here. The instrument */
/*     ALPHA_DIAMOND_NONE uses the 'POLYGON' shape specifier. */

/*     The third component of each name is the aberration correction */
/*     applied to the position vectors used in the frame specification. */

/*     The reference frames associated with the instruments are, */
/*     respectively */

/*        ALPHA_VIEW_XY */
/*        ALPHA_VIEW_XZ */
/*        ALPHA_VIEW_XY */
/*        ALPHA_VIEW_XY */

/*     Note that the frame of ALPHA_DIAMOND_NONE has been selected */
/*     so that body Beta orbits in the X-Z plane of that frame. */

/* $ Particulars */

/*     This routine creates an IK file for use in testing. The */
/*     file is registered with the TSPICE system via a call to */
/*     TFILES. */

/* $ Examples */

/*     The normal way to use this routine is shown below. */

/*     CALL NATSPK ( 'nat.bsp', .TRUE., HANDLE  ) */
/*     CALL NATPCK ( 'nat.tpc', .TRUE., .TRUE.  ) */
/*     CALL NATIK  ( 'nat.ti',  .TRUE., .FALSE. ) */

/*        [perform some tests and computations] */

/*     CALL SPKUEF ( HANDLE ) */
/*     CALL KILFIL ( 'nat.bsp' ) */

/*     If these calls are made within a TSPICE test family, the */
/*     kernels will be deleted at the time the test family returns. */
/*     In other settings, the caller will need to clean up the */
/*     PCK file via an explicit deletion. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    Test Utilities 1.0.0, 29-JUL-2008 (NJB) */

/* -& */
/* $ Index_Entries */

/*     Create a "Nat's solar system" IK file */

/* -& */

/*     Test Utility Functions */


/*     Local Parameters */


/*     Local variables */

    chkin_("NATIK", (ftnlen)5);

/*     Delete any existing file of the same name. */

    kilfil_(ik, ik_len);

/*     Before creating the IK, we derive the parameters */
/*     needed to create the intrument FOVs we'll specify there. */

/*     Load the Nat's solar system SPK and PCK. */

    spklef_(spk, &handle, spk_len);
    ldpool_(pck, pck_len);
    bodvrd_("ALPHA", "RADII", &c__3, &n, radii, (ftnlen)5, (ftnlen)5);

/*     Compute the limb of body Alpha as seen from the Sun */
/*     at 0 seconds past J2000 TDB. Do not use aberration */
/*     corrections. */

    et0 = 0.;
    spkpos_("ALPHA", &et0, "ALPHAFIXED", "NONE", "SUN", pos, &lt, (ftnlen)5, (
	    ftnlen)10, (ftnlen)4, (ftnlen)3);
    vminus_(pos, viewpt);
    edlimb_(radii, &radii[1], &radii[2], viewpt, limb);

/*     Create boundary vectors for an elliptical FOV in the */
/*     ALPHAFIXED frame. */

    el2cgv_(limb, center, smajor, sminor);
/* ********************************************************************** */

/*     Create FOV specification and instrument name-ID mapping */
/*     for the instrument "Alpha_Ellipse_NONE." */

/* ********************************************************************** */

/*     This FOV is fixed to the dynamic frame ALPHA_VIEW_XY. */
/*     Thus the instrument "tracks" body Alpha. As seen from the */
/*     Sun, with aberration corrections turned off, */
/*     the FOV coincides with the limb of Alpha. */

    s_copy(insnam, "ALPHA_ELLIPSE_NONE", (ftnlen)36, (ftnlen)18);
    inst = -1500000;

/*     Look up the transformation from the ALPHAFIXED frame to the */
/*     ALPHA_VIEW_XY frame. The latter rotates with the orbital motion */
/*     of planet Alpha. */

    pxform_("ALPHAFIXED", "ALPHA_VIEW_XY", &et0, xform, (ftnlen)10, (ftnlen)
	    13);

/*     Compute the boresight vector. */

    mxv_(xform, pos, vtemp);
    vhat_(vtemp, bsite);
    vlcom3_(&c_b13, center, &c_b13, smajor, &c_b15, viewpt, bvec);
    vlcom3_(&c_b13, center, &c_b13, sminor, &c_b15, viewpt, &bvec[3]);
    for (i__ = 1; i__ <= 2; ++i__) {
	mxv_(xform, &bvec[(i__1 = i__ * 3 - 3) < 30 && 0 <= i__1 ? i__1 : 
		s_rnge("bvec", i__1, "natik_", (ftnlen)340)], &bnds[(i__2 = 
		i__ * 3 - 3) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"natik_", (ftnlen)340)]);
    }

/*     As obnoxious as the practice may seem, we'll use the variable */
/*     L instead of hard-coded constants to index buffer elements. */
/*     Hard-coded indices are a big problem when changes are needed. */

    l = 1;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)349)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)351)) * 80, " KPL/IK", (ftnlen)80, (ftnlen)7);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)353)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    begdat_(ch__1, (ftnlen)16);
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)355)) * 80, ch__1, (ftnlen)80, (ftnlen)16);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)357)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)360)) * 80, "NAIF_BODY_NAME += '#' ", (ftnlen)
	    80, (ftnlen)22);
    repmc_(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)361)) * 80, "#", insnam, tx + ((i__2 = l - 1) <
	     100 && 0 <= i__2 ? i__2 : s_rnge("tx", i__2, "natik_", (ftnlen)
	    361)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)36, (ftnlen)80);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)364)) * 80, "NAIF_BODY_CODE += #", (ftnlen)80, 
	    (ftnlen)19);
    repmi_(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)365)) * 80, "#", &inst, tx + ((i__2 = l - 1) < 
	    100 && 0 <= i__2 ? i__2 : s_rnge("tx", i__2, "natik_", (ftnlen)
	    365)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)368)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    ixinb = l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)372)) * 80, "INS#_FOV_SHAPE            = 'ELL"
	    "IPSE' ", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)374)) * 80, "INS#_FOV_FRAME            = 'ALP"
	    "HA_VIEW_XY' ", (ftnlen)80, (ftnlen)44);
    ++l;
    ixbsb = l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)377)) * 80, "INS#_BORESIGHT            = ( *", 
	    (ftnlen)80, (ftnlen)31);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)379)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)381)) * 80, "                                "
	    "     * )", (ftnlen)80, (ftnlen)40);
    ++l;
    ixbcb = l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)384)) * 80, "INS#_FOV_BOUNDARY         = ( *", 
	    (ftnlen)80, (ftnlen)31);
    ixine = l;
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)387)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)389)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)391)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)393)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)395)) * 80, "                                "
	    "     * )", (ftnlen)80, (ftnlen)40);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)397)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    begtxt_(ch__1, (ftnlen)16);
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)399)) * 80, ch__1, (ftnlen)80, (ftnlen)16);
    ++l;

/*     Set the instrument ID in the keywords above. */

    i__1 = ixine;
    for (i__ = ixinb; i__ <= i__1; ++i__) {
	repmi_(tx + ((i__2 = i__ - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(
		"tx", i__2, "natik_", (ftnlen)406)) * 80, "#", &inst, tx + ((
		i__3 = i__ - 1) < 100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3,
		 "natik_", (ftnlen)406)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)
		80);
    }

/*     Set the boresight values. */

    j = ixbsb - 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	repmd_(tx + ((i__1 = j + i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"tx", i__1, "natik_", (ftnlen)415)) * 80, "*", &bsite[(i__2 = 
		i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge("bsite", i__2, 
		"natik_", (ftnlen)415)], &c__14, tx + ((i__3 = j + i__ - 1) < 
		100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3, "natik_", (
		ftnlen)415)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    }

/*     Set the boundary corner values. */

    j = ixbcb - 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	repmd_(tx + ((i__1 = j + i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"tx", i__1, "natik_", (ftnlen)424)) * 80, "*", &bnds[(i__2 = 
		i__ - 1) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"natik_", (ftnlen)424)], &c__14, tx + ((i__3 = j + i__ - 1) < 
		100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3, "natik_", (
		ftnlen)424)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
	repmd_(tx + ((i__1 = j + i__ + 2) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"tx", i__1, "natik_", (ftnlen)425)) * 80, "*", &bnds[(i__2 = 
		i__ + 2) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"natik_", (ftnlen)425)], &c__14, tx + ((i__3 = j + i__ + 2) < 
		100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3, "natik_", (
		ftnlen)425)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    }
/* ********************************************************************** */

/*     Create FOV specification and instrument name-ID mapping */
/*     for the instrument "Alpha_Circle_NONE." */

/* ********************************************************************** */

/*     This FOV is fixed to the dynamic frame ALPHA_VIEW_XY. */
/*     Thus the instrument "tracks" body Alpha. As seen from the */
/*     Sun, with aberration corrections turned off, */
/*     the FOV is inscribed in the limb of Alpha. */

    s_copy(insnam, "ALPHA_CIRCLE_NONE", (ftnlen)36, (ftnlen)17);
    inst = -1500001;

/*     Look up the transformation from the ALPHAFIXED frame to the */
/*     ALPHA_VIEW_XY frame. The latter rotates with the orbital motion */
/*     of planet Alpha. */

    pxform_("ALPHAFIXED", "ALPHA_VIEW_XY", &et0, xform, (ftnlen)10, (ftnlen)
	    13);

/*     Compute the boresight vector. */

    mxv_(xform, pos, vtemp);
    vhat_(vtemp, bsite);

/*     We use the semi-minor axis to define the boundary vector, */
/*     since we want our circle to be inscribed in Alpha's limb. */

    vlcom3_(&c_b13, center, &c_b13, sminor, &c_b15, viewpt, bvec);
    mxv_(xform, bvec, bnds);
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)473)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)475)) * 80, " KPL/TX", (ftnlen)80, (ftnlen)7);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)477)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    begdat_(ch__1, (ftnlen)16);
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)479)) * 80, ch__1, (ftnlen)80, (ftnlen)16);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)481)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)484)) * 80, "NAIF_BODY_NAME += '#' ", (ftnlen)
	    80, (ftnlen)22);
    repmc_(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)485)) * 80, "#", insnam, tx + ((i__2 = l - 1) <
	     100 && 0 <= i__2 ? i__2 : s_rnge("tx", i__2, "natik_", (ftnlen)
	    485)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)36, (ftnlen)80);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)488)) * 80, "NAIF_BODY_CODE += #", (ftnlen)80, 
	    (ftnlen)19);
    repmi_(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)489)) * 80, "#", &inst, tx + ((i__2 = l - 1) < 
	    100 && 0 <= i__2 ? i__2 : s_rnge("tx", i__2, "natik_", (ftnlen)
	    489)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)492)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    ixinb = l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)496)) * 80, "INS#_FOV_SHAPE            = 'CIR"
	    "CLE' ", (ftnlen)80, (ftnlen)37);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)498)) * 80, "INS#_FOV_FRAME            = 'ALP"
	    "HA_VIEW_XY' ", (ftnlen)80, (ftnlen)44);
    ++l;
    ixbsb = l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)501)) * 80, "INS#_BORESIGHT            = ( *", 
	    (ftnlen)80, (ftnlen)31);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)503)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)505)) * 80, "                                "
	    "     * )", (ftnlen)80, (ftnlen)40);
    ++l;
    ixbcb = l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)508)) * 80, "INS#_FOV_BOUNDARY         = ( *", 
	    (ftnlen)80, (ftnlen)31);
    ixine = l;
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)511)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)513)) * 80, "                                "
	    "     * )", (ftnlen)80, (ftnlen)40);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)515)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    begtxt_(ch__1, (ftnlen)16);
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)517)) * 80, ch__1, (ftnlen)80, (ftnlen)16);
    ++l;

/*     Set the instrument ID in the keywords above. */

    i__1 = ixine;
    for (i__ = ixinb; i__ <= i__1; ++i__) {
	repmi_(tx + ((i__2 = i__ - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(
		"tx", i__2, "natik_", (ftnlen)524)) * 80, "#", &inst, tx + ((
		i__3 = i__ - 1) < 100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3,
		 "natik_", (ftnlen)524)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)
		80);
    }

/*     Set the boresight values. */

    j = ixbsb - 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	repmd_(tx + ((i__1 = j + i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"tx", i__1, "natik_", (ftnlen)533)) * 80, "*", &bsite[(i__2 = 
		i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge("bsite", i__2, 
		"natik_", (ftnlen)533)], &c__14, tx + ((i__3 = j + i__ - 1) < 
		100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3, "natik_", (
		ftnlen)533)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    }

/*     Set the boundary corner values. */

    j = ixbcb - 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	repmd_(tx + ((i__1 = j + i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"tx", i__1, "natik_", (ftnlen)542)) * 80, "*", &bnds[(i__2 = 
		i__ - 1) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"natik_", (ftnlen)542)], &c__14, tx + ((i__3 = j + i__ - 1) < 
		100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3, "natik_", (
		ftnlen)542)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
	repmd_(tx + ((i__1 = j + i__ + 2) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"tx", i__1, "natik_", (ftnlen)543)) * 80, "*", &bnds[(i__2 = 
		i__ + 2) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"natik_", (ftnlen)543)], &c__14, tx + ((i__3 = j + i__ + 2) < 
		100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3, "natik_", (
		ftnlen)543)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    }
/* ********************************************************************** */

/*     Create FOV specification and instrument name-ID mapping */
/*     for the instrument "Alpha_Rectangle_NONE." */

/* ********************************************************************** */

/*     This FOV is fixed to the dynamic frame ALPHA_VIEW_XY. Thus the */
/*     instrument "tracks" body Alpha. As seen from the Sun, with */
/*     aberration corrections turned off, the FOV circumscribes the limb */
/*     of Alpha. */

    s_copy(insnam, "ALPHA_RECTANGLE_NONE", (ftnlen)36, (ftnlen)20);
    inst = -1500003;
    nv = 4;

/*     Look up the transformation from the ALPHAFIXED frame to the */
/*     ALPHA_VIEW_XY frame. The latter rotates with the orbital motion */
/*     of planet Alpha. */

    pxform_("ALPHAFIXED", "ALPHA_VIEW_XY", &et0, xform, (ftnlen)10, (ftnlen)
	    13);

/*     Compute the boresight vector. */

    mxv_(xform, pos, vtemp);
    vhat_(vtemp, bsite);

/*     Compute the boundary vectors. */

    vsub_(center, viewpt, vtemp);
    vlcom3_(&c_b13, sminor, &c_b13, smajor, &c_b13, vtemp, bvec);
    vlcom3_(&c_b15, sminor, &c_b13, smajor, &c_b13, vtemp, &bvec[3]);
    vlcom3_(&c_b15, sminor, &c_b15, smajor, &c_b13, vtemp, &bvec[6]);
    vlcom3_(&c_b13, sminor, &c_b15, smajor, &c_b13, vtemp, &bvec[9]);

/*     Apply the transformation from the ALPHAFIXED frame to the */
/*     ALPHA_VIEW_XY frame. The latter rotates with the orbital motion */
/*     of planet Alpha. */

    mxv_(xform, pos, vtemp);
    vhat_(vtemp, bsite);
    i__1 = nv;
    for (i__ = 1; i__ <= i__1; ++i__) {
	mxv_(xform, &bvec[(i__2 = i__ * 3 - 3) < 30 && 0 <= i__2 ? i__2 : 
		s_rnge("bvec", i__2, "natik_", (ftnlen)614)], &bnds[(i__3 = 
		i__ * 3 - 3) < 30 && 0 <= i__3 ? i__3 : s_rnge("bnds", i__3, 
		"natik_", (ftnlen)614)]);
	vhat_(&bnds[(i__2 = i__ * 3 - 3) < 30 && 0 <= i__2 ? i__2 : s_rnge(
		"bnds", i__2, "natik_", (ftnlen)616)], vtemp);
	vequ_(vtemp, &bnds[(i__2 = i__ * 3 - 3) < 30 && 0 <= i__2 ? i__2 : 
		s_rnge("bnds", i__2, "natik_", (ftnlen)617)]);
    }
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)621)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)623)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)625)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    begdat_(ch__1, (ftnlen)16);
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)627)) * 80, ch__1, (ftnlen)80, (ftnlen)16);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)629)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)632)) * 80, "NAIF_BODY_NAME += '#' ", (ftnlen)
	    80, (ftnlen)22);
    repmc_(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)633)) * 80, "#", insnam, tx + ((i__2 = l - 1) <
	     100 && 0 <= i__2 ? i__2 : s_rnge("tx", i__2, "natik_", (ftnlen)
	    633)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)36, (ftnlen)80);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)636)) * 80, "NAIF_BODY_CODE += #", (ftnlen)80, 
	    (ftnlen)19);
    repmi_(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)637)) * 80, "#", &inst, tx + ((i__2 = l - 1) < 
	    100 && 0 <= i__2 ? i__2 : s_rnge("tx", i__2, "natik_", (ftnlen)
	    637)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)640)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    ixinb = l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)644)) * 80, "INS#_FOV_SHAPE            = 'REC"
	    "TANGLE' ", (ftnlen)80, (ftnlen)40);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)646)) * 80, "INS#_FOV_FRAME            = 'ALP"
	    "HA_VIEW_XY' ", (ftnlen)80, (ftnlen)44);
    ++l;
    ixbsb = l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)649)) * 80, "INS#_BORESIGHT            = ( *", 
	    (ftnlen)80, (ftnlen)31);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)651)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)653)) * 80, "                                "
	    "     * )", (ftnlen)80, (ftnlen)40);
    ++l;
    ixbcb = l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)656)) * 80, "INS#_FOV_BOUNDARY         = ( *", 
	    (ftnlen)80, (ftnlen)31);
    ixine = l;
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)659)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)661)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)663)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)665)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)667)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)669)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)671)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)673)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)675)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)677)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)679)) * 80, "                                "
	    "     * )", (ftnlen)80, (ftnlen)40);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)681)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    begtxt_(ch__1, (ftnlen)16);
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)683)) * 80, ch__1, (ftnlen)80, (ftnlen)16);
    ++l;

/*     Set the instrument ID in the keywords above. */

    i__1 = ixine;
    for (i__ = ixinb; i__ <= i__1; ++i__) {
	repmi_(tx + ((i__2 = i__ - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(
		"tx", i__2, "natik_", (ftnlen)690)) * 80, "#", &inst, tx + ((
		i__3 = i__ - 1) < 100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3,
		 "natik_", (ftnlen)690)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)
		80);
    }

/*     Set the boresight values. */

    j = ixbsb - 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	repmd_(tx + ((i__1 = j + i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"tx", i__1, "natik_", (ftnlen)699)) * 80, "*", &bsite[(i__2 = 
		i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge("bsite", i__2, 
		"natik_", (ftnlen)699)], &c__14, tx + ((i__3 = j + i__ - 1) < 
		100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3, "natik_", (
		ftnlen)699)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    }

/*     Set the boundary corner values. */

    j = ixbcb - 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	repmd_(tx + ((i__1 = j + i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"tx", i__1, "natik_", (ftnlen)708)) * 80, "*", &bnds[(i__2 = 
		i__ - 1) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"natik_", (ftnlen)708)], &c__14, tx + ((i__3 = j + i__ - 1) < 
		100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3, "natik_", (
		ftnlen)708)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
	repmd_(tx + ((i__1 = j + i__ + 2) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"tx", i__1, "natik_", (ftnlen)709)) * 80, "*", &bnds[(i__2 = 
		i__ + 2) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"natik_", (ftnlen)709)], &c__14, tx + ((i__3 = j + i__ + 2) < 
		100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3, "natik_", (
		ftnlen)709)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
	repmd_(tx + ((i__1 = j + i__ + 5) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"tx", i__1, "natik_", (ftnlen)710)) * 80, "*", &bnds[(i__2 = 
		i__ + 5) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"natik_", (ftnlen)710)], &c__14, tx + ((i__3 = j + i__ + 5) < 
		100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3, "natik_", (
		ftnlen)710)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
	repmd_(tx + ((i__1 = j + i__ + 8) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"tx", i__1, "natik_", (ftnlen)711)) * 80, "*", &bnds[(i__2 = 
		i__ + 8) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"natik_", (ftnlen)711)], &c__14, tx + ((i__3 = j + i__ + 8) < 
		100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3, "natik_", (
		ftnlen)711)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    }
/* ********************************************************************** */

/*     Create FOV specification and instrument name-ID mapping */
/*     for the instrument "Alpha_Diamond_NONE." */

/* ********************************************************************** */

/*     This FOV is fixed to the dynamic frame ALPHA_VIEW_XZ (note: NOT */
/*     "_XY"). Thus the instrument "tracks" body Alpha. As seen from the */
/*     Sun, with aberration corrections turned off, the FOV inscribes */
/*     the limb of Alpha. */

    s_copy(insnam, "ALPHA_DIAMOND_NONE", (ftnlen)36, (ftnlen)18);
    inst = -1500004;
    nv = 4;

/*     Look up the transformation from the ALPHAFIXED frame to the */
/*     ALPHA_VIEW_XY frame. The latter rotates with the orbital motion */
/*     of planet Alpha. */

    pxform_("ALPHAFIXED", "ALPHA_VIEW_XZ", &et0, xform, (ftnlen)10, (ftnlen)
	    13);

/*     Compute the boresight vector. */

    mxv_(xform, pos, vtemp);
    vhat_(vtemp, bsite);

/*     Compute the boundary vectors. */

    vsub_(center, viewpt, vtemp);
    vlcom_(&c_b13, sminor, &c_b13, vtemp, bvec);
    vlcom_(&c_b13, smajor, &c_b13, vtemp, &bvec[3]);
    vlcom_(&c_b15, sminor, &c_b13, vtemp, &bvec[6]);
    vlcom_(&c_b15, smajor, &c_b13, vtemp, &bvec[9]);

/*     Apply the transformation from the ALPHAFIXED frame to the */
/*     ALPHA_VIEW_XZ frame. The latter rotates with the orbital motion */
/*     of planet Alpha. */

    mxv_(xform, pos, vtemp);
    vhat_(vtemp, bsite);
    i__1 = nv;
    for (i__ = 1; i__ <= i__1; ++i__) {
	mxv_(xform, &bvec[(i__2 = i__ * 3 - 3) < 30 && 0 <= i__2 ? i__2 : 
		s_rnge("bvec", i__2, "natik_", (ftnlen)774)], &bnds[(i__3 = 
		i__ * 3 - 3) < 30 && 0 <= i__3 ? i__3 : s_rnge("bnds", i__3, 
		"natik_", (ftnlen)774)]);
	vhat_(&bnds[(i__2 = i__ * 3 - 3) < 30 && 0 <= i__2 ? i__2 : s_rnge(
		"bnds", i__2, "natik_", (ftnlen)776)], vtemp);
	vequ_(vtemp, &bnds[(i__2 = i__ * 3 - 3) < 30 && 0 <= i__2 ? i__2 : 
		s_rnge("bnds", i__2, "natik_", (ftnlen)777)]);
    }
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)781)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)783)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)785)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    begdat_(ch__1, (ftnlen)16);
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)787)) * 80, ch__1, (ftnlen)80, (ftnlen)16);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)789)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)792)) * 80, "NAIF_BODY_NAME += '#' ", (ftnlen)
	    80, (ftnlen)22);
    repmc_(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)793)) * 80, "#", insnam, tx + ((i__2 = l - 1) <
	     100 && 0 <= i__2 ? i__2 : s_rnge("tx", i__2, "natik_", (ftnlen)
	    793)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)36, (ftnlen)80);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)796)) * 80, "NAIF_BODY_CODE += #", (ftnlen)80, 
	    (ftnlen)19);
    repmi_(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)797)) * 80, "#", &inst, tx + ((i__2 = l - 1) < 
	    100 && 0 <= i__2 ? i__2 : s_rnge("tx", i__2, "natik_", (ftnlen)
	    797)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)800)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    ixinb = l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)804)) * 80, "INS#_FOV_SHAPE            = 'POL"
	    "YGON' ", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)806)) * 80, "INS#_FOV_FRAME            = 'ALP"
	    "HA_VIEW_XZ' ", (ftnlen)80, (ftnlen)44);
    ++l;
    ixbsb = l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)809)) * 80, "INS#_BORESIGHT            = ( *", 
	    (ftnlen)80, (ftnlen)31);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)811)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)813)) * 80, "                                "
	    "     * )", (ftnlen)80, (ftnlen)40);
    ++l;
    ixbcb = l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)816)) * 80, "INS#_FOV_BOUNDARY         = ( *", 
	    (ftnlen)80, (ftnlen)31);
    ixine = l;
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)819)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)821)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)823)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)825)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)827)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)829)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)831)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)833)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)835)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)837)) * 80, "                                "
	    "     *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)839)) * 80, "                                "
	    "     * )", (ftnlen)80, (ftnlen)40);
    ++l;
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)841)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    begtxt_(ch__1, (ftnlen)16);
    s_copy(tx + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("tx", i__1,
	     "natik_", (ftnlen)843)) * 80, ch__1, (ftnlen)80, (ftnlen)16);
    ++l;

/*     Set the instrument ID in the keywords above. */

    i__1 = ixine;
    for (i__ = ixinb; i__ <= i__1; ++i__) {
	repmi_(tx + ((i__2 = i__ - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(
		"tx", i__2, "natik_", (ftnlen)850)) * 80, "#", &inst, tx + ((
		i__3 = i__ - 1) < 100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3,
		 "natik_", (ftnlen)850)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)
		80);
    }

/*     Set the boresight values. */

    j = ixbsb - 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	repmd_(tx + ((i__1 = j + i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"tx", i__1, "natik_", (ftnlen)859)) * 80, "*", &bsite[(i__2 = 
		i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge("bsite", i__2, 
		"natik_", (ftnlen)859)], &c__14, tx + ((i__3 = j + i__ - 1) < 
		100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3, "natik_", (
		ftnlen)859)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    }

/*     Set the boundary corner values. */

    j = ixbcb - 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	repmd_(tx + ((i__1 = j + i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"tx", i__1, "natik_", (ftnlen)868)) * 80, "*", &bnds[(i__2 = 
		i__ - 1) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"natik_", (ftnlen)868)], &c__14, tx + ((i__3 = j + i__ - 1) < 
		100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3, "natik_", (
		ftnlen)868)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
	repmd_(tx + ((i__1 = j + i__ + 2) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"tx", i__1, "natik_", (ftnlen)869)) * 80, "*", &bnds[(i__2 = 
		i__ + 2) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"natik_", (ftnlen)869)], &c__14, tx + ((i__3 = j + i__ + 2) < 
		100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3, "natik_", (
		ftnlen)869)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
	repmd_(tx + ((i__1 = j + i__ + 5) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"tx", i__1, "natik_", (ftnlen)870)) * 80, "*", &bnds[(i__2 = 
		i__ + 5) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"natik_", (ftnlen)870)], &c__14, tx + ((i__3 = j + i__ + 5) < 
		100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3, "natik_", (
		ftnlen)870)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
	repmd_(tx + ((i__1 = j + i__ + 8) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"tx", i__1, "natik_", (ftnlen)871)) * 80, "*", &bnds[(i__2 = 
		i__ + 8) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"natik_", (ftnlen)871)], &c__14, tx + ((i__3 = j + i__ + 8) < 
		100 && 0 <= i__3 ? i__3 : s_rnge("tx", i__3, "natik_", (
		ftnlen)871)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    }
/* ********************************************************************** */

/*     Create the IK. */

/* ********************************************************************** */

/*     L is incremented after each assignment; decrement it here. */

    nl = l - 1;
    txtopn_(ik, &unit, ik_len);
    i__1 = nl;
    for (i__ = 1; i__ <= i__1; ++i__) {
	writln_(tx + ((i__2 = i__ - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(
		"tx", i__2, "natik_", (ftnlen)890)) * 80, &unit, (ftnlen)80);
    }
    cl__1.cerr = 0;
    cl__1.cunit = unit;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*     If this file needs to be loaded, do it. */

    if (*loadik) {
	ldpool_(ik, ik_len);
    }
    if (*keepik) {

/*        If we are keeping this file, we need to register it */
/*        with FILREG. */

	tfiles_(ik, ik_len);
    } else {

/*        Lose the file. */

	kilfil_(ik, ik_len);
    }
    if (! (*loadik)) {

/*        Unload the SPK. */

	spkuef_(&handle);
    }
    chkout_("NATIK", (ftnlen)5);
    return 0;
} /* natik_ */

