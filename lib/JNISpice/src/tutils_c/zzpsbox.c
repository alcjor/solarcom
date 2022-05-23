/* zzpsbox.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* $Procedure ZZPSBOX ( Plate set, create box ) */
/* Subroutine */ int zzpsbox_(doublereal *a, doublereal *b, doublereal *c__, 
	doublereal *vout, integer *pout)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    integer j;
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    integer plate[36]	/* was [3][12] */;
    extern /* Subroutine */ int errdp_(char *, doublereal *, ftnlen);
    extern integer sized_(doublereal *);
    extern /* Subroutine */ int movei_(integer *, integer *, integer *);
    extern integer sizei_(integer *);
    integer cpout, cvout, np;
    extern /* Subroutine */ int scardd_(integer *, doublereal *);
    integer ix, iy, iz, nv;
    extern /* Subroutine */ int scardi_(integer *, integer *), sigerr_(char *,
	     ftnlen), chkout_(char *, ftnlen), setmsg_(char *, ftnlen), 
	    errint_(char *, integer *, ftnlen);
    extern logical return_(void);

/* $ Abstract */

/*     Create a plate set representing a box centered at the origin. */
/*     The dimensions of the box are specified by the caller. */

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
/*     A          I   Box edge length in the X direction. */
/*     B          I   Box edge length in the Y direction. */
/*     C          I   Box edge length in the Z direction. */
/*     VOUT       O   Vertex cell of the plate set. */
/*     POUT       O   Plate cell of the plate set. */

/* $ Detailed_Input */

/*     A, */
/*     B, */
/*     C              are the edge lengths of the box in the */
/*                    X, Y, and Z directions, respectively. */

/* $ Detailed_Output */

/*     VOUT           is a SPICELIB double precision cell containing the */
/*                    vertices of a plate set representing the surface */
/*                    of a box having dimensions A x B x C. The edges of */
/*                    the box are parallel to the coordinate axes. The */
/*                    box is centered at the origin. */

/*     POUT           is a SPICELIB integer cell containing the plates */
/*                    of the plate set. The vertices of each plate are */
/*                    ordered so that they define an outward normal */
/*                    vector having positive dot product with the */
/*                    plate's vertices. (In other words, the normal */
/*                    vectors point outward.) */

/* $ Parameters */

/*    LBCELL is the lower bound of the SPICELIB cell data structure. */

/* $ Exceptions */

/*     1) If the size of VOUT is too small to contain the output */
/*        plate set's vertices, the error SPICE(VERTARRAYTOOSMALL) is */
/*        signaled. */

/*     2) If the size of POUT is too small to contain the output plate */
/*        set's plates, the error SPICE(PLTARRAYTOOSMALL) is signaled. */

/*     3) Any other errors that occur while accessing SPICE cells */
/*        will be diagnosed by routines in the call tree of this */
/*        routine. */

/*     4) If any of the box dimensions are non-positive, the error */
/*        SPICE(INVALIDEDGELENGTH) will be signaled. */

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

/* -    DSKLIB Version 1.0.0, 05-SEP-2014 (NJB) */

/* -& */

/*     SPICELIB functions */


/*     Local variables */

    if (return_()) {
	return 0;
    }
    chkin_("ZZPSBOX", (ftnlen)7);

/*     Check the space in the output cells. */

    nv = 8;
    cvout = nv * 3;
    np = 12;
    cpout = np * 3;
    if (sized_(vout) < cvout) {
	setmsg_("Output vertex array is too small to contain box vertex arra"
		"y. Output vertex array size is #; required space is # elemen"
		"ts.", (ftnlen)122);
	i__1 = sized_(vout);
	errint_("#", &i__1, (ftnlen)1);
	errint_("#", &cvout, (ftnlen)1);
	sigerr_("SPICE(VERTARRAYTOOSMALL)", (ftnlen)24);
	chkout_("ZZPSBOX", (ftnlen)7);
	return 0;
    }
    if (sizei_(pout) < cpout) {
	setmsg_("Output plate array is too small to contain box plate array."
		" Output plate array size is #; required space is # elements.",
		 (ftnlen)119);
	i__1 = sizei_(pout);
	errint_("#", &i__1, (ftnlen)1);
	errint_("#", &cpout, (ftnlen)1);
	sigerr_("SPICE(PLTARRAYTOOSMALL)", (ftnlen)23);
	chkout_("ZZPSBOX", (ftnlen)7);
	return 0;
    }

/*     Check the box dimensions. */

    if (*a <= 0. || *b <= 0. || *c__ <= 0.) {
	setmsg_("Box dimensions must be positive. Actual dimensions were A ="
		" #; B = #; C = #.", (ftnlen)76);
	errdp_("#", a, (ftnlen)1);
	errdp_("#", b, (ftnlen)1);
	errdp_("#", c__, (ftnlen)1);
	sigerr_("SPICE(INVALIDDGELENGTH)", (ftnlen)23);
	chkout_("ZZPSBOX", (ftnlen)7);
	return 0;
    }

/*     Create the vertices. */

    j = 1;
    for (iz = 0; iz <= 1; ++iz) {
	for (iy = 0; iy <= 1; ++iy) {
	    for (ix = 0; ix <= 1; ++ix) {
		vout[j + 7] = (iz - .5) * *c__;
		vout[j + 6] = (iy - .5) * *b;
		vout[j + 5] = (ix - .5) * *a;
		j += 3;
	    }
	}
    }
    scardd_(&cvout, vout);

/*     Create the plates. */


/*     +Z face: */

    plate[0] = 5;
    plate[1] = 6;
    plate[2] = 7;
    plate[3] = 6;
    plate[4] = 8;
    plate[5] = 7;

/*     -Z face: */

    plate[6] = 1;
    plate[7] = 3;
    plate[8] = 2;
    plate[9] = 2;
    plate[10] = 3;
    plate[11] = 4;

/*     +Y face: */

    plate[12] = 4;
    plate[13] = 3;
    plate[14] = 8;
    plate[15] = 3;
    plate[16] = 7;
    plate[17] = 8;

/*     -Y face: */

    plate[18] = 1;
    plate[19] = 2;
    plate[20] = 5;
    plate[21] = 2;
    plate[22] = 6;
    plate[23] = 5;

/*     +X face: */

    plate[24] = 2;
    plate[25] = 4;
    plate[26] = 6;
    plate[27] = 4;
    plate[28] = 8;
    plate[29] = 6;

/*     -X face: */

    plate[30] = 3;
    plate[31] = 1;
    plate[32] = 7;
    plate[33] = 1;
    plate[34] = 5;
    plate[35] = 7;
    movei_(plate, &cpout, &pout[6]);
    scardi_(&cpout, pout);
    chkout_("ZZPSBOX", (ftnlen)7);
    return 0;
} /* zzpsbox_ */

