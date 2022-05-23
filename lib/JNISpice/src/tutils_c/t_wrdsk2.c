/* t_wrdsk2.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static doublereal c_b10 = .23;
static integer c_b11 = 8000000;
static integer c__0 = 0;
static integer c__2 = 2;
static logical c_true = TRUE_;
static integer c_b24 = 4000000;
static integer c_b25 = 16000000;
static logical c_false = FALSE_;
static integer c__1 = 1;
static integer c__10 = 10;
static integer c_b40 = 2000000;
static integer c__3 = 3;
static doublereal c_b79 = 0.;
static doublereal c_b82 = 1.;
static integer c_b166 = 12000000;

/* $Procedure T_WRDSK2 ( DSK test utilities, type 2 writer umbrella ) */
/* Subroutine */ int t_wrdsk2__0_(int n__, integer *bodyid, integer *surfid, 
	char *frname, doublereal *first, doublereal *last, doublereal *a, 
	doublereal *b, doublereal *c__, integer *corsys, doublereal *corpar, 
	doublereal *bounds, integer *nlon, integer *nlat, integer *nv, 
	integer *np, doublereal *usrvrt, integer *usrplt, logical *makvtl, 
	logical *usepad, integer *npolyv, integer *ncross, doublereal *r__, 
	doublereal *rcross, doublereal *center, doublereal *normal, char *dsk,
	 ftnlen frname_len, ftnlen dsk_len)
{
    /* Initialized data */

    static logical small1 = TRUE_;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *), d_int(doublereal *);
    integer s_rnge(char *, integer, char *, integer);

    /* Local variables */
    integer base;
    doublereal dlat, dlon;
    extern /* Subroutine */ int vscl_(doublereal *, doublereal *, doublereal *
	    );
    integer size;
    extern /* Subroutine */ int vequ_(doublereal *, doublereal *);
    static integer work[16000000]	/* was [2][8000000] */;
    extern /* Subroutine */ int zzellsec_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, integer *, integer *, integer 
	    *, doublereal *, integer *, integer *), zzchrlat_(doublereal *, 
	    doublereal *, doublereal *), t_torcrv__(doublereal *, doublereal *
	    , doublereal *, doublereal *), t_torset__(doublereal *, 
	    doublereal *, doublereal *), zzellplt_(doublereal *, doublereal *,
	     doublereal *, integer *, integer *, integer *, integer *, 
	    integer *, doublereal *, integer *, integer *), zzpstube_(integer 
	    *, doublereal *, S_fp, integer *, logical *, doublereal *, 
	    integer *);
    integer i__;
    extern integer cardd_(doublereal *);
    integer n;
    doublereal q;
    extern integer cardi_(integer *);
    doublereal radii[3], delta, x[3], y[3];
    extern /* Subroutine */ int chkin_(char *, ftnlen), frame_(doublereal *, 
	    doublereal *, doublereal *), errch_(char *, char *, ftnlen, 
	    ftnlen), vpack_(doublereal *, doublereal *, doublereal *, 
	    doublereal *);
    doublereal theta;
    extern doublereal jyear_(void);
    integer lnlat;
    extern /* Subroutine */ int dskw02_(integer *, integer *, integer *, 
	    integer *, char *, integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *,
	     integer *, integer *, doublereal *, integer *, ftnlen), errdp_(
	    char *, doublereal *, ftnlen);
    integer lnlon;
    doublereal c0, d0[3];
    extern doublereal twopi_(void);
    doublereal v0[3], twist;
    extern /* Subroutine */ int vrotv_(doublereal *, doublereal *, doublereal 
	    *, doublereal *), dskrb2_(integer *, doublereal *, integer *, 
	    integer *, integer *, doublereal *, doublereal *, doublereal *), 
	    dskmi2_(integer *, doublereal *, integer *, integer *, doublereal 
	    *, integer *, integer *, integer *, integer *, logical *, integer 
	    *, integer *, doublereal *, integer *);
    doublereal mncor1, mncor2, mncor3, mxcor1, mxcor2, mxcor3;
    extern logical failed_(void);
    extern /* Subroutine */ int cleard_(integer *, doublereal *);
    integer handle;
    doublereal adjlat;
    extern /* Subroutine */ int bodvcd_(integer *, char *, integer *, integer 
	    *, doublereal *, ftnlen);
    integer framid;
    extern doublereal halfpi_(void);
    doublereal finscl, locpar[10];
    extern logical exists_(char *, ftnlen), return_(void);
    doublereal et0, et1, maxlat, maxlon, minlat, minlon;
    static doublereal smlixd[10];
    doublereal spaixd[10];
    static doublereal vrtces[6000000]	/* was [3][2000000] */;
    integer corscl, lnp, lsizep, lsizev, lnv;
    static integer plates[12000000]	/* was [3][4000000] */, smlixi[100100]
	    , spaixi[20100007];
    integer spxisz, vlsize, vmapsz, vpsize;
    extern /* Subroutine */ int sigerr_(char *, ftnlen), chkout_(char *, 
	    ftnlen), namfrm_(char *, integer *, ftnlen), setmsg_(char *, 
	    ftnlen), dasopw_(char *, integer *, ftnlen), dskopn_(char *, char 
	    *, integer *, integer *, ftnlen, ftnlen), dskcls_(integer *, 
	    logical *), ssized_(integer *, doublereal *), ssizei_(integer *, 
	    integer *), zzt_cg__(doublereal *, integer *), errint_(char *, 
	    integer *, ftnlen);

/* $ Abstract */

/*     This is the umbrella routine for DSK type 2 writing test */
/*     utilities. */

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

/* $ Keywords */

/*     ELLIPSOID */
/*     PLATE */
/*     TILE */
/*     TESSELLATE */
/*     TEST */
/*     UTILITY */

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

/*     VARIABLE  I/O  Entry points */
/*     --------  ---  -------------------------------------------------- */
/*     BODYID     I   T_WRTPLT, T_WRTPLZ, T_ELDSK2, T_ELDS2Z, T_SMLDSK */
/*                    T_SECDS2, T_TORUS */
/*     SURFID     I   T_WRTPLT, T_WRTPLZ, T_ELDSK2, T_ELDS2Z, T_SMLDSK */
/*                    T_SECDS2, T_TORUS */
/*     FRNAME     I   T_WRTPLT, T_WRTPLZ, T_ELDSK2, T_ELDS2Z, T_SMLDSK */
/*                    T_SECDS2, T_TORUS */
/*     FIRST      I   T_WRTPLT, T_ELDSK2, T_SECDS2 */
/*     LAST       I   T_WRTPLT, T_ELDSK2, T_SECDS2 */
/*     A          I   T_ELLDSK, T_SECDS2 */
/*     B          I   T_ELLDSK, T_SECDS2 */
/*     C          I   T_ELLDSK, T_SECDS2 */
/*     CORSYS     I   T_WRTPLT, T_ELDSK2, T_SECDS2 */
/*     CORPAR     I   T_WRTPLT, T_ELDSK2, T_SECDS2 */
/*     BOUNDS     I   T_WRTPLT, T_ELDSK2, T_SECDS2 */
/*     NLON       I   T_ELDSK2, T_ELDS2Z, T_SECDS2 */
/*     NLAT       I   T_ELDSK2, T_ELDS2Z, T_SECDS2 */
/*     NV         I   T_WRTPLT, T_WRTPLZ */
/*     NP         I   T_WRTPLT, T_WRTPLZ */
/*     USRVRT     I   T_WRTPLT, T_WRTPLZ */
/*     USRPLT     I   T_WRTPLT, T_WRTPLZ */
/*     MAKVTL     I   T_WRTPLT, T_ELDSK2, T_SECDS2 */
/*     USEPAD     I   T_SECDS2 */
/*     NPOLYV     I   T_TORUS */
/*     NCROSS     I   T_TORUS */
/*     R          I   T_TORUS */
/*     RCROSS     I   T_TORUS */
/*     CENTER     I   T_TORUS */
/*     NORMAL     I   T_TORUS */
/*     DSK        I   T_WRTPLT, T_WRTPLZ, T_ELDSK2, T_ELDS2Z, T_SMLDSK, */
/*                    T_CG, T_SECDS2, T_TORUS */

/* $ Detailed_Input */

/*     See the entry points for descriptions of their inputs. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If this routine is called directly, the error */
/*         SPICE(BOGUSENTRY) is signaled. */

/*     See the entry points for descriptions of exceptions */
/*     specific to those routines. */

/* $ Files */

/*     See the entry points. */

/* $ Particulars */

/*     The entry points in this routine create type 2 DSKs for */
/*     SPICELIB regression testing. */

/*     This umbrella routine serves as a location for declaration */
/*     of large arrays needed for spatial index generation, and */
/*     in some cases, for generation of plates and vertices. */

/*     In order to take advantage of the arrays declared here, new */
/*     DSK generating test utilities should be implemented as new */
/*     entry points of this routine, if feasible. */

/*     The entry points of this routine are */

/*       T_WRTPLT     {write plates and vertices: general case} */

/*       T_WRTPLZ     {write plates and vertices: "easy"} */

/*                       This routine uses latitudinal coordinates and */
/*                       default values for time and spatial bounds. It */
/*                       does not create a vertex-plate map. */

/*       T_ELDSK2     {write tessellated ellipsoid: general case} */


/*       T_ELDS2Z     {write tessellated ellipsoid: "easy"} */

/*                       This routine uses latitudinal coordinates and */
/*                       default values for time and spatial bounds. It */
/*                       does not create a vertex-plate map. It obtains */
/*                       target body reference ellipsoid radii from the */
/*                       kernel pool. */

/*       T_SMLDSK     {write DSK containing a single plate} */


/*       T_CG         {write DSK containing extremely simplified */
/*                     shape representing comet C-G} */

/*       T_SECDS2     {write section of tessellated ellipsoid: general */
/*                     case} */

/*       T_TORUS      {write DSK containing torus plate model} */


