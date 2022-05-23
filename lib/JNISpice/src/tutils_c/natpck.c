/* natpck.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* $Procedure   NATPCK (Create a text PCK for Nat's solar system) */
/* Subroutine */ int natpck_(char *namepc, logical *loadpc, logical *keeppc, 
	ftnlen namepc_len)
{
    /* System generated locals */
    integer i__1;
    char ch__1[16];
    cllist cl__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rnge(char *, integer, char *, integer), f_clos(cllist *);

    /* Local variables */
    integer unit, i__;
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    extern /* Character */ VOID begdat_(char *, ftnlen);
    extern /* Subroutine */ int kilfil_(char *, ftnlen), tfiles_(char *, 
	    ftnlen), ldpool_(char *, ftnlen);
    extern /* Character */ VOID begtxt_(char *, ftnlen);
    extern /* Subroutine */ int chkout_(char *, ftnlen), writln_(char *, 
	    integer *, ftnlen), txtopn_(char *, integer *, ftnlen);
    char pck[80*393];

/* $ Abstract */

/*     Create and if appropriate load a text PCK kernel for Nat's */
/*     solar system. */

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
/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     NAMEPC     I   The name of the PC-kernel to create. */
/*     LOADPC     I   Load the PC-kernel if .TRUE. */
/*     KEEPPC     I   Keep the PC-kernel if .TRUE., else delete it. */

/* $ Detailed_Input */

/*     NAMEPC      is the name of a PCK to create and load if LOADPC is */
/*                 set to .TRUE.  If a PCK of the same name already */
/*                 exists it is deleted. */

/*     LOADPC      is a logical that indicates whether or not the PCK */
/*                 file should be loaded after it is created.  If LOADPC */
/*                 has the value .TRUE. the PCK is loaded after it is */
/*                 created.  Otherwise it is left un-opened. */

/*     KEEPPC      is a logical that indicates whether or not the PCK */
/*                 file should be deleted after it is loaded.  If KEEPPC */
/*                 is .TRUE. the file is not deleted.  If KEEPPC is */
/*                 .FALSE. the file is deleted after it is loaded. */

/*                 Note this behavior is different from that of TSTPCK, */
/*                 which always keeps the file if the file is not loaded, */
/*                 regardless of the value of KEEPPC. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any I/O errors occurring in the creation of the PCK file */
/*        will be signaled by routines in the call tree of this */
/*        routine. */

/*     Since this routine is normally used within the TSPICE system, */
/*     it's up the the caller to call CHCKXC to catch errors signaled by */
/*     this routine. */

/* $ Files */

/*     This routine creates a PCK file meant for use with the SPK */
/*     file created by the test utility NATSPK.  If that routine */
/*     is changed, the body radii defined here may need to be */
/*     changed as well.  NATSPK contains commented-out lines of code */
/*     that generate appropriate body radii. */

/*     The PCK created by this routine contains */

/*        - Name-ID mappings for bodies ALPHA and BETA */

/*        - Body radii for bodies ALPHA and BETA */

/*        - Rotational elements for bodies ALPHA and BETA */

/*        - PCK frame definitions for the body-fixed frames */

/*             ALPHAFIXED */
/*             BETAFIXED */

/*        - Associations of the bodyfixed frames with the */
/*          bodies ALPHA and BETA */

/*        - GM and radii for the "sun" of this solar system.  The */
/*          GM value is computed by NATSPK; normally the lines of */
/*          code that write out the value are commented out. */

/*          The smaller radii of the sun are provided because the */
/*          original values make the sun too large relative to the */
/*          orbital radii of the planets. */

/*        - View frames for bodies Alpha and Beta. These frames */
/*          have a primary axis that points toward the center */
/*          of the defining object; the secondary vector points */
/*          in the velocity direction. */

/*          There are two kinds of view frames for Alpha: those */
/*          with Alpha's orbit in the frame's X-Y plane and those */
/*          with Alpha's orbit in the frame's X-Z plane. The first */
/*          group has variants that use different aberration corrections */
/*          for the defining position and velocity vectors. All */
/*          light time corrections are converged Newtonian. */

/*          For Beta, the only frames are based on geometric vectors. */

/*          The view frames' names are: */

/*             'ALPHA_VIEW_XY' */
/*             'ALPHA_VIEW_XY_CN' */
/*             'ALPHA_VIEW_XY_CNS' */
/*             'ALPHA_VIEW_XY_XCN' */
/*             'ALPHA_VIEW_XY_XCNS' */
/*             'ALPHA_VIEW_XZ' */
/*             'ALPHA_VIEW_XZ_CN' */
/*             'ALPHA_VIEW_XZ_CNS' */
/*             'ALPHA_VIEW_XZ_XCN' */
/*             'ALPHA_VIEW_XZ_XCNS' */
/*             'BETA_VIEW_XY' */
/*             'BETA_VIEW_XZ' */


/* $ Particulars */

/*     This routine creates a planetary constants file for use in */
/*     testing. */

/* $ Examples */

/*     The normal way to use this routine is shown below. */

/*     CALL NATSPK ( 'nat.bsp', .TRUE., HANDLE  ) */
/*     CALL NATPCK ( 'nat.tpc', .TRUE., .FALSE. ) */

/*        [perform some tests and computations] */

/*     CALL SPKUEF ( HANDLE ) */
/*     CALL KILFIL ( 'nat.bsp' ) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    Test Utilities 4.0.0, 17-JUL-2008 (NJB) */

/*        Dynamic view frames for Alpha and Beta were added. */

/* -    Test Utilities 3.0.0, 14-APR-2008 (NJB) */

/*        Kernel loading is now performed using LDPOOL. */
/*        Header was updated to satisfy checkit. */

/* -    Test Utilities 2.0.0, 11-NOV-2007 (NJB) */

/*        Changed polar radii of bodies Alpha and Beta to */
/*        make shape of Alpha prolate and shape of Beta */
/*        oblate. Changed body-fixed frame of alpha so that */
/*        axes are permuted relative to those of Beta. */

/*        If the PCK is loaded, it is now loaded via FURNSH. */

/* -    Test Utilities 1.0.0, 29-SEP-2004 (NJB) */

/* -& */
/* $ Index_Entries */

/*     Create a "Nat's solar system" PCK file */

/* -& */

/*     Test Utility Functions */


/*     Local Parameters */


/*     Local Variables */

    chkin_("NATPCK", (ftnlen)6);

/*     Delete any existing file of the same name. */

    kilfil_(namepc, namepc_len);

/*     Fill the PCK buffer with the PCK kernel variable assignments. */

    begdat_(ch__1, (ftnlen)16);
    s_copy(pck, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(pck + 80, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 160, "      NAIF_BODY_NAME += ( 'ALPHA', 'BETA',  'GAMMA' )",
	     (ftnlen)80, (ftnlen)53);
    s_copy(pck + 240, "      NAIF_BODY_CODE += ( 1000,     2000,   1001    )",
	     (ftnlen)80, (ftnlen)53);
    s_copy(pck + 320, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)16);
    s_copy(pck + 400, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(pck + 480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 560, "   Radii for", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 720, "      ALPHA", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 800, "      BETA", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 880, "      GAMMA", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 960, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)16);
    s_copy(pck + 1040, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(pck + 1120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 1200, "      BODY1000_RADII = ( 0.73249397533875424E+05,", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 1280, "                         0.36624698766937712E+05,", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 1360, "                         0.36624698766937712E+05 )", (
	    ftnlen)80, (ftnlen)50);
    s_copy(pck + 1440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 1520, "      BODY1001_RADII = ( 1.E4, 1.E4, 1.E4 )", (ftnlen)
	    80, (ftnlen)43);
    s_copy(pck + 1600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 1680, "      BODY2000_RADII = ( 0.22891526271046937E+04,", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 1760, "                         0.22891526271046937E+04,", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 1840, "                         0.1E+04 )", (ftnlen)80, (
	    ftnlen)34);
    s_copy(pck + 1920, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)16);
    s_copy(pck + 2000, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(pck + 2080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 2160, "   Orientation data for", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 2240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 2320, "      ALPHA", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 2400, "      BETA", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 2480, "      GAMMA", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 2560, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)16);
    s_copy(pck + 2640, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(pck + 2720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 2800, "      BODY1000_POLE_RA        = (    0.       0.    "
	    "     0. )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 2880, "      BODY1000_POLE_DEC       = (  +90.       0.    "
	    "     0. )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 2960, "      BODY1000_PM             = (    0.       0.    "
	    "     0. )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 3040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 3120, "      BODY1001_POLE_RA        = ( +180.       0.    "
	    "     0. )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 3200, "      BODY1001_POLE_DEC       = (    0.       0.    "
	    "     0. )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 3280, "      BODY1001_PM             = ( +180.       360.  "
	    "     0. )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 3360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 3440, "      BODY2000_POLE_RA        = (    0.       0.    "
	    "     0. )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 3520, "      BODY2000_POLE_DEC       = (  +90.       0.    "
	    "     0. )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 3600, "      BODY2000_PM             = (    0.       0.    "
	    "     0. )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 3680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 3760, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)16);
    s_copy(pck + 3840, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(pck + 3920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 4000, "   Body-fixed frame specifications for", (ftnlen)80, (
	    ftnlen)38);
    s_copy(pck + 4080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 4160, "      ALPHA", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 4240, "      BETA", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 4320, "      GAMMA", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 4400, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)16);
    s_copy(pck + 4480, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(pck + 4560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 4640, "      FRAME_ALPHAFIXED          =  1000001", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 4720, "      FRAME_1000001_NAME        = 'ALPHAFIXED'", (
	    ftnlen)80, (ftnlen)46);
    s_copy(pck + 4800, "      FRAME_1000001_CLASS       =  4", (ftnlen)80, (
	    ftnlen)36);
    s_copy(pck + 4880, "      FRAME_1000001_CLASS_ID    =  1000001", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 4960, "      FRAME_1000001_CENTER      =  1000", (ftnlen)80, 
	    (ftnlen)39);
    s_copy(pck + 5040, "      TKFRAME_1000001_RELATIVE  = 'BETAFIXED'", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 5120, "      TKFRAME_1000001_SPEC      = 'MATRIX'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 5200, "      TKFRAME_1000001_MATRIX    = ( 0, 0, 1,", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 5280, "                                    1, 0, 0,", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 5360, "                                    0, 1, 0 )", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 5440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 5520, "      OBJECT_1000_FRAME       = 'ALPHAFIXED'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 5600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 5680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 5760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 5840, "      FRAME_BETAFIXED         =  1000002", (ftnlen)80,
	     (ftnlen)40);
    s_copy(pck + 5920, "      FRAME_1000002_NAME      = 'BETAFIXED'", (ftnlen)
	    80, (ftnlen)43);
    s_copy(pck + 6000, "      FRAME_1000002_CLASS     =  2", (ftnlen)80, (
	    ftnlen)34);
    s_copy(pck + 6080, "      FRAME_1000002_CLASS_ID  =  2000", (ftnlen)80, (
	    ftnlen)37);
    s_copy(pck + 6160, "      FRAME_1000002_CENTER    =  2000", (ftnlen)80, (
	    ftnlen)37);
    s_copy(pck + 6240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 6320, "      OBJECT_2000_FRAME       = 'BETAFIXED'", (ftnlen)
	    80, (ftnlen)43);
    s_copy(pck + 6400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 6480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 6560, "      FRAME_GAMMAFIXED        =  1000003", (ftnlen)80,
	     (ftnlen)40);
    s_copy(pck + 6640, "      FRAME_1000003_NAME      = 'GAMMAFIXED'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 6720, "      FRAME_1000003_CLASS     =  2", (ftnlen)80, (
	    ftnlen)34);
    s_copy(pck + 6800, "      FRAME_1000003_CLASS_ID  =  1001", (ftnlen)80, (
	    ftnlen)37);
    s_copy(pck + 6880, "      FRAME_1000003_CENTER    =  1001", (ftnlen)80, (
	    ftnlen)37);
    s_copy(pck + 6960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 7040, "      OBJECT_1001_FRAME       = 'GAMMAFIXED'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 7120, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)16);
    s_copy(pck + 7200, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(pck + 7280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 7360, "      View frames for body ALPHA relative to the Sun",
	     (ftnlen)80, (ftnlen)52);
    s_copy(pck + 7440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 7520, "         ALPHA_VIEW_XY     orbital motion of ALPHA l"
	    "ies in X-Y plane", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 7600, "                           of this frame.", (ftnlen)
	    80, (ftnlen)41);
    s_copy(pck + 7680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 7760, "         ALPHA_VIEW_XZ     orbital motion of ALPHA l"
	    "ies in X-Z plane", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 7840, "                           of this frame.", (ftnlen)
	    80, (ftnlen)41);
    s_copy(pck + 7920, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)16);
    s_copy(pck + 8000, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(pck + 8080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 8160, "      FRAME_ALPHA_VIEW_XY         =  1700000", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 8240, "      FRAME_1700000_NAME           = 'ALPHA_VIEW_XY'",
	     (ftnlen)80, (ftnlen)52);
    s_copy(pck + 8320, "      FRAME_1700000_CLASS          =  5", (ftnlen)80, 
	    (ftnlen)39);
    s_copy(pck + 8400, "      FRAME_1700000_CLASS_ID       =  1700000", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 8480, "      FRAME_1700000_CENTER         = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 8560, "      FRAME_1700000_RELATIVE       = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 8640, "      FRAME_1700000_DEF_STYLE      = 'PARAMETERIZED'",
	     (ftnlen)80, (ftnlen)52);
    s_copy(pck + 8720, "      FRAME_1700000_FAMILY         = 'TWO-VECTOR'", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 8800, "      FRAME_1700000_PRI_AXIS       = 'X'", (ftnlen)80,
	     (ftnlen)40);
    s_copy(pck + 8880, "      FRAME_1700000_PRI_VECTOR_DEF = 'OBSERVER_TARGE"
	    "T_POSITION'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 8960, "      FRAME_1700000_PRI_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 9040, "      FRAME_1700000_PRI_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 9120, "      FRAME_1700000_PRI_ABCORR     = 'NONE'", (ftnlen)
	    80, (ftnlen)43);
    s_copy(pck + 9200, "      FRAME_1700000_SEC_AXIS       = 'Y'", (ftnlen)80,
	     (ftnlen)40);
    s_copy(pck + 9280, "      FRAME_1700000_SEC_VECTOR_DEF = 'OBSERVER_TARGE"
	    "T_VELOCITY'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 9360, "      FRAME_1700000_SEC_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 9440, "      FRAME_1700000_SEC_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 9520, "      FRAME_1700000_SEC_ABCORR     = 'NONE'", (ftnlen)
	    80, (ftnlen)43);
    s_copy(pck + 9600, "      FRAME_1700000_SEC_FRAME      = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 9680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 9760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 9840, "      FRAME_ALPHA_VIEW_XZ         =  1700001", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 9920, "      FRAME_1700001_NAME           = 'ALPHA_VIEW_XZ'",
	     (ftnlen)80, (ftnlen)52);
    s_copy(pck + 10000, "      FRAME_1700001_CLASS          =  5", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 10080, "      FRAME_1700001_CLASS_ID       =  1700001", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 10160, "      FRAME_1700001_CENTER         = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 10240, "      FRAME_1700001_RELATIVE       = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 10320, "      FRAME_1700001_DEF_STYLE      = 'PARAMETERIZED'"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 10400, "      FRAME_1700001_FAMILY         = 'TWO-VECTOR'", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 10480, "      FRAME_1700001_PRI_AXIS       = 'X'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 10560, "      FRAME_1700001_PRI_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_POSITION'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 10640, "      FRAME_1700001_PRI_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 10720, "      FRAME_1700001_PRI_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 10800, "      FRAME_1700001_PRI_ABCORR     = 'NONE'", (
	    ftnlen)80, (ftnlen)43);
    s_copy(pck + 10880, "      FRAME_1700001_SEC_AXIS       = 'Z'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 10960, "      FRAME_1700001_SEC_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_VELOCITY'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 11040, "      FRAME_1700001_SEC_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 11120, "      FRAME_1700001_SEC_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 11200, "      FRAME_1700001_SEC_ABCORR     = 'NONE'", (
	    ftnlen)80, (ftnlen)43);
    s_copy(pck + 11280, "      FRAME_1700001_SEC_FRAME      = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 11360, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)16);
    s_copy(pck + 11440, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(pck + 11520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 11600, "      Aberration corrected view frames for body ALP"
	    "HA relative to the Sun.", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 11680, "      Variants of both", (ftnlen)80, (ftnlen)22);
    s_copy(pck + 11760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 11840, "         ALPHA_VIEW_XY", (ftnlen)80, (ftnlen)22);
    s_copy(pck + 11920, "         ALPHA_VIEW_XZ", (ftnlen)80, (ftnlen)22);
    s_copy(pck + 12000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 12080, "      are supported. All light time corrections are"
	    " converged Newtonian.", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 12160, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)16);
    s_copy(pck + 12240, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(pck + 12320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 12400, "      FRAME_ALPHA_VIEW_XY_CN       =  1700002", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 12480, "      FRAME_1700002_NAME           = 'ALPHA_VIEW_XY"
	    "_CN'", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 12560, "      FRAME_1700002_CLASS          =  5", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 12640, "      FRAME_1700002_CLASS_ID       =  1700002", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 12720, "      FRAME_1700002_CENTER         = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 12800, "      FRAME_1700002_RELATIVE       = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 12880, "      FRAME_1700002_DEF_STYLE      = 'PARAMETERIZED'"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 12960, "      FRAME_1700002_FAMILY         = 'TWO-VECTOR'", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 13040, "      FRAME_1700002_PRI_AXIS       = 'X'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 13120, "      FRAME_1700002_PRI_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_POSITION'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 13200, "      FRAME_1700002_PRI_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 13280, "      FRAME_1700002_PRI_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 13360, "      FRAME_1700002_PRI_ABCORR     = 'CN'", (ftnlen)
	    80, (ftnlen)41);
    s_copy(pck + 13440, "      FRAME_1700002_SEC_AXIS       = 'Y'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 13520, "      FRAME_1700002_SEC_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_VELOCITY'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 13600, "      FRAME_1700002_SEC_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 13680, "      FRAME_1700002_SEC_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 13760, "      FRAME_1700002_SEC_ABCORR     = 'CN'", (ftnlen)
	    80, (ftnlen)41);
    s_copy(pck + 13840, "      FRAME_1700002_SEC_FRAME      = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 13920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 14000, "      FRAME_ALPHA_VIEW_XY_CNS      =  1700003", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 14080, "      FRAME_1700003_NAME           = 'ALPHA_VIEW_XY"
	    "_CNS'", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 14160, "      FRAME_1700003_CLASS          =  5", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 14240, "      FRAME_1700003_CLASS_ID       =  1700003", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 14320, "      FRAME_1700003_CENTER         = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 14400, "      FRAME_1700003_RELATIVE       = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 14480, "      FRAME_1700003_DEF_STYLE      = 'PARAMETERIZED'"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 14560, "      FRAME_1700003_FAMILY         = 'TWO-VECTOR'", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 14640, "      FRAME_1700003_PRI_AXIS       = 'X'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 14720, "      FRAME_1700003_PRI_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_POSITION'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 14800, "      FRAME_1700003_PRI_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 14880, "      FRAME_1700003_PRI_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 14960, "      FRAME_1700003_PRI_ABCORR     = 'CN+S'", (
	    ftnlen)80, (ftnlen)43);
    s_copy(pck + 15040, "      FRAME_1700003_SEC_AXIS       = 'Y'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 15120, "      FRAME_1700003_SEC_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_VELOCITY'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 15200, "      FRAME_1700003_SEC_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 15280, "      FRAME_1700003_SEC_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 15360, "      FRAME_1700003_SEC_ABCORR     = 'CN+S'", (
	    ftnlen)80, (ftnlen)43);
    s_copy(pck + 15440, "      FRAME_1700003_SEC_FRAME      = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 15520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 15600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 15680, "      FRAME_ALPHA_VIEW_XY_XCN      =  1700004", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 15760, "      FRAME_1700004_NAME           = 'ALPHA_VIEW_XY"
	    "_XCN'", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 15840, "      FRAME_1700004_CLASS          =  5", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 15920, "      FRAME_1700004_CLASS_ID       =  1700004", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 16000, "      FRAME_1700004_CENTER         = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 16080, "      FRAME_1700004_RELATIVE       = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 16160, "      FRAME_1700004_DEF_STYLE      = 'PARAMETERIZED'"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 16240, "      FRAME_1700004_FAMILY         = 'TWO-VECTOR'", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 16320, "      FRAME_1700004_PRI_AXIS       = 'X'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 16400, "      FRAME_1700004_PRI_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_POSITION'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 16480, "      FRAME_1700004_PRI_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 16560, "      FRAME_1700004_PRI_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 16640, "      FRAME_1700004_PRI_ABCORR     = 'XCN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 16720, "      FRAME_1700004_SEC_AXIS       = 'Y'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 16800, "      FRAME_1700004_SEC_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_VELOCITY'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 16880, "      FRAME_1700004_SEC_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 16960, "      FRAME_1700004_SEC_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 17040, "      FRAME_1700004_SEC_ABCORR     = 'XCN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 17120, "      FRAME_1700004_SEC_FRAME      = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 17200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 17280, "      FRAME_ALPHA_VIEW_XY_XCNS     =  1700005", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 17360, "      FRAME_1700005_NAME           = 'ALPHA_VIEW_XY"
	    "_XCNS'", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 17440, "      FRAME_1700005_CLASS          =  5", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 17520, "      FRAME_1700005_CLASS_ID       =  1700005", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 17600, "      FRAME_1700005_CENTER         = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 17680, "      FRAME_1700005_RELATIVE       = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 17760, "      FRAME_1700005_DEF_STYLE      = 'PARAMETERIZED'"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 17840, "      FRAME_1700005_FAMILY         = 'TWO-VECTOR'", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 17920, "      FRAME_1700005_PRI_AXIS       = 'X'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 18000, "      FRAME_1700005_PRI_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_POSITION'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 18080, "      FRAME_1700005_PRI_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 18160, "      FRAME_1700005_PRI_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 18240, "      FRAME_1700005_PRI_ABCORR     = 'XCN+S'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 18320, "      FRAME_1700005_SEC_AXIS       = 'Y'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 18400, "      FRAME_1700005_SEC_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_VELOCITY'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 18480, "      FRAME_1700005_SEC_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 18560, "      FRAME_1700005_SEC_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 18640, "      FRAME_1700005_SEC_ABCORR     = 'XCN+S'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 18720, "      FRAME_1700005_SEC_FRAME      = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 18800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 18880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 18960, "      FRAME_ALPHA_VIEW_XZ_CN       =  1700006", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 19040, "      FRAME_1700006_NAME           = 'ALPHA_VIEW_XZ"
	    "_CN'", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 19120, "      FRAME_1700006_CLASS          =  5", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 19200, "      FRAME_1700006_CLASS_ID       =  1700006", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 19280, "      FRAME_1700006_CENTER         = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 19360, "      FRAME_1700006_RELATIVE       = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 19440, "      FRAME_1700006_DEF_STYLE      = 'PARAMETERIZED'"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 19520, "      FRAME_1700006_FAMILY         = 'TWO-VECTOR'", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 19600, "      FRAME_1700006_PRI_AXIS       = 'X'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 19680, "      FRAME_1700006_PRI_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_POSITION'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 19760, "      FRAME_1700006_PRI_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 19840, "      FRAME_1700006_PRI_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 19920, "      FRAME_1700006_PRI_ABCORR     = 'CN'", (ftnlen)
	    80, (ftnlen)41);
    s_copy(pck + 20000, "      FRAME_1700006_SEC_AXIS       = 'Z'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 20080, "      FRAME_1700006_SEC_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_VELOCITY'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 20160, "      FRAME_1700006_SEC_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 20240, "      FRAME_1700006_SEC_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 20320, "      FRAME_1700006_SEC_ABCORR     = 'CN'", (ftnlen)
	    80, (ftnlen)41);
    s_copy(pck + 20400, "      FRAME_1700006_SEC_FRAME      = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 20480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 20560, "      FRAME_ALPHA_VIEW_XZ_CNS      =  1700007", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 20640, "      FRAME_1700007_NAME           = 'ALPHA_VIEW_XZ"
	    "_CNS'", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 20720, "      FRAME_1700007_CLASS          =  5", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 20800, "      FRAME_1700007_CLASS_ID       =  1700007", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 20880, "      FRAME_1700007_CENTER         = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 20960, "      FRAME_1700007_RELATIVE       = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 21040, "      FRAME_1700007_DEF_STYLE      = 'PARAMETERIZED'"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 21120, "      FRAME_1700007_FAMILY         = 'TWO-VECTOR'", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 21200, "      FRAME_1700007_PRI_AXIS       = 'X'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 21280, "      FRAME_1700007_PRI_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_POSITION'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 21360, "      FRAME_1700007_PRI_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 21440, "      FRAME_1700007_PRI_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 21520, "      FRAME_1700007_PRI_ABCORR     = 'CN+S'", (
	    ftnlen)80, (ftnlen)43);
    s_copy(pck + 21600, "      FRAME_1700007_SEC_AXIS       = 'Z'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 21680, "      FRAME_1700007_SEC_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_VELOCITY'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 21760, "      FRAME_1700007_SEC_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 21840, "      FRAME_1700007_SEC_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 21920, "      FRAME_1700007_SEC_ABCORR     = 'CN+S'", (
	    ftnlen)80, (ftnlen)43);
    s_copy(pck + 22000, "      FRAME_1700007_SEC_FRAME      = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 22080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 22160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 22240, "      FRAME_ALPHA_VIEW_XZ_XCN      =  1700008", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 22320, "      FRAME_1700008_NAME           = 'ALPHA_VIEW_XZ"
	    "_XCN'", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 22400, "      FRAME_1700008_CLASS          =  5", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 22480, "      FRAME_1700008_CLASS_ID       =  1700008", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 22560, "      FRAME_1700008_CENTER         = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 22640, "      FRAME_1700008_RELATIVE       = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 22720, "      FRAME_1700008_DEF_STYLE      = 'PARAMETERIZED'"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 22800, "      FRAME_1700008_FAMILY         = 'TWO-VECTOR'", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 22880, "      FRAME_1700008_PRI_AXIS       = 'X'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 22960, "      FRAME_1700008_PRI_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_POSITION'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 23040, "      FRAME_1700008_PRI_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 23120, "      FRAME_1700008_PRI_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 23200, "      FRAME_1700008_PRI_ABCORR     = 'XCN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 23280, "      FRAME_1700008_SEC_AXIS       = 'Z'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 23360, "      FRAME_1700008_SEC_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_VELOCITY'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 23440, "      FRAME_1700008_SEC_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 23520, "      FRAME_1700008_SEC_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 23600, "      FRAME_1700008_SEC_ABCORR     = 'XCN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 23680, "      FRAME_1700008_SEC_FRAME      = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 23760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 23840, "      FRAME_ALPHA_VIEW_XZ_XCNS     =  1700009", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 23920, "      FRAME_1700009_NAME           = 'ALPHA_VIEW_XZ"
	    "_XCNS'", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 24000, "      FRAME_1700009_CLASS          =  5", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 24080, "      FRAME_1700009_CLASS_ID       =  1700009", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 24160, "      FRAME_1700009_CENTER         = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 24240, "      FRAME_1700009_RELATIVE       = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 24320, "      FRAME_1700009_DEF_STYLE      = 'PARAMETERIZED'"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 24400, "      FRAME_1700009_FAMILY         = 'TWO-VECTOR'", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 24480, "      FRAME_1700009_PRI_AXIS       = 'X'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 24560, "      FRAME_1700009_PRI_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_POSITION'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 24640, "      FRAME_1700009_PRI_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 24720, "      FRAME_1700009_PRI_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 24800, "      FRAME_1700009_PRI_ABCORR     = 'XCN+S'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 24880, "      FRAME_1700009_SEC_AXIS       = 'Z'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 24960, "      FRAME_1700009_SEC_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_VELOCITY'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 25040, "      FRAME_1700009_SEC_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 25120, "      FRAME_1700009_SEC_TARGET     = 'ALPHA'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 25200, "      FRAME_1700009_SEC_ABCORR     = 'XCN+S'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 25280, "      FRAME_1700009_SEC_FRAME      = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 25360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 25440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 25520, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)16);
    s_copy(pck + 25600, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(pck + 25680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 25760, "      View frames for body BETA relative to the Sun",
	     (ftnlen)80, (ftnlen)51);
    s_copy(pck + 25840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 25920, "         BETA_VIEW_XY      orbital motion of BETA l"
	    "ies in X-Y plane", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 26000, "                           of this frame.", (ftnlen)
	    80, (ftnlen)41);
    s_copy(pck + 26080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 26160, "         BETA_VIEW_XZ      orbital motion of BETA l"
	    "ies in X-Z plane", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 26240, "                           of this frame.", (ftnlen)
	    80, (ftnlen)41);
    s_copy(pck + 26320, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)16);
    s_copy(pck + 26400, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(pck + 26480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 26560, "      FRAME_BETA_VIEW_XY           =  1700010", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 26640, "      FRAME_1700010_NAME           = 'BETA_VIEW_XY'",
	     (ftnlen)80, (ftnlen)51);
    s_copy(pck + 26720, "      FRAME_1700010_CLASS          =  5", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 26800, "      FRAME_1700010_CLASS_ID       =  1700010", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 26880, "      FRAME_1700010_CENTER         = 'BETA'", (
	    ftnlen)80, (ftnlen)43);
    s_copy(pck + 26960, "      FRAME_1700010_RELATIVE       = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 27040, "      FRAME_1700010_DEF_STYLE      = 'PARAMETERIZED'"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 27120, "      FRAME_1700010_FAMILY         = 'TWO-VECTOR'", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 27200, "      FRAME_1700010_PRI_AXIS       = 'X'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 27280, "      FRAME_1700010_PRI_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_POSITION'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 27360, "      FRAME_1700010_PRI_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 27440, "      FRAME_1700010_PRI_TARGET     = 'BETA'", (
	    ftnlen)80, (ftnlen)43);
    s_copy(pck + 27520, "      FRAME_1700010_PRI_ABCORR     = 'NONE'", (
	    ftnlen)80, (ftnlen)43);
    s_copy(pck + 27600, "      FRAME_1700010_SEC_AXIS       = 'Y'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 27680, "      FRAME_1700010_SEC_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_VELOCITY'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 27760, "      FRAME_1700010_SEC_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 27840, "      FRAME_1700010_SEC_TARGET     = 'BETA'", (
	    ftnlen)80, (ftnlen)43);
    s_copy(pck + 27920, "      FRAME_1700010_SEC_ABCORR     = 'NONE'", (
	    ftnlen)80, (ftnlen)43);
    s_copy(pck + 28000, "      FRAME_1700010_SEC_FRAME      = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 28080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 28160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 28240, "      FRAME_BETA_VIEW_XZ           =  1700011", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 28320, "      FRAME_1700011_NAME           = 'BETA_VIEW_XZ'",
	     (ftnlen)80, (ftnlen)51);
    s_copy(pck + 28400, "      FRAME_1700011_CLASS          =  5", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 28480, "      FRAME_1700011_CLASS_ID       =  1700011", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 28560, "      FRAME_1700011_CENTER         = 'BETA'", (
	    ftnlen)80, (ftnlen)43);
    s_copy(pck + 28640, "      FRAME_1700011_RELATIVE       = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 28720, "      FRAME_1700011_DEF_STYLE      = 'PARAMETERIZED'"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 28800, "      FRAME_1700011_FAMILY         = 'TWO-VECTOR'", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 28880, "      FRAME_1700011_PRI_AXIS       = 'X'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 28960, "      FRAME_1700011_PRI_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_POSITION'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 29040, "      FRAME_1700011_PRI_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 29120, "      FRAME_1700011_PRI_TARGET     = 'BETA'", (
	    ftnlen)80, (ftnlen)43);
    s_copy(pck + 29200, "      FRAME_1700011_PRI_ABCORR     = 'NONE'", (
	    ftnlen)80, (ftnlen)43);
    s_copy(pck + 29280, "      FRAME_1700011_SEC_AXIS       = 'Z'", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 29360, "      FRAME_1700011_SEC_VECTOR_DEF = 'OBSERVER_TARG"
	    "ET_VELOCITY'", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 29440, "      FRAME_1700011_SEC_OBSERVER   = 'SUN'", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 29520, "      FRAME_1700011_SEC_TARGET     = 'BETA'", (
	    ftnlen)80, (ftnlen)43);
    s_copy(pck + 29600, "      FRAME_1700011_SEC_ABCORR     = 'NONE'", (
	    ftnlen)80, (ftnlen)43);
    s_copy(pck + 29680, "      FRAME_1700011_SEC_FRAME      = 'J2000'", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 29760, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)16);
    s_copy(pck + 29840, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(pck + 29920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 30000, "   Radii and GM for the Sun.", (ftnlen)80, (ftnlen)
	    28);
    s_copy(pck + 30080, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)16);
    s_copy(pck + 30160, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(pck + 30240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 30320, "      BODY10_RADII            = ( 1000, 1000, 1000 )"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 30400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 30480, "      BODY10_GM               =  0.9974529073915115"
	    "6E+09", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 30560, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)16);
    s_copy(pck + 30640, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(pck + 30720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 30800, "   GM for ALPHA. This GM, together with a circular", 
	    (ftnlen)80, (ftnlen)50);
    s_copy(pck + 30880, "   orbit of radius 1.E5 for body GAMMA, yields a 24"
	    " hour period", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 30960, "   for GAMMA.", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 31040, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)16);
    s_copy(pck + 31120, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(pck + 31200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 31280, "      BODY1000_GM             =  0.5288496871297023"
	    "3E+07", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 31360, " ", (ftnlen)80, (ftnlen)1);

/*     Create the PCK. */

    txtopn_(namepc, &unit, namepc_len);
    for (i__ = 1; i__ <= 393; ++i__) {
	writln_(pck + ((i__1 = i__ - 1) < 393 && 0 <= i__1 ? i__1 : s_rnge(
		"pck", i__1, "natpck_", (ftnlen)888)) * 80, &unit, (ftnlen)80)
		;
    }
    cl__1.cerr = 0;
    cl__1.cunit = unit;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*     If this file needs to be loaded, do it. */

    if (*loadpc) {
	ldpool_(namepc, namepc_len);
    }
    if (*keeppc) {

/*        If we are keeping this file, we need to register it */
/*        with FILREG. */

	tfiles_(namepc, namepc_len);
    } else {

/*        Lose the file. */

	kilfil_(namepc, namepc_len);
    }
    chkout_("NATPCK", (ftnlen)6);
    return 0;
} /* natpck_ */

