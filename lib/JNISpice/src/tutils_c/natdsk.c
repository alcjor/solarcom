/* natdsk.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1000 = 1000;
static integer c__3 = 3;
static integer c__2000 = 2000;
static integer c__10 = 10;

/* $Procedure   NATDSK (Create a DSK for Nat's solar system) */
/* Subroutine */ int natdsk_(char *dsk, char *aframe, integer *anlon, integer 
	*anlat, char *bframe, integer *bnlon, integer *bnlat, ftnlen dsk_len, 
	ftnlen aframe_len, ftnlen bframe_len)
{
    doublereal arad[3], brad[3], last;
    integer n;
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    extern doublereal jyear_(void);
    doublereal first;
    extern doublereal twopi_(void);
    extern logical failed_(void);
    extern /* Subroutine */ int cleard_(integer *, doublereal *), delfil_(
	    char *, ftnlen), bodvcd_(integer *, char *, integer *, integer *, 
	    doublereal *, ftnlen);
    extern doublereal halfpi_(void);
    integer bodyid;
    doublereal bounds[4]	/* was [2][2] */;
    extern logical exists_(char *, ftnlen), return_(void);
    doublereal corpar[10];
    integer corsys, surfid;
    logical makvtl;
    extern /* Subroutine */ int chkout_(char *, ftnlen), t_eldsk2__(integer *,
	     integer *, char *, doublereal *, doublereal *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, logical *, char *, ftnlen, 
	    ftnlen);

/* $ Abstract */

/*     Create and if appropriate load a DSK containing shape data */
/*     for the objects in Nat's solar system. */

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

/*     Include file dskdsc.inc */

/*     This include file declares parameters for DSK segment descriptors. */

/* -       SPICELIB Version 1.0.0 08-FEB-2017 (NJB) */

/*           Updated version info. */

/*           22-JAN-2016 (NJB) */

/*              Added parameter for data class 2. Changed name of data */
/*              class 1 parameter. Corrected data class descriptions. */

/*           13-MAY-2010 (NJB) */

/*              Descriptor now contains two ID codes, one for the */
/*              surface, one for the associated ephemeris object. This */
/*              supports association of multiple surfaces with one */
/*              ephemeris object without creating file management */
/*              issues. */

/*              Room was added for coordinate system definition */
/*              parameters. */

/*               Flag arrays and model ID/component entries were deleted. */

/*            11-SEP-2008 (NJB) */


/*     DSK segment descriptors are implemented as an array of d.p. */
/*     numbers.  Note that each integer descriptor datum occupies one */
/*     d.p. value. */




/*     Segment descriptor parameters */

/*     Each segment descriptor occupies a contiguous */
/*     range of DAS d.p. addresses. */

/*        The DSK segment descriptor layout is: */

/*           +---------------------+ */
/*           | Surface ID code     | */
/*           +---------------------+ */
/*           | Center ID code      | */
/*           +---------------------+ */
/*           | Data class code     | */
/*           +---------------------+ */
/*           | Data type           | */
/*           +---------------------+ */
/*           | Ref frame code      | */
/*           +---------------------+ */
/*           | Coord sys code      | */
/*           +---------------------+ */
/*           | Coord sys parameters|  {10 elements} */
/*           +---------------------+ */
/*           | Min coord 1         | */
/*           +---------------------+ */
/*           | Max coord 1         | */
/*           +---------------------+ */
/*           | Min coord 2         | */
/*           +---------------------+ */
/*           | Max coord 2         | */
/*           +---------------------+ */
/*           | Min coord 3         | */
/*           +---------------------+ */
/*           | Max coord 3         | */
/*           +---------------------+ */
/*           | Start time          | */
/*           +---------------------+ */
/*           | Stop time           | */
/*           +---------------------+ */

/*     Parameters defining offsets for segment descriptor elements */
/*     follow. */


/*     Surface ID code: */


/*     Central ephemeris object NAIF ID: */


/*     Data class: */

/*     The "data class" is a code indicating the category of */
/*     data contained in the segment. */


/*     Data type: */


/*     Frame ID: */


/*     Coordinate system code: */


/*     Coordinate system parameter start index: */


/*     Number of coordinate system parameters: */


/*     Ranges for coordinate bounds: */


/*     Coverage time bounds: */


/*     Descriptor size (24): */


/*     Data class values: */

/*        Class 1 indicates a surface that can be represented as a */
/*                single-valued function of its domain coordinates. */

/*                An example is a surface defined by a function that */
/*                maps each planetodetic longitude and latitude pair to */
/*                a unique altitude. */


/*        Class 2 indicates a general surface. Surfaces that */
/*                have multiple points for a given pair of domain */
/*                coordinates---for example, multiple radii for a given */
/*                latitude and longitude---belong to class 2. */



/*     Coordinate system values: */

/*        The coordinate system code indicates the system to which the */
/*        tangential coordinate bounds belong. */

/*        Code 1 refers to the planetocentric latitudinal system. */

/*        In this system, the first tangential coordinate is longitude */
/*        and the second tangential coordinate is latitude. The third */
/*        coordinate is radius. */



/*        Code 2 refers to the cylindrical system. */

/*        In this system, the first tangential coordinate is radius and */
/*        the second tangential coordinate is longitude. The third, */
/*        orthogonal coordinate is Z. */



/*        Code 3 refers to the rectangular system. */

/*        In this system, the first tangential coordinate is X and */
/*        the second tangential coordinate is Y. The third, */
/*        orthogonal coordinate is Z. */



/*        Code 4 refers to the planetodetic/geodetic system. */

/*        In this system, the first tangential coordinate is longitude */
/*        and the second tangential coordinate is planetodetic */
/*        latitude. The third, orthogonal coordinate is altitude. */



/*     End of include file dskdsc.inc */


/*     Include file dsk02.inc */

/*     This include file declares parameters for DSK data type 2 */
/*     (plate model). */

/* -       SPICELIB Version 1.0.0 08-FEB-2017 (NJB) */

/*          Updated version info. */

/*           22-JAN-2016 (NJB) */

/*              Now includes spatial index parameters. */

/*           26-MAR-2015 (NJB) */

/*              Updated to increase MAXVRT to 16000002. MAXNPV */
/*              has been changed to (3/2)*MAXPLT. Set MAXVOX */
/*              to 100000000. */

/*           13-MAY-2010 (NJB) */

/*              Updated to reflect new no-record design. */

/*           04-MAY-2010 (NJB) */

/*              Updated for new type 2 segment design. Now uses */
/*              a local parameter to represent DSK descriptor */
/*              size (NB). */

/*           13-SEP-2008 (NJB) */

/*              Updated to remove albedo information. */
/*              Updated to use parameter for DSK descriptor size. */

/*           27-DEC-2006 (NJB) */

/*              Updated to remove minimum and maximum radius information */
/*              from segment layout.  These bounds are now included */
/*              in the segment descriptor. */

/*           26-OCT-2006 (NJB) */

/*              Updated to remove normal, center, longest side, albedo, */
/*              and area keyword parameters. */

/*           04-AUG-2006 (NJB) */

/*              Updated to support coarse voxel grid.  Area data */
/*              have now been removed. */

/*           10-JUL-2006 (NJB) */


/*     Each type 2 DSK segment has integer, d.p., and character */
/*     components.  The segment layout in DAS address space is as */
/*     follows: */


/*        Integer layout: */

/*           +-----------------+ */
/*           | NV              |  (# of vertices) */
/*           +-----------------+ */
/*           | NP              |  (# of plates ) */
/*           +-----------------+ */
/*           | NVXTOT          |  (total number of voxels) */
/*           +-----------------+ */
/*           | VGREXT          |  (voxel grid extents, 3 integers) */
/*           +-----------------+ */
/*           | CGRSCL          |  (coarse voxel grid scale, 1 integer) */
/*           +-----------------+ */
/*           | VOXNPT          |  (size of voxel-plate pointer list) */
/*           +-----------------+ */
/*           | VOXNPL          |  (size of voxel-plate list) */
/*           +-----------------+ */
/*           | VTXNPL          |  (size of vertex-plate list) */
/*           +-----------------+ */
/*           | PLATES          |  (NP 3-tuples of vertex IDs) */
/*           +-----------------+ */
/*           | VOXPTR          |  (voxel-plate pointer array) */
/*           +-----------------+ */
/*           | VOXPLT          |  (voxel-plate list) */
/*           +-----------------+ */
/*           | VTXPTR          |  (vertex-plate pointer array) */
/*           +-----------------+ */
/*           | VTXPLT          |  (vertex-plate list) */
/*           +-----------------+ */
/*           | CGRPTR          |  (coarse grid occupancy pointers) */
/*           +-----------------+ */



/*        D.p. layout: */

/*           +-----------------+ */
/*           | DSK descriptor  |  DSKDSZ elements */
/*           +-----------------+ */
/*           | Vertex bounds   |  6 values (min/max for each component) */
/*           +-----------------+ */
/*           | Voxel origin    |  3 elements */
/*           +-----------------+ */
/*           | Voxel size      |  1 element */
/*           +-----------------+ */
/*           | Vertices        |  3*NV elements */
/*           +-----------------+ */


/*     This local parameter MUST be kept consistent with */
/*     the parameter DSKDSZ which is declared in dskdsc.inc. */


/*     Integer item keyword parameters used by fetch routines: */


/*     Double precision item keyword parameters used by fetch routines: */


/*     The parameters below formerly were declared in pltmax.inc. */

/*     Limits on plate model capacity: */

/*     The maximum number of bodies, vertices and */
/*     plates in a plate model or collective thereof are */
/*     provided here. */

/*     These values can be used to dimension arrays, or to */
/*     use as limit checks. */

/*     The value of MAXPLT is determined from MAXVRT via */
/*     Euler's Formula for simple polyhedra having triangular */
/*     faces. */

/*     MAXVRT is the maximum number of vertices the triangular */
/*            plate model software will support. */


/*     MAXPLT is the maximum number of plates that the triangular */
/*            plate model software will support. */


/*     MAXNPV is the maximum allowed number of vertices, not taking into */
/*     account shared vertices. */

/*     Note that this value is not sufficient to create a vertex-plate */
/*     mapping for a model of maximum plate count. */


/*     MAXVOX is the maximum number of voxels. */


/*     MAXCGR is the maximum size of the coarse voxel grid. */


/*     MAXEDG is the maximum allowed number of vertex or plate */
/*     neighbors a vertex may have. */

/*     DSK type 2 spatial index parameters */
/*     =================================== */

/*        DSK type 2 spatial index integer component */
/*        ------------------------------------------ */

/*           +-----------------+ */
/*           | VGREXT          |  (voxel grid extents, 3 integers) */
/*           +-----------------+ */
/*           | CGRSCL          |  (coarse voxel grid scale, 1 integer) */
/*           +-----------------+ */
/*           | VOXNPT          |  (size of voxel-plate pointer list) */
/*           +-----------------+ */
/*           | VOXNPL          |  (size of voxel-plate list) */
/*           +-----------------+ */
/*           | VTXNPL          |  (size of vertex-plate list) */
/*           +-----------------+ */
/*           | CGRPTR          |  (coarse grid occupancy pointers) */
/*           +-----------------+ */
/*           | VOXPTR          |  (voxel-plate pointer array) */
/*           +-----------------+ */
/*           | VOXPLT          |  (voxel-plate list) */
/*           +-----------------+ */
/*           | VTXPTR          |  (vertex-plate pointer array) */
/*           +-----------------+ */
/*           | VTXPLT          |  (vertex-plate list) */
/*           +-----------------+ */


/*        Index parameters */


/*     Grid extent: */


/*     Coarse grid scale: */


/*     Voxel pointer count: */


/*     Voxel-plate list count: */


/*     Vertex-plate list count: */


/*     Coarse grid pointers: */


/*     Size of fixed-size portion of integer component: */


/*        DSK type 2 spatial index double precision component */
/*        --------------------------------------------------- */

/*           +-----------------+ */
/*           | Vertex bounds   |  6 values (min/max for each component) */
/*           +-----------------+ */
/*           | Voxel origin    |  3 elements */
/*           +-----------------+ */
/*           | Voxel size      |  1 element */
/*           +-----------------+ */



/*        Index parameters */

/*     Vertex bounds: */


/*     Voxel grid origin: */


/*     Voxel size: */


/*     Size of fixed-size portion of double precision component: */


/*     The limits below are used to define a suggested maximum */
/*     size for the integer component of the spatial index. */


/*     Maximum number of entries in voxel-plate pointer array: */


/*     Maximum cell size: */


/*     Maximum number of entries in voxel-plate list: */


/*     Spatial index integer component size: */


/*     End of include file dsk02.inc */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     DSK        I   The name of the DSK file to create. */
/*     AFRAME     I   Body-fixed frame for body Alpha. */
/*     ANLON      I   Number of longitude bands in model for Alpha. */
/*     ANLAT      I   Number of latitude bands in model for Alpha. */
/*     BFRAME     I   Body-fixed frame for body Beta. */
/*     BNLON      I   Number of longitude bands in model for Beta. */
/*     BNLAT      I   Number of latitude bands in model for Beta. */

/* $ Detailed_Input */

/*     DSK        is the name of a DSK file to create. If a DSK */
/*                of the same name already exists, it is deleted. */

/*     AFRAME     is the name of the body-fixed frame to be used in */
/*                the segment for body Alpha. */

/*     ANLON      is the number of longitude bands in the plate set for */
/*                body Alpha. Each longitude band is bounded by two */
/*                meridians. All longitude bands have equal angular */
/*                extent in longitude. The vertices of any plate lie on */
/*                adjacent longitude band boundaries. */

/*     ANLAT      is the number of latitude bands in the plate set for */
/*                body Alpha. The vertices of each band are bounded by */
/*                two cones of constant planetocentric latitude. All */
/*                latitude bands have equal angular extent in */
/*                planetocentric latitude. The vertices of any plate lie */
/*                on adjacent latitude band boundaries. */

/*                Each polar "cap" consists of one longitude band. */

/*     BFRAME     is the name of the body-fixed frame to be used in */
/*                the segment for body Beta. */

/*     BNLON      is the number of longitude bands in the plate set for */
/*                body Beta. See description of ANLON for details. */

/*     BNLAT      is the number of latitude bands in the plate set for */
/*                body Beta. See description of ANLAT for details. */


/* $ Detailed_Output */

/*     None. This routine creates an output file. */

/* $ Parameters */

/*     The maximum plate and column counts for each segment are */
/*     defined by the parameters in T_WRDSK2. These values */
/*     are considerably smaller than those used in dsk02.inc. */

/* $ Exceptions */

/*     1) Any error occurring during the creation of spatial indexes */
/*        for the segments in the output DSK will be signaled by */
/*        routines in the call tree of this routine. */

/*     2) Any I/O errors occurring in the creation of the DSK file */
/*        will be signaled by routines in the call tree of this */
/*        routine. */

/*     Since this routine is normally used within the TSPICE system, */
/*     it's up the caller to call CHCKXC to catch errors signaled by */
/*     this routine. */

/* $ Files */

/*     Input */
/*     ===== */

/*     This routine requires the kernel pool variables defined by */
/*     the PCK file created by NATPCK. That kernel should be loaded */
/*     by the caller. */

/*     Output */
/*     ====== */

/*     This routine creates a DSK file meant for use with the SPK file */
/*     and PCK file created by the respective test utilities NATSPK and */
/*     NATPCK. */

/*     The DSK file contains tessellated ellipsoid shape models for */
/*     bodies ALPHA and BETA. Radii for the ellipsoids are obtained from */
/*     the PCK created by NATPCK. */

/*     Each model is contained in a single segment. The surface IDs */
/*     for both segments are set to 1. The coordinate systems of both */
/*     segments are latitudinal. */

/*     The body-fixed frames associated with ALPHA and BETA are specified */
/*     by the caller. */

/* $ Particulars */

/*     This routine creates a DSK file for use in testing. See the Files */
/*     section above. */

/*     The DSK created by this routine in particular supports testing */
/*     the routines */

/*        GFOCLT */
/*        OCCULT */

/* $ Examples */

/*     The normal way to use this routine is shown below. */

/*        CALL NATPCK ( 'nat.tpc' ) */

/*           ... */

/*        CALL NATSPK ( 'nat.bds', */
/*       .              'ALPHAFIXED', ANLON, ANLAT, */
/*       .              'BETAFIXED',  BNLON, BNLAT ) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    Test Utilities 1.0.0, 23-MAY-2016 (NJB) */

/* -& */
/* $ Index_Entries */

/*     Create a "Nat's solar system" DSK file */

/* -& */

/*     SPICELIB functions */


/*     Local Parameters */


/*     Local Variables */

    if (return_()) {
	return 0;
    }
    chkin_("NATDSK", (ftnlen)6);

/*     Delete any existing file of the same name. */

    if (exists_(dsk, dsk_len)) {
	delfil_(dsk, dsk_len);
	if (failed_()) {
	    chkout_("NATDSK", (ftnlen)6);
	    return 0;
	}
    }

/*     Fetch body radii. */

    bodvcd_(&c__1000, "RADII", &c__3, &n, arad, (ftnlen)5);
    bodvcd_(&c__2000, "RADII", &c__3, &n, brad, (ftnlen)5);
    if (failed_()) {
	chkout_("NATDSK", (ftnlen)6);
	return 0;
    }

/*     Create a tessellated plate model segment for body */
/*     Alpha. */

    bodyid = 1000;
    surfid = 1;
    first = jyear_() * -100;
    last = jyear_() * 100;
    corsys = 1;
    cleard_(&c__10, corpar);

/*     Set longitude and latitude bounds for the segment. */

    bounds[0] = 0.;
    bounds[1] = twopi_();
    bounds[2] = -halfpi_();
    bounds[3] = halfpi_();

/*     Don't make a vertex-plate list. */

    makvtl = FALSE_;
    t_eldsk2__(&bodyid, &surfid, aframe, &first, &last, &corsys, corpar, 
	    bounds, arad, &arad[1], &arad[2], anlon, anlat, &makvtl, dsk, 
	    aframe_len, dsk_len);
    if (failed_()) {
	chkout_("NATDSK", (ftnlen)6);
	return 0;
    }

/*     Append to the DSK we just created a segment for body Beta. */

    bodyid = 2000;
    surfid = 1;
    first = jyear_() * -100;
    last = jyear_() * 100;
    corsys = 1;
    cleard_(&c__10, corpar);

/*     Set longitude and latitude bounds for the segment. */

    bounds[0] = 0.;
    bounds[1] = twopi_();
    bounds[2] = -halfpi_();
    bounds[3] = halfpi_();

/*     Don't make a vertex-plate list. */

    makvtl = FALSE_;
    t_eldsk2__(&bodyid, &surfid, bframe, &first, &last, &corsys, corpar, 
	    bounds, brad, &brad[1], &brad[2], bnlon, bnlat, &makvtl, dsk, 
	    bframe_len, dsk_len);
    if (failed_()) {
	chkout_("NATDSK", (ftnlen)6);
	return 0;
    }
    chkout_("NATDSK", (ftnlen)6);
    return 0;
} /* natdsk_ */

