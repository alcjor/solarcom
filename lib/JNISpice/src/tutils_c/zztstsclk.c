/* zztstsclk.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__9 = 9;
static integer c__1 = 1;

/* $Procedure ZZTSTSCLK (Create an SCLK file) */
/* Subroutine */ int zztstsclk_(char *sclknm, ftnlen sclknm_len)
{
    /* System generated locals */
    integer i__1;
    char ch__1[16];
    cllist cl__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rnge(char *, integer, char *, integer), s_wsle(cilist *), 
	    do_lio(integer *, integer *, char *, ftnlen), e_wsle(void), 
	    f_clos(cllist *);

    /* Local variables */
    integer unit, i__, r__;
    extern integer rtrim_(char *, ftnlen);
    extern /* Character */ VOID begdat_(char *, ftnlen);
    char sclkbf[80*98];
    extern /* Subroutine */ int kilfil_(char *, ftnlen), txtopn_(char *, 
	    integer *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___5 = { 0, 0, 0, 0, 0 };


/* $ Abstract */

/*     Create an S-clock kernel file. */

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

/*      None. */

/* $ Keywords */

/*       TESTING */

/* $ Declarations */
/* $ Brief_I/O */

/*      VARIABLE  I/O  DESCRIPTION */
/*      --------  ---  -------------------------------------------------- */
/*      SCLKNM     I   The name of the S-clock kernel to create. */

/* $ Detailed_Input */

/*     SCLKNM      is the name of an S-clock Kernel to create. */
/*                 If an S-clock kernel of the same name exists, */
/*                 delete the existing kernel before creating */
/*                 this one. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*      None. */

/* $ Exceptions */

/*     None. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     An SCLK kernel is created. */

/* $ Examples */

/*     Suppose that you are testing some portion of the toolkit */
/*     that requires the use of an SCLK kernel.  This routine */
/*     allows you to create an SCLK kernel without having to */
/*     know where a current SCLK kernel is located on the */
/*     file system. */

/*        CALL ZZTSTSCLK( SCLKNM ) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*      None. */

/* $ Author_and_Institution */

/*      W.L. Taber      (JPL) */
/*      E.D. Wright     (JPL) */

/* $ Version */

/* -    Test Utilities 1.0.0, 19-APR-2006 (EDW) */

/*        Reimplementation of TSTCK3 removing all code */
/*        except that needed to write the test SCLK. */

/* -& */
/* $ Index_Entries */

/*     Create test SCLK files. */

/* -& */

/*     Spicelib Functions */


/*     Test Utility Functions */


/*     Local Variables. */


/*     The first order of business is to wipe out any existing */
/*     files with the same name. */

    kilfil_(sclknm, sclknm_len);

/*     Fill up the buffer SCLKBF with the text that will make up */
/*     our test SCLK file. */

    s_copy(sclkbf, "TEST SPICE SCLK Kernel ", (ftnlen)80, (ftnlen)23);
    s_copy(sclkbf + 80, "------------------------------------------- -------"
	    "------ ", (ftnlen)80, (ftnlen)58);
    s_copy(sclkbf + 160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 240, "This file contains the data necessary for converti"
	    "ng from ", (ftnlen)80, (ftnlen)58);
    s_copy(sclkbf + 320, "ET to ticks for the fictional spacecraft -9999.  I"
	    "t is produced ", (ftnlen)80, (ftnlen)64);
    s_copy(sclkbf + 400, "by the Test Utility routine ZZTSTSCLK. ", (ftnlen)
	    80, (ftnlen)39);
    s_copy(sclkbf + 480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 560, "This SCLK kernel is intended to be used with the t"
	    "est CK file ", (ftnlen)80, (ftnlen)62);
    s_copy(sclkbf + 640, "produced by that same routine.  The internal file "
	    "name of the ", (ftnlen)80, (ftnlen)62);
    s_copy(sclkbf + 720, "test C-Kernel is ZZ-TEST-CK-ZZ.  It contains a sin"
	    "gle type 03 ", (ftnlen)80, (ftnlen)62);
    s_copy(sclkbf + 800, "segment. ", (ftnlen)80, (ftnlen)9);
    s_copy(sclkbf + 880, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 960, "This fictional clock begins a 1 JAN 1980 00:00:00 "
	    "ET and continues ", (ftnlen)80, (ftnlen)67);
    s_copy(sclkbf + 1040, "for 1 billion seconds.  (i.e. until 2011 SEP 9, 0"
	    "1:46:40.000 ET ). ", (ftnlen)80, (ftnlen)67);
    s_copy(sclkbf + 1120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 1200, "This is intended for test purposes only and can b"
	    "e easily rebuilt ", (ftnlen)80, (ftnlen)66);
    s_copy(sclkbf + 1280, "by calling the routine ZZTSTSCLK. ", (ftnlen)80, (
	    ftnlen)34);
    s_copy(sclkbf + 1360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 1440, "If you have any questions about this file that th"
	    "ese comments don't ", (ftnlen)80, (ftnlen)68);
    s_copy(sclkbf + 1520, "answer, contact Bill Taber at NAIF. ", (ftnlen)80, 
	    (ftnlen)36);
    s_copy(sclkbf + 1600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 1680, "(818) 354-4279 ", (ftnlen)80, (ftnlen)15);
    s_copy(sclkbf + 1760, "btaber@spice.jpl.nasa.gov ", (ftnlen)80, (ftnlen)
	    26);
    s_copy(sclkbf + 1840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 1920, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 2000, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 2080, "Implementation notes ", (ftnlen)80, (ftnlen)21);
    s_copy(sclkbf + 2160, "-------------------------------------------------"
	    "------- ", (ftnlen)80, (ftnlen)57);
    s_copy(sclkbf + 2240, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 2320, "This SCLK file is constructed so that the valid S"
	    "CLK strings ", (ftnlen)80, (ftnlen)61);
    s_copy(sclkbf + 2400, "are simply the number of TDB seconds that have pa"
	    "ssed ", (ftnlen)80, (ftnlen)54);
    s_copy(sclkbf + 2480, "since the Ephemeris epoch 1 Jan 1980 00:00:00 ", (
	    ftnlen)80, (ftnlen)46);
    s_copy(sclkbf + 2560, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 2640, "So that 1/ 288929292.82017  simply represents the"
	    " epoch that occurs ", (ftnlen)80, (ftnlen)68);
    s_copy(sclkbf + 2720, "288929292.82017 TDB seconds past the ET epoch 1 J"
	    "an 1980. ", (ftnlen)80, (ftnlen)58);
    s_copy(sclkbf + 2800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 2880, "For all time, the clock runs at the same rate as "
	    "TDB. There is only ", (ftnlen)80, (ftnlen)68);
    s_copy(sclkbf + 2960, "one partition for this clock. ", (ftnlen)80, (
	    ftnlen)30);
    s_copy(sclkbf + 3040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 3120, "You must load this file into the kernel pool befo"
	    "re using any of the ", (ftnlen)80, (ftnlen)69);
    s_copy(sclkbf + 3200, "SPICELIB SCLK routines. The code fragment ", (
	    ftnlen)80, (ftnlen)42);
    s_copy(sclkbf + 3280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 3360, "CALL FURNSH ( < name of this file > ) ", (ftnlen)
	    80, (ftnlen)38);
    s_copy(sclkbf + 3440, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 3520, "performs this task. To convert between ET and UTC"
	    ", you will also need ", (ftnlen)80, (ftnlen)70);
    s_copy(sclkbf + 3600, "to load a leapseconds kernel. The additional call"
	    " to FURNSH, ", (ftnlen)80, (ftnlen)61);
    s_copy(sclkbf + 3680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 3760, "CALL FURNSH ( < name of your leapsecond file > ) ",
	     (ftnlen)80, (ftnlen)49);
    s_copy(sclkbf + 3840, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 3920, "will accomplish this. Note that you must supply t"
	    "he actual names of ", (ftnlen)80, (ftnlen)68);
    s_copy(sclkbf + 4000, "the files used on your system as arguments to FUR"
	    "NSH. Because the file ", (ftnlen)80, (ftnlen)71);
    s_copy(sclkbf + 4080, "names are system dependent, we do not list them h"
	    "ere. ", (ftnlen)80, (ftnlen)54);
    s_copy(sclkbf + 4160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 4240, "For more information, consult your SPICELIB requi"
	    "red reading files. ", (ftnlen)80, (ftnlen)68);
    s_copy(sclkbf + 4320, "The following areas are covered: ", (ftnlen)80, (
	    ftnlen)33);
    s_copy(sclkbf + 4400, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 4480, "SCLK system                     SCLK required rea"
	    "ding ", (ftnlen)80, (ftnlen)54);
    s_copy(sclkbf + 4560, "Time systems and conversion     TIME required rea"
	    "ding ", (ftnlen)80, (ftnlen)54);
    s_copy(sclkbf + 4640, "Kernel pool                     KERNEL required r"
	    "eading ", (ftnlen)80, (ftnlen)56);
    s_copy(sclkbf + 4720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 4800, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 4880, "Kernel data ", (ftnlen)80, (ftnlen)12);
    s_copy(sclkbf + 4960, "-------------------------------------------------"
	    "------- ", (ftnlen)80, (ftnlen)57);
    s_copy(sclkbf + 5040, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 5120, " ", (ftnlen)80, (ftnlen)1);
    begdat_(ch__1, (ftnlen)16);
    s_copy(sclkbf + 5200, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(sclkbf + 5280, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 5360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 5440, "SCLK_KERNEL_ID                = ( @28-OCT-1994   "
	    "     ) ", (ftnlen)80, (ftnlen)56);
    s_copy(sclkbf + 5520, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 5600, "SCLK_DATA_TYPE_9              = ( 1 ) ", (ftnlen)
	    80, (ftnlen)38);
    s_copy(sclkbf + 5680, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 5760, "SCLK01_TIME_SYSTEM_9          = ( 1 ) ", (ftnlen)
	    80, (ftnlen)38);
    s_copy(sclkbf + 5840, "SCLK01_N_FIELDS_9             = ( 2 ) ", (ftnlen)
	    80, (ftnlen)38);
    s_copy(sclkbf + 5920, "SCLK01_MODULI_9               = ( 1000000000     "
	    "10000 ) ", (ftnlen)80, (ftnlen)57);
    s_copy(sclkbf + 6000, "SCLK01_OFFSETS_9              = ( 0         0 ) ", 
	    (ftnlen)80, (ftnlen)48);
    s_copy(sclkbf + 6080, "SCLK01_OUTPUT_DELIM_9         = ( 1 ) ", (ftnlen)
	    80, (ftnlen)38);
    s_copy(sclkbf + 6160, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 6240, "SCLK_PARTITION_START_9        = ( 0.0000000000000"
	    "E+00 ) ", (ftnlen)80, (ftnlen)56);
    s_copy(sclkbf + 6320, "SCLK_PARTITION_END_9          = ( 1.00000000E+14 "
	    "     ) ", (ftnlen)80, (ftnlen)56);
    s_copy(sclkbf + 6400, "SCLK01_COEFFICIENTS_9         = ( 0.00000000E+00 ",
	     (ftnlen)80, (ftnlen)49);
    s_copy(sclkbf + 6480, "@01-JAN-1980-00:00:00.000 ", (ftnlen)80, (ftnlen)
	    26);
    s_copy(sclkbf + 6560, "1  ) ", (ftnlen)80, (ftnlen)5);
    s_copy(sclkbf + 6640, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 6720, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 6800, "DELTET/DELTA_T_A       =   32.184 ", (ftnlen)80, (
	    ftnlen)34);
    s_copy(sclkbf + 6880, "DELTET/K               =    1.657D-3 ", (ftnlen)80,
	     (ftnlen)37);
    s_copy(sclkbf + 6960, "DELTET/EB              =    1.671D-2 ", (ftnlen)80,
	     (ftnlen)37);
    s_copy(sclkbf + 7040, "DELTET/M               = (  6.239996D0 1.99096871"
	    "D-7 ) ", (ftnlen)80, (ftnlen)55);
    s_copy(sclkbf + 7120, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 7200, "CK_-9999_SCLK          =   -9 ", (ftnlen)80, (
	    ftnlen)30);
    s_copy(sclkbf + 7280, "CK_-9999_SPK           =   -9 ", (ftnlen)80, (
	    ftnlen)30);
    s_copy(sclkbf + 7360, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 7440, "CK_-10000_SCLK         =   -9 ", (ftnlen)80, (
	    ftnlen)30);
    s_copy(sclkbf + 7520, "CK_-10000_SPK          =   -9 ", (ftnlen)80, (
	    ftnlen)30);
    s_copy(sclkbf + 7600, " ", (ftnlen)80, (ftnlen)1);
    s_copy(sclkbf + 7680, "CK_-10001_SCLK         =   -9 ", (ftnlen)80, (
	    ftnlen)30);
    s_copy(sclkbf + 7760, "CK_-10001_SPK          =   -9 ", (ftnlen)80, (
	    ftnlen)30);

/*     Create the SCLK kernel. */

    txtopn_(sclknm, &unit, sclknm_len);
    for (i__ = 1; i__ <= 98; ++i__) {
	r__ = rtrim_(sclkbf + ((i__1 = i__ - 1) < 98 && 0 <= i__1 ? i__1 : 
		s_rnge("sclkbf", i__1, "zztstsclk_", (ftnlen)304)) * 80, (
		ftnlen)80);
	io___5.ciunit = unit;
	s_wsle(&io___5);
	do_lio(&c__9, &c__1, sclkbf + ((i__1 = i__ - 1) < 98 && 0 <= i__1 ? 
		i__1 : s_rnge("sclkbf", i__1, "zztstsclk_", (ftnlen)305)) * 
		80, r__);
	e_wsle();
    }
    cl__1.cerr = 0;
    cl__1.cunit = unit;
    cl__1.csta = 0;
    f_clos(&cl__1);
    return 0;
} /* zztstsclk_ */

