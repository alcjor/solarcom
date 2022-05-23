/* t_pck09.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__4009 = 4009;
static integer c__4 = 4;
static integer c__2 = 2;

/* $Procedure      T_PCK09 (Create a test text PCK based on pck00009.tpc ) */
/* Subroutine */ int t_pck09__(char *namepc, logical *loadpc, logical *keeppc,
	 ftnlen namepc_len)
{
    /* System generated locals */
    address a__1[4], a__2[2];
    integer i__1[4], i__2[2], i__3;
    char ch__1[10], ch__2[10];
    cllist cl__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    integer s_rnge(char *, integer, char *, integer), f_clos(cllist *);

    /* Local variables */
    integer unit, i__, r__;
    extern integer rtrim_(char *, ftnlen);
    extern /* Character */ VOID begdat_(char *, ftnlen);
    extern /* Subroutine */ int clearc_(integer *, char *, ftnlen), kilfil_(
	    char *, ftnlen), tfiles_(char *, ftnlen), ldpool_(char *, ftnlen);
    extern /* Character */ VOID begtxt_(char *, ftnlen);
    extern /* Subroutine */ int writln_(char *, integer *, ftnlen), txtopn_(
	    char *, integer *, ftnlen);
    char pck[80*4009];

/* $ Abstract */

/*     Create and if appropriate load a test PCK kernel.  The kernel */
/*     created by this routine is meant to contain data consistent with */
/*     the equations implemented in the test utility routine t_pckeq. */

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

/*      VARIABLE  I/O  DESCRIPTION */
/*      --------  ---  -------------------------------------------------- */
/*      NAMEPC     I   The name of the PC-kernel to create */
/*      LOADPC     I   Load the PC-kernel if TRUE */
/*      KEEPPC     I   Keep the PC-kernel if TRUE, else delete it. */

/* $ Detailed_Input */

/*     NAMEPC      is the name of a PC-kernel to create and load if */
/*                 LOADPC is set to TRUE.  If a PC-kernel of the same */
/*                 name already exists it is deleted. */


/*     LOADPC      is a logical that indicates whether or not the PCK */
/*                 file should be loaded after it is created.  If it */
/*                 has the value TRUE the PC-kernel is loaded after */
/*                 it is created.  Otherwise it is left un-opened. */


/*     KEEPPC      is a logical that indicates whether or not the PCK */
/*                 file should be deleted after it is loaded.  If KEEPPC */
/*                 is TRUE the file is not deleted.  If KEEPPC is FALSE */
/*                 the file is deleted after it is loaded.  NOTE that */
/*                 unless LOADSC is TRUE, the PCK file is not deleted */
/*                 by this routine.  This routine deletes the PC-kernel */
/*                 only if it LOADSC is TRUE and KEEPPC is FALSE. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*      None. */

/* $ Exceptions */

/*     None. */

/* $ Files */

/*     This routine creates a text PCK based on the current */
/*     IAU report [1]. */

/* $ Particulars */

/*     This test utility supports validation of the current NAIF */
/*     text PCK. */

/* $ Examples */

/*     See F_RDPCK. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     [1]   Seidelmann, P.K., Archinal, B.A., A'Hearn, M.F., */
/*           Conrad, A., Consolmagno, G.J., Hestroffer, D., */
/*           Hilton, J.L., Krasinsky, G.A., Neumann, G., */
/*           Oberst, J., Stooke, P., Tedesco, E.F., Tholen, D.J., */
/*           and Thomas, P.C. "Report of the IAU/IAG Working Group */
/*           on cartographic coordinates and rotational elements: 2006." */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */
/*     W.L. Taber      (JPL) */

/* $ Version */

/* -    Test Utilities 1.0.0, 03-MAR-2010 (WLT) (NJB) */

/* -& */
/* $ Index_Entries */

/*     Create current NAIF text PCK file. */

/* -& */

/*     SPICELIB Functions */


/*     Test Utility Functions */


/*     Local Variables. */

    kilfil_(namepc, namepc_len);
    clearc_(&c__4009, pck, (ftnlen)80);
    s_copy(pck, "KPL/PCK", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 80, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 240, "P_constants (PcK) SPICE kernel file", (ftnlen)80, (
	    ftnlen)35);
    s_copy(pck + 320, "====================================================="
	    "======================", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 480, "        By: Nat Bachman (NAIF)    2010 March 3", (
	    ftnlen)80, (ftnlen)46);
    s_copy(pck + 560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 720, "Purpose", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 800, "-----------------------------------------------------"
	    "---", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 960, "     This file makes available for use in SPICE-based"
	    " application", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 1040, "     software orientation and size/shape data for na"
	    "tural bodies. The", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 1120, "     principal source of the data is a published rep"
	    "ort by the IAU/IAG", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 1200, "     Working Group on Cartographic Coordinates and R"
	    "otational Elements [1].", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 1280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 1360, "     Orientation and size/shape data not provided by"
	    " this file may be", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 1440, "     available in mission-specific PCK files. Such P"
	    "CKs may be the preferred", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 1520, "     data source for mission-related applications. M"
	    "ission-specific PCKs can", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 1600, "     be found in PDS archives or on the NAIF web sit"
	    "e at URL:", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 1680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 1760, "        http://naif.jpl.nasa.gov", (ftnlen)80, (
	    ftnlen)32);
    s_copy(pck + 1840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 1920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 2000, "File Organization", (ftnlen)80, (ftnlen)17);
    s_copy(pck + 2080, "----------------------------------------------------"
	    "----", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 2160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 2240, "     The contents of this file are as follows.", (
	    ftnlen)80, (ftnlen)46);
    s_copy(pck + 2320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 2400, "     Introductory Information:", (ftnlen)80, (ftnlen)
	    30);
    s_copy(pck + 2480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 2560, "         --   Purpose", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 2640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 2720, "         --   File Organization", (ftnlen)80, (ftnlen)
	    31);
    s_copy(pck + 2800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 2880, "         --   Version description", (ftnlen)80, (
	    ftnlen)33);
    s_copy(pck + 2960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 3040, "         --   Disclaimer", (ftnlen)80, (ftnlen)24);
    s_copy(pck + 3120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 3200, "         --   Sources", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 3280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 3360, "         --   Explanatory notes", (ftnlen)80, (ftnlen)
	    31);
    s_copy(pck + 3440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 3520, "         --   Body numbers and names", (ftnlen)80, (
	    ftnlen)36);
    s_copy(pck + 3600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 3680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 3760, "     PcK Data:", (ftnlen)80, (ftnlen)14);
    s_copy(pck + 3840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 3920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 4000, "        Orientation Data", (ftnlen)80, (ftnlen)24);
    s_copy(pck + 4080, "        ----------------", (ftnlen)80, (ftnlen)24);
    s_copy(pck + 4160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 4240, "         --   Orientation constants for the Sun and "
	    "planets.", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 4320, "              Additional items included in this sect"
	    "ion:", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 4400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 4480, "                 - Earth north geomagnetic centered "
	    "dipole values", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 4560, "                   for epochs 1945-2000", (ftnlen)80, 
	    (ftnlen)39);
    s_copy(pck + 4640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 4720, "                 - Mars prime meridian offset \"lamb"
	    "da_a\"", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 4800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 4880, "         --   Orientation constants for satellites", (
	    ftnlen)80, (ftnlen)50);
    s_copy(pck + 4960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 5040, "         --   Orientation constants for asteroids Er"
	    "os, Gaspra, Ida,", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 5120, "              Itokawa, and Vesta", (ftnlen)80, (
	    ftnlen)32);
    s_copy(pck + 5200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 5280, "         --   Orientation constants for comets 19P/B"
	    "orrelly", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 5360, "              and 9P/Tempel 1", (ftnlen)80, (ftnlen)
	    29);
    s_copy(pck + 5440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 5520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 5600, "        Radii of Bodies", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 5680, "        ---------------", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 5760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 5840, "         --   Radii of Sun and planets", (ftnlen)80, (
	    ftnlen)38);
    s_copy(pck + 5920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 6000, "         --   Radii of satellites, where available", (
	    ftnlen)80, (ftnlen)50);
    s_copy(pck + 6080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 6160, "         --   Radii of asteroids Ceres, Eros, Gaspra"
	    ", Ida, Itokawa,", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 6240, "              Mathilde, Toutatis, and Vesta.", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 6320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 6400, "         --   Radii of comets 19P/Borrelly, Halley, "
	    "9P/Tempel 1,", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 6480, "              and 81P/Wild 2", (ftnlen)80, (ftnlen)28)
	    ;
    s_copy(pck + 6560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 6640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 6720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 6800, "Version Description", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 6880, "----------------------------------------------------"
	    "----", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 6960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 7040, "     This file was created on March 3, 2010. This ve"
	    "rsion", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 7120, "     incorporates data from reference [1].", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 7200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 7280, "     This file contains size, shape, and orientation"
	    " data for all", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 7360, "     objects described by the previous version of th"
	    "e file, except", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 7440, "     for Kleopatra: a shape model for this body is n"
	    "ot provided in [1]", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 7520, "     because, according to this source, it had been"
	    " \"modeled from", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 7600, "     low resolution radar data, and cannot be mapped"
	    " from those", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 7680, "     data.\"", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 7760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 7840, "     New objects covered by this file but not the pr"
	    "evious", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 7920, "     version are:", (ftnlen)80, (ftnlen)17);
    s_copy(pck + 8000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 8080, "        19P/Borrelly", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 8160, "        Halley", (ftnlen)80, (ftnlen)14);
    s_copy(pck + 8240, "        9P/Tempel 1", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 8320, "        81P/Wild 2", (ftnlen)80, (ftnlen)18);
    s_copy(pck + 8400, "        Ceres", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 8480, "        Itokawa", (ftnlen)80, (ftnlen)15);
    s_copy(pck + 8560, "        Mathilde", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 8640, "        Toutatis", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 8720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 8800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 8880, "Disclaimer", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 8960, "----------------------------------------------------"
	    "----", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 9040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 9120, "Applicability of Data", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 9200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 9280, "     This P_constants file may not contain the param"
	    "eter values that", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 9360, "     you prefer. NAIF suggests that you inspect this"
	    " file visually", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 9440, "     before proceeding with any critical or extended"
	    " data processing.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 9520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 9600, "File Modifications by Users", (ftnlen)80, (ftnlen)27);
    s_copy(pck + 9680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 9760, "     Note that this file may be readily modified by "
	    "you to change", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 9840, "     values or add/delete parameters. NAIF requests "
	    "that you update the", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 9920, "     \"by line,\" date, and version description sect"
	    "ion if you modify", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 10000, "     this file.", (ftnlen)80, (ftnlen)15);
    s_copy(pck + 10080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 10160, "Known Limitations and Caveats", (ftnlen)80, (ftnlen)
	    29);
    s_copy(pck + 10240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 10320, "     Accuracy", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 10400, "     --------", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 10480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 10560, "     In general, the orientation models given here "
	    "are claimed by the", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 10640, "     IAU/IAG Working Group Report [1] to be accurat"
	    "e to 0.1 degree", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 10720, "     ([1], p.158). However, NAIF notes that orienta"
	    "tion models for", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 10800, "     natural satellites and asteroids have in some "
	    "cases changed", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 10880, "     substantially with the availability of new obs"
	    "ervational data, so", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 10960, "     users are urged to investigate the suitability"
	    " for their", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 11040, "     applications of the models presented here.", (
	    ftnlen)80, (ftnlen)47);
    s_copy(pck + 11120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 11200, "     Earth orientation", (ftnlen)80, (ftnlen)22);
    s_copy(pck + 11280, "     -----------------", (ftnlen)80, (ftnlen)22);
    s_copy(pck + 11360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 11440, "     NAIF strongly cautions against using the earth"
	    " rotation model", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 11520, "     (from [1]) for work demanding high accuracy. T"
	    "his model has been", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 11600, "     determined by NAIF to have an error in the pri"
	    "me meridian location", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 11680, "     of magnitude at least 150 arcseconds, with a l"
	    "ocal minimum", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 11760, "     occurring during the year 1999. Regarding avai"
	    "lability of better", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 11840, "     earth orientation data for use with the SPICE "
	    "system:", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 11920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 12000, "        Earth orientation data are available from N"
	    "AIF in the form of", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 12080, "        binary earth PCK files. NAIF employs an aut"
	    "omated process to", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 12160, "        create these files; each time JPL's Trackin"
	    "g Systems and", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 12240, "        Applications Section produces a new earth o"
	    "rientation parameter", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 12320, "        (EOP) file, a new PCK is produced. These PC"
	    "Ks cover a roughly", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 12400, "        10 year time span starting at Jan. 1, 2000."
	    " In these PCK files,", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 12480, "        the following effects are accounted for in "
	    "modeling the earth's", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 12560, "        rotation:", (ftnlen)80, (ftnlen)17);
    s_copy(pck + 12640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 12720, "           - Precession:                   1976 IAU"
	    " model", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 12800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 12880, "           - Nutation:                     1980 IAU"
	    " model, plus interpolated", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 12960, "                                           EOP nuta"
	    "tion corrections", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 13040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 13120, "           - Polar motion:                 interpol"
	    "ated from EOP file", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 13200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 13280, "           - True sidereal time:", (ftnlen)80, (
	    ftnlen)32);
    s_copy(pck + 13360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 13440, "                  UT1 - UT1R (if needed):  given by"
	    " analytic formula", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 13520, "                + TAI - UT1 (or UT1R):     interpol"
	    "ated from EOP file", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 13600, "                + UT1 - GMST:              given by"
	    " analytic formula", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 13680, "                + equation of equinoxes:   given by"
	    " analytic formula", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 13760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 13840, "             where", (ftnlen)80, (ftnlen)18);
    s_copy(pck + 13920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 14000, "                TAI    =   International Atomic Time"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 14080, "                UT1    =   Greenwich hour angle of "
	    "computed mean sun - 12h", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 14160, "                UT1R   =   Regularized UT1", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 14240, "                GMST   =   Greenwich mean sidereal "
	    "time", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 14320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 14400, "        These kernels are available from the NAIF w"
	    "eb site", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 14480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 14560, "           http://naif.jpl.nasa.gov", (ftnlen)80, (
	    ftnlen)35);
    s_copy(pck + 14640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 14720, "        (follow the links to Data, generic_kernels,"
	    " and PCK data) or", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 14800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 14880, "           ftp://naif.jpl.nasa.gov/pub/naif/generic"
	    "_kernels/pck", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 14960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 15040, "        or via anonymous ftp from the server", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 15120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 15200, "           naif.jpl.nasa.gov", (ftnlen)80, (ftnlen)
	    28);
    s_copy(pck + 15280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 15360, "        The kernels are in the path", (ftnlen)80, (
	    ftnlen)35);
    s_copy(pck + 15440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 15520, "           pub/naif/generic_kernels/pck", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 15600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 15680, "        At this time, these kernels have file names"
	    " of the form", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 15760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 15840, "           earth_000101_yymmdd_yymmdd.bpc", (ftnlen)
	    80, (ftnlen)41);
    s_copy(pck + 15920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 16000, "        The second and third dates are, respectivel"
	    "y, the file's", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 16080, "        coverage end time and the epoch of the last"
	    " datum.", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 16160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 16240, "        These binary PCK files are very accurate (e"
	    "rror < 0.1", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 16320, "        microradian) for epochs preceding the epoch"
	    " of the last datum.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 16400, "        For later epochs, the error rises to severa"
	    "l microradians.", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 16480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 16560, "        Binary PCK files giving accurate earth orie"
	    "ntation from 1972 to", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 16640, "        2007 and *low accuracy* predicted earth ori"
	    "entation from", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 16720, "        2007 to 2037 are also available in the same"
	    " location. See the", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 16800, "        aareadme.txt file at the \"pck\" URL above "
	    "for details.", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 16880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 16960, "        Characteristics and names of the binary ker"
	    "nels described here", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 17040, "        are subject to change. See the \"pck\" URL "
	    "above for information", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 17120, "        on current binary earth PCKs.", (ftnlen)80, (
	    ftnlen)37);
    s_copy(pck + 17200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 17280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 17360, "     Lunar orientation", (ftnlen)80, (ftnlen)22);
    s_copy(pck + 17440, "     -----------------", (ftnlen)80, (ftnlen)22);
    s_copy(pck + 17520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 17600, "     The lunar orientation formula provided by this"
	    " file is a", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 17680, "     trigonometric polynomial approximation yieldin"
	    "g the orientation of", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 17760, "     the lunar \"Mean Earth/Polar Axis\" (ME) refer"
	    "ence frame. A more", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 17840, "     accurate approximation can be obtained by usin"
	    "g both the NAIF", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 17920, "     lunar frame kernel and the binary lunar orient"
	    "ation PCK file,", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 18000, "     which are available on the NAIF web site (see "
	    "URLS above)", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 18080, "     and in the NAIF server's ftp area. The lunar f"
	    "rame kernel", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 18160, "     is located in the path", (ftnlen)80, (ftnlen)27)
	    ;
    s_copy(pck + 18240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 18320, "        pub/naif/generic_kernels/fk/satellites", (
	    ftnlen)80, (ftnlen)46);
    s_copy(pck + 18400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 18480, "     and has a name of the form", (ftnlen)80, (
	    ftnlen)31);
    s_copy(pck + 18560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 18640, "        moon_yymmdd.tf", (ftnlen)80, (ftnlen)22);
    s_copy(pck + 18720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 18800, "     The binary lunar PCK is in the path", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 18880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 18960, "        pub/naif/generic_kernels/pck", (ftnlen)80, (
	    ftnlen)36);
    s_copy(pck + 19040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 19120, "     and has a name of the form", (ftnlen)80, (
	    ftnlen)31);
    s_copy(pck + 19200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 19280, "        moon_pa_dennn_yyyy-yyyy.bpc", (ftnlen)80, (
	    ftnlen)35);
    s_copy(pck + 19360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 19440, "     See the \"aareadme.txt\" files in the paths sh"
	    "own above for details", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 19520, "     on file contents and versions. We also suggest"
	    " you refer to the", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 19600, "     SPICE tutorial named \"lunar_earth_pck-fk,\" w"
	    "hich is available from", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 19680, "     the NAIF web site.", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 19760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 19840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 19920, "     Earth geomagnetic dipole", (ftnlen)80, (ftnlen)
	    29);
    s_copy(pck + 20000, "     ------------------------", (ftnlen)80, (ftnlen)
	    29);
    s_copy(pck + 20080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 20160, "     The SPICE Toolkit doesn't currently contain so"
	    "ftware to model the", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 20240, "     earth's north geomagnetic centered dipole as a"
	    " function of time.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 20320, "     As a convenience for users, the north dipole l"
	    "ocation from the", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 20400, "     J2000 epoch was selected as a representative d"
	    "atum, and the", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 20480, "     planetocentric longitude and latitude of this "
	    "location have been", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 20560, "     associated with the keywords", (ftnlen)80, (
	    ftnlen)33);
    s_copy(pck + 20640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 20720, "        BODY399_N_GEOMAG_CTR_DIPOLE_LON", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 20800, "        BODY399_N_GEOMAG_CTR_DIPOLE_LAT", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 20880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 20960, "     Values for the earth's north geomagnetic cente"
	    "red dipole are", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 21040, "     presented in comments as a discrete time serie"
	    "s for the time range", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 21120, "     1945-2000. For details concerning the geomagne"
	    "tic field model from", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 21200, "     which these values were derived, including a d"
	    "iscussion of the", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 21280, "     model's accuracy, see [9].", (ftnlen)80, (
	    ftnlen)31);
    s_copy(pck + 21360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 21440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 21520, "     Mars prime meridian offset", (ftnlen)80, (
	    ftnlen)31);
    s_copy(pck + 21600, "     --------------------------", (ftnlen)80, (
	    ftnlen)31);
    s_copy(pck + 21680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 21760, "     The Mars prime meridian offset given by [5] is"
	    " not used by", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 21840, "     SPICE geometry software for computations invol"
	    "ving the shape", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 21920, "     of Mars (for example, in sub-observer point or"
	    " surface intercept", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 22000, "     computations). The value is provided for infor"
	    "mational", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 22080, "     purposes only.", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 22160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 22240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 22320, "     Software limitations", (ftnlen)80, (ftnlen)25);
    s_copy(pck + 22400, "     --------------------", (ftnlen)80, (ftnlen)25);
    s_copy(pck + 22480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 22560, "     SPICE Toolkits prior to version N0057 cannot m"
	    "ake use of", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 22640, "     trigonometric polynomial terms in the formulas"
	    " for orientation of", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 22720, "     the planets. The only planets for which such t"
	    "erms are used are", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 22800, "     Jupiter and Neptune. Use of trigonometric poly"
	    "nomial terms for", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 22880, "     natural satellites is and has been supported f"
	    "or all SPICE Toolkit", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 22960, "     versions.", (ftnlen)80, (ftnlen)14);
    s_copy(pck + 23040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 23120, "     The second nutation precession angle (M2) for "
	    "Mars is represented", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 23200, "     by a quadratic polynomial in the 2006 IAU repo"
	    "rt. The SPICELIB", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 23280, "     subroutine BODEUL can not handle this term (wh"
	    "ich is extremely", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 23360, "     small), so we truncate the polynomial to a lin"
	    "ear one. The", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 23440, "     resulting orientation error has a maximum magn"
	    "itude of less", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 23520, "     than 0.0032 degrees over the time span 1996-20"
	    "15 and less than", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 23600, "     0.0082 degrees over the time span 1986-2025.", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 23680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 23760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 23840, "Sources", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 23920, "---------------------------------------------------"
	    "-----", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 24000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 24080, "     The sources for the constants listed in this f"
	    "ile are:", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 24160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 24240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 24320, "        [1]   Seidelmann, P.K., Archinal, B.A., A'H"
	    "earn, M.F.,", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 24400, "              Conrad, A., Consolmagno, G.J., Hestro"
	    "ffer, D.,", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 24480, "              Hilton, J.L., Krasinsky, G.A., Neuman"
	    "n, G.,", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 24560, "              Oberst, J., Stooke, P., Tedesco, E.F."
	    ", Tholen, D.J.,", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 24640, "              and Thomas, P.C. \"Report of the IAU/"
	    "IAG Working Group", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 24720, "              on cartographic coordinates and rotat"
	    "ional elements: 2006.\"", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 24800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 24880, "        [2]   Seidelmann, P.K., Archinal, B.A., A'H"
	    "earn, M.F.,", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 24960, "              Cruikshank, D.P., Hilton, J.L., Kelle"
	    "r, H.U., Oberst, J.,", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 25040, "              Simon, J.L., Stooke, P., Tholen, D.J."
	    ", and Thomas, P.C.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 25120, "              \"Report of the IAU/IAG Working Group"
	    " on Cartographic", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 25200, "              Coordinates and Rotational Elements o"
	    "f the Planets and", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 25280, "              Satellites: 2003.\"", (ftnlen)80, (
	    ftnlen)32);
    s_copy(pck + 25360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 25440, "        [3]   Nautical Almanac Office, United State"
	    "s Naval Observatory", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 25520, "              and H.M. Nautical Almanac Office, Rut"
	    "herford Appleton", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 25600, "              Laboratory (2010). \"The Astronomical"
	    " Almanac for", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 25680, "              the Year 2010,\" U.S. Government Prin"
	    "ting Office,", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 25760, "              Washington, D.C.: and The Stationary "
	    "Office, London.", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 25840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 25920, "        [4]   Nautical Almanac Office, United State"
	    "s Naval Observatory,", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 26000, "              H.M. Nautical Almanac Office, Royal G"
	    "reenwich", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 26080, "              Observatory, Jet Propulsion Laborator"
	    "y, Bureau des", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 26160, "              Longitudes, and The Time Service and "
	    "Astronomy", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 26240, "              Departments, United States Naval Obse"
	    "rvatory (1992).", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 26320, "              \"Explanatory Supplement to the Astro"
	    "nomical Almanac,\" P.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 26400, "              Kenneth Seidelmann, ed. University Sc"
	    "ience Books, 20", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 26480, "              Edgehill Road, Mill Valley, CA 9494.", 
	    (ftnlen)80, (ftnlen)50);
    s_copy(pck + 26560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 26640, "        [5]   Duxbury, Thomas C. (2001). \"IAU/IAG "
	    "2000 Mars Cartographic", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 26720, "              Conventions,\"  presentation to the M"
	    "ars Express Data", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 26800, "              Archive Working Group, Dec. 14, 2001.",
	     (ftnlen)80, (ftnlen)51);
    s_copy(pck + 26880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 26960, "        [6]   Russell, C.T. and Luhmann, J.G. (1990"
	    "). \"Earth: Magnetic", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 27040, "              Field and Magnetosphere.\" <http://ww"
	    "w-ssc.igpp.ucla.", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 27120, "              edu/personnel/russell/papers/earth_ma"
	    "g>. Originally", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 27200, "              published in \"Encyclopedia of Planet"
	    "ary Sciences,\" J.H.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 27280, "              Shirley and R.W. Fainbridge, eds. Cha"
	    "pman and Hall,", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 27360, "              New York, pp 208-211.", (ftnlen)80, (
	    ftnlen)35);
    s_copy(pck + 27440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 27520, "        [7]   Russell, C.T. (1971). \"Geophysical C"
	    "oordinate", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 27600, "              Transformations,\" Cosmic Electrodyna"
	    "mics 2  184-186.", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 27680, "              NAIF document 181.0.", (ftnlen)80, (
	    ftnlen)34);
    s_copy(pck + 27760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 27840, "        [8]   ESA/ESTEC Space Environment Informati"
	    "on System (SPENVIS)", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 27920, "              (2003). Web page:  \"Dipole approxima"
	    "tions of the", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 28000, "              geomagnetic field.\"  <http://www.spe"
	    "nvis.oma.be/spenvis/", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 28080, "              help/background/magfield/cd.html>.", (
	    ftnlen)80, (ftnlen)48);
    s_copy(pck + 28160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 28240, "        [9]   International Association of Geomagne"
	    "tism and Aeronomy", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 28320, "              and International Union of Geodesy an"
	    "d Geophysics (2004).", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 28400, "              Web page:  \"The 9th Generation Inter"
	    "national Geomagnetic", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 28480, "              Reference Field.\" <http://www.ngdc.n"
	    "oaa.gov/", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 28560, "              IAGA/vmod/igrf.html>.", (ftnlen)80, (
	    ftnlen)35);
    s_copy(pck + 28640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 28720, "        [10]  Davies, M.E., Abalakin, V.K., Bursa, "
	    "M., Hunt, G.E.,", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 28800, "              and Lieske, J.H. (1989). \"Report of "
	    "the IAU/IAG/COSPAR", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 28880, "              Working Group on Cartographic Coordin"
	    "ates and Rotational", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 28960, "              Elements of the Planets and Satellite"
	    "s: 1988,\" Celestial", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 29040, "              Mechanics and Dynamical Astronomy, v."
	    "46, no.2, pp.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 29120, "              187-204.", (ftnlen)80, (ftnlen)22);
    s_copy(pck + 29200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 29280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 29360, "     Most values are from [1]. All exceptions are", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 29440, "     commented where they occur in this file. The e"
	    "xceptions are:", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 29520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 29600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 29680, "         --   Radii for the Sun are from [3].", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 29760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 29840, "         --   The second nutation precession angle "
	    "(M2) for Mars is", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 29920, "              represented by a quadratic polynomial"
	    " in the 2000", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 30000, "              IAU report. The SPICELIB subroutine B"
	    "ODEUL can not", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 30080, "              handle this term (which is extremely "
	    "small), so we", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 30160, "              truncate the polynomial to a linear o"
	    "ne.", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 30240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 30320, "          --  Earth north geomagnetic centered dipo"
	    "le values are from", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 30400, "              [8]. The article [6] was used to chec"
	    "k most of", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 30480, "              these values, and the values were als"
	    "o re-computed from", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 30560, "              the 9th generation IGRF [9] by Nat Ba"
	    "chman.", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 30640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 30720, "          -- The Mars prime meridian offset angle i"
	    "s from [5].", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 30800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 30880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 30960, "     \"Old values\" listed are from the SPICE P_con"
	    "stants file", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 31040, "     pck00008.tpc dated September 21, 2004. Most of"
	    " these values came", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 31120, "     from the 2003 IAU report [2].", (ftnlen)80, (
	    ftnlen)34);
    s_copy(pck + 31200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 31280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 31360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 31440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 31520, "Explanatory Notes", (ftnlen)80, (ftnlen)17);
    s_copy(pck + 31600, "---------------------------------------------------"
	    "-----", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 31680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 31760, "     This file, which is logically part of the SPIC"
	    "E P-kernel, contains", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 31840, "     constants used to model the orientation, size "
	    "and shape of the", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 31920, "     Sun, planets, natural satellites, and selected"
	    " comets and", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 32000, "     asteroids. The orientation models express the "
	    "direction of the", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 32080, "     pole and location of the prime meridian of a b"
	    "ody as a function of", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 32160, "     time. The size/shape models (\"shape models\" "
	    "for short) represent", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 32240, "     all bodies as ellipsoids, using two equatorial"
	    " radii and a polar", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 32320, "     radius. Spheroids and spheres are obtained whe"
	    "n two or all three", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 32400, "     radii are equal.", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 32480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 32560, "     The SPICE Toolkit routines that use this file "
	    "are documented in", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 32640, "     the SPICE \"Required Reading\" file pck.req. T"
	    "hey are also", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 32720, "     documented in the \"PCK\" SPICE tutorial, whic"
	    "h is available on", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 32800, "     the NAIF web site.", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 32880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 32960, "File Format", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 33040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 33120, "     A terse description of the PCK file format is "
	    "given here. See the", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 33200, "     SPICE \"Required Reading\" files pck.req and k"
	    "ernel.req for a", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 33280, "     detailed explanation of the SPICE text kernel "
	    "file format. The", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 33360, "     files pck.req and kernel.req are included in t"
	    "he documentation", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 33440, "     provided with the SPICE Toolkit.", (ftnlen)80, (
	    ftnlen)37);
    s_copy(pck + 33520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 33600, "     The file starts out with the ``ID word'' string"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 33680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 33760, "        KPL/PCK", (ftnlen)80, (ftnlen)15);
    s_copy(pck + 33840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 33920, "     This string identifies the file as a text kern"
	    "el containing PCK", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 34000, "     data.", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 34080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 34160, "     This file consists of a series of comment bloc"
	    "ks and data blocks.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 34240, "     Comment blocks, which contain free-form descri"
	    "ptive or explanatory", (ftnlen)80, (ftnlen)71);
/* Writing concatenation */
    i__1[0] = 29, a__1[0] = "     text, are preceded by a ";
    begtxt_(ch__1, (ftnlen)10);
    i__1[1] = 10, a__1[1] = ch__1;
    i__1[2] = 29, a__1[2] = " token. Data blocks follow a ";
    begdat_(ch__2, (ftnlen)10);
    i__1[3] = 10, a__1[3] = ch__2;
    s_cat(pck + 34320, a__1, i__1, &c__4, (ftnlen)80);
    s_copy(pck + 34400, "     token. In order to be recognized, each of thes"
	    "e tokens", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 34480, "     must be placed on a line by itself.", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 34560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 34640, "     The portion of the file preceding the first da"
	    "ta block is treated", (ftnlen)80, (ftnlen)70);
/* Writing concatenation */
    i__2[0] = 55, a__2[0] = "     as a comment block; it doesn't require an "
	    "initial ";
    begtxt_(ch__1, (ftnlen)10);
    i__2[1] = 10, a__2[1] = ch__1;
    s_cat(pck + 34720, a__2, i__2, &c__2, (ftnlen)80);
    s_copy(pck + 34800, "     token.", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 34880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 34960, "     This file identifies data using a series of", (
	    ftnlen)80, (ftnlen)48);
    s_copy(pck + 35040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 35120, "        KEYWORD = VALUE", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 35200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 35280, "     assignments. The left hand side of each assign"
	    "ment is a", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 35360, "     \"kernel variable\" name; the right hand side "
	    "is an associated value", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 35440, "     or list of values. The SPICE subroutine API al"
	    "lows SPICE routines", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 35520, "     and user applications to retrieve the set of v"
	    "alues associated", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 35600, "     with each kernel variable name.", (ftnlen)80, (
	    ftnlen)36);
    s_copy(pck + 35680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 35760, "     Kernel variable names are case-sensitive and a"
	    "re limited to", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 35840, "     32 characters in length.", (ftnlen)80, (ftnlen)
	    29);
    s_copy(pck + 35920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 36000, "     Numeric values may be integer or floating poin"
	    "t. String values", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 36080, "     are normally limited to 80 characters in lengt"
	    "h; however, SPICE", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 36160, "     provides a mechanism for identifying longer,"
	    " \"continued\" strings.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 36240, "     See the SPICE routine STPOOL for details.", (
	    ftnlen)80, (ftnlen)46);
    s_copy(pck + 36320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 36400, "     String values are single quoted.", (ftnlen)80, (
	    ftnlen)37);
    s_copy(pck + 36480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 36560, "     When the right hand side of an assignment is a"
	    " list of values,", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 36640, "     the list items may be separated by commas or s"
	    "imply by blanks.", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 36720, "     The list must be bracketed by parentheses. Exa"
	    "mple:", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 36800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 36880, "        BODY399_RADII = ( 6378.14 6378.14 6356.75 )",
	     (ftnlen)80, (ftnlen)51);
    s_copy(pck + 36960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 37040, "     Any blanks preceding or following keyword name"
	    "s, values and equal", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 37120, "     signs are ignored.", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 37200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 37280, "     Assignments may be spread over multiple lines,"
	    " for example:", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 37360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 37440, "        BODY399_RADII = ( 6378.14", (ftnlen)80, (
	    ftnlen)33);
    s_copy(pck + 37520, "                          6378.14", (ftnlen)80, (
	    ftnlen)33);
    s_copy(pck + 37600, "                          6356.75 )", (ftnlen)80, (
	    ftnlen)35);
    s_copy(pck + 37680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 37760, "     This file may contain blank lines anywhere. No"
	    "n-printing", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 37840, "     characters including TAB should not be present"
	    " in the file: the", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 37920, "     presence of such characters may cause formatti"
	    "ng errors when the", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 38000, "     file is viewed.", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 38080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 38160, "Time systems and reference frames", (ftnlen)80, (
	    ftnlen)33);
    s_copy(pck + 38240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 38320, "     The 2006 IAU/IAG Working Group Report [1] stat"
	    "es the time scale", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 38400, "     used as the independent variable for the rotat"
	    "ion formulas is", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 38480, "     Barycentric Dynamical Time (TDB) and that the "
	    "epoch of variable", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 38560, "     quantities is J2000 TDB (2000 Jan 1 12:00 TDB)"
	    ". Throughout SPICE", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 38640, "     documentation and in this file, we use the nam"
	    "es \"J2000 TDB\" and", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 38720, "     \"J2000\" for this epoch. The name \"J2000.0\""
	    " is equivalent.", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 38800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 38880, "     SPICE documentation refers to the time system "
	    "used in this file", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 38960, "     as either \"ET\" or \"TDB.\" SPICE software ma"
	    "kes no distinction", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 39040, "     between TDB and the time system associated wit"
	    "h the independent", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 39120, "     variable of the JPL planetary ephemerides T_ep"
	    "h.", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 39200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 39280, "     The inertial reference frame used for the rota"
	    "tional elements in", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 39360, "     this file is identified by [1] as the ICRF (In"
	    "ternational", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 39440, "     Celestial Reference Frame).", (ftnlen)80, (
	    ftnlen)32);
    s_copy(pck + 39520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 39600, "     The SPICE PCK software that reads this file us"
	    "es the label \"J2000\"", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 39680, "     to refer to the ICRF; this is actually a misla"
	    "beling which has", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 39760, "     been retained in the interest of backward comp"
	    "atibility. Using", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 39840, "     data from this file, by means of calls to the "
	    "SPICE frame", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 39920, "     transformation routines, will actually compute"
	    " orientation", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 40000, "     relative to the ICRF.", (ftnlen)80, (ftnlen)26);
    s_copy(pck + 40080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 40160, "     The difference between the J2000 frame and the"
	    " ICRF is", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 40240, "     on the order of tens of milliarcseconds and is"
	    " well below the", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 40320, "     accuracy level of the formulas in this file.", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 40400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 40480, "Orientation models", (ftnlen)80, (ftnlen)18);
    s_copy(pck + 40560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 40640, "     All of the orientation models use three Euler "
	    "angles to describe", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 40720, "     the orientation of the coordinate axes of the"
	    " \"Body Equator and", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 40800, "     Prime Meridian\" system with respect to an ine"
	    "rtial system. By", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 40880, "     default, the inertial system is the ICRF (labe"
	    "led as \"J2000\"), but", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 40960, "     other frames can be specified in the file. See"
	    " the PCK Required", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 41040, "     Reading for details.", (ftnlen)80, (ftnlen)25);
    s_copy(pck + 41120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 41200, "     The first two angles, in order, are the ICRF r"
	    "ight ascension and", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 41280, "     declination (henceforth RA and DEC) of the nor"
	    "th pole of a body as", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 41360, "     a function of time. The third angle is the pri"
	    "me meridian location", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 41440, "     (represented by \"W\"), which is expressed as "
	    "a rotation about the", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 41520, "     north pole, and is also a function of time.", (
	    ftnlen)80, (ftnlen)48);
    s_copy(pck + 41600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 41680, "     For each body, the expressions for the north p"
	    "ole's right", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 41760, "     ascension and declination, as well as prime me"
	    "ridian location, are", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 41840, "     sums (as far as the models that appear in this"
	    " file are concerned)", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 41920, "     of quadratic polynomials and trigonometric pol"
	    "ynomials, where the", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 42000, "     independent variable is time.", (ftnlen)80, (
	    ftnlen)34);
    s_copy(pck + 42080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 42160, "     In this file, the time arguments in expression"
	    "s always refer to", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 42240, "     Barycentric Dynamical Time (TDB), measured in "
	    "centuries or days", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 42320, "     past a reference epoch. By default, the refere"
	    "nce epoch is the", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 42400, "     J2000 epoch, which is Julian ephemeris date 24"
	    "51545.0, but other", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 42480, "     epochs can be specified in the file. See the P"
	    "CK Required Reading", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 42560, "     for details.", (ftnlen)80, (ftnlen)17);
    s_copy(pck + 42640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 42720, "     Orientation models for satellites and some pla"
	    "nets (including", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 42800, "     Jupiter) involve both polynomial terms and tri"
	    "gonometric terms.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 42880, "     The arguments of the trigonometric terms are l"
	    "inear polynomials.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 42960, "     In this file, we call the arguments of these t"
	    "rigonometric terms", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 43040, "     \"nutation precession angles.\"", (ftnlen)80, (
	    ftnlen)34);
    s_copy(pck + 43120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 43200, "     Example: 2006 IAU Model for orientation of Jup"
	    "iter.  Note that", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 43280, "     these values are used as an example only; see "
	    "the data area below", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 43360, "     for current values.", (ftnlen)80, (ftnlen)24);
    s_copy(pck + 43440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 43520, "        Right ascension", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 43600, "        ---------------", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 43680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 43760, "        alpha   =  268.056595 - 0.006499 T        +"
	    "  0.000117 sin(Ja)", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 43840, "             0                + 0.000938 sin(Jb)  +"
	    "  0.001432 sin(Jc)", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 43920, "                              + 0.000030 sin(Jd)  +"
	    "  0.002150 sin(Je)", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 44000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 44080, "        Declination", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 44160, "        -----------", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 44240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 44320, "        delta   =   64.495303 + 0.002413 T        +"
	    "  0.000050 cos(Ja)", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 44400, "             0                + 0.000404 cos(Jb)  +"
	    "  0.000617 cos(Jc)", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 44480, "                              - 0.000013 cos(Jd)  +"
	    "  0.000926 cos(Je)", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 44560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 44640, "        Prime meridian", (ftnlen)80, (ftnlen)22);
    s_copy(pck + 44720, "        --------------", (ftnlen)80, (ftnlen)22);
    s_copy(pck + 44800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 44880, "        W       =  284.95  + 870.5366420 d", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 44960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 45040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 45120, "     Here", (ftnlen)80, (ftnlen)9);
    s_copy(pck + 45200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 45280, "        T represents centuries past J2000 ( TDB ),", 
	    (ftnlen)80, (ftnlen)50);
    s_copy(pck + 45360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 45440, "        d represents days past J2000 ( TDB ).", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 45520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 45600, "        Ja-Je are nutation precession angles.", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 45680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 45760, "     In this file, the polynomials' coefficients ab"
	    "ove are assigned", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 45840, "     to kernel variable names (left-hand-side symbo"
	    "ls) as follows", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 45920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 46000, "        BODY599_POLE_RA        = (   268.056595    "
	    " -0.006499       0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 46080, "        BODY599_POLE_DEC       = (    64.495303    "
	    "  0.002413       0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 46160, "        BODY599_PM             = (   284.95        "
	    "870.5366420      0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 46240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 46320, "     and the trigonometric polynomials' coefficient"
	    "s are assigned", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 46400, "     as follows", (ftnlen)80, (ftnlen)15);
    s_copy(pck + 46480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 46560, "        BODY599_NUT_PREC_RA  = ( 0. 0. 0. 0. 0. 0. "
	    "0. 0. 0. 0.  0.000117", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 46640, "                                                   "
	    "             0.000938", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 46720, "                                                   "
	    "             0.001432", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 46800, "                                                   "
	    "             0.000030", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 46880, "                                                   "
	    "             0.002150 )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 46960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 47040, "        BODY599_NUT_PREC_DEC = ( 0. 0. 0. 0. 0. 0. "
	    "0. 0. 0. 0.  0.000050", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 47120, "                                                   "
	    "             0.000404", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 47200, "                                                   "
	    "             0.000617", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 47280, "                                                   "
	    "            -0.000013", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 47360, "                                                   "
	    "             0.000926 )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 47440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 47520, "        BODY599_NUT_PREC_PM  = ( 0. 0. 0. 0. 0. 0. "
	    "0. 0. 0. 0.  0.0", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 47600, "                                                   "
	    "             0.0", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 47680, "                                                   "
	    "             0.0", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 47760, "                                                   "
	    "             0.0", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 47840, "                                                   "
	    "             0.0  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 47920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 48000, "     Note the number \"599\"; this is the NAIF ID c"
	    "ode for Jupiter.", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 48080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 48160, "     In this file, the polynomial expressions for t"
	    "he nutation", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 48240, "     precession angles are listed along with the pl"
	    "anet's RA, DEC, and", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 48320, "     prime meridian terms. Below are the 2006 IAU n"
	    "utation precession", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 48400, "     angles for the Jupiter system.", (ftnlen)80, (
	    ftnlen)35);
    s_copy(pck + 48480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 48560, "        J1  =   73.32      +  91472.9 T", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 48640, "        J2  =   24.62      +  45137.2 T", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 48720, "        J3  =  283.90      +   4850.7 T", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 48800, "        J4  =  355.80      +   1191.3 T", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 48880, "        J5  =  119.90      +    262.1 T", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 48960, "        J6  =  229.80      +     64.3 T", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 49040, "        J7  =  352.25      +   2382.6 T", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 49120, "        J8  =  113.35      +   6070.0 T", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 49200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 49280, "        J9  =  146.64      + 182945.8 T", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 49360, "        J10 =   49.24      +  90274.4 T", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 49440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 49520, "        Ja  =   99.360714  +   4850.4046 T", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 49600, "        Jb  =  175.895369  +   1191.9605 T", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 49680, "        Jc  =  300.323162  +    262.5475 T", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 49760, "        Jd  =  114.012305  +   6070.2476 T", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 49840, "        Je  =   49.511251  +     64.3000 T", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 49920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 50000, "     Here", (ftnlen)80, (ftnlen)9);
    s_copy(pck + 50080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 50160, "        T represents centuries past J2000 ( TDB )", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 50240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 50320, "        J1-J10 and Ja-Je are the nutation precessio"
	    "n angles. The angles", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 50400, "        J9 and J10 are equal to 2*J1 and 2*J2, resp"
	    "ectively.", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 50480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 50560, "        Angles J9 and J10 are not present in [1]; t"
	    "hey have been added", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 50640, "        to fit the terms 2*J1 and 2*J2, which appea"
	    "r in the orientation", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 50720, "        models of several satellites, into a form t"
	    "hat can be accepted", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 50800, "        by the PCK system.", (ftnlen)80, (ftnlen)26);
    s_copy(pck + 50880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 50960, "     The assignment of the nutation precession angl"
	    "es for the", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 51040, "     Jupiter system is as follows:", (ftnlen)80, (
	    ftnlen)34);
    s_copy(pck + 51120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 51200, "        BODY5_NUT_PREC_ANGLES  = (    73.32      91"
	    "472.9", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 51280, "                                      24.62      45"
	    "137.2", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 51360, "                                     283.90       4"
	    "850.7", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 51440, "                                     355.80       1"
	    "191.3", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 51520, "                                     119.90        "
	    "262.1", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 51600, "                                     229.80        "
	    " 64.3", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 51680, "                                     352.25       2"
	    "382.6", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 51760, "                                     113.35       6"
	    "070.0", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 51840, "                                     146.64     182"
	    "945.8", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 51920, "                                      49.24      90"
	    "274.4", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 52000, "                                      99.360714   4"
	    "850.4046", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 52080, "                                     175.895369   1"
	    "191.9605", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 52160, "                                     300.323162    "
	    "262.5475", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 52240, "                                     114.012305   6"
	    "070.2476", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 52320, "                                      49.511251    "
	    " 64.3000  )", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 52400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 52480, "     You'll see an additional symbol grouped with t"
	    "he ones listed", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 52560, "     above; it is", (ftnlen)80, (ftnlen)17);
    s_copy(pck + 52640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 52720, "        BODY599_LONG_AXIS", (ftnlen)80, (ftnlen)25);
    s_copy(pck + 52800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 52880, "     This term is zero for all bodies except Mars. "
	    "It represents the", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 52960, "     angular offset between the meridian containing"
	    " the longest axis of", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 53040, "     the triaxial ellipsoid used to model a body's "
	    "surface and the", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 53120, "     prime meridian of the body.", (ftnlen)80, (
	    ftnlen)32);
    s_copy(pck + 53200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 53280, "     The pattern of the formulas for satellite orie"
	    "ntation is similar", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 53360, "     to that for Jupiter. Example: 2006 IAU values "
	    "for Io. Again, these", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 53440, "     values are used as an example only; see the da"
	    "ta area below for", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 53520, "     current values.", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 53600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 53680, "        Right ascension", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 53760, "        ---------------", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 53840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 53920, "        alpha  = 268.05  -  0.009 T  + 0.094 sin(J3"
	    ")  +  0.024 sin(J4)", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 54000, "             0", (ftnlen)80, (ftnlen)14);
    s_copy(pck + 54080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 54160, "        Declination", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 54240, "        -----------", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 54320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 54400, "        delta  =  64.50  +  0.003 T  + 0.040 cos(J3"
	    ")  +  0.011 cos(J4)", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 54480, "             0", (ftnlen)80, (ftnlen)14);
    s_copy(pck + 54560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 54640, "        Prime meridian", (ftnlen)80, (ftnlen)22);
    s_copy(pck + 54720, "        --------------", (ftnlen)80, (ftnlen)22);
    s_copy(pck + 54800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 54880, "        W      = 200.39  +  203.4889538 d  -  0.085"
	    " sin(J3)  -  0.022 sin(J4)", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 54960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 55040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 55120, "        d represents days past J2000.", (ftnlen)80, (
	    ftnlen)37);
    s_copy(pck + 55200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 55280, "        J3 and J4 are nutation precession angles.", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 55360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 55440, "     The polynomial terms are assigned to symbols b"
	    "y the statements", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 55520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 55600, "        BODY501_POLE_RA       = (  268.05          "
	    "-0.009      0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 55680, "        BODY501_POLE_DEC      = (   64.50          "
	    " 0.003      0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 55760, "        BODY501_PM            = (  200.39         2"
	    "03.4889538  0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 55840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 55920, "     The coefficients of the trigonometric terms ar"
	    "e assigned to symbols by", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 56000, "     the statements", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 56080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 56160, "        BODY501_NUT_PREC_RA   = (    0.   0.     0."
	    "094    0.024   )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 56240, "        BODY501_NUT_PREC_DEC  = (    0.   0.     0."
	    "040    0.011   )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 56320, "        BODY501_NUT_PREC_PM   = (    0.   0.    -0."
	    "085   -0.022   )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 56400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 56480, "     501 is the NAIF ID code for Io.", (ftnlen)80, (
	    ftnlen)36);
    s_copy(pck + 56560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 56640, "     SPICE software expects the models for satellit"
	    "e orientation to", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 56720, "     follow the form of the model shown here: the p"
	    "olynomial portions of the", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 56800, "     RA, DEC, and W expressions are expected to be "
	    "quadratic, the", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 56880, "     trigonometric terms for RA and W (satellite pr"
	    "ime meridian) are expected", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 56960, "     to be linear combinations of sines of nutation"
	    " precession angles, the", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 57040, "     trigonometric terms for DEC are expected to be"
	    " linear combinations of", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 57120, "     cosines of nutation precession angles, and the"
	    " polynomials for the", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 57200, "     nutation precession angles themselves are expe"
	    "cted to be linear.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 57280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 57360, "     Eventually, the software will handle more comp"
	    "lex expressions, we", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 57440, "     expect.", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 57520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 57600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 57680, "Shape models", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 57760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 57840, "     There is only one kind of shape model supporte"
	    "d by the SPICE Toolkit", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 57920, "     software at present: the triaxial ellipsoid. T"
	    "he 2006 IAU report does", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 58000, "     not use any other models, except in the case o"
	    "f Mars, where", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 58080, "     separate values are given for the north and so"
	    "uth polar radii.", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 58160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 58240, "     For each body, three radii are listed:  The fi"
	    "rst number is", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 58320, "     the largest equatorial radius (the length of t"
	    "he semi-axis", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 58400, "     containing the prime meridian), the second num"
	    "ber is the smaller", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 58480, "     equatorial radius, and the third is the polar "
	    "radius.", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 58560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 58640, "     Example: Radii of the Earth.", (ftnlen)80, (
	    ftnlen)33);
    s_copy(pck + 58720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 58800, "        BODY399_RADII     = (     6378.14    6378.1"
	    "4      6356.75   )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 58880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 58960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 59040, "Body Numbers and Names", (ftnlen)80, (ftnlen)22);
    s_copy(pck + 59120, "---------------------------------------------------"
	    "-----", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 59200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 59280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 59360, "        1  Mercury barycenter", (ftnlen)80, (ftnlen)
	    29);
    s_copy(pck + 59440, "        2  Venus barycenter", (ftnlen)80, (ftnlen)27)
	    ;
    s_copy(pck + 59520, "        3  Earth barycenter", (ftnlen)80, (ftnlen)27)
	    ;
    s_copy(pck + 59600, "        4  Mars barycenter", (ftnlen)80, (ftnlen)26);
    s_copy(pck + 59680, "        5  Jupiter barycenter", (ftnlen)80, (ftnlen)
	    29);
    s_copy(pck + 59760, "        6  Saturn barycenter", (ftnlen)80, (ftnlen)
	    28);
    s_copy(pck + 59840, "        7  Uranus barycenter", (ftnlen)80, (ftnlen)
	    28);
    s_copy(pck + 59920, "        8  Neptune barycenter", (ftnlen)80, (ftnlen)
	    29);
    s_copy(pck + 60000, "        9  Pluto barycenter", (ftnlen)80, (ftnlen)27)
	    ;
    s_copy(pck + 60080, "        10 Sun", (ftnlen)80, (ftnlen)14);
    s_copy(pck + 60160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 60240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 60320, "        199 Mercury", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 60400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 60480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 60560, "        299 Venus", (ftnlen)80, (ftnlen)17);
    s_copy(pck + 60640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 60720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 60800, "        399 Earth", (ftnlen)80, (ftnlen)17);
    s_copy(pck + 60880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 60960, "        301 Moon", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 61040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 61120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 61200, "        499 Mars", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 61280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 61360, "        401 Phobos      402 Deimos", (ftnlen)80, (
	    ftnlen)34);
    s_copy(pck + 61440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 61520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 61600, "        599 Jupiter", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 61680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 61760, "        501 Io          502 Europa      503 Ganymed"
	    "e    504 Callisto", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 61840, "        505 Amalthea    506 Himalia     507 Elara  "
	    "     508 Pasiphae", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 61920, "        509 Sinope      510 Lysithea    511 Carme  "
	    "     512 Ananke", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 62000, "        513 Leda        514 Thebe       515 Adraste"
	    "a    516 Metis", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 62080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 62160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 62240, "        699 Saturn", (ftnlen)80, (ftnlen)18);
    s_copy(pck + 62320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 62400, "        601 Mimas       602 Enceladus   603 Tethys "
	    "     604 Dione", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 62480, "        605 Rhea        606 Titan       607 Hyperio"
	    "n    608 Iapetus", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 62560, "        609 Phoebe      610 Janus       611 Epimeth"
	    "eus  612 Helene", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 62640, "        613 Telesto     614 Calypso     615 Atlas  "
	    "     616 Prometheus", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 62720, "        617 Pandora     618 Pan", (ftnlen)80, (
	    ftnlen)31);
    s_copy(pck + 62800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 62880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 62960, "        799 Uranus", (ftnlen)80, (ftnlen)18);
    s_copy(pck + 63040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 63120, "        701 Ariel       702 Umbriel     703 Titania"
	    "     704 Oberon", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 63200, "        705 Miranda     706 Cordelia    707 Ophelia"
	    "     708 Bianca", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 63280, "        709 Cressida    710 Desdemona   711 Juliet "
	    "     712 Portia", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 63360, "        713 Rosalind    714 Belinda     715 Puck", (
	    ftnlen)80, (ftnlen)48);
    s_copy(pck + 63440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 63520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 63600, "        899 Neptune", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 63680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 63760, "        801 Triton      802 Nereid      803 Naiad  "
	    "     804 Thalassa", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 63840, "        805 Despina     806 Galatea     807 Larissa"
	    "     808 Proteus", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 63920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 64000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 64080, "        999 Pluto", (ftnlen)80, (ftnlen)17);
    s_copy(pck + 64160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 64240, "        901 Charon", (ftnlen)80, (ftnlen)18);
    s_copy(pck + 64320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 64400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 64480, "        1000005 Comet 19P/Borrelly", (ftnlen)80, (
	    ftnlen)34);
    s_copy(pck + 64560, "        1000036 Comet Halley", (ftnlen)80, (ftnlen)
	    28);
    s_copy(pck + 64640, "        1000093 Comet 9P/Tempel 1", (ftnlen)80, (
	    ftnlen)33);
    s_copy(pck + 64720, "        1000107 Comet 81P/Wild 2", (ftnlen)80, (
	    ftnlen)32);
    s_copy(pck + 64800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 64880, "        2000001 Asteroid Ceres", (ftnlen)80, (ftnlen)
	    30);
    s_copy(pck + 64960, "        2000004 Asteroid Vesta", (ftnlen)80, (ftnlen)
	    30);
    s_copy(pck + 65040, "        2000216 Asteroid Kleopatra", (ftnlen)80, (
	    ftnlen)34);
    s_copy(pck + 65120, "        2000253 Asteroid Mathilde", (ftnlen)80, (
	    ftnlen)33);
    s_copy(pck + 65200, "        2000433 Asteroid Eros", (ftnlen)80, (ftnlen)
	    29);
    s_copy(pck + 65280, "        2004179 Asteroid Toutatis", (ftnlen)80, (
	    ftnlen)33);
    s_copy(pck + 65360, "        2025143 Asteroid Itokawa", (ftnlen)80, (
	    ftnlen)32);
    s_copy(pck + 65440, "        2431010 Asteroid Ida", (ftnlen)80, (ftnlen)
	    28);
    s_copy(pck + 65520, "        9511010 Asteroid Gaspra", (ftnlen)80, (
	    ftnlen)31);
    s_copy(pck + 65600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 65680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 65760, "Orientation Constants for the Sun and Planets", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 65840, "---------------------------------------------------"
	    "-----", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 65920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 66000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 66080, "Sun", (ftnlen)80, (ftnlen)3);
    s_copy(pck + 66160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 66240, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 66320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 66400, "        Values are from the 2003 IAU report.", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 66480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 66560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 66640, "        body10_pole_ra         = (  286.13       0."
	    "          0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 66720, "        body10_pole_dec        = (   63.87       0."
	    "          0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 66800, "        body10_pm              = (   84.10      14."
	    "18440     0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 66880, "        body10_long_axis       = (    0.           "
	    "             )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 66960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 67040, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 67120, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 67200, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 67280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 67360, "        BODY10_POLE_RA         = (  286.13       0."
	    "          0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 67440, "        BODY10_POLE_DEC        = (   63.87       0."
	    "          0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 67520, "        BODY10_PM              = (   84.176     14."
	    "18440     0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 67600, "        BODY10_LONG_AXIS       = (    0.           "
	    "             )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 67680, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 67760, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 67840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 67920, "Mercury", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 68000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 68080, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 68160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 68240, "        Values are unchanged in the 2006 IAU report."
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 68320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 68400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 68480, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 68560, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 68640, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 68720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 68800, "        BODY199_POLE_RA          = (  281.01     -0"
	    ".033      0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 68880, "        BODY199_POLE_DEC         = (   61.45     -0"
	    ".005      0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 68960, "        BODY199_PM               = (  329.548     6"
	    ".1385025  0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 69040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 69120, "        BODY199_LONG_AXIS        = (    0.         "
	    "               )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 69200, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 69280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 69360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 69440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 69520, "Venus", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 69600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 69680, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 69760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 69840, "        Values are unchanged in the 2006 IAU report."
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 69920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 70000, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 70080, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 70160, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 70240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 70320, "        BODY299_POLE_RA          = (  272.76       "
	    "0.          0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 70400, "        BODY299_POLE_DEC         = (   67.16       "
	    "0.          0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 70480, "        BODY299_PM               = (  160.20      -"
	    "1.4813688   0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 70560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 70640, "        BODY299_LONG_AXIS        = (    0.         "
	    "               )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 70720, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 70800, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 70880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 70960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 71040, "Earth", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 71120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 71200, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 71280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 71360, "        Values are unchanged in the 2006 report.", (
	    ftnlen)80, (ftnlen)48);
    s_copy(pck + 71440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 71520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 71600, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 71680, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 71760, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 71840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 71920, "        BODY399_POLE_RA        = (    0.      -0.64"
	    "1         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 72000, "        BODY399_POLE_DEC       = (   90.      -0.55"
	    "7         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 72080, "        BODY399_PM             = (  190.147  360.98"
	    "56235     0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 72160, "        BODY399_LONG_AXIS      = (    0.           "
	    "             )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 72240, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 72320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 72400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 72480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 72560, "        Nutation precession angles for the Earth-Mo"
	    "on system:", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 72640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 72720, "           The linear coefficients have been scaled"
	    " up from degrees/day", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 72800, "           to degrees/century, because the SPICELIB"
	    " PCK reader expects", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 72880, "           these units.  The original constants wer"
	    "e:", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 72960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 73040, "                                    125.045D0   -0."
	    "0529921D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 73120, "                                    250.089D0   -0."
	    "1059842D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 73200, "                                    260.008D0   13."
	    "0120009D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 73280, "                                    176.625D0   13."
	    "3407154D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 73360, "                                    357.529D0    0."
	    "9856003D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 73440, "                                    311.589D0   26."
	    "4057084D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 73520, "                                    134.963D0   13."
	    "0649930D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 73600, "                                    276.617D0    0."
	    "3287146D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 73680, "                                     34.226D0    1."
	    "7484877D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 73760, "                                     15.134D0   -0."
	    "1589763D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 73840, "                                    119.743D0    0."
	    "0036096D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 73920, "                                    239.961D0    0."
	    "1643573D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 74000, "                                     25.053D0   12."
	    "9590088D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 74080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 74160, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 74240, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 74320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 74400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 74480, "        BODY3_NUT_PREC_ANGLES  = (  125.045        "
	    " -1935.5364525000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 74560, "                                    250.089        "
	    " -3871.0729050000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 74640, "                                    260.008        "
	    "475263.3328725000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 74720, "                                    176.625        "
	    "487269.6299850000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 74800, "                                    357.529        "
	    " 35999.0509575000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 74880, "                                    311.589        "
	    "964468.4993100000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 74960, "                                    134.963        "
	    "477198.8693250000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 75040, "                                    276.617        "
	    " 12006.3007650000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 75120, "                                     34.226        "
	    " 63863.5132425000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 75200, "                                     15.134        "
	    " -5806.6093575000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 75280, "                                    119.743        "
	    "   131.8406400000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 75360, "                                    239.961        "
	    "  6003.1503825000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 75440, "                                     25.053        "
	    "473327.7964200000 )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 75520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 75600, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 75680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 75760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 75840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 75920, "     Earth north geomagnetic centered dipole:", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 76000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 76080, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 76160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 76240, "           Values are from [7].  Note the year of p"
	    "ublication was 1971.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 76320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 76400, "           body399_mag_north_pole_lon  =  ( -69.761"
	    " )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 76480, "           body399_mag_north_pole_lat  =  (  78.565"
	    " )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 76560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 76640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 76720, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 76800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 76880, "           The north dipole location is time-varyin"
	    "g.  The values shown", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 76960, "           below, taken from [8], represent a discr"
	    "ete sampling of the", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 77040, "           north dipole location from 1945 to 2000."
	    " The terms DGRF and", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 77120, "           IGRF refer to, respectively, \"Definitiv"
	    "e Geomagnetic", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 77200, "           Reference Field\" and \"International Ge"
	    "omagnetic Reference", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 77280, "           Field.\"  See references [6], [8], and ["
	    "9] for details.", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 77360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 77440, "           Coordinates are planetocentric.", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 77520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 77600, "             Data source    Lat      Lon", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 77680, "             -----------   -----    ------", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 77760, "              DGRF 1945    78.47    291.47", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 77840, "              DGRF 1950    78.47    291.15", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 77920, "              DGRF 1955    78.46    290.84", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 78000, "              DGRF 1960    78.51    290.53", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 78080, "              DGRF 1965    78.53    290.15", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 78160, "              DGRF 1970    78.59    289.82", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 78240, "              DGRF 1975    78.69    289.53", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 78320, "              DGRF 1980    78.81    289.24", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 78400, "              DGRF 1985    78.97    289.10", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 78480, "              DGRF 1990    79.13    288.89", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 78560, "              IGRF 1995    79.30    288.59", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 78640, "              IGRF 2000    79.54    288.43", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 78720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 78800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 78880, "        Values are given for the epoch 2000 and are"
	    " from the final row", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 78960, "        of the above table, which is from [8]. As s"
	    "hown by the table", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 79040, "        these values constitute a low-accuracy appr"
	    "oximation for epochs", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 79120, "        not close to 2000.", (ftnlen)80, (ftnlen)26);
    s_copy(pck + 79200, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 79280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 79360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 79440, "        BODY399_N_GEOMAG_CTR_DIPOLE_LON  =  ( 288.4"
	    "3 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 79520, "        BODY399_N_GEOMAG_CTR_DIPOLE_LAT  =  (  79.5"
	    "4 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 79600, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 79680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 79760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 79840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 79920, "Mars", (ftnlen)80, (ftnlen)4);
    s_copy(pck + 80000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 80080, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 80160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 80240, "        Values are unchanged in the 2006 IAU report."
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 80320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 80400, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 80480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 80560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 80640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 80720, "        BODY499_POLE_RA          = (  317.68143   -"
	    "0.1061      0.  )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 80800, "        BODY499_POLE_DEC         = (   52.88650   -"
	    "0.0609      0.  )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 80880, "        BODY499_PM               = (  176.630    35"
	    "0.89198226  0.  )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 80960, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 81040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 81120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 81200, "        Source [5] specifies the following value fo"
	    "r the lambda_a term", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 81280, "        (BODY499_LONG_AXIS ) for Mars. This term is"
	    " the POSITIVE EAST", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 81360, "        LONGITUDE, measured from the prime meridian"
	    ", of the meridian", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 81440, "        containing the longest axis of the referenc"
	    "e ellipsoid.", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 81520, "        (CAUTION: previous values were POSITIVE WES"
	    "T.)", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 81600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 81680, "           body499_long_axis        = (  252.  )", (
	    ftnlen)80, (ftnlen)48);
    s_copy(pck + 81760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 81840, "        We list this lambda_a value for completenes"
	    "s. The IAU report", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 81920, "        [1] gives equal values for both equatorial "
	    "radii, so the", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 82000, "        lambda_a offset does not apply to the IAU m"
	    "odel.", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 82080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 82160, "        The 2003 IAU report defines M2, the second "
	    "nutation precession angle,", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 82240, "        by:", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 82320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 82400, "                                                2", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 82480, "           192.93  +  1128.4096700 d  +  8.864 T", (
	    ftnlen)80, (ftnlen)48);
    s_copy(pck + 82560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 82640, "        We truncate the M2 series to a linear expre"
	    "ssion, because the PCK", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 82720, "        software cannot handle the quadratic term.", 
	    (ftnlen)80, (ftnlen)50);
    s_copy(pck + 82800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 82880, "        Again, the linear terms are scaled by 36525"
	    ".0:", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 82960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 83040, "            -0.4357640000000000       -->     -1591"
	    "6.28010000000", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 83120, "          1128.409670000000           -->   4121516"
	    "3.19675000", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 83200, "            -1.8151000000000000E-02   -->       -66"
	    "2.9652750000000", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 83280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 83360, "        We also introduce a fourth nutation precess"
	    "ion angle, which", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 83440, "        is the pi/2-complement of the third angle. "
	    " This angle is used", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 83520, "        in computing the prime meridian location fo"
	    "r Deimos.  See the", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 83600, "        discussion of this angle below in the secti"
	    "on containing orientation", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 83680, "        constants for Deimos.", (ftnlen)80, (ftnlen)
	    29);
    s_copy(pck + 83760, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 83840, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 83920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 84000, "        BODY4_NUT_PREC_ANGLES  = (  169.51     -159"
	    "16.2801", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 84080, "                                    192.93   412151"
	    "63.19675", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 84160, "                                     53.47       -6"
	    "62.965275", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 84240, "                                     36.53        6"
	    "62.965275  )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 84320, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 84400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 84480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 84560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 84640, "Jupiter", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 84720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 84800, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 84880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 84960, "        Values are from the 2003 IAU report.", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 85040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 85120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 85200, "           body599_pole_ra        = (   268.05     "
	    " -0.009       0. )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 85280, "           body599_pole_dec       = (    64.49     "
	    "  0.003       0. )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 85360, "           body599_pm             = (   284.95     "
	    "870.5366420   0. )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 85440, "           body599_long_axis      = (     0.       "
	    "                 )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 85520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 85600, "           body5_nut_prec_angles  = (    73.32   91"
	    "472.9", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 85680, "                                         24.62   45"
	    "137.2", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 85760, "                                        283.90    4"
	    "850.7", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 85840, "                                        355.80    1"
	    "191.3", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 85920, "                                        119.90     "
	    "262.1", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 86000, "                                        229.80     "
	    " 64.3", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 86080, "                                        352.35    2"
	    "382.6", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 86160, "                                        113.35    6"
	    "070.0", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 86240, "                                        146.64  182"
	    "945.8", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 86320, "                                         49.24   90"
	    "274.4  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 86400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 86480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 86560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 86640, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 86720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 86800, "        The number of nutation precession angles is"
	    " 15. The ninth and", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 86880, "        tenth are twice the first and second, respe"
	    "ctively. The", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 86960, "        eleventh through fifteenth correspond to an"
	    "gles JA-JE in", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 87040, "        the 2006 IAU report; angles JA-JE were not "
	    "used prior to that", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 87120, "        report.", (ftnlen)80, (ftnlen)15);
    s_copy(pck + 87200, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 87280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 87360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 87440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 87520, "        BODY599_POLE_RA        = (   268.056595    "
	    " -0.006499       0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 87600, "        BODY599_POLE_DEC       = (    64.495303    "
	    "  0.002413       0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 87680, "        BODY599_PM             = (   284.95        "
	    "870.5366420      0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 87760, "        BODY599_LONG_AXIS      = (     0.          "
	    "              )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 87840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 87920, "        BODY599_NUT_PREC_RA  = ( 0. 0. 0. 0. 0. 0. "
	    "0. 0. 0. 0.  0.000117", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 88000, "                                                   "
	    "             0.000938", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 88080, "                                                   "
	    "             0.001432", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 88160, "                                                   "
	    "             0.000030", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 88240, "                                                   "
	    "             0.002150 )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 88320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 88400, "        BODY599_NUT_PREC_DEC = ( 0. 0. 0. 0. 0. 0. "
	    "0. 0. 0. 0.  0.000050", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 88480, "                                                   "
	    "             0.000404", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 88560, "                                                   "
	    "             0.000617", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 88640, "                                                   "
	    "            -0.000013", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 88720, "                                                   "
	    "             0.000926 )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 88800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 88880, "        BODY599_NUT_PREC_PM  = ( 0. 0. 0. 0. 0. 0. "
	    "0. 0. 0. 0.  0.0", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 88960, "                                                   "
	    "             0.0", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 89040, "                                                   "
	    "             0.0", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 89120, "                                                   "
	    "             0.0", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 89200, "                                                   "
	    "             0.0  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 89280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 89360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 89440, "        BODY5_NUT_PREC_ANGLES  = (    73.32      91"
	    "472.9", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 89520, "                                      24.62      45"
	    "137.2", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 89600, "                                     283.90       4"
	    "850.7", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 89680, "                                     355.80       1"
	    "191.3", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 89760, "                                     119.90        "
	    "262.1", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 89840, "                                     229.80        "
	    " 64.3", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 89920, "                                     352.25       2"
	    "382.6", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 90000, "                                     113.35       6"
	    "070.0", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 90080, "                                     146.64     182"
	    "945.8", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 90160, "                                      49.24      90"
	    "274.4", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 90240, "                                      99.360714   4"
	    "850.4046", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 90320, "                                     175.895369   1"
	    "191.9605", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 90400, "                                     300.323162    "
	    "262.5475", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 90480, "                                     114.012305   6"
	    "070.2476", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 90560, "                                      49.511251    "
	    " 64.3000  )", (ftnlen)80, (ftnlen)62);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 90640, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 90720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 90800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 90880, "Saturn", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 90960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 91040, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 91120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 91200, "        Values are unchanged in the 2006 IAU report."
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 91280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 91360, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 91440, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 91520, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 91600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 91680, "        BODY699_POLE_RA        = (    40.589    -0."
	    "036      0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 91760, "        BODY699_POLE_DEC       = (    83.537    -0."
	    "004      0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 91840, "        BODY699_PM             = (    38.90    810."
	    "7939024  0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 91920, "        BODY699_LONG_AXIS      = (     0.          "
	    "             )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 92000, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 92080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 92160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 92240, "        The first seven angles given here are the a"
	    "ngles S1", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 92320, "        through S7 from the 2000 report; the eighth"
	    " and", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 92400, "        ninth angles are 2*S1 and 2*S2, respectivel"
	    "y.", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 92480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 92560, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 92640, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 92720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 92800, "        BODY6_NUT_PREC_ANGLES  = (  353.32   75706.7"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 92880, "                                     28.72   75706.7"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 92960, "                                    177.40  -36505.5"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 93040, "                                    300.00   -7225.9"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 93120, "                                    316.45     506.2"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 93200, "                                    345.20   -1016.3"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 93280, "                                     29.80     -52.1"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 93360, "                                    706.64  151413.4"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 93440, "                                     57.44  151413."
	    "4  )", (ftnlen)80, (ftnlen)55);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 93520, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 93600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 93680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 93760, "Uranus", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 93840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 93920, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 94000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 94080, "        Values are unchanged in the 2006 IAU report."
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 94160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 94240, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 94320, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 94400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 94480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 94560, "        BODY799_POLE_RA        = (  257.311     0. "
	    "        0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 94640, "        BODY799_POLE_DEC       = (  -15.175     0. "
	    "        0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 94720, "        BODY799_PM             = (  203.81   -501.1"
	    "600928  0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 94800, "        BODY799_LONG_AXIS      = (    0.           "
	    "            )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 94880, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 94960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 95040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 95120, "        The first 16 angles given here are the angl"
	    "es U1", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 95200, "        through U16 from the 2000 report; the 17th "
	    "and", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 95280, "        18th angles are 2*U11 and 2*U12, respective"
	    "ly.", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 95360, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 95440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 95520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 95600, "        BODY7_NUT_PREC_ANGLES  = (  115.75   54991."
	    "87", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 95680, "                                    141.69   41887."
	    "66", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 95760, "                                    135.03   29927."
	    "35", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 95840, "                                     61.77   25733."
	    "59", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 95920, "                                    249.32   24471."
	    "46", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 96000, "                                     43.86   22278."
	    "41", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 96080, "                                     77.66   20289."
	    "42", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 96160, "                                    157.36   16652."
	    "76", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 96240, "                                    101.81   12872."
	    "63", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 96320, "                                    138.64    8061."
	    "81", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 96400, "                                    102.23   -2024."
	    "22", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 96480, "                                    316.41    2863."
	    "96", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 96560, "                                    304.01     -51."
	    "94", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 96640, "                                    308.71     -93."
	    "17", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 96720, "                                    340.82     -75."
	    "32", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 96800, "                                    259.14    -504."
	    "81", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 96880, "                                    204.46   -4048."
	    "44", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 96960, "                                    632.82    5727."
	    "92     )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 97040, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 97120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 97200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 97280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 97360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 97440, "Neptune", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 97520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 97600, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 97680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 97760, "        Values are unchanged in the 2006 IAU report."
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 97840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 97920, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 98000, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 98080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 98160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 98240, "           BODY899_POLE_RA        = (  299.36     0"
	    ".         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 98320, "           BODY899_POLE_DEC       = (   43.46     0"
	    ".         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 98400, "           BODY899_PM             = (  253.18   536"
	    ".3128492  0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 98480, "           BODY899_LONG_AXIS      = (    0.        "
	    "             )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 98560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 98640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 98720, "           BODY899_NUT_PREC_RA    = (  0.70 0. 0. 0"
	    ". 0. 0. 0. 0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 98800, "           BODY899_NUT_PREC_DEC   = ( -0.51 0. 0. 0"
	    ". 0. 0. 0. 0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 98880, "           BODY899_NUT_PREC_PM    = ( -0.48 0. 0. 0"
	    ". 0. 0. 0. 0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 98960, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 99040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 99120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 99200, "           The 2000 report defines the nutation pre"
	    "cession angles", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 99280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 99360, "              N, N1, N2, ... , N7", (ftnlen)80, (
	    ftnlen)33);
    s_copy(pck + 99440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 99520, "           and also uses the multiples of N1 and N7",
	     (ftnlen)80, (ftnlen)51);
    s_copy(pck + 99600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 99680, "              2*N1", (ftnlen)80, (ftnlen)18);
    s_copy(pck + 99760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 99840, "           and", (ftnlen)80, (ftnlen)14);
    s_copy(pck + 99920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 100000, "              2*N7, 3*N7, ..., 9*N7", (ftnlen)80, (
	    ftnlen)35);
    s_copy(pck + 100080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 100160, "           In this file, we treat the angles and t"
	    "heir multiples as", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 100240, "           separate angles.  In the kernel variable"
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 100320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 100400, "              BODY8_NUT_PREC_ANGLES", (ftnlen)80, (
	    ftnlen)35);
    s_copy(pck + 100480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 100560, "           the order of the angles is", (ftnlen)80, 
	    (ftnlen)37);
    s_copy(pck + 100640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 100720, "              N, N1, N2, ... , N7, 2*N1, 2*N7, 3*N"
	    "7, ..., 9*N7", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 100800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 100880, "           Each angle is defined by a linear polyn"
	    "omial, so two", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 100960, "           consecutive array elements are allocate"
	    "d for each", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 101040, "           angle.  The first term of each pair is "
	    "the constant term,", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 101120, "           the second is the linear term.", (ftnlen)
	    80, (ftnlen)41);
    s_copy(pck + 101200, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 101280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 101360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 101440, "              BODY8_NUT_PREC_ANGLES = (   357.85  "
	    "       52.316", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 101520, "                                          323.92  "
	    "    62606.6", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 101600, "                                          220.51  "
	    "    55064.2", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 101680, "                                          354.27  "
	    "    46564.5", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 101760, "                                           75.31  "
	    "    26109.4", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 101840, "                                           35.36  "
	    "    14325.4", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 101920, "                                          142.61  "
	    "     2824.6", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 102000, "                                          177.85  "
	    "       52.316", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 102080, "                                          647.840 "
	    "   125213.200", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 102160, "                                          355.700 "
	    "      104.632", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 102240, "                                          533.550 "
	    "      156.948", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 102320, "                                          711.400 "
	    "      209.264", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 102400, "                                          889.250 "
	    "      261.580", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 102480, "                                         1067.100 "
	    "      313.896", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 102560, "                                         1244.950 "
	    "      366.212", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 102640, "                                         1422.800 "
	    "      418.528", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 102720, "                                         1600.650 "
	    "      470.844   )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 102800, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 102880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 102960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 103040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 103120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 103200, "Pluto", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 103280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 103360, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 103440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 103520, "        Values are from the 2003 IAU report.", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 103600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 103680, "        BODY999_POLE_RA        = (  313.02    0.  "
	    "       0.   )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 103760, "        BODY999_POLE_DEC       = (    9.09    0.  "
	    "       0.   )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 103840, "        BODY999_PM             = (  236.77  -56.36"
	    "23195  0.   )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 103920, "        BODY999_LONG_AXIS      = (    0.          "
	    "            )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 104000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 104080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 104160, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 104240, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 104320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 104400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 104480, "        BODY999_POLE_RA        = (  312.993   0.  "
	    "        0. )", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 104560, "        BODY999_POLE_DEC       = (    6.163   0.  "
	    "        0. )", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 104640, "        BODY999_PM             = (  237.305  -56.3"
	    "625225  0. )", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 104720, "        BODY999_LONG_AXIS      = (    0.          "
	    "           )", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 104800, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 104880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 104960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 105040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 105120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 105200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 105280, "Orientation constants for the satellites", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 105360, "--------------------------------------------------"
	    "------", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 105440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 105520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 105600, "Satellites of Earth", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 105680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 105760, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 105840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 105920, "        Values are unchanged in the 2006 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 106000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 106080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 106160, "     New values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 106240, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 106320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 106400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 106480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 106560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 106640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 106720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 106800, "        BODY301_POLE_RA      = (  269.9949        "
	    "0.0031        0.      )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 106880, "        BODY301_POLE_DEC     = (   66.5392        "
	    "0.0130        0.      )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 106960, "        BODY301_PM           = (   38.3213       1"
	    "3.17635815   -1.4D-12 )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 107040, "        BODY301_LONG_AXIS    = (    0.            "
	    "                      )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 107120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 107200, "        BODY301_NUT_PREC_RA  = (   -3.8787   -0.12"
	    "04   0.0700   -0.0172", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 107280, "                                    0.0       0.00"
	    "72   0.0       0.0", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 107360, "                                    0.0      -0.00"
	    "52   0.0       0.0", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 107440, "                                    0.0043        "
	    "                      )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 107520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 107600, "        BODY301_NUT_PREC_DEC = (   1.5419     0.02"
	    "39  -0.0278    0.0068", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 107680, "                                   0.0       -0.00"
	    "29   0.0009    0.0", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 107760, "                                   0.0        0.00"
	    "08   0.0       0.0", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 107840, "                                  -0.0009         "
	    "                      )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 107920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 108000, "        BODY301_NUT_PREC_PM  = (   3.5610     0.12"
	    "08  -0.0642    0.0158", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 108080, "                                   0.0252    -0.00"
	    "66  -0.0047   -0.0046", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 108160, "                                   0.0028     0.00"
	    "52   0.0040    0.0019", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 108240, "                                  -0.0044         "
	    "                      )", (ftnlen)80, (ftnlen)73);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 108320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 108400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 108480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 108560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 108640, "Satellites of Mars", (ftnlen)80, (ftnlen)18);
    s_copy(pck + 108720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 108800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 108880, "     Phobos", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 108960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 109040, "          Old values:", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 109120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 109200, "             Values are unchanged in the 2006 IAU "
	    "report.", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 109280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 109360, "          Current values:", (ftnlen)80, (ftnlen)25);
    s_copy(pck + 109440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 109520, "            The quadratic prime meridian term is s"
	    "caled by 1/36525**2:", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 109600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 109680, "               8.864000000000000   --->   6.644300"
	    "9930565219E-09", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 109760, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 109840, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 109920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 110000, "          BODY401_POLE_RA  = ( 317.68    -0.108   "
	    "  0.                     )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 110080, "          BODY401_POLE_DEC = (  52.90    -0.061   "
	    "  0.                     )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 110160, "          BODY401_PM       = (  35.06  1128.844585"
	    "0 6.6443009930565219E-09 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 110240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 110320, "          BODY401_LONG_AXIS     = (    0.   )", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 110400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 110480, "          BODY401_NUT_PREC_RA   = (   1.79    0.  "
	    "  0.   0. )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 110560, "          BODY401_NUT_PREC_DEC  = (  -1.08    0.  "
	    "  0.   0. )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 110640, "          BODY401_NUT_PREC_PM   = (  -1.42   -0.78"
	    "  0.   0. )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 110720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 110800, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 110880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 110960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 111040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 111120, "     Deimos", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 111200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 111280, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 111360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 111440, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 111520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 111600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 111680, "        New values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 111760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 111840, "           The Deimos prime meridian expression is:"
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 111920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 112000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 112080, "                                                  "
	    "   2", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 112160, "              W = 79.41  +  285.1618970 d  -  0.52"
	    "0 T  -  2.58 sin M", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 112240, "                                                  "
	    "                  3", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 112320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 112400, "                                                  "
	    "     +  0.19 cos M .", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 112480, "                                                  "
	    "                  3", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 112560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 112640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 112720, "           At the present time, the PCK kernel sof"
	    "tware (the routine", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 112800, "           BODEUL in particular) cannot handle the"
	    " cosine term directly,", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 112880, "           but we can represent it as", (ftnlen)80, 
	    (ftnlen)37);
    s_copy(pck + 112960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 113040, "              0.19 sin M", (ftnlen)80, (ftnlen)24);
    s_copy(pck + 113120, "                        4", (ftnlen)80, (ftnlen)25);
    s_copy(pck + 113200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 113280, "           where", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 113360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 113440, "              M   =  90.D0 - M", (ftnlen)80, (
	    ftnlen)30);
    s_copy(pck + 113520, "               4              3", (ftnlen)80, (
	    ftnlen)31);
    s_copy(pck + 113600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 113680, "           Therefore, the nutation precession angl"
	    "e assignments for Phobos", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 113760, "           and Deimos contain four coefficients ra"
	    "ther than three.", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 113840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 113920, "           The quadratic prime meridian term is sc"
	    "aled by 1/36525**2:", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 114000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 114080, "              -0.5200000000000000  --->   -3.89783"
	    "00049519307E-10", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 114160, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 114240, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 114320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 114400, "           BODY402_POLE_RA       = (  316.65     -"
	    "0.108       0.           )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 114480, "           BODY402_POLE_DEC      = (   53.52     -"
	    "0.061       0.           )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 114560, "           BODY402_PM            = (   79.41    28"
	    "5.1618970  -3.897830D-10 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 114640, "           BODY402_LONG_AXIS     = (    0.        "
	    "                         )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 114720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 114800, "           BODY402_NUT_PREC_RA   = (    0.   0.   "
	    "2.98    0.   )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 114880, "           BODY402_NUT_PREC_DEC  = (    0.   0.  -"
	    "1.78    0.   )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 114960, "           BODY402_NUT_PREC_PM   = (    0.   0.  -"
	    "2.58    0.19 )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 115040, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 115120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 115200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 115280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 115360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 115440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 115520, "Satellites of Jupiter", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 115600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 115680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 115760, "     Io", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 115840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 115920, "          Old values:", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 116000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 116080, "             Values are unchanged in the 2006 IAU "
	    "report.", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 116160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 116240, "          Current values:", (ftnlen)80, (ftnlen)25);
    s_copy(pck + 116320, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 116400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 116480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 116560, "        BODY501_POLE_RA       = (  268.05         "
	    " -0.009      0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 116640, "        BODY501_POLE_DEC      = (   64.50         "
	    "  0.003      0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 116720, "        BODY501_PM            = (  200.39         "
	    "203.4889538  0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 116800, "        BODY501_LONG_AXIS     = (    0.           "
	    "                )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 116880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 116960, "        BODY501_NUT_PREC_RA   = (    0.   0.     0"
	    ".094    0.024   )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 117040, "        BODY501_NUT_PREC_DEC  = (    0.   0.     0"
	    ".040    0.011   )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 117120, "        BODY501_NUT_PREC_PM   = (    0.   0.    -0"
	    ".085   -0.022   )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 117200, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 117280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 117360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 117440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 117520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 117600, "     Europa", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 117680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 117760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 117840, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 117920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 118000, "           Values are from the 2003 IAU report.", (
	    ftnlen)80, (ftnlen)47);
    s_copy(pck + 118080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 118160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 118240, "        body502_pole_ra       = (  268.08         "
	    " -0.009      0.   )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 118320, "        body502_pole_dec      = (   64.51         "
	    "  0.003      0.   )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 118400, "        body502_pm            = (   35.67         "
	    "101.3747235  0.   )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 118480, "        body502_long_axis     = (    0.           "
	    "                  )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 118560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 118640, "        body502_nut_prec_ra   = ( 0. 0. 0.   1.086"
	    "   0.060   0.015   0.009 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 118720, "        body502_nut_prec_dec  = ( 0. 0. 0.   0.468"
	    "   0.026   0.007   0.002 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 118800, "        body502_nut_prec_pm   = ( 0. 0. 0.  -0.980"
	    "  -0.054  -0.014  -0.008 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 118880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 118960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 119040, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 119120, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 119200, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 119280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 119360, "        BODY502_POLE_RA       = (  268.08         "
	    " -0.009      0.   )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 119440, "        BODY502_POLE_DEC      = (   64.51         "
	    "  0.003      0.   )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 119520, "        BODY502_PM            = (   36.022        "
	    "101.3747235  0.   )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 119600, "        BODY502_LONG_AXIS     = (    0.           "
	    "                  )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 119680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 119760, "        BODY502_NUT_PREC_RA   = ( 0. 0. 0.   1.086"
	    "   0.060   0.015   0.009 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 119840, "        BODY502_NUT_PREC_DEC  = ( 0. 0. 0.   0.468"
	    "   0.026   0.007   0.002 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 119920, "        BODY502_NUT_PREC_PM   = ( 0. 0. 0.  -0.980"
	    "  -0.054  -0.014  -0.008 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 120000, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 120080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 120160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 120240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 120320, "     Ganymede", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 120400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 120480, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 120560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 120640, "             Values are unchanged in the 2006 IAU "
	    "report.", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 120720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 120800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 120880, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 120960, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 121040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 121120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 121200, "        BODY503_POLE_RA       = (  268.20         "
	    "-0.009       0.  )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 121280, "        BODY503_POLE_DEC      = (   64.57         "
	    " 0.003       0.  )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 121360, "        BODY503_PM            = (   44.064        "
	    "50.3176081   0.  )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 121440, "        BODY503_LONG_AXIS     = (    0.           "
	    "                 )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 121520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 121600, "        BODY503_NUT_PREC_RA   = ( 0. 0. 0.  -0.037"
	    "   0.431   0.091   )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 121680, "        BODY503_NUT_PREC_DEC  = ( 0. 0. 0.  -0.016"
	    "   0.186   0.039   )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 121760, "        BODY503_NUT_PREC_PM   = ( 0. 0. 0.   0.033"
	    "  -0.389  -0.082   )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 121840, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 121920, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 122000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 122080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 122160, "     Callisto", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 122240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 122320, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 122400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 122480, "             Values are unchanged in the 2006 IAU "
	    "report.", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 122560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 122640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 122720, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 122800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 122880, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 122960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 123040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 123120, "        BODY504_POLE_RA       = (   268.72    -0.0"
	    "09       0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 123200, "        BODY504_POLE_DEC      = (    64.83     0.0"
	    "03       0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 123280, "        BODY504_PM            = (   259.51    21.5"
	    "710715   0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 123360, "        BODY504_LONG_AXIS     = (     0.          "
	    "             )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 123440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 123520, "        BODY504_NUT_PREC_RA   = ( 0. 0. 0. 0.  -0."
	    "068   0.590  0.   0.010 )", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 123600, "        BODY504_NUT_PREC_DEC  = ( 0. 0. 0. 0.  -0."
	    "029   0.254  0.  -0.004 )", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 123680, "        BODY504_NUT_PREC_PM   = ( 0. 0. 0. 0.   0."
	    "061  -0.533  0.  -0.009 )", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 123760, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 123840, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 123920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 124000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 124080, "     Amalthea", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 124160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 124240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 124320, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 124400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 124480, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 124560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 124640, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 124720, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 124800, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 124880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 124960, "        BODY505_POLE_RA       = (   268.05    -0.0"
	    "09      0.  )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 125040, "        BODY505_POLE_DEC      = (    64.49     0.0"
	    "03      0.  )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 125120, "        BODY505_PM            = (   231.67   722.6"
	    "314560  0.  )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 125200, "        BODY505_LONG_AXIS     = (     0.          "
	    "            )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 125280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 125360, "        BODY505_NUT_PREC_RA  = ( -0.84  0. 0. 0. 0"
	    ". 0. 0. 0.   0.01  0. )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 125440, "        BODY505_NUT_PREC_DEC = ( -0.36  0. 0. 0. 0"
	    ". 0. 0. 0.   0.    0. )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 125520, "        BODY505_NUT_PREC_PM  = (  0.76  0. 0. 0. 0"
	    ". 0. 0. 0.  -0.01  0. )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 125600, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 125680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 125760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 125840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 125920, "     Thebe", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 126000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 126080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 126160, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 126240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 126320, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 126400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 126480, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 126560, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 126640, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 126720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 126800, "        BODY514_POLE_RA       = (  268.05     -0.0"
	    "09       0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 126880, "        BODY514_POLE_DEC      = (   64.49      0.0"
	    "03       0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 126960, "        BODY514_PM            = (    8.56    533.7"
	    "004100   0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 127040, "        BODY514_LONG_AXIS     = (    0.           "
	    "             )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 127120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 127200, "        BODY514_NUT_PREC_RA  = ( 0.  -2.11  0. 0. "
	    "0. 0. 0. 0. 0.  0.04 )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 127280, "        BODY514_NUT_PREC_DEC = ( 0.  -0.91  0. 0. "
	    "0. 0. 0. 0. 0.  0.01 )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 127360, "        BODY514_NUT_PREC_PM  = ( 0.   1.91  0. 0. "
	    "0. 0. 0. 0. 0. -0.04 )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 127440, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 127520, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 127600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 127680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 127760, "     Adrastea", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 127840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 127920, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 128000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 128080, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 128160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 128240, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 128320, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 128400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 128480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 128560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 128640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 128720, "        BODY515_POLE_RA       = (  268.05     -0.0"
	    "09       0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 128800, "        BODY515_POLE_DEC      = (   64.49      0.0"
	    "03       0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 128880, "        BODY515_PM            = (   33.29   1206.9"
	    "986602   0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 128960, "        BODY515_LONG_AXIS     = (    0.           "
	    "             )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 129040, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 129120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 129200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 129280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 129360, "     Metis", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 129440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 129520, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 129600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 129680, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 129760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 129840, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 129920, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 130000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 130080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 130160, "        BODY516_POLE_RA       = (  268.05     -0.0"
	    "09       0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 130240, "        BODY516_POLE_DEC      = (   64.49      0.0"
	    "03       0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 130320, "        BODY516_PM            = (  346.09   1221.2"
	    "547301   0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 130400, "        BODY516_LONG_AXIS     = (    0.           "
	    "             )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 130480, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 130560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 130640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 130720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 130800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 130880, "Satellites of Saturn", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 130960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 131040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 131120, "     Mimas", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 131200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 131280, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 131360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 131440, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 131520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 131600, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 131680, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 131760, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 131840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 131920, "           BODY601_POLE_RA       = (   40.66     -"
	    "0.036      0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 132000, "           BODY601_POLE_DEC      = (   83.52     -"
	    "0.004      0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 132080, "           BODY601_PM            = (  337.46    38"
	    "1.9945550  0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 132160, "           BODY601_LONG_AXIS     = (     0.       "
	    "               )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 132240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 132320, "           BODY601_NUT_PREC_RA   = ( 0. 0.   13.56"
	    "  0.    0.    0. 0. 0. 0. )", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 132400, "           BODY601_NUT_PREC_DEC  = ( 0. 0.   -1.53"
	    "  0.    0.    0. 0. 0. 0. )", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 132480, "           BODY601_NUT_PREC_PM   = ( 0. 0.  -13.48"
	    "  0.  -44.85  0. 0. 0. 0. )", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 132560, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 132640, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 132720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 132800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 132880, "     Enceladus", (ftnlen)80, (ftnlen)14);
    s_copy(pck + 132960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 133040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 133120, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 133200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 133280, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 133360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 133440, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 133520, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 133600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 133680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 133760, "           BODY602_POLE_RA       = (   40.66    -0"
	    ".036       0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 133840, "           BODY602_POLE_DEC      = (   83.52    -0"
	    ".004       0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 133920, "           BODY602_PM            = (    2.82   262"
	    ".7318996   0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 134000, "           BODY602_LONG_AXIS     = (    0.        "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 134080, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 134160, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 134240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 134320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 134400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 134480, "     Tethys", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 134560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 134640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 134720, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 134800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 134880, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 134960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 135040, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 135120, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 135200, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 135280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 135360, "           BODY603_POLE_RA       = (   40.66    -0"
	    ".036       0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 135440, "           BODY603_POLE_DEC      = (   83.52    -0"
	    ".004       0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 135520, "           BODY603_PM            = (   10.45   190"
	    ".6979085   0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 135600, "           BODY603_LONG_AXIS     = (    0.        "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 135680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 135760, "           BODY603_NUT_PREC_RA   = ( 0. 0. 0.   9."
	    "66   0.    0.  0.  0.  0. )", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 135840, "           BODY603_NUT_PREC_DEC  = ( 0. 0. 0.  -1."
	    "09   0.    0.  0.  0.  0. )", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 135920, "           BODY603_NUT_PREC_PM   = ( 0. 0. 0.  -9."
	    "60   2.23  0.  0.  0.  0. )", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 136000, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 136080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 136160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 136240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 136320, "     Dione", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 136400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 136480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 136560, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 136640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 136720, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 136800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 136880, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 136960, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 137040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 137120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 137200, "           BODY604_POLE_RA       = (  40.66      -"
	    "0.036      0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 137280, "           BODY604_POLE_DEC      = (  83.52      -"
	    "0.004      0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 137360, "           BODY604_PM            = (  357.00    13"
	    "1.5349316  0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 137440, "           BODY604_LONG_AXIS     = (    0.        "
	    "               )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 137520, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 137600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 137680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 137760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 137840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 137920, "     Rhea", (ftnlen)80, (ftnlen)9);
    s_copy(pck + 138000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 138080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 138160, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 138240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 138320, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 138400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 138480, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 138560, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 138640, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 138720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 138800, "           BODY605_POLE_RA       = (   40.38   -0."
	    "036       0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 138880, "           BODY605_POLE_DEC      = (   83.55   -0."
	    "004       0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 138960, "           BODY605_PM            = (  235.16   79."
	    "6900478   0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 139040, "           BODY605_LONG_AXIS     = (    0.        "
	    "             )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 139120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 139200, "           BODY605_NUT_PREC_RA   = ( 0. 0. 0. 0. 0"
	    ".   3.10   0. 0. 0. )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 139280, "           BODY605_NUT_PREC_DEC  = ( 0. 0. 0. 0. 0"
	    ".  -0.35   0. 0. 0. )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 139360, "           BODY605_NUT_PREC_PM   = ( 0. 0. 0. 0. 0"
	    ".  -3.08   0. 0. 0. )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 139440, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 139520, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 139600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 139680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 139760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 139840, "     Titan", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 139920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 140000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 140080, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 140160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 140240, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 140320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 140400, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 140480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 140560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 140640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 140720, "           BODY606_POLE_RA       = (    36.41   -0"
	    ".036      0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 140800, "           BODY606_POLE_DEC      = (    83.94   -0"
	    ".004      0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 140880, "           BODY606_PM            = (   189.64   22"
	    ".5769768  0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 140960, "           BODY606_LONG_AXIS     = (     0.       "
	    "             )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 141040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 141120, "           BODY606_NUT_PREC_RA   = ( 0. 0. 0. 0. 0"
	    ". 0.  2.66  0. 0 )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 141200, "           BODY606_NUT_PREC_DEC  = ( 0. 0. 0. 0. 0"
	    ". 0. -0.30  0. 0 )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 141280, "           BODY606_NUT_PREC_PM   = ( 0. 0. 0. 0. 0"
	    ". 0. -2.64  0. 0 )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 141360, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 141440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 141520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 141600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 141680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 141760, "     Hyperion", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 141840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 141920, "         The IAU report does not give an orientati"
	    "on model for Hyperion.", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 142000, "         Hyperion's rotation is in chaotic and is "
	    "not predictable for", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 142080, "         long periods.", (ftnlen)80, (ftnlen)22);
    s_copy(pck + 142160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 142240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 142320, "     Iapetus", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 142400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 142480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 142560, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 142640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 142720, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 142800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 142880, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 142960, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 143040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 143120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 143200, "           BODY608_POLE_RA       = (   318.16  -3."
	    "949      0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 143280, "           BODY608_POLE_DEC      = (    75.03  -1."
	    "143      0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 143360, "           BODY608_PM            = (   350.20   4."
	    "5379572  0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 143440, "           BODY608_LONG_AXIS     = (     0.       "
	    "             )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 143520, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 143600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 143680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 143760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 143840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 143920, "     Phoebe", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 144000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 144080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 144160, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 144240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 144320, "           Values are from the 2003 IAU report.", (
	    ftnlen)80, (ftnlen)47);
    s_copy(pck + 144400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 144480, "           body609_pole_ra       = ( 355.00       "
	    "0.         0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 144560, "           body609_pole_dec      = (  68.70       "
	    "0.         0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 144640, "           body609_pm            = ( 304.70     93"
	    "0.8338720  0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 144720, "           body609_long_axis     = (    0.        "
	    "               )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 144800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 144880, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 144960, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 145040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 145120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 145200, "           BODY609_POLE_RA       = ( 356.90       "
	    "0.         0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 145280, "           BODY609_POLE_DEC      = (  77.80       "
	    "0.         0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 145360, "           BODY609_PM            = ( 178.58     93"
	    "1.639      0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 145440, "           BODY609_LONG_AXIS     = (    0.        "
	    "               )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 145520, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 145600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 145680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 145760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 145840, "     Janus", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 145920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 146000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 146080, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 146160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 146240, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 146320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 146400, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 146480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 146560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 146640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 146720, "           BODY610_POLE_RA       = (  40.58    -0."
	    "036       0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 146800, "           BODY610_POLE_DEC      = (  83.52    -0."
	    "004       0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 146880, "           BODY610_PM            = (  58.83   518."
	    "2359876   0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 146960, "           BODY610_LONG_AXIS     = (   0.         "
	    "             )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 147040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 147120, "           BODY610_NUT_PREC_RA   = ( 0. -1.623  0."
	    " 0. 0. 0. 0. 0.  0.023 )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 147200, "           BODY610_NUT_PREC_DEC  = ( 0. -0.183  0."
	    " 0. 0. 0. 0. 0.  0.001 )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 147280, "           BODY610_NUT_PREC_PM   = ( 0.  1.613  0."
	    " 0. 0. 0. 0. 0. -0.023 )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 147360, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 147440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 147520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 147600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 147680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 147760, "     Epimetheus", (ftnlen)80, (ftnlen)15);
    s_copy(pck + 147840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 147920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 148000, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 148080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 148160, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 148240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 148320, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 148400, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 148480, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 148560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 148640, "           BODY611_POLE_RA       = (  40.58    -0."
	    "036        0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 148720, "           BODY611_POLE_DEC      = (  83.52    -0."
	    "004        0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 148800, "           BODY611_PM            = ( 293.87   518."
	    "4907239    0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 148880, "           BODY611_LONG_AXIS     = (   0.         "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 148960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 149040, "           BODY611_NUT_PREC_RA   = ( -3.153   0. 0"
	    ". 0. 0. 0. 0.   0.086  0. )", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 149120, "           BODY611_NUT_PREC_DEC  = ( -0.356   0. 0"
	    ". 0. 0. 0. 0.   0.005  0. )", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 149200, "           BODY611_NUT_PREC_PM   = (  3.133   0. 0"
	    ". 0. 0. 0. 0.  -0.086  0. )", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 149280, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 149360, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 149440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 149520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 149600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 149680, "     Helene", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 149760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 149840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 149920, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 150000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 150080, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 150160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 150240, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 150320, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 150400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 150480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 150560, "           BODY612_POLE_RA       = (  40.85     -0"
	    ".036        0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 150640, "           BODY612_POLE_DEC      = (  83.34     -0"
	    ".004        0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 150720, "           BODY612_PM            = ( 245.12    131"
	    ".6174056    0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 150800, "           BODY612_LONG_AXIS     = (   0.         "
	    "               )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 150880, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 150960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 151040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 151120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 151200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 151280, "     Telesto", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 151360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 151440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 151520, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 151600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 151680, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 151760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 151840, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 151920, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 152000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 152080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 152160, "           BODY613_POLE_RA       = ( 50.51    -0.0"
	    "36      0.  )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 152240, "           BODY613_POLE_DEC      = ( 84.06    -0.0"
	    "04      0.  )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 152320, "           BODY613_PM            = ( 56.88   190.6"
	    "979332  0.  )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 152400, "           BODY613_LONG_AXIS     = (  0.          "
	    "            )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 152480, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 152560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 152640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 152720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 152800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 152880, "     Calypso", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 152960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 153040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 153120, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 153200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 153280, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 153360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 153440, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 153520, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 153600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 153680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 153760, "           BODY614_POLE_RA       = (   36.41    -0"
	    ".036        0.  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 153840, "           BODY614_POLE_DEC      = (   85.04    -0"
	    ".004        0.  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 153920, "           BODY614_PM            = (  153.51   190"
	    ".6742373    0.  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 154000, "           BODY614_LONG_AXIS     = (    0.        "
	    "                )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 154080, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 154160, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 154240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 154320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 154400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 154480, "     Atlas", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 154560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 154640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 154720, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 154800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 154880, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 154960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 155040, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 155120, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 155200, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 155280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 155360, "           BODY615_POLE_RA       = (   40.58     -"
	    "0.036      0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 155440, "           BODY615_POLE_DEC      = (   83.53     -"
	    "0.004      0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 155520, "           BODY615_PM            = (  137.88    59"
	    "8.3060000  0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 155600, "           BODY615_LONG_AXIS     = (    0.        "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 155680, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 155760, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 155840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 155920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 156000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 156080, "     Prometheus", (ftnlen)80, (ftnlen)15);
    s_copy(pck + 156160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 156240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 156320, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 156400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 156480, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 156560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 156640, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 156720, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 156800, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 156880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 156960, "           BODY616_POLE_RA       = (  40.58      -"
	    "0.036    )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 157040, "           BODY616_POLE_DEC      = (  83.53      -"
	    "0.004    )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 157120, "           BODY616_PM            = ( 296.14     58"
	    "7.289000 )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 157200, "           BODY616_LONG_AXIS     = (   0.         "
	    "         )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 157280, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 157360, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 157440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 157520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 157600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 157680, "     Pandora", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 157760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 157840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 157920, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 158000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 158080, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 158160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 158240, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 158320, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 158400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 158480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 158560, "           BODY617_POLE_RA       = (   40.58     -"
	    "0.036      0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 158640, "           BODY617_POLE_DEC      = (   83.53     -"
	    "0.004      0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 158720, "           BODY617_PM            = (  162.92    57"
	    "2.7891000  0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 158800, "           BODY617_LONG_AXIS     = (     0.       "
	    "               )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 158880, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 158960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 159040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 159120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 159200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 159280, "     Pan", (ftnlen)80, (ftnlen)8);
    s_copy(pck + 159360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 159440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 159520, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 159600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 159680, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 159760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 159840, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 159920, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 160000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 160080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 160160, "           BODY618_POLE_RA       = (   40.6     -0"
	    ".036       0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 160240, "           BODY618_POLE_DEC      = (   83.5     -0"
	    ".004       0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 160320, "           BODY618_PM            = (   48.8    626"
	    ".0440000   0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 160400, "           BODY618_LONG_AXIS     = (    0.        "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 160480, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 160560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 160640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 160720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 160800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 160880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 160960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 161040, "Satellites of Uranus", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 161120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 161200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 161280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 161360, "     Ariel", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 161440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 161520, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 161600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 161680, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 161760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 161840, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 161920, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 162000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 162080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 162160, "           BODY701_POLE_RA       = ( 257.43     0."
	    "          0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 162240, "           BODY701_POLE_DEC      = ( -15.10     0."
	    "          0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 162320, "           BODY701_PM            = ( 156.22  -142."
	    "8356681   0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 162400, "           BODY701_LONG_AXIS     = (   0.         "
	    "             )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 162480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 162560, "           BODY701_NUT_PREC_RA   = (  0. 0. 0. 0. "
	    "0.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 162640, "                                      0. 0. 0. 0. "
	    "0.  0.    0.    0.29 )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 162720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 162800, "           BODY701_NUT_PREC_DEC  = (  0. 0. 0. 0. "
	    "0.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 162880, "                                      0. 0. 0. 0. "
	    "0.  0.    0.    0.28 )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 162960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 163040, "           BODY701_NUT_PREC_PM   = (  0. 0. 0. 0. "
	    "0.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 163120, "                                      0. 0. 0. 0. "
	    "0.  0.   0.05   0.08 )", (ftnlen)80, (ftnlen)72);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 163200, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 163280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 163360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 163440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 163520, "     Umbriel", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 163600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 163680, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 163760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 163840, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 163920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 164000, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 164080, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 164160, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 164240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 164320, "           BODY702_POLE_RA       = (  257.43     0"
	    ".          0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 164400, "           BODY702_POLE_DEC      = (  -15.10     0"
	    ".          0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 164480, "           BODY702_PM            = (  108.05   -86"
	    ".8688923   0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 164560, "           BODY702_LONG_AXIS     = (    0.        "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 164640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 164720, "           BODY702_NUT_PREC_RA   = ( 0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 164800, "                                     0. 0. 0. 0. 0"
	    ".   0.   0.    0.   0.21 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 164880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 164960, "           BODY702_NUT_PREC_DEC  = ( 0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 165040, "                                     0. 0. 0. 0. 0"
	    ".   0.   0.    0.   0.20 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 165120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 165200, "           BODY702_NUT_PREC_PM   = ( 0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 165280, "                                     0. 0. 0. 0. 0"
	    ".   0.  -0.09  0.   0.06 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 165360, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 165440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 165520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 165600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 165680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 165760, "     Titania", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 165840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 165920, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 166000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 166080, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 166160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 166240, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 166320, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 166400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 166480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 166560, "           BODY703_POLE_RA       = (  257.43    0."
	    "          0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 166640, "           BODY703_POLE_DEC      = (  -15.10    0."
	    "          0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 166720, "           BODY703_PM            = (   77.74  -41."
	    "3514316   0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 166800, "           BODY703_LONG_AXIS     = (    0.        "
	    "             )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 166880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 166960, "           BODY703_NUT_PREC_RA   = ( 0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 167040, "                                     0. 0. 0. 0. 0"
	    ".   0. 0. 0. 0.   0.29 )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 167120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 167200, "           BODY703_NUT_PREC_DEC  = ( 0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 167280, "                                     0. 0. 0. 0. 0"
	    ".   0. 0. 0. 0.   0.28 )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 167360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 167440, "           BODY703_NUT_PREC_PM   = ( 0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 167520, "                                     0. 0. 0. 0. 0"
	    ".   0. 0. 0. 0.   0.08 )", (ftnlen)80, (ftnlen)74);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 167600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 167680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 167760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 167840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 167920, "     Oberon", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 168000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 168080, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 168160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 168240, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 168320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 168400, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 168480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 168560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 168640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 168720, "           BODY704_POLE_RA       = (  257.43    0."
	    "          0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 168800, "           BODY704_POLE_DEC      = (  -15.10    0."
	    "          0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 168880, "           BODY704_PM            = (    6.77  -26."
	    "7394932   0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 168960, "           BODY704_LONG_AXIS     = (    0.        "
	    "             )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 169040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 169120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 169200, "           BODY704_NUT_PREC_RA   = ( 0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 169280, "                                     0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 169360, "                                     0. 0. 0. 0. 0"
	    ".   0.16 )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 169440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 169520, "           BODY704_NUT_PREC_DEC  = ( 0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 169600, "                                     0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 169680, "                                     0. 0. 0. 0. 0"
	    ".   0.16 )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 169760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 169840, "           BODY704_NUT_PREC_PM   = ( 0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 169920, "                                     0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 170000, "                                     0. 0. 0. 0. 0"
	    ".   0.04 )", (ftnlen)80, (ftnlen)60);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 170080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 170160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 170240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 170320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 170400, "     Miranda", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 170480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 170560, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 170640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 170720, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 170800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 170880, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 170960, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 171040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 171120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 171200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 171280, "           BODY705_POLE_RA      = (  257.43     0."
	    "         0. )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 171360, "           BODY705_POLE_DEC     = (  -15.08     0."
	    "         0. )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 171440, "           BODY705_PM           = (   30.70  -254."
	    "6906892  0. )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 171520, "           BODY705_LONG_AXIS    = (    0.         "
	    "            )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 171600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 171680, "           BODY705_NUT_PREC_RA  = ( 0.     0.     "
	    "0.    0.    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 171760, "                                    0.     0.     "
	    "0.    0.    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 171840, "                                    4.41   0.     "
	    "0.    0.    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 171920, "                                    0.    -0.04   "
	    "0.             )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 172000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 172080, "           BODY705_NUT_PREC_DEC = ( 0.     0.     "
	    "0.    0.    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 172160, "                                    0.     0.     "
	    "0.    0.    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 172240, "                                    4.25   0.     "
	    "0.    0.    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 172320, "                                    0.    -0.02   "
	    "0.             )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 172400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 172480, "           BODY705_NUT_PREC_PM  = ( 0.     0.     "
	    "0.    0.    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 172560, "                                    0.     0.     "
	    "0.    0.    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 172640, "                                    1.15  -1.27   "
	    "0.    0.    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 172720, "                                    0.    -0.09   "
	    "0.15           )", (ftnlen)80, (ftnlen)66);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 172800, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 172880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 172960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 173040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 173120, "     Cordelia", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 173200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 173280, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 173360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 173440, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 173520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 173600, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 173680, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 173760, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 173840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 173920, "           BODY706_POLE_RA      = (   257.31      "
	    "0.         0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 174000, "           BODY706_POLE_DEC     = (   -15.18      "
	    "0.         0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 174080, "           BODY706_PM           = (   127.69  -107"
	    "4.5205730  0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 174160, "           BODY706_LONG_AXIS    = (     0.        "
	    "               )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 174240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 174320, "           BODY706_NUT_PREC_RA  = (   -0.15    0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 174400, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 174480, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 174560, "                                       0.      0. "
	    "    0.             )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 174640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 174720, "           BODY706_NUT_PREC_DEC = (    0.14    0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 174800, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 174880, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 174960, "                                       0.      0. "
	    "    0.             )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 175040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 175120, "           BODY706_NUT_PREC_PM  = (   -0.04    0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 175200, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 175280, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 175360, "                                       0.      0. "
	    "    0.             )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 175440, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 175520, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 175600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 175680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 175760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 175840, "     Ophelia", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 175920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 176000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 176080, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 176160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 176240, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 176320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 176400, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 176480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 176560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 176640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 176720, "           BODY707_POLE_RA      = (  257.31     0."
	    "         0. )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 176800, "           BODY707_POLE_DEC     = (  -15.18     0."
	    "         0. )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 176880, "           BODY707_PM           = (  130.35  -956."
	    "4068150  0. )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 176960, "           BODY707_LONG_AXIS    = (    0.         "
	    "            )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 177040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 177120, "           BODY707_NUT_PREC_RA  = (    0.     -0.0"
	    "9   0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 177200, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 177280, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 177360, "                                       0.      0. "
	    "    0.             )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 177440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 177520, "           BODY707_NUT_PREC_DEC = (    0.      0.0"
	    "9   0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 177600, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 177680, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 177760, "                                       0.      0. "
	    "    0.             )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 177840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 177920, "           BODY707_NUT_PREC_PM  = (    0.     -0.0"
	    "3   0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 178000, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 178080, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 178160, "                                       0.      0. "
	    "    0.             )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 178240, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 178320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 178400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 178480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 178560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 178640, "     Bianca", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 178720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 178800, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 178880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 178960, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 179040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 179120, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 179200, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 179280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 179360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 179440, "           BODY708_POLE_RA      = (  257.31     0."
	    "         0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 179520, "           BODY708_POLE_DEC     = (  -15.18     0."
	    "         0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 179600, "           BODY708_PM           = (  105.46  -828."
	    "3914760  0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 179680, "           BODY708_LONG_AXIS    = (    0.         "
	    "             )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 179760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 179840, "           BODY708_NUT_PREC_RA  = (    0.      0. "
	    "   -0.16    0.    0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 179920, "                                       0.      0. "
	    "    0.      0.    0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 180000, "                                       0.      0. "
	    "    0.      0.    0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 180080, "                                       0.      0. "
	    "    0.               )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 180160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 180240, "           BODY708_NUT_PREC_DEC = (    0.      0. "
	    "    0.16    0.    0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 180320, "                                       0.      0. "
	    "    0.      0.    0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 180400, "                                       0.      0. "
	    "    0.      0.    0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 180480, "                                       0.      0. "
	    "    0.               )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 180560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 180640, "           BODY708_NUT_PREC_PM  = (    0.      0. "
	    "   -0.04    0.    0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 180720, "                                       0.      0. "
	    "    0.      0.    0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 180800, "                                       0.      0. "
	    "    0.      0.    0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 180880, "                                       0.      0. "
	    "    0.               )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 180960, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 181040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 181120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 181200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 181280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 181360, "     Cressida", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 181440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 181520, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 181600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 181680, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 181760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 181840, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 181920, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 182000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 182080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 182160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 182240, "           BODY709_POLE_RA      = (  257.31      0"
	    ".          0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 182320, "           BODY709_POLE_DEC     = (  -15.18      0"
	    ".          0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 182400, "           BODY709_PM           = (   59.16   -776"
	    ".5816320   0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 182480, "           BODY709_LONG_AXIS    = (    0.         "
	    "               )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 182560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 182640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 182720, "           BODY709_NUT_PREC_RA  = (    0.      0. "
	    "    0.     -0.04   0.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 182800, "                                       0.      0. "
	    "    0.      0.     0.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 182880, "                                       0.      0. "
	    "    0.      0.     0.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 182960, "                                       0.      0. "
	    "    0.                )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 183040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 183120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 183200, "           BODY709_NUT_PREC_DEC = (    0.      0. "
	    "    0.      0.04   0.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 183280, "                                       0.      0. "
	    "    0.      0.     0.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 183360, "                                       0.      0. "
	    "    0.      0.     0.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 183440, "                                       0.      0. "
	    "    0.                )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 183520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 183600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 183680, "           BODY709_NUT_PREC_PM  = (    0.      0. "
	    "    0.     -0.01   0.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 183760, "                                       0.      0. "
	    "    0.      0.     0.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 183840, "                                       0.      0. "
	    "    0.      0.     0.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 183920, "                                       0.      0. "
	    "    0.                )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 184000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 184080, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 184160, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 184240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 184320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 184400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 184480, "     Desdemona", (ftnlen)80, (ftnlen)14);
    s_copy(pck + 184560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 184640, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 184720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 184800, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 184880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 184960, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 185040, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 185120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 185200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 185280, "           BODY710_POLE_RA      = ( 257.31      0."
	    "           0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 185360, "           BODY710_POLE_DEC     = ( -15.18      0."
	    "           0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 185440, "           BODY710_PM           = (  95.08   -760."
	    "0531690    0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 185520, "           BODY710_LONG_AXIS    = (   0.          "
	    "               )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 185600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 185680, "           BODY710_NUT_PREC_RA  = (   0.      0.  "
	    "   0.      0.    -0.17", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 185760, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 185840, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 185920, "                                      0.      0.  "
	    "   0.                  )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 186000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 186080, "           BODY710_NUT_PREC_DEC = (   0.      0.  "
	    "   0.      0.     0.16", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 186160, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 186240, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 186320, "                                      0.      0.  "
	    "   0.                  )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 186400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 186480, "           BODY710_NUT_PREC_PM  = (   0.      0.  "
	    "   0.      0.    -0.04", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 186560, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 186640, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 186720, "                                      0.      0.  "
	    "   0.                 )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 186800, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 186880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 186960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 187040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 187120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 187200, "     Juliet", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 187280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 187360, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 187440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 187520, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 187600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 187680, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 187760, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 187840, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 187920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 188000, "           BODY711_POLE_RA      = (  257.31     0."
	    "           0.   )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 188080, "           BODY711_POLE_DEC     = (  -15.18     0."
	    "           0.   )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 188160, "           BODY711_PM           = (  302.56  -730."
	    "1253660    0.   )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 188240, "           BODY711_LONG_AXIS    = (    0.         "
	    "                )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 188320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 188400, "           BODY711_NUT_PREC_RA  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 188480, "                                     -0.06    0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 188560, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 188640, "                                      0.      0.  "
	    "   0.                 )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 188720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 188800, "           BODY711_NUT_PREC_DEC = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 188880, "                                      0.06    0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 188960, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 189040, "                                      0.      0.  "
	    "   0.                 )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 189120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 189200, "           BODY711_NUT_PREC_PM  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 189280, "                                     -0.02    0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 189360, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 189440, "                                      0.      0.  "
	    "   0.                 )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 189520, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 189600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 189680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 189760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 189840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 189920, "     Portia", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 190000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 190080, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 190160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 190240, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 190320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 190400, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 190480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 190560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 190640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 190720, "           BODY712_POLE_RA      = (  257.31      0"
	    ".           0.   )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 190800, "           BODY712_POLE_DEC     = (  -15.18      0"
	    ".           0.   )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 190880, "           BODY712_PM           = (   25.03   -701"
	    ".4865870    0.   )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 190960, "           BODY712_LONG_AXIS    = (    0.         "
	    "                 )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 191040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 191120, "           BODY712_NUT_PREC_RA  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 191200, "                                      0.     -0.09"
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 191280, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 191360, "                                      0.      0.  "
	    "   0.                )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 191440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 191520, "           BODY712_NUT_PREC_DEC = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 191600, "                                      0.      0.09"
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 191680, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 191760, "                                      0.      0.  "
	    "   0.               )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 191840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 191920, "           BODY712_NUT_PREC_PM  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 192000, "                                      0.     -0.02"
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 192080, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 192160, "                                      0.      0.  "
	    "   0.               )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 192240, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 192320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 192400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 192480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 192560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 192640, "     Rosalind", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 192720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 192800, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 192880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 192960, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 193040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 193120, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 193200, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 193280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 193360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 193440, "           BODY713_POLE_RA      = ( 257.31      0."
	    "          0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 193520, "           BODY713_POLE_DEC     = ( -15.18      0."
	    "          0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 193600, "           BODY713_PM           = ( 314.90   -644."
	    "6311260   0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 193680, "           BODY713_LONG_AXIS    = (   0.          "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 193760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 193840, "           BODY713_NUT_PREC_RA  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 193920, "                                      0.      0.  "
	    "  -0.29    0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 194000, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 194080, "                                      0.      0.  "
	    "   0.               )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 194160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 194240, "           BODY713_NUT_PREC_DEC = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 194320, "                                      0.      0.  "
	    "   0.28    0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 194400, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 194480, "                                      0.      0.  "
	    "   0.              )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 194560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 194640, "           BODY713_NUT_PREC_PM  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 194720, "                                      0.      0.  "
	    "  -0.08    0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 194800, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 194880, "                                      0.      0.  "
	    "   0.              )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 194960, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 195040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 195120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 195200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 195280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 195360, "     Belinda", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 195440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 195520, "       Old values:", (ftnlen)80, (ftnlen)18);
    s_copy(pck + 195600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 195680, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 195760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 195840, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 195920, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 196000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 196080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 196160, "           BODY714_POLE_RA      = (   257.31      "
	    "0.         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 196240, "           BODY714_POLE_DEC     = (   -15.18      "
	    "0.         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 196320, "           BODY714_PM           = (   297.46   -57"
	    "7.3628170  0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 196400, "           BODY714_LONG_AXIS    = (     0.        "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 196480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 196560, "           BODY714_NUT_PREC_RA  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 196640, "                                      0.      0.  "
	    "   0.     -0.03   0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 196720, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 196800, "                                      0.      0.  "
	    "   0.                )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 196880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 196960, "           BODY714_NUT_PREC_DEC = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 197040, "                                      0.      0.  "
	    "   0.      0.03   0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 197120, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 197200, "                                      0.      0.  "
	    "   0.                )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 197280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 197360, "           BODY714_NUT_PREC_PM  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 197440, "                                      0.      0.  "
	    "   0.     -0.01   0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 197520, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 197600, "                                      0.      0.  "
	    "   0.                )", (ftnlen)80, (ftnlen)72);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 197680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 197760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 197840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 197920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 198000, "     Puck", (ftnlen)80, (ftnlen)9);
    s_copy(pck + 198080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 198160, "       Old values:", (ftnlen)80, (ftnlen)18);
    s_copy(pck + 198240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 198320, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 198400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 198480, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 198560, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 198640, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 198720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 198800, "           BODY715_POLE_RA      = (  257.31      0"
	    ".         0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 198880, "           BODY715_POLE_DEC     = (  -15.18      0"
	    ".         0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 198960, "           BODY715_PM           = (   91.24   -472"
	    ".5450690  0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 199040, "           BODY715_LONG_AXIS    = (    0.         "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 199120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 199200, "           BODY715_NUT_PREC_RA  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 199280, "                                      0.      0.  "
	    "   0.      0.    -0.33", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 199360, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 199440, "                                      0.      0.  "
	    "   0.                  )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 199520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 199600, "           BODY715_NUT_PREC_DEC = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 199680, "                                      0.      0.  "
	    "   0.      0.     0.31", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 199760, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 199840, "                                      0.      0.  "
	    "   0.                  )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 199920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 200000, "           BODY715_NUT_PREC_PM  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 200080, "                                      0.      0.  "
	    "   0.      0.    -0.09", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 200160, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 200240, "                                      0.      0.  "
	    "   0.                  )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 200320, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 200400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 200480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 200560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 200640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 200720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 200800, "Satellites of Neptune", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 200880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 200960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 201040, "     Triton", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 201120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 201200, "       Old values:", (ftnlen)80, (ftnlen)18);
    s_copy(pck + 201280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 201360, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 201440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 201520, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 201600, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 201680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 201760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 201840, "           BODY801_POLE_RA       = ( 299.36     0."
	    "         0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 201920, "           BODY801_POLE_DEC      = (  41.17     0."
	    "         0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 202000, "           BODY801_PM            = ( 296.53   -61."
	    "2572637  0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 202080, "           BODY801_LONG_AXIS     = (   0.         "
	    "             )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 202160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 202240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 202320, "           BODY801_NUT_PREC_RA   = (  0.      0.  "
	    "    0.      0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 202400, "                                      0.      0.  "
	    "    0.    -32.35", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 202480, "                                      0.     -6.28"
	    "   -2.08   -0.74", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 202560, "                                     -0.28   -0.11"
	    "   -0.07   -0.02", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 202640, "                                     -0.01        "
	    "                 )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 202720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 202800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 202880, "           BODY801_NUT_PREC_DEC  = (  0.      0.  "
	    "    0.      0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 202960, "                                      0.      0.  "
	    "    0.     22.55", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 203040, "                                      0.      2.10"
	    "    0.55    0.16", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 203120, "                                      0.05    0.02"
	    "    0.01    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 203200, "                                      0.          "
	    "                 )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 203280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 203360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 203440, "           BODY801_NUT_PREC_PM   = (  0.      0.  "
	    "    0.      0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 203520, "                                      0.      0.  "
	    "    0.     22.25", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 203600, "                                      0.      6.73"
	    "    2.05    0.74", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 203680, "                                      0.28    0.11"
	    "    0.05    0.02", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 203760, "                                      0.01        "
	    "                 )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 203840, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 203920, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 204000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 204080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 204160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 204240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 204320, "     Nereid", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 204400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 204480, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 204560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 204640, "           Values are from the 1988 IAU report [10"
	    "].  Note that this", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 204720, "           rotation model pre-dated the 1989 Voyag"
	    "er 2 Neptune", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 204800, "           encounter.", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 204880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 204960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 205040, "           body802_pole_ra       = (    273.48    "
	    "0.        0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 205120, "           body802_pole_dec      = (     67.22    "
	    "0.        0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 205200, "           body802_pm            = (    237.22    "
	    "0.9996465 0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 205280, "           body802_long_axis     = (      0.      "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 205360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 205440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 205520, "           The report seems to have a typo:  in th"
	    "e nut_prec_ra expression,", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 205600, "           where the report gives  -0.51 sin 3N3, "
	    "we use -0.51 3N2.", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 205680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 205760, "           body802_nut_prec_ra   = (  0.    -17.81",
	     (ftnlen)80, (ftnlen)50);
    s_copy(pck + 205840, "                                      0.      0.  "
	    "   0.      0.", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 205920, "                                      0.      0.  "
	    "   0.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 206000, "                                      2.56   -0.51"
	    "   0.11   -0.03  )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 206080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 206160, "           body802_nut_prec_dec  = (  0.     -6.67",
	     (ftnlen)80, (ftnlen)50);
    s_copy(pck + 206240, "                                      0.      0.  "
	    "   0.      0.", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 206320, "                                      0.      0.  "
	    "   0.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 206400, "                                      0.47   -0.07"
	    "   0.01          )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 206480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 206560, "           body802_nut_prec_pm   = (  0.     16.48",
	     (ftnlen)80, (ftnlen)50);
    s_copy(pck + 206640, "                                      0.      0.  "
	    "   0.      0.", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 206720, "                                      0.      0.  "
	    "   0.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 206800, "                                     -2.57    0.51"
	    " -0.11    0.02  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 206880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 206960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 207040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 207120, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 207200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 207280, "           The 2006 report [1] states that values "
	    "for Nereid are not", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 207360, "           given because Nereid is not in synchron"
	    "ous rotation with Neptune", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 207440, "           (p. 167).", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 207520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 207600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 207680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 207760, "     Naiad", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 207840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 207920, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 208000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 208080, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 208160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 208240, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 208320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 208400, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 208480, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 208560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 208640, "           BODY803_POLE_RA       = (  299.36      "
	    "0.          0.  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 208720, "           BODY803_POLE_DEC      = (   43.36      "
	    "0.          0.  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 208800, "           BODY803_PM            = (  254.06  +122"
	    "2.8441209   0.  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 208880, "           BODY803_LONG_AXIS     = (    0.        "
	    "                )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 208960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 209040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 209120, "           BODY803_NUT_PREC_RA   = (    0.70     -"
	    "6.49     0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 209200, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 209280, "                                        0.25      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 209360, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 209440, "                                        0.        "
	    "                    )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 209520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 209600, "           BODY803_NUT_PREC_DEC  = (   -0.51     -"
	    "4.75     0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 209680, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 209760, "                                        0.09      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 209840, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 209920, "                                        0.        "
	    "                    )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 210000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 210080, "           BODY803_NUT_PREC_PM   = (   -0.48      "
	    "4.40     0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 210160, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 210240, "                                       -0.27      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 210320, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 210400, "                                        0.        "
	    "                    )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 210480, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 210560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 210640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 210720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 210800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 210880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 210960, "     Thalassa", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 211040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 211120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 211200, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 211280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 211360, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 211440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 211520, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 211600, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 211680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 211760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 211840, "           BODY804_POLE_RA       = (  299.36      "
	    "0.          0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 211920, "           BODY804_POLE_DEC      = (   43.45      "
	    "0.          0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 212000, "           BODY804_PM            = (  102.06   115"
	    "5.7555612   0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 212080, "           BODY804_LONG_AXIS     = (    0.        "
	    "               )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 212160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 212240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 212320, "           BODY804_NUT_PREC_RA   = (    0.70      "
	    "0.      -0.28    0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 212400, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 212480, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 212560, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 212640, "                                        0.        "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 212720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 212800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 212880, "           BODY804_NUT_PREC_DEC  = (   -0.51      "
	    "0.      -0.21    0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 212960, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 213040, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 213120, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 213200, "                                        0.        "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 213280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 213360, "           BODY804_NUT_PREC_PM   = (   -0.48      "
	    "0.       0.19    0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 213440, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 213520, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 213600, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 213680, "                                        0.        "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 213760, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 213840, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 213920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 214000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 214080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 214160, "     Despina", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 214240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 214320, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 214400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 214480, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 214560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 214640, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 214720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 214800, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 214880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 214960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 215040, "           BODY805_POLE_RA       = (  299.36      "
	    "0.          0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 215120, "           BODY805_POLE_DEC      = (   43.45      "
	    "0.          0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 215200, "           BODY805_PM            = (  306.51  +107"
	    "5.7341562   0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 215280, "           BODY805_LONG_AXIS     = (    0.        "
	    "               )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 215360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 215440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 215520, "           BODY805_NUT_PREC_RA   = (    0.70      "
	    "0.       0.     -0.09", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 215600, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 215680, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 215760, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 215840, "                                        0.        "
	    "                      )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 215920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 216000, "           BODY805_NUT_PREC_DEC  = (   -0.51      "
	    "0.       0.     -0.07", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 216080, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 216160, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 216240, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 216320, "                                        0.        "
	    "                      )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 216400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 216480, "           BODY805_NUT_PREC_PM   = (   -0.49      "
	    "0.       0.      0.06", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 216560, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 216640, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 216720, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 216800, "                                        0.        "
	    "                      )", (ftnlen)80, (ftnlen)73);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 216880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 216960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 217040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 217120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 217200, "     Galatea", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 217280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 217360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 217440, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 217520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 217600, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 217680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 217760, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 217840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 217920, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 218000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 218080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 218160, "           BODY806_POLE_RA       = (   299.36     "
	    " 0.          0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 218240, "           BODY806_POLE_DEC      = (    43.43     "
	    " 0.          0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 218320, "           BODY806_PM            = (   258.09    8"
	    "39.6597686   0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 218400, "           BODY806_LONG_AXIS     = (     0.       "
	    "                )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 218480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 218560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 218640, "           BODY806_NUT_PREC_RA   = (    0.70      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 218720, "                                       -0.07      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 218800, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 218880, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 218960, "                                        0.        "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 219040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 219120, "           BODY806_NUT_PREC_DEC  = (   -0.51      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 219200, "                                       -0.05      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 219280, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 219360, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 219440, "                                        0.        "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 219520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 219600, "           BODY806_NUT_PREC_PM   = (   -0.48      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 219680, "                                        0.05      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 219760, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 219840, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 219920, "                                        0.        "
	    "                     )", (ftnlen)80, (ftnlen)72);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 220000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 220080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 220160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 220240, "     Larissa", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 220320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 220400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 220480, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 220560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 220640, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 220720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 220800, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 220880, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 220960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 221040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 221120, "           BODY807_POLE_RA       = (   299.36     "
	    "0.           0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 221200, "           BODY807_POLE_DEC      = (    43.41     "
	    "0.           0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 221280, "           BODY807_PM            = (   179.41  +64"
	    "9.0534470    0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 221360, "           BODY807_LONG_AXIS     = (     0.       "
	    "                )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 221440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 221520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 221600, "           BODY807_NUT_PREC_RA   = (    0.70      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 221680, "                                        0.       -"
	    "0.27     0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 221760, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 221840, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 221920, "                                        0.        "
	    "                    )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 222000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 222080, "           BODY807_NUT_PREC_DEC  = (   -0.51      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 222160, "                                        0.       -"
	    "0.20     0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 222240, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 222320, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 222400, "                                        0.        "
	    "                    )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 222480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 222560, "           BODY807_NUT_PREC_PM   = (   -0.48      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 222640, "                                        0.        "
	    "0.19     0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 222720, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 222800, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 222880, "                                        0.        "
	    "                    )", (ftnlen)80, (ftnlen)71);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 222960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 223040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 223120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 223200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 223280, "     Proteus", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 223360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 223440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 223520, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 223600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 223680, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 223760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 223840, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 223920, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 224000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 224080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 224160, "           BODY808_POLE_RA       = (  299.27      "
	    "0.          0.  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 224240, "           BODY808_POLE_DEC      = (   42.91      "
	    "0.          0.  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 224320, "           BODY808_PM            = (   93.38   +32"
	    "0.7654228   0.  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 224400, "           BODY808_LONG_AXIS     = (    0.        "
	    "                )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 224480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 224560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 224640, "           BODY808_NUT_PREC_RA   = (    0.70      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 224720, "                                        0.        "
	    "0.      -0.05    0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 224800, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 224880, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 224960, "                                        0.        "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 225040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 225120, "           BODY808_NUT_PREC_DEC  = (   -0.51      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 225200, "                                        0.        "
	    "0.      -0.04    0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 225280, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 225360, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 225440, "                                        0.        "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 225520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 225600, "           BODY808_NUT_PREC_PM   = (   -0.48      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 225680, "                                        0.        "
	    "0.       0.04    0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 225760, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 225840, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 225920, "                                        0.        "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 226000, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 226080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 226160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 226240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 226320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 226400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 226480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 226560, "Satellites of Pluto", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 226640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 226720, "     Charon", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 226800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 226880, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 226960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 227040, "           Values are from the 2003 IAU report.", (
	    ftnlen)80, (ftnlen)47);
    s_copy(pck + 227120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 227200, "           body901_pole_ra       = (   313.02     "
	    "0.         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 227280, "           body901_pole_dec      = (     9.09     "
	    "0.         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 227360, "           body901_pm            = (    56.77   -5"
	    "6.3623195  0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 227440, "           body901_long_axis     = (     0.       "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 227520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 227600, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 227680, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 227760, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 227840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 227920, "           BODY901_POLE_RA       = (   312.993    "
	    "0.         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 228000, "           BODY901_POLE_DEC      = (     6.163    "
	    "0.         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 228080, "           BODY901_PM            = (    57.305  -5"
	    "6.3625225  0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 228160, "           BODY901_LONG_AXIS     = (     0.       "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 228240, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 228320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 228400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 228480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 228560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 228640, "Orientation constants for Selected Comets and Aste"
	    "roids", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 228720, "--------------------------------------------------"
	    "------", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 228800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 228880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 228960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 229040, "19P/Borrelly", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 229120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 229200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 229280, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 229360, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 229440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 229520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 229600, "           BODY1000005_POLE_RA       = (   218.5  "
	    "    0.         0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 229680, "           BODY1000005_POLE_DEC      = (   -12.5  "
	    "    0.         0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 229760, "           BODY1000005_PM            = (   000.   "
	    "  390.0        0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 229840, "           BODY1000005_LONG_AXIS     = (     0.   "
	    "                   )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 229920, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 230000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 230080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 230160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 230240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 230320, "9P/Tempel 1", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 230400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 230480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 230560, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 230640, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 230720, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 230800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 230880, "           BODY1000093_POLE_RA       = (   294.   "
	    "    0.         0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 230960, "           BODY1000093_POLE_DEC      = (    73.   "
	    "    0.         0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 231040, "           BODY1000093_PM            = (   252.63 "
	    "  212.064      0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 231120, "           BODY1000093_LONG_AXIS     = (     0.   "
	    "                   )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 231200, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 231280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 231360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 231440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 231520, "Vesta", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 231600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 231680, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 231760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 231840, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 231920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 232000, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 232080, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 232160, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 232240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 232320, "           BODY2000004_POLE_RA       = (   301.   "
	    "   0.         0.  )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 232400, "           BODY2000004_POLE_DEC      = (    41.   "
	    "   0.         0.  )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 232480, "           BODY2000004_PM            = (   292.   "
	    "1617.332776   0.  )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 232560, "           BODY2000004_LONG_AXIS     = (     0.   "
	    "                  )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 232640, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 232720, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 232800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 232880, "Eros", (ftnlen)80, (ftnlen)4);
    s_copy(pck + 232960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 233040, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 233120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 233200, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 233280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 233360, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 233440, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 233520, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 233600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 233680, "           BODY2000433_POLE_RA       = (   11.35  "
	    "     0.           0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 233760, "           BODY2000433_POLE_DEC      = (   17.22  "
	    "     0.           0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 233840, "           BODY2000433_PM            = (  326.07  "
	    "  1639.38864745   0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 233920, "           BODY2000433_LONG_AXIS     = (    0.    "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 234000, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 234080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 234160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 234240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 234320, "Itokawa", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 234400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 234480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 234560, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 234640, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 234720, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 234800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 234880, "           BODY2025143_POLE_RA       = (   90.53  "
	    "     0.           0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 234960, "           BODY2025143_POLE_DEC      = (  -66.30  "
	    "     0.           0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 235040, "           BODY2025143_PM            = (  000.0   "
	    "   712.143        0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 235120, "           BODY2025143_LONG_AXIS     = (    0.    "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 235200, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 235280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 235360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 235440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 235520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 235600, "Ida", (ftnlen)80, (ftnlen)3);
    s_copy(pck + 235680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 235760, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 235840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 235920, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 236000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 236080, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 236160, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 236240, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 236320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 236400, "           BODY2431010_POLE_RA       = (  168.76  "
	    "    0.         0. )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 236480, "           BODY2431010_POLE_DEC      = (   -2.88  "
	    "    0.         0. )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 236560, "           BODY2431010_PM            = (  265.95  "
	    "+1864.6280070  0. )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 236640, "           BODY2431010_LONG_AXIS     = (    0.    "
	    "                  )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 236720, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 236800, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 236880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 236960, "Gaspra", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 237040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 237120, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 237200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 237280, "           Values are unchanged in the 2006 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 237360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 237440, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 237520, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 237600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 237680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 237760, "           BODY9511010_POLE_RA       = (   9.47   "
	    "  0.         0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 237840, "           BODY9511010_POLE_DEC      = (  26.70   "
	    "  0.         0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 237920, "           BODY9511010_PM            = (  83.67  1"
	    "226.9114850  0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 238000, "           BODY9511010_LONG_AXIS     = (   0.     "
	    "                )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 238080, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 238160, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 238240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 238320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 238400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 238480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 238560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 238640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 238720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 238800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 238880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 238960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 239040, "Radii of Sun and Planets", (ftnlen)80, (ftnlen)24);
    s_copy(pck + 239120, "--------------------------------------------------"
	    "------", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 239200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 239280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 239360, "Sun", (ftnlen)80, (ftnlen)3);
    s_copy(pck + 239440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 239520, "     Value for the Sun is from the [3], page K7.", (
	    ftnlen)80, (ftnlen)48);
    s_copy(pck + 239600, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 239680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 239760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 239840, "        BODY10_RADII      = (   696000.     696000"
	    ".      696000.     )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 239920, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 240000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 240080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 240160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 240240, "Mercury", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 240320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 240400, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 240480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 240560, "        Values are unchanged in the 2006 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 240640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 240720, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 240800, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 240880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 240960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 241040, "        BODY199_RADII     = ( 2439.7   2439.7   24"
	    "39.7 )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 241120, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 241200, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 241280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 241360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 241440, "Venus", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 241520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 241600, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 241680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 241760, "        Values are unchanged in the 2006 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 241840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 241920, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 242000, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 242080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 242160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 242240, "        BODY299_RADII     = ( 6051.8   6051.8   60"
	    "51.8 )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 242320, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 242400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 242480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 242560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 242640, "Earth", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 242720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 242800, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 242880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 242960, "        Values are unchanged in the 2006 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 243040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 243120, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 243200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 243280, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 243360, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 243440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 243520, "        BODY399_RADII     = ( 6378.14   6378.14   "
	    "6356.75 )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 243600, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 243680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 243760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 243840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 243920, "Mars", (ftnlen)80, (ftnlen)4);
    s_copy(pck + 244000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 244080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 244160, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 244240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 244320, "        body499_radii       = (     3397.      339"
	    "7.         3375.     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 244400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 244480, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 244560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 244640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 244720, "        The IAU report gives separate values for t"
	    "he north and south", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 244800, "        polar radii:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 244880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 244960, "           north:  3373.19", (ftnlen)80, (ftnlen)26)
	    ;
    s_copy(pck + 245040, "           south:  3379.21", (ftnlen)80, (ftnlen)26)
	    ;
    s_copy(pck + 245120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 245200, "        We use the average of these values as the "
	    "polar radius for", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 245280, "        the triaxial model.", (ftnlen)80, (ftnlen)
	    27);
    s_copy(pck + 245360, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 245440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 245520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 245600, "        BODY499_RADII       = ( 3396.19   3396.19 "
	    "  3376.20 )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 245680, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 245760, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 245840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 245920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 246000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 246080, "Jupiter", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 246160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 246240, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 246320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 246400, "        Values are unchanged in the 2006 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 246480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 246560, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 246640, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 246720, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 246800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 246880, "        BODY599_RADII     = ( 71492   71492   6685"
	    "4 )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 246960, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 247040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 247120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 247200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 247280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 247360, "Saturn", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 247440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 247520, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 247600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 247680, "        Values are unchanged in the 2006 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 247760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 247840, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 247920, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 248000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 248080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 248160, "        BODY699_RADII     = ( 60268   60268   5436"
	    "4 )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 248240, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 248320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 248400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 248480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 248560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 248640, "Uranus", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 248720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 248800, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 248880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 248960, "        Values are unchanged in the 2006 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 249040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 249120, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 249200, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 249280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 249360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 249440, "        BODY799_RADII     = ( 25559   25559   2497"
	    "3 )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 249520, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 249600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 249680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 249760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 249840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 249920, "Neptune", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 250000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 250080, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 250160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 250240, "        Values are unchanged in the 2006 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 250320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 250400, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 250480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 250560, "        (Values are for the 1 bar pressure level.)",
	     (ftnlen)80, (ftnlen)50);
    s_copy(pck + 250640, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 250720, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 250800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 250880, "        BODY899_RADII     = ( 24764   24764  24341"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 250960, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 251040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 251120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 251200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 251280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 251360, "Pluto", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 251440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 251520, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 251600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 251680, "        Values are unchanged in the 2006 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 251760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 251840, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 251920, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 252000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 252080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 252160, "        BODY999_RADII     = ( 1195   1195   1195 )",
	     (ftnlen)80, (ftnlen)50);
    s_copy(pck + 252240, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 252320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 252400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 252480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 252560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 252640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 252720, "Radii of Satellites", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 252800, "--------------------------------------------------"
	    "------", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 252880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 252960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 253040, "Moon", (ftnlen)80, (ftnlen)4);
    s_copy(pck + 253120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 253200, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 253280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 253360, "        Values are unchanged in the 2006 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 253440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 253520, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 253600, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 253680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 253760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 253840, "        BODY301_RADII     = ( 1737.4   1737.4   17"
	    "37.4 )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 253920, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 254000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 254080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 254160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 254240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 254320, "Satellites of Mars", (ftnlen)80, (ftnlen)18);
    s_copy(pck + 254400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 254480, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 254560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 254640, "        Values are unchanged in the 2006 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 254720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 254800, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 254880, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 254960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 255040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 255120, "        BODY401_RADII     = ( 13.4    11.2    9.2 )"
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 255200, "        BODY402_RADII     = (  7.5     6.1    5.2 )"
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 255280, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 255360, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 255440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 255520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 255600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 255680, "Satellites of Jupiter", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 255760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 255840, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 255920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 256000, "        Values are unchanged in the 2006 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 256080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 256160, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 256240, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 256320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 256400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 256480, "        BODY501_RADII     = ( 1829.4   1819.3   18"
	    "15.7  )", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 256560, "        BODY502_RADII     = ( 1564.13  1561.23  15"
	    "60.93 )", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 256640, "        BODY503_RADII     = ( 2632.4   2632.29  26"
	    "32.35 )", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 256720, "        BODY504_RADII     = ( 2409.4   2409.2   24"
	    "09.3  )", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 256800, "        BODY505_RADII     = (  125       73       "
	    "64    )", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 256880, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 256960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 257040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 257120, "        Only mean radii are available in the 2003 "
	    "IAU report for bodies", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 257200, "        506-513.", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 257280, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 257360, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 257440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 257520, "        BODY506_RADII    = (    85       85       "
	    "85   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 257600, "        BODY507_RADII    = (    40       40       "
	    "40   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 257680, "        BODY508_RADII    = (    18       18       "
	    "18   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 257760, "        BODY509_RADII    = (    14       14       "
	    "14   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 257840, "        BODY510_RADII    = (    12       12       "
	    "12   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 257920, "        BODY511_RADII    = (    15       15       "
	    "15   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 258000, "        BODY512_RADII    = (    10       10       "
	    "10   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 258080, "        BODY513_RADII    = (     5        5       "
	    " 5   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 258160, "        BODY514_RADII    = (    58       49       "
	    "42   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 258240, "        BODY515_RADII    = (    10        8       "
	    " 7   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 258320, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 258400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 258480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 258560, "        The value for the second radius for body 5"
	    "16 is not given in", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 258640, "        2003 IAU report.   The values given are:", (
	    ftnlen)80, (ftnlen)48);
    s_copy(pck + 258720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 258800, "           BODY516_RADII    = (  30   ---   20   )",
	     (ftnlen)80, (ftnlen)50);
    s_copy(pck + 258880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 258960, "        For use within the SPICE system, we use on"
	    "ly the mean radius.", (ftnlen)80, (ftnlen)69);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 259040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 259120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 259200, "        BODY516_RADII    = (  21.5   21.5  21.5  )",
	     (ftnlen)80, (ftnlen)50);
    s_copy(pck + 259280, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 259360, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 259440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 259520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 259600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 259680, "Satellites of Saturn", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 259760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 259840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 259920, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 260000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 260080, "        Values are from the 2003 IAU report.", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 260160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 260240, "        body601_radii     = (  209.1   196.2   191"
	    ".4 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 260320, "        body602_radii     = (  256.3   247.3   244"
	    ".6 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 260400, "        body603_radii     = (  535.6   528.2   525"
	    ".8 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 260480, "        body604_radii     = (  560     560     560"
	    "   )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 260560, "        body605_radii     = (  764     764     764"
	    "   )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 260640, "        body606_radii     = ( 2575    2575    2575"
	    "   )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 260720, "        body607_radii     = (  164     130     107"
	    "   )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 260800, "        body608_radii     = (  718     718     718"
	    "   )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 260880, "        body609_radii     = (  115     110     105"
	    "   )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 260960, "        body610_radii     = (   97.0    95.0    77"
	    ".0 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 261040, "        body611_radii     = (   69.0    55.0    55"
	    ".0 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 261120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 261200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 261280, "        Only the first equatorial radius for Helen"
	    "e (body 612) was given in the", (ftnlen)80, (ftnlen)79);
    s_copy(pck + 261360, "        2003 IAU report:", (ftnlen)80, (ftnlen)24);
    s_copy(pck + 261440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 261520, "            body612_radii     = (       17.5      "
	    "  ---          ---     )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 261600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 261680, "        The mean radius was 16km; we used this rad"
	    "ius for all three axes, as", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 261760, "        we do for the satellites for which only th"
	    "e mean radius is available.", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 261840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 261920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 262000, "        body612_radii     = (   16      16       1"
	    "6  )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 262080, "        body613_radii     = (   15      12.5     7"
	    ".5 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 262160, "        body614_radii     = (   15.0     8.0     8"
	    ".0 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 262240, "        body615_radii     = (   18.5    17.2    13"
	    ".5 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 262320, "        body616_radii     = (   74.0    50.0    34"
	    ".0 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 262400, "        body617_radii     = (   55.0    44.0    31"
	    ".0 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 262480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 262560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 262640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 262720, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 262800, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 262880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 262960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 263040, "        BODY601_RADII     = (  207.4     196.8    "
	    " 190.6  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 263120, "        BODY602_RADII     = (  256.6     251.4    "
	    " 248.3  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 263200, "        BODY603_RADII     = (  540.4     531.1    "
	    " 527.5  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 263280, "        BODY604_RADII     = (  563.8     561.0    "
	    " 560.3  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 263360, "        BODY605_RADII     = (  767.2     762.5    "
	    " 763.1  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 263440, "        BODY606_RADII     = ( 2575      2575      "
	    "2575    )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 263520, "        BODY607_RADII     = (  164       130      "
	    " 107    )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 263600, "        BODY608_RADII     = (  747.4     747.4    "
	    " 712.4  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 263680, "        BODY609_RADII     = (  108.6     107.7    "
	    " 101.5  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 263760, "        BODY610_RADII     = (   97.0      95.0    "
	    "  77.0  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 263840, "        BODY611_RADII     = (   69.0      55.0    "
	    "  55.0  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 263920, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 264000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 264080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 264160, "        Only the first equatorial radius for Helen"
	    "e (body 612) is given in the", (ftnlen)80, (ftnlen)78);
    s_copy(pck + 264240, "        2006 IAU report:", (ftnlen)80, (ftnlen)24);
    s_copy(pck + 264320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 264400, "            BODY612_RADII     = (       17.5      "
	    "  ---          ---     )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 264480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 264560, "        The mean radius is 16km; we use this radiu"
	    "s for all three axes, as", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 264640, "        we do for the satellites for which only th"
	    "e mean radius is available.", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 264720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 264800, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 264880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 264960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 265040, "        BODY612_RADII     = (  17.5      17.5     "
	    " 17.5  )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 265120, "        BODY613_RADII     = (  15        12.5     "
	    "  7.5  )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 265200, "        BODY614_RADII     = (  15.0       8.0     "
	    "  8.0  )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 265280, "        BODY615_RADII     = (  18.5      17.2     "
	    " 13.5  )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 265360, "        BODY616_RADII     = (  74.0      50.0     "
	    " 34.0  )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 265440, "        BODY617_RADII     = (  55.0      44.0     "
	    " 31.0  )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 265520, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 265600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 265680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 265760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 265840, "         For Pan, only a mean radius is given in t"
	    "he 2006 report.", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 265920, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 266000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 266080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 266160, "        BODY618_RADII     = (   10       10     10"
	    "   )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 266240, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 266320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 266400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 266480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 266560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 266640, "Satellites of Uranus", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 266720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 266800, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 266880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 266960, "        Values are unchanged in the 2006 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 267040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 267120, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 267200, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 267280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 267360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 267440, "        BODY701_RADII     = (  581.1   577.9   577"
	    ".7 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 267520, "        BODY702_RADII     = (  584.7   584.7   584"
	    ".7 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 267600, "        BODY703_RADII     = (  788.9   788.9   788"
	    ".9 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 267680, "        BODY704_RADII     = (  761.4   761.4   761"
	    ".4 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 267760, "        BODY705_RADII     = (  240.4   234.2   232"
	    ".9 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 267840, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 267920, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 268000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 268080, "        The 2000 report gives only mean radii for "
	    "satellites 706--715.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 268160, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 268240, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 268320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 268400, "        BODY706_RADII     = (   13      13      13"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 268480, "        BODY707_RADII     = (   15      15      15"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 268560, "        BODY708_RADII     = (   21      21      21"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 268640, "        BODY709_RADII     = (   31      31      31"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 268720, "        BODY710_RADII     = (   27      27      27"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 268800, "        BODY711_RADII     = (   42      42      42"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 268880, "        BODY712_RADII     = (   54      54      54"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 268960, "        BODY713_RADII     = (   27      27      27"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 269040, "        BODY714_RADII     = (   33      33      33"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 269120, "        BODY715_RADII     = (   77      77      77"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 269200, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 269280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 269360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 269440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 269520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 269600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 269680, "Satellites of Neptune", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 269760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 269840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 269920, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 270000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 270080, "        Values are unchanged in the 2006 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 270160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 270240, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 270320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 270400, "        The 2000 report gives mean radii only for "
	    "bodies 801-806.", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 270480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 270560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 270640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 270720, "        BODY801_RADII     = ( 1352.6  1352.6  1352"
	    ".6 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 270800, "        BODY802_RADII     = (  170     170     170"
	    "   )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 270880, "        BODY803_RADII     = (   29      29     29 "
	    "   )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 270960, "        BODY804_RADII     = (   40      40     40 "
	    "   )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 271040, "        BODY805_RADII     = (   74      74     74 "
	    "   )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 271120, "        BODY806_RADII     = (   79      79     79 "
	    "   )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 271200, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 271280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 271360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 271440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 271520, "        The second equatorial radius for Larissa i"
	    "s not given in the 2000", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 271600, "        report.  The available values are:", (
	    ftnlen)80, (ftnlen)42);
    s_copy(pck + 271680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 271760, "            BODY807_RADII     = (   104     ---   "
	    "  89   )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 271840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 271920, "        For use within the SPICE system, we use on"
	    "ly the mean radius.", (ftnlen)80, (ftnlen)69);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 272000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 272080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 272160, "        BODY807_RADII     = (   96      96     96 "
	    "  )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 272240, "        BODY808_RADII     = (  218     208    201 "
	    "  )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 272320, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 272400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 272480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 272560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 272640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 272720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 272800, "Satellites of Pluto", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 272880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 272960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 273040, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 273120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 273200, "        Values are from the 2003 IAU report.", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 273280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 273360, "        BODY901_RADII     = (  593     593    593 "
	    "  )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 273440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 273520, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 273600, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 273680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 273760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 273840, "        BODY901_RADII     = (  605     605    605 "
	    "  )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 273920, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 274000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 274080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 274160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 274240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 274320, "Radii for Selected Comets and Asteroids", (ftnlen)
	    80, (ftnlen)39);
    s_copy(pck + 274400, "--------------------------------------------------"
	    "------", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 274480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 274560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 274640, "19P/Borrelly", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 274720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 274800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 274880, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 274960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 275040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 275120, "        The value in the data assignment below is "
	    "the", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 275200, "        \"effective radius.\"", (ftnlen)80, (ftnlen)
	    27);
    s_copy(pck + 275280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 275360, "        The first principal axis length is", (
	    ftnlen)80, (ftnlen)42);
    s_copy(pck + 275440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 275520, "           3.5 km", (ftnlen)80, (ftnlen)17);
    s_copy(pck + 275600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 275680, "        The lengths of the other semi-axes are not"
	    " provided", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 275760, "        by [1].", (ftnlen)80, (ftnlen)15);
    s_copy(pck + 275840, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 275920, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 276000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 276080, "        BODY1000005_RADII     = (  4.22   4.22   4"
	    ".22  )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 276160, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 276240, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 276320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 276400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 276480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 276560, "Halley", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 276640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 276720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 276800, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 276880, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 276960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 277040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 277120, "        BODY1000036_RADII     = (  8.0   4.0   4.0"
	    "  )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 277200, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 277280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 277360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 277440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 277520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 277600, "9P/Tempel 1", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 277680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 277760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 277840, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 277920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 278000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 278080, "        The value in the data assignment below is "
	    "the", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 278160, "        \"effective radius.\"", (ftnlen)80, (ftnlen)
	    27);
    s_copy(pck + 278240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 278320, "        According to [1]:", (ftnlen)80, (ftnlen)25);
    s_copy(pck + 278400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 278480, "           The maximum and minimum radii are not p"
	    "roperly", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 278560, "           the values of the principal semi-axes, "
	    "they", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 278640, "           are half the maximum and minimum values"
	    " of the", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 278720, "           diameter. Due to the large deviations f"
	    "rom a", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 278800, "           simple ellipsoid, they may not correspo"
	    "nd with", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 278880, "           measurements along the principal axes, "
	    "or be", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 278960, "           orthogonal to each other.", (ftnlen)80, (
	    ftnlen)36);
    s_copy(pck + 279040, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 279120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 279200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 279280, "        BODY1000093_RADII     = (  3.0   3.0   3.0"
	    "  )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 279360, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 279440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 279520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 279600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 279680, "81P/Wild 2", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 279760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 279840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 279920, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 280000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 280080, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 280160, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 280240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 280320, "        BODY1000107_RADII     = (  2.7   1.9   1.5"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 280400, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 280480, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 280560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 280640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 280720, "Ceres", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 280800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 280880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 280960, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 281040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 281120, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 281200, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 281280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 281360, "        BODY2000001_RADII     = ( 487.3  487.3  45"
	    "4.7 )", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 281440, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 281520, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 281600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 281680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 281760, "Vesta", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 281840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 281920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 282000, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 282080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 282160, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 282240, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 282320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 282400, "        BODY2000004_RADII     = ( 289.  280.  229."
	    "  )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 282480, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 282560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 282640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 282720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 282800, "Toutatis", (ftnlen)80, (ftnlen)8);
    s_copy(pck + 282880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 282960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 283040, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 283120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 283200, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 283280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 283360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 283440, "        BODY2004179_RADII     = (  2.13  1.015  0."
	    "85  )", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 283520, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 283600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 283680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 283760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 283840, "Kleopatra", (ftnlen)80, (ftnlen)9);
    s_copy(pck + 283920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 284000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 284080, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 284160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 284240, "        Values are from the 2003 report.", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 284320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 284400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 284480, "        body2000216_radii     = (   108.5      47 "
	    "   40.5  )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 284560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 284640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 284720, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 284800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 284880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 284960, "        No values are provided in the 2006 report.",
	     (ftnlen)80, (ftnlen)50);
    s_copy(pck + 285040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 285120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 285200, "Mathilde", (ftnlen)80, (ftnlen)8);
    s_copy(pck + 285280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 285360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 285440, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 285520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 285600, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 285680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 285760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 285840, "        BODY2000253_RADII     = (  33.   24.   23."
	    "  )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 285920, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 286000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 286080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 286160, "Eros", (ftnlen)80, (ftnlen)4);
    s_copy(pck + 286240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 286320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 286400, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 286480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 286560, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 286640, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 286720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 286800, "        BODY2000433_RADII     = (  17.0   5.5   5."
	    "5  )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 286880, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 286960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 287040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 287120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 287200, "Itokawa", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 287280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 287360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 287440, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 287520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 287600, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 287680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 287760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 287840, "        BODY2025143_RADII     = (  0.535   0.294  "
	    " 0.209  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 287920, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 288000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 288080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 288160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 288240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 288320, "Gaspra", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 288400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 288480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 288560, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 288640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 288720, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 288800, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 288880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 288960, "        BODY9511010_RADII     = (    9.1    5.2   "
	    " 4.4 )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 289040, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 289120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 289200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 289280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 289360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 289440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 289520, "Ida", (ftnlen)80, (ftnlen)3);
    s_copy(pck + 289600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 289680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 289760, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 289840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 289920, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 290000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 290080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 290160, "        BODY2431010_RADII     = (   26.8   12.0   "
	    " 7.6 )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 290240, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 290320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 290400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 290480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 290560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 290640, "=================================================="
	    "=========================", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 290720, "End of file pck00009.tpc", (ftnlen)80, (ftnlen)24);
    s_copy(pck + 290800, "=================================================="
	    "=========================", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 290880, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 319840, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 319920, "BODY-10_CONSTANTS_REF_FRAME = 2", (ftnlen)80, (
	    ftnlen)31);
    s_copy(pck + 320000, "BODY-10_CONSTANTS_JED_EPOCH = 2433282.42345905D0", (
	    ftnlen)80, (ftnlen)48);
    s_copy(pck + 320080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 320160, "BODY-10_POLE_RA         = (  286.13       0.      "
	    "    0. )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 320240, "BODY-10_POLE_DEC        = (   63.87       0.      "
	    "    0. )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 320320, "BODY-10_PM              = (   84.176     14.18440 "
	    "    0. )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 320400, "BODY-10_LONG_AXIS       = (  459.00               "
	    "       )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 320480, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 320560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 320640, " ", (ftnlen)80, (ftnlen)1);

/*     Create the PCK kernel. */

    txtopn_(namepc, &unit, namepc_len);
    for (i__ = 1; i__ <= 4009; ++i__) {
	r__ = rtrim_(pck + ((i__3 = i__ - 1) < 4009 && 0 <= i__3 ? i__3 : 
		s_rnge("pck", i__3, "t_pck09__", (ftnlen)5299)) * 80, (ftnlen)
		80);
	writln_(pck + ((i__3 = i__ - 1) < 4009 && 0 <= i__3 ? i__3 : s_rnge(
		"pck", i__3, "t_pck09__", (ftnlen)5301)) * 80, &unit, r__);
    }
    cl__1.cerr = 0;
    cl__1.cunit = unit;
    cl__1.csta = 0;
    f_clos(&cl__1);

/*     If this file needs to be loaded.  Do it now.  If not we are */
/*     done and can return. */

    if (*loadpc) {
	ldpool_(namepc, namepc_len);
	if (*keeppc) {

/*           If we are keeping this file, we need to register it */
/*           with FILREG. */

	    tfiles_(namepc, namepc_len);
	    return 0;
	}
    } else {

/*        We are keeping this file, so we need to register it */
/*        with FILREG. */

	tfiles_(namepc, namepc_len);
	return 0;
    }
    kilfil_(namepc, namepc_len);
    return 0;
} /* t_pck09__ */

