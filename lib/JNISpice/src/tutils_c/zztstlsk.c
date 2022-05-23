/* zztstlsk.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* $Procedure TSTLSK (Create a test LSK) */
/* Subroutine */ int zztstlsk_(char *namels, ftnlen namels_len)
{
    /* System generated locals */
    integer i__1;
    char ch__1[16];
    cllist cl__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rnge(char *, integer, char *, integer), f_clos(cllist *);

    /* Local variables */
    integer unit, i__, r__;
    char lskln[80];
    extern integer rtrim_(char *, ftnlen);
    extern /* Character */ VOID begdat_(char *, ftnlen);
    extern /* Subroutine */ int kilfil_(char *, ftnlen), writln_(char *, 
	    integer *, ftnlen), txtopn_(char *, integer *, ftnlen);
    char lsk[80*29];

/* $ Abstract */

/*    This test utility routine creates a leapsecond kernel */
/*    (valid as of July 1, 1997). */

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

/*       TESTING */

/* $ Declarations */
/* $ Brief_I/O */

/*     None. */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     Error free. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     A leapseconds kernel is created. */

/* $ Examples */

/*     Suppose that you are testing some portion of the toolkit */
/*     that requires the use of a leapseconds kernel.  This routine */
/*     allows you to create a leapseconds kernel without having to */
/*     know where a current leapsecond kernel is located on the */
/*     file system. */

/*        CALL ZZTSTLSK( NAMELS ) */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     W.L. Taber      (JPL) */
/*     E.D. Wright     (JPL) */

/* $ Version */

/* -    Test Utilities 1.0.0, 18-AUG-2008 (EDW) */

/*        Replaced WRITE with WRITLN. */

/* -    Test Utilities 1.0.0, 05-JAN-2006 (EDW) */

/*        Reimplementation of TSTLSK removing all code */
/*        except that needed to write the test LSK. */

/* -& */
/* $ Index_Entries */

/*     Generate a leapseconds kernel for testing. */

/* -& */

/*     Spicelib Functions */


/*     Test Utility Functions */


/*     Local Variables. */

    kilfil_(namels, namels_len);
    begdat_(ch__1, (ftnlen)16);
    s_copy(lsk, ch__1, (ftnlen)80, (ftnlen)16);
    s_copy(lsk + 80, " ", (ftnlen)80, (ftnlen)1);
    s_copy(lsk + 160, "DELTET/DELTA_T_A       =   32.184", (ftnlen)80, (
	    ftnlen)33);
    s_copy(lsk + 240, "DELTET/K               =    1.657D-3", (ftnlen)80, (
	    ftnlen)36);
    s_copy(lsk + 320, "DELTET/EB              =    1.671D-2", (ftnlen)80, (
	    ftnlen)36);
    s_copy(lsk + 400, "DELTET/M               = (  6.239996D0   1.99096871D-"
	    "7 )", (ftnlen)80, (ftnlen)56);
    s_copy(lsk + 480, " ", (ftnlen)80, (ftnlen)1);
    s_copy(lsk + 560, "DELTET/DELTA_AT        = ( 10,   @1972-JAN-1", (ftnlen)
	    80, (ftnlen)44);
    s_copy(lsk + 640, "                           11,   @1972-JUL-1", (ftnlen)
	    80, (ftnlen)44);
    s_copy(lsk + 720, "                           12,   @1973-JAN-1", (ftnlen)
	    80, (ftnlen)44);
    s_copy(lsk + 800, "                           13,   @1974-JAN-1", (ftnlen)
	    80, (ftnlen)44);
    s_copy(lsk + 880, "                           14,   @1975-JAN-1", (ftnlen)
	    80, (ftnlen)44);
    s_copy(lsk + 960, "                           15,   @1976-JAN-1", (ftnlen)
	    80, (ftnlen)44);
    s_copy(lsk + 1040, "                           16,   @1977-JAN-1", (
	    ftnlen)80, (ftnlen)44);
    s_copy(lsk + 1120, "                           17,   @1978-JAN-1", (
	    ftnlen)80, (ftnlen)44);
    s_copy(lsk + 1200, "                           18,   @1979-JAN-1", (
	    ftnlen)80, (ftnlen)44);
    s_copy(lsk + 1280, "                           19,   @1980-JAN-1", (
	    ftnlen)80, (ftnlen)44);
    s_copy(lsk + 1360, "                           20,   @1981-JUL-1", (
	    ftnlen)80, (ftnlen)44);
    s_copy(lsk + 1440, "                           21,   @1982-JUL-1", (
	    ftnlen)80, (ftnlen)44);
    s_copy(lsk + 1520, "                           22,   @1983-JUL-1", (
	    ftnlen)80, (ftnlen)44);
    s_copy(lsk + 1600, "                           23,   @1985-JUL-1", (
	    ftnlen)80, (ftnlen)44);
    s_copy(lsk + 1680, "                           24,   @1988-JAN-1", (
	    ftnlen)80, (ftnlen)44);
    s_copy(lsk + 1760, "                           25,   @1990-JAN-1", (
	    ftnlen)80, (ftnlen)44);
    s_copy(lsk + 1840, "                           26,   @1991-JAN-1", (
	    ftnlen)80, (ftnlen)44);
    s_copy(lsk + 1920, "                           27,   @1992-JUL-1", (
	    ftnlen)80, (ftnlen)44);
    s_copy(lsk + 2000, "                           28,   @1993-JUL-1", (
	    ftnlen)80, (ftnlen)44);
    s_copy(lsk + 2080, "                           29,   @1994-JUL-1", (
	    ftnlen)80, (ftnlen)44);
    s_copy(lsk + 2160, "                           30,   @1996-JAN-1", (
	    ftnlen)80, (ftnlen)44);
    s_copy(lsk + 2240, "                           31,   @1997-JUL-1 )", (
	    ftnlen)80, (ftnlen)46);

/*     Create the LSK kernel. */

    txtopn_(namels, &unit, namels_len);
    for (i__ = 1; i__ <= 29; ++i__) {
	s_copy(lskln, lsk + ((i__1 = i__ - 1) < 29 && 0 <= i__1 ? i__1 : 
		s_rnge("lsk", i__1, "zztstlsk_", (ftnlen)210)) * 80, (ftnlen)
		80, (ftnlen)80);
	r__ = rtrim_(lskln, (ftnlen)80);
	writln_(lskln, &unit, r__);
    }
    cl__1.cerr = 0;
    cl__1.cunit = unit;
    cl__1.csta = 0;
    f_clos(&cl__1);
    return 0;
} /* zztstlsk_ */

