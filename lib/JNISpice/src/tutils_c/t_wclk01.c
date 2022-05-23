/* t_wclk01.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__10 = 10;
static doublereal c_b76 = 1e14;
static integer c__2 = 2;
static doublereal c_b91 = 1e15;
static integer c__1 = 1;
static integer c__0 = 0;
static integer c__3 = 3;
static integer c__9999 = 9999;
static integer c__50000 = 50000;

/* $Procedure T_WCLK01 ( Write a type 1 SCLK kernel ) */
/* Subroutine */ int t_wclk01__(char *fname, char *coms, integer *clkid, char 
	*kerid, char *timsys, integer *nfield, doublereal *moduli, doublereal 
	*offset, char *delim, integer *nparts, doublereal *pstart, doublereal 
	*pstop, integer *ncoeff, doublereal *coeffs, ftnlen fname_len, ftnlen 
	coms_len, ftnlen kerid_len, ftnlen timsys_len, ftnlen delim_len)
{
    /* Initialized data */

    static char dlchrs[5] = ".:-, ";

    /* System generated locals */
    address a__1[3];
    integer moduli_dim1, offset_dim1, pstart_dim1, pstop_dim1, coeffs_dim2, 
	    i__1, i__2, i__3, i__4, i__5[3];
    doublereal d__1;
    char ch__1[80], ch__2[4];
    icilist ici__1;
    cllist cl__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_cmp(char *, char *, 
	    ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rnge(char *, integer, char *, integer), pow_ii(integer *, 
	    integer *);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    double d_nint(doublereal *);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , f_clos(cllist *);

    /* Local variables */
    doublereal sp2000;
    char line[80];
    integer unit, i__, j;
    extern integer cardc_(char *, ftnlen);
    integer l;
    extern /* Subroutine */ int chkin_(char *, ftnlen), errch_(char *, char *,
	     ftnlen, ftnlen), repmc_(char *, char *, char *, char *, ftnlen, 
	    ftnlen, ftnlen, ftnlen), dpfmt_(doublereal *, char *, char *, 
	    ftnlen, ftnlen), repmi_(char *, char *, integer *, char *, ftnlen,
	     ftnlen, ftnlen), errdp_(char *, doublereal *, ftnlen);
    doublereal prodm;
    integer strid, start;
    extern logical eqstr_(char *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int ljust_(char *, char *, ftnlen, ftnlen);
    extern logical failed_(void);
    extern /* Character */ VOID begdat_(char *, ftnlen);
    integer timcde;
    extern integer lastnb_(char *, ftnlen);
    char longln[200];
    extern /* Subroutine */ int sigerr_(char *, ftnlen);
    extern /* Character */ VOID begtxt_(char *, ftnlen);
    extern /* Subroutine */ int chkout_(char *, ftnlen);
    char errmsg[240];
    extern /* Subroutine */ int tparse_(char *, doublereal *, char *, ftnlen, 
	    ftnlen), setmsg_(char *, ftnlen);
    integer iostat;
    extern /* Subroutine */ int errint_(char *, integer *, ftnlen), suffix_(
	    char *, integer *, char *, ftnlen, ftnlen);
    extern logical exists_(char *, ftnlen), return_(void);
    extern /* Subroutine */ int writln_(char *, integer *, ftnlen);
    char numstr[80];
    extern /* Subroutine */ int txtopn_(char *, integer *, ftnlen);
    integer lnb;

/* $ Abstract */

/*     Write a type 1 SCLK kernel whose kernel variable assignments are */
/*     based on data passed in by the caller. */

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

/*     SCLK */

/* $ Keywords */

/*     SCLK */
/*     TEST */
/*     UTILITY */

/* $ Declarations */
/* $ Abstract */

/*     Include file sclk.inc */

/*     SPICE private file intended solely for the support of SPICE */
/*     routines.  Users should not include this file directly due */
/*     to the volatile nature of this file */

/*     The parameters below define sizes and limits used by */
/*     the SCLK system. */

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

/* $ Parameters */

/*     See the declaration section below. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 2.0.0, 24-MAY-2010 (NJB) */

/*        Increased value of maximum coefficient record count */
/*        parameter MXCOEF from 10K to 50K. */

/* -    SPICELIB Version 1.0.0, 11-FEB-2008 (NJB) */

/* -& */

/*     Number of supported SCLK field delimiters: */


/*     Supported SCLK string field delimiters: */


/*     Maximum number of partitions: */


/*     Partition string length. */

/*     Since the maximum number of partitions is given by MXPART is */
/*     9999, PRTSTR needs at most 4 characters for the partition number */
/*     and one character for the slash. */


/*     Maximum number of coefficient records: */


/*     Maximum number of fields in an SCLK string: */


/*     Length of strings used to represent D.P. */
/*     numbers: */


/*     Maximum number of supported parallel time systems: */


/*     End of include file sclk.inc */

/* $ Brief_I/O */

/*     VARIABLE  I/O  DESCRIPTION */
/*     --------  ---  -------------------------------------------------- */
/*     FNAME      I   SCLK kernel name. */
/*     COMS       I   Kernel comment block. */
/*     CLKID      I   SCLK ID code. */
/*     KERID      I   Kernel ID: date in text kernel format. */
/*     TIMSYS     I   Time system name. */
/*     NFIELD     I   Number of fields in SCLK string format. */
/*     MODULI     I   Moduli of SCLK string format. */
/*     OFFSET     I   Offsets of SCLK string format. */
/*     DELIM      I   SCLK string output delimiter. */
/*     NPARTS     I   Number of partitions. */
/*     PSTART     I   Partition start times. */
/*     PSTOP      I   Partition stop times. */
/*     NCOEFF     I   Number of SCLK coefficient records. */
/*     COEFFS     I   SCLK coefficient records. */

/* $ Detailed_Input */

/*     FNAME      is the name of the output SCLK kernel to create. */
/*                This kernel must not already exist. */

/*     COMS       is a SPICELIB character cell containing a block */
/*                of comments to be inserted in the SCLK kernel */
/*                after the ID word and before the first "begindata" */
/*                marker. */

/*     CLKID      is the integer ID code of the clock with which */
/*                the output kernel is associated. This ID normally */
/*                is the same as the integer ID of the spacecraft */
/*                on which the clock is mounted. */

/*     KERID      is the SCLK Kernel ID string. This is a */
/*                date in text kernel format: The date starts */
/*                with the character '@' and contains no embedded */
/*                blanks. Example: */

/*                   @01-JAN-2000/12:00:00 */

/*     TIMSYS     is the name of the parallel time system referenced */
/*                by the clock correlation coefficients. Supported */
/*                values are */

/*                   'TDB' */
/*                   'TDT' */

/*                case and blanks are not significant in TIMSYS. */

/*     NFIELD     is the number of fields in SCLK string format. */

/*     MODULI     is an array containing the moduli of SCLK string */
/*                format. The order of the moduli in the array */
/*                corresponds to left-to-right order in the SCLK string */
/*                format. */

/*     OFFSET     is an array containing the offsets of SCLK string */
/*                format. The order of the offsets in the array */
/*                corresponds to left-to-right order in the SCLK string */
/*                format. */

/*     DELIM      is the SCLK string output delimiter. This delimiter */
/*                is used by the SCLK system to create SCLK strings. */
/*                The delimiter must belong to the set contained in */
/*                the parameter DELIMS declared in the INCLUDE file */
/*                sclk.inc. */

/*     NPARTS     is the number of partitions for the SCLK data set. */
/*                NPARTS is used to define the dimensions of the */
/*                input arrays PSTART and PSTOP. */

/*     PSTART     is an array of partition start times. PSTART has */
/*                dimension NPARTS. */

/*     PSTOP      is an array of partition stop times.  PSTOP has */
/*                dimension NPARTS. */

/*     NCOEFF     is the number of SCLK coefficient records in the */
/*                array COEFFS. */

/*     COEFFS     is a 3 x NCOEFF array of SCLK coefficient records. */
/*                The elements having indices */

/*                   (1,I), (2,I), (3,I) */

/*                are, respectively, the Ith tick coefficient, the Ith */
/*                parallel time system coefficient, and the Ith clock */
/*                rate coefficient. */

/* $ Detailed_Output */

/*     None. See the section Files below. */

/* $ Parameters */

/*     See the INCLUDE file sclk.inc. */

/* $ Exceptions */

/*     1)  If the file designated by FNAME exists, the error */
/*         SPICE(FILEEXISTS) is signaled. */

/*     2)  If the SCLK kernel ID string does not contain */
/*         a date in SPICE text kernel format, the error */
/*         SPICE(INVALIDIDSTRING) is signaled. */

/*     3)  If the input time system name is not equivalent */
/*         to (ignoring case and blanks) a supported value, */
/*         the error SPICE(INVALIDTIMESYSTEM) is signaled. */

/*     4)  If the SCLK string field count is out of range, */
/*         the error SPICE(INVALIDFIELDCOUNT) is signaled. */

/*     5)  If any SCLK field modulus is out of range, */
/*         the error SPICE(INVALIDMODULUS) is signaled. */

/*     6)  If the product of the SCLK field moduli is out of range, */
/*         the error SPICE(INVALIDMODULI) is signaled. */

/*     7)  If any SCLK field offset is out of range, */
/*         the error SPICE(INVALIDOFFSET) is signaled. */

/*     8)  If the output SCLK string field delimiter is not */
/*         a supported value, the error SPICE(INVALIDDELIMITER) */
/*         is signaled. */

/*     9)  If the partition count is out of range, */
/*         the error SPICE(BADPARTITIONCOUNT) is signaled. */

/*     10) If any partition start time is out of range, */
/*         the error SPICE(BADPARTITIONSTART) is signaled. */

/*     11) If any partition start time is non-integral, */
/*         the error SPICE(BADPARTITIONSTART) is signaled. */

/*     12) If any partition start time cannot be converted to a */
/*         string via a Fortran WRITE, the error */
/*         SPICE(WRITEERROR) is signaled. */

/*     13) If any partition stop time is out of range, */
/*         the error SPICE(BADPARTITIONSTOP) is signaled. */

/*     14) If any partition stop time is non-integral, */
/*         the error SPICE(BADPARTITIONSTOP) is signaled. */

/*     15) If any partition stop time cannot be converted to a */
/*         string via a Fortran WRITE, the error */
/*         SPICE(WRITEERROR) is signaled. */

/*     16) If the SCLK coefficient record count is out of range, */
/*         the error SPICE(BADRECORDCOUNT) is signaled. */

/*     17) If the first tick coefficient is negative, the */
/*         error SPICE(NEGATIVETICK) is signaled. */

/*     18) If the tick coefficients are not in strictly increasing */
/*         order, the error SPICE(TICKSOUTOFORDER) is signaled. */

/*     19) If the parallel time system coefficients are not in strictly */
/*         increasing order, the error SPICE(TIMESOUTOFORDER) is */
/*         signaled. */

/*     20) If any SCLK rate value is non-positive, the error */
/*         SPICE(NONPOSITIVERATE) is signaled. */

/*     21) If 3-element coefficient record cannot be converted to a */
/*         string via a Fortran WRITE, the error */
/*         SPICE(WRITEERROR) is signaled. */

/* $ Files */

/*     The output of this routine is the SCLK kernel named */
/*     FNAME having contents provided by the input arguments */
/*     to this routine. */

/*     No leapseconds kernel need be loaded in order to use this */
/*     routine. */

/* $ Particulars */

/*     This routine is intended to support creation of SCLK kernels */
/*     for testing. The routine could be used as a component of */
/*     a general purpose SCLK kernel writing routine. */

/* $ Examples */

/*     1) The following program creates the SCLK kernel shown */
/*        at the bottom of this header section: */


/*        PROGRAM TWRT */
/*        IMPLICIT NONE */
/*  C */
/*  C     SPICELIB Functions */
/*  C */
/*        LOGICAL               EXISTS */
/*  C */
/*  C     Local parameters */
/*  C */
/*        CHARACTER*(*)         FNAME */
/*        PARAMETER           ( FNAME  = 'wrt.tsc' ) */

/*        INTEGER               LBCELL */
/*        PARAMETER           ( LBCELL = -5 ) */

/*        INTEGER               NCOM */
/*        PARAMETER           ( NCOM   = 3 ) */

/*        CHARACTER*(*)         DELIM */
/*        PARAMETER           ( DELIM  = ':' ) */

/*        INTEGER               NFIELD */
/*        PARAMETER           ( NFIELD = 4 ) */

/*        INTEGER               NPARTS */
/*        PARAMETER           ( NPARTS = 3 ) */

/*        INTEGER               NCOEFF */
/*        PARAMETER           ( NCOEFF = 10 ) */

/*        INTEGER               LNSIZE */
/*        PARAMETER           ( LNSIZE = 80 ) */

/*  C */
/*  C     Local variables */
/*  C */
/*        CHARACTER*(LNSIZE)    COMS ( LBCELL : NCOM ) */
/*        CHARACTER*(LNSIZE)    LINE */

/*        DOUBLE PRECISION      COEFFS ( 3, NCOEFF ) */
/*        DOUBLE PRECISION      DELTA */
/*        DOUBLE PRECISION      MODULI ( NFIELD ) */
/*        DOUBLE PRECISION      OFFSET ( NFIELD ) */
/*        DOUBLE PRECISION      PSTART ( NPARTS ) */
/*        DOUBLE PRECISION      PSTOP  ( NPARTS ) */

/*        INTEGER               I */


/*        IF ( EXISTS(FNAME) ) THEN */
/*           CALL DELFIL ( FNAME ) */
/*        END IF */

/*        CALL SSIZEC ( NCOM, COMS ) */

/*        DO I = 1, NCOM */

/*           LINE = '>>>>>>>> Comment line # <<<<<<<<<<<<' */
/*           CALL REPMI ( LINE, '#', I, LINE ) */

/*           CALL APPNDC ( LINE, COMS ) */

/*        END DO */

/*        MODULI(1) = 1000000 */
/*        MODULI(2) =      10 */
/*        MODULI(3) =       9 */
/*        MODULI(4) =       8 */

/*        OFFSET(1) =       1 */
/*        OFFSET(2) =       2 */
/*        OFFSET(3) =       3 */
/*        OFFSET(4) =       4 */

/*        DO I = 1, NPARTS */
/*           PSTART(I) = I */
/*           PSTOP (I) = 720000 + I */
/*        END DO */

/*        DELTA = 1.D-9 */

/*        DO I = 1, NCOEFF */

/*           COEFFS(1,I) = (I-1) * 180000.D0 */

/*           COEFFS(2,I) = (I-1) *  90000.D0 */

/*           COEFFS(3,I) = 2.D0  +  I*DELTA */

/*        END DO */

/*        CALL T_WCLK01 ( FNAME, */
/*       .                COMS, */
/*       .                -99, */
/*       .                '@01-JAN-2000/12:00:00', */
/*       .                'TDB', */
/*       .                NFIELD, */
/*       .                MODULI, */
/*       .                OFFSET, */
/*       .                DELIM, */
/*       .                NPARTS, */
/*       .                PSTART, */
/*       .                PSTOP, */
/*       .                NCOEFF, */
/*       .                COEFFS       ) */

/*        END */


/*     The SCLK kernel shown below has been modified slightly */
/*     to fit within the 72-column limit imposed by standard */
/*     Fortran 77 format restrictions: the SCLK coefficients */
/*     assignments have been shifted left. */


/*     KPL/SCLK */

/*     >>>>>>>> Comment line 1 <<<<<<<<<<<< */
/*     >>>>>>>> Comment line 2 <<<<<<<<<<<< */
/*     >>>>>>>> Comment line 3 <<<<<<<<<<<< */

/*     \begindata */

/*        SCLK_KERNEL_ID                  = ( @01-JAN-2000/12:00:00 ) */

/*        SCLK_DATA_TYPE_99               = ( 1 ) */

/*        SCLK01_TIME_SYSTEM_99           = ( 1 ) */
/*        SCLK01_N_FIELDS_99              = ( 4 ) */
/*        SCLK01_MODULI_99                = ( 1000000 10 9 8 ) */
/*        SCLK01_OFFSETS_99               = ( 4 3 2 1 ) */
/*        SCLK01_OUTPUT_DELIM_99          = ( 2 ) */

/*        SCLK_PARTITION_START_99         = ( 1.0, */
/*                                            2.0, */
/*                                            3.0 ) */

/*        SCLK_PARTITION_END_99           = ( 720001.0, */
/*                                            720002.0, */
/*                                            720003.0 ) */

/*        SCLK01_COEFFICIENTS_99          = ( */

/*                0.0    0.0000000000000000E+00    0.2000000001000000E+01 */
/*           180000.0    0.9000000000000000E+05    0.2000000002000000E+01 */
/*           360000.0    0.1800000000000000E+06    0.2000000003000000E+01 */
/*           540000.0    0.2700000000000000E+06    0.2000000004000000E+01 */
/*           720000.0    0.3600000000000000E+06    0.2000000005000000E+01 */
/*           900000.0    0.4500000000000000E+06    0.2000000006000000E+01 */
/*          1080000.0    0.5400000000000000E+06    0.2000000007000000E+01 */
/*          1260000.0    0.6300000000000000E+06    0.2000000008000000E+01 */
/*          1440000.0    0.7200000000000000E+06    0.2000000009000000E+01 */
/*          1620000.0    0.8100000000000000E+06    0.2000000010000000E+01 */
/*        ) */

/*     \begintext */



/* $ Restrictions */

/*     1) This routine supports only type 1 spacecraft clocks. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman     (JPL) */

/* $ Version */

/* -    TSPICE Version 1.1.0, 31-JAN-2014 (BVS) */

/*        BUG FIX: changed (MODULI(I) .LT. 2) to (MODULI(I) .LT. 1.D0) */
/*        as comparison of a DP must be done to a DP value and the */
/*        smallest allowed moduli value is 1. */

/* -    TSPICE Version 1.0.0, 21-FEB-2008 (NJB) */


/* -& */

/*     SPICELIB functions */


/*     Test utility functions */


/*     Local Parameters */


/*     Local Variables */


/*     We use a longer, non-standard length for ABCORR because we */
/*     want to include embedded blanks for testing. */


/*     Saved variables */


/*     Initial values */

    /* Parameter adjustments */
    offset_dim1 = *nfield;
    moduli_dim1 = *nfield;
    pstop_dim1 = *nparts;
    pstart_dim1 = *nparts;
    coeffs_dim2 = *ncoeff;

    /* Function Body */
    if (return_()) {
	return 0;
    }
    chkin_("T_WCLK01", (ftnlen)8);

/*     The clock ID to use in strings is the negative of */
/*     the input ID. */

    strid = -(*clkid);

/*     Don't overwrite an existing file. */

    if (exists_(fname, fname_len)) {
	setmsg_("File # already exists.", (ftnlen)22);
	errch_("#", fname, (ftnlen)1, fname_len);
	sigerr_("SPICE(FILEEXISTS)", (ftnlen)17);
	chkout_("T_WCLK01", (ftnlen)8);
	return 0;
    }

/*     Open the SCLK kernel as a new text file. */

    txtopn_(fname, &unit, fname_len);
    if (failed_()) {
	chkout_("T_WCLK01", (ftnlen)8);
	return 0;
    }

/*     Write the SCLK ID word. */

    writln_(" ", &unit, (ftnlen)1);
    writln_("KPL/SCLK", &unit, (ftnlen)8);
    writln_(" ", &unit, (ftnlen)1);

/*     Write any initial comments that may have been */
/*     supplied. */

    i__1 = cardc_(coms, coms_len);
    for (i__ = 1; i__ <= i__1; ++i__) {
	writln_(coms + (i__ + 5) * coms_len, &unit, coms_len);
    }

/*     Write the "begindata" marker. */

    writln_(" ", &unit, (ftnlen)1);
    begdat_(ch__1, (ftnlen)80);
    writln_(ch__1, &unit, (ftnlen)80);
    writln_(" ", &unit, (ftnlen)1);

/*     Write the kernel ID. The kernel ID must be a date */
/*     of the form */

/*        @<date> */

/*     where <date contains no embedded blanks. */

    ljust_(kerid, line, kerid_len, (ftnlen)80);
    l = lastnb_(line, (ftnlen)80);
    if (l == 0) {
	setmsg_("Kernel ID written to file # must be non-blank.", (ftnlen)46);
	errch_("#", fname, (ftnlen)1, fname_len);
	sigerr_("SPICE(INVALIDIDSTRING)", (ftnlen)22);
	chkout_("T_WCLK01", (ftnlen)8);
	return 0;
    }
    if (i_indx(line, " ", l, (ftnlen)1) != 0) {
	setmsg_("Kernel ID <#> written to file # must contain no embedded bl"
		"anks", (ftnlen)63);
	errch_("#", kerid, (ftnlen)1, kerid_len);
	errch_("#", fname, (ftnlen)1, fname_len);
	sigerr_("SPICE(INVALIDIDSTRING)", (ftnlen)22);
	chkout_("T_WCLK01", (ftnlen)8);
	return 0;
    }
    if (*(unsigned char *)line != '@') {
	setmsg_("Kernel ID <#> written to file # must be of the form @<date>"
		" where date contains no embedded blanks.", (ftnlen)99);
	errch_("#", kerid, (ftnlen)1, kerid_len);
	errch_("#", fname, (ftnlen)1, fname_len);
	sigerr_("SPICE(INVALIDIDSTRING)", (ftnlen)22);
	chkout_("T_WCLK01", (ftnlen)8);
	return 0;
    }
    if (l < 9) {
	setmsg_("Kernel ID <#> written to file # must be of the form @<date>"
		" where date contains no embedded blanks.", (ftnlen)99);
	errch_("#", kerid, (ftnlen)1, kerid_len);
	errch_("#", fname, (ftnlen)1, fname_len);
	sigerr_("SPICE(INVALIDIDSTRING)", (ftnlen)22);
	chkout_("T_WCLK01", (ftnlen)8);
	return 0;
    }
    tparse_(line + 1, &sp2000, errmsg, l - 1, (ftnlen)240);
    if (s_cmp(errmsg, " ", (ftnlen)240, (ftnlen)1) != 0) {
	setmsg_("Kernel ID <#> written to file # must be of the form @<date>"
		" where date contains no embedded blanks. TPARSE returned mes"
		"sage < # > ", (ftnlen)130);
	errch_("#", kerid, (ftnlen)1, kerid_len);
	errch_("#", fname, (ftnlen)1, fname_len);
	errch_("#", errmsg, (ftnlen)1, (ftnlen)240);
	sigerr_("SPICE(INVALIDIDSTRING)", (ftnlen)22);
	chkout_("T_WCLK01", (ftnlen)8);
	return 0;
    }
    s_copy(line, "   SCLK_KERNEL_ID                  = ( # )", (ftnlen)80, (
	    ftnlen)42);
    repmc_(line, "#", kerid, line, (ftnlen)80, (ftnlen)1, kerid_len, (ftnlen)
	    80);
    writln_(line, &unit, (ftnlen)80);
    writln_(" ", &unit, (ftnlen)1);

/*     Write the SCLK data type: for this routine, the value */
/*     is always 1. */

    s_copy(line, "   SCLK_DATA_TYPE_#              = ( 1 )", (ftnlen)80, (
	    ftnlen)40);
    repmi_(line, "#", &strid, line, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    writln_(line, &unit, (ftnlen)80);
    writln_(" ", &unit, (ftnlen)1);

/*     Write the time system code. */

    if (eqstr_(timsys, "TDB", timsys_len, (ftnlen)3)) {
	timcde = 1;
    } else if (eqstr_(timsys, "TDT", timsys_len, (ftnlen)3)) {
	timcde = 2;
    } else {
	setmsg_("SCLK time system for file # must be TDB or TDT but was #.", (
		ftnlen)57);
	errch_("#", fname, (ftnlen)1, fname_len);
	errch_("#", timsys, (ftnlen)1, timsys_len);
	sigerr_("SPICE(INVALIDTIMESYSTEM)", (ftnlen)24);
	chkout_("T_WCLK01", (ftnlen)8);
	return 0;
    }
    s_copy(line, "   SCLK_DATA_TYPE_#              = ( 1 )", (ftnlen)80, (
	    ftnlen)40);
    s_copy(line, "   SCLK01_TIME_SYSTEM_#          = ( # )", (ftnlen)80, (
	    ftnlen)40);
    repmi_(line, "#", &strid, line, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    repmi_(line, "#", &timcde, line, (ftnlen)80, (ftnlen)1, (ftnlen)80);

/*     No blank line follows this output because the clock */
/*     attribute parameters are written as a contiguous */
/*     block. Why?  ...tradition. */

    writln_(line, &unit, (ftnlen)80);

/*     Write the number of fields. */

    if (*nfield < 1 || *nfield > 10) {
	setmsg_("SCLK field count for file # must be in range 1:# but was #.",
		 (ftnlen)59);
	errch_("#", fname, (ftnlen)1, fname_len);
	errint_("#", &c__10, (ftnlen)1);
	errint_("#", nfield, (ftnlen)1);
	sigerr_("SPICE(INVALIDFIELDCOUNT)", (ftnlen)24);
	chkout_("T_WCLK01", (ftnlen)8);
	return 0;
    }
    s_copy(line, "   SCLK01_N_FIELDS_#             = ( # )", (ftnlen)80, (
	    ftnlen)40);
    repmi_(line, "#", &strid, line, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    repmi_(line, "#", nfield, line, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    writln_(line, &unit, (ftnlen)80);

/*     Write the moduli. Recall these are d.p. numbers. */

    i__1 = *nfield;
    for (i__ = 1; i__ <= i__1; ++i__) {

/*        All moduli must be in the range 1 : 1e14. */

	if (moduli[(i__2 = i__ - 1) < moduli_dim1 && 0 <= i__2 ? i__2 : 
		s_rnge("moduli", i__2, "t_wclk01__", (ftnlen)732)] < 1. || 
		moduli[(i__3 = i__ - 1) < moduli_dim1 && 0 <= i__3 ? i__3 : 
		s_rnge("moduli", i__3, "t_wclk01__", (ftnlen)732)] > 1e14) {
	    setmsg_("SCLK modulus # for file # must be in range 1 : # but wa"
		    "s #.", (ftnlen)59);
	    errint_("#", &i__, (ftnlen)1);
	    errch_("#", fname, (ftnlen)1, fname_len);
	    errdp_("#", &c_b76, (ftnlen)1);
	    errdp_("#", &moduli[(i__2 = i__ - 1) < moduli_dim1 && 0 <= i__2 ? 
		    i__2 : s_rnge("moduli", i__2, "t_wclk01__", (ftnlen)740)],
		     (ftnlen)1);
	    sigerr_("SPICE(INVALIDMODULUS)", (ftnlen)21);
	    chkout_("T_WCLK01", (ftnlen)8);
	    return 0;
	}
    }

/*     Make sure the product of the moduli can fit in the d.p. mantissa */
/*     without truncation. */

    prodm = moduli[(i__1 = 0) < moduli_dim1 ? i__1 : s_rnge("moduli", i__1, 
	    "t_wclk01__", (ftnlen)753)];
    i__1 = *nfield;
    for (i__ = 2; i__ <= i__1; ++i__) {
	prodm *= moduli[(i__2 = i__ - 1) < moduli_dim1 && 0 <= i__2 ? i__2 : 
		s_rnge("moduli", i__2, "t_wclk01__", (ftnlen)756)];
    }
    if (prodm > 1e15) {
	setmsg_("SCLK modulus product for file # must be in range # : # but "
		"was #. (Lower bound is 2**NFIELD.)", (ftnlen)93);
	errch_("#", fname, (ftnlen)1, fname_len);
	i__1 = pow_ii(&c__2, nfield);
	errint_("#", &i__1, (ftnlen)1);
	errdp_("#", &c_b91, (ftnlen)1);
	errdp_("#", &prodm, (ftnlen)1);
	sigerr_("SPICE(INVALIDMODULI)", (ftnlen)20);
	chkout_("T_WCLK01", (ftnlen)8);
	return 0;
    }

/*     If we have 4 or fewer fields, write the moduli out */
/*     on one line on the right hand side. Otherwise */
/*     stack up the values on multiple lines. */

/*     Build the line in a long string; check the length */
/*     before writing the line. */

    s_copy(longln, "   SCLK01_MODULI_#               = ( #", (ftnlen)200, (
	    ftnlen)38);
    repmi_(longln, "#", &strid, longln, (ftnlen)200, (ftnlen)1, (ftnlen)200);
    if (*nfield <= 4) {
	i__1 = *nfield - 1;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    repmc_(longln, "#", "# #", longln, (ftnlen)200, (ftnlen)1, (
		    ftnlen)3, (ftnlen)200);
	    dpfmt_(&moduli[(i__2 = i__ - 1) < moduli_dim1 && 0 <= i__2 ? i__2 
		    : s_rnge("moduli", i__2, "t_wclk01__", (ftnlen)792)], 
		    "XXXXXXXXXXXXXX", numstr, (ftnlen)14, (ftnlen)80);
	    ljust_(numstr, numstr, (ftnlen)80, (ftnlen)80);
	    repmc_(longln, "#", numstr, longln, (ftnlen)200, (ftnlen)1, (
		    ftnlen)80, (ftnlen)200);
	}
	dpfmt_(&moduli[(i__1 = *nfield - 1) < moduli_dim1 && 0 <= i__1 ? i__1 
		: s_rnge("moduli", i__1, "t_wclk01__", (ftnlen)798)], "XXXXX"
		"XXXXXXXXX", numstr, (ftnlen)14, (ftnlen)80);
	ljust_(numstr, numstr, (ftnlen)80, (ftnlen)80);
	repmc_(longln, "#", numstr, longln, (ftnlen)200, (ftnlen)1, (ftnlen)
		80, (ftnlen)200);
	suffix_(")", &c__1, longln, (ftnlen)1, (ftnlen)200);
	lnb = lastnb_(longln, (ftnlen)200);
	if (lnb <= 80) {
	    writln_(longln, &unit, (ftnlen)200);
	}
    }

/*     The following case is for moduli assignments that */
/*     span multiple lines. */

    if (*nfield > 4 || lnb > 80) {

/*        Save the start position for the moduli. */

	start = lastnb_(longln, (ftnlen)200);


/*        Fill in the first line and write it. */

	dpfmt_(&moduli[(i__1 = 0) < moduli_dim1 ? i__1 : s_rnge("moduli", 
		i__1, "t_wclk01__", (ftnlen)827)], "XXXXXXXXXXXXXX", numstr, (
		ftnlen)14, (ftnlen)80);
	ljust_(numstr, numstr, (ftnlen)80, (ftnlen)80);
	repmc_(longln, "#", numstr, longln, (ftnlen)200, (ftnlen)1, (ftnlen)
		80, (ftnlen)200);

/*        Append a comma to the line. */

	suffix_(",", &c__0, longln, (ftnlen)1, (ftnlen)200);
	writln_(longln, &unit, (ftnlen)200);

/*        Fill in the lines preceding the last line and */
/*        write these as well. */

	i__1 = *nfield - 1;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    s_copy(longln, " ", (ftnlen)200, (ftnlen)1);
	    s_copy(longln + (start - 1), "#,", 200 - (start - 1), (ftnlen)2);
	    dpfmt_(&moduli[(i__2 = i__ - 1) < moduli_dim1 && 0 <= i__2 ? i__2 
		    : s_rnge("moduli", i__2, "t_wclk01__", (ftnlen)847)], 
		    "XXXXXXXXXXXXXX", numstr, (ftnlen)14, (ftnlen)80);
	    ljust_(numstr, numstr, (ftnlen)80, (ftnlen)80);
	    repmc_(longln, "#", numstr, longln, (ftnlen)200, (ftnlen)1, (
		    ftnlen)80, (ftnlen)200);
	    writln_(longln, &unit, (ftnlen)200);
	}

/*        Fill in and write the last line. */

	s_copy(longln, " ", (ftnlen)200, (ftnlen)1);
	s_copy(longln + (start - 1), "# )", 200 - (start - 1), (ftnlen)3);
	dpfmt_(&moduli[(i__1 = *nfield - 1) < moduli_dim1 && 0 <= i__1 ? i__1 
		: s_rnge("moduli", i__1, "t_wclk01__", (ftnlen)861)], "XXXXX"
		"XXXXXXXXX", numstr, (ftnlen)14, (ftnlen)80);
	ljust_(numstr, numstr, (ftnlen)80, (ftnlen)80);
	repmc_(longln, "#", numstr, longln, (ftnlen)200, (ftnlen)1, (ftnlen)
		80, (ftnlen)200);
	writln_(longln, &unit, (ftnlen)200);
    }

/*     Write the offsets. Recall these are d.p. numbers. */
/*     The method is the same as for the moduli, except for */
/*     the range check. */

    i__1 = *nfield;
    for (i__ = 1; i__ <= i__1; ++i__) {

/*        All offsets must be in the range 0 : moduli(i)-1. */

	if (offset[(i__2 = i__ - 1) < offset_dim1 && 0 <= i__2 ? i__2 : 
		s_rnge("offset", i__2, "t_wclk01__", (ftnlen)879)] < 0. || 
		offset[(i__3 = i__ - 1) < offset_dim1 && 0 <= i__3 ? i__3 : 
		s_rnge("offset", i__3, "t_wclk01__", (ftnlen)879)] > moduli[(
		i__4 = 0) < moduli_dim1 ? i__4 : s_rnge("moduli", i__4, "t_w"
		"clk01__", (ftnlen)879)] - 1) {
	    setmsg_("SCLK offset # for file # must be in range 0 : # but was"
		    " #.", (ftnlen)58);
	    errint_("#", &i__, (ftnlen)1);
	    errch_("#", fname, (ftnlen)1, fname_len);
	    d__1 = moduli[(i__2 = i__ - 1) < moduli_dim1 && 0 <= i__2 ? i__2 :
		     s_rnge("moduli", i__2, "t_wclk01__", (ftnlen)886)] - 1;
	    errdp_("#", &d__1, (ftnlen)1);
	    errdp_("#", &offset[(i__2 = i__ - 1) < offset_dim1 && 0 <= i__2 ? 
		    i__2 : s_rnge("offset", i__2, "t_wclk01__", (ftnlen)887)],
		     (ftnlen)1);
	    sigerr_("SPICE(INVALIDOFFSET)", (ftnlen)20);
	    chkout_("T_WCLK01", (ftnlen)8);
	    return 0;
	}
    }

/*     If we have 4 or fewer fields, write the offsets out */
/*     on one line on the right hand side. Otherwise */
/*     stack up the values on multiple lines. */

/*     Build the line in a long string; check the length */
/*     before writing the line. */

    s_copy(longln, "   SCLK01_OFFSETS_#              = ( #", (ftnlen)200, (
	    ftnlen)38);
    repmi_(longln, "#", &strid, longln, (ftnlen)200, (ftnlen)1, (ftnlen)200);
    if (*nfield <= 4) {
	i__1 = *nfield - 1;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    repmc_(longln, "#", "# #", longln, (ftnlen)200, (ftnlen)1, (
		    ftnlen)3, (ftnlen)200);
	    dpfmt_(&offset[(i__2 = i__ - 1) < offset_dim1 && 0 <= i__2 ? i__2 
		    : s_rnge("offset", i__2, "t_wclk01__", (ftnlen)913)], 
		    "XXXXXXXXXXXXXX", numstr, (ftnlen)14, (ftnlen)80);
	    ljust_(numstr, numstr, (ftnlen)80, (ftnlen)80);
	    repmc_(longln, "#", numstr, longln, (ftnlen)200, (ftnlen)1, (
		    ftnlen)80, (ftnlen)200);
	}
	dpfmt_(&offset[(i__1 = *nfield - 1) < offset_dim1 && 0 <= i__1 ? i__1 
		: s_rnge("offset", i__1, "t_wclk01__", (ftnlen)919)], "XXXXX"
		"XXXXXXXXX", numstr, (ftnlen)14, (ftnlen)80);
	ljust_(numstr, numstr, (ftnlen)80, (ftnlen)80);
	repmc_(longln, "#", numstr, longln, (ftnlen)200, (ftnlen)1, (ftnlen)
		80, (ftnlen)200);
	suffix_(")", &c__1, longln, (ftnlen)1, (ftnlen)200);
	lnb = lastnb_(longln, (ftnlen)200);
	if (lnb <= 80) {
	    writln_(longln, &unit, (ftnlen)200);
	}
    }

/*     The following case is for offset assignments that */
/*     span multiple lines. */

    if (*nfield > 4 || lnb > 80) {

/*        Save the start position for the offsets. */

	start = lastnb_(longln, (ftnlen)200);


/*        Fill in the first line and write it. */

	dpfmt_(&offset[(i__1 = 0) < offset_dim1 ? i__1 : s_rnge("offset", 
		i__1, "t_wclk01__", (ftnlen)948)], "XXXXXXXXXXXXXX", numstr, (
		ftnlen)14, (ftnlen)80);
	ljust_(numstr, numstr, (ftnlen)80, (ftnlen)80);
	repmc_(longln, "#", numstr, longln, (ftnlen)200, (ftnlen)1, (ftnlen)
		80, (ftnlen)200);

/*        Append a comma to the line. */

	suffix_(",", &c__0, longln, (ftnlen)1, (ftnlen)200);
	writln_(longln, &unit, (ftnlen)200);

/*        Fill in the lines preceding the last line and */
/*        write these as well. */

	i__1 = *nfield - 1;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    s_copy(longln, " ", (ftnlen)200, (ftnlen)1);
	    s_copy(longln + (start - 1), "#,", 200 - (start - 1), (ftnlen)2);
	    dpfmt_(&offset[(i__2 = i__ - 1) < offset_dim1 && 0 <= i__2 ? i__2 
		    : s_rnge("offset", i__2, "t_wclk01__", (ftnlen)968)], 
		    "XXXXXXXXXXXXXX", numstr, (ftnlen)14, (ftnlen)80);
	    ljust_(numstr, numstr, (ftnlen)80, (ftnlen)80);
	    repmc_(longln, "#", numstr, longln, (ftnlen)200, (ftnlen)1, (
		    ftnlen)80, (ftnlen)200);
	    writln_(longln, &unit, (ftnlen)200);
	}

/*        Fill in and write the last line. */

	s_copy(longln, " ", (ftnlen)200, (ftnlen)1);
	s_copy(longln + (start - 1), "# )", 200 - (start - 1), (ftnlen)3);
	dpfmt_(&offset[(i__1 = *nfield - 1) < offset_dim1 && 0 <= i__1 ? i__1 
		: s_rnge("offset", i__1, "t_wclk01__", (ftnlen)982)], "XXXXX"
		"XXXXXXXXX", numstr, (ftnlen)14, (ftnlen)80);
	ljust_(numstr, numstr, (ftnlen)80, (ftnlen)80);
	repmc_(longln, "#", numstr, longln, (ftnlen)200, (ftnlen)1, (ftnlen)
		80, (ftnlen)200);
	writln_(longln, &unit, (ftnlen)200);
    }

/*     Write the output delimiter line. */

    j = i_indx(dlchrs, delim, (ftnlen)5, delim_len);
    if (j == 0) {
	setmsg_("SCLK output delimiter for file # must be in set {#} but was"
		" #.", (ftnlen)62);
	errch_("#", fname, (ftnlen)1, fname_len);
	for (i__ = 1; i__ <= 4; ++i__) {
/* Writing concatenation */
	    i__5[0] = 1, a__1[0] = "#";
	    i__5[1] = 1, a__1[1] = dlchrs + (i__ - 1);
	    i__5[2] = 2, a__1[2] = ",#";
	    s_cat(ch__2, a__1, i__5, &c__3, (ftnlen)4);
	    errch_("#", ch__2, (ftnlen)1, (ftnlen)4);
	}
	errch_("#", dlchrs + 4, (ftnlen)1, (ftnlen)1);
	errch_("#", delim, (ftnlen)1, delim_len);
	sigerr_("SPICE(INVALIDDELIMITER)", (ftnlen)23);
	chkout_("T_WCLK01", (ftnlen)8);
	return 0;
    }
    s_copy(line, "   SCLK01_OUTPUT_DELIM_#         = ( # )", (ftnlen)80, (
	    ftnlen)40);
    repmi_(line, "#", &strid, line, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    repmi_(line, "#", &j, line, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    writln_(line, &unit, (ftnlen)80);

/*     A blank line separates the clock attributes from the */
/*     partition data. */

    writln_(" ", &unit, (ftnlen)1);

/*     Write the partition start data; one value only per line. */

    if (*nparts < 1 || *nparts > 9999) {
	setmsg_("SCLK partition count for file # must be in range 1 : # but "
		"was #.", (ftnlen)65);
	errch_("#", fname, (ftnlen)1, fname_len);
	errint_("#", &c__9999, (ftnlen)1);
	errint_("#", nparts, (ftnlen)1);
	sigerr_("SPICE(BADPARTITIONCOUNT)", (ftnlen)24);
	chkout_("T_WCLK01", (ftnlen)8);
	return 0;
    }
    i__1 = *nparts;
    for (i__ = 1; i__ <= i__1; ++i__) {

/*        Partition start readouts must be at least zero */
/*        and must be strictly less than the corresponding */
/*        stop readouts. */

	if (pstart[(i__2 = i__ - 1) < pstart_dim1 && 0 <= i__2 ? i__2 : 
		s_rnge("pstart", i__2, "t_wclk01__", (ftnlen)1047)] < 0. || 
		pstart[(i__3 = i__ - 1) < pstart_dim1 && 0 <= i__3 ? i__3 : 
		s_rnge("pstart", i__3, "t_wclk01__", (ftnlen)1047)] >= pstop[(
		i__4 = i__ - 1) < pstop_dim1 && 0 <= i__4 ? i__4 : s_rnge(
		"pstop", i__4, "t_wclk01__", (ftnlen)1047)]) {
	    setmsg_("SCLK partition start # for file # must be in range 0 : "
		    "# but was #.", (ftnlen)67);
	    errint_("#", &i__, (ftnlen)1);
	    errch_("#", fname, (ftnlen)1, fname_len);
	    d__1 = pstop[(i__2 = i__ - 1) < pstop_dim1 && 0 <= i__2 ? i__2 : 
		    s_rnge("pstop", i__2, "t_wclk01__", (ftnlen)1054)] - 1;
	    errdp_("#", &d__1, (ftnlen)1);
	    errdp_("#", &pstart[(i__2 = i__ - 1) < pstart_dim1 && 0 <= i__2 ? 
		    i__2 : s_rnge("pstart", i__2, "t_wclk01__", (ftnlen)1055)]
		    , (ftnlen)1);
	    sigerr_("SPICE(BADPARTITIONSTART)", (ftnlen)24);
	    chkout_("T_WCLK01", (ftnlen)8);
	    return 0;
	}

/*        Partition start times must be integral. */

	if (pstart[(i__2 = i__ - 1) < pstart_dim1 && 0 <= i__2 ? i__2 : 
		s_rnge("pstart", i__2, "t_wclk01__", (ftnlen)1065)] != d_nint(
		&pstart[(i__3 = i__ - 1) < pstart_dim1 && 0 <= i__3 ? i__3 : 
		s_rnge("pstart", i__3, "t_wclk01__", (ftnlen)1065)])) {
	    setmsg_("SCLK partition start # for file # must be integral but "
		    "was #.", (ftnlen)61);
	    errint_("#", &i__, (ftnlen)1);
	    errch_("#", fname, (ftnlen)1, fname_len);
	    errdp_("#", &pstart[(i__2 = i__ - 1) < pstart_dim1 && 0 <= i__2 ? 
		    i__2 : s_rnge("pstart", i__2, "t_wclk01__", (ftnlen)1071)]
		    , (ftnlen)1);
	    sigerr_("SPICE(BADPARTITIONSTART)", (ftnlen)24);
	    chkout_("T_WCLK01", (ftnlen)8);
	    return 0;
	}
    }
    s_copy(line, "   SCLK_PARTITION_START_#        = ( #", (ftnlen)80, (
	    ftnlen)38);
    repmi_(line, "#", &strid, line, (ftnlen)80, (ftnlen)1, (ftnlen)80);

/*     Record the value start index in the line. */

    start = lastnb_(line, (ftnlen)80);

/*     We must format partition bounds using a Fortran internal write */
/*     because the SPICE formatting routines can't handle 16 */
/*     significant digits. */

    ici__1.icierr = 1;
    ici__1.icirnum = 1;
    ici__1.icirlen = 80;
    ici__1.iciunit = numstr;
    ici__1.icifmt = "(F20.1)";
    iostat = s_wsfi(&ici__1);
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_fio(&c__1, (char *)&pstart[(i__1 = 0) < pstart_dim1 ? i__1 : 
	    s_rnge("pstart", i__1, "t_wclk01__", (ftnlen)1094)], (ftnlen)
	    sizeof(doublereal));
    if (iostat != 0) {
	goto L100001;
    }
    iostat = e_wsfi();
L100001:
    if (iostat != 0) {
	setmsg_("SCLK partition start # for file # could not be formatted; v"
		"alue = #; IOSTAT = #.", (ftnlen)80);
	errint_("#", &i__, (ftnlen)1);
	errch_("#", fname, (ftnlen)1, fname_len);
	errdp_("#", &pstart[(i__1 = 0) < pstart_dim1 ? i__1 : s_rnge("pstart",
		 i__1, "t_wclk01__", (ftnlen)1102)], (ftnlen)1);
	errint_("#", &iostat, (ftnlen)1);
	sigerr_("SPICE(WRITEERROR)", (ftnlen)17);
	chkout_("T_WCLK01", (ftnlen)8);
	return 0;
    }
    repmc_(line, "#", numstr, line, (ftnlen)80, (ftnlen)1, (ftnlen)80, (
	    ftnlen)80);
    if (*nparts > 1) {
	suffix_(",", &c__0, line, (ftnlen)1, (ftnlen)80);
    } else {
	suffix_(")", &c__1, line, (ftnlen)1, (ftnlen)80);
    }
    writln_(line, &unit, (ftnlen)80);
    if (*nparts > 1) {

/*        Write the rest of the partitions. */

	i__1 = *nparts - 1;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    ici__1.icierr = 1;
	    ici__1.icirnum = 1;
	    ici__1.icirlen = 80;
	    ici__1.iciunit = numstr;
	    ici__1.icifmt = "(F20.1)";
	    iostat = s_wsfi(&ici__1);
	    if (iostat != 0) {
		goto L100002;
	    }
	    iostat = do_fio(&c__1, (char *)&pstart[(i__2 = i__ - 1) < 
		    pstart_dim1 && 0 <= i__2 ? i__2 : s_rnge("pstart", i__2, 
		    "t_wclk01__", (ftnlen)1128)], (ftnlen)sizeof(doublereal));
	    if (iostat != 0) {
		goto L100002;
	    }
	    iostat = e_wsfi();
L100002:
	    if (iostat != 0) {
		setmsg_("SCLK partition start # for file # could not be form"
			"atted; value = #; IOSTAT = #.", (ftnlen)80);
		errint_("#", &i__, (ftnlen)1);
		errch_("#", fname, (ftnlen)1, fname_len);
		errdp_("#", &pstart[(i__2 = i__ - 1) < pstart_dim1 && 0 <= 
			i__2 ? i__2 : s_rnge("pstart", i__2, "t_wclk01__", (
			ftnlen)1136)], (ftnlen)1);
		errint_("#", &iostat, (ftnlen)1);
		sigerr_("SPICE(WRITEERROR)", (ftnlen)17);
		chkout_("T_WCLK01", (ftnlen)8);
		return 0;
	    }
	    ljust_(numstr, numstr, (ftnlen)80, (ftnlen)80);
	    s_copy(line, " ", (ftnlen)80, (ftnlen)1);
	    s_copy(line + (start - 1), numstr, 80 - (start - 1), (ftnlen)80);
	    suffix_(",", &c__0, line, (ftnlen)1, (ftnlen)80);
	    writln_(line, &unit, (ftnlen)80);
	}
	ici__1.icierr = 1;
	ici__1.icirnum = 1;
	ici__1.icirlen = 80;
	ici__1.iciunit = numstr;
	ici__1.icifmt = "(F20.1)";
	iostat = s_wsfi(&ici__1);
	if (iostat != 0) {
	    goto L100003;
	}
	iostat = do_fio(&c__1, (char *)&pstart[(i__1 = *nparts - 1) < 
		pstart_dim1 && 0 <= i__1 ? i__1 : s_rnge("pstart", i__1, 
		"t_wclk01__", (ftnlen)1156)], (ftnlen)sizeof(doublereal));
	if (iostat != 0) {
	    goto L100003;
	}
	iostat = e_wsfi();
L100003:
	if (iostat != 0) {
	    setmsg_("SCLK partition start # for file # could not be formatte"
		    "d; value = #; IOSTAT = #.", (ftnlen)80);
	    errint_("#", &i__, (ftnlen)1);
	    errch_("#", fname, (ftnlen)1, fname_len);
	    errdp_("#", &pstart[(i__1 = i__ - 1) < pstart_dim1 && 0 <= i__1 ? 
		    i__1 : s_rnge("pstart", i__1, "t_wclk01__", (ftnlen)1164)]
		    , (ftnlen)1);
	    errint_("#", &iostat, (ftnlen)1);
	    sigerr_("SPICE(WRITEERROR)", (ftnlen)17);
	    chkout_("T_WCLK01", (ftnlen)8);
	    return 0;
	}
	ljust_(numstr, numstr, (ftnlen)80, (ftnlen)80);
	s_copy(line, " ", (ftnlen)80, (ftnlen)1);
	s_copy(line + (start - 1), numstr, 80 - (start - 1), (ftnlen)80);
	suffix_(")", &c__1, line, (ftnlen)1, (ftnlen)80);
	writln_(line, &unit, (ftnlen)80);
    }
    writln_(" ", &unit, (ftnlen)1);

/*     Write the partition stop data; one value only per line. */

    i__1 = *nparts;
    for (i__ = 1; i__ <= i__1; ++i__) {

/*        Partition stop readouts must be strictly greater than the */
/*        partition start values (this has been checked) and must not */
/*        exceed the product of the moduli. */

	if (pstop[(i__2 = i__ - 1) < pstop_dim1 && 0 <= i__2 ? i__2 : s_rnge(
		"pstop", i__2, "t_wclk01__", (ftnlen)1195)] > prodm) {
	    setmsg_("SCLK partition stop # for file # must be in range # : #"
		    " but was #.", (ftnlen)66);
	    errint_("#", &i__, (ftnlen)1);
	    errch_("#", fname, (ftnlen)1, fname_len);
	    errdp_("#", &pstart[(i__2 = i__ - 1) < pstart_dim1 && 0 <= i__2 ? 
		    i__2 : s_rnge("pstart", i__2, "t_wclk01__", (ftnlen)1201)]
		    , (ftnlen)1);
	    errdp_("#", &prodm, (ftnlen)1);
	    errdp_("#", &pstop[(i__2 = i__ - 1) < pstop_dim1 && 0 <= i__2 ? 
		    i__2 : s_rnge("pstop", i__2, "t_wclk01__", (ftnlen)1203)],
		     (ftnlen)1);
	    sigerr_("SPICE(BADPARTITIONSTOP)", (ftnlen)23);
	    chkout_("T_WCLK01", (ftnlen)8);
	    return 0;
	}

/*        Partition stop times must be integral. */

	if (pstop[(i__2 = i__ - 1) < pstop_dim1 && 0 <= i__2 ? i__2 : s_rnge(
		"pstop", i__2, "t_wclk01__", (ftnlen)1213)] != d_nint(&pstop[(
		i__3 = i__ - 1) < pstop_dim1 && 0 <= i__3 ? i__3 : s_rnge(
		"pstop", i__3, "t_wclk01__", (ftnlen)1213)])) {
	    setmsg_("SCLK partition stop # for file # must be integral but w"
		    "as #.", (ftnlen)60);
	    errint_("#", &i__, (ftnlen)1);
	    errch_("#", fname, (ftnlen)1, fname_len);
	    errdp_("#", &pstop[(i__2 = i__ - 1) < pstop_dim1 && 0 <= i__2 ? 
		    i__2 : s_rnge("pstop", i__2, "t_wclk01__", (ftnlen)1219)],
		     (ftnlen)1);
	    sigerr_("SPICE(BADPARTITIONSTOP)", (ftnlen)23);
	    chkout_("T_WCLK01", (ftnlen)8);
	    return 0;
	}
    }
    s_copy(line, "   SCLK_PARTITION_END_#          = ( #", (ftnlen)80, (
	    ftnlen)38);
    repmi_(line, "#", &strid, line, (ftnlen)80, (ftnlen)1, (ftnlen)80);

/*     Record the value start index in the line. */

    start = lastnb_(line, (ftnlen)80);

/*     We must format partition bounds using a Fortran internal write */
/*     because the SPICE formatting routines can't handle 16 */
/*     significant digits. */

    ici__1.icierr = 1;
    ici__1.icirnum = 1;
    ici__1.icirlen = 80;
    ici__1.iciunit = numstr;
    ici__1.icifmt = "(F20.1)";
    iostat = s_wsfi(&ici__1);
    if (iostat != 0) {
	goto L100004;
    }
    iostat = do_fio(&c__1, (char *)&pstop[(i__1 = 0) < pstop_dim1 ? i__1 : 
	    s_rnge("pstop", i__1, "t_wclk01__", (ftnlen)1242)], (ftnlen)
	    sizeof(doublereal));
    if (iostat != 0) {
	goto L100004;
    }
    iostat = e_wsfi();
L100004:
    if (iostat != 0) {
	setmsg_("SCLK partition stop # for file # could not be formatted; va"
		"lue = #; IOSTAT = #.", (ftnlen)79);
	errint_("#", &i__, (ftnlen)1);
	errch_("#", fname, (ftnlen)1, fname_len);
	errdp_("#", &pstop[(i__1 = 0) < pstop_dim1 ? i__1 : s_rnge("pstop", 
		i__1, "t_wclk01__", (ftnlen)1250)], (ftnlen)1);
	errint_("#", &iostat, (ftnlen)1);
	sigerr_("SPICE(WRITEERROR)", (ftnlen)17);
	chkout_("T_WCLK01", (ftnlen)8);
	return 0;
    }
    repmc_(line, "#", numstr, line, (ftnlen)80, (ftnlen)1, (ftnlen)80, (
	    ftnlen)80);
    if (*nparts > 1) {
	suffix_(",", &c__0, line, (ftnlen)1, (ftnlen)80);
    } else {
	suffix_(")", &c__1, line, (ftnlen)1, (ftnlen)80);
    }
    writln_(line, &unit, (ftnlen)80);
    if (*nparts > 1) {

/*        Write the rest of the partitions. */

	i__1 = *nparts - 1;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    ici__1.icierr = 1;
	    ici__1.icirnum = 1;
	    ici__1.icirlen = 80;
	    ici__1.iciunit = numstr;
	    ici__1.icifmt = "(F20.1)";
	    iostat = s_wsfi(&ici__1);
	    if (iostat != 0) {
		goto L100005;
	    }
	    iostat = do_fio(&c__1, (char *)&pstop[(i__2 = i__ - 1) < 
		    pstop_dim1 && 0 <= i__2 ? i__2 : s_rnge("pstop", i__2, 
		    "t_wclk01__", (ftnlen)1276)], (ftnlen)sizeof(doublereal));
	    if (iostat != 0) {
		goto L100005;
	    }
	    iostat = e_wsfi();
L100005:
	    if (iostat != 0) {
		setmsg_("SCLK partition stop # for file # could not be forma"
			"tted; value = #; IOSTAT = #.", (ftnlen)79);
		errint_("#", &i__, (ftnlen)1);
		errch_("#", fname, (ftnlen)1, fname_len);
		errdp_("#", &pstop[(i__2 = i__ - 1) < pstop_dim1 && 0 <= i__2 
			? i__2 : s_rnge("pstop", i__2, "t_wclk01__", (ftnlen)
			1284)], (ftnlen)1);
		errint_("#", &iostat, (ftnlen)1);
		sigerr_("SPICE(WRITEERROR)", (ftnlen)17);
		chkout_("T_WCLK01", (ftnlen)8);
		return 0;
	    }
	    ljust_(numstr, numstr, (ftnlen)80, (ftnlen)80);
	    s_copy(line, " ", (ftnlen)80, (ftnlen)1);
	    s_copy(line + (start - 1), numstr, 80 - (start - 1), (ftnlen)80);
	    suffix_(",", &c__0, line, (ftnlen)1, (ftnlen)80);
	    writln_(line, &unit, (ftnlen)80);
	}
	ici__1.icierr = 1;
	ici__1.icirnum = 1;
	ici__1.icirlen = 80;
	ici__1.iciunit = numstr;
	ici__1.icifmt = "(F20.1)";
	iostat = s_wsfi(&ici__1);
	if (iostat != 0) {
	    goto L100006;
	}
	iostat = do_fio(&c__1, (char *)&pstop[(i__1 = *nparts - 1) < 
		pstop_dim1 && 0 <= i__1 ? i__1 : s_rnge("pstop", i__1, "t_wc"
		"lk01__", (ftnlen)1304)], (ftnlen)sizeof(doublereal));
	if (iostat != 0) {
	    goto L100006;
	}
	iostat = e_wsfi();
L100006:
	if (iostat != 0) {
	    setmsg_("SCLK partition stop # for file # could not be formatted"
		    "; value = #; IOSTAT = #.", (ftnlen)79);
	    errint_("#", &i__, (ftnlen)1);
	    errch_("#", fname, (ftnlen)1, fname_len);
	    errdp_("#", &pstop[(i__1 = i__ - 1) < pstop_dim1 && 0 <= i__1 ? 
		    i__1 : s_rnge("pstop", i__1, "t_wclk01__", (ftnlen)1312)],
		     (ftnlen)1);
	    errint_("#", &iostat, (ftnlen)1);
	    sigerr_("SPICE(WRITEERROR)", (ftnlen)17);
	    chkout_("T_WCLK01", (ftnlen)8);
	    return 0;
	}
	ljust_(numstr, numstr, (ftnlen)80, (ftnlen)80);
	s_copy(line, " ", (ftnlen)80, (ftnlen)1);
	s_copy(line + (start - 1), numstr, 80 - (start - 1), (ftnlen)80);
	suffix_(")", &c__1, line, (ftnlen)1, (ftnlen)80);
	writln_(line, &unit, (ftnlen)80);
    }
    writln_(" ", &unit, (ftnlen)1);

/*     Prepare to write the coefficients. */


/*     Perform some simple checks on the coefficients. */

    if (*ncoeff < 1 || *ncoeff > 50000) {
	setmsg_("SCLK coefficient record count for file # must be in range 1"
		" : # but was #.", (ftnlen)74);
	errch_("#", fname, (ftnlen)1, fname_len);
	errint_("#", &c__50000, (ftnlen)1);
	errint_("#", ncoeff, (ftnlen)1);
	sigerr_("SPICE(BADRECORDCOUNT)", (ftnlen)21);
	chkout_("T_WCLK01", (ftnlen)8);
	return 0;
    }

/*     The first tick value must be non-negative; the tick values */
/*     must be strictly increasing. */

    if (coeffs[(i__1 = 0) < coeffs_dim2 * 3 ? i__1 : s_rnge("coeffs", i__1, 
	    "t_wclk01__", (ftnlen)1358)] < 0.) {
	setmsg_("First tick coefficient  for file # must be non-negative but"
		" was #.", (ftnlen)66);
	errch_("#", fname, (ftnlen)1, fname_len);
	errdp_("#", &coeffs[(i__1 = 0) < coeffs_dim2 * 3 ? i__1 : s_rnge(
		"coeffs", i__1, "t_wclk01__", (ftnlen)1363)], (ftnlen)1);
	sigerr_("SPICE(NEGATIVETICK)", (ftnlen)19);
	chkout_("T_WCLK01", (ftnlen)8);
	return 0;
    }
    i__1 = *ncoeff;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (coeffs[(i__2 = i__ * 3 - 3) < coeffs_dim2 * 3 && 0 <= i__2 ? i__2 
		: s_rnge("coeffs", i__2, "t_wclk01__", (ftnlen)1372)] <= 
		coeffs[(i__3 = (i__ - 1) * 3 - 3) < coeffs_dim2 * 3 && 0 <= 
		i__3 ? i__3 : s_rnge("coeffs", i__3, "t_wclk01__", (ftnlen)
		1372)]) {
	    setmsg_("In file #, tick coefficient # at index # must be strict"
		    "ly less than coefficient # at index # but was not. ", (
		    ftnlen)106);
	    errch_("#", fname, (ftnlen)1, fname_len);
	    errdp_("#", &coeffs[(i__2 = (i__ - 1) * 3 - 3) < coeffs_dim2 * 3 
		    && 0 <= i__2 ? i__2 : s_rnge("coeffs", i__2, "t_wclk01__",
		     (ftnlen)1378)], (ftnlen)1);
	    i__2 = i__ - 1;
	    errint_("#", &i__2, (ftnlen)1);
	    errdp_("#", &coeffs[(i__2 = i__ * 3 - 3) < coeffs_dim2 * 3 && 0 <=
		     i__2 ? i__2 : s_rnge("coeffs", i__2, "t_wclk01__", (
		    ftnlen)1380)], (ftnlen)1);
	    errint_("#", &i__, (ftnlen)1);
	    sigerr_("SPICE(TICKSOUTOFORDER)", (ftnlen)22);
	    chkout_("T_WCLK01", (ftnlen)8);
	    return 0;
	}
    }

/*     The parallel time system values must be strictly increasing. */

    i__1 = *ncoeff;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (coeffs[(i__2 = i__ * 3 - 2) < coeffs_dim2 * 3 && 0 <= i__2 ? i__2 
		: s_rnge("coeffs", i__2, "t_wclk01__", (ftnlen)1395)] <= 
		coeffs[(i__3 = (i__ - 1) * 3 - 2) < coeffs_dim2 * 3 && 0 <= 
		i__3 ? i__3 : s_rnge("coeffs", i__3, "t_wclk01__", (ftnlen)
		1395)]) {
	    setmsg_("In file #, parallel time coefficient # at index # must "
		    "be strictly less than coefficient # at index # but was n"
		    "ot. ", (ftnlen)115);
	    errch_("#", fname, (ftnlen)1, fname_len);
	    errdp_("#", &coeffs[(i__2 = (i__ - 1) * 3 - 2) < coeffs_dim2 * 3 
		    && 0 <= i__2 ? i__2 : s_rnge("coeffs", i__2, "t_wclk01__",
		     (ftnlen)1401)], (ftnlen)1);
	    i__2 = i__ - 1;
	    errint_("#", &i__2, (ftnlen)1);
	    errdp_("#", &coeffs[(i__2 = i__ * 3 - 2) < coeffs_dim2 * 3 && 0 <=
		     i__2 ? i__2 : s_rnge("coeffs", i__2, "t_wclk01__", (
		    ftnlen)1403)], (ftnlen)1);
	    errint_("#", &i__, (ftnlen)1);
	    sigerr_("SPICE(TIMESOUTOFORDER)", (ftnlen)22);
	    chkout_("T_WCLK01", (ftnlen)8);
	    return 0;
	}
    }

/*     The SCLK rate values must be strictly positive. */

    i__1 = *ncoeff;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (coeffs[(i__2 = i__ * 3 - 1) < coeffs_dim2 * 3 && 0 <= i__2 ? i__2 
		: s_rnge("coeffs", i__2, "t_wclk01__", (ftnlen)1418)] <= 0.) {
	    setmsg_("In file #, SCLK rate coefficient # at index # must be s"
		    "trictly positive but was not. ", (ftnlen)85);
	    errch_("#", fname, (ftnlen)1, fname_len);
	    errdp_("#", &coeffs[(i__2 = (i__ - 1) * 3 - 1) < coeffs_dim2 * 3 
		    && 0 <= i__2 ? i__2 : s_rnge("coeffs", i__2, "t_wclk01__",
		     (ftnlen)1424)], (ftnlen)1);
	    errint_("#", &i__, (ftnlen)1);
	    sigerr_("SPICE(NONPOSITIVERATE)", (ftnlen)22);
	    chkout_("T_WCLK01", (ftnlen)8);
	    return 0;
	}
    }

