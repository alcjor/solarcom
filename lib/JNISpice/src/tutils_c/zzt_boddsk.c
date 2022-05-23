/* zzt_boddsk.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1000 = 1000;
static integer c__500 = 500;

/* $Procedure ZZT_BODDSK (Make type 2 DSK for body's reference ellipsoid) */
/* Subroutine */ int zzt_boddsk__(char *dsk, char *body, char *fixref, 
	logical *load, integer *handle, ftnlen dsk_len, ftnlen body_len, 
	ftnlen fixref_len)
{
    extern /* Subroutine */ int t_elds2z__(integer *, integer *, char *, 
	    integer *, integer *, char *, ftnlen, ftnlen), chkin_(char *, 
	    ftnlen), errch_(char *, char *, ftnlen, ftnlen);
    logical found;
    extern /* Subroutine */ int bods2c_(char *, integer *, logical *, ftnlen);
    integer bodcde;
    extern logical failed_(void);
    integer frcode, frclid;
    extern /* Subroutine */ int namfrm_(char *, integer *, ftnlen);
    integer frcent;
    extern /* Subroutine */ int frinfo_(integer *, integer *, integer *, 
	    integer *, logical *), dasopr_(char *, integer *, ftnlen), 
	    sigerr_(char *, ftnlen);
    integer frclss, surfid;
    extern /* Subroutine */ int chkout_(char *, ftnlen), setmsg_(char *, 
	    ftnlen), errint_(char *, integer *, ftnlen);
    extern logical return_(void);

/* $ Abstract */

/*     Create a DSK containing a tessellation of the reference */
/*     ellipsoid of a specified body. */

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
/*     ELLIPSOID */
/*     PLATE */
/*     TILE */
/*     TESSELLATE */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     DSK        I   Name of DSK file to create. */
/*     BODY       I   Name of central body and of surface. */
/*     FIXREF     I   Name of body-fixed, body-centered reference frame. */
/*     LOAD       I   Flag indicating whether to load the DSK. */
/*     HANDLE     O   DAS handle of DSK if loaded. */

/* $ Detailed_Input */

/*     DSK        is the name of a new DSK file to create. */


/*     BODY       is the name of a body for which a DSK file is to be */
/*                created. The ID code associated with BODY is used as */
/*                both the surface and body ID code in the DSK file. */

/*                Case and leading and trailing blanks in the name are */
/*                not significant. */


/*     FIXREF     is the name of a body-fixed, body-centered reference */
/*                frame associated with BODY. */

/*                Case and leading and trailing blanks in the name are */
/*                not significant. */


/*     LOAD       is a logical flag that indicates whether to load the */
/*                DSK file for read access after the file has been */
/*                created. If LOAD is set to .TRUE., the file is loaded */
/*                for read access by DASOPR. */

/* $ Detailed_Output */

/*     HANDLE     is a DAS handle associated with the specified */
/*                DSK file, if the input flag LOAD is .TRUE. */

/*                HANDLE is undefined if the input LOAD is .FALSE. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1)  If the input body name cannot be mapped to an integer */
/*         ID code, the error SPICE(BODYIDNOTFOUND) will be signaled. */

/*     2)  If the input frame name cannot be mapped to an integer */
/*         ID code, the error SPICE(UNKNOWNFRAME) will be signaled. */

/*     3)  If the radii of the specified body are not available */
/*         in the kernel pool, the error will be diagnosed by */
/*         a routine in the call tree of this routine. */

/*     4)  If the reference frame designated by FIXREF is not */
/*         centered at BODY, the error SPICE(BADFRAMECENTER) */
/*         will be signaled. */

/*     5)  If the specified DSK file already exists, it will not be */
/*         overwritten. An error will be signaled by a routine in the */
/*         call tree of this routine. */

/*     6)  If an error is encountered while writing the DSK file, the */
/*         error will be signaled by a routine in the call tree of this */
/*         routine. */

/* $ Files */

/*     1)  This routine requires radii for BODY to be available */
/*         in the kernel pool. Normally these radii are made */
/*         available by loading a PCK containing them. */

/*     2)  This routine creates a type 2 segment containing a */
/*         tessellation of the reference ellipsoid of a specified */
/*         body. The segment contains */

/*            1000   longitude bands */
/*             500   latitude bands */

/*         which yields */

/*            499002 vertices */
/*            998000 plates */

/*         The body and surface IDs of the segment are both the NAIF ID */
/*         corresponding to BODY. */

/*         The coordinate system of the segment is planetocentric. */
/*         The longitude range is */

/*           -180 : 180 degrees */

/*         The latitude range is */

/*            -90 :  90 degrees */

/*         Time coverage of the segment is J2000 TDB +/- 100 Julian */
/*         years. */

/*         The data class of the segment is 1 (spherically */
/*         parameterized surface). */

/*         The size of the file is roughly 50 Mb. The size will */
/*         depend on voxel sizes and voxel grid dimensions, which */
/*         vary with the body's shape and size. */

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

/* -    TESTUTIL Version 1.0.0, 27-JUL-2016 (NJB) */

/*        Re-implemented. Now uses T_WRDSK2 entry poin T_ELDS2Z. */

/*     30-APR-2014 (NJB) */

/*        Original version. */

/* -& */
/* $ Index_Entries */

/*     tessellate reference ellipsoid of body */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */

    if (return_()) {
	return 0;
    }
    chkin_("ZZT_BODDSK", (ftnlen)10);

/*     Get body ID code. */

    bods2c_(body, &bodcde, &found, body_len);
    if (! found) {
	setmsg_("The body name # could not be mapped to an ID code.", (ftnlen)
		50);
	errch_("#", body, (ftnlen)1, body_len);
	sigerr_("SPICE(BODYIDNOTFOUND)", (ftnlen)21);
	chkout_("ZZT_BODDSK", (ftnlen)10);
	return 0;
    }

/*     Map frame name to code. */

    namfrm_(fixref, &frcode, fixref_len);
    if (frcode == 0) {
	setmsg_("The frame name # could not be mapped to an ID code.", (
		ftnlen)51);
	errch_("#", fixref, (ftnlen)1, fixref_len);
	sigerr_("SPICE(UNKNOWNFRAME)", (ftnlen)19);
	chkout_("ZZT_BODDSK", (ftnlen)10);
	return 0;
    }

/*     Get frame info and check frame center. */

    frinfo_(&frcode, &frcent, &frclss, &frclid, &found);
    if (failed_()) {
	chkout_("ZZT_BODDSK", (ftnlen)10);
	return 0;
    }
    if (! found) {

/*        We really don't expect to get here, but.... */

	setmsg_("The frame name # could not be mapped to an ID code.", (
		ftnlen)51);
	errch_("#", fixref, (ftnlen)1, fixref_len);
	sigerr_("SPICE(UNKNOWNFRAME)", (ftnlen)19);
	chkout_("ZZT_BODDSK", (ftnlen)10);
	return 0;
    }
    if (frcent != bodcde) {
	setmsg_("The frame # is centered at #; the center must coincide with"
		" the body # which has ID #.", (ftnlen)86);
	errch_("#", fixref, (ftnlen)1, fixref_len);
	errint_("#", &frcent, (ftnlen)1);
	errch_("#", body, (ftnlen)1, body_len);
	errint_("#", &bodcde, (ftnlen)1);
	sigerr_("SPICE(BADFRAMECENTER)", (ftnlen)21);
	chkout_("ZZT_BODDSK", (ftnlen)10);
	return 0;
    }

/*     Create DSK file. */

/*     Some of the *PL02 routines require the surface ID to */
/*     match the body ID. */

    surfid = bodcde;
    t_elds2z__(&bodcde, &surfid, fixref, &c__1000, &c__500, dsk, fixref_len, 
	    dsk_len);
    if (failed_()) {
	chkout_("ZZT_BODDSK", (ftnlen)10);
	return 0;
    }

/*     Open the file for read access if so directed. */

    if (*load) {
	dasopr_(dsk, handle, dsk_len);
    } else {

/*        Ensure that the stale handle can't be used. */

	*handle = 0;
    }
    chkout_("ZZT_BODDSK", (ftnlen)10);
    return 0;
} /* zzt_boddsk__ */

