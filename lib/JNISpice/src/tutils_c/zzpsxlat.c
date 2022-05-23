/* zzpsxlat.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* $Procedure ZZPSXLAT ( Plate set, translate ) */
/* Subroutine */ int zzpsxlat_(doublereal *v1, doublereal *offset, doublereal 
	*vout)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    extern /* Subroutine */ int vadd_(doublereal *, doublereal *, doublereal *
	    );
    integer i__, j;
    extern integer cardd_(doublereal *);
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    extern integer sized_(doublereal *);
    extern /* Subroutine */ int scardd_(integer *, doublereal *);
    integer nv;
    extern /* Subroutine */ int sigerr_(char *, ftnlen), chkout_(char *, 
	    ftnlen), setmsg_(char *, ftnlen), errint_(char *, integer *, 
	    ftnlen);
    integer cv1;
    extern logical return_(void);

/* $ Abstract */

/*     Apply a translation to a plate set: offset the vertices of a */
/*     plate set by a specified vector. */

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
/*     V1         I   Vertex cell of a plate set. */
/*     OFFSET     I   Vector to add to each vertex of V1. */
/*     VOUT       O   Vertex cell of the translated plate set. */

/* $ Detailed_Input */

/*     V1             is a SPICELIB double precision cell containing the */
/*                    vertices of a plate set. */

/*     OFFSET         is a 3-vector to be added to each vertex of V1. */

/* $ Detailed_Output */

/*     VOUT           is a SPICELIB double precision cell containing the */
/*                    vertices of a plate set resulting from adding */
/*                    OFFSET to each vertex of V1. */

/* $ Parameters */

/*    LBCELL is the lower bound of the SPICELIB cell data structure. */

/* $ Exceptions */

/*     1) If the cardinality of V1 is not a multiple of 3, the error */
/*        SPICE(BADVERTEXARRAY) is signaled. */

/*     2) If the size of VOUT is too small to contain the vertices */
/*        of the output plate set, the error SPICE(VERTARRAYTOOSMALL) */
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

/* -    DSKLIB Version 1.0.0, 04-SEP-2014 (NJB) */

/* -& */

/*     SPICELIB functions */


/*     Local variables */

    if (return_()) {
	return 0;
    }
    chkin_("ZZPSXLAT", (ftnlen)8);

/*     Make sure the cardinality of the input vertex set is a */
/*     multiple of 3. */

    cv1 = cardd_(v1);
    nv = cv1 / 3;
    if (nv * 3 != cv1) {
	setmsg_("Input vertex set cardinality # is not a multiple of 3.", (
		ftnlen)54);
	errint_("#", &cv1, (ftnlen)1);
	sigerr_("SPICE(BADVERTEXARRAY)", (ftnlen)21);
	chkout_("ZZPSXLAT", (ftnlen)8);
	return 0;
    }

/*     Check room in output vertex array. */

    cv1 = cardd_(v1);
    if (sized_(vout) < cv1) {
	setmsg_("Output vertex array size is #; required space is # elements."
		, (ftnlen)60);
	i__1 = sized_(vout);
	errint_("#", &i__1, (ftnlen)1);
	errint_("#", &cv1, (ftnlen)1);
	sigerr_("SPICE(VERTARRAYTOOSMALL)", (ftnlen)24);
	chkout_("ZZPSXLAT", (ftnlen)8);
	return 0;
    }

/*     Add the offset vector to each vertex of the input plate set and */
/*     append the result to the output plate set. We've already */
/*     verified there's enough room in the output set. */

    i__1 = nv;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = (i__ - 1) * 3 + 1;
	vadd_(offset, &v1[j + 5], &vout[j + 5]);
    }
    scardd_(&cv1, vout);
    chkout_("ZZPSXLAT", (ftnlen)8);
    return 0;
} /* zzpsxlat_ */