/* $ Examples */

/*     See use of in TSPICE test families. */

/* $ Restrictions */

/*     For use only by TSPICE. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 28-JAN-2017 (NJB) */

/*        Added entry point that writes simplified CG DSK. */

/*        Reduced large array sizes by a factor of 8. */

/*        Previous version was dated 21-MAR-2016. */

/* -& */
/* $ Index_Entries */

/*     testutil type 2 dsk writing umbrella */

/* -& */

/*     SPICELIB functions */


/*     EXTERNAL routines */


/*     Local parameters */


/*     Local variables */


/*     Saved variables */

/*     Save all large arrays to avoid stack problems. */
/*     Save spatial index variables for the small DSK writer. */


/*     Initial values */

    /* Parameter adjustments */
    if (corpar) {
	}
    if (bounds) {
	}
    if (usrvrt) {
	}
    if (usrplt) {
	}
    if (center) {
	}
    if (normal) {
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_t_wrtplt;
	case 2: goto L_t_wrtplz;
	case 3: goto L_t_eldsk2;
	case 4: goto L_t_elds2z;
	case 5: goto L_t_smldsk;
	case 6: goto L_t_cg;
	case 7: goto L_t_secds2;
	case 8: goto L_t_torus;
	}

    chkin_("T_WRDSK2", (ftnlen)8);
    sigerr_("SPICE(BOGUSENTRY)", (ftnlen)17);
    chkout_("T_WRDSK2", (ftnlen)8);
    return 0;
/* $Procedure T_WRTPLT ( DSK test, write caller-supplied plate data ) */

L_t_wrtplt:
/* $ Abstract */

/*     Write a type 2 DSK containing vertices and plates passed */
/*     in by the caller. */

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

/* $ Keywords */

/*     PLATE */
/*     TEST */
/*     UTILITY */
/*     VERTEX */

/* $ Declarations */

/*     INTEGER               BODYID */
/*     INTEGER               SURFID */
/*     CHARACTER*(*)         FRNAME */
/*     DOUBLE PRECISION      FIRST */
/*     DOUBLE PRECISION      LAST */
/*     INTEGER               CORSYS */
/*     DOUBLE PRECISION      CORPAR ( * ) */
/*     DOUBLE PRECISION      BOUNDS ( 2, 2 ) */
/*     INTEGER               NV */
/*     INTEGER               NP */
/*     DOUBLE PRECISION      USRVRT ( 3, * ) */
/*     INTEGER               USRPLT ( 3, * ) */
/*     LOGICAL               MAKVTL */
/*     CHARACTER*(*)         DSK */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     BODYID     I   Body ID. */
/*     SURFID     I   Surface ID. */
/*     FRNAME     I   Reference frame name. */
/*     FIRST      I   Start time, TDB. */
/*     LAST       I   Stop time, TDB. */
/*     CORSYS     I   Coordinate system code. */
/*     CORPAR     I   Coordinate parameters. */
/*     BOUNDS     I   Segment spatial bounds. */
/*     NV         I   Number of vertices in input array. */
/*     NP         I   Number of plates in input array. */
/*     USRVRT     I   Vertex array. */
/*     USRPLT     I   Plate array. */
/*     MAKVTL     I   Vertex-plate mapping flag. */
/*     DSK        I   Name of DSK file to write. */

/* $ Detailed_Input */

/*     BODYID     is the body ID code of the segment to be written */
/*                to the output DSK file. */

/*     SURFID     is surface ID code. */

/*     FRNAME     is the name of the reference frame. */

/*     FIRST, */
/*     LAST       are, respectively, the start and stop times of */
/*                the coverage interval of the segment. FIRST and */
/*                LAST are expressed as seconds past J2000, TDB. */

/*     CORSYS     is an integer code designating the coordinate */
/*                system of the segment. */


/*     CORPAR     is an array of parameters associated with */
/*                the coordinate system. */

/*                For planetodetic coordinates, */

/*                   CORPAR(1) is the equatorial radius of the */
/*                             reference spheroid */


/*                   CORPAR(2) is the flattening coefficient of the */
/*                             reference spheroid */


/*     BOUNDS     is a 2x2 array of bounds of the first two coordinates */
/*                of the segment's spatial coverage. BOUNDS(1,I) is */
/*                the lower bound of the Ith coordinate; BOUNDS(2,I) is */
/*                the upper bound. */

/*     NV         is the number of vertices in the input vertex array. */

/*     NP         is the number of plates in the input plate array. */

/*     USRVRT     is an array of vertices. Elements */

/*                   USRVRT(J,I), J = 1, 3 */

/*                are the components of the Ith vertex. Vertex indices */
/*                range from 1 to NV. */


/*     USRPLT     is an array of plates. Elements */

/*                   USRPLT(J,I), J = 1, 3 */

/*                are the components of the Ith plate. Each component */
/*                is a vertex index. Plate indices range from 1 to NP. */

/*     MAKVTL     is a logical flag that controls whether a vertex-plate */
/*                mapping is created in the output segment. A mapping */
/*                is created if and only if MAKVTL is .TRUE. */

/*     DSK        is the name of the DSK file to write. If the file */
/*                does not exist, it will be created. If the file */
/*                exists, this routine will append to it. */

/* $ Detailed_Output */

/*     None. This routine operates by side effects. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the input frame name cannot be converted to an ID code, */
/*         the error SPICE(FRAMEIDNOTFOUND) will be signaled. */

/*     2)  Any errors that occur during the process of creating the */
/*         output segment's spatial index or of writing the DSK will be */
/*         signaled by routines in the call tree of this routine. */

/* $ Files */

/*     See the description of DSK above. */

/* $ Particulars */

/*     This is the general test API for writing plate-vertex */
/*     data to a DSK file. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     1) For use only by TSPICE. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 28-JAN-2017 (NJB) */

/* -& */
/* $ Index_Entries */

/*     testutil type 2 dsk plate-vertex writer */

/* -& */
    if (return_()) {
	return 0;
    }
    chkin_("T_WRTPLT", (ftnlen)8);

/*     Convert the frame name to an ID code. */

    namfrm_(frname, &framid, frname_len);
    if (framid == 0) {
	setmsg_("Could not convert frame name # to an ID code.", (ftnlen)45);
	errch_("#", frname, (ftnlen)1, frname_len);
	sigerr_("SPICE(FRAMEIDNOTFOUND)", (ftnlen)22);
	chkout_("T_WRTPLT", (ftnlen)8);
	return 0;
    }

/*     Create a spatial index for the plate set. */

/*     Use a heuristic formula for the fine scale. */

/* Computing MAX */
    d__3 = (doublereal) (*np);
    d__1 = 1., d__2 = pow_dd(&d__3, &c_b10) / 8;
    finscl = max(d__1,d__2);

/*     Pick a one-size-fits-all value for the large scale. */

    corscl = 10;

/*     Set the spatial index integer component size. */

    if (*makvtl) {
	vpsize = 2000000;
	vlsize = 8000000;
	vmapsz = (*nv << 1) + *np * 3;
	spxisz = vpsize + 100007 + vlsize + vmapsz;
    } else {
	vpsize = 4000000;
	vlsize = 16000000;
	spxisz = 20100007;
    }
    dskmi2_(nv, usrvrt, np, usrplt, &finscl, &corscl, &c_b11, &vpsize, &
	    vlsize, makvtl, &spxisz, work, spaixd, spaixi);

/*     Generate bounds for the 3rd coordinate. */

    dskrb2_(nv, usrvrt, np, usrplt, corsys, corpar, &mncor3, &mxcor3);
    if (failed_()) {
	chkout_("T_WRTPLT", (ftnlen)8);
	return 0;
    }

/*     Write the file. */

    if (exists_(dsk, dsk_len)) {

/*        Open the existing file for writing. */

	dasopw_(dsk, &handle, dsk_len);
    } else {

/*        Open a new file. */

	dskopn_(dsk, dsk, &c__0, &handle, dsk_len, dsk_len);
    }
    dskw02_(&handle, bodyid, surfid, &c__2, frname, corsys, corpar, bounds, &
	    bounds[1], &bounds[2], &bounds[3], &mncor3, &mxcor3, first, last, 
	    nv, usrvrt, np, usrplt, spaixd, spaixi, frname_len);

/*     Close the file. */

    dskcls_(&handle, &c_true);
    chkout_("T_WRTPLT", (ftnlen)8);
    return 0;
/* $Procedure T_WRTPLZ ( DSK test, write plate data, easy ) */

L_t_wrtplz:
/* $ Abstract */

/*     Write a type 2 DSK containing vertices and plates passed */
/*     in by the caller. Use default values to simplify the call. */

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

/* $ Keywords */

/*     PLATE */
/*     TEST */
/*     UTILITY */
/*     VERTEX */

/* $ Declarations */

/*     INTEGER               BODYID */
/*     INTEGER               SURFID */
/*     CHARACTER*(*)         FRNAME */
/*     INTEGER               NV */
/*     INTEGER               NP */
/*     DOUBLE PRECISION      USRVRT ( 3, * ) */
/*     INTEGER               USRPLT ( 3, * ) */
/*     CHARACTER*(*)         DSK */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     BODYID     I   Body ID. */
/*     SURFID     I   Surface ID. */
/*     FRNAME     I   Reference frame name. */
/*     NV         I   Number of vertices in input array. */
/*     NP         I   Number of plates in input array. */
/*     USRVRT     I   Vertex array. */
/*     USRPLT     I   Plate array. */
/*     DSK        I   Name of DSK file to write. */

/* $ Detailed_Input */

/*     BODYID     is the body ID code of the segment to be written */
/*                to the output DSK file. */

/*     SURFID     is surface ID code. */

/*     FRNAME     is the name of the reference frame. */

/*     NV         is the number of vertices in the input vertex array. */

/*     NP         is the number of plates in the input plate array. */

/*     USRVRT     is an array of vertices. Elements */

/*                   USRVRT(J,I), J = 1, 3 */

