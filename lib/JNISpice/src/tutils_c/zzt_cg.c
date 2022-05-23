/* zzt_cg.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1500 = 1500;
static integer c__3000 = 3000;

/* $Procedure ZZT_CG ( Make plate set for shape like comet C-G ) */
/* Subroutine */ int zzt_cg__(doublereal *vout, integer *pout)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Local variables */
    doublereal a;
    extern /* Subroutine */ int zzpsxlat_(doublereal *, doublereal *, 
	    doublereal *), chkin_(char *, ftnlen), copyd_(doublereal *, 
	    doublereal *), copyi_(integer *, integer *);
    integer ptemp0[3006], ptemp1[3006];
    doublereal vtemp0[1506], vtemp1[1506], offset[3];
    extern /* Subroutine */ int chkout_(char *, ftnlen), ssized_(integer *, 
	    doublereal *), ssizei_(integer *, integer *);
    extern logical return_(void);
    extern /* Subroutine */ int zzpsun_(doublereal *, integer *, doublereal *,
	     integer *, doublereal *, integer *), zzpsbox_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);

/* $ Abstract */

/*     Create a plate set representing, in an extremely crude fashion, */
/*     the self-occulting property of the shape of comet C-G. */

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

/*     DSK */
/*     PCK */

/* $ Keywords */

/*     BODY */
/*     PLATE */
/*     TILE */
/*     TESSELLATE */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     VOUT       O   Vertex cell of the plate set. */
/*     POUT       O   Plate cell of the plate set. */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     VOUT           is a SPICELIB double precision cell containing the */
/*                    vertices of a plate set that simulates the */
/*                    self-occulting property of the surface of comet */
/*                    C-G. The surface is composed of three disjoint */
/*                    boxes. */

/*     POUT           is a SPICELIB integer cell containing the plates */
/*                    of the plate set. The vertices of each plate are */
/*                    ordered so that they define an outward normal */
/*                    vector having positive dot product with the */
/*                    plate's vertices. (In other words, the normal */
/*                    vectors point outward.) */

/* $ Parameters */

/*     See the implementation for buffer size parameters. */

/* $ Exceptions */

/*     1) Any other errors that occur while accessing SPICE cells */
/*        will be diagnosed by routines in the call tree of this */
/*        routine. */

/* $ Files */

/*     1)  This routine creates a plate set consisting of a */
/*         union of box shapes constituting an extremely crude */
/*         representation of an object such as comet C-G. */

/* $ Particulars */

/*     See Files above. */

/* $ Examples */

/*     See use of C language version in tspice_c test families. */

/* $ Restrictions */

/*     1) For use only by TSPICE. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 09-SEP-2014 (NJB) */

/* -& */
/* $ Index_Entries */

/*     make crude plate set for object like comet c-g */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */

    if (return_()) {
	return 0;
    }
    chkin_("ZZT_CG", (ftnlen)6);
    ssized_(&c__1500, vtemp0);
    ssized_(&c__1500, vtemp1);
    ssizei_(&c__3000, ptemp0);
    ssizei_(&c__3000, ptemp1);
    a = 5.;
    d__1 = a * 3;
    d__2 = a * 4;
    zzpsbox_(&a, &d__1, &d__2, vout, pout);
    zzpsbox_(&a, &a, &a, vtemp0, ptemp0);
    offset[0] = a * 1.5;
    offset[1] = a;
    offset[2] = 0.;
    zzpsxlat_(vtemp0, offset, vtemp1);
    copyd_(vtemp1, vtemp0);
    zzpsun_(vtemp0, ptemp0, vout, pout, vtemp1, ptemp1);
    copyd_(vtemp1, vout);
    copyi_(ptemp1, pout);
    d__1 = a * 5;
    d__2 = a * 3;
    zzpsbox_(&a, &d__1, &d__2, vtemp0, ptemp0);
    offset[0] = a * 3;
    offset[1] = a;
    offset[2] = a;
    zzpsxlat_(vtemp0, offset, vtemp1);
    copyd_(vtemp1, vtemp0);
    zzpsun_(vtemp0, ptemp0, vout, pout, vtemp1, ptemp1);
    copyd_(vtemp1, vout);
    copyi_(ptemp1, pout);
    chkout_("ZZT_CG", (ftnlen)6);
    return 0;
} /* zzt_cg__ */

