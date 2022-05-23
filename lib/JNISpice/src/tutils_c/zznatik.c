/* zznatik.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__3 = 3;
static doublereal c_b13 = 1.;
static doublereal c_b15 = -1.;
static integer c__14 = 14;

/* $Procedure ZZNATIK (Create an SCLK file) */
/* Subroutine */ int zznatik_(char *nameik, char *spk, char *pck, ftnlen 
	nameik_len, ftnlen spk_len, ftnlen pck_len)
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
    integer ixbsb;
    extern /* Subroutine */ int repmc_(char *, char *, char *, char *, ftnlen,
	     ftnlen, ftnlen, ftnlen);
    integer ixinb;
    extern /* Subroutine */ int repmd_(char *, char *, doublereal *, integer *
	    , char *, ftnlen, ftnlen, ftnlen);
    integer ixine;
    extern /* Subroutine */ int repmi_(char *, char *, integer *, char *, 
	    ftnlen, ftnlen, ftnlen), vlcom_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    doublereal xform[9]	/* was [3][3] */, vtemp[3];
    extern /* Subroutine */ int el2cgv_(doublereal *, doublereal *, 
	    doublereal *, doublereal *), vlcom3_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);
    char ik[80*100];
    extern /* Character */ VOID begdat_(char *, ftnlen);
    integer nl;
    extern /* Subroutine */ int edlimb_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    doublereal lt;
    integer nv;
    extern /* Subroutine */ int kilfil_(char *, ftnlen);
    doublereal center[3];
    extern /* Subroutine */ int bodvrd_(char *, char *, integer *, integer *, 
	    doublereal *, ftnlen, ftnlen), unload_(char *, ftnlen);
    char insnam[36];
    doublereal smajor[3];
    extern /* Character */ VOID begtxt_(char *, ftnlen);
    extern /* Subroutine */ int chkout_(char *, ftnlen), furnsh_(char *, 
	    ftnlen);
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

/*     Create a test IK text kernel named NAMEIK. This IK */
/*     will correspond only to the Nat's Solar System SPK */
/*     and PCK */

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

/*   None. */

/* $ Keywords */

/*   None. */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */

/* $ Detailed_Input */

/*   None. */

/* $ Detailed_Output */

/*   None. */

/* $ Parameters */

/*   None. */

/* $ Exceptions */

/*   None. */

/* $ Files */

/*   None. */

/* $ Particulars */

/*   None. */

/* $ Examples */

/*   None. */

/* $ Restrictions */

/*   None. */

/* $ Literature_References */

/*   None. */

/* $ Author_and_Institution */

/*   None. */

/* $ Version */

/* -    Test Utilities 1.0.0, 18-AUG-2008 (EDW) */

/*        Reimplementation of NATIK removing all code */
/*        except that needed to write the test IK. */
/* -& */
/* $ Index_Entries */

/*   None. */

/* -& */

/*     Test Utility Functions */


/*     Local Parameters */


/*     Local variables */

    chkin_("ZZNATIK", (ftnlen)7);

/*     Delete any existing file of the same name. */

    kilfil_(nameik, nameik_len);
    furnsh_(pck, pck_len);
    furnsh_(spk, spk_len);

/*     Before creating the IK, we derive the parameters */
/*     needed to create the intrument FOVs we'll specify there. */

/*     Load the Nat's solar system SPK and PCK. */

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
		s_rnge("bvec", i__1, "zznatik_", (ftnlen)257)], &bnds[(i__2 = 
		i__ * 3 - 3) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"zznatik_", (ftnlen)257)]);
    }