/*                are the components of the Ith vertex. Vertex indices */
/*                range from 1 to NV. */


/*     USRPLT     is an array of plates. Elements */

/*                   USRPLT(J,I), J = 1, 3 */

/*                are the components of the Ith plate. Each component */
/*                is a vertex index. Plate indices range from 1 to NP. */

/*     DSK        is the name of the DSK file to write. If the file */
/*                does not exist, it will be created. If the file */
/*                exists, this routine will append to it. */

/* $ Detailed_Output */

/*     None. This routine operates by side effects. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the input frame name cannot be converted to an ID code, */
/*         the error SPICE(FRAMEIDNOTFOUND) will be signaled. */

/*     2)  Any errors that occur during the process of creating the */
/*         output segment's spatial index or of writing the DSK will be */
/*         signaled by routines in the call tree of this routine. */

/* $ Files */

/*     See the description of DSK above. */

/* $ Particulars */

/*     This is a simplified API for writing plate-vertex */
/*     data to a DSK file. The following defaults are used */

/*        Time bounds:               -100 : 100 Julian years TDB */

/*        Coordinate system:         Latitudinal */

/*        Longitude bounds:          0     : 2*pi radians */
/*        Latitude bounds:           -pi/2 : pi/2 radians */

/*     This routine does not construct a vertex-plate mapping. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     1) For use only by TSPICE. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 28-JAN-2017 (NJB) */

/* -& */
/* $ Index_Entries */

/*     testutil type 2 dsk plate-vertex easy writer */

/* -& */
    if (return_()) {
	return 0;
    }
    chkin_("T_WRTPLZ", (ftnlen)8);

/*     Convert the frame name to an ID code. */

    namfrm_(frname, &framid, frname_len);
    if (framid == 0) {
	setmsg_("Could not convert frame name # to an ID code.", (ftnlen)45);
	errch_("#", frname, (ftnlen)1, frname_len);
	sigerr_("SPICE(FRAMEIDNOTFOUND)", (ftnlen)22);
	chkout_("T_WRTPLZ", (ftnlen)8);
	return 0;
    }

/*     Create a spatial index for the plate set. */

/*     Use a heuristic formula for the fine scale. */

/* Computing MAX */
    d__3 = (doublereal) (*np);
    d__1 = 1., d__2 = pow_dd(&d__3, &c_b10) / 8;
    finscl = max(d__1,d__2);

/*     Pick a one-size-fits-all value for the large scale. */

    corscl = 10;

/*     Set the spatial index integer component size. */

    vpsize = 4000000;
    vlsize = 16000000;
    spxisz = 20100007;
    dskmi2_(nv, usrvrt, np, usrplt, &finscl, &corscl, &c_b11, &c_b24, &c_b25, 
	    &c_false, &spxisz, work, spaixd, spaixi);

/*     Generate bounds for the 3rd coordinate. */

    dskrb2_(nv, usrvrt, np, usrplt, &c__1, locpar, &mncor3, &mxcor3);
    if (failed_()) {
	chkout_("T_WRTPLZ", (ftnlen)8);
	return 0;
    }

/*     Set default segment parameters. */

    mncor1 = 0.;
    mxcor1 = twopi_();
    mncor2 = -halfpi_();
    mxcor2 = halfpi_();
    cleard_(&c__10, locpar);
    et0 = jyear_() * -100;
    et1 = jyear_() * 100;

/*     Write the file. */

    if (exists_(dsk, dsk_len)) {

/*        Open the existing file for writing. */

	dasopw_(dsk, &handle, dsk_len);
    } else {

/*        Open a new file. */

	dskopn_(dsk, dsk, &c__0, &handle, dsk_len, dsk_len);
    }
    dskw02_(&handle, bodyid, surfid, &c__2, frname, &c__1, locpar, &mncor1, &
	    mxcor1, &mncor2, &mxcor2, &mncor3, &mxcor3, &et0, &et1, nv, 
	    usrvrt, np, usrplt, spaixd, spaixi, frname_len);

/*     Close the file. */

    dskcls_(&handle, &c_true);
    chkout_("T_WRTPLZ", (ftnlen)8);
    return 0;
/* $Procedure T_ELDSK2 ( DSK test, write tessellated ellipsoid DSK ) */

L_t_eldsk2:
/* $ Abstract */

/*     Write a type 2 DSK containing a tessellated ellipsoid. */

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

/* $ Keywords */

/*     ELLIPSOID */
/*     PLATE */
/*     TILE */
/*     TESSELLATE */
/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     INTEGER               BODYID */
/*     INTEGER               SURFID */
/*     CHARACTER*(*)         FRNAME */
/*     DOUBLE PRECISION      FIRST */
/*     DOUBLE PRECISION      LAST */
/*     INTEGER               CORSYS */
/*     DOUBLE PRECISION      CORPAR ( * ) */
/*     DOUBLE PRECISION      BOUNDS ( 2, 2 ) */
/*     DOUBLE PRECISION      A */
/*     DOUBLE PRECISION      B */
/*     DOUBLE PRECISION      C */
/*     INTEGER               NLON */
/*     INTEGER               NLAT */
/*     LOGICAL               MAKVTL */
/*     CHARACTER*(*)         DSK */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     BODYID     I   Body ID. */
/*     SURFID     I   Surface ID. */
/*     FRNAME     I   Reference frame name. */
/*     FIRST      I   Start time, TDB. */
/*     LAST       I   Stop time, TDB. */
/*     CORSYS     I   Coordinate system code. */
/*     CORPAR     I   Coordinate parameters. */
/*     BOUNDS     I   Segment spatial bounds. */
/*     A          I   Length of ellipsoid semi-axis lying on the x-axis. */
/*     B          I   Length of ellipsoid semi-axis lying on the y-axis. */
/*     C          I   Length of ellipsoid semi-axis lying on the z-axis. */
/*     NLON       I   Number of longitude bands in plate set. */
/*     NLAT       I   Number of latitude bands in plate set. */
/*     MAKVTL     I   Vertex-plate mapping flag. */
/*     DSK        I   Name of DSK file to write. */

/* $ Detailed_Input */

/*     BODYID     is the body ID code of the segment to be written */
/*                to the output DSK file. */

/*     SURFID     is surface ID code. */

/*     FRNAME     is the name of the reference frame. */

/*     FIRST, */
/*     LAST       are, respectively, the start and stop times of */
/*                the coverage interval of the segment. FIRST and */
/*                LAST are expressed as seconds past J2000, TDB. */

/*     CORSYS     is an integer code designating the coordinate */
/*                system of the segment. */


/*     CORPAR     is an array of parameters associated with */
/*                the coordinate system. */

/*                For planetodetic coordinates, */

/*                   CORPAR(1) is the equatorial radius of the */
/*                             reference spheroid */


/*                   CORPAR(2) is the flattening coefficient of the */
/*                             reference spheroid */


/*     BOUNDS     is a 2x2 array of bounds of the first two coordinates */
/*                of the segment's spatial coverage. BOUNDS(1,I) is */
/*                the lower bound of the Ith coordinate; BOUNDS(2,I) is */
/*                the upper bound. */

/*     A, */
/*     B, */
/*     C          are the lengths of the semi-axes of a triaxial */
/*                ellipsoid. The ellipsoid is centered at the origin and */
/*                oriented so that its axes lie on the x, y and z axes. */
/*                A, B, and C are the lengths of the semi-axes that */
/*                point in the x, y, and z directions respectively. */


/*     NLON       is the number of longitude bands in the plate set to */
/*                be created by this routine. Each longitude band is */
/*                bounded by two meridians. All longitude bands have */
/*                equal angular extent in longitude. The vertices of any */
/*                plate lie on adjacent longitude band boundaries. */


/*     NLAT       is the number of latitude bands in the plate set. The */
/*                vertices of each band are bounded by two cones of */
/*                constant planetocentric latitude. All latitude bands */
/*                have equal angular extent in planetocentric latitude. */
/*                The vertices of any plate lie on adjacent latitude */
/*                band boundaries. */

/*                Each polar "cap" consists of one longitude band. */


/*     MAKVTL     is a logical flag that controls whether a vertex-plate */
/*                mapping is created in the output segment. A mapping */
/*                is created if and only if MAKVTL is .TRUE. */


/*     DSK        is the name of the DSK file to write. If the file */
/*                does not exist, it will be created. If the file */
/*                exists, this routine will append to it. */

/* $ Detailed_Output */

/*     None. This routine operates by side effects. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the input frame name cannot be converted to an ID code, */
/*         the error SPICE(FRAMEIDNOTFOUND) will be signaled. */

/*     2)  Any errors that occur during the process of creating the */
/*         output segment's spatial index or of writing the DSK will be */
/*         signaled by routines in the call tree of this routine. */

/*     3)  If the length of any semi-axis of the ellipsoid is */
/*         non-positive, the error SPICE(INVALIDAXISLENGTH) is signaled. */

/* $ Files */

/*     See the description of DSK above. */

/* $ Particulars */

/*     This routine creates a DSK containing a single type 2 segment. */
/*     The plate and vertex data in the segment represent a tessellated */
/*     ellipsoid. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     1) For use only by TSPICE. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 28-JAN-2017 (NJB) */

/* -& */
/* $ Index_Entries */

/*     write type 2 dsk containing tessellated ellipsoid */

/* -& */
    if (return_()) {
	return 0;
    }
    chkin_("T_ELDSK2", (ftnlen)8);

/*     Convert the frame name to an ID code. */

    namfrm_(frname, &framid, frname_len);
    if (framid == 0) {
	setmsg_("Could not convert frame name # to an ID code.", (ftnlen)45);
	errch_("#", frname, (ftnlen)1, frname_len);
	sigerr_("SPICE(FRAMEIDNOTFOUND)", (ftnlen)22);
	chkout_("T_ELDSK2", (ftnlen)8);
	return 0;
    }

