/* t_topker.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;
static integer c__12 = 12;
static integer c__2 = 2;
static integer c__1 = 1;

/* $Procedure T_TOPKER ( Create topocentric FK and SPK ) */
/* Subroutine */ int t_topker__(char *fk, char *spk, char *target, char *
	trgref, integer *nsites, integer *sitids, char *sitnms, doublereal *
	sitpos, char *sitfnm, integer *sitfid, doublereal *first, doublereal *
	last, integer *axes, doublereal *angles, ftnlen fk_len, ftnlen 
	spk_len, ftnlen target_len, ftnlen trgref_len, ftnlen sitnms_len, 
	ftnlen sitfnm_len)
{
    /* System generated locals */
    address a__1[2];
    integer sitids_dim1, sitnms_dim1, sitpos_dim2, sitfnm_dim1, sitfid_dim1, 
	    axes_dim2, angles_dim2, i__1, i__2, i__3[2];
    icilist ici__1;
    cllist cl__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rnge(char *, integer, char *, integer);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , f_clos(cllist *);

    /* Local variables */
    doublereal step;
    integer unit;
    extern /* Subroutine */ int vequ_(doublereal *, doublereal *);
    integer i__, j;
    char bname[36];
    doublereal angle;
    char segid[40];
    extern /* Subroutine */ int chkin_(char *, ftnlen), ucase_(char *, char *,
	     ftnlen, ftnlen), errch_(char *, char *, ftnlen, ftnlen);
    logical found;
    extern /* Subroutine */ int repmi_(char *, char *, integer *, char *, 
	    ftnlen, ftnlen, ftnlen);
    char fstem[32];
    extern /* Subroutine */ int spkw08_(integer *, integer *, integer *, char 
	    *, doublereal *, doublereal *, char *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, ftnlen, ftnlen);
    extern integer rtrim_(char *, ftnlen);
    extern /* Subroutine */ int bods2c_(char *, integer *, logical *, ftnlen);
    extern logical failed_(void);
    char begdat[10];
    extern /* Subroutine */ int cleard_(integer *, doublereal *);
    integer degree, handle, trgcde;
    extern /* Subroutine */ int sigerr_(char *, ftnlen);
    char begtxt[10], angstr[25*3];
    integer nstate;
    doublereal states[12]	/* was [6][2] */;
    integer iostat;
    extern /* Subroutine */ int setmsg_(char *, ftnlen);
    char outlin[255];
    extern /* Subroutine */ int errint_(char *, integer *, ftnlen), chkout_(
	    char *, ftnlen), spkopn_(char *, char *, integer *, integer *, 
	    ftnlen, ftnlen);
    extern logical exists_(char *, ftnlen), return_(void);
    extern /* Subroutine */ int spkcls_(integer *), writln_(char *, integer *,
	     ftnlen), prefix_(char *, integer *, char *, ftnlen, ftnlen), 
	    suffix_(char *, integer *, char *, ftnlen, ftnlen), intstr_(
	    integer *, char *, ftnlen), ljucrs_(integer *, char *, char *, 
	    ftnlen, ftnlen), txtopn_(char *, integer *, ftnlen);
    extern doublereal dpr_(void);

/* $ Abstract */

/*     Create a topocentric frame kernel and SPK file for a set of */
/*     sites on a specified target body. */

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

/*     FRAME */
/*     KERNEL */
/*     SPK */
/*     TOPOCENTRIC */
/*     TEST */
/*     UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     FK         I   Name of frame kernel to create. */
/*     SPK        I   Name of SPK file to create. */
/*     TARGET     I   Name of target body. */
/*     TRGREF     I   Target body's dody-fixed frame. */
/*     NSITES     I   Number of sites. */
/*     SITIDS     I   Body ID codes of sites. */
/*     SITNMS     I   Names of sites. */
/*     SITPOS     I   Positions of sites relative to target. */
/*     SITFNM     I   Site frame names. */
/*     SITFID     I   Site frame ID codes. */
/*     FIRST      I   SPK coverage start time. */
/*     LAST       I   SPK coverage stop time. */
/*     AXES       I   Axis indices of Euler angles. */
/*     ANGLES     I   Euler angles giving frame orientations. */

/* $ Detailed_Input */

/*     FK         is the name of the frame kernel to create. The */
/*                file must not already exist. */

/*     SPK        is the name of the SPK file to create. The file */
/*                contains positions the sites relative to the target */
/*                body (see description of TARGET below). The file must */
/*                not already exist. */

/*     TARGET     is the name of the target body. The positions */
/*                of all sites are expressed relative to the */
/*                position of the target. */

/*     TRGREF     is the name of a body-centered, body-fixed */
/*                reference frame associated with the target. */

/*     NSITES     is the number of sites for which frames and */
/*                SPK segments are to be created. */

/*     SITIDS     is an array of body ID codes of the sites. */

/*     SITNMS     is an array of names of the sites. */

/*     SITPOS     is an array of position vectors of the sites. The */
/*                positions of all sites are expressed relative to the */
/*                position of the target, in the reference frame */
/*                designated by TRGREF. */

/*     SITFNM     is an array of names of reference frames associated */
/*                with the sites. */

/*     SITFID     is an array of frame IDs for the frames associated */
/*                with the sites. */

/*     FIRST      is the coverage start time of the site position */
/*                SPK file. */

/*     LAST       is the coverage end time of the site position */
/*                SPK file. */


/*     AXES       is an array of sequences of axes of Euler rotations. */
/*                Elements */

/*                    AXES(J,I),  J = 1, 3 */

/*                are the indices for the Ith site reference frame. */
/*                See the discussion of ANGLES below. */

/*     ANGLES     is an array of sequences of angles of Euler rotations. */
/*                Elements */

/*                    ANGLES(J,I),  J = 1, 3 */

/*                are the angles for the Ith site reference frame. */

/*                If M is the matrix that converts vectors relative to a */
/*                site frame to the target frame by left multiplication, */
/*                then the angles and axes must satisfy the following */
/*                relationship: */

/*                   M = [angle_1]      [angle_2]      [angle_3] */
/*                                axis_1         axis_2         axis_3 */

/* $ Detailed_Output */

/*     None. This routine creates two files. See Files below. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the site count is non-positive, the error */
/*         SPICE(INVALIDCOUNT) is signaled. */

/*     2)  If the target body name cannot be converted to */
/*         an ID code, the error SPICE(IDCODENOTFOUND) */
/*         is signaled. */

/*     3)  If the file named by FK already exists, the error */
/*         SPICE(FILEEXISTS) is signaled. */

/*     4)  If an error occurs while writing the SPK file, the */
/*         error will be diagnosed by a routine in the call */
/*         tree of this routine. */

/*     5)  If an internal write performed by this routine fails, */
/*         the error SPICE(WRITEFAILED) will be signaled. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     The site reference frames are typically topocentric, but they */
/*     are not required to be (this is why the caller supplies the */
/*     site frame orientation). */

/*     To create a frame in the style of NAIF DSN topocentric frames, */
/*     where the planetodetic longitude and latitude of the site */
/*     are LON and LAT respectively, use the rotation sequence */

/*           [angle_1]      [angle_2]      [angle_3] */
/*                    axis_1         axis_2         axis_3 */

/*        = */

/*           [ -LON ]  [ LAT - pi/2 ]  [ pi ] */
/*                   3               2       3 */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman     (JPL) */

/* $ Version */

/* -    Test utilities version 1.0.0, 16-JUN-2016 (NJB) */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     Saved variables */

    /* Parameter adjustments */
    angles_dim2 = *nsites;
    axes_dim2 = *nsites;
    sitfid_dim1 = *nsites;
    sitfnm_dim1 = *nsites;
    sitpos_dim2 = *nsites;
    sitnms_dim1 = *nsites;
    sitids_dim1 = *nsites;

    /* Function Body */
    if (return_()) {
	return 0;
    }
    chkin_("T_TOPKER", (ftnlen)8);
    if (*nsites < 1) {
	setmsg_("Site count must be positive but was #.", (ftnlen)38);
	errint_("#", nsites, (ftnlen)1);
	sigerr_("SPICE(INVALIDCOUNT)", (ftnlen)19);
	chkout_("T_TOPKER", (ftnlen)8);
	return 0;
    }

/*     Get the body ID for the target. */

    bods2c_(target, &trgcde, &found, target_len);
    if (! found) {
	setmsg_("Could not translate body name #.", (ftnlen)32);
	errch_("#", target, (ftnlen)1, target_len);
	sigerr_("SPICE(IDCODENOTFOUND)", (ftnlen)21);
	chkout_("T_TOPKER", (ftnlen)8);
	return 0;
    }

/*     Create an SPK file containing data for the input sites. */

    spkopn_(spk, spk, &c__0, &handle, spk_len, spk_len);
    if (failed_()) {
	chkout_("T_TOPKER", (ftnlen)8);
	return 0;
    }
    cleard_(&c__12, states);
    s_copy(segid, " ", (ftnlen)40, (ftnlen)1);
    nstate = 2;
    degree = 1;
    step = *last - *first;
    i__1 = *nsites;
    for (i__ = 1; i__ <= i__1; ++i__) {
	s_copy(segid, "Body #", (ftnlen)40, (ftnlen)6);
	repmi_(segid, "#", &i__, segid, (ftnlen)40, (ftnlen)1, (ftnlen)40);
	vequ_(&sitpos[(i__2 = i__ * 3 - 3) < sitpos_dim2 * 3 && 0 <= i__2 ? 
		i__2 : s_rnge("sitpos", i__2, "t_topker__", (ftnlen)370)], 
		states);
	vequ_(&sitpos[(i__2 = i__ * 3 - 3) < sitpos_dim2 * 3 && 0 <= i__2 ? 
		i__2 : s_rnge("sitpos", i__2, "t_topker__", (ftnlen)371)], &
		states[6]);
	spkw08_(&handle, &sitids[(i__2 = i__ - 1) < sitids_dim1 && 0 <= i__2 ?
		 i__2 : s_rnge("sitids", i__2, "t_topker__", (ftnlen)373)], &
		trgcde, trgref, first, last, segid, &degree, &nstate, states, 
		first, &step, trgref_len, (ftnlen)40);
	if (failed_()) {
	    chkout_("T_TOPKER", (ftnlen)8);
	    return 0;
	}
    }
    spkcls_(&handle);
    if (failed_()) {
	chkout_("T_TOPKER", (ftnlen)8);
	return 0;
    }

/*     Create frame kernel. */

    if (exists_(fk, fk_len)) {
	setmsg_("Frame kernel # already exists; this program wont't overwrit"
		"e it.", (ftnlen)64);
	errch_("#", fk, (ftnlen)1, fk_len);
	sigerr_("SPICE(FILEEXISTS)", (ftnlen)17);
	chkout_("T_TOPKER", (ftnlen)8);
	return 0;
    }

/*     Open output file. */

    txtopn_(fk, &unit, fk_len);

/*     Write ID word. */

    writln_("KPL/FK", &unit, (ftnlen)6);
    writln_(" ", &unit, (ftnlen)1);
/* Writing concatenation */
    i__3[0] = 9, a__1[0] = "   FILE: ";
    i__3[1] = rtrim_(fk, fk_len), a__1[1] = fk;
    s_cat(outlin, a__1, i__3, &c__2, (ftnlen)255);
    writln_(outlin, &unit, (ftnlen)255);
    writln_(" ", &unit, (ftnlen)1);
    s_copy(outlin, "   This file was created by T_TOPKER.", (ftnlen)255, (
	    ftnlen)37);
    writln_(outlin, &unit, (ftnlen)255);
    writln_(" ", &unit, (ftnlen)1);

/*     Initialize data and text markers. */

    s_copy(begdat, "\\begindata", (ftnlen)10, (ftnlen)10);
    s_copy(begtxt, "\\begintext", (ftnlen)10, (ftnlen)10);

/*     Create a body-name mapping for each central body, in case the */
/*     mapping is not already known to SPICE. */

    writln_(" ", &unit, (ftnlen)1);
    s_copy(outlin, "   Body-name mapping follows:", (ftnlen)255, (ftnlen)29);
    writln_(outlin, &unit, (ftnlen)255);

/*     Start data area. */

    writln_(" ", &unit, (ftnlen)1);
    writln_(begdat, &unit, (ftnlen)10);
    i__1 = *nsites;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ucase_(sitnms + ((i__2 = i__ - 1) < sitnms_dim1 && 0 <= i__2 ? i__2 : 
		s_rnge("sitnms", i__2, "t_topker__", (ftnlen)454)) * 
		sitnms_len, bname, sitnms_len, (ftnlen)36);
	prefix_("'", &c__0, bname, (ftnlen)1, (ftnlen)36);
	suffix_("'", &c__0, bname, (ftnlen)1, (ftnlen)36);
	writln_(" ", &unit, (ftnlen)1);
	s_copy(outlin, " ", (ftnlen)255, (ftnlen)1);
	s_copy(outlin + 3, "NAIF_BODY_NAME", (ftnlen)252, (ftnlen)14);
	s_copy(outlin + 39, "+=", (ftnlen)216, (ftnlen)2);
	s_copy(outlin + 42, bname, (ftnlen)213, (ftnlen)36);
	writln_(outlin, &unit, (ftnlen)255);
	s_copy(outlin, " ", (ftnlen)255, (ftnlen)1);
	s_copy(outlin + 3, "NAIF_BODY_CODE", (ftnlen)252, (ftnlen)14);
	s_copy(outlin + 39, "+=", (ftnlen)216, (ftnlen)2);
	intstr_(&sitids[(i__2 = i__ - 1) < sitids_dim1 && 0 <= i__2 ? i__2 : 
		s_rnge("sitids", i__2, "t_topker__", (ftnlen)472)], outlin + 
		42, (ftnlen)213);
	writln_(outlin, &unit, (ftnlen)255);
    }

