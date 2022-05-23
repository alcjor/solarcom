/* t_pck10.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__3151 = 3151;

/* $Procedure      T_PCK10 (Create a test text PCK based on pck00010.tpc ) */
/* Subroutine */ int t_pck10__(char *namepc, logical *loadpc, logical *keeppc,
	 ftnlen namepc_len)
{
    /* System generated locals */
    integer i__1;
    char ch__1[10];
    cllist cl__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
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
    char pck[80*3151];

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

/* -    Test Utilities 2.0.0, 21-OCT-2011 (NJB) */

/*        Updated to reflect changes for Pluto, Charon, and Ida. */

/* -    Test Utilities 1.0.0, 29-JAN-2011 (WLT) (NJB) */

/* -& */
/* $ Index_Entries */

/*     Create current NAIF text PCK file. */

/* -& */

/*     SPICELIB Functions */


/*     Test Utility Functions */


/*     Local Variables. */

    kilfil_(namepc, namepc_len);
    clearc_(&c__3151, pck, (ftnlen)80);
    s_copy(pck, "Orientation Constants for the Sun and Planets", (ftnlen)80, (
	    ftnlen)45);
    s_copy(pck + 80, "------------------------------------------------------"
	    "--", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 320, "Sun", (ftnlen)80, (ftnlen)3);
    s_copy(pck + 400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 480, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 640, "        Values are unchanged in the 2009 IAU report.", 
	    (ftnlen)80, (ftnlen)52);
    s_copy(pck + 720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 800, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 880, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 1040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 1120, "        BODY10_POLE_RA         = (  286.13       0. "
	    "         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 1200, "        BODY10_POLE_DEC        = (   63.87       0. "
	    "         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 1280, "        BODY10_PM              = (   84.176     14.1"
	    "8440     0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 1360, "        BODY10_LONG_AXIS       = (    0.            "
	    "            )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 1440, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 1520, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 1600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 1680, "Mercury", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 1760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 1840, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 1920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 2000, "        Values are from the 2006 IAU report.", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 2080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 2160, "        body199_pole_ra          = (  281.01     -0."
	    "033      0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 2240, "        body199_pole_dec         = (   61.45     -0."
	    "005      0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 2320, "        body199_pm               = (  329.548     6."
	    "1385025  0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 2400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 2480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 2560, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 2640, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 2720, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 2800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 2880, "        BODY199_POLE_RA          = (  281.0097   -0."
	    "0328     0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 2960, "        BODY199_POLE_DEC         = (   61.4143   -0."
	    "0049     0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 3040, "        BODY199_PM               = (  329.5469    6."
	    "1385025  0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 3120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 3200, "        BODY199_LONG_AXIS        = (    0.          "
	    "              )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 3280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 3360, "        BODY199_NUT_PREC_RA  = ( 0. 0. 0. 0. 0. )", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 3440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 3520, "        BODY199_NUT_PREC_DEC = ( 0. 0. 0. 0. 0. )", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 3600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 3680, "        BODY199_NUT_PREC_PM  = (    0.00993822", (
	    ftnlen)80, (ftnlen)46);
    s_copy(pck + 3760, "                                   -0.00104581", (
	    ftnlen)80, (ftnlen)46);
    s_copy(pck + 3840, "                                   -0.00010280", (
	    ftnlen)80, (ftnlen)46);
    s_copy(pck + 3920, "                                   -0.00002364", (
	    ftnlen)80, (ftnlen)46);
    s_copy(pck + 4000, "                                   -0.00000532  )", (
	    ftnlen)80, (ftnlen)49);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 4080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 4160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 4240, "           The linear coefficients have been scaled "
	    "up from degrees/day", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 4320, "           to degrees/century, because the SPICELIB "
	    "PCK reader expects", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 4400, "           these units.  The original constants were:"
	    , (ftnlen)80, (ftnlen)53);
    s_copy(pck + 4480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 4560, "                                    174.791086      "
	    "4.092335", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 4640, "                                    349.582171      "
	    "8.184670", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 4720, "                                    164.373257     1"
	    "2.277005", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 4800, "                                    339.164343     1"
	    "6.369340", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 4880, "                                    153.955429     2"
	    "0.461675", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 4960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 5040, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 5120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 5200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 5280, "        BODY1_NUT_PREC_ANGLES  = ( 174.791086  0.149"
	    "47253587500003E+06", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 5360, "                                   349.582171  0.298"
	    "94507175000006E+06", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 5440, "                                   164.373257  0.448"
	    "41760762500006E+06", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 5520, "                                   339.164343  0.597"
	    "89014350000012E+06", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 5600, "                                   153.955429  0.747"
	    "36267937499995E+06 )", (ftnlen)80, (ftnlen)72);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 5680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 5760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 5840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 5920, "Venus", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 6000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 6080, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 6160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 6240, "        Values are unchanged in the 2009 IAU report.",
	     (ftnlen)80, (ftnlen)52);
    s_copy(pck + 6320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 6400, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 6480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 6560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 6640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 6720, "        BODY299_POLE_RA          = (  272.76       0"
	    ".          0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 6800, "        BODY299_POLE_DEC         = (   67.16       0"
	    ".          0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 6880, "        BODY299_PM               = (  160.20      -1"
	    ".4813688   0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 6960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 7040, "        BODY299_LONG_AXIS        = (    0.          "
	    "              )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 7120, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 7200, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 7280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 7360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 7440, "Earth", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 7520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 7600, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 7680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 7760, "        Values are unchanged in the 2009 report.", (
	    ftnlen)80, (ftnlen)48);
    s_copy(pck + 7840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 7920, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 8000, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 8080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 8160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 8240, "        BODY399_POLE_RA        = (    0.      -0.641"
	    "         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 8320, "        BODY399_POLE_DEC       = (   90.      -0.557"
	    "         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 8400, "        BODY399_PM             = (  190.147  360.985"
	    "6235     0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 8480, "        BODY399_LONG_AXIS      = (    0.            "
	    "            )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 8560, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 8640, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 8720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 8800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 8880, "        Nutation precession angles for the Earth-Moo"
	    "n system:", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 8960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 9040, "           The linear coefficients have been scaled "
	    "up from degrees/day", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 9120, "           to degrees/century, because the SPICELIB "
	    "PCK reader expects", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 9200, "           these units.  The original constants were:"
	    , (ftnlen)80, (ftnlen)53);
    s_copy(pck + 9280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 9360, "                                    125.045D0   -0.0"
	    "529921D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 9440, "                                    250.089D0   -0.1"
	    "059842D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 9520, "                                    260.008D0   13.0"
	    "120009D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 9600, "                                    176.625D0   13.3"
	    "407154D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 9680, "                                    357.529D0    0.9"
	    "856003D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 9760, "                                    311.589D0   26.4"
	    "057084D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 9840, "                                    134.963D0   13.0"
	    "649930D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 9920, "                                    276.617D0    0.3"
	    "287146D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 10000, "                                     34.226D0    1."
	    "7484877D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 10080, "                                     15.134D0   -0."
	    "1589763D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 10160, "                                    119.743D0    0."
	    "0036096D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 10240, "                                    239.961D0    0."
	    "1643573D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 10320, "                                     25.053D0   12."
	    "9590088D0", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 10400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 10480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 10560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 10640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 10720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 10800, "        BODY3_NUT_PREC_ANGLES  = (  125.045        "
	    " -1935.5364525000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 10880, "                                    250.089        "
	    " -3871.0729050000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 10960, "                                    260.008        "
	    "475263.3328725000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 11040, "                                    176.625        "
	    "487269.6299850000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 11120, "                                    357.529        "
	    " 35999.0509575000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 11200, "                                    311.589        "
	    "964468.4993100000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 11280, "                                    134.963        "
	    "477198.8693250000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 11360, "                                    276.617        "
	    " 12006.3007650000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 11440, "                                     34.226        "
	    " 63863.5132425000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 11520, "                                     15.134        "
	    " -5806.6093575000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 11600, "                                    119.743        "
	    "   131.8406400000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 11680, "                                    239.961        "
	    "  6003.1503825000", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 11760, "                                     25.053        "
	    "473327.7964200000 )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 11840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 11920, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 12000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 12080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 12160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 12240, "     Earth north geomagnetic centered dipole:", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 12320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 12400, "           The north dipole location is time-varyin"
	    "g.  The values shown", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 12480, "           below, taken from [8], represent a discr"
	    "ete sampling of the", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 12560, "           north dipole location from 1945 to 2000."
	    " The terms DGRF and", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 12640, "           IGRF refer to, respectively, \"Definitiv"
	    "e Geomagnetic", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 12720, "           Reference Field\" and \"International Ge"
	    "omagnetic Reference", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 12800, "           Field.\"  See references [6], [8], and ["
	    "9] for details.", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 12880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 12960, "           Coordinates are planetocentric.", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 13040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 13120, "             Data source    Lat      Lon", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 13200, "             -----------   -----    ------", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 13280, "              DGRF 1945    78.47    291.47", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 13360, "              DGRF 1950    78.47    291.15", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 13440, "              DGRF 1955    78.46    290.84", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 13520, "              DGRF 1960    78.51    290.53", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 13600, "              DGRF 1965    78.53    290.15", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 13680, "              DGRF 1970    78.59    289.82", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 13760, "              DGRF 1975    78.69    289.53", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 13840, "              DGRF 1980    78.81    289.24", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 13920, "              DGRF 1985    78.97    289.10", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 14000, "              DGRF 1990    79.13    288.89", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 14080, "              IGRF 1995    79.30    288.59", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 14160, "              IGRF 2000    79.54    288.43", (ftnlen)
	    80, (ftnlen)42);
    s_copy(pck + 14240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 14320, "        Original values:", (ftnlen)80, (ftnlen)24);
    s_copy(pck + 14400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 14480, "           Values are from [7].  Note the year of p"
	    "ublication was 1971.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 14560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 14640, "           body399_mag_north_pole_lon  =  ( -69.761"
	    " )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 14720, "           body399_mag_north_pole_lat  =  (  78.565"
	    " )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 14800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 14880, "        Previous values:", (ftnlen)80, (ftnlen)24);
    s_copy(pck + 14960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 15040, "           body399_n_geomag_ctr_dipole_lon  =  ( 28"
	    "8.43 )", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 15120, "           body399_n_geomag_ctr_dipole_lat  =  (  7"
	    "9.54 )", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 15200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 15280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 15360, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 15440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 15520, "           Values are given for the epoch 2012.0 an"
	    "d were derived", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 15600, "           by Nat Bachman from constants provided b"
	    "y [11].", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 15680, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 15760, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 15840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 15920, "        BODY399_N_GEOMAG_CTR_DIPOLE_LON  =  ( 287.6"
	    "2 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 16000, "        BODY399_N_GEOMAG_CTR_DIPOLE_LAT  =  (  80.1"
	    "3 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 16080, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 16160, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 16240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 16320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 16400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 16480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 16560, "Mars", (ftnlen)80, (ftnlen)4);
    s_copy(pck + 16640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 16720, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 16800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 16880, "        Values are unchanged in the 2009 IAU report."
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 16960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 17040, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 17120, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 17200, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 17280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 17360, "        BODY499_POLE_RA          = (  317.68143   -"
	    "0.1061      0.  )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 17440, "        BODY499_POLE_DEC         = (   52.88650   -"
	    "0.0609      0.  )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 17520, "        BODY499_PM               = (  176.630    35"
	    "0.89198226  0.  )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 17600, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 17680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 17760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 17840, "        Source [5] specifies the following value fo"
	    "r the lambda_a term", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 17920, "        (BODY499_LONG_AXIS ) for Mars. This term is"
	    " the POSITIVE EAST", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 18000, "        LONGITUDE, measured from the prime meridian"
	    ", of the meridian", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 18080, "        containing the longest axis of the referenc"
	    "e ellipsoid.", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 18160, "        (CAUTION: previous values were POSITIVE WES"
	    "T.)", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 18240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 18320, "           body499_long_axis        = (  252.  )", (
	    ftnlen)80, (ftnlen)48);
    s_copy(pck + 18400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 18480, "        We list this lambda_a value for completenes"
	    "s. The IAU report", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 18560, "        [1] gives equal values for both equatorial "
	    "radii, so the", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 18640, "        lambda_a offset does not apply to the IAU m"
	    "odel.", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 18720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 18800, "        The 2003 IAU report defines M2, the second "
	    "nutation precession angle,", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 18880, "        by:", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 18960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 19040, "                                                2", (
	    ftnlen)80, (ftnlen)49);
    s_copy(pck + 19120, "           192.93  +  1128.4096700 d  +  8.864 T", (
	    ftnlen)80, (ftnlen)48);
    s_copy(pck + 19200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 19280, "        We truncate the M2 series to a linear expre"
	    "ssion, because the PCK", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 19360, "        software cannot handle the quadratic term.", 
	    (ftnlen)80, (ftnlen)50);
    s_copy(pck + 19440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 19520, "        Again, the linear terms are scaled by 36525"
	    ".0:", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 19600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 19680, "            -0.4357640000000000       -->     -1591"
	    "6.28010000000", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 19760, "          1128.409670000000           -->   4121516"
	    "3.19675000", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 19840, "            -1.8151000000000000E-02   -->       -66"
	    "2.9652750000000", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 19920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 20000, "        We also introduce a fourth nutation precess"
	    "ion angle, which", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 20080, "        is the pi/2-complement of the third angle. "
	    " This angle is used", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 20160, "        in computing the prime meridian location fo"
	    "r Deimos.  See the", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 20240, "        discussion of this angle below in the secti"
	    "on containing orientation", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 20320, "        constants for Deimos.", (ftnlen)80, (ftnlen)
	    29);
    s_copy(pck + 20400, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 20480, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 20560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 20640, "        BODY4_NUT_PREC_ANGLES  = (  169.51     -159"
	    "16.2801", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 20720, "                                    192.93   412151"
	    "63.19675", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 20800, "                                     53.47       -6"
	    "62.965275", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 20880, "                                     36.53        6"
	    "62.965275  )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 20960, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 21040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 21120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 21200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 21280, "Jupiter", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 21360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 21440, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 21520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 21600, "        The rotation rate is from the 2006 IAU repo"
	    "rt; all other", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 21680, "        values are unchanged in the 2009 report.", (
	    ftnlen)80, (ftnlen)48);
    s_copy(pck + 21760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 21840, "           body599_pm             = (   284.95     "
	    "   870.5366420      0. )", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 21920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 22000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 22080, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 22160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 22240, "        The number of nutation precession angles is"
	    " 15. The ninth and", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 22320, "        tenth are twice the first and second, respe"
	    "ctively. The", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 22400, "        eleventh through fifteenth correspond to an"
	    "gles JA-JE in", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 22480, "        the 2006 IAU report; angles JA-JE were not "
	    "used prior to that", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 22560, "        report.", (ftnlen)80, (ftnlen)15);
    s_copy(pck + 22640, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 22720, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 22800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 22880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 22960, "        BODY599_POLE_RA        = (   268.056595    "
	    " -0.006499       0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 23040, "        BODY599_POLE_DEC       = (    64.495303    "
	    "  0.002413       0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 23120, "        BODY599_PM             = (   284.95        "
	    "870.5360000      0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 23200, "        BODY599_LONG_AXIS      = (     0.          "
	    "              )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 23280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 23360, "        BODY599_NUT_PREC_RA  = ( 0. 0. 0. 0. 0. 0. "
	    "0. 0. 0. 0.  0.000117", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 23440, "                                                   "
	    "             0.000938", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 23520, "                                                   "
	    "             0.001432", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 23600, "                                                   "
	    "             0.000030", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 23680, "                                                   "
	    "             0.002150 )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 23760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 23840, "        BODY599_NUT_PREC_DEC = ( 0. 0. 0. 0. 0. 0. "
	    "0. 0. 0. 0.  0.000050", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 23920, "                                                   "
	    "             0.000404", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 24000, "                                                   "
	    "             0.000617", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 24080, "                                                   "
	    "            -0.000013", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 24160, "                                                   "
	    "             0.000926 )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 24240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 24320, "        BODY599_NUT_PREC_PM  = ( 0. 0. 0. 0. 0. 0. "
	    "0. 0. 0. 0.  0.0", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 24400, "                                                   "
	    "             0.0", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 24480, "                                                   "
	    "             0.0", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 24560, "                                                   "
	    "             0.0", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 24640, "                                                   "
	    "             0.0  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 24720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 24800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 24880, "        BODY5_NUT_PREC_ANGLES  = (    73.32      91"
	    "472.9", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 24960, "                                      24.62      45"
	    "137.2", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 25040, "                                     283.90       4"
	    "850.7", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 25120, "                                     355.80       1"
	    "191.3", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 25200, "                                     119.90        "
	    "262.1", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 25280, "                                     229.80        "
	    " 64.3", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 25360, "                                     352.25       2"
	    "382.6", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 25440, "                                     113.35       6"
	    "070.0", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 25520, "                                     146.64     182"
	    "945.8", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 25600, "                                      49.24      90"
	    "274.4", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 25680, "                                      99.360714   4"
	    "850.4046", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 25760, "                                     175.895369   1"
	    "191.9605", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 25840, "                                     300.323162    "
	    "262.5475", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 25920, "                                     114.012305   6"
	    "070.2476", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 26000, "                                      49.511251    "
	    " 64.3000  )", (ftnlen)80, (ftnlen)62);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 26080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 26160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 26240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 26320, "Saturn", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 26400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 26480, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 26560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 26640, "        Values are from the 2006 IAU report.", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 26720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 26800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 26880, "        body699_pole_ra        = (    40.589    -0."
	    "036      0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 26960, "        body699_pole_dec       = (    83.537    -0."
	    "004      0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 27040, "        body699_pm             = (    38.90    810."
	    "7939024  0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 27120, "        body699_long_axis      = (     0.          "
	    "             )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 27200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 27280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 27360, "        The first seven angles given here are the a"
	    "ngles S1", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 27440, "        through S7 from the 2000 report; the eighth"
	    " and", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 27520, "        ninth angles are 2*S1 and 2*S2, respectivel"
	    "y.", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 27600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 27680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 27760, "        body6_nut_prec_angles  = (  353.32   75706.7"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 27840, "                                     28.72   75706.7"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 27920, "                                    177.40  -36505.5"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 28000, "                                    300.00   -7225.9"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 28080, "                                    316.45     506.2"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 28160, "                                    345.20   -1016.3"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 28240, "                                     29.80     -52.1"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 28320, "                                    706.64  151413.4"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 28400, "                                     57.44  151413."
	    "4  )", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 28480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 28560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 28640, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 28720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 28800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 28880, "        The change from the previous set of values "
	    "is the", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 28960, "        removal of S7. This causes BODY6_NUT_PREC_A"
	    "NGLES", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 29040, "        elements that formerly corresponded to 2*S1"
	    " and 2*S1", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 29120, "        to be shifted toward the start of the array."
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 29200, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 29280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 29360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 29440, "        BODY699_POLE_RA        = (    40.589    -0."
	    "036      0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 29520, "        BODY699_POLE_DEC       = (    83.537    -0."
	    "004      0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 29600, "        BODY699_PM             = (    38.90    810."
	    "7939024  0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 29680, "        BODY699_LONG_AXIS      = (     0.          "
	    "             )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 29760, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 29840, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 29920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 30000, "        The first six angles given here are the ang"
	    "les S1", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 30080, "        through S6 from the 2009 report; the sevent"
	    "h and", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 30160, "        eigth angles are 2*S1 and 2*S2, respectivel"
	    "y.", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 30240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 30320, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 30400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 30480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 30560, "        BODY6_NUT_PREC_ANGLES  = (  353.32   75706.7"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 30640, "                                     28.72   75706.7"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 30720, "                                    177.40  -36505.5"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 30800, "                                    300.00   -7225.9"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 30880, "                                    316.45     506.2"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 30960, "                                    345.20   -1016.3"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 31040, "                                    706.64  151413.4"
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 31120, "                                     57.44  151413."
	    "4  )", (ftnlen)80, (ftnlen)55);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 31200, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 31280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 31360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 31440, "Uranus", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 31520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 31600, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 31680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 31760, "        Values are unchanged in the 2009 IAU report."
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 31840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 31920, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 32000, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 32080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 32160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 32240, "        BODY799_POLE_RA        = (  257.311     0. "
	    "        0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 32320, "        BODY799_POLE_DEC       = (  -15.175     0. "
	    "        0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 32400, "        BODY799_PM             = (  203.81   -501.1"
	    "600928  0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 32480, "        BODY799_LONG_AXIS      = (    0.           "
	    "            )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 32560, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 32640, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 32720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 32800, "        The first 16 angles given here are the angl"
	    "es U1", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 32880, "        through U16 from the 2000 report; the 17th "
	    "and", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 32960, "        18th angles are 2*U11 and 2*U12, respective"
	    "ly.", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 33040, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 33120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 33200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 33280, "        BODY7_NUT_PREC_ANGLES  = (  115.75   54991."
	    "87", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 33360, "                                    141.69   41887."
	    "66", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 33440, "                                    135.03   29927."
	    "35", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 33520, "                                     61.77   25733."
	    "59", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 33600, "                                    249.32   24471."
	    "46", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 33680, "                                     43.86   22278."
	    "41", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 33760, "                                     77.66   20289."
	    "42", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 33840, "                                    157.36   16652."
	    "76", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 33920, "                                    101.81   12872."
	    "63", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 34000, "                                    138.64    8061."
	    "81", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 34080, "                                    102.23   -2024."
	    "22", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 34160, "                                    316.41    2863."
	    "96", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 34240, "                                    304.01     -51."
	    "94", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 34320, "                                    308.71     -93."
	    "17", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 34400, "                                    340.82     -75."
	    "32", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 34480, "                                    259.14    -504."
	    "81", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 34560, "                                    204.46   -4048."
	    "44", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 34640, "                                    632.82    5727."
	    "92     )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 34720, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 34800, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 34880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 34960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 35040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 35120, "Neptune", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 35200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 35280, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 35360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 35440, "        Values are unchanged in the 2009 IAU report."
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 35520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 35600, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 35680, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 35760, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 35840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 35920, "           BODY899_POLE_RA        = (  299.36     0"
	    ".         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 36000, "           BODY899_POLE_DEC       = (   43.46     0"
	    ".         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 36080, "           BODY899_PM             = (  253.18   536"
	    ".3128492  0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 36160, "           BODY899_LONG_AXIS      = (    0.        "
	    "             )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 36240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 36320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 36400, "           BODY899_NUT_PREC_RA    = (  0.70 0. 0. 0"
	    ". 0. 0. 0. 0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 36480, "           BODY899_NUT_PREC_DEC   = ( -0.51 0. 0. 0"
	    ". 0. 0. 0. 0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 36560, "           BODY899_NUT_PREC_PM    = ( -0.48 0. 0. 0"
	    ". 0. 0. 0. 0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 36640, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 36720, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 36800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 36880, "           The 2000 report defines the nutation pre"
	    "cession angles", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 36960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 37040, "              N, N1, N2, ... , N7", (ftnlen)80, (
	    ftnlen)33);
    s_copy(pck + 37120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 37200, "           and also uses the multiples of N1 and N7",
	     (ftnlen)80, (ftnlen)51);
    s_copy(pck + 37280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 37360, "              2*N1", (ftnlen)80, (ftnlen)18);
    s_copy(pck + 37440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 37520, "           and", (ftnlen)80, (ftnlen)14);
    s_copy(pck + 37600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 37680, "              2*N7, 3*N7, ..., 9*N7", (ftnlen)80, (
	    ftnlen)35);
    s_copy(pck + 37760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 37840, "           In this file, we treat the angles and th"
	    "eir multiples as", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 37920, "           separate angles.  In the kernel variable",
	     (ftnlen)80, (ftnlen)51);
    s_copy(pck + 38000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 38080, "              BODY8_NUT_PREC_ANGLES", (ftnlen)80, (
	    ftnlen)35);
    s_copy(pck + 38160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 38240, "           the order of the angles is", (ftnlen)80, (
	    ftnlen)37);
    s_copy(pck + 38320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 38400, "              N, N1, N2, ... , N7, 2*N1, 2*N7, 3*N7"
	    ", ..., 9*N7", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 38480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 38560, "           Each angle is defined by a linear polyno"
	    "mial, so two", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 38640, "           consecutive array elements are allocated"
	    " for each", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 38720, "           angle.  The first term of each pair is t"
	    "he constant term,", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 38800, "           the second is the linear term.", (ftnlen)
	    80, (ftnlen)41);
    s_copy(pck + 38880, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 38960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 39040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 39120, "              BODY8_NUT_PREC_ANGLES = (   357.85   "
	    "      52.316", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 39200, "                                          323.92   "
	    "   62606.6", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 39280, "                                          220.51   "
	    "   55064.2", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 39360, "                                          354.27   "
	    "   46564.5", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 39440, "                                           75.31   "
	    "   26109.4", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 39520, "                                           35.36   "
	    "   14325.4", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 39600, "                                          142.61   "
	    "    2824.6", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 39680, "                                          177.85   "
	    "      52.316", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 39760, "                                          647.840  "
	    "  125213.200", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 39840, "                                          355.700  "
	    "     104.632", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 39920, "                                          533.550  "
	    "     156.948", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 40000, "                                          711.400  "
	    "     209.264", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 40080, "                                          889.250  "
	    "     261.580", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 40160, "                                         1067.100  "
	    "     313.896", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 40240, "                                         1244.950  "
	    "     366.212", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 40320, "                                         1422.800  "
	    "     418.528", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 40400, "                                         1600.650  "
	    "     470.844   )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 40480, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 40560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 40640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 40720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 40800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 40880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 40960, "Orientation Constants for the Dwarf Planet Pluto", (
	    ftnlen)80, (ftnlen)48);
    s_copy(pck + 41040, "---------------------------------------------------"
	    "-----", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 41120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 41200, "Pluto", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 41280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 41360, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 41440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 41520, "        Values are from the 2006 IAU report.", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 41600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 41680, "        body999_pole_ra        = (  312.993   0.   "
	    "       0. )", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 41760, "        body999_pole_dec       = (    6.163   0.   "
	    "       0. )", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 41840, "        body999_pm             = (  237.305  -56.36"
	    "25225  0. )", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 41920, "        body999_long_axis      = (    0.           "
	    "          )", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 42000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 42080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 42160, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 42240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 42320, "        Due to the new definition of planetocentric"
	    " coordinates", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 42400, "        for small bodies, and to the reclassificati"
	    "on of Pluto", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 42480, "        as a dwarf planet, Pluto's north pole direc"
	    "tion has been", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 42560, "        inverted.", (ftnlen)80, (ftnlen)17);
    s_copy(pck + 42640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 42720, "        The PM constant W0 is from [2].", (ftnlen)80,
	     (ftnlen)39);
    s_copy(pck + 42800, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 42880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 42960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 43040, "        BODY999_POLE_RA        = (  132.993   0.   "
	    "       0. )", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 43120, "        BODY999_POLE_DEC       = (   -6.163   0.   "
	    "       0. )", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 43200, "        BODY999_PM             = (  302.695   56.36"
	    "25225  0. )", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 43280, "        BODY999_LONG_AXIS      = (    0.           "
	    "          )", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 43360, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 43440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 43520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 43600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 43680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 43760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 43840, "Orientation constants for the satellites", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 43920, "---------------------------------------------------"
	    "-----", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 44000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 44080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 44160, "Satellites of Earth", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 44240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 44320, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 44400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 44480, "        Values are unchanged in the 2009 IAU report."
	    , (ftnlen)80, (ftnlen)52);
    s_copy(pck + 44560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 44640, "     New values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 44720, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 44800, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 44880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 44960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 45040, "        BODY301_POLE_RA      = (  269.9949        0"
	    ".0031        0.      )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 45120, "        BODY301_POLE_DEC     = (   66.5392        0"
	    ".0130        0.      )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 45200, "        BODY301_PM           = (   38.3213       13"
	    ".17635815   -1.4D-12 )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 45280, "        BODY301_LONG_AXIS    = (    0.             "
	    "                     )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 45360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 45440, "        BODY301_NUT_PREC_RA  = (   -3.8787   -0.120"
	    "4   0.0700   -0.0172", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 45520, "                                    0.0       0.007"
	    "2   0.0       0.0", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 45600, "                                    0.0      -0.005"
	    "2   0.0       0.0", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 45680, "                                    0.0043         "
	    "                     )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 45760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 45840, "        BODY301_NUT_PREC_DEC = (   1.5419     0.023"
	    "9  -0.0278    0.0068", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 45920, "                                   0.0       -0.002"
	    "9   0.0009    0.0", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 46000, "                                   0.0        0.000"
	    "8   0.0       0.0", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 46080, "                                  -0.0009          "
	    "                     )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 46160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 46240, "        BODY301_NUT_PREC_PM  = (   3.5610     0.120"
	    "8  -0.0642    0.0158", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 46320, "                                   0.0252    -0.006"
	    "6  -0.0047   -0.0046", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 46400, "                                   0.0028     0.005"
	    "2   0.0040    0.0019", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 46480, "                                  -0.0044          "
	    "                     )", (ftnlen)80, (ftnlen)73);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 46560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 46640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 46720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 46800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 46880, "Satellites of Mars", (ftnlen)80, (ftnlen)18);
    s_copy(pck + 46960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 47040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 47120, "     Phobos", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 47200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 47280, "          Old values:", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 47360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 47440, "             Values are unchanged in the 2009 IAU r"
	    "eport.", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 47520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 47600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 47680, "          Current values:", (ftnlen)80, (ftnlen)25);
    s_copy(pck + 47760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 47840, "            The quadratic prime meridian term is sc"
	    "aled by 1/36525**2:", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 47920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 48000, "               8.864000000000000   --->   6.6443009"
	    "930565219E-09", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 48080, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 48160, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 48240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 48320, "          BODY401_POLE_RA  = ( 317.68    -0.108    "
	    " 0.                     )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 48400, "          BODY401_POLE_DEC = (  52.90    -0.061    "
	    " 0.                     )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 48480, "          BODY401_PM       = (  35.06  1128.8445850"
	    " 6.6443009930565219E-09 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 48560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 48640, "          BODY401_LONG_AXIS     = (    0.   )", (
	    ftnlen)80, (ftnlen)45);
    s_copy(pck + 48720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 48800, "          BODY401_NUT_PREC_RA   = (   1.79    0.   "
	    " 0.   0. )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 48880, "          BODY401_NUT_PREC_DEC  = (  -1.08    0.   "
	    " 0.   0. )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 48960, "          BODY401_NUT_PREC_PM   = (  -1.42   -0.78 "
	    " 0.   0. )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 49040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 49120, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 49200, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 49280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 49360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 49440, "     Deimos", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 49520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 49600, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 49680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 49760, "           Values are unchanged in the 2009 IAU rep"
	    "ort.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 49840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 49920, "        New values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 50000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 50080, "           The Deimos prime meridian expression is:",
	     (ftnlen)80, (ftnlen)51);
    s_copy(pck + 50160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 50240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 50320, "                                                   "
	    "  2", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 50400, "              W = 79.41  +  285.1618970 d  -  0.520"
	    " T  -  2.58 sin M", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 50480, "                                                   "
	    "                 3", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 50560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 50640, "                                                   "
	    "    +  0.19 cos M .", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 50720, "                                                   "
	    "                 3", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 50800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 50880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 50960, "           At the present time, the PCK kernel soft"
	    "ware (the routine", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 51040, "           BODEUL in particular) cannot handle the "
	    "cosine term directly,", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 51120, "           but we can represent it as", (ftnlen)80, (
	    ftnlen)37);
    s_copy(pck + 51200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 51280, "              0.19 sin M", (ftnlen)80, (ftnlen)24);
    s_copy(pck + 51360, "                        4", (ftnlen)80, (ftnlen)25);
    s_copy(pck + 51440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 51520, "           where", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 51600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 51680, "              M   =  90.D0 - M", (ftnlen)80, (ftnlen)
	    30);
    s_copy(pck + 51760, "               4              3", (ftnlen)80, (
	    ftnlen)31);
    s_copy(pck + 51840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 51920, "           Therefore, the nutation precession angle"
	    " assignments for Phobos", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 52000, "           and Deimos contain four coefficients rat"
	    "her than three.", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 52080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 52160, "           The quadratic prime meridian term is sca"
	    "led by 1/36525**2:", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 52240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 52320, "              -0.5200000000000000  --->   -3.897830"
	    "0049519307E-10", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 52400, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 52480, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 52560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 52640, "           BODY402_POLE_RA       = (  316.65     -0"
	    ".108       0.           )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 52720, "           BODY402_POLE_DEC      = (   53.52     -0"
	    ".061       0.           )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 52800, "           BODY402_PM            = (   79.41    285"
	    ".1618970  -3.897830D-10 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 52880, "           BODY402_LONG_AXIS     = (    0.         "
	    "                        )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 52960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 53040, "           BODY402_NUT_PREC_RA   = (    0.   0.   2"
	    ".98    0.   )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 53120, "           BODY402_NUT_PREC_DEC  = (    0.   0.  -1"
	    ".78    0.   )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 53200, "           BODY402_NUT_PREC_PM   = (    0.   0.  -2"
	    ".58    0.19 )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 53280, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 53360, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 53440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 53520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 53600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 53680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 53760, "Satellites of Jupiter", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 53840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 53920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 54000, "     Io", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 54080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 54160, "          Old values:", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 54240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 54320, "             Values are unchanged in the 2009 IAU r"
	    "eport.", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 54400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 54480, "          Current values:", (ftnlen)80, (ftnlen)25);
    s_copy(pck + 54560, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 54640, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 54720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 54800, "        BODY501_POLE_RA       = (  268.05          "
	    "-0.009      0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 54880, "        BODY501_POLE_DEC      = (   64.50          "
	    " 0.003      0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 54960, "        BODY501_PM            = (  200.39         2"
	    "03.4889538  0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 55040, "        BODY501_LONG_AXIS     = (    0.            "
	    "               )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 55120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 55200, "        BODY501_NUT_PREC_RA   = (    0.   0.     0."
	    "094    0.024   )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 55280, "        BODY501_NUT_PREC_DEC  = (    0.   0.     0."
	    "040    0.011   )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 55360, "        BODY501_NUT_PREC_PM   = (    0.   0.    -0."
	    "085   -0.022   )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 55440, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 55520, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 55600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 55680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 55760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 55840, "     Europa", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 55920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 56000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 56080, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 56160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 56240, "           Values are unchanged in the 2009 IAU rep"
	    "ort.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 56320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 56400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 56480, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 56560, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 56640, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 56720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 56800, "        BODY502_POLE_RA       = (  268.08          "
	    "-0.009      0.   )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 56880, "        BODY502_POLE_DEC      = (   64.51          "
	    " 0.003      0.   )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 56960, "        BODY502_PM            = (   36.022        1"
	    "01.3747235  0.   )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 57040, "        BODY502_LONG_AXIS     = (    0.            "
	    "                 )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 57120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 57200, "        BODY502_NUT_PREC_RA   = ( 0. 0. 0.   1.086 "
	    "  0.060   0.015   0.009 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 57280, "        BODY502_NUT_PREC_DEC  = ( 0. 0. 0.   0.468 "
	    "  0.026   0.007   0.002 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 57360, "        BODY502_NUT_PREC_PM   = ( 0. 0. 0.  -0.980 "
	    " -0.054  -0.014  -0.008 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 57440, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 57520, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 57600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 57680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 57760, "     Ganymede", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 57840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 57920, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 58000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 58080, "             Values are unchanged in the 2009 IAU r"
	    "eport.", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 58160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 58240, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 58320, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 58400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 58480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 58560, "        BODY503_POLE_RA       = (  268.20         -"
	    "0.009       0.  )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 58640, "        BODY503_POLE_DEC      = (   64.57          "
	    "0.003       0.  )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 58720, "        BODY503_PM            = (   44.064        5"
	    "0.3176081   0.  )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 58800, "        BODY503_LONG_AXIS     = (    0.            "
	    "                )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 58880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 58960, "        BODY503_NUT_PREC_RA   = ( 0. 0. 0.  -0.037 "
	    "  0.431   0.091   )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 59040, "        BODY503_NUT_PREC_DEC  = ( 0. 0. 0.  -0.016 "
	    "  0.186   0.039   )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 59120, "        BODY503_NUT_PREC_PM   = ( 0. 0. 0.   0.033 "
	    " -0.389  -0.082   )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 59200, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 59280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 59360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 59440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 59520, "     Callisto", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 59600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 59680, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 59760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 59840, "             Values are unchanged in the 2009 IAU r"
	    "eport.", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 59920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 60000, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 60080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 60160, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 60240, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 60320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 60400, "        BODY504_POLE_RA       = (   268.72    -0.00"
	    "9       0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 60480, "        BODY504_POLE_DEC      = (    64.83     0.00"
	    "3       0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 60560, "        BODY504_PM            = (   259.51    21.57"
	    "10715   0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 60640, "        BODY504_LONG_AXIS     = (     0.           "
	    "            )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 60720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 60800, "        BODY504_NUT_PREC_RA   = ( 0. 0. 0. 0.  -0.0"
	    "68   0.590  0.   0.010 )", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 60880, "        BODY504_NUT_PREC_DEC  = ( 0. 0. 0. 0.  -0.0"
	    "29   0.254  0.  -0.004 )", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 60960, "        BODY504_NUT_PREC_PM   = ( 0. 0. 0. 0.   0.0"
	    "61  -0.533  0.  -0.009 )", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 61040, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 61120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 61200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 61280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 61360, "     Amalthea", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 61440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 61520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 61600, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 61680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 61760, "           Values are unchanged in the 2009 IAU rep"
	    "ort.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 61840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 61920, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 62000, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 62080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 62160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 62240, "        BODY505_POLE_RA       = (   268.05    -0.00"
	    "9      0.  )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 62320, "        BODY505_POLE_DEC      = (    64.49     0.00"
	    "3      0.  )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 62400, "        BODY505_PM            = (   231.67   722.63"
	    "14560  0.  )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 62480, "        BODY505_LONG_AXIS     = (     0.           "
	    "           )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 62560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 62640, "        BODY505_NUT_PREC_RA  = ( -0.84  0. 0. 0. 0."
	    " 0. 0. 0.   0.01  0. )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 62720, "        BODY505_NUT_PREC_DEC = ( -0.36  0. 0. 0. 0."
	    " 0. 0. 0.   0.    0. )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 62800, "        BODY505_NUT_PREC_PM  = (  0.76  0. 0. 0. 0."
	    " 0. 0. 0.  -0.01  0. )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 62880, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 62960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 63040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 63120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 63200, "     Thebe", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 63280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 63360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 63440, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 63520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 63600, "           Values are unchanged in the 2009 IAU rep"
	    "ort.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 63680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 63760, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 63840, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 63920, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 64000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 64080, "        BODY514_POLE_RA       = (  268.05     -0.00"
	    "9       0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 64160, "        BODY514_POLE_DEC      = (   64.49      0.00"
	    "3       0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 64240, "        BODY514_PM            = (    8.56    533.70"
	    "04100   0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 64320, "        BODY514_LONG_AXIS     = (    0.            "
	    "            )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 64400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 64480, "        BODY514_NUT_PREC_RA  = ( 0.  -2.11  0. 0. 0"
	    ". 0. 0. 0. 0.  0.04 )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 64560, "        BODY514_NUT_PREC_DEC = ( 0.  -0.91  0. 0. 0"
	    ". 0. 0. 0. 0.  0.01 )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 64640, "        BODY514_NUT_PREC_PM  = ( 0.   1.91  0. 0. 0"
	    ". 0. 0. 0. 0. -0.04 )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 64720, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 64800, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 64880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 64960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 65040, "     Adrastea", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 65120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 65200, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 65280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 65360, "           Values are unchanged in the 2009 IAU rep"
	    "ort.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 65440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 65520, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 65600, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 65680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 65760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 65840, "        BODY515_POLE_RA       = (  268.05     -0.00"
	    "9       0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 65920, "        BODY515_POLE_DEC      = (   64.49      0.00"
	    "3       0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 66000, "        BODY515_PM            = (   33.29   1206.99"
	    "86602   0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 66080, "        BODY515_LONG_AXIS     = (    0.            "
	    "            )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 66160, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 66240, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 66320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 66400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 66480, "     Metis", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 66560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 66640, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 66720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 66800, "           Values are unchanged in the 2009 IAU rep"
	    "ort.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 66880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 66960, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 67040, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 67120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 67200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 67280, "        BODY516_POLE_RA       = (  268.05     -0.00"
	    "9       0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 67360, "        BODY516_POLE_DEC      = (   64.49      0.00"
	    "3       0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 67440, "        BODY516_PM            = (  346.09   1221.25"
	    "47301   0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 67520, "        BODY516_LONG_AXIS     = (    0.            "
	    "            )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 67600, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 67680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 67760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 67840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 67920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 68000, "Satellites of Saturn", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 68080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 68160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 68240, "     Mimas", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 68320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 68400, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 68480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 68560, "           Values are from the 2006 IAU report.", (
	    ftnlen)80, (ftnlen)47);
    s_copy(pck + 68640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 68720, "           body601_pole_ra       = (   40.66     -0"
	    ".036      0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 68800, "           body601_pole_dec      = (   83.52     -0"
	    ".004      0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 68880, "           body601_pm            = (  337.46    381"
	    ".9945550  0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 68960, "           body601_long_axis     = (     0.        "
	    "              )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 69040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 69120, "           body601_nut_prec_ra   = ( 0. 0.   13.56 "
	    " 0.    0.    0. 0. 0. 0. )", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 69200, "           body601_nut_prec_dec  = ( 0. 0.   -1.53 "
	    " 0.    0.    0. 0. 0. 0. )", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 69280, "           body601_nut_prec_pm   = ( 0. 0.  -13.48 "
	    " 0.  -44.85  0. 0. 0. 0. )", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 69360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 69440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 69520, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 69600, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 69680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 69760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 69840, "           BODY601_POLE_RA       = (   40.66     -0"
	    ".036      0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 69920, "           BODY601_POLE_DEC      = (   83.52     -0"
	    ".004      0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 70000, "           BODY601_PM            = (  333.46    381"
	    ".9945550  0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 70080, "           BODY601_LONG_AXIS     = (     0.        "
	    "              )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 70160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 70240, "           BODY601_NUT_PREC_RA   = ( 0. 0.   13.56 "
	    " 0.    0.    0. 0. 0.  )", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 70320, "           BODY601_NUT_PREC_DEC  = ( 0. 0.   -1.53 "
	    " 0.    0.    0. 0. 0.  )", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 70400, "           BODY601_NUT_PREC_PM   = ( 0. 0.  -13.48 "
	    " 0.  -44.85  0. 0. 0.  )", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 70480, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 70560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 70640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 70720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 70800, "     Enceladus", (ftnlen)80, (ftnlen)14);
    s_copy(pck + 70880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 70960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 71040, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 71120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 71200, "           Values are from the 2006 IAU report.", (
	    ftnlen)80, (ftnlen)47);
    s_copy(pck + 71280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 71360, "           body602_pole_ra       = (   40.66    -0."
	    "036       0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 71440, "           body602_pole_dec      = (   83.52    -0."
	    "004       0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 71520, "           body602_pm            = (    2.82   262."
	    "7318996   0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 71600, "           body602_long_axis     = (    0.         "
	    "             )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 71680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 71760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 71840, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 71920, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 72000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 72080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 72160, "           BODY602_POLE_RA       = (   40.66    -0."
	    "036       0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 72240, "           BODY602_POLE_DEC      = (   83.52    -0."
	    "004       0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 72320, "           BODY602_PM            = (    6.32   262."
	    "7318996   0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 72400, "           BODY602_LONG_AXIS     = (    0.         "
	    "             )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 72480, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 72560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 72640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 72720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 72800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 72880, "     Tethys", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 72960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 73040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 73120, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 73200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 73280, "           Values are from the 2006 IAU report.", (
	    ftnlen)80, (ftnlen)47);
    s_copy(pck + 73360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 73440, "           body603_pole_ra       = (   40.66    -0."
	    "036       0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 73520, "           body603_pole_dec      = (   83.52    -0."
	    "004       0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 73600, "           body603_pm            = (   10.45   190."
	    "6979085   0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 73680, "           body603_long_axis     = (    0.         "
	    "             )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 73760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 73840, "           body603_nut_prec_ra   = ( 0. 0. 0.   9.6"
	    "6   0.    0.  0.  0.  0. )", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 73920, "           body603_nut_prec_dec  = ( 0. 0. 0.  -1.0"
	    "9   0.    0.  0.  0.  0. )", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 74000, "           body603_nut_prec_pm   = ( 0. 0. 0.  -9.6"
	    "0   2.23  0.  0.  0.  0. )", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 74080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 74160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 74240, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 74320, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 74400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 74480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 74560, "           BODY603_POLE_RA       = (   40.66    -0."
	    "036       0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 74640, "           BODY603_POLE_DEC      = (   83.52    -0."
	    "004       0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 74720, "           BODY603_PM            = (    8.95   190."
	    "6979085   0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 74800, "           BODY603_LONG_AXIS     = (    0.         "
	    "             )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 74880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 74960, "           BODY603_NUT_PREC_RA   = ( 0. 0. 0.   9.6"
	    "6   0.    0.  0.  0. )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 75040, "           BODY603_NUT_PREC_DEC  = ( 0. 0. 0.  -1.0"
	    "9   0.    0.  0.  0. )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 75120, "           BODY603_NUT_PREC_PM   = ( 0. 0. 0.  -9.6"
	    "0   2.23  0.  0.  0. )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 75200, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 75280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 75360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 75440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 75520, "     Dione", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 75600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 75680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 75760, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 75840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 75920, "           Values are from the 2006 IAU report.", (
	    ftnlen)80, (ftnlen)47);
    s_copy(pck + 76000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 76080, "           body604_pole_ra       = (  40.66      -0"
	    ".036      0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 76160, "           body604_pole_dec      = (  83.52      -0"
	    ".004      0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 76240, "           body604_pm            = (  357.00    131"
	    ".5349316  0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 76320, "           body604_long_axis     = (    0.         "
	    "              )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 76400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 76480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 76560, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 76640, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 76720, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 76800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 76880, "           BODY604_POLE_RA       = (  40.66      -0"
	    ".036      0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 76960, "           BODY604_POLE_DEC      = (  83.52      -0"
	    ".004      0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 77040, "           BODY604_PM            = (  357.6     131"
	    ".5349316  0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 77120, "           BODY604_LONG_AXIS     = (    0.         "
	    "              )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 77200, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 77280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 77360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 77440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 77520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 77600, "     Rhea", (ftnlen)80, (ftnlen)9);
    s_copy(pck + 77680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 77760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 77840, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 77920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 78000, "           Values are from the 2009 IAU report.", (
	    ftnlen)80, (ftnlen)47);
    s_copy(pck + 78080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 78160, "           body605_pole_ra       = (   40.38   -0.0"
	    "36       0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 78240, "           body605_pole_dec      = (   83.55   -0.0"
	    "04       0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 78320, "           body605_pm            = (  235.16   79.6"
	    "900478   0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 78400, "           body605_long_axis     = (    0.         "
	    "            )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 78480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 78560, "           body605_nut_prec_ra   = ( 0. 0. 0. 0. 0."
	    "   3.10   0. 0. 0. )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 78640, "           body605_nut_prec_dec  = ( 0. 0. 0. 0. 0."
	    "  -0.35   0. 0. 0. )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 78720, "           body605_nut_prec_pm   = ( 0. 0. 0. 0. 0."
	    "  -3.08   0. 0. 0. )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 78800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 78880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 78960, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 79040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 79120, "           Data values are unchanged in the 2009 IA"
	    "U report. However", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 79200, "           the kernel variable contents have change"
	    "d due to removal of", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 79280, "           the angle S7.", (ftnlen)80, (ftnlen)24);
    s_copy(pck + 79360, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 79440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 79520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 79600, "           BODY605_POLE_RA       = (   40.38   -0.0"
	    "36       0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 79680, "           BODY605_POLE_DEC      = (   83.55   -0.0"
	    "04       0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 79760, "           BODY605_PM            = (  235.16   79.6"
	    "900478   0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 79840, "           BODY605_LONG_AXIS     = (    0.         "
	    "            )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 79920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 80000, "           BODY605_NUT_PREC_RA   = ( 0. 0. 0. 0. 0."
	    "   3.10   0. 0. )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 80080, "           BODY605_NUT_PREC_DEC  = ( 0. 0. 0. 0. 0."
	    "  -0.35   0. 0. )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 80160, "           BODY605_NUT_PREC_PM   = ( 0. 0. 0. 0. 0."
	    "  -3.08   0. 0. )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 80240, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 80320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 80400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 80480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 80560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 80640, "     Titan", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 80720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 80800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 80880, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 80960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 81040, "           Values are from the 2006 IAU report.", (
	    ftnlen)80, (ftnlen)47);
    s_copy(pck + 81120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 81200, "           BODY606_POLE_RA       = (    36.41   -0."
	    "036      0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 81280, "           BODY606_POLE_DEC      = (    83.94   -0."
	    "004      0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 81360, "           BODY606_PM            = (   189.64   22."
	    "5769768  0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 81440, "           BODY606_LONG_AXIS     = (     0.        "
	    "            )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 81520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 81600, "           BODY606_NUT_PREC_RA   = ( 0. 0. 0. 0. 0."
	    " 0.  2.66  0. 0 )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 81680, "           BODY606_NUT_PREC_DEC  = ( 0. 0. 0. 0. 0."
	    " 0. -0.30  0. 0 )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 81760, "           BODY606_NUT_PREC_PM   = ( 0. 0. 0. 0. 0."
	    " 0. -2.64  0. 0 )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 81840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 81920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 82000, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 82080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 82160, "              Note removal of dependence on the nut"
	    "ation precession", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 82240, "              angles.", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 82320, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 82400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 82480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 82560, "           BODY606_POLE_RA       = (    39.4827    "
	    "0.         0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 82640, "           BODY606_POLE_DEC      = (    83.4279    "
	    "0.         0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 82720, "           BODY606_PM            = (   186.5855   2"
	    "2.5769768  0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 82800, "           BODY606_LONG_AXIS     = (     0.        "
	    "              )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 82880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 82960, "           BODY606_NUT_PREC_RA   = ( 0. 0. 0. 0. 0."
	    " 0. 0. 0 )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 83040, "           BODY606_NUT_PREC_DEC  = ( 0. 0. 0. 0. 0."
	    " 0. 0. 0 )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 83120, "           BODY606_NUT_PREC_PM   = ( 0. 0. 0. 0. 0."
	    " 0. 0. 0 )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 83200, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 83280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 83360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 83440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 83520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 83600, "     Hyperion", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 83680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 83760, "         The IAU report does not give an orientatio"
	    "n model for Hyperion.", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 83840, "         Hyperion's rotation is in chaotic and is n"
	    "ot predictable for", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 83920, "         long periods.", (ftnlen)80, (ftnlen)22);
    s_copy(pck + 84000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 84080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 84160, "     Iapetus", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 84240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 84320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 84400, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 84480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 84560, "           Values are from the 2006 IAU report.", (
	    ftnlen)80, (ftnlen)47);
    s_copy(pck + 84640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 84720, "           body608_pole_ra       = (   318.16  -3.9"
	    "49      0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 84800, "           body608_pole_dec      = (    75.03  -1.1"
	    "43      0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 84880, "           body608_pm            = (   350.20   4.5"
	    "379572  0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 84960, "           body608_long_axis     = (     0.        "
	    "            )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 85040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 85120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 85200, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 85280, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 85360, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 85440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 85520, "           BODY608_POLE_RA       = (   318.16  -3.9"
	    "49      0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 85600, "           BODY608_POLE_DEC      = (    75.03  -1.1"
	    "43      0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 85680, "           BODY608_PM            = (   355.2    4.5"
	    "379572  0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 85760, "           BODY608_LONG_AXIS     = (     0.        "
	    "            )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 85840, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 85920, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 86000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 86080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 86160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 86240, "     Phoebe", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 86320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 86400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 86480, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 86560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 86640, "           Values are unchanged in the 2009 IAU rep"
	    "ort.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 86720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 86800, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 86880, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 86960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 87040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 87120, "           BODY609_POLE_RA       = ( 356.90       0"
	    ".         0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 87200, "           BODY609_POLE_DEC      = (  77.80       0"
	    ".         0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 87280, "           BODY609_PM            = ( 178.58     931"
	    ".639      0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 87360, "           BODY609_LONG_AXIS     = (    0.         "
	    "              )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 87440, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 87520, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 87600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 87680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 87760, "     Janus", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 87840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 87920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 88000, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 88080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 88160, "           Values are unchanged in the 2009 IAU rep"
	    "ort.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 88240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 88320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 88400, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 88480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 88560, "           Data values are unchanged in the 2009 IA"
	    "U report. However", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 88640, "           the kernel variable contents have change"
	    "d due to removal of", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 88720, "           the angle S7.", (ftnlen)80, (ftnlen)24);
    s_copy(pck + 88800, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 88880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 88960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 89040, "           BODY610_POLE_RA       = (  40.58    -0.0"
	    "36       0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 89120, "           BODY610_POLE_DEC      = (  83.52    -0.0"
	    "04       0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 89200, "           BODY610_PM            = (  58.83   518.2"
	    "359876   0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 89280, "           BODY610_LONG_AXIS     = (   0.          "
	    "            )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 89360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 89440, "           BODY610_NUT_PREC_RA   = ( 0. -1.623  0. "
	    "0. 0. 0. 0.  0.023 )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 89520, "           BODY610_NUT_PREC_DEC  = ( 0. -0.183  0. "
	    "0. 0. 0. 0.  0.001 )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 89600, "           BODY610_NUT_PREC_PM   = ( 0.  1.613  0. "
	    "0. 0. 0. 0. -0.023 )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 89680, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 89760, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 89840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 89920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 90000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 90080, "     Epimetheus", (ftnlen)80, (ftnlen)15);
    s_copy(pck + 90160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 90240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 90320, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 90400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 90480, "           Values are unchanged in the 2009 IAU rep"
	    "ort.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 90560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 90640, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 90720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 90800, "           Data values are unchanged in the 2009 IA"
	    "U report. However", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 90880, "           the kernel variable contents have change"
	    "d due to removal of", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 90960, "           the angle S7.", (ftnlen)80, (ftnlen)24);
    s_copy(pck + 91040, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 91120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 91200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 91280, "           BODY611_POLE_RA       = (  40.58    -0.0"
	    "36        0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 91360, "           BODY611_POLE_DEC      = (  83.52    -0.0"
	    "04        0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 91440, "           BODY611_PM            = ( 293.87   518.4"
	    "907239    0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 91520, "           BODY611_LONG_AXIS     = (   0.          "
	    "             )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 91600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 91680, "           BODY611_NUT_PREC_RA   = ( -3.153   0. 0."
	    " 0. 0. 0.   0.086  0. )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 91760, "           BODY611_NUT_PREC_DEC  = ( -0.356   0. 0."
	    " 0. 0. 0.   0.005  0. )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 91840, "           BODY611_NUT_PREC_PM   = (  3.133   0. 0."
	    " 0. 0. 0.  -0.086  0. )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 91920, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 92000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 92080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 92160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 92240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 92320, "     Helene", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 92400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 92480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 92560, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 92640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 92720, "           Values are unchanged in the 2009 IAU rep"
	    "ort.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 92800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 92880, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 92960, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 93040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 93120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 93200, "           BODY612_POLE_RA       = (  40.85     -0."
	    "036        0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 93280, "           BODY612_POLE_DEC      = (  83.34     -0."
	    "004        0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 93360, "           BODY612_PM            = ( 245.12    131."
	    "6174056    0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 93440, "           BODY612_LONG_AXIS     = (   0.          "
	    "              )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 93520, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 93600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 93680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 93760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 93840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 93920, "     Telesto", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 94000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 94080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 94160, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 94240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 94320, "           Values are unchanged in the 2009 IAU rep"
	    "ort.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 94400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 94480, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 94560, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 94640, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 94720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 94800, "           BODY613_POLE_RA       = ( 50.51    -0.03"
	    "6      0.  )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 94880, "           BODY613_POLE_DEC      = ( 84.06    -0.00"
	    "4      0.  )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 94960, "           BODY613_PM            = ( 56.88   190.69"
	    "79332  0.  )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 95040, "           BODY613_LONG_AXIS     = (  0.           "
	    "           )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 95120, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 95200, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 95280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 95360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 95440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 95520, "     Calypso", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 95600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 95680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 95760, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 95840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 95920, "           Values are unchanged in the 2009 IAU rep"
	    "ort.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 96000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 96080, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 96160, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 96240, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 96320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 96400, "           BODY614_POLE_RA       = (   36.41    -0."
	    "036        0.  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 96480, "           BODY614_POLE_DEC      = (   85.04    -0."
	    "004        0.  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 96560, "           BODY614_PM            = (  153.51   190."
	    "6742373    0.  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 96640, "           BODY614_LONG_AXIS     = (    0.         "
	    "               )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 96720, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 96800, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 96880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 96960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 97040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 97120, "     Atlas", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 97200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 97280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 97360, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 97440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 97520, "           Values are unchanged in the 2009 IAU rep"
	    "ort.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 97600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 97680, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 97760, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 97840, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 97920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 98000, "           BODY615_POLE_RA       = (   40.58     -0"
	    ".036      0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 98080, "           BODY615_POLE_DEC      = (   83.53     -0"
	    ".004      0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 98160, "           BODY615_PM            = (  137.88    598"
	    ".3060000  0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 98240, "           BODY615_LONG_AXIS     = (    0.         "
	    "             )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 98320, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 98400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 98480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 98560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 98640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 98720, "     Prometheus", (ftnlen)80, (ftnlen)15);
    s_copy(pck + 98800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 98880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 98960, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 99040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 99120, "           Values are unchanged in the 2009 IAU rep"
	    "ort.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 99200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 99280, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 99360, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 99440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 99520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 99600, "           BODY616_POLE_RA       = (  40.58      -0"
	    ".036    )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 99680, "           BODY616_POLE_DEC      = (  83.53      -0"
	    ".004    )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 99760, "           BODY616_PM            = ( 296.14     587"
	    ".289000 )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 99840, "           BODY616_LONG_AXIS     = (   0.          "
	    "        )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 99920, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 100000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 100080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 100160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 100240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 100320, "     Pandora", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 100400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 100480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 100560, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 100640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 100720, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 100800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 100880, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 100960, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 101040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 101120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 101200, "           BODY617_POLE_RA       = (   40.58     -"
	    "0.036      0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 101280, "           BODY617_POLE_DEC      = (   83.53     -"
	    "0.004      0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 101360, "           BODY617_PM            = (  162.92    57"
	    "2.7891000  0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 101440, "           BODY617_LONG_AXIS     = (     0.       "
	    "               )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 101520, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 101600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 101680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 101760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 101840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 101920, "     Pan", (ftnlen)80, (ftnlen)8);
    s_copy(pck + 102000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 102080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 102160, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 102240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 102320, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 102400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 102480, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 102560, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 102640, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 102720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 102800, "           BODY618_POLE_RA       = (   40.6     -0"
	    ".036       0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 102880, "           BODY618_POLE_DEC      = (   83.5     -0"
	    ".004       0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 102960, "           BODY618_PM            = (   48.8    626"
	    ".0440000   0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 103040, "           BODY618_LONG_AXIS     = (    0.        "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 103120, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 103200, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 103280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 103360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 103440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 103520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 103600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 103680, "Satellites of Uranus", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 103760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 103840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 103920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 104000, "     Ariel", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 104080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 104160, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 104240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 104320, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 104400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 104480, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 104560, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 104640, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 104720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 104800, "           BODY701_POLE_RA       = ( 257.43     0."
	    "          0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 104880, "           BODY701_POLE_DEC      = ( -15.10     0."
	    "          0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 104960, "           BODY701_PM            = ( 156.22  -142."
	    "8356681   0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 105040, "           BODY701_LONG_AXIS     = (   0.         "
	    "             )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 105120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 105200, "           BODY701_NUT_PREC_RA   = (  0. 0. 0. 0. "
	    "0.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 105280, "                                      0. 0. 0. 0. "
	    "0.  0.    0.    0.29 )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 105360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 105440, "           BODY701_NUT_PREC_DEC  = (  0. 0. 0. 0. "
	    "0.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 105520, "                                      0. 0. 0. 0. "
	    "0.  0.    0.    0.28 )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 105600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 105680, "           BODY701_NUT_PREC_PM   = (  0. 0. 0. 0. "
	    "0.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 105760, "                                      0. 0. 0. 0. "
	    "0.  0.   0.05   0.08 )", (ftnlen)80, (ftnlen)72);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 105840, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 105920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 106000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 106080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 106160, "     Umbriel", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 106240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 106320, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 106400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 106480, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 106560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 106640, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 106720, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 106800, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 106880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 106960, "           BODY702_POLE_RA       = (  257.43     0"
	    ".          0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 107040, "           BODY702_POLE_DEC      = (  -15.10     0"
	    ".          0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 107120, "           BODY702_PM            = (  108.05   -86"
	    ".8688923   0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 107200, "           BODY702_LONG_AXIS     = (    0.        "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 107280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 107360, "           BODY702_NUT_PREC_RA   = ( 0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 107440, "                                     0. 0. 0. 0. 0"
	    ".   0.   0.    0.   0.21 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 107520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 107600, "           BODY702_NUT_PREC_DEC  = ( 0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 107680, "                                     0. 0. 0. 0. 0"
	    ".   0.   0.    0.   0.20 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 107760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 107840, "           BODY702_NUT_PREC_PM   = ( 0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 107920, "                                     0. 0. 0. 0. 0"
	    ".   0.  -0.09  0.   0.06 )", (ftnlen)80, (ftnlen)76);
    s_copy(pck + 108000, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 108080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 108160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 108240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 108320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 108400, "     Titania", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 108480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 108560, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 108640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 108720, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 108800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 108880, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 108960, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 109040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 109120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 109200, "           BODY703_POLE_RA       = (  257.43    0."
	    "          0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 109280, "           BODY703_POLE_DEC      = (  -15.10    0."
	    "          0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 109360, "           BODY703_PM            = (   77.74  -41."
	    "3514316   0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 109440, "           BODY703_LONG_AXIS     = (    0.        "
	    "             )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 109520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 109600, "           BODY703_NUT_PREC_RA   = ( 0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 109680, "                                     0. 0. 0. 0. 0"
	    ".   0. 0. 0. 0.   0.29 )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 109760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 109840, "           BODY703_NUT_PREC_DEC  = ( 0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 109920, "                                     0. 0. 0. 0. 0"
	    ".   0. 0. 0. 0.   0.28 )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 110000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 110080, "           BODY703_NUT_PREC_PM   = ( 0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 110160, "                                     0. 0. 0. 0. 0"
	    ".   0. 0. 0. 0.   0.08 )", (ftnlen)80, (ftnlen)74);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 110240, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 110320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 110400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 110480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 110560, "     Oberon", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 110640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 110720, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 110800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 110880, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 110960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 111040, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 111120, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 111200, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 111280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 111360, "           BODY704_POLE_RA       = (  257.43    0."
	    "          0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 111440, "           BODY704_POLE_DEC      = (  -15.10    0."
	    "          0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 111520, "           BODY704_PM            = (    6.77  -26."
	    "7394932   0. )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 111600, "           BODY704_LONG_AXIS     = (    0.        "
	    "             )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 111680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 111760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 111840, "           BODY704_NUT_PREC_RA   = ( 0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 111920, "                                     0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 112000, "                                     0. 0. 0. 0. 0"
	    ".   0.16 )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 112080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 112160, "           BODY704_NUT_PREC_DEC  = ( 0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 112240, "                                     0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 112320, "                                     0. 0. 0. 0. 0"
	    ".   0.16 )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 112400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 112480, "           BODY704_NUT_PREC_PM   = ( 0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 112560, "                                     0. 0. 0. 0. 0."
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 112640, "                                     0. 0. 0. 0. 0"
	    ".   0.04 )", (ftnlen)80, (ftnlen)60);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 112720, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 112800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 112880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 112960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 113040, "     Miranda", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 113120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 113200, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 113280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 113360, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 113440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 113520, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 113600, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 113680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 113760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 113840, "           BODY705_POLE_RA      = (  257.43     0."
	    "         0. )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 113920, "           BODY705_POLE_DEC     = (  -15.08     0."
	    "         0. )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 114000, "           BODY705_PM           = (   30.70  -254."
	    "6906892  0. )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 114080, "           BODY705_LONG_AXIS    = (    0.         "
	    "            )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 114160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 114240, "           BODY705_NUT_PREC_RA  = ( 0.     0.     "
	    "0.    0.    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 114320, "                                    0.     0.     "
	    "0.    0.    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 114400, "                                    4.41   0.     "
	    "0.    0.    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 114480, "                                    0.    -0.04   "
	    "0.             )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 114560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 114640, "           BODY705_NUT_PREC_DEC = ( 0.     0.     "
	    "0.    0.    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 114720, "                                    0.     0.     "
	    "0.    0.    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 114800, "                                    4.25   0.     "
	    "0.    0.    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 114880, "                                    0.    -0.02   "
	    "0.             )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 114960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 115040, "           BODY705_NUT_PREC_PM  = ( 0.     0.     "
	    "0.    0.    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 115120, "                                    0.     0.     "
	    "0.    0.    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 115200, "                                    1.15  -1.27   "
	    "0.    0.    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 115280, "                                    0.    -0.09   "
	    "0.15           )", (ftnlen)80, (ftnlen)66);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 115360, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 115440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 115520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 115600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 115680, "     Cordelia", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 115760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 115840, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 115920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 116000, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 116080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 116160, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 116240, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 116320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 116400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 116480, "           BODY706_POLE_RA      = (   257.31      "
	    "0.         0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 116560, "           BODY706_POLE_DEC     = (   -15.18      "
	    "0.         0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 116640, "           BODY706_PM           = (   127.69  -107"
	    "4.5205730  0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 116720, "           BODY706_LONG_AXIS    = (     0.        "
	    "               )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 116800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 116880, "           BODY706_NUT_PREC_RA  = (   -0.15    0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 116960, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 117040, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 117120, "                                       0.      0. "
	    "    0.             )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 117200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 117280, "           BODY706_NUT_PREC_DEC = (    0.14    0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 117360, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 117440, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 117520, "                                       0.      0. "
	    "    0.             )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 117600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 117680, "           BODY706_NUT_PREC_PM  = (   -0.04    0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 117760, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 117840, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 117920, "                                       0.      0. "
	    "    0.             )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 118000, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 118080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 118160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 118240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 118320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 118400, "     Ophelia", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 118480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 118560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 118640, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 118720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 118800, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 118880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 118960, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 119040, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 119120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 119200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 119280, "           BODY707_POLE_RA      = (  257.31     0."
	    "         0. )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 119360, "           BODY707_POLE_DEC     = (  -15.18     0."
	    "         0. )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 119440, "           BODY707_PM           = (  130.35  -956."
	    "4068150  0. )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 119520, "           BODY707_LONG_AXIS    = (    0.         "
	    "            )", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 119600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 119680, "           BODY707_NUT_PREC_RA  = (    0.     -0.0"
	    "9   0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 119760, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 119840, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 119920, "                                       0.      0. "
	    "    0.             )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 120000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 120080, "           BODY707_NUT_PREC_DEC = (    0.      0.0"
	    "9   0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 120160, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 120240, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 120320, "                                       0.      0. "
	    "    0.             )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 120400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 120480, "           BODY707_NUT_PREC_PM  = (    0.     -0.0"
	    "3   0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 120560, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 120640, "                                       0.      0. "
	    "    0.    0.    0.", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 120720, "                                       0.      0. "
	    "    0.             )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 120800, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 120880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 120960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 121040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 121120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 121200, "     Bianca", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 121280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 121360, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 121440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 121520, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 121600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 121680, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 121760, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 121840, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 121920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 122000, "           BODY708_POLE_RA      = (  257.31     0."
	    "         0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 122080, "           BODY708_POLE_DEC     = (  -15.18     0."
	    "         0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 122160, "           BODY708_PM           = (  105.46  -828."
	    "3914760  0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 122240, "           BODY708_LONG_AXIS    = (    0.         "
	    "             )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 122320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 122400, "           BODY708_NUT_PREC_RA  = (    0.      0. "
	    "   -0.16    0.    0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 122480, "                                       0.      0. "
	    "    0.      0.    0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 122560, "                                       0.      0. "
	    "    0.      0.    0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 122640, "                                       0.      0. "
	    "    0.               )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 122720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 122800, "           BODY708_NUT_PREC_DEC = (    0.      0. "
	    "    0.16    0.    0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 122880, "                                       0.      0. "
	    "    0.      0.    0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 122960, "                                       0.      0. "
	    "    0.      0.    0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 123040, "                                       0.      0. "
	    "    0.               )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 123120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 123200, "           BODY708_NUT_PREC_PM  = (    0.      0. "
	    "   -0.04    0.    0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 123280, "                                       0.      0. "
	    "    0.      0.    0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 123360, "                                       0.      0. "
	    "    0.      0.    0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 123440, "                                       0.      0. "
	    "    0.               )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 123520, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 123600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 123680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 123760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 123840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 123920, "     Cressida", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 124000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 124080, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 124160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 124240, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 124320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 124400, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 124480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 124560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 124640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 124720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 124800, "           BODY709_POLE_RA      = (  257.31      0"
	    ".          0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 124880, "           BODY709_POLE_DEC     = (  -15.18      0"
	    ".          0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 124960, "           BODY709_PM           = (   59.16   -776"
	    ".5816320   0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 125040, "           BODY709_LONG_AXIS    = (    0.         "
	    "               )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 125120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 125200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 125280, "           BODY709_NUT_PREC_RA  = (    0.      0. "
	    "    0.     -0.04   0.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 125360, "                                       0.      0. "
	    "    0.      0.     0.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 125440, "                                       0.      0. "
	    "    0.      0.     0.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 125520, "                                       0.      0. "
	    "    0.                )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 125600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 125680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 125760, "           BODY709_NUT_PREC_DEC = (    0.      0. "
	    "    0.      0.04   0.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 125840, "                                       0.      0. "
	    "    0.      0.     0.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 125920, "                                       0.      0. "
	    "    0.      0.     0.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 126000, "                                       0.      0. "
	    "    0.                )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 126080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 126160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 126240, "           BODY709_NUT_PREC_PM  = (    0.      0. "
	    "    0.     -0.01   0.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 126320, "                                       0.      0. "
	    "    0.      0.     0.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 126400, "                                       0.      0. "
	    "    0.      0.     0.", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 126480, "                                       0.      0. "
	    "    0.                )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 126560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 126640, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 126720, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 126800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 126880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 126960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 127040, "     Desdemona", (ftnlen)80, (ftnlen)14);
    s_copy(pck + 127120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 127200, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 127280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 127360, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 127440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 127520, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 127600, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 127680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 127760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 127840, "           BODY710_POLE_RA      = ( 257.31      0."
	    "           0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 127920, "           BODY710_POLE_DEC     = ( -15.18      0."
	    "           0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 128000, "           BODY710_PM           = (  95.08   -760."
	    "0531690    0.  )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 128080, "           BODY710_LONG_AXIS    = (   0.          "
	    "               )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 128160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 128240, "           BODY710_NUT_PREC_RA  = (   0.      0.  "
	    "   0.      0.    -0.17", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 128320, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 128400, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 128480, "                                      0.      0.  "
	    "   0.                  )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 128560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 128640, "           BODY710_NUT_PREC_DEC = (   0.      0.  "
	    "   0.      0.     0.16", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 128720, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 128800, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 128880, "                                      0.      0.  "
	    "   0.                  )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 128960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 129040, "           BODY710_NUT_PREC_PM  = (   0.      0.  "
	    "   0.      0.    -0.04", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 129120, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 129200, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 129280, "                                      0.      0.  "
	    "   0.                 )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 129360, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 129440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 129520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 129600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 129680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 129760, "     Juliet", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 129840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 129920, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 130000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 130080, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 130160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 130240, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 130320, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 130400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 130480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 130560, "           BODY711_POLE_RA      = (  257.31     0."
	    "           0.   )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 130640, "           BODY711_POLE_DEC     = (  -15.18     0."
	    "           0.   )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 130720, "           BODY711_PM           = (  302.56  -730."
	    "1253660    0.   )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 130800, "           BODY711_LONG_AXIS    = (    0.         "
	    "                )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 130880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 130960, "           BODY711_NUT_PREC_RA  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 131040, "                                     -0.06    0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 131120, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 131200, "                                      0.      0.  "
	    "   0.                 )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 131280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 131360, "           BODY711_NUT_PREC_DEC = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 131440, "                                      0.06    0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 131520, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 131600, "                                      0.      0.  "
	    "   0.                 )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 131680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 131760, "           BODY711_NUT_PREC_PM  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 131840, "                                     -0.02    0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 131920, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 132000, "                                      0.      0.  "
	    "   0.                 )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 132080, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 132160, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 132240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 132320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 132400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 132480, "     Portia", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 132560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 132640, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 132720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 132800, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 132880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 132960, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 133040, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 133120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 133200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 133280, "           BODY712_POLE_RA      = (  257.31      0"
	    ".           0.   )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 133360, "           BODY712_POLE_DEC     = (  -15.18      0"
	    ".           0.   )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 133440, "           BODY712_PM           = (   25.03   -701"
	    ".4865870    0.   )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 133520, "           BODY712_LONG_AXIS    = (    0.         "
	    "                 )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 133600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 133680, "           BODY712_NUT_PREC_RA  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 133760, "                                      0.     -0.09"
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 133840, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 133920, "                                      0.      0.  "
	    "   0.                )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 134000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 134080, "           BODY712_NUT_PREC_DEC = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 134160, "                                      0.      0.09"
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 134240, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 134320, "                                      0.      0.  "
	    "   0.               )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 134400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 134480, "           BODY712_NUT_PREC_PM  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 134560, "                                      0.     -0.02"
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 134640, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 134720, "                                      0.      0.  "
	    "   0.               )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 134800, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 134880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 134960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 135040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 135120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 135200, "     Rosalind", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 135280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 135360, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 135440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 135520, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 135600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 135680, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 135760, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 135840, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 135920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 136000, "           BODY713_POLE_RA      = ( 257.31      0."
	    "          0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 136080, "           BODY713_POLE_DEC     = ( -15.18      0."
	    "          0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 136160, "           BODY713_PM           = ( 314.90   -644."
	    "6311260   0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 136240, "           BODY713_LONG_AXIS    = (   0.          "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 136320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 136400, "           BODY713_NUT_PREC_RA  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 136480, "                                      0.      0.  "
	    "  -0.29    0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 136560, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 136640, "                                      0.      0.  "
	    "   0.               )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 136720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 136800, "           BODY713_NUT_PREC_DEC = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 136880, "                                      0.      0.  "
	    "   0.28    0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 136960, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 137040, "                                      0.      0.  "
	    "   0.              )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 137120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 137200, "           BODY713_NUT_PREC_PM  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 137280, "                                      0.      0.  "
	    "  -0.08    0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 137360, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 137440, "                                      0.      0.  "
	    "   0.              )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 137520, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 137600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 137680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 137760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 137840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 137920, "     Belinda", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 138000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 138080, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 138160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 138240, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 138320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 138400, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 138480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 138560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 138640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 138720, "           BODY714_POLE_RA      = (   257.31      "
	    "0.         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 138800, "           BODY714_POLE_DEC     = (   -15.18      "
	    "0.         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 138880, "           BODY714_PM           = (   297.46   -57"
	    "7.3628170  0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 138960, "           BODY714_LONG_AXIS    = (     0.        "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 139040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 139120, "           BODY714_NUT_PREC_RA  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 139200, "                                      0.      0.  "
	    "   0.     -0.03   0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 139280, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 139360, "                                      0.      0.  "
	    "   0.                )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 139440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 139520, "           BODY714_NUT_PREC_DEC = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 139600, "                                      0.      0.  "
	    "   0.      0.03   0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 139680, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 139760, "                                      0.      0.  "
	    "   0.                )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 139840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 139920, "           BODY714_NUT_PREC_PM  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 140000, "                                      0.      0.  "
	    "   0.     -0.01   0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 140080, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 140160, "                                      0.      0.  "
	    "   0.                )", (ftnlen)80, (ftnlen)72);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 140240, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 140320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 140400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 140480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 140560, "     Puck", (ftnlen)80, (ftnlen)9);
    s_copy(pck + 140640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 140720, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 140800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 140880, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 140960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 141040, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 141120, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 141200, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 141280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 141360, "           BODY715_POLE_RA      = (  257.31      0"
	    ".         0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 141440, "           BODY715_POLE_DEC     = (  -15.18      0"
	    ".         0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 141520, "           BODY715_PM           = (   91.24   -472"
	    ".5450690  0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 141600, "           BODY715_LONG_AXIS    = (    0.         "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 141680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 141760, "           BODY715_NUT_PREC_RA  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 141840, "                                      0.      0.  "
	    "   0.      0.    -0.33", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 141920, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 142000, "                                      0.      0.  "
	    "   0.                  )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 142080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 142160, "           BODY715_NUT_PREC_DEC = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 142240, "                                      0.      0.  "
	    "   0.      0.     0.31", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 142320, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 142400, "                                      0.      0.  "
	    "   0.                  )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 142480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 142560, "           BODY715_NUT_PREC_PM  = (   0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 142640, "                                      0.      0.  "
	    "   0.      0.    -0.09", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 142720, "                                      0.      0.  "
	    "   0.      0.     0.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 142800, "                                      0.      0.  "
	    "   0.                  )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 142880, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 142960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 143040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 143120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 143200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 143280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 143360, "Satellites of Neptune", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 143440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 143520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 143600, "     Triton", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 143680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 143760, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 143840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 143920, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 144000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 144080, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 144160, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 144240, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 144320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 144400, "           BODY801_POLE_RA       = ( 299.36     0."
	    "         0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 144480, "           BODY801_POLE_DEC      = (  41.17     0."
	    "         0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 144560, "           BODY801_PM            = ( 296.53   -61."
	    "2572637  0.  )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 144640, "           BODY801_LONG_AXIS     = (   0.         "
	    "             )", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 144720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 144800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 144880, "           BODY801_NUT_PREC_RA   = (  0.      0.  "
	    "    0.      0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 144960, "                                      0.      0.  "
	    "    0.    -32.35", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 145040, "                                      0.     -6.28"
	    "   -2.08   -0.74", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 145120, "                                     -0.28   -0.11"
	    "   -0.07   -0.02", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 145200, "                                     -0.01        "
	    "                 )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 145280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 145360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 145440, "           BODY801_NUT_PREC_DEC  = (  0.      0.  "
	    "    0.      0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 145520, "                                      0.      0.  "
	    "    0.     22.55", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 145600, "                                      0.      2.10"
	    "    0.55    0.16", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 145680, "                                      0.05    0.02"
	    "    0.01    0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 145760, "                                      0.          "
	    "                 )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 145840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 145920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 146000, "           BODY801_NUT_PREC_PM   = (  0.      0.  "
	    "    0.      0.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 146080, "                                      0.      0.  "
	    "    0.     22.25", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 146160, "                                      0.      6.73"
	    "    2.05    0.74", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 146240, "                                      0.28    0.11"
	    "    0.05    0.02", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 146320, "                                      0.01        "
	    "                 )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 146400, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 146480, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 146560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 146640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 146720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 146800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 146880, "     Nereid", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 146960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 147040, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 147120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 147200, "           Values are from the 1988 IAU report [10"
	    "].  Note that this", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 147280, "           rotation model pre-dated the 1989 Voyag"
	    "er 2 Neptune", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 147360, "           encounter.", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 147440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 147520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 147600, "           body802_pole_ra       = (    273.48    "
	    "0.        0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 147680, "           body802_pole_dec      = (     67.22    "
	    "0.        0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 147760, "           body802_pm            = (    237.22    "
	    "0.9996465 0.  )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 147840, "           body802_long_axis     = (      0.      "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 147920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 148000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 148080, "           The report seems to have a typo:  in th"
	    "e nut_prec_ra expression,", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 148160, "           where the report gives  -0.51 sin 3N3, "
	    "we use -0.51 3N2.", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 148240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 148320, "           body802_nut_prec_ra   = (  0.    -17.81",
	     (ftnlen)80, (ftnlen)50);
    s_copy(pck + 148400, "                                      0.      0.  "
	    "   0.      0.", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 148480, "                                      0.      0.  "
	    "   0.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 148560, "                                      2.56   -0.51"
	    "   0.11   -0.03  )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 148640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 148720, "           body802_nut_prec_dec  = (  0.     -6.67",
	     (ftnlen)80, (ftnlen)50);
    s_copy(pck + 148800, "                                      0.      0.  "
	    "   0.      0.", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 148880, "                                      0.      0.  "
	    "   0.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 148960, "                                      0.47   -0.07"
	    "   0.01          )", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 149040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 149120, "           body802_nut_prec_pm   = (  0.     16.48",
	     (ftnlen)80, (ftnlen)50);
    s_copy(pck + 149200, "                                      0.      0.  "
	    "   0.      0.", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 149280, "                                      0.      0.  "
	    "   0.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 149360, "                                     -2.57    0.51"
	    " -0.11    0.02  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 149440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 149520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 149600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 149680, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 149760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 149840, "           The 2009 report [1] states that values "
	    "for Nereid are not", (ftnlen)80, (ftnlen)68);
    s_copy(pck + 149920, "           given because Nereid is not in synchron"
	    "ous rotation with Neptune", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 150000, "           (notes following table 2).", (ftnlen)80, 
	    (ftnlen)37);
    s_copy(pck + 150080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 150160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 150240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 150320, "     Naiad", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 150400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 150480, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 150560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 150640, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 150720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 150800, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 150880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 150960, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 151040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 151120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 151200, "           BODY803_POLE_RA       = (  299.36      "
	    "0.          0.  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 151280, "           BODY803_POLE_DEC      = (   43.36      "
	    "0.          0.  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 151360, "           BODY803_PM            = (  254.06  +122"
	    "2.8441209   0.  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 151440, "           BODY803_LONG_AXIS     = (    0.        "
	    "                )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 151520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 151600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 151680, "           BODY803_NUT_PREC_RA   = (    0.70     -"
	    "6.49     0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 151760, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 151840, "                                        0.25      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 151920, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 152000, "                                        0.        "
	    "                    )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 152080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 152160, "           BODY803_NUT_PREC_DEC  = (   -0.51     -"
	    "4.75     0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 152240, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 152320, "                                        0.09      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 152400, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 152480, "                                        0.        "
	    "                    )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 152560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 152640, "           BODY803_NUT_PREC_PM   = (   -0.48      "
	    "4.40     0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 152720, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 152800, "                                       -0.27      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 152880, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 152960, "                                        0.        "
	    "                    )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 153040, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 153120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 153200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 153280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 153360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 153440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 153520, "     Thalassa", (ftnlen)80, (ftnlen)13);
    s_copy(pck + 153600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 153680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 153760, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 153840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 153920, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 154000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 154080, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 154160, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 154240, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 154320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 154400, "           BODY804_POLE_RA       = (  299.36      "
	    "0.          0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 154480, "           BODY804_POLE_DEC      = (   43.45      "
	    "0.          0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 154560, "           BODY804_PM            = (  102.06   115"
	    "5.7555612   0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 154640, "           BODY804_LONG_AXIS     = (    0.        "
	    "               )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 154720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 154800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 154880, "           BODY804_NUT_PREC_RA   = (    0.70      "
	    "0.      -0.28    0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 154960, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 155040, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 155120, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 155200, "                                        0.        "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 155280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 155360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 155440, "           BODY804_NUT_PREC_DEC  = (   -0.51      "
	    "0.      -0.21    0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 155520, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 155600, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 155680, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 155760, "                                        0.        "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 155840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 155920, "           BODY804_NUT_PREC_PM   = (   -0.48      "
	    "0.       0.19    0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 156000, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 156080, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 156160, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 156240, "                                        0.        "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 156320, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 156400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 156480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 156560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 156640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 156720, "     Despina", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 156800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 156880, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 156960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 157040, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 157120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 157200, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 157280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 157360, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 157440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 157520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 157600, "           BODY805_POLE_RA       = (  299.36      "
	    "0.          0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 157680, "           BODY805_POLE_DEC      = (   43.45      "
	    "0.          0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 157760, "           BODY805_PM            = (  306.51  +107"
	    "5.7341562   0. )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 157840, "           BODY805_LONG_AXIS     = (    0.        "
	    "               )", (ftnlen)80, (ftnlen)66);
    s_copy(pck + 157920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 158000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 158080, "           BODY805_NUT_PREC_RA   = (    0.70      "
	    "0.       0.     -0.09", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 158160, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 158240, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 158320, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 158400, "                                        0.        "
	    "                      )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 158480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 158560, "           BODY805_NUT_PREC_DEC  = (   -0.51      "
	    "0.       0.     -0.07", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 158640, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 158720, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 158800, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 158880, "                                        0.        "
	    "                      )", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 158960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 159040, "           BODY805_NUT_PREC_PM   = (   -0.49      "
	    "0.       0.      0.06", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 159120, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 159200, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 159280, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 159360, "                                        0.        "
	    "                      )", (ftnlen)80, (ftnlen)73);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 159440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 159520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 159600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 159680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 159760, "     Galatea", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 159840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 159920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 160000, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 160080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 160160, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 160240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 160320, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 160400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 160480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 160560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 160640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 160720, "           BODY806_POLE_RA       = (   299.36     "
	    " 0.          0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 160800, "           BODY806_POLE_DEC      = (    43.43     "
	    " 0.          0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 160880, "           BODY806_PM            = (   258.09    8"
	    "39.6597686   0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 160960, "           BODY806_LONG_AXIS     = (     0.       "
	    "                )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 161040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 161120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 161200, "           BODY806_NUT_PREC_RA   = (    0.70      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 161280, "                                       -0.07      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 161360, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 161440, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 161520, "                                        0.        "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 161600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 161680, "           BODY806_NUT_PREC_DEC  = (   -0.51      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 161760, "                                       -0.05      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 161840, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 161920, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 162000, "                                        0.        "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 162080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 162160, "           BODY806_NUT_PREC_PM   = (   -0.48      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 162240, "                                        0.05      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 162320, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 162400, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 162480, "                                        0.        "
	    "                     )", (ftnlen)80, (ftnlen)72);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 162560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 162640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 162720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 162800, "     Larissa", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 162880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 162960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 163040, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 163120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 163200, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 163280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 163360, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 163440, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 163520, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 163600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 163680, "           BODY807_POLE_RA       = (   299.36     "
	    "0.           0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 163760, "           BODY807_POLE_DEC      = (    43.41     "
	    "0.           0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 163840, "           BODY807_PM            = (   179.41  +64"
	    "9.0534470    0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 163920, "           BODY807_LONG_AXIS     = (     0.       "
	    "                )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 164000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 164080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 164160, "           BODY807_NUT_PREC_RA   = (    0.70      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 164240, "                                        0.       -"
	    "0.27     0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 164320, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 164400, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 164480, "                                        0.        "
	    "                    )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 164560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 164640, "           BODY807_NUT_PREC_DEC  = (   -0.51      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 164720, "                                        0.       -"
	    "0.20     0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 164800, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 164880, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 164960, "                                        0.        "
	    "                    )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 165040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 165120, "           BODY807_NUT_PREC_PM   = (   -0.48      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 165200, "                                        0.        "
	    "0.19     0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 165280, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 165360, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 165440, "                                        0.        "
	    "                    )", (ftnlen)80, (ftnlen)71);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 165520, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 165600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 165680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 165760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 165840, "     Proteus", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 165920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 166000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 166080, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 166160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 166240, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 166320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 166400, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 166480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 166560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 166640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 166720, "           BODY808_POLE_RA       = (  299.27      "
	    "0.          0.  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 166800, "           BODY808_POLE_DEC      = (   42.91      "
	    "0.          0.  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 166880, "           BODY808_PM            = (   93.38   +32"
	    "0.7654228   0.  )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 166960, "           BODY808_LONG_AXIS     = (    0.        "
	    "                )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 167040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 167120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 167200, "           BODY808_NUT_PREC_RA   = (    0.70      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 167280, "                                        0.        "
	    "0.      -0.05    0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 167360, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 167440, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 167520, "                                        0.        "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 167600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 167680, "           BODY808_NUT_PREC_DEC  = (   -0.51      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 167760, "                                        0.        "
	    "0.      -0.04    0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 167840, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 167920, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 168000, "                                        0.        "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 168080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 168160, "           BODY808_NUT_PREC_PM   = (   -0.48      "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 168240, "                                        0.        "
	    "0.       0.04    0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 168320, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 168400, "                                        0.        "
	    "0.       0.      0.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 168480, "                                        0.        "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 168560, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 168640, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 168720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 168800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 168880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 168960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 169040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 169120, "Satellites of Pluto", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 169200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 169280, "     Charon", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 169360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 169440, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 169520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 169600, "           Values are from the 2006 IAU report.", (
	    ftnlen)80, (ftnlen)47);
    s_copy(pck + 169680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 169760, "           body901_pole_ra       = (   312.993    "
	    "0.         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 169840, "           body901_pole_dec      = (     6.163    "
	    "0.         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 169920, "           body901_pm            = (    57.305  -5"
	    "6.3625225  0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 170000, "           body901_long_axis     = (     0.       "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 170080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 170160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 170240, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 170320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 170400, "        Due to the new definition of planetocentri"
	    "c coordinates", (ftnlen)80, (ftnlen)63);
    s_copy(pck + 170480, "        for small bodies, and to the reclassificat"
	    "ion of Pluto", (ftnlen)80, (ftnlen)62);
    s_copy(pck + 170560, "        as a dwarf planet, Charon's north pole dir"
	    "ection has been", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 170640, "        inverted.", (ftnlen)80, (ftnlen)17);
    s_copy(pck + 170720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 170800, "        The PM constant W0 is from [2].", (ftnlen)
	    80, (ftnlen)39);
    s_copy(pck + 170880, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 170960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 171040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 171120, "           BODY901_POLE_RA       = (   132.993    "
	    "0.         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 171200, "           BODY901_POLE_DEC      = (    -6.163    "
	    "0.         0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 171280, "           BODY901_PM            = (   122.695   5"
	    "6.3625225  0. )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 171360, "           BODY901_LONG_AXIS     = (     0.       "
	    "              )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 171440, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 171520, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 171600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 171680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 171760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 171840, "Orientation constants for Selected Comets and Aste"
	    "roids", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 171920, "--------------------------------------------------"
	    "------", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 172000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 172080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 172160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 172240, "Ceres", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 172320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 172400, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 172480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 172560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 172640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 172720, "           BODY2000001_POLE_RA       = (   291.   "
	    "    0.         0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 172800, "           BODY2000001_POLE_DEC      = (    59.   "
	    "    0.         0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 172880, "           BODY2000001_PM            = (   170.90 "
	    "  952.1532     0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 172960, "           BODY2000001_LONG_AXIS     = (     0.   "
	    "                   )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 173040, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 173120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 173200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 173280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 173360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 173440, "Pallas", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 173520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 173600, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 173680, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 173760, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 173840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 173920, "           BODY2000002_POLE_RA       = (    33.   "
	    "    0.         0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 174000, "           BODY2000002_POLE_DEC      = (    -3.   "
	    "    0.         0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 174080, "           BODY2000002_PM            = (    38.   "
	    " 1105.8036     0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 174160, "           BODY2000002_LONG_AXIS     = (     0.   "
	    "                   )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 174240, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 174320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 174400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 174480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 174560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 174640, "Vesta", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 174720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 174800, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 174880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 174960, "           Values are from the 2009 IAU report.", (
	    ftnlen)80, (ftnlen)47);
    s_copy(pck + 175040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 175120, "           body2000004_pole_ra       = (   301.   "
	    "   0.         0.  )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 175200, "           body2000004_pole_dec      = (    41.   "
	    "   0.         0.  )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 175280, "           body2000004_pm            = (   292.   "
	    "1617.332776   0.  )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 175360, "           body2000004_long_axis     = (     0.   "
	    "                  )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 175440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 175520, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 175600, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 175680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 175760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 175840, "           BODY2000004_POLE_RA       = (   305.8  "
	    "   0.         0.  )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 175920, "           BODY2000004_POLE_DEC      = (    41.4  "
	    "   0.         0.  )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 176000, "           BODY2000004_PM            = (   292.   "
	    "1617.332776   0.  )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 176080, "           BODY2000004_LONG_AXIS     = (     0.   "
	    "                  )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 176160, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 176240, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 176320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 176400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 176480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 176560, "Lutetia", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 176640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 176720, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 176800, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 176880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 176960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 177040, "           BODY2000021_POLE_RA       = (    52.   "
	    "    0.         0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 177120, "           BODY2000021_POLE_DEC      = (    12.   "
	    "    0.         0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 177200, "           BODY2000021_PM            = (    94.   "
	    " 1057.7515     0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 177280, "           BODY2000021_LONG_AXIS     = (     0.   "
	    "                   )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 177360, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 177440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 177520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 177600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 177680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 177760, "Ida", (ftnlen)80, (ftnlen)3);
    s_copy(pck + 177840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 177920, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 178000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 178080, "           BODY2431010_POLE_RA       = (  168.76  "
	    "    0.         0. )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 178160, "           BODY2431010_POLE_DEC      = (   -2.88  "
	    "    0.         0. )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 178240, "           BODY2431010_PM            = (  265.95  "
	    "+1864.6280070  0. )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 178320, "           BODY2431010_LONG_AXIS     = (    0.    "
	    "                  )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 178400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 178480, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 178560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 178640, "        The PM constant W0 is from [2].", (ftnlen)
	    80, (ftnlen)39);
    s_copy(pck + 178720, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 178800, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 178880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 178960, "           BODY2431010_POLE_RA       = (  168.76  "
	    "    0.         0. )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 179040, "           BODY2431010_POLE_DEC      = (   -2.88  "
	    "    0.         0. )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 179120, "           BODY2431010_PM            = (  274.05  "
	    "+1864.6280070  0. )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 179200, "           BODY2431010_LONG_AXIS     = (    0.    "
	    "                  )", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 179280, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 179360, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 179440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 179520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 179600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 179680, "Eros", (ftnlen)80, (ftnlen)4);
    s_copy(pck + 179760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 179840, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 179920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 180000, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 180080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 180160, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 180240, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 180320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 180400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 180480, "           BODY2000433_POLE_RA       = (   11.35  "
	    "     0.           0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 180560, "           BODY2000433_POLE_DEC      = (   17.22  "
	    "     0.           0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 180640, "           BODY2000433_PM            = (  326.07  "
	    "  1639.38864745   0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 180720, "           BODY2000433_LONG_AXIS     = (    0.    "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 180800, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 180880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 180960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 181040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 181120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 181200, "Davida", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 181280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 181360, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 181440, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 181520, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 181600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 181680, "           BODY2000511_POLE_RA       = (  297.    "
	    "    0.           0. )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 181760, "           BODY2000511_POLE_DEC      = (    5.    "
	    "    0.           0. )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 181840, "           BODY2000511_PM            = (  268.1   "
	    " 1684.4193549    0. )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 181920, "           BODY2000511_LONG_AXIS     = (    0.    "
	    "                    )", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 182000, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 182080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 182160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 182240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 182320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 182400, "Gaspra", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 182480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 182560, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 182640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 182720, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 182800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 182880, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 182960, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 183040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 183120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 183200, "           BODY9511010_POLE_RA       = (   9.47   "
	    "  0.         0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 183280, "           BODY9511010_POLE_DEC      = (  26.70   "
	    "  0.         0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 183360, "           BODY9511010_PM            = (  83.67  1"
	    "226.9114850  0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 183440, "           BODY9511010_LONG_AXIS     = (   0.     "
	    "                )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 183520, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 183600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 183680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 183760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 183840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 183920, "Steins", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 184000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 184080, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 184160, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 184240, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 184320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 184400, "           BODY2002867_POLE_RA       = (  90.     "
	    "   0.        0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 184480, "           BODY2002867_POLE_DEC      = ( -62.     "
	    "   0.        0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 184560, "           BODY2002867_PM            = (  93.94   "
	    "1428.852332  0. )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 184640, "           BODY2002867_LONG_AXIS     = (   0.     "
	    "                )", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 184720, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 184800, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 184880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 184960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 185040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 185120, "Itokawa", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 185200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 185280, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 185360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 185440, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 185520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 185600, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 185680, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 185760, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 185840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 185920, "           BODY2025143_POLE_RA       = (   90.53  "
	    "     0.           0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 186000, "           BODY2025143_POLE_DEC      = (  -66.30  "
	    "     0.           0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 186080, "           BODY2025143_PM            = (  000.0   "
	    "   712.143        0. )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 186160, "           BODY2025143_LONG_AXIS     = (    0.    "
	    "                     )", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 186240, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 186320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 186400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 186480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 186560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 186640, "9P/Tempel 1", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 186720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 186800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 186880, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 186960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 187040, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 187120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 187200, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 187280, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 187360, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 187440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 187520, "           BODY1000093_POLE_RA       = (   294.   "
	    "    0.         0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 187600, "           BODY1000093_POLE_DEC      = (    73.   "
	    "    0.         0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 187680, "           BODY1000093_PM            = (   252.63 "
	    "  212.064      0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 187760, "           BODY1000093_LONG_AXIS     = (     0.   "
	    "                   )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 187840, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 187920, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 188000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 188080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 188160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 188240, "19P/Borrelly", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 188320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 188400, "        Old values:", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 188480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 188560, "           Values are unchanged in the 2009 IAU re"
	    "port.", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 188640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 188720, "        Current values:", (ftnlen)80, (ftnlen)23);
    s_copy(pck + 188800, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 188880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 188960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 189040, "           BODY1000005_POLE_RA       = (   218.5  "
	    "    0.         0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 189120, "           BODY1000005_POLE_DEC      = (   -12.5  "
	    "    0.         0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 189200, "           BODY1000005_PM            = (   000.   "
	    "  390.0        0.  )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 189280, "           BODY1000005_LONG_AXIS     = (     0.   "
	    "                   )", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 189360, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 189440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 189520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 189600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 189680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 189760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 189840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 189920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 190000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 190080, "Radii of Sun and Planets", (ftnlen)80, (ftnlen)24);
    s_copy(pck + 190160, "--------------------------------------------------"
	    "------", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 190240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 190320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 190400, "Sun", (ftnlen)80, (ftnlen)3);
    s_copy(pck + 190480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 190560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 190640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 190720, "        BODY10_RADII      = (  696000.  696000.  6"
	    "96000.  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 190800, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 190880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 190960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 191040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 191120, "Mercury", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 191200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 191280, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 191360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 191440, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 191520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 191600, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 191680, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 191760, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 191840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 191920, "        BODY199_RADII     = ( 2439.7   2439.7   24"
	    "39.7 )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 192000, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 192080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 192160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 192240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 192320, "Venus", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 192400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 192480, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 192560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 192640, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 192720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 192800, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 192880, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 192960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 193040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 193120, "        BODY299_RADII     = ( 6051.8   6051.8   60"
	    "51.8 )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 193200, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 193280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 193360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 193440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 193520, "Earth", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 193600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 193680, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 193760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 193840, "        Values are from the 2006 IAU report.", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 193920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 194000, "        body399_radii     = ( 6378.14   6378.14   "
	    "6356.75 )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 194080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 194160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 194240, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 194320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 194400, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 194480, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 194560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 194640, "        BODY399_RADII     = ( 6378.1366   6378.136"
	    "6   6356.7519 )", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 194720, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 194800, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 194880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 194960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 195040, "Mars", (ftnlen)80, (ftnlen)4);
    s_copy(pck + 195120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 195200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 195280, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 195360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 195440, "        Values are from the 2006 IAU report.", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 195520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 195600, "        body499_radii       = (  3397.  3397.  337"
	    "5.  )", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 195680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 195760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 195840, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 195920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 196000, "        The 2009 IAU report gives separate values "
	    "for the north and", (ftnlen)80, (ftnlen)67);
    s_copy(pck + 196080, "        south polar radii:", (ftnlen)80, (ftnlen)26)
	    ;
    s_copy(pck + 196160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 196240, "           north:  3373.19", (ftnlen)80, (ftnlen)26)
	    ;
    s_copy(pck + 196320, "           south:  3379.21", (ftnlen)80, (ftnlen)26)
	    ;
    s_copy(pck + 196400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 196480, "        The report provides the average of these v"
	    "alues as well,", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 196560, "        which we use as the polar radius for the t"
	    "riaxial model.", (ftnlen)80, (ftnlen)64);
    s_copy(pck + 196640, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 196720, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 196800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 196880, "        BODY499_RADII       = ( 3396.19   3396.19 "
	    "  3376.20 )", (ftnlen)80, (ftnlen)61);
    s_copy(pck + 196960, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 197040, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 197120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 197200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 197280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 197360, "Jupiter", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 197440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 197520, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 197600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 197680, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 197760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 197840, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 197920, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 198000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 198080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 198160, "        BODY599_RADII     = ( 71492   71492   6685"
	    "4 )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 198240, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 198320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 198400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 198480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 198560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 198640, "Saturn", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 198720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 198800, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 198880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 198960, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 199040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 199120, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 199200, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 199280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 199360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 199440, "        BODY699_RADII     = ( 60268   60268   5436"
	    "4 )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 199520, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 199600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 199680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 199760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 199840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 199920, "Uranus", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 200000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 200080, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 200160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 200240, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 200320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 200400, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 200480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 200560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 200640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 200720, "        BODY799_RADII     = ( 25559   25559   2497"
	    "3 )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 200800, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 200880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 200960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 201040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 201120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 201200, "Neptune", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 201280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 201360, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 201440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 201520, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 201600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 201680, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 201760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 201840, "        (Values are for the 1 bar pressure level.)",
	     (ftnlen)80, (ftnlen)50);
    s_copy(pck + 201920, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 202000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 202080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 202160, "        BODY899_RADII     = ( 24764   24764  24341"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 202240, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 202320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 202400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 202480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 202560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 202640, "Radii of the Dwarf Planet Pluto", (ftnlen)80, (
	    ftnlen)31);
    s_copy(pck + 202720, "--------------------------------------------------"
	    "------", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 202800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 202880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 202960, "Pluto", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 203040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 203120, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 203200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 203280, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 203360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 203440, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 203520, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 203600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 203680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 203760, "        BODY999_RADII     = ( 1195   1195   1195 )",
	     (ftnlen)80, (ftnlen)50);
    s_copy(pck + 203840, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 203920, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 204000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 204080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 204160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 204240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 204320, "Radii of Satellites", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 204400, "--------------------------------------------------"
	    "------", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 204480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 204560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 204640, "Moon", (ftnlen)80, (ftnlen)4);
    s_copy(pck + 204720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 204800, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 204880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 204960, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 205040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 205120, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 205200, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 205280, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 205360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 205440, "        BODY301_RADII     = ( 1737.4   1737.4   17"
	    "37.4 )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 205520, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 205600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 205680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 205760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 205840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 205920, "Satellites of Mars", (ftnlen)80, (ftnlen)18);
    s_copy(pck + 206000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 206080, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 206160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 206240, "        Values are from the 2006 IAU report.", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 206320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 206400, "        body401_radii     = ( 13.4    11.2    9.2 )"
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 206480, "        body402_radii     = (  7.5     6.1    5.2 )"
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 206560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 206640, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 206720, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 206800, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 206880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 206960, "        BODY401_RADII     = ( 13.0    11.4    9.1 )"
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 207040, "        BODY402_RADII     = (  7.8     6.0    5.1 )"
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 207120, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 207200, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 207280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 207360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 207440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 207520, "Satellites of Jupiter", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 207600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 207680, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 207760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 207840, "        Values are unchanged in the 2009 IAU repor"
	    "t,", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 207920, "        except for those of Europa, Ganymede, Call"
	    "isto,", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 208000, "        and Metis. For Metis, now all three radii "
	    "are", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 208080, "        provided.", (ftnlen)80, (ftnlen)17);
    s_copy(pck + 208160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 208240, "           body502_radii     = ( 1564.13  1561.23 "
	    " 1560.93 )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 208320, "           body503_radii     = ( 2632.4   2632.29 "
	    " 2632.35 )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 208400, "           body504_radii     = ( 2409.4   2409.2  "
	    " 2409.3  )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 208480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 208560, "           The value for the second radius for bod"
	    "y 516 is not given in", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 208640, "           2003 IAU report.   The values given are:"
	    , (ftnlen)80, (ftnlen)51);
    s_copy(pck + 208720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 208800, "              body516_radii    = (  30   ---   20 "
	    "  )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 208880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 208960, "           For use within the SPICE system, we use"
	    " only the mean radius.", (ftnlen)80, (ftnlen)72);
    s_copy(pck + 209040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 209120, "           body516_radii    = (  21.5   21.5  21.5"
	    "  )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 209200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 209280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 209360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 209440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 209520, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 209600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 209680, "        Note that for Ganymede and Callisto only m"
	    "ean radii", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 209760, "        are provided.", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 209840, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 209920, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 210000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 210080, "        BODY501_RADII     = ( 1829.4   1819.4   18"
	    "15.7  )", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 210160, "        BODY502_RADII     = ( 1562.6  1560.3    15"
	    "59.5  )", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 210240, "        BODY503_RADII     = ( 2631.2  2631.2    26"
	    "31.2  )", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 210320, "        BODY504_RADII     = ( 2410.3  2410.3    24"
	    "10.3  )", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 210400, "        BODY505_RADII     = (  125       73       "
	    "64    )", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 210480, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 210560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 210640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 210720, "        Only mean radii are available in the 2003 "
	    "IAU report for bodies", (ftnlen)80, (ftnlen)71);
    s_copy(pck + 210800, "        506-513.", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 210880, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 210960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 211040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 211120, "        BODY506_RADII    = (    85       85       "
	    "85   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 211200, "        BODY507_RADII    = (    40       40       "
	    "40   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 211280, "        BODY508_RADII    = (    18       18       "
	    "18   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 211360, "        BODY509_RADII    = (    14       14       "
	    "14   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 211440, "        BODY510_RADII    = (    12       12       "
	    "12   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 211520, "        BODY511_RADII    = (    15       15       "
	    "15   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 211600, "        BODY512_RADII    = (    10       10       "
	    "10   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 211680, "        BODY513_RADII    = (     5        5       "
	    " 5   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 211760, "        BODY514_RADII    = (    58       49       "
	    "42   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 211840, "        BODY515_RADII    = (    10        8       "
	    " 7   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 211920, "        BODY516_RADII    = (    30       20       "
	    "17   )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 212000, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 212080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 212160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 212240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 212320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 212400, "Satellites of Saturn", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 212480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 212560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 212640, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 212720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 212800, "        Values are from the 2006 IAU report.", (
	    ftnlen)80, (ftnlen)44);
    s_copy(pck + 212880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 212960, "        body601_radii     = (  207.4     196.8    "
	    " 190.6  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 213040, "        body602_radii     = (  256.6     251.4    "
	    " 248.3  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 213120, "        body603_radii     = (  540.4     531.1    "
	    " 527.5  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 213200, "        body604_radii     = (  563.8     561.0    "
	    " 560.3  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 213280, "        body605_radii     = (  767.2     762.5    "
	    " 763.1  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 213360, "        body606_radii     = ( 2575      2575      "
	    "2575    )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 213440, "        body607_radii     = (  164       130      "
	    " 107    )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 213520, "        body608_radii     = (  747.4     747.4    "
	    " 712.4  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 213600, "        body609_radii     = (  108.6     107.7    "
	    " 101.5  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 213680, "        body610_radii     = (   97.0      95.0    "
	    "  77.0  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 213760, "        body611_radii     = (   69.0      55.0    "
	    "  55.0  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 213840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 213920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 214000, "        Only the first equatorial radius for Helen"
	    "e (body 612) is given in the", (ftnlen)80, (ftnlen)78);
    s_copy(pck + 214080, "        2006 IAU report:", (ftnlen)80, (ftnlen)24);
    s_copy(pck + 214160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 214240, "            body612_radii     = (       17.5      "
	    "  ---          ---     )", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 214320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 214400, "        The mean radius is 16km; we use this radiu"
	    "s for all three axes, as", (ftnlen)80, (ftnlen)74);
    s_copy(pck + 214480, "        we do for the satellites for which only th"
	    "e mean radius is available.", (ftnlen)80, (ftnlen)77);
    s_copy(pck + 214560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 214640, "        body612_radii     = (  17.5      17.5     "
	    " 17.5  )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 214720, "        body613_radii     = (  15        12.5     "
	    "  7.5  )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 214800, "        body614_radii     = (  15.0       8.0     "
	    "  8.0  )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 214880, "        body615_radii     = (  18.5      17.2     "
	    " 13.5  )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 214960, "        body616_radii     = (  74.0      50.0     "
	    " 34.0  )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 215040, "        body617_radii     = (  55.0      44.0     "
	    " 31.0  )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 215120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 215200, "         For Pan, only a mean radius is given in t"
	    "he 2006 report.", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 215280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 215360, "        body618_radii     = (   10       10     10"
	    "   )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 215440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 215520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 215600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 215680, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 215760, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 215840, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 215920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 216000, "        BODY601_RADII     = (  207.8     196.7    "
	    " 190.6   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 216080, "        BODY602_RADII     = (  256.6     251.4    "
	    " 248.3   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 216160, "        BODY603_RADII     = (  538.4     528.3    "
	    " 526.3   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 216240, "        BODY604_RADII     = (  563.4     561.3    "
	    " 559.6   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 216320, "        BODY605_RADII     = (  765.0     763.1    "
	    " 762.4   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 216400, "        BODY606_RADII     = ( 2575.15    2574.78  "
	    " 2574.47 )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 216480, "        BODY607_RADII     = (  180.1      133.0   "
	    " 102.7   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 216560, "        BODY608_RADII     = (  745.7     745.7    "
	    " 712.1   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 216640, "        BODY609_RADII     = (  109.4     108.5    "
	    " 101.8   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 216720, "        BODY610_RADII     = (  101.5      92.5    "
	    "  76.3   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 216800, "        BODY611_RADII     = (   64.9      57.0    "
	    "  53.1   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 216880, "        BODY612_RADII     = (   21.7      19.1    "
	    "  13.0   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 216960, "        BODY613_RADII     = (   16.3      11.8    "
	    "  10.0   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 217040, "        BODY614_RADII     = (   15.1      11.5    "
	    "   7.0   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 217120, "        BODY615_RADII     = (   20.4      17.7    "
	    "   9.4   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 217200, "        BODY616_RADII     = (   67.8      39.7    "
	    "  29.7   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 217280, "        BODY617_RADII     = (   52.0      40.5    "
	    "  32.0   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 217360, "        BODY618_RADII     = (   17.2      15.7    "
	    "  10.4   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 217440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 217520, "        BODY632_RADII     = (    1.6       1.6    "
	    "   1.6   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 217600, "        BODY633_RADII     = (    2.9       2.8    "
	    "   2.0   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 217680, "        BODY634_RADII     = (    1.5       1.2    "
	    "   1.0   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 217760, "        BODY635_RADII     = (    4.3       4.1    "
	    "   3.2   )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 217840, "        BODY649_RADII     = (    1         1      "
	    "   1     )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 217920, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 218000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 218080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 218160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 218240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 218320, "Satellites of Uranus", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 218400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 218480, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 218560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 218640, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 218720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 218800, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 218880, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 218960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 219040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 219120, "        BODY701_RADII     = (  581.1   577.9   577"
	    ".7 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 219200, "        BODY702_RADII     = (  584.7   584.7   584"
	    ".7 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 219280, "        BODY703_RADII     = (  788.9   788.9   788"
	    ".9 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 219360, "        BODY704_RADII     = (  761.4   761.4   761"
	    ".4 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 219440, "        BODY705_RADII     = (  240.4   234.2   232"
	    ".9 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 219520, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 219600, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 219680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 219760, "        The 2000 report gives only mean radii for "
	    "satellites 706--715.", (ftnlen)80, (ftnlen)70);
    s_copy(pck + 219840, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 219920, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 220000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 220080, "        BODY706_RADII     = (   13      13      13"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 220160, "        BODY707_RADII     = (   15      15      15"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 220240, "        BODY708_RADII     = (   21      21      21"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 220320, "        BODY709_RADII     = (   31      31      31"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 220400, "        BODY710_RADII     = (   27      27      27"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 220480, "        BODY711_RADII     = (   42      42      42"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 220560, "        BODY712_RADII     = (   54      54      54"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 220640, "        BODY713_RADII     = (   27      27      27"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 220720, "        BODY714_RADII     = (   33      33      33"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 220800, "        BODY715_RADII     = (   77      77      77"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 220880, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 220960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 221040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 221120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 221200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 221280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 221360, "Satellites of Neptune", (ftnlen)80, (ftnlen)21);
    s_copy(pck + 221440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 221520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 221600, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 221680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 221760, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 221840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 221920, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 222000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 222080, "        The 2009 report gives mean radii only for "
	    "bodies 801-806.", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 222160, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 222240, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 222320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 222400, "        BODY801_RADII     = ( 1352.6  1352.6  1352"
	    ".6 )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 222480, "        BODY802_RADII     = (  170     170     170"
	    "   )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 222560, "        BODY803_RADII     = (   29      29     29 "
	    "   )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 222640, "        BODY804_RADII     = (   40      40     40 "
	    "   )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 222720, "        BODY805_RADII     = (   74      74     74 "
	    "   )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 222800, "        BODY806_RADII     = (   79      79     79 "
	    "   )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 222880, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 222960, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 223040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 223120, "        The second equatorial radius for Larissa i"
	    "s not given in the 2009", (ftnlen)80, (ftnlen)73);
    s_copy(pck + 223200, "        report.  The available values are:", (
	    ftnlen)80, (ftnlen)42);
    s_copy(pck + 223280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 223360, "            BODY807_RADII     = (   104     ---   "
	    "  89   )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 223440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 223520, "        For use within the SPICE system, we use on"
	    "ly the mean radius.", (ftnlen)80, (ftnlen)69);
    s_copy(pck + 223600, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 223680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 223760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 223840, "        BODY807_RADII     = (   96      96     96 "
	    "  )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 223920, "        BODY808_RADII     = (  218     208    201 "
	    "  )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 224000, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 224080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 224160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 224240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 224320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 224400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 224480, "Satellites of Pluto", (ftnlen)80, (ftnlen)19);
    s_copy(pck + 224560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 224640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 224720, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 224800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 224880, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 224960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 225040, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 225120, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 225200, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 225280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 225360, "        BODY901_RADII     = (  605     605    605 "
	    "  )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 225440, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 225520, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 225600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 225680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 225760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 225840, "Radii for Selected Comets and Asteroids", (ftnlen)
	    80, (ftnlen)39);
    s_copy(pck + 225920, "--------------------------------------------------"
	    "------", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 226000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 226080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 226160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 226240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 226320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 226400, "Ceres", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 226480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 226560, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 226640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 226720, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 226800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 226880, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 226960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 227040, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 227120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 227200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 227280, "        BODY2000001_RADII     = ( 487.3  487.3  45"
	    "4.7 )", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 227360, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 227440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 227520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 227600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 227680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 227760, "Vesta", (ftnlen)80, (ftnlen)5);
    s_copy(pck + 227840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 227920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 228000, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 228080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 228160, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 228240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 228320, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 228400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 228480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 228560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 228640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 228720, "        BODY2000004_RADII     = ( 289.  280.  229."
	    "  )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 228800, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 228880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 228960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 229040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 229120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 229200, "Lutetia", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 229280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 229360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 229440, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 229520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 229600, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 229680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 229760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 229840, "        BODY2000021_RADII     = (  62.0   50.5   4"
	    "6.5  )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 229920, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 230000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 230080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 230160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 230240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 230320, "Ida", (ftnlen)80, (ftnlen)3);
    s_copy(pck + 230400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 230480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 230560, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 230640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 230720, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 230800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 230880, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 230960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 231040, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 231120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 231200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 231280, "        BODY2431010_RADII     = (   26.8   12.0   "
	    " 7.6 )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 231360, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 231440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 231520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 231600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 231680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 231760, "Mathilde", (ftnlen)80, (ftnlen)8);
    s_copy(pck + 231840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 231920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 232000, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 232080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 232160, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 232240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 232320, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 232400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 232480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 232560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 232640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 232720, "        BODY2000253_RADII     = (  33.   24.   23."
	    "  )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 232800, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 232880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 232960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 233040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 233120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 233200, "Eros", (ftnlen)80, (ftnlen)4);
    s_copy(pck + 233280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 233360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 233440, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 233520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 233600, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 233680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 233760, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 233840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 233920, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 234000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 234080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 234160, "        BODY2000433_RADII     = (  17.0   5.5   5."
	    "5  )", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 234240, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 234320, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 234400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 234480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 234560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 234640, "Davida", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 234720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 234800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 234880, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 234960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 235040, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 235120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 235200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 235280, "        BODY2000511_RADII     = (  180.   147.   1"
	    "27.  )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 235360, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 235440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 235520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 235600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 235680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 235760, "Gaspra", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 235840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 235920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 236000, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 236080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 236160, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 236240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 236320, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 236400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 236480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 236560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 236640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 236720, "        BODY9511010_RADII     = (    9.1    5.2   "
	    " 4.4 )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 236800, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 236880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 236960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 237040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 237120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 237200, "Steins", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 237280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 237360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 237440, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 237520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 237600, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 237680, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 237760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 237840, "        BODY2002867_RADII     = (  3.24     2.73  "
	    "   2.04  )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 237920, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 238000, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 238080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 238160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 238240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 238320, "Toutatis", (ftnlen)80, (ftnlen)8);
    s_copy(pck + 238400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 238480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 238560, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 238640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 238720, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 238800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 238880, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 238960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 239040, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 239120, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 239200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 239280, "        BODY2004179_RADII     = (  2.13  1.015  0."
	    "85  )", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 239360, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 239440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 239520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 239600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 239680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 239760, "Itokawa", (ftnlen)80, (ftnlen)7);
    s_copy(pck + 239840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 239920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 240000, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 240080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 240160, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 240240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 240320, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 240400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 240480, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 240560, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 240640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 240720, "        BODY2025143_RADII     = (  0.535   0.294  "
	    " 0.209  )", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 240800, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 240880, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 240960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 241040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 241120, "Kleopatra", (ftnlen)80, (ftnlen)9);
    s_copy(pck + 241200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 241280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 241360, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 241440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 241520, "        Values are from the 2003 report.", (ftnlen)
	    80, (ftnlen)40);
    s_copy(pck + 241600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 241680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 241760, "        body2000216_radii     = (   108.5      47 "
	    "   40.5  )", (ftnlen)80, (ftnlen)60);
    s_copy(pck + 241840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 241920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 242000, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 242080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 242160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 242240, "        No values are provided in the 2009 report.",
	     (ftnlen)80, (ftnlen)50);
    s_copy(pck + 242320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 242400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 242480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 242560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 242640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 242720, "Halley", (ftnlen)80, (ftnlen)6);
    s_copy(pck + 242800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 242880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 242960, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 243040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 243120, "        Values are unchanged in the 2009 IAU repor"
	    "t.", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 243200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 243280, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 243360, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 243440, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 243520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 243600, "        BODY1000036_RADII     = (  8.0   4.0   4.0"
	    "  )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 243680, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 243760, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 243840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 243920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 244000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 244080, "9P/Tempel 1", (ftnlen)80, (ftnlen)11);
    s_copy(pck + 244160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 244240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 244320, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 244400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 244480, "        The effective radius is unchanged in the 2"
	    "009 IAU report.", (ftnlen)80, (ftnlen)65);
    s_copy(pck + 244560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 244640, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 244720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 244800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 244880, "        The value in the data assignment below is "
	    "the", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 244960, "        \"effective radius.\"", (ftnlen)80, (ftnlen)
	    27);
    s_copy(pck + 245040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 245120, "        According to [1]:", (ftnlen)80, (ftnlen)25);
    s_copy(pck + 245200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 245280, "           The maximum and minimum radii are not p"
	    "roperly", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 245360, "           the values of the principal semi-axes, "
	    "they", (ftnlen)80, (ftnlen)54);
    s_copy(pck + 245440, "           are half the maximum and minimum values"
	    " of the", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 245520, "           diameter. Due to the large deviations f"
	    "rom a", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 245600, "           simple ellipsoid, they may not correspo"
	    "nd with", (ftnlen)80, (ftnlen)57);
    s_copy(pck + 245680, "           measurements along the principal axes, "
	    "or be", (ftnlen)80, (ftnlen)55);
    s_copy(pck + 245760, "           orthogonal to each other.", (ftnlen)80, (
	    ftnlen)36);
    s_copy(pck + 245840, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 245920, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 246000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 246080, "        BODY1000093_RADII     = (  3.0   3.0   3.0"
	    "  )", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 246160, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 246240, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 246320, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 246400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 246480, "19P/Borrelly", (ftnlen)80, (ftnlen)12);
    s_copy(pck + 246560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 246640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 246720, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 246800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 246880, "        Values are unchanged in the 2009 report.", (
	    ftnlen)80, (ftnlen)48);
    s_copy(pck + 246960, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 247040, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 247120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 247200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 247280, "        The value in the data assignment below is "
	    "the", (ftnlen)80, (ftnlen)53);
    s_copy(pck + 247360, "        \"effective radius.\"", (ftnlen)80, (ftnlen)
	    27);
    s_copy(pck + 247440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 247520, "        The first principal axis length is", (
	    ftnlen)80, (ftnlen)42);
    s_copy(pck + 247600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 247680, "           3.5 km", (ftnlen)80, (ftnlen)17);
    s_copy(pck + 247760, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 247840, "        The lengths of the other semi-axes are not"
	    " provided", (ftnlen)80, (ftnlen)59);
    s_copy(pck + 247920, "        by [1].", (ftnlen)80, (ftnlen)15);
    s_copy(pck + 248000, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 248080, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 248160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 248240, "        BODY1000005_RADII     = (  4.22   4.22   4"
	    ".22  )", (ftnlen)80, (ftnlen)56);
    s_copy(pck + 248320, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 248400, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 248480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 248560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 248640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 248720, "81P/Wild 2", (ftnlen)80, (ftnlen)10);
    s_copy(pck + 248800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 248880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 248960, "     Old values:", (ftnlen)80, (ftnlen)16);
    s_copy(pck + 249040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 249120, "        Values are unchanged in the 2009 report.", (
	    ftnlen)80, (ftnlen)48);
    s_copy(pck + 249200, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 249280, "     Current values:", (ftnlen)80, (ftnlen)20);
    s_copy(pck + 249360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 249440, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 249520, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 249600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 249680, "        BODY1000107_RADII     = (  2.7   1.9   1.5"
	    " )", (ftnlen)80, (ftnlen)52);
    s_copy(pck + 249760, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 249840, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 249920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 250000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 250080, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 250160, "=================================================="
	    "=========================", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 250240, "End of file pck00010.tpc", (ftnlen)80, (ftnlen)24);
    s_copy(pck + 250320, "=================================================="
	    "=========================", (ftnlen)80, (ftnlen)75);
    s_copy(pck + 250400, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)10);
    s_copy(pck + 251200, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 251280, "BODY-10_CONSTANTS_REF_FRAME = 2", (ftnlen)80, (
	    ftnlen)31);
    s_copy(pck + 251360, "BODY-10_CONSTANTS_JED_EPOCH = 2433282.42345905D0", (
	    ftnlen)80, (ftnlen)48);
    s_copy(pck + 251440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(pck + 251520, "BODY-10_POLE_RA         = (  286.13       0.      "
	    "    0. )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 251600, "BODY-10_POLE_DEC        = (   63.87       0.      "
	    "    0. )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 251680, "BODY-10_PM              = (   84.176     14.18440 "
	    "    0. )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 251760, "BODY-10_LONG_AXIS       = (  459.00               "
	    "       )", (ftnlen)80, (ftnlen)58);
    s_copy(pck + 251840, " ", (ftnlen)80, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)10);
    s_copy(pck + 251920, ch__1, (ftnlen)80, (ftnlen)10);
    s_copy(pck + 252000, " ", (ftnlen)80, (ftnlen)1);

/*     Create the PCK kernel. */

    txtopn_(namepc, &unit, namepc_len);
    for (i__ = 1; i__ <= 3151; ++i__) {
	r__ = rtrim_(pck + ((i__1 = i__ - 1) < 3151 && 0 <= i__1 ? i__1 : 
		s_rnge("pck", i__1, "t_pck10__", (ftnlen)4532)) * 80, (ftnlen)
		80);
	writln_(pck + ((i__1 = i__ - 1) < 3151 && 0 <= i__1 ? i__1 : s_rnge(
		"pck", i__1, "t_pck10__", (ftnlen)4534)) * 80, &unit, r__);
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
} /* t_pck10__ */