/*     Create vertices and plates. */

    zzellplt_(a, b, c__, nlon, nlat, &c_b40, &c_b24, &lnv, vrtces, &lnp, 
	    plates);
    if (failed_()) {
	chkout_("T_ELDSK2", (ftnlen)8);
	return 0;
    }

/*     Create a spatial index for the plate set. */

/*     Use a heuristic formula for the fine scale. */

/* Computing MAX */
    d__3 = (doublereal) lnp;
    d__1 = 1., d__2 = pow_dd(&d__3, &c_b10) / 8;
    finscl = max(d__1,d__2);

/*     Pick a one-size-fits-all value for the coarse scale. */

    corscl = 10;

/*     Set the spatial index integer component size. */

    if (*makvtl) {
	vpsize = 2000000;
	vlsize = 8000000;
	vmapsz = (lnv << 1) + lnp * 3;
	spxisz = vpsize + 100007 + vlsize + vmapsz;
    } else {
	vpsize = 4000000;
	vlsize = 16000000;
	spxisz = 20100007;
    }
    dskmi2_(&lnv, vrtces, &lnp, plates, &finscl, &corscl, &c_b11, &vpsize, &
	    vlsize, makvtl, &spxisz, work, spaixd, spaixi);

/*     Generate bounds for the 3rd coordinate. */

    dskrb2_(&lnv, vrtces, &lnp, plates, corsys, corpar, &mncor3, &mxcor3);
    if (failed_()) {
	chkout_("T_ELDSK2", (ftnlen)8);
	return 0;
    }

/*     Write the file. */

    if (exists_(dsk, dsk_len)) {

/*        Open the existing file for writing. */

	dasopw_(dsk, &handle, dsk_len);
    } else {

/*        Open a new file. */

	dskopn_(dsk, dsk, &c__0, &handle, dsk_len, dsk_len);
    }
    dskw02_(&handle, bodyid, surfid, &c__2, frname, corsys, corpar, bounds, &
	    bounds[1], &bounds[2], &bounds[3], &mncor3, &mxcor3, first, last, 
	    &lnv, vrtces, &lnp, plates, spaixd, spaixi, frname_len);

/*     Close the file. */

    dskcls_(&handle, &c_true);
    chkout_("T_ELDSK2", (ftnlen)8);
    return 0;
/* $Procedure T_ELDS2Z ( write tessellated ellipsoid type 2 DSK, easy ) */

L_t_elds2z:
/* $ Abstract */

/*     Write a type 2 DSK containing a tessellated ellipsoid. */
/*     Use default values to simplify the call. */

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

/* $ Keywords */

/*     ELLIPSOID */
/*     PLATE */
/*     TILE */
/*     TESSELLATE */
/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     INTEGER               BODYID */
/*     INTEGER               SURFID */
/*     CHARACTER*(*)         FRNAME */
/*     INTEGER               NLON */
/*     INTEGER               NLAT */
/*     CHARACTER*(*)         DSK */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     BODYID     I   Body ID. */
/*     SURFID     I   Surface ID. */
/*     FRNAME     I   Reference frame name. */
/*     NLON       I   Number of longitude bands in plate set. */
/*     NLAT       I   Number of latitude bands in plate set. */
/*     DSK        I   Name of DSK file to write. */

/* $ Detailed_Input */

/*     BODYID     is the body ID code of the segment to be written */
/*                to the output DSK file. */


/*     SURFID     is surface ID code. */


/*     FRNAME     is the name of the reference frame. */


/*     NLON       is the number of longitude bands in the plate set to */
/*                be created by this routine. Each longitude band is */
/*                bounded by two meridians. All longitude bands have */
/*                equal angular extent in longitude. The vertices of any */
/*                plate lie on adjacent longitude band boundaries. */


/*     NLAT       is the number of latitude bands in the plate set. The */
/*                vertices of each band are bounded by two cones of */
/*                constant planetocentric latitude. All latitude bands */
/*                have equal angular extent in planetocentric latitude. */
/*                The vertices of any plate lie on adjacent latitude */
/*                band boundaries. */

/*                Each polar "cap" consists of one longitude band. */


/*     DSK        is the name of the DSK file to write. If the file */
/*                does not exist, it will be created. If the file */
/*                exists, this routine will append to it. */

/* $ Detailed_Output */

/*     None. This routine operates by side effects. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the input frame name cannot be converted to an ID code, */
/*         the error SPICE(FRAMEIDNOTFOUND) will be signaled. */

/*     2)  Any errors that occur during the process of creating the */
/*         output segment's spatial index or of writing the DSK will be */
/*         signaled by routines in the call tree of this routine. */

/*     3)  If the length of any semi-axis of the ellipsoid is */
/*         non-positive, the error SPICE(INVALIDAXISLENGTH) is signaled. */

/* $ Files */

/*     Input: a PCK file must be loaded in order to provide radii of */
/*            the reference ellipsoid for the specified body. */

/*     Output: see the description of DSK above. */

/* $ Particulars */

/*     This is a simplified API for writing a tessellated ellipsoid */
/*     model to a DSK file. The following defaults are used */

/*        Time bounds:               -100 : 100 Julian years TDB */

/*        Coordinate system:         Latitudinal */

/*        Longitude bounds:          0     : 2*pi radians */
/*        Latitude bounds:           -pi/2 : pi/2 radians */

/*     This routine does not construct a vertex-plate mapping. */

/*     Ellipsoid radii for the specified body are obtained from the */
/*     kernel pool. */

/*     This routine creates a DSK containing a single type 2 segment. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     1) For use only by TSPICE. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 28-JAN-2017 (NJB) */

/* -& */
/* $ Index_Entries */

/*     write type 2 dsk containing tessellated ellipsoid, easy */

/* -& */
    if (return_()) {
	return 0;
    }
    chkin_("T_ELDS2Z", (ftnlen)8);

/*     Convert the frame name to an ID code. */

    namfrm_(frname, &framid, frname_len);
    if (framid == 0) {
	setmsg_("Could not convert frame name # to an ID code.", (ftnlen)45);
	errch_("#", frname, (ftnlen)1, frname_len);
	sigerr_("SPICE(FRAMEIDNOTFOUND)", (ftnlen)22);
	chkout_("T_ELDS2Z", (ftnlen)8);
	return 0;
    }

/*     Get target body radii from the kernel pool. */

    bodvcd_(bodyid, "RADII", &c__3, &n, radii, (ftnlen)5);
    if (failed_()) {
	chkout_("T_ELDS2Z", (ftnlen)8);
	return 0;
    }

/*     Create vertices and plates. */

    zzellplt_(radii, &radii[1], &radii[2], nlon, nlat, &c_b40, &c_b24, &lnv, 
	    vrtces, &lnp, plates);
    if (failed_()) {
	chkout_("T_ELDS2Z", (ftnlen)8);
	return 0;
    }

/*     Create a spatial index for the plate set. */

/*     Use a heuristic formula for the fine scale. */

/* Computing MAX */
    d__3 = (doublereal) lnp;
    d__1 = 1., d__2 = pow_dd(&d__3, &c_b10) / 8;
    finscl = max(d__1,d__2);

/*     Pick a one-size-fits-all value for the coarse scale. */

    corscl = 10;

/*     Set the spatial index integer component size. */

    vpsize = 4000000;
    vlsize = 16000000;
    spxisz = 20100007;
    dskmi2_(&lnv, vrtces, &lnp, plates, &finscl, &corscl, &c_b11, &c_b24, &
	    c_b25, &c_false, &spxisz, work, spaixd, spaixi);

/*     Generate bounds for the 3rd coordinate. */

    dskrb2_(&lnv, vrtces, &lnp, plates, &c__1, locpar, &mncor3, &mxcor3);
    if (failed_()) {
	chkout_("T_ELDS2Z", (ftnlen)8);
	return 0;
    }

/*     Set default inputs. */

    mncor1 = 0.;
    mxcor1 = twopi_();
    mncor2 = -halfpi_();
    mxcor2 = halfpi_();
    et0 = -jyear_() * 100;
    et1 = jyear_() * 100;
    cleard_(&c__10, locpar);

/*     Write the file. */

    if (exists_(dsk, dsk_len)) {

/*        Open the existing file for writing. */

	dasopw_(dsk, &handle, dsk_len);
    } else {

/*        Open a new file. */

	dskopn_(dsk, dsk, &c__0, &handle, dsk_len, dsk_len);
    }
    dskw02_(&handle, bodyid, surfid, &c__2, frname, &c__1, locpar, &mncor1, &
	    mxcor1, &mncor2, &mxcor2, &mncor3, &mxcor3, &et0, &et1, &lnv, 
	    vrtces, &lnp, plates, spaixd, spaixi, frname_len);

/*     Close the file. */

    dskcls_(&handle, &c_true);
    chkout_("T_ELDS2Z", (ftnlen)8);
    return 0;
/* $Procedure T_SMLDSK ( write small DSK ) */

L_t_smldsk:
/* $ Abstract */

/*     Write a trivial type 2 DSK containing one plate. */

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

/* $ Keywords */

/*     PLATE */
/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     INTEGER               BODYID */
/*     INTEGER               SURFID */
/*     CHARACTER*(*)         FRNAME */
/*     CHARACTER*(*)         DSK */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     BODYID     I   Body ID. */
/*     SURFID     I   Surface ID. */
/*     FRNAME     I   Reference frame name. */
/*     DSK        I   Name of DSK file to write. */

/* $ Detailed_Input */

/*     BODYID     is the body ID code of the segment to be written */
/*                to the output DSK file. */

/*     SURFID     is surface ID code. */

/*     FRNAME     is the name of the reference frame. */

/*     DSK        is the name of the DSK file to write. If the file */
/*                does not exist, it will be created. If the file */
/*                exists, this routine will append to it. */

/*                The DSK is file is unsegregated. */

/* $ Detailed_Output */

/*     None. This routine operates by side effects. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the input frame name cannot be converted to an ID code, */
/*         the error SPICE(FRAMEIDNOTFOUND) will be signaled. */