/*     Write the coefficient data; three values per line. */
/*     The first line contains no data. */

    s_copy(line, "   SCLK01_COEFFICIENTS_#         = (", (ftnlen)80, (ftnlen)
	    36);
    repmi_(line, "#", &strid, line, (ftnlen)80, (ftnlen)1, (ftnlen)80);
    writln_(line, &unit, (ftnlen)80);
    writln_(" ", &unit, (ftnlen)1);
    i__1 = *ncoeff;
    for (i__ = 1; i__ <= i__1; ++i__) {

/*        We must format coefficients using a Fortran internal write */
/*        because the SPICE formatting routines can't handle 16 */
/*        significant digits. */

	ici__1.icierr = 1;
	ici__1.icirnum = 1;
	ici__1.icirlen = 80;
	ici__1.iciunit = line;
	ici__1.icifmt = "(3X,F20.1,2E26.16)";
	iostat = s_wsfi(&ici__1);
	if (iostat != 0) {
	    goto L100007;
	}
	for (j = 1; j <= 3; ++j) {
	    iostat = do_fio(&c__1, (char *)&coeffs[(i__2 = j + i__ * 3 - 4) < 
		    coeffs_dim2 * 3 && 0 <= i__2 ? i__2 : s_rnge("coeffs", 
		    i__2, "t_wclk01__", (ftnlen)1451)], (ftnlen)sizeof(
		    doublereal));
	    if (iostat != 0) {
		goto L100007;
	    }
	}
	iostat = e_wsfi();
L100007:
	if (iostat != 0) {
	    setmsg_("Coefficient record # for file # could not be formatted;"
		    " values = # # #; IOSTAT = #.", (ftnlen)83);
	    errint_("#", &i__, (ftnlen)1);
	    errch_("#", fname, (ftnlen)1, fname_len);
	    errdp_("#", &coeffs[(i__2 = i__ * 3 - 3) < coeffs_dim2 * 3 && 0 <=
		     i__2 ? i__2 : s_rnge("coeffs", i__2, "t_wclk01__", (
		    ftnlen)1462)], (ftnlen)1);
	    errdp_("#", &coeffs[(i__2 = i__ * 3 - 2) < coeffs_dim2 * 3 && 0 <=
		     i__2 ? i__2 : s_rnge("coeffs", i__2, "t_wclk01__", (
		    ftnlen)1463)], (ftnlen)1);
	    errdp_("#", &coeffs[(i__2 = i__ * 3 - 1) < coeffs_dim2 * 3 && 0 <=
		     i__2 ? i__2 : s_rnge("coeffs", i__2, "t_wclk01__", (
		    ftnlen)1464)], (ftnlen)1);
	    errint_("#", &iostat, (ftnlen)1);
	    sigerr_("SPICE(WRITEERROR)", (ftnlen)17);
	    chkout_("T_WCLK01", (ftnlen)8);
	    return 0;
	}
	writln_(line, &unit, (ftnlen)80);
    }
    s_copy(line, "   )", (ftnlen)80, (ftnlen)4);
    writln_(line, &unit, (ftnlen)80);

/*     Write a final "begintext" marker. */

    writln_(" ", &unit, (ftnlen)1);
    begtxt_(ch__1, (ftnlen)80);
    writln_(ch__1, &unit, (ftnlen)80);
    writln_(" ", &unit, (ftnlen)1);

/*     Finish the file. */

    cl__1.cerr = 0;
    cl__1.cunit = unit;
    cl__1.csta = 0;
    f_clos(&cl__1);
    chkout_("T_WCLK01", (ftnlen)8);
    return 0;
} /* t_wclk01__ */

