/* zzpsun.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* $Procedure ZZPSUN ( Plate set union ) */
/* Subroutine */ int zzpsun_(doublereal *v1, integer *p1, doublereal *v2, 
	integer *p2, doublereal *vout, integer *pout)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    integer i__;
    extern integer cardd_(doublereal *), cardi_(integer *);
    extern /* Subroutine */ int chkin_(char *, ftnlen), moved_(doublereal *, 
	    integer *, doublereal *);
    extern integer sized_(doublereal *);
    extern /* Subroutine */ int copyd_(doublereal *, doublereal *);
    extern integer sizei_(integer *);
    extern /* Subroutine */ int copyi_(integer *, integer *);
    integer cpout, cvout;
    extern /* Subroutine */ int scardd_(integer *, doublereal *), scardi_(
	    integer *, integer *), sigerr_(char *, ftnlen), chkout_(char *, 
	    ftnlen), setmsg_(char *, ftnlen), errint_(char *, integer *, 
	    ftnlen);
    integer cp1, cp2, cv1, cv2;
    extern logical return_(void);

/* $ Abstract */

/*     Compute the union of two plate sets. */

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
/*     V1         I   Vertex cell of first plate set. */
/*     P1         I   Plate cell of first plate set. */
/*     V2         I   Vertex cell of second plate set. */
/*     P2         I   Plate cell of second plate set. */
/*     VOUT       O   Vertex cell of plate set union. */
/*     POUT       O   Plate cell of plate set union. */

/* $ Detailed_Input */

/*     V1             is a SPICELIB double precision cell containing the */
/*                    vertices of the first input plate set. The */
/*                    vertices are stored in increasing order of the */
/*                    vertex IDs, and the components of each vertex are */
/*                    stored consecutively in the order X, Y, Z. */

/*     P1             is a SPICELIB integer cell containing the plates */
/*                    of the first input plate set. Each plate is a */
/*                    sequence of three vertex IDs. The vertex IDs */
/*                    are 1-based: they range from 1 to NV, where */
/*                    NV is the number of vertices stored in V1. */
/*                    The vertices of each plate are ordered in the */
/*                    positive (counterclockwise) sense about the */
/*                    plate's outward normal vector. The plates are */
/*                    store in increasing order of the plate IDs. */

/*     V2             is a SPICELIB double precision cell containing the */
/*                    vertices of the second input plate set. */

/*     P2             is a SPICELIB integer cell containing the plates */
/*                    of the second input plate set. */

/* $ Detailed_Output */

/*     VOUT           is a SPICELIB double precision cell containing the */
/*                    "union" of the sets of vertices of the input plate */
/*                    sets. The union is constructed by appending the */
/*                    data of V2 to the data of V1; no attempt is made */
/*                    to identify and remove repeated vertices. The */
/*                    cardinality of VOUT is the sum of the cardinalities */
/*                    of V1 and V2. */

/*     POUT           is a SPICELIB integer cell containing the plates */
/*                    of the union of the input plate sets. In POUT, */
/*                    each vertex ID from P2 is augmented by the number */
/*                    of vertices in V1. Each vertex ID from P1 is */
/*                    simply copied. The union is constructed by */
/*                    appending to the data from P1 the augmented */
/*                    versions of the plates from P2. The cardinality of */
/*                    POUT is the sum of the cardinalities of P1 and P2. */

/* $ Parameters */

/*    LBCELL is the lower bound of the SPICELIB cell data structure. */

/* $ Exceptions */

/*     1) If the size of VOUT is too small to contain the union */
/*        of the vertex sets, the error SPICE(VERTARRAYTOOSMALL) */
/*        is signaled. */

/*     2) If the size of POUT is too small to contain the union */
/*        of the plate sets, the error SPICE(PLTARRAYTOOSMALL) */
/*        is signaled. */

/*     3) Any other errors that occur while accessing SPICE cells */
/*        will be diagnosed by routines in the call tree of this */
/*        routine. */

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

/* -    DSKLIB Version 1.0.0, 02-SEP-2014 (NJB) */

/* -& */

/*     SPICELIB functions */


/*     Local variables */

    if (return_()) {
	return 0;
    }
    chkin_("ZZPSUN", (ftnlen)6);

/*     Check room in output vertex array. */

    cv1 = cardd_(v1);
    cv2 = cardd_(v2);
    cvout = cv1 + cv2;
    if (sized_(vout) < cvout) {
	setmsg_("Output vertex array is too small to contain union of input "
		"vertex arrays. Output vertex array size is #; required space"
		" is # elements.", (ftnlen)134);
	i__1 = sized_(vout);
	errint_("#", &i__1, (ftnlen)1);
	errint_("#", &cvout, (ftnlen)1);
	sigerr_("SPICE(VERTARRAYTOOSMALL)", (ftnlen)24);
	chkout_("ZZPSUN", (ftnlen)6);
	return 0;
    }

/*     Check room in output plate array. */

    cp1 = cardi_(p1);
    cp2 = cardi_(p2);
    cpout = cp1 + cp2;
    if (sizei_(pout) < cpout) {
	setmsg_("Output plate array is too small to contain union of input p"
		"late arrays. Output plate array size is #; required space is"
		" # elements.", (ftnlen)131);
	i__1 = sizei_(pout);
	errint_("#", &i__1, (ftnlen)1);
	errint_("#", &cpout, (ftnlen)1);
	sigerr_("SPICE(PLTARRAYTOOSMALL)", (ftnlen)23);
	chkout_("ZZPSUN", (ftnlen)6);
	return 0;
    }

/*     Copy the vertices and plates of the first input plate set */
/*     to the output plate set. */

    copyd_(v1, vout);
    copyi_(p1, pout);

/*     Append the vertices of the second input plate set to the */
/*     output plate set. We've already verified there's enough */
/*     room in the output set. */

    moved_(&v2[6], &cv2, &vout[cv1 + 6]);
    i__1 = cv1 + cv2;
    scardd_(&i__1, vout);

/*     In the output plate set, the vertex indices of the */
/*     second input plate set must be shifted by the number */
/*     of vertices in the first input vertex set. */

/*     Shift and append the plates of the second input plate set to the */
/*     output plate set. We've already verified there's enough room in */
/*     the output set. */

    i__1 = cp2;
    for (i__ = 1; i__ <= i__1; ++i__) {
	pout[cp1 + i__ + 5] = p2[i__ + 5] + cv1 / 3;
    }
    i__1 = cp1 + cp2;
    scardi_(&i__1, pout);
    chkout_("ZZPSUN", (ftnlen)6);
    return 0;
} /* zzpsun_ */