/*     As obnoxious as the practice may seem, we'll use the variable */
/*     L instead of hard-coded constants to index buffer elements. */
/*     Hard-coded indices are a big problem when changes are needed. */

    l = 1;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)266)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)268)) * 80, " KPL/IK", (ftnlen)80, (ftnlen)7)
	    ;
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)270)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    begdat_(ch__1, (ftnlen)16);
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)272)) * 80, ch__1, (ftnlen)80, (ftnlen)16);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)274)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)277)) * 80, "NAIF_BODY_NAME += '#' ", (
	    ftnlen)80, (ftnlen)22);
    repmc_(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)278)) * 80, "#", insnam, ik + ((i__2 = l - 1)
	     < 100 && 0 <= i__2 ? i__2 : s_rnge("ik", i__2, "zznatik_", (
	    ftnlen)278)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)36, (ftnlen)80);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)281)) * 80, "NAIF_BODY_CODE += #", (ftnlen)
	    80, (ftnlen)19);
    repmi_(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)282)) * 80, "#", &inst, ik + ((i__2 = l - 1) 
	    < 100 && 0 <= i__2 ? i__2 : s_rnge("ik", i__2, "zznatik_", (
	    ftnlen)282)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)285)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    ixinb = l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)289)) * 80, "INS#_FOV_SHAPE            = 'E"
	    "LLIPSE' ", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)291)) * 80, "INS#_FOV_FRAME            = 'A"
	    "LPHA_VIEW_XY' ", (ftnlen)80, (ftnlen)44);
    ++l;
    ixbsb = l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)294)) * 80, "INS#_BORESIGHT            = ( *"
	    , (ftnlen)80, (ftnlen)31);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)296)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)298)) * 80, "                              "
	    "       * )", (ftnlen)80, (ftnlen)40);
    ++l;
    ixbcb = l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)301)) * 80, "INS#_FOV_BOUNDARY         = ( *"
	    , (ftnlen)80, (ftnlen)31);
    ixine = l;
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)304)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)306)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)308)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)310)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)312)) * 80, "                              "
	    "       * )", (ftnlen)80, (ftnlen)40);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)314)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    begtxt_(ch__1, (ftnlen)16);
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)316)) * 80, ch__1, (ftnlen)80, (ftnlen)16);
    ++l;

/*     Set the instrument ID in the keywords above. */

    i__1 = ixine;
    for (i__ = ixinb; i__ <= i__1; ++i__) {
	repmi_(ik + ((i__2 = i__ - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(
		"ik", i__2, "zznatik_", (ftnlen)323)) * 80, "#", &inst, ik + (
		(i__3 = i__ - 1) < 100 && 0 <= i__3 ? i__3 : s_rnge("ik", 
		i__3, "zznatik_", (ftnlen)323)) * 80, (ftnlen)80, (ftnlen)1, (
		ftnlen)80);
    }

/*     Set the boresight values. */

    j = ixbsb - 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	repmd_(ik + ((i__1 = j + i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"ik", i__1, "zznatik_", (ftnlen)332)) * 80, "*", &bsite[(i__2 
		= i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge("bsite", i__2, 
		"zznatik_", (ftnlen)332)], &c__14, ik + ((i__3 = j + i__ - 1) 
		< 100 && 0 <= i__3 ? i__3 : s_rnge("ik", i__3, "zznatik_", (
		ftnlen)332)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    }

/*     Set the boundary corner values. */

    j = ixbcb - 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	repmd_(ik + ((i__1 = j + i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"ik", i__1, "zznatik_", (ftnlen)341)) * 80, "*", &bnds[(i__2 =
		 i__ - 1) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"zznatik_", (ftnlen)341)], &c__14, ik + ((i__3 = j + i__ - 1) 
		< 100 && 0 <= i__3 ? i__3 : s_rnge("ik", i__3, "zznatik_", (
		ftnlen)341)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
	repmd_(ik + ((i__1 = j + i__ + 2) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"ik", i__1, "zznatik_", (ftnlen)342)) * 80, "*", &bnds[(i__2 =
		 i__ + 2) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"zznatik_", (ftnlen)342)], &c__14, ik + ((i__3 = j + i__ + 2) 
		< 100 && 0 <= i__3 ? i__3 : s_rnge("ik", i__3, "zznatik_", (
		ftnlen)342)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
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
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)390)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)392)) * 80, " KPL/IK", (ftnlen)80, (ftnlen)7)
	    ;
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)394)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    begdat_(ch__1, (ftnlen)16);
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)396)) * 80, ch__1, (ftnlen)80, (ftnlen)16);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)398)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)401)) * 80, "NAIF_BODY_NAME += '#' ", (
	    ftnlen)80, (ftnlen)22);
    repmc_(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)402)) * 80, "#", insnam, ik + ((i__2 = l - 1)
	     < 100 && 0 <= i__2 ? i__2 : s_rnge("ik", i__2, "zznatik_", (
	    ftnlen)402)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)36, (ftnlen)80);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)405)) * 80, "NAIF_BODY_CODE += #", (ftnlen)
	    80, (ftnlen)19);
    repmi_(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)406)) * 80, "#", &inst, ik + ((i__2 = l - 1) 
	    < 100 && 0 <= i__2 ? i__2 : s_rnge("ik", i__2, "zznatik_", (
	    ftnlen)406)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)409)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    ixinb = l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)413)) * 80, "INS#_FOV_SHAPE            = 'C"
	    "IRCLE' ", (ftnlen)80, (ftnlen)37);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)415)) * 80, "INS#_FOV_FRAME            = 'A"
	    "LPHA_VIEW_XY' ", (ftnlen)80, (ftnlen)44);
    ++l;
    ixbsb = l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)418)) * 80, "INS#_BORESIGHT            = ( *"
	    , (ftnlen)80, (ftnlen)31);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)420)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)422)) * 80, "                              "
	    "       * )", (ftnlen)80, (ftnlen)40);
    ++l;
    ixbcb = l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)425)) * 80, "INS#_FOV_BOUNDARY         = ( *"
	    , (ftnlen)80, (ftnlen)31);
    ixine = l;
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)428)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)430)) * 80, "                              "
	    "       * )", (ftnlen)80, (ftnlen)40);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)432)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    begtxt_(ch__1, (ftnlen)16);
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)434)) * 80, ch__1, (ftnlen)80, (ftnlen)16);
    ++l;