/*     2)  Any errors that occur during the process of creating the */
/*         output segment's spatial index or of writing the DSK will be */
/*         signaled by routines in the call tree of this routine. */

/* $ Files */

/*     Output: see the description of DSK above. */

/* $ Particulars */

/*     This is a simplified API for quickly writing small DSK file. The */
/*     file contains one type 2 segment; the segment contains a single */
/*     plate. */

/*     The output file is unsegregated. */

/*     Files created by this routine are suitable for testing */
/*     load/unload operations. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     1) For use only by TSPICE. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 28-JAN-2017 (NJB) */

/* -& */
/* $ Index_Entries */

/*     write small type 2 dsk */

/* -& */
    if (return_()) {
	return 0;
    }
    chkin_("T_SMLDSK", (ftnlen)8);

/*     Convert the frame name to an ID code. */

    namfrm_(frname, &framid, frname_len);
    if (framid == 0) {
	setmsg_("Could not convert frame name # to an ID code.", (ftnlen)45);
	errch_("#", frname, (ftnlen)1, frname_len);
	sigerr_("SPICE(FRAMEIDNOTFOUND)", (ftnlen)22);
	chkout_("T_SMLDSK", (ftnlen)8);
	return 0;
    }
    lnp = 1;
    lnv = 3;
    vpack_(&c_b79, &c_b79, &c_b79, vrtces);
    vpack_(&c_b82, &c_b79, &c_b79, &vrtces[3]);
    vpack_(&c_b79, &c_b82, &c_b79, &vrtces[6]);
    plates[0] = 1;
    plates[1] = 2;
    plates[2] = 3;
    vpsize = 32;
    vlsize = 40;
    spxisz = 100100;
    finscl = 1.;
    corscl = 1;

/*     Set default inputs. */

    mncor1 = 0.;
    mxcor1 = twopi_();
    mncor2 = -halfpi_();
    mxcor2 = halfpi_();
    mncor3 = 0.;
    mxcor3 = 1.;
    et0 = -jyear_() * 100;
    et1 = jyear_() * 100;
    cleard_(&c__10, locpar);
    if (small1) {
	dskmi2_(&lnv, vrtces, &lnp, plates, &finscl, &corscl, &c_b11, &vpsize,
		 &vlsize, &c_false, &spxisz, work, smlixd, smlixi);
	if (failed_()) {
	    chkout_("T_SMLDSK", (ftnlen)8);
	    return 0;
	}
	small1 = FALSE_;
    }

/*     Write the file. */

    if (exists_(dsk, dsk_len)) {

/*        Open the existing file for writing. */

	dasopw_(dsk, &handle, dsk_len);
    } else {

/*        Open a new file. */

	dskopn_(dsk, dsk, &c__0, &handle, dsk_len, dsk_len);
    }
    dskw02_(&handle, bodyid, surfid, &c__2, frname, &c__1, locpar, &mncor1, &
	    mxcor1, &mncor2, &mxcor2, &mncor3, &mxcor3, &et0, &et1, &lnv, 
	    vrtces, &lnp, plates, smlixd, smlixi, frname_len);

/*     Close the file. */

    dskcls_(&handle, &c_false);
    chkout_("T_SMLDSK", (ftnlen)8);
    return 0;
/* $Procedure T_CG ( write simplified comet C-G DSK ) */

L_t_cg:
/* $ Abstract */

/*     Write a DSK containing an extremely simplified shape model */
/*     representing the nucleus of comet Churymov-Gerasimenko. The model */
/*     is a union of boxes. */

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

/* $ Keywords */

/*     PLATE */
/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     CHARACTER*(*)         DSK */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     BODYID     I   Body ID. */
/*     SURFID     I   Surface ID. */
/*     FRNAME     I   Reference frame name. */
/*     DSK        I   Name of DSK file to write. */

/* $ Detailed_Input */

/*     BODYID     is the body ID code of the segment to be written */
/*                to the output DSK file. */

/*     SURFID     is surface ID code. */

/*     FRNAME     is the name of the reference frame. */

/*     DSK        is the name of the DSK file to write. If the file */
/*                does not exist, it will be created. If the file */
/*                exists, this routine will append to it. */

/* $ Detailed_Output */

/*     None. This routine operates by side effects. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the input frame name cannot be converted to an ID code, */
/*         the error SPICE(FRAMEIDNOTFOUND) will be signaled. */

/*     2)  Any errors that occur during the process of creating the */
/*         output segment's spatial index or of writing the DSK will be */
/*         signaled by routines in the call tree of this routine. */

/* $ Files */

/*     Output: see the description of DSK above. */

/* $ Particulars */

/*     This routine writes a DSK that contains a representation */
/*     of the shape similar to that of comet Churymov-Gerasimenko. */
/*     The model is composed of several boxes. */

/*     The output file contains a single type 2 segment. */

/*     The ID codes in the output file are provided by the user. */
/*     The user may wish to center the segment on a body other */
/*     than comet C-G. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     1) For use only by TSPICE. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 28-JAN-2017 (NJB) */

/* -& */
/* $ Index_Entries */

/*     write comet cg-like dsk */

/* -& */
    if (return_()) {
	return 0;
    }
    chkin_("T_CG", (ftnlen)4);

/*     Treat the local vertex and plate arrays as cells, */
/*     since the API of ZZT_CG requires this. */

    lsizev = 100;
    lsizep = 200;
    ssized_(&lsizev, vrtces);
    ssizei_(&lsizep, plates);

/*     Create vertices and plates. In each array, data */
/*     start at 1-dimensional index LBCELL+1. This */
/*     location coincides with the 2-dimensional index (1,3). */

    zzt_cg__(vrtces, plates);
    if (failed_()) {
	chkout_("T_CG", (ftnlen)4);
	return 0;
    }
    lnv = cardd_(vrtces) / 3;
    lnp = cardi_(plates) / 3;

/*     Create a spatial index for the plate set. */

    finscl = 1.;

/*     We can use a small coarse scale. */

    corscl = 1;

/*     Set the spatial index integer component size. */

    vpsize = 4000000;
    vlsize = 16000000;
    spxisz = 20100007;
    dskmi2_(&lnv, &vrtces[6], &lnp, &plates[6], &finscl, &corscl, &c_b11, &
	    c_b24, &c_b25, &c_false, &spxisz, work, spaixd, spaixi);

/*     Generate bounds for the 3rd coordinate. */

    dskrb2_(&lnv, &vrtces[6], &lnp, &plates[6], &c__1, locpar, &mncor3, &
	    mxcor3);
    if (failed_()) {
	chkout_("T_CG", (ftnlen)4);
	return 0;
    }

/*     Set default inputs. */

    mncor1 = 0.;
    mxcor1 = twopi_();
    mncor2 = -halfpi_();
    mxcor2 = halfpi_();
    et0 = -jyear_() * 100;
    et1 = jyear_() * 100;
    cleard_(&c__10, locpar);

/*     Write the file. */

    if (exists_(dsk, dsk_len)) {

/*        Open the existing file for writing. */

	dasopw_(dsk, &handle, dsk_len);
    } else {

/*        Open a new file. */

	dskopn_(dsk, dsk, &c__0, &handle, dsk_len, dsk_len);
    }
    dskw02_(&handle, bodyid, surfid, &c__2, frname, &c__1, locpar, &mncor1, &
	    mxcor1, &mncor2, &mxcor2, &mncor3, &mxcor3, &et0, &et1, &lnv, &
	    vrtces[6], &lnp, &plates[6], spaixd, spaixi, frname_len);

/*     Close the file. */

    dskcls_(&handle, &c_true);
    chkout_("T_CG", (ftnlen)4);
    return 0;
/* $Procedure T_SECDS2 ( DSK test, write ellipsoid section DSK ) */

L_t_secds2:
/* $ Abstract */

/*     Write a type 2 DSK containing a section of a tessellated */
/*     ellipsoid. */

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

/* $ Keywords */

/*     ELLIPSOID */
/*     PLATE */
/*     TILE */
/*     TESSELLATE */
/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     INTEGER               BODYID */
/*     INTEGER               SURFID */
/*     CHARACTER*(*)         FRNAME */
/*     DOUBLE PRECISION      FIRST */
/*     DOUBLE PRECISION      LAST */
/*     INTEGER               CORSYS */
/*     DOUBLE PRECISION      CORPAR ( * ) */
/*     DOUBLE PRECISION      BOUNDS ( 2, 2 ) */
/*     DOUBLE PRECISION      A */
/*     DOUBLE PRECISION      B */
/*     DOUBLE PRECISION      C */
/*     INTEGER               NLON */
/*     INTEGER               NLAT */
/*     LOGICAL               MAKVTL */
/*     LOGICAL               USEPAD */
/*     CHARACTER*(*)         DSK */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     BODYID     I   Body ID. */
/*     SURFID     I   Surface ID. */
/*     FRNAME     I   Reference frame name. */
/*     FIRST      I   Start time, TDB. */
/*     LAST       I   Stop time, TDB. */
/*     CORSYS     I   Coordinate system code. */
/*     CORPAR     I   Coordinate parameters. */
/*     BOUNDS     I   Segment spatial bounds. */
/*     A          I   Length of ellipsoid semi-axis lying on the x-axis. */
/*     B          I   Length of ellipsoid semi-axis lying on the y-axis. */
/*     C          I   Length of ellipsoid semi-axis lying on the z-axis. */
/*     NLON       I   Number of longitude bands in plate set. */
/*     NLAT       I   Number of latitude bands in plate set. */
/*     MAKVTL     I   Vertex-plate mapping flag. */
/*     USEPAD     I   Padding flag. */
/*     DSK        I   Name of DSK file to write. */

/* $ Detailed_Input */

/*     BODYID     is the body ID code of the segment to be written */
/*                to the output DSK file. */

/*     SURFID     is surface ID code. */

