/* zzpsball.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* $Procedure ZZPSBALL ( Plate set, create ball ) */
/* Subroutine */ int zzpsball_(doublereal *r__, integer *nlon, integer *nlat, 
	doublereal *vout, integer *pout)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    integer maxp, maxv;
    extern /* Subroutine */ int zzellplt_(doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, integer *, integer *, integer 
	    *, doublereal *, integer *, integer *), chkin_(char *, ftnlen);
    extern integer sized_(doublereal *), sizei_(integer *);
    extern logical failed_(void);
    integer np;
    extern /* Subroutine */ int scardd_(integer *, doublereal *);
    integer nv;
    extern /* Subroutine */ int scardi_(integer *, integer *), chkout_(char *,
	     ftnlen);
    extern logical return_(void);

/* $ Abstract */

/*     Create a plate set representing a sphere centered at the origin. */
/*     The radius of the sphere is specified by the caller. */

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
/*     R          I   Radius of sphere. */
/*     NLON       I   Number of longitude bands of plates. */
/*     NLAT       I   Number of latitude bands of plates. */
/*     VOUT       O   Vertex cell of the plate set. */
/*     POUT       O   Plate cell of the plate set. */

/* $ Detailed_Input */

/*     R              is the radius of the sphere to be represented */
/*                    by a collection of plates. */

/*     NLON, */
/*     NLAT           are, respectively, the number of longitude and */
/*                    latitude bands of plates representing the */
/*                    sphere's surface. */

/*                    The vertices of the plate set are located on */
/*                    NLON equally spaced (in angular measure) meridians */
/*                    and NLAT parallels, with an additional vertex at */
/*                    each pole. */

/* $ Detailed_Output */

/*     VOUT           is a SPICELIB double precision cell containing the */
/*                    vertices of a plate set representing the surface */
/*                    of a sphere having radius R. The sphere is */
/*                    centered at the origin. */

/*                    The vertex cell VOUT contains */

/*                       ( NLON * (NLAT-1) )  +  2 */

/*                    vertices. */


/*     POUT           is a SPICELIB integer cell containing the plates */
/*                    of the plate set. The vertices of each plate are */
/*                    ordered so that they define an outward normal */
/*                    vector having positive dot product with the */
/*                    plate's vertices. (In other words, the normal */
/*                    vectors point outward.) */

/*                    The plate cell POUT contains */

/*                       2 * NLON * (NLAT-1) */

/*                    plates. */


/* $ Parameters */

/*    LBCELL is the lower bound of the SPICELIB cell data structure. */

/* $ Exceptions */

/*     1) If the size of VOUT is too small to contain the output */
/*        plate set's vertices, the error will be diagnosed by */
/*        routines in the call tree of this routine. */

/*     2) If the size of POUT is too small to contain the output plate */
/*        set's plates, the error will be diagnosed by routines in the */
/*        call tree of this routine. */

/*     3) Any other errors that occur while accessing SPICE cells */
/*        will be diagnosed by routines in the call tree of this */
/*        routine. */

/*     4) If the radius is non-positive, the error will be diagnosed by */
/*        routines in the call tree of this routine. */

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

/* -    DSKLIB Version 1.0.0, 03-SEP-2014 (NJB) */

/* -& */
    if (return_()) {
	return 0;
    }
    chkin_("ZZPSBALL", (ftnlen)8);
    maxv = sized_(vout) / 3;
    maxp = sizei_(pout) / 3;

/*     From the header of ZZELLPLT: */


/*     MAXV       is the maximum number of vertices to return. MAXV must */
/*                be at least */

/*                   ( NLON * ( NLAT - 1 ) )  +  2 */

/*                The array VERTS must have size at least 3*MAXV. */


/*     MAXP       is the maximum number of plates to return. MAXP must */
/*                be at least */

/*                   2 * NLON * ( NLAT - 1 ) */

/*                The array PLATES must have size at least 3*MAXP. */

    zzellplt_(r__, r__, r__, nlon, nlat, &maxv, &maxp, &nv, &vout[6], &np, &
	    pout[6]);
    if (failed_()) {
	chkout_("ZZPSBALL", (ftnlen)8);
	return 0;
    }
    i__1 = nv * 3;
    scardd_(&i__1, vout);
    i__1 = np * 3;
    scardi_(&i__1, pout);
    chkout_("ZZPSBALL", (ftnlen)8);
    return 0;
} /* zzpsball_ */