/*     Set the instrument ID in the keywords above. */

    i__1 = ixine;
    for (i__ = ixinb; i__ <= i__1; ++i__) {
	repmi_(ik + ((i__2 = i__ - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(
		"ik", i__2, "zznatik_", (ftnlen)441)) * 80, "#", &inst, ik + (
		(i__3 = i__ - 1) < 100 && 0 <= i__3 ? i__3 : s_rnge("ik", 
		i__3, "zznatik_", (ftnlen)441)) * 80, (ftnlen)80, (ftnlen)1, (
		ftnlen)80);
    }

/*     Set the boresight values. */

    j = ixbsb - 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	repmd_(ik + ((i__1 = j + i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"ik", i__1, "zznatik_", (ftnlen)450)) * 80, "*", &bsite[(i__2 
		= i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge("bsite", i__2, 
		"zznatik_", (ftnlen)450)], &c__14, ik + ((i__3 = j + i__ - 1) 
		< 100 && 0 <= i__3 ? i__3 : s_rnge("ik", i__3, "zznatik_", (
		ftnlen)450)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    }

/*     Set the boundary corner values. */

    j = ixbcb - 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	repmd_(ik + ((i__1 = j + i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"ik", i__1, "zznatik_", (ftnlen)459)) * 80, "*", &bnds[(i__2 =
		 i__ - 1) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"zznatik_", (ftnlen)459)], &c__14, ik + ((i__3 = j + i__ - 1) 
		< 100 && 0 <= i__3 ? i__3 : s_rnge("ik", i__3, "zznatik_", (
		ftnlen)459)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
	repmd_(ik + ((i__1 = j + i__ + 2) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"ik", i__1, "zznatik_", (ftnlen)460)) * 80, "*", &bnds[(i__2 =
		 i__ + 2) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"zznatik_", (ftnlen)460)], &c__14, ik + ((i__3 = j + i__ + 2) 
		< 100 && 0 <= i__3 ? i__3 : s_rnge("ik", i__3, "zznatik_", (
		ftnlen)460)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
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
		s_rnge("bvec", i__2, "zznatik_", (ftnlen)531)], &bnds[(i__3 = 
		i__ * 3 - 3) < 30 && 0 <= i__3 ? i__3 : s_rnge("bnds", i__3, 
		"zznatik_", (ftnlen)531)]);
	vhat_(&bnds[(i__2 = i__ * 3 - 3) < 30 && 0 <= i__2 ? i__2 : s_rnge(
		"bnds", i__2, "zznatik_", (ftnlen)533)], vtemp);
	vequ_(vtemp, &bnds[(i__2 = i__ * 3 - 3) < 30 && 0 <= i__2 ? i__2 : 
		s_rnge("bnds", i__2, "zznatik_", (ftnlen)534)]);
    }
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)538)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)540)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)542)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    begdat_(ch__1, (ftnlen)16);
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)544)) * 80, ch__1, (ftnlen)80, (ftnlen)16);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)546)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)549)) * 80, "NAIF_BODY_NAME += '#' ", (
	    ftnlen)80, (ftnlen)22);
    repmc_(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)550)) * 80, "#", insnam, ik + ((i__2 = l - 1)
	     < 100 && 0 <= i__2 ? i__2 : s_rnge("ik", i__2, "zznatik_", (
	    ftnlen)550)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)36, (ftnlen)80);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)553)) * 80, "NAIF_BODY_CODE += #", (ftnlen)
	    80, (ftnlen)19);
    repmi_(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)554)) * 80, "#", &inst, ik + ((i__2 = l - 1) 
	    < 100 && 0 <= i__2 ? i__2 : s_rnge("ik", i__2, "zznatik_", (
	    ftnlen)554)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)557)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    ixinb = l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)561)) * 80, "INS#_FOV_SHAPE            = 'R"
	    "ECTANGLE' ", (ftnlen)80, (ftnlen)40);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)563)) * 80, "INS#_FOV_FRAME            = 'A"
	    "LPHA_VIEW_XY' ", (ftnlen)80, (ftnlen)44);
    ++l;
    ixbsb = l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)566)) * 80, "INS#_BORESIGHT            = ( *"
	    , (ftnlen)80, (ftnlen)31);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)568)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)570)) * 80, "                              "
	    "       * )", (ftnlen)80, (ftnlen)40);
    ++l;
    ixbcb = l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)573)) * 80, "INS#_FOV_BOUNDARY         = ( *"
	    , (ftnlen)80, (ftnlen)31);
    ixine = l;
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)576)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)578)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)580)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)582)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)584)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)586)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)588)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)590)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)592)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)594)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)596)) * 80, "                              "
	    "       * )", (ftnlen)80, (ftnlen)40);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)598)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    begtxt_(ch__1, (ftnlen)16);
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)600)) * 80, ch__1, (ftnlen)80, (ftnlen)16);
    ++l;