/*     FRNAME     is the name of the reference frame. */

/*     FIRST, */
/*     LAST       are, respectively, the start and stop times of */
/*                the coverage interval of the segment. FIRST and */
/*                LAST are expressed as seconds past J2000, TDB. */

/*     CORSYS     is an integer code designating the coordinate */
/*                system of the segment. Limited to planetocentric */
/*                coordinates for full functionality. Planetodetic */
/*                coordinates may be used if padding generation is */
/*                not invoked. */


/*     CORPAR     is an array of parameters associated with */
/*                the coordinate system. */

/*                For planetodetic coordinates, */

/*                   CORPAR(1) is the equatorial radius of the */
/*                             reference spheroid */


/*                   CORPAR(2) is the flattening coefficient of the */
/*                             reference spheroid */


/*     BOUNDS     is a 2x2 array of bounds of the first two coordinates */
/*                of the segment's spatial coverage. BOUNDS(1,I) is */
/*                the lower bound of the Ith coordinate; BOUNDS(2,I) is */
/*                the upper bound. */

/*     A, */
/*     B, */
/*     C          are the lengths of the semi-axes of a triaxial */
/*                ellipsoid. The ellipsoid is centered at the origin and */
/*                oriented so that its axes lie on the x, y and z axes. */
/*                A, B, and C are the lengths of the semi-axes that */
/*                point in the x, y, and z directions respectively. */


/*     NLON       is the number of longitude bands in the plate set to */
/*                be created by this routine. Each longitude band is */
/*                bounded by two meridians. All longitude bands have */
/*                equal angular extent in longitude. The vertices of any */
/*                plate lie on adjacent longitude band boundaries. */

/*                If padding is enabled, an extra longitude band will be */
/*                created at both longitude boundaries of the segment. */


/*     NLAT       is the number of latitude bands in the plate set. The */
/*                vertices of each band are bounded by two cones of */
/*                constant planetocentric latitude. All latitude bands */
/*                have equal angular extent in planetocentric latitude. */
/*                The vertices of any plate lie on adjacent latitude */
/*                band boundaries. */

/*                Each polar "cap" consists of one longitude band. */

/*                If padding is enabled, and if the segment does not */
/*                span the X-Y plane, one or more extra latitude bands */
/*                will be created at the segment latitude boundary */
/*                closest to the X-Y plane. A single extra latitude band */
/*                will be created at the other latitude boundary. If the */
/*                segment spans the X-Y plane, then a single extra */
/*                latitude bound will be created at each latitude */
/*                boundary. */


/*     MAKVTL     is a logical flag that controls whether a vertex-plate */
/*                mapping is created in the output segment. A mapping */
/*                is created if and only if MAKVTL is .TRUE. */


/*     USEPAD     is a logical flag indicating whether segment padding */
/*                is to be created. When USEPAD is .TRUE., sections */
/*                having positive lower latitude bounds are padded at */
/*                the bottom to ensure coverage. This padding consists */
/*                of an integral number of extra latitude bands. Each of */
/*                the other boundaries are padded with a single latitude */
/*                or longitude band. Whe USEPAD is .FALSE., no padding */
/*                is created. */

/*                See Restrictions below. */


/*     DSK        is the name of the DSK file to write. If the file */
/*                does not exist, it will be created. If the file */
/*                exists, this routine will append to it. */

/* $ Detailed_Output */

/*     None. This routine operates by side effects. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the input frame name cannot be converted to an ID code, */
/*         the error SPICE(FRAMEIDNOTFOUND) will be signaled. */

/*     2)  Any errors that occur during the process of creating the */
/*         output segment's spatial index or of writing the DSK will be */
/*         signaled by routines in the call tree of this routine. */

/*     3)  If the length of any semi-axis of the ellipsoid is */
/*         non-positive, the error SPICE(INVALIDAXISLENGTH) is signaled. */

/*     4)  If either the longitude or latitude band count is */
/*         non-positive, the error SPICE(VALUEOUTOFRANGE) is signaled. */

/*     5)  If the input latitude bounds are out of order, the error */
/*         SPICE(BOUNDSOUTOFORDER) is signaled. */

/* $ Files */

/*     See the description of DSK above. */

/* $ Particulars */

/*     This routine creates a DSK containing a single type 2 segment. */
/*     The plate and vertex data in the segment represent a section of a */
/*     tessellated ellipsoid. The section covers a specified longitude/ */
/*     latitude rectangle. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     1) For use only by TSPICE. */

/*     2) Currently restricted to latitudinal coordinates for full */
/*        functionality. Planetodetic and rectangular coordinates may be */
/*        used if padding generation is not commanded. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 28-JAN-2017 (NJB) */

/* -& */
/* $ Index_Entries */

/*     write type 2 dsk containing ellipsoid section */

/* -& */
    if (return_()) {
	return 0;
    }
    chkin_("T_SECDS2", (ftnlen)8);

/*     Check coordinate system. */

    if (*corsys != 1 && *corsys != 4 && *corsys != 3) {
	setmsg_("Input coordinate system code was #. Only latitudinal, plane"
		"todetic, and rectangular coordinates are currently supported"
		" by this routine.", (ftnlen)136);
	errint_("#", corsys, (ftnlen)1);
	sigerr_("SPICE(NOTSUPPORTED)", (ftnlen)19);
	chkout_("T_SECDS2", (ftnlen)8);
	return 0;
    }

/*     Convert the frame name to an ID code. */

    namfrm_(frname, &framid, frname_len);
    if (framid == 0) {
	setmsg_("Could not convert frame name # to an ID code.", (ftnlen)45);
	errch_("#", frname, (ftnlen)1, frname_len);
	sigerr_("SPICE(FRAMEIDNOTFOUND)", (ftnlen)22);
	chkout_("T_SECDS2", (ftnlen)8);
	return 0;
    }

/*     Check band counts. */

    if (*nlat < 1) {
	setmsg_("Latitude band count must be positive but was #.", (ftnlen)47)
		;
	errint_("#", nlat, (ftnlen)1);
	sigerr_("SPICE(VALUEOUTOFRANGE)", (ftnlen)22);
	chkout_("T_SECDS2", (ftnlen)8);
	return 0;
    }
    if (*nlon < 1) {
	setmsg_("Longitude band count must be positive but was #.", (ftnlen)
		48);
	errint_("#", nlon, (ftnlen)1);
	sigerr_("SPICE(VALUEOUTOFRANGE)", (ftnlen)22);
	chkout_("T_SECDS2", (ftnlen)8);
	return 0;
    }

/*     Reject invalid latitude bounds. */

    if (bounds[3] < bounds[2]) {
	setmsg_("Latitude bounds are out of order: bounds are #:#.", (ftnlen)
		49);
	errdp_("#", &bounds[2], (ftnlen)1);
	errdp_("#", &bounds[3], (ftnlen)1);
	sigerr_("SPICE(BOUNDSOUTOFORDER)", (ftnlen)23);
	chkout_("T_SECDS2", (ftnlen)8);
	return 0;
    }

/*     Make local copies of the band counts. */

    lnlon = *nlon;
    lnlat = *nlat;

/*     Create vertices and plates. */

    if (*usepad) {
	if (*corsys != 1) {
	    setmsg_("Padding generation was requested for coordinate system "
		    "#. This service is available only for planetocentric coo"
		    "rdinates.", (ftnlen)120);
	    errint_("#", corsys, (ftnlen)1);
	    sigerr_("SPICE(NOTSUPPORTED)", (ftnlen)19);
	    chkout_("T_SECDS2", (ftnlen)8);
	    return 0;
	}

/*        Determine sizes of longitude and latitude bands. */

	minlat = bounds[2];
	maxlat = bounds[3];
	dlat = (maxlat - minlat) / *nlat;
	minlon = bounds[0];
	maxlon = bounds[1];
	if (maxlon <= minlon) {
	    maxlon += twopi_();
	}
	dlon = (maxlon - minlon) / *nlon;

/*        Determine the latitude padding. */

	if (maxlat >= 0.) {

/*           Add just one upper band, if it will fit. If not, */
/*           don't create a smaller band; just omit the band. */

	    if (maxlat + dlat < halfpi_()) {
		maxlat += dlat;
		++lnlat;
	    }
	} else {

/*           Determine the adjusted latitude needed for full */
/*           latitude coverage. */

	    zzchrlat_(&maxlat, &dlon, &adjlat);
	    if (failed_()) {
		chkout_("T_SECDS2", (ftnlen)8);
		return 0;
	    }
	    delta = adjlat - maxlat;

/*           Determine the number of latitude bands that must */
/*           be added to give the required coverage. */

	    q = delta / dlat;
	    if (q > d_int(&q)) {

/*              Q has a non-zero fractional part. */

		q = d_int(&q) + 1.;
	    }
	    maxlat += q * dlat;
	    lnlat += (integer) q;
	}

/*        MAXLAT and LNLAT have been updated to account for */
/*        upper padding, if it has been added. */

	if (minlat <= 0.) {

/*           Add just one lower band, if it will fit. If not, */
/*           don't create a smaller band; just omit the band. */

	    if (minlat - dlat > -halfpi_()) {
		minlat -= dlat;
		++lnlat;
	    }
	} else {

/*           Determine the adjusted latitude needed for full */
/*           latitude coverage. */

	    zzchrlat_(&minlat, &dlon, &adjlat);
	    if (failed_()) {
		chkout_("T_SECDS2", (ftnlen)8);
		return 0;
	    }
	    delta = minlat - adjlat;

/*           Determine the number of latitude bands that must */
/*           be added to give the required coverage. */

	    q = delta / dlat;
	    if (q > d_int(&q)) {

/*              Q has a non-zero fractional part. */

		q = d_int(&q) + 1.;
	    }
	    minlat -= q * dlat;
	    lnlat += (integer) q;
	}

/*        MAXLAT and LNLAT have been updated to account for */
/*        lower padding, if it has been added. */


/*        Adjust the longitude boundaries and band count to */
/*        reflect longitude padding. Padded is added only if */
/*        the padded section would have 2*pi longitude extent or */
/*        less. */

	if (maxlon - minlon < twopi_() - dlon * 2) {

/*           Add longitude padding. */

	    minlon -= dlon;
	    maxlon += dlon;
	    lnlon += 2;
	}

/*        Create a vertex and plate set that includes padding. */

	zzellsec_(a, b, c__, &minlon, &maxlon, &minlat, &maxlat, &lnlon, &
		lnlat, &c_b40, &c_b24, &lnv, vrtces, &lnp, plates);
    } else {

/*        Create a vertex and plate set only for the specified region. */

	zzellsec_(a, b, c__, bounds, &bounds[1], &bounds[2], &bounds[3], nlon,
		 nlat, &c_b40, &c_b24, &lnv, vrtces, &lnp, plates);
    }
    if (failed_()) {
	chkout_("T_SECDS2", (ftnlen)8);
	return 0;
    }

