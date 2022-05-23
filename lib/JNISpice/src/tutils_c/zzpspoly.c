/* zzpspoly.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__2 = 2;
static integer c__3 = 3;

/* $Procedure ZZPSPOLY ( Plate set, create polygon ) */
/* Subroutine */ int zzpspoly_(integer *n, doublereal *vrtces, doublereal *
	vout, integer *pout)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    doublereal perp[2];
    integer i__, j;
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    extern integer sized_(doublereal *);
    extern doublereal vdotg_(doublereal *, doublereal *, integer *);
    extern integer sizei_(integer *);
    integer cpout, cvout;
    extern /* Subroutine */ int cleard_(integer *, doublereal *);
    integer np;
    extern /* Subroutine */ int scardd_(integer *, doublereal *);
    integer nv;
    extern /* Subroutine */ int scardi_(integer *, integer *), sigerr_(char *,
	     ftnlen), chkout_(char *, ftnlen), setmsg_(char *, ftnlen), 
	    errint_(char *, integer *, ftnlen);
    extern logical return_(void);

/* $ Abstract */

/*     Create a plate set with a polygonal boundary in the X-Y plane. */
/*     The normal vectors of the plates point in the +Z direction. */

/*     The input vertices are required to be ordered in the positive */
/*     sense about the +Z axis. */

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

/*     CELLS */
/*     DSK */

/* $ Keywords */

/*     DSK */
/*     PLATE */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     N          I   Number of vertices in the polygon. */
/*     VRTCES     I   2-D vertices of the polygon. */
/*     VOUT       O   Vertex cell of the plate set. */
/*     POUT       O   Plate cell of the plate set. */

/* $ Detailed_Input */

/*     N              is the number of vertices in the polygon. */

/*     VRTCES         is an array of 2-D vertices. The vertices must be */
/*                    ordered in the positive (counterclockwise) sense */
/*                    about the +Z axis. */

/* $ Detailed_Output */

/*     VOUT           is a SPICELIB double precision cell containing the */
/*                    (3-D) vertices of a plate set representing planar */
/*                    region bounded by the polygon. */

/*     POUT           is a SPICELIB integer cell containing the plates */
/*                    of the plate set. The vertices of each plate are */
/*                    ordered so that they define a normal vector */
/*                    pointing in the +Z direction. */

/* $ Parameters */

/*     LBCELL is the lower bound of the SPICELIB cell data structure. */

/* $ Exceptions */

/*     1) If the size of VOUT is too small to contain the output */
/*        plate set's vertices, the error SPICE(VERTARRAYTOOSMALL) is */
/*        signaled. */

/*     2) If the size of POUT is too small to contain the output plate */
/*        set's plates, the error SPICE(PLTARRAYTOOSMALL) is signaled. */

/*     3) Any other errors that occur while accessing SPICE cells */
/*        will be diagnosed by routines in the call tree of this */
/*        routine. */

/*     4) If the vertices are not ordered in the positive sense */
/*        about the +Z axis, the error SPICE(BADVERTEXORDER) will be */
/*        signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    DSKLIB Version 1.0.0, 04-SEP-2014 (NJB) */

/* -& */

/*     SPICELIB functions */


/*     Local variables */

    if (return_()) {
	return 0;
    }
    chkin_("ZZPSPOLY", (ftnlen)8);

/*     Check the space in the output cells. */

    nv = *n + 1;
    cvout = nv * 3;
    np = *n;
    cpout = np * 3;
    if (sized_(vout) < cvout) {
	setmsg_("Output vertex array size is #; required space is # elements."
		, (ftnlen)60);
	i__1 = sized_(vout);
	errint_("#", &i__1, (ftnlen)1);
	errint_("#", &cvout, (ftnlen)1);
	sigerr_("SPICE(VERTARRAYTOOSMALL)", (ftnlen)24);
	chkout_("ZZPSPOLY", (ftnlen)8);
	return 0;
    }
    if (sizei_(pout) < cpout) {
	setmsg_("Output plate array size is #; required space is # elements.",
		 (ftnlen)59);
	i__1 = sizei_(pout);
	errint_("#", &i__1, (ftnlen)1);
	errint_("#", &cpout, (ftnlen)1);
	sigerr_("SPICE(PLTARRAYTOOSMALL)", (ftnlen)23);
	chkout_("ZZPSPOLY", (ftnlen)8);
	return 0;
    }

/*     Check the order of the input vertices. */

    i__1 = *n - 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	perp[0] = -vrtces[(i__ << 1) - 1];
	perp[1] = vrtces[(i__ << 1) - 2];
	if (vdotg_(&vrtces[(i__ + 1 << 1) - 2], perp, &c__2) <= 0.) {
	    setmsg_("Input vertices are not in strictly increasing order: ro"
		    "tation angle from vertex # to vertex # about the +Z axis"
		    " is not positive.", (ftnlen)128);
	    errint_("#", &i__, (ftnlen)1);
	    i__2 = i__ + 1;
	    errint_("#", &i__2, (ftnlen)1);
	    sigerr_("SPICE(BADVERTEXORDER)", (ftnlen)21);
	    chkout_("ZZPSPOLY", (ftnlen)8);
	    return 0;
	}
    }

/*     Create 3-D vertices. */

    j = 1;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	vout[j + 5] = vrtces[(i__ << 1) - 2];
	vout[j + 6] = vrtces[(i__ << 1) - 1];
	vout[j + 7] = 0.;
	j += 3;
    }

/*     The last vertex is the origin. */

    cleard_(&c__3, &vout[cvout + 3]);
    scardd_(&cvout, vout);

/*     Create plates. */

    j = 1;
    i__1 = *n - 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	pout[j + 5] = nv;
	pout[j + 6] = i__;
	pout[j + 7] = i__ + 1;
	j += 3;
    }

/*     Fill in the last plate. */

    pout[j + 5] = nv;
    pout[j + 6] = *n;
    pout[j + 7] = 1;
    scardi_(&cpout, pout);
    chkout_("ZZPSPOLY", (ftnlen)8);
    return 0;
} /* zzpspoly_ */