/*     End data area. */

    writln_(" ", &unit, (ftnlen)1);
    writln_(begtxt, &unit, (ftnlen)10);
    writln_(" ", &unit, (ftnlen)1);

/*     Introduce the frame definitions. */

    writln_(" ", &unit, (ftnlen)1);
    s_copy(outlin, "   Reference frame specifications follow:", (ftnlen)255, (
	    ftnlen)41);
    writln_(outlin, &unit, (ftnlen)255);
    writln_(" ", &unit, (ftnlen)1);
    writln_(" ", &unit, (ftnlen)1);

/*     Start data area. */

    writln_(" ", &unit, (ftnlen)1);
    writln_(begdat, &unit, (ftnlen)10);
    writln_(" ", &unit, (ftnlen)1);
    i__1 = *nsites;
    for (i__ = 1; i__ <= i__1; ++i__) {

/*        Create the frame ID assignment. */

	s_copy(outlin, " ", (ftnlen)255, (ftnlen)1);
	ljucrs_(&c__0, sitfnm + ((i__2 = i__ - 1) < sitfnm_dim1 && 0 <= i__2 ?
		 i__2 : s_rnge("sitfnm", i__2, "t_topker__", (ftnlen)510)) * 
		sitfnm_len, outlin + 3, sitfnm_len, (ftnlen)252);
	prefix_("FRAME_", &c__0, outlin + 3, (ftnlen)6, (ftnlen)252);
	s_copy(outlin + 39, "=", (ftnlen)216, (ftnlen)1);
	intstr_(&sitfid[(i__2 = i__ - 1) < sitfid_dim1 && 0 <= i__2 ? i__2 : 
		s_rnge("sitfid", i__2, "t_topker__", (ftnlen)516)], outlin + 
		42, (ftnlen)213);
	writln_(outlin, &unit, (ftnlen)255);

/*        Create the frame name assignment. */

	s_copy(outlin, " ", (ftnlen)255, (ftnlen)1);
	intstr_(&sitfid[(i__2 = i__ - 1) < sitfid_dim1 && 0 <= i__2 ? i__2 : 
		s_rnge("sitfid", i__2, "t_topker__", (ftnlen)525)], fstem, (
		ftnlen)32);
	prefix_("FRAME_", &c__0, fstem, (ftnlen)6, (ftnlen)32);
	s_copy(outlin + 3, fstem, (ftnlen)252, (ftnlen)32);
	suffix_("_NAME", &c__0, outlin + 3, (ftnlen)5, (ftnlen)252);
	s_copy(outlin + 39, "=", (ftnlen)216, (ftnlen)1);
	ljucrs_(&c__0, sitfnm + ((i__2 = i__ - 1) < sitfnm_dim1 && 0 <= i__2 ?
		 i__2 : s_rnge("sitfnm", i__2, "t_topker__", (ftnlen)533)) * 
		sitfnm_len, outlin + 42, sitfnm_len, (ftnlen)213);
	prefix_("'", &c__0, outlin + 42, (ftnlen)1, (ftnlen)213);
	suffix_("'", &c__0, outlin + 42, (ftnlen)1, (ftnlen)213);
	writln_(outlin, &unit, (ftnlen)255);

/*        Create the frame class and class ID assignments. */

	s_copy(outlin, " ", (ftnlen)255, (ftnlen)1);
	s_copy(outlin + 3, fstem, (ftnlen)252, (ftnlen)32);
	suffix_("_CLASS", &c__0, outlin + 3, (ftnlen)6, (ftnlen)252);
	s_copy(outlin + 39, "=  4", (ftnlen)216, (ftnlen)4);
	writln_(outlin, &unit, (ftnlen)255);
	s_copy(outlin, " ", (ftnlen)255, (ftnlen)1);
	s_copy(outlin + 3, fstem, (ftnlen)252, (ftnlen)32);
	suffix_("_CLASS_ID", &c__0, outlin + 3, (ftnlen)9, (ftnlen)252);
	s_copy(outlin + 39, "=", (ftnlen)216, (ftnlen)1);
	intstr_(&sitfid[(i__2 = i__ - 1) < sitfid_dim1 && 0 <= i__2 ? i__2 : 
		s_rnge("sitfid", i__2, "t_topker__", (ftnlen)558)], outlin + 
		42, (ftnlen)213);
	writln_(outlin, &unit, (ftnlen)255);

/*        Create the center assignment. */

	s_copy(outlin, " ", (ftnlen)255, (ftnlen)1);
	s_copy(outlin + 3, fstem, (ftnlen)252, (ftnlen)32);
	suffix_("_CENTER", &c__0, outlin + 3, (ftnlen)7, (ftnlen)252);
	s_copy(outlin + 39, "=", (ftnlen)216, (ftnlen)1);
	intstr_(&sitids[(i__2 = i__ - 1) < sitids_dim1 && 0 <= i__2 ? i__2 : 
		s_rnge("sitids", i__2, "t_topker__", (ftnlen)571)], outlin + 
		42, (ftnlen)213);
	writln_(outlin, &unit, (ftnlen)255);

/*        Create the object-frame association assignment. */

	s_copy(outlin, " ", (ftnlen)255, (ftnlen)1);
	intstr_(&sitids[(i__2 = i__ - 1) < sitids_dim1 && 0 <= i__2 ? i__2 : 
		s_rnge("sitids", i__2, "t_topker__", (ftnlen)580)], outlin + 
		3, (ftnlen)252);
	prefix_("OBJECT_", &c__0, outlin + 3, (ftnlen)7, (ftnlen)252);
	suffix_("_FRAME", &c__0, outlin + 3, (ftnlen)6, (ftnlen)252);
	s_copy(outlin + 39, "=", (ftnlen)216, (ftnlen)1);
	ljucrs_(&c__0, sitfnm + ((i__2 = i__ - 1) < sitfnm_dim1 && 0 <= i__2 ?
		 i__2 : s_rnge("sitfnm", i__2, "t_topker__", (ftnlen)586)) * 
		sitfnm_len, outlin + 42, sitfnm_len, (ftnlen)213);
	prefix_("'", &c__0, outlin + 42, (ftnlen)1, (ftnlen)213);
	suffix_("'", &c__0, outlin + 42, (ftnlen)1, (ftnlen)213);
	writln_(" ", &unit, (ftnlen)1);
	writln_(outlin, &unit, (ftnlen)255);
	writln_(" ", &unit, (ftnlen)1);

/*        Create the relative frame assignment. */

	prefix_("TK", &c__0, fstem, (ftnlen)2, (ftnlen)32);
	s_copy(outlin, " ", (ftnlen)255, (ftnlen)1);
	s_copy(outlin + 3, fstem, (ftnlen)252, (ftnlen)32);
	suffix_("_RELATIVE", &c__0, outlin + 3, (ftnlen)9, (ftnlen)252);
	s_copy(outlin + 39, "=", (ftnlen)216, (ftnlen)1);
	s_copy(outlin + 42, trgref, (ftnlen)213, trgref_len);
	prefix_("'", &c__0, outlin + 42, (ftnlen)1, (ftnlen)213);
	suffix_("'", &c__0, outlin + 42, (ftnlen)1, (ftnlen)213);
	writln_(outlin, &unit, (ftnlen)255);

/*        Create the frame and units assignments. */

	s_copy(outlin, " ", (ftnlen)255, (ftnlen)1);
	s_copy(outlin + 3, fstem, (ftnlen)252, (ftnlen)32);
	suffix_("_SPEC", &c__0, outlin + 3, (ftnlen)5, (ftnlen)252);
	s_copy(outlin + 39, "=  'ANGLES'", (ftnlen)216, (ftnlen)11);
	writln_(outlin, &unit, (ftnlen)255);
	s_copy(outlin, " ", (ftnlen)255, (ftnlen)1);
	s_copy(outlin + 3, fstem, (ftnlen)252, (ftnlen)32);
	suffix_("_UNITS", &c__0, outlin + 3, (ftnlen)6, (ftnlen)252);
	s_copy(outlin + 39, "=  'DEGREES'", (ftnlen)216, (ftnlen)12);
	writln_(outlin, &unit, (ftnlen)255);

/*        Create the axis sequence assignment. */

	s_copy(outlin, " ", (ftnlen)255, (ftnlen)1);
	s_copy(outlin + 3, fstem, (ftnlen)252, (ftnlen)32);
	suffix_("_AXES", &c__0, outlin + 3, (ftnlen)5, (ftnlen)252);
	s_copy(outlin + 39, "=", (ftnlen)216, (ftnlen)1);
	s_copy(outlin + 42, "( #, #, # )", (ftnlen)213, (ftnlen)11);
	for (j = 1; j <= 3; ++j) {
	    repmi_(outlin + 42, "#", &axes[(i__2 = j + i__ * 3 - 4) < 
		    axes_dim2 * 3 && 0 <= i__2 ? i__2 : s_rnge("axes", i__2, 
		    "t_topker__", (ftnlen)652)], outlin + 42, (ftnlen)213, (
		    ftnlen)1, (ftnlen)213);
	}
	writln_(outlin, &unit, (ftnlen)255);

/*        Create the angle sequence assignments. */


/*        First convert the angles to strings. Scale to degrees */
/*        in the process. */

	for (j = 1; j <= 3; ++j) {
	    angle = angles[(i__2 = j + i__ * 3 - 4) < angles_dim2 * 3 && 0 <= 
		    i__2 ? i__2 : s_rnge("angles", i__2, "t_topker__", (
		    ftnlen)669)] * dpr_();
	    ici__1.icierr = 1;
	    ici__1.icirnum = 1;
	    ici__1.icirlen = 25;
	    ici__1.iciunit = angstr + ((i__2 = j - 1) < 3 && 0 <= i__2 ? i__2 
		    : s_rnge("angstr", i__2, "t_topker__", (ftnlen)671)) * 25;
	    ici__1.icifmt = "(F18.13)";
	    iostat = s_wsfi(&ici__1);
	    if (iostat != 0) {
		goto L100001;
	    }
	    iostat = do_fio(&c__1, (char *)&angle, (ftnlen)sizeof(doublereal))
		    ;
	    if (iostat != 0) {
		goto L100001;
	    }
	    iostat = e_wsfi();
L100001:
	    if (iostat != 0) {
		setmsg_("Attempt to write angle # for frame # failed; IOSTAT"
			" was #.", (ftnlen)58);
		errint_("#", &j, (ftnlen)1);
		errch_("#", sitfnm + ((i__2 = i__ - 1) < sitfnm_dim1 && 0 <= 
			i__2 ? i__2 : s_rnge("sitfnm", i__2, "t_topker__", (
			ftnlen)678)) * sitfnm_len, (ftnlen)1, sitfnm_len);
		errint_("#", &iostat, (ftnlen)1);
		sigerr_("SPICE(WRITEFAILED)", (ftnlen)18);
		chkout_("T_TOPKER", (ftnlen)8);
		return 0;
	    }
	}

/*        First angle: */

	s_copy(outlin, " ", (ftnlen)255, (ftnlen)1);
	s_copy(outlin + 3, fstem, (ftnlen)252, (ftnlen)32);
	suffix_("_ANGLES", &c__0, outlin + 3, (ftnlen)7, (ftnlen)252);
	s_copy(outlin + 39, "=  (", (ftnlen)216, (ftnlen)4);
	s_copy(outlin + 44, angstr, (ftnlen)211, (ftnlen)25);
	suffix_(",", &c__0, outlin + 44, (ftnlen)1, (ftnlen)211);
	writln_(outlin, &unit, (ftnlen)255);

/*        Second angle: */

	s_copy(outlin, " ", (ftnlen)255, (ftnlen)1);
	s_copy(outlin + 44, angstr + 25, (ftnlen)211, (ftnlen)25);
	suffix_(",", &c__0, outlin + 44, (ftnlen)1, (ftnlen)211);
	writln_(outlin, &unit, (ftnlen)255);

/*        Third angle: */

	s_copy(outlin, " ", (ftnlen)255, (ftnlen)1);
	s_copy(outlin + 44, angstr + 50, (ftnlen)211, (ftnlen)25);
	suffix_(")", &c__1, outlin + 44, (ftnlen)1, (ftnlen)211);
	writln_(outlin, &unit, (ftnlen)255);

/*        Add a little vertical white space between frame */
/*        specifications. */

	writln_(" ", &unit, (ftnlen)1);
    }

/*     End data area. */

    writln_(begtxt, &unit, (ftnlen)10);
    writln_(" ", &unit, (ftnlen)1);
    writln_(" ", &unit, (ftnlen)1);
    writln_("[End of definitions file]", &unit, (ftnlen)25);
    writln_(" ", &unit, (ftnlen)1);

/*     Close output file. */

    cl__1.cerr = 0;
    cl__1.cunit = unit;
    cl__1.csta = 0;
    f_clos(&cl__1);
    chkout_("T_TOPKER", (ftnlen)8);
    return 0;
} /* t_topker__ */