/*     Create a spatial index for the plate set. */

/*     Use a heuristic formula for the fine scale. */

/* Computing MAX */
    d__3 = (doublereal) lnp;
    d__1 = 1., d__2 = pow_dd(&d__3, &c_b10) / 8;
    finscl = max(d__1,d__2);

/*     Pick a one-size-fits-all value for the coarse scale. */

    corscl = 10;

/*     Set the spatial index integer component size. */

    if (*makvtl) {
	vpsize = 2000000;
	vlsize = 8000000;
	vmapsz = (lnv << 1) + lnp * 3;
	spxisz = vpsize + 100007 + vlsize + vmapsz;
    } else {
	vpsize = 4000000;
	vlsize = 16000000;
	spxisz = 20100007;
    }
    dskmi2_(&lnv, vrtces, &lnp, plates, &finscl, &corscl, &c_b11, &vpsize, &
	    vlsize, makvtl, &spxisz, work, spaixd, spaixi);

/*     Generate bounds for the 3rd coordinate. */

    dskrb2_(&lnv, vrtces, &lnp, plates, corsys, corpar, &mncor3, &mxcor3);
    if (failed_()) {
	chkout_("T_SECDS2", (ftnlen)8);
	return 0;
    }

/*     Write the file. */

    if (exists_(dsk, dsk_len)) {

/*        Open the existing file for writing. */

	dasopw_(dsk, &handle, dsk_len);
    } else {

/*        Open a new file. */

	dskopn_(dsk, dsk, &c__0, &handle, dsk_len, dsk_len);
    }
    dskw02_(&handle, bodyid, surfid, &c__2, frname, corsys, corpar, bounds, &
	    bounds[1], &bounds[2], &bounds[3], &mncor3, &mxcor3, first, last, 
	    &lnv, vrtces, &lnp, plates, spaixd, spaixi, frname_len);

/*     Close the file. */

    dskcls_(&handle, &c_true);
    chkout_("T_SECDS2", (ftnlen)8);
    return 0;
/* $Procedure T_TORUS ( write DSK containing torus plate model ) */

L_t_torus:
/* $ Abstract */

/*     Write a DSK containing a plate model representing a torus. */

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

/* $ Keywords */

/*     PLATE */
/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     INTEGER               BODYID */
/*     INTEGER               SURFID */
/*     CHARACTER*(*)         FRNAME */
/*     INTEGER               NPOLYV */
/*     INTEGER               NCROSS */
/*     DOUBLE PRECISION      R */
/*     DOUBLE PRECISION      RCROSS */
/*     DOUBLE PRECISION      CENTER ( 3 ) */
/*     DOUBLE PRECISION      NORMAL ( 3 ) */
/*     CHARACTER*(*)         DSK */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     BODYID     I   Body ID. */
/*     SURFID     I   Surface ID. */
/*     FRNAME     I   Reference frame name. */
/*     NPOLYV     I   Number of vertices in polygonal cross section. */
/*     NCROSS     I   Number of cross sections. */
/*     R          I   Radius of central curve. */
/*     RCROSS     I   Radius of cross section. */
/*     CENTER     I   Center of the torus. */
/*     NORMAL     I   Normal vector to plane of central curve. */
/*     DSK        I   Name of DSK file to write. */

/* $ Detailed_Input */

/*     BODYID     is the body ID code of the segment to be written */
/*                to the output DSK file. */

/*     SURFID     is surface ID code. */

/*     FRNAME     is the name of the reference frame. */

/*     NPOLYV     is the number of vertices per polygonal cross section */
/*                of the torus. Each cross section is the set of */
/*                vertices of a regular polygon inscribed in a circle of */
/*                radius RCROSS (see below). Each cross section lies in */
/*                a plane normal to the derivative of the central curve */
/*                at its point of intersection with the plane. */

/*     NCROSS     is the number of cross sections of the torus. */

/*     R          is the radius of the central curve of the torus. */
/*                Each cross section is centered on this curve and */
/*                is normal to the derivative of the curve at the point */
/*                of intersection. */

/*     RCROSS     is the radius of each circular cross section of the */
/*                torus. */

/*     CENTER     is the center of the torus. This is the center of the */
/*                central curve of the torus. The line normal to the */
/*                plane of the central curve and passing through CENTER */
/*                is the axis of azimuthal symmetry of the torus. */

/*     NORMAL     is a vector normal to the plane containing the */
/*                central curve of the torus. */

/*     DSK        is the name of the DSK file to write. If the file */
/*                does not exist, it will be created. If the file */
/*                exists, this routine will append to it. */

/* $ Detailed_Output */

/*     None. This routine operates by side effects. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the input frame name cannot be converted to an ID code, */
/*         the error SPICE(FRAMEIDNOTFOUND) will be signaled. */

/*     2)  Any errors that occur during the process of creating the */
/*         output segment's spatial index or of writing the DSK will be */
/*         signaled by routines in the call tree of this routine. */

/* $ Files */

/*     Output: see the description of DSK above. */

/* $ Particulars */

/*     In a Cartesian coordinate system having the Z axis parallel to */
/*     NORMAL, and having an origin coincident with CENTER, the torus */
/*     is the set of points */

/*                                2   2  1/2  2     2           2 */
/*        { (x,y,z) : (  R  -  ( x + y  )    )  +  z   =  RCROSS  } */


/*     This routine can be used to create shape models suitable for */
/*     testing limb finding and terminator finding routines. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     1) For use only by TSPICE. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 28-JAN-2017 (NJB) */

/* -& */
/* $ Index_Entries */

/*     write dsk containing torus plate model */

/* -& */
    if (return_()) {
	return 0;
    }
    chkin_("T_TORUS", (ftnlen)7);
    if (*npolyv < 3) {
	setmsg_("Polygon side count # must be at least three.", (ftnlen)44);
	errint_("#", npolyv, (ftnlen)1);
	sigerr_("SPICE(INVALIDCOUNT)", (ftnlen)19);
	chkout_("T_TORUS", (ftnlen)7);
	return 0;
    }
    if (*ncross < 3) {
	setmsg_("Cross section count # must be at least three.", (ftnlen)45);
	errint_("#", ncross, (ftnlen)1);
	sigerr_("SPICE(INVALIDCOUNT)", (ftnlen)19);
	chkout_("T_TORUS", (ftnlen)7);
	return 0;
    }

/*     Initialize the routine that generates the central curve */
/*     for the torus. */

    t_torset__(r__, center, normal);
    if (failed_()) {
	chkout_("T_TORUS", (ftnlen)7);
	return 0;
    }

/*     Generate the cross-section polygon for the torus. The polygon is */
/*     positively oriented about the first endpoint of the central */
/*     curve. */

/*     Start by generating a first vertex on the polygon. V0 is a point */
/*     on the central curve. */

    t_torcrv__(&c_b79, &c0, d0, &twist);
    frame_(d0, x, y);
    vscl_(rcross, x, v0);

/*     Generate the rest of the vertices. */

    vequ_(v0, vrtces);
    i__1 = *npolyv;
    for (i__ = 2; i__ <= i__1; ++i__) {

/*        NPOLYV has been checked to ensure it's non-zero. */

	theta = (i__ - 1) * twopi_() / *npolyv;
	vrotv_(v0, d0, &theta, &vrtces[(i__2 = i__ * 3 - 3) < 6000000 && 0 <= 
		i__2 ? i__2 : s_rnge("vrtces", i__2, "t_wrdsk2__", (ftnlen)
		2914)]);
    }

/*     Prepare to use the rest of the VRTCES array as a cell. */

    base = *npolyv + 1;
    size = (2000000 - *npolyv - 2) * 3;
    ssized_(&size, &vrtces[(i__1 = base * 3 - 3) < 6000000 && 0 <= i__1 ? 
	    i__1 : s_rnge("vrtces", i__1, "t_wrdsk2__", (ftnlen)2925)]);
    ssizei_(&c_b166, plates);

/*     Create a tube centered on the central curve. This is the */
/*     torus. */

    zzpstube_(npolyv, vrtces, (S_fp)t_torcrv__, ncross, &c_true, &vrtces[(
	    i__1 = base * 3 - 3) < 6000000 && 0 <= i__1 ? i__1 : s_rnge("vrt"
	    "ces", i__1, "t_wrdsk2__", (ftnlen)2932)], plates);
    if (failed_()) {
	chkout_("T_TORUS", (ftnlen)7);
	return 0;
    }

/*     Get the vertex and plate counts. */

    lnv = cardd_(&vrtces[(i__1 = base * 3 - 3) < 6000000 && 0 <= i__1 ? i__1 :
	     s_rnge("vrtces", i__1, "t_wrdsk2__", (ftnlen)2943)]) / 3;
    lnp = cardi_(plates) / 3;

/*     Create a spatial index for the plate set. */

/*     Use a heuristic formula for the fine scale. */

/* Computing MAX */
    d__3 = (doublereal) lnp;
    d__1 = 1., d__2 = pow_dd(&d__3, &c_b10) / 8;
    finscl = max(d__1,d__2);