/*     Set the instrument ID in the keywords above. */

    i__1 = ixine;
    for (i__ = ixinb; i__ <= i__1; ++i__) {
	repmi_(ik + ((i__2 = i__ - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(
		"ik", i__2, "zznatik_", (ftnlen)607)) * 80, "#", &inst, ik + (
		(i__3 = i__ - 1) < 100 && 0 <= i__3 ? i__3 : s_rnge("ik", 
		i__3, "zznatik_", (ftnlen)607)) * 80, (ftnlen)80, (ftnlen)1, (
		ftnlen)80);
    }

/*     Set the boresight values. */

    j = ixbsb - 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	repmd_(ik + ((i__1 = j + i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"ik", i__1, "zznatik_", (ftnlen)616)) * 80, "*", &bsite[(i__2 
		= i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge("bsite", i__2, 
		"zznatik_", (ftnlen)616)], &c__14, ik + ((i__3 = j + i__ - 1) 
		< 100 && 0 <= i__3 ? i__3 : s_rnge("ik", i__3, "zznatik_", (
		ftnlen)616)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    }

/*     Set the boundary corner values. */

    j = ixbcb - 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	repmd_(ik + ((i__1 = j + i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"ik", i__1, "zznatik_", (ftnlen)625)) * 80, "*", &bnds[(i__2 =
		 i__ - 1) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"zznatik_", (ftnlen)625)], &c__14, ik + ((i__3 = j + i__ - 1) 
		< 100 && 0 <= i__3 ? i__3 : s_rnge("ik", i__3, "zznatik_", (
		ftnlen)625)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
	repmd_(ik + ((i__1 = j + i__ + 2) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"ik", i__1, "zznatik_", (ftnlen)626)) * 80, "*", &bnds[(i__2 =
		 i__ + 2) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"zznatik_", (ftnlen)626)], &c__14, ik + ((i__3 = j + i__ + 2) 
		< 100 && 0 <= i__3 ? i__3 : s_rnge("ik", i__3, "zznatik_", (
		ftnlen)626)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
	repmd_(ik + ((i__1 = j + i__ + 5) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"ik", i__1, "zznatik_", (ftnlen)627)) * 80, "*", &bnds[(i__2 =
		 i__ + 5) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"zznatik_", (ftnlen)627)], &c__14, ik + ((i__3 = j + i__ + 5) 
		< 100 && 0 <= i__3 ? i__3 : s_rnge("ik", i__3, "zznatik_", (
		ftnlen)627)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
	repmd_(ik + ((i__1 = j + i__ + 8) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"ik", i__1, "zznatik_", (ftnlen)628)) * 80, "*", &bnds[(i__2 =
		 i__ + 8) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"zznatik_", (ftnlen)628)], &c__14, ik + ((i__3 = j + i__ + 8) 
		< 100 && 0 <= i__3 ? i__3 : s_rnge("ik", i__3, "zznatik_", (
		ftnlen)628)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
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
		s_rnge("bvec", i__2, "zznatik_", (ftnlen)691)], &bnds[(i__3 = 
		i__ * 3 - 3) < 30 && 0 <= i__3 ? i__3 : s_rnge("bnds", i__3, 
		"zznatik_", (ftnlen)691)]);
	vhat_(&bnds[(i__2 = i__ * 3 - 3) < 30 && 0 <= i__2 ? i__2 : s_rnge(
		"bnds", i__2, "zznatik_", (ftnlen)693)], vtemp);
	vequ_(vtemp, &bnds[(i__2 = i__ * 3 - 3) < 30 && 0 <= i__2 ? i__2 : 
		s_rnge("bnds", i__2, "zznatik_", (ftnlen)694)]);
    }
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)698)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)700)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)702)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    begdat_(ch__1, (ftnlen)16);
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)704)) * 80, ch__1, (ftnlen)80, (ftnlen)16);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)706)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)709)) * 80, "NAIF_BODY_NAME += '#' ", (
	    ftnlen)80, (ftnlen)22);
    repmc_(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)710)) * 80, "#", insnam, ik + ((i__2 = l - 1)
	     < 100 && 0 <= i__2 ? i__2 : s_rnge("ik", i__2, "zznatik_", (
	    ftnlen)710)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)36, (ftnlen)80);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)713)) * 80, "NAIF_BODY_CODE += #", (ftnlen)
	    80, (ftnlen)19);
    repmi_(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)714)) * 80, "#", &inst, ik + ((i__2 = l - 1) 
	    < 100 && 0 <= i__2 ? i__2 : s_rnge("ik", i__2, "zznatik_", (
	    ftnlen)714)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)717)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    ixinb = l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)721)) * 80, "INS#_FOV_SHAPE            = 'P"
	    "OLYGON' ", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)723)) * 80, "INS#_FOV_FRAME            = 'A"
	    "LPHA_VIEW_XZ' ", (ftnlen)80, (ftnlen)44);
    ++l;
    ixbsb = l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)726)) * 80, "INS#_BORESIGHT            = ( *"
	    , (ftnlen)80, (ftnlen)31);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)728)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)730)) * 80, "                              "
	    "       * )", (ftnlen)80, (ftnlen)40);
    ++l;
    ixbcb = l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)733)) * 80, "INS#_FOV_BOUNDARY         = ( *"
	    , (ftnlen)80, (ftnlen)31);
    ixine = l;
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)736)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)738)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)740)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)742)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)744)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)746)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)748)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)750)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)752)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)754)) * 80, "                              "
	    "       *", (ftnlen)80, (ftnlen)38);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)756)) * 80, "                              "
	    "       * )", (ftnlen)80, (ftnlen)40);
    ++l;
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)758)) * 80, " ", (ftnlen)80, (ftnlen)1);
    ++l;
    begtxt_(ch__1, (ftnlen)16);
    s_copy(ik + ((i__1 = l - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge("ik", i__1,
	     "zznatik_", (ftnlen)760)) * 80, ch__1, (ftnlen)80, (ftnlen)16);
    ++l;

/*     Set the instrument ID in the keywords above. */

    i__1 = ixine;
    for (i__ = ixinb; i__ <= i__1; ++i__) {
	repmi_(ik + ((i__2 = i__ - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(
		"ik", i__2, "zznatik_", (ftnlen)767)) * 80, "#", &inst, ik + (
		(i__3 = i__ - 1) < 100 && 0 <= i__3 ? i__3 : s_rnge("ik", 
		i__3, "zznatik_", (ftnlen)767)) * 80, (ftnlen)80, (ftnlen)1, (
		ftnlen)80);
    }

/*     Set the boresight values. */

    j = ixbsb - 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	repmd_(ik + ((i__1 = j + i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"ik", i__1, "zznatik_", (ftnlen)776)) * 80, "*", &bsite[(i__2 
		= i__ - 1) < 3 && 0 <= i__2 ? i__2 : s_rnge("bsite", i__2, 
		"zznatik_", (ftnlen)776)], &c__14, ik + ((i__3 = j + i__ - 1) 
		< 100 && 0 <= i__3 ? i__3 : s_rnge("ik", i__3, "zznatik_", (
		ftnlen)776)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    }

/*     Set the boundary corner values. */

    j = ixbcb - 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	repmd_(ik + ((i__1 = j + i__ - 1) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"ik", i__1, "zznatik_", (ftnlen)785)) * 80, "*", &bnds[(i__2 =
		 i__ - 1) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"zznatik_", (ftnlen)785)], &c__14, ik + ((i__3 = j + i__ - 1) 
		< 100 && 0 <= i__3 ? i__3 : s_rnge("ik", i__3, "zznatik_", (
		ftnlen)785)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
	repmd_(ik + ((i__1 = j + i__ + 2) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"ik", i__1, "zznatik_", (ftnlen)786)) * 80, "*", &bnds[(i__2 =
		 i__ + 2) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"zznatik_", (ftnlen)786)], &c__14, ik + ((i__3 = j + i__ + 2) 
		< 100 && 0 <= i__3 ? i__3 : s_rnge("ik", i__3, "zznatik_", (
		ftnlen)786)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
	repmd_(ik + ((i__1 = j + i__ + 5) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"ik", i__1, "zznatik_", (ftnlen)787)) * 80, "*", &bnds[(i__2 =
		 i__ + 5) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"zznatik_", (ftnlen)787)], &c__14, ik + ((i__3 = j + i__ + 5) 
		< 100 && 0 <= i__3 ? i__3 : s_rnge("ik", i__3, "zznatik_", (
		ftnlen)787)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
	repmd_(ik + ((i__1 = j + i__ + 8) < 100 && 0 <= i__1 ? i__1 : s_rnge(
		"ik", i__1, "zznatik_", (ftnlen)788)) * 80, "*", &bnds[(i__2 =
		 i__ + 8) < 30 && 0 <= i__2 ? i__2 : s_rnge("bnds", i__2, 
		"zznatik_", (ftnlen)788)], &c__14, ik + ((i__3 = j + i__ + 8) 
		< 100 && 0 <= i__3 ? i__3 : s_rnge("ik", i__3, "zznatik_", (
		ftnlen)788)) * 80, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    }
/* ********************************************************************** */

/*     Create the IK. */

/* ********************************************************************** */
    unload_(pck, pck_len);
    unload_(spk, spk_len);

/*     L is incremented after each assignment; decrement it here. */

    nl = l - 1;
    txtopn_(nameik, &unit, nameik_len);
    i__1 = nl;
    for (i__ = 1; i__ <= i__1; ++i__) {
	writln_(ik + ((i__2 = i__ - 1) < 100 && 0 <= i__2 ? i__2 : s_rnge(
		"ik", i__2, "zznatik_", (ftnlen)810)) * 80, &unit, (ftnlen)80)
		;
    }
    cl__1.cerr = 0;
    cl__1.cunit = unit;
    cl__1.csta = 0;
    f_clos(&cl__1);
    chkout_("ZZNATIK", (ftnlen)7);
    return 0;
} /* zznatik_ */