/*     Pick a one-size-fits-all value for the coarse scale. */

    corscl = 10;

/*     Set the spatial index integer component size. */

    vpsize = 4000000;
    vlsize = 16000000;
    spxisz = 20100007;
    dskmi2_(&lnv, &vrtces[(i__1 = (base + 2) * 3 - 3) < 6000000 && 0 <= i__1 ?
	     i__1 : s_rnge("vrtces", i__1, "t_wrdsk2__", (ftnlen)2966)], &lnp,
	     &plates[6], &finscl, &corscl, &c_b11, &vpsize, &vlsize, &c_false,
	     &spxisz, work, spaixd, spaixi);

/*     Generate bounds for the 3rd coordinate. */

    dskrb2_(&lnv, &vrtces[(i__1 = (base + 2) * 3 - 3) < 6000000 && 0 <= i__1 ?
	     i__1 : s_rnge("vrtces", i__1, "t_wrdsk2__", (ftnlen)2975)], &lnp,
	     &plates[6], &c__1, locpar, &mncor3, &mxcor3);
    if (failed_()) {
	chkout_("T_TORUS", (ftnlen)7);
	return 0;
    }

/*     Write the file. */

    if (exists_(dsk, dsk_len)) {

/*        Open the existing file for writing. */

	dasopw_(dsk, &handle, dsk_len);
    } else {

/*        Open a new file. */

	dskopn_(dsk, dsk, &c__0, &handle, dsk_len, dsk_len);
    }

/*     Set default inputs. */

    mncor1 = 0.;
    mxcor1 = twopi_();
    mncor2 = -halfpi_();
    mxcor2 = halfpi_();
    et0 = -jyear_() * 100;
    et1 = jyear_() * 100;
    cleard_(&c__10, locpar);

/*     Write the file. */

    dskw02_(&handle, bodyid, surfid, &c__2, frname, &c__1, locpar, &mncor1, &
	    mxcor1, &mncor2, &mxcor2, &mncor3, &mxcor3, &et0, &et1, &lnv, &
	    vrtces[(i__1 = (base + 2) * 3 - 3) < 6000000 && 0 <= i__1 ? i__1 :
	     s_rnge("vrtces", i__1, "t_wrdsk2__", (ftnlen)3018)], &lnp, &
	    plates[6], spaixd, spaixi, frname_len);

/*     Close the file. */

    dskcls_(&handle, &c_true);
    chkout_("T_TORUS", (ftnlen)7);
    return 0;
} /* t_wrdsk2__ */

/* Subroutine */ int t_wrdsk2__(integer *bodyid, integer *surfid, char *
	frname, doublereal *first, doublereal *last, doublereal *a, 
	doublereal *b, doublereal *c__, integer *corsys, doublereal *corpar, 
	doublereal *bounds, integer *nlon, integer *nlat, integer *nv, 
	integer *np, doublereal *usrvrt, integer *usrplt, logical *makvtl, 
	logical *usepad, integer *npolyv, integer *ncross, doublereal *r__, 
	doublereal *rcross, doublereal *center, doublereal *normal, char *dsk,
	 ftnlen frname_len, ftnlen dsk_len)
{
    return t_wrdsk2__0_(0, bodyid, surfid, frname, first, last, a, b, c__, 
	    corsys, corpar, bounds, nlon, nlat, nv, np, usrvrt, usrplt, 
	    makvtl, usepad, npolyv, ncross, r__, rcross, center, normal, dsk, 
	    frname_len, dsk_len);
    }

/* Subroutine */ int t_wrtplt__(integer *bodyid, integer *surfid, char *
	frname, doublereal *first, doublereal *last, integer *corsys, 
	doublereal *corpar, doublereal *bounds, integer *nv, integer *np, 
	doublereal *usrvrt, integer *usrplt, logical *makvtl, char *dsk, 
	ftnlen frname_len, ftnlen dsk_len)
{
    return t_wrdsk2__0_(1, bodyid, surfid, frname, first, last, (doublereal *)
	    0, (doublereal *)0, (doublereal *)0, corsys, corpar, bounds, (
	    integer *)0, (integer *)0, nv, np, usrvrt, usrplt, makvtl, (
	    logical *)0, (integer *)0, (integer *)0, (doublereal *)0, (
	    doublereal *)0, (doublereal *)0, (doublereal *)0, dsk, frname_len,
	     dsk_len);
    }

/* Subroutine */ int t_wrtplz__(integer *bodyid, integer *surfid, char *
	frname, integer *nv, integer *np, doublereal *usrvrt, integer *usrplt,
	 char *dsk, ftnlen frname_len, ftnlen dsk_len)
{
    return t_wrdsk2__0_(2, bodyid, surfid, frname, (doublereal *)0, (
	    doublereal *)0, (doublereal *)0, (doublereal *)0, (doublereal *)0,
	     (integer *)0, (doublereal *)0, (doublereal *)0, (integer *)0, (
	    integer *)0, nv, np, usrvrt, usrplt, (logical *)0, (logical *)0, (
	    integer *)0, (integer *)0, (doublereal *)0, (doublereal *)0, (
	    doublereal *)0, (doublereal *)0, dsk, frname_len, dsk_len);
    }

/* Subroutine */ int t_eldsk2__(integer *bodyid, integer *surfid, char *
	frname, doublereal *first, doublereal *last, integer *corsys, 
	doublereal *corpar, doublereal *bounds, doublereal *a, doublereal *b, 
	doublereal *c__, integer *nlon, integer *nlat, logical *makvtl, char *
	dsk, ftnlen frname_len, ftnlen dsk_len)
{
    return t_wrdsk2__0_(3, bodyid, surfid, frname, first, last, a, b, c__, 
	    corsys, corpar, bounds, nlon, nlat, (integer *)0, (integer *)0, (
	    doublereal *)0, (integer *)0, makvtl, (logical *)0, (integer *)0, 
	    (integer *)0, (doublereal *)0, (doublereal *)0, (doublereal *)0, (
	    doublereal *)0, dsk, frname_len, dsk_len);
    }

/* Subroutine */ int t_elds2z__(integer *bodyid, integer *surfid, char *
	frname, integer *nlon, integer *nlat, char *dsk, ftnlen frname_len, 
	ftnlen dsk_len)
{
    return t_wrdsk2__0_(4, bodyid, surfid, frname, (doublereal *)0, (
	    doublereal *)0, (doublereal *)0, (doublereal *)0, (doublereal *)0,
	     (integer *)0, (doublereal *)0, (doublereal *)0, nlon, nlat, (
	    integer *)0, (integer *)0, (doublereal *)0, (integer *)0, (
	    logical *)0, (logical *)0, (integer *)0, (integer *)0, (
	    doublereal *)0, (doublereal *)0, (doublereal *)0, (doublereal *)0,
	     dsk, frname_len, dsk_len);
    }

/* Subroutine */ int t_smldsk__(integer *bodyid, integer *surfid, char *
	frname, char *dsk, ftnlen frname_len, ftnlen dsk_len)
{
    return t_wrdsk2__0_(5, bodyid, surfid, frname, (doublereal *)0, (
	    doublereal *)0, (doublereal *)0, (doublereal *)0, (doublereal *)0,
	     (integer *)0, (doublereal *)0, (doublereal *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (doublereal *)0, (
	    integer *)0, (logical *)0, (logical *)0, (integer *)0, (integer *)
	    0, (doublereal *)0, (doublereal *)0, (doublereal *)0, (doublereal 
	    *)0, dsk, frname_len, dsk_len);
    }

/* Subroutine */ int t_cg__(integer *bodyid, integer *surfid, char *frname, 
	char *dsk, ftnlen frname_len, ftnlen dsk_len)
{
    return t_wrdsk2__0_(6, bodyid, surfid, frname, (doublereal *)0, (
	    doublereal *)0, (doublereal *)0, (doublereal *)0, (doublereal *)0,
	     (integer *)0, (doublereal *)0, (doublereal *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (doublereal *)0, (
	    integer *)0, (logical *)0, (logical *)0, (integer *)0, (integer *)
	    0, (doublereal *)0, (doublereal *)0, (doublereal *)0, (doublereal 
	    *)0, dsk, frname_len, dsk_len);
    }

/* Subroutine */ int t_secds2__(integer *bodyid, integer *surfid, char *
	frname, doublereal *first, doublereal *last, integer *corsys, 
	doublereal *corpar, doublereal *bounds, doublereal *a, doublereal *b, 
	doublereal *c__, integer *nlon, integer *nlat, logical *makvtl, 
	logical *usepad, char *dsk, ftnlen frname_len, ftnlen dsk_len)
{
    return t_wrdsk2__0_(7, bodyid, surfid, frname, first, last, a, b, c__, 
	    corsys, corpar, bounds, nlon, nlat, (integer *)0, (integer *)0, (
	    doublereal *)0, (integer *)0, makvtl, usepad, (integer *)0, (
	    integer *)0, (doublereal *)0, (doublereal *)0, (doublereal *)0, (
	    doublereal *)0, dsk, frname_len, dsk_len);
    }

/* Subroutine */ int t_torus__(integer *bodyid, integer *surfid, char *frname,
	 integer *npolyv, integer *ncross, doublereal *r__, doublereal *
	rcross, doublereal *center, doublereal *normal, char *dsk, ftnlen 
	frname_len, ftnlen dsk_len)
{
    return t_wrdsk2__0_(8, bodyid, surfid, frname, (doublereal *)0, (
	    doublereal *)0, (doublereal *)0, (doublereal *)0, (doublereal *)0,
	     (integer *)0, (doublereal *)0, (doublereal *)0, (integer *)0, (
	    integer *)0, (integer *)0, (integer *)0, (doublereal *)0, (
	    integer *)0, (logical *)0, (logical *)0, npolyv, ncross, r__, 
	    rcross, center, normal, dsk, frname_len, dsk_len);
    }

