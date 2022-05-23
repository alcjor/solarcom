/* t_trajfn.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* $Procedure T_TRAJFN ( Test utility, evaluate trajectory functions ) */
doublereal t_trajfn__0_(int n__, integer *targ, doublereal *et, char *ref, 
	char *abcorr, integer *obs, ftnlen ref_len, ftnlen abcorr_len)
{
    /* System generated locals */
    doublereal ret_val;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static doublereal state[6];
    static char svref[32];
    static doublereal pcorr[3], stobs[6];
    static integer svobs;
    extern /* Subroutine */ int spkez_(integer *, doublereal *, char *, char *
	    , integer *, doublereal *, doublereal *, ftnlen, ftnlen);
    static doublereal lt, dpcorr[3];
    extern /* Subroutine */ int sigerr_(char *, ftnlen), spkltc_(integer *, 
	    doublereal *, char *, char *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, ftnlen, ftnlen), spkssb_(integer *, 
	    doublereal *, char *, doublereal *, ftnlen);
    static integer svtarg;
    static char svcorr[5];
    static doublereal dlt;
    extern /* Subroutine */ int t_getsa__(integer *, doublereal *, char *, 
	    char *, integer *, doublereal *, doublereal *, ftnlen, ftnlen);

/* $ Abstract */

/*     Umbrella routine for function entry points that return state */
/*     components, light time and light time rate, and stellar */
/*     aberration correction components and their rates. */

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

/*     SPK */

/* $ Keywords */

/*     TEST */
/*     UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     TARG       I   Target body ID code. */
/*     ET         I   Epoch. */
/*     REF        I   Reference frame name. */
/*     ABCORR     I   Aberration correction. */
/*     OBS        I   Observer ID code. */

/* $ Detailed_Input */

/*     TARG           is the NAIF ID code of the target body. */

/*     ET             is the time at which to evaluate a */
/*                    state component, light time or light time */
/*                    rate, or stellar aberration correction */
/*                    component. ET is expressed as seconds */
/*                    past J2000 TDB. */

/*     REF            is the reference frame in which to */
/*                    compute a state, aberration correction, */
/*                    or aberration correction rate. */

/*     ABCORR         is an aberration correction specification */
/*                    string. Any value acceptable to SPKEZ */
/*                    may be used. */

/*     OBS            is the NAIF ID of the observer body. */

/* $ Detailed_Output */

/*     The outputs of this routine are the values returned by this */
/*     routine's function entry points. See those entry points */
/*     for details. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any exceptions that may be incurred by SPKEZ may be incurred */
/*        by this routine. */

/*     2) Any exceptions that may be incurred by SPKLTC may be incurred */
/*        by this routine. */

/*     3) Any exceptions that may be incurred by the test utility */
/*        T_GETSA may be incurred by this routine. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine contains 15 function entry points which allow a */
/*     caller to fetch state components, stellar aberration correction */
/*     components, and light time and light time rate values via */
/*     function calls. These entry points are suitable for use with the */
/*     SUPPORT library Chebyshev fitting routine CHBFIT. */

/*     To use this package, an application should call the entry point */

/*        T_STCINI */

/*     to set the saved variables defining a state computation: */

/*        observer */
/*        target */
/*        aberration correction */
/*        reference frame. */

/*     After this, any of the state or aberration correction computation */
/*     functions can be called with an ET (seconds past J2000 TDB) input */
/*     value. */

/*     The entry points and their descriptions are listed below. */


/*     T_GETDLT {Get light time derivative} */
/*     T_GETDSX {Get stellar aberration correction velocity X-component} */
/*     T_GETDSY {Get stellar aberration correction velocity Y-component} */
/*     T_GETDSZ {Get stellar aberration correction velocity Z-component} */
/*     T_GETDX  {Get velocity X-component} */
/*     T_GETDY  {Get velocity Y-component} */
/*     T_GETDZ  {Get velocity Z-component} */
/*     T_GETLT  {Get light time} */
/*     T_GETSX  {Get stellar aberration correction X-component} */
/*     T_GETSY  {Get stellar aberration correction Y-component} */
/*     T_GETSZ  {Get stellar aberration correction Z-component} */
/*     T_GETX   {Get position X-component} */
/*     T_GETY   {Get position Y-component} */
/*     T_GETZ   {Get position Z-component} */
/*     T_STCINI {Initialize state and aberration correction computations} */



/* $ Examples */

/*     See the test family F_ABCORR for usage examples. */

/* $ Restrictions */

/*     Due to the large number and trivial nature of the entry points, */
/*     these functions have very abbreviated header comments. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 26-DEC-2007 (NJB) */

/* -& */

/*     Entry points */

/* $ Abstract */

/*     Include file zzabcorr.inc */

/*     SPICE private file intended solely for the support of SPICE */
/*     routines.  Users should not include this file directly due */
/*     to the volatile nature of this file */

/*     The parameters below define the structure of an aberration */
/*     correction attribute block. */

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

/*     An aberration correction attribute block is an array of logical */
/*     flags indicating the attributes of the aberration correction */
/*     specified by an aberration correction string.  The attributes */
/*     are: */

/*        - Is the correction "geometric"? */

/*        - Is light time correction indicated? */

/*        - Is stellar aberration correction indicated? */

/*        - Is the light time correction of the "converged */
/*          Newtonian" variety? */

/*        - Is the correction for the transmission case? */

/*        - Is the correction relativistic? */

/*    The parameters defining the structure of the block are as */
/*    follows: */

/*       NABCOR    Number of aberration correction choices. */

/*       ABATSZ    Number of elements in the aberration correction */
/*                 block. */

/*       GEOIDX    Index in block of geometric correction flag. */

/*       LTIDX     Index of light time flag. */

/*       STLIDX    Index of stellar aberration flag. */

/*       CNVIDX    Index of converged Newtonian flag. */

/*       XMTIDX    Index of transmission flag. */

/*       RELIDX    Index of relativistic flag. */

/*    The following parameter is not required to define the block */
/*    structure, but it is convenient to include it here: */

/*       CORLEN    The maximum string length required by any aberration */
/*                 correction string */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Literature_References */

/*     None. */

/* $ Version */

/* -    SPICELIB Version 1.0.0, 18-DEC-2004 (NJB) */

/* -& */
/*     Number of aberration correction choices: */


/*     Aberration correction attribute block size */
/*     (number of aberration correction attributes): */


/*     Indices of attributes within an aberration correction */
/*     attribute block: */


/*     Maximum length of an aberration correction string: */


/*     End of include file zzabcorr.inc */


/*     Local parameters */


/*     Local variables */


/*     Saved variables */

    switch(n__) {
	case 1: goto L_t_stcini;
	case 2: goto L_t_getx;
	case 3: goto L_t_gety;
	case 4: goto L_t_getz;
	case 5: goto L_t_getdx;
	case 6: goto L_t_getdy;
	case 7: goto L_t_getdz;
	case 8: goto L_t_getsx;
	case 9: goto L_t_getsy;
	case 10: goto L_t_getsz;
	case 11: goto L_t_getdsx;
	case 12: goto L_t_getdsy;
	case 13: goto L_t_getdsz;
	case 14: goto L_t_getlt;
	case 15: goto L_t_getdlt;
	}

    ret_val = 0.;
    sigerr_("SPICE(BOGUSENTRY)", (ftnlen)17);
    return ret_val;
/* $Procedure T_STCINI ( Test utility, state computation initialization ) */

L_t_stcini:
/* $ Abstract */


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

/*     SPK */

/* $ Keywords */

/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     INTEGER               TARG */
/*     CHARACTER*(*)         REF */
/*     CHARACTER*(*)         ABCORR */
/*     INTEGER               OBS */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     TARG       I   Target body ID code. */
/*     REF        I   Reference frame name. */
/*     ABCORR     I   Aberration correction. */
/*     OBS        I   Observer ID code. */

/* $ Detailed_Input */

/*     TARG           is the NAIF ID code of the target body. */

/*     REF            is the reference frame in which to */
/*                    compute a state, aberration correction, */
/*                    or aberration correction rate. */

/*     ABCORR         is an aberration correction specification */
/*                    string. Any value acceptable to SPKEZ */
/*                    may be used. */

/*     OBS            is the NAIF ID of the observer body. */

/* $ Detailed_Output */

/*     This routine operates by side effects. It returns an */
/*     unspecfied double precision constant, since Fortran */
/*     requires all functions and function entry points to */
/*     return values. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any exceptions that may be incurred by ZZPRSCOR may be incurred */
/*        by this routine. */

/* $ Files */

/*     See the header of SPKEZ. */

/* $ Particulars */

/*     This function initializes a state, aberration correction, or */
/*     aberration correction rate computation by saving parameters, */
/*     other than time, required to define a state. This function should */
/*     be called prior to calling the other entry points. */

/* $ Examples */

/*     See the test family F_ABCORR for usage examples. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 30-DEC-2007 (NJB) */

/* -& */

/*     Set the double precision return value, since one is */
/*     required. */

    ret_val = 0.;

/*     Save the input arguments for later use. */

    svtarg = *targ;
    s_copy(svref, ref, (ftnlen)32, ref_len);
    s_copy(svcorr, abcorr, (ftnlen)5, abcorr_len);
    svobs = *obs;
    return ret_val;
/* $Procedure T_GETX ( Test utility, get position X component ) */

L_t_getx:
/* $ Abstract */

/*     Return X component of position vector at ET. */

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

/*     SPK */

/* $ Keywords */

/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      ET */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Epoch. */

/* $ Detailed_Input */

/*     ET             is the time at which to evaluate the state vector */
/*                    whose X position component is requested. ET is */
/*                    expressed as seconds past J2000 TDB. */

/* $ Detailed_Output */

/*     This routine returns the X component of the position vector */
/*     defined by the input ET value and the saved observer, target, */
/*     reference frame, and aberration correction values initialized */
/*     by the last call to T_STCINI. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any exceptions that may be incurred by SPKEZ may be incurred */
/*        by this routine. */

/* $ Files */

/*     See the header of SPKEZ. */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*     See the test family F_ABCORR for usage examples. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 21-DEC-2007 (NJB) */

/* -& */

/*     Look up the state. Return the X component of position. */

    spkez_(&svtarg, et, svref, svcorr, &svobs, state, &lt, (ftnlen)32, (
	    ftnlen)5);
    ret_val = state[0];
    return ret_val;
/* $Procedure T_GETY ( Test utility, get position Y component ) */

L_t_gety:
/* $ Abstract */

/*     Return Y component of position vector at ET. */

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

/*     SPK */

/* $ Keywords */

/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      ET */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Epoch. */

/* $ Detailed_Input */

/*     ET             is the time at which to evaluate the state vector */
/*                    whose Y position component is requested. ET is */
/*                    expressed as seconds past J2000 TDB. */

/* $ Detailed_Output */

/*     This routine returns the Y component of the position vector */
/*     defined by the input ET value and the saved observer, target, */
/*     reference frame, and aberration correction values initialized */
/*     by the last call to T_STCINI. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any exceptions that may be incurred by SPKEZ may be incurred */
/*        by this routine. */

/* $ Files */

/*     See the header of SPKEZ. */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*     See the test family F_ABCORR for usage examples. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 21-DEC-2007 (NJB) */

/* -& */

/*     Look up the state. Return the Y component of position. */

    spkez_(&svtarg, et, svref, svcorr, &svobs, state, &lt, (ftnlen)32, (
	    ftnlen)5);
    ret_val = state[1];
    return ret_val;
/* $Procedure T_GETZ ( Test utility, get position Z component ) */

L_t_getz:
/* $ Abstract */

/*     Return Z component of position vector at ET. */

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

/*     SPK */

/* $ Keywords */

/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      ET */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Epoch. */

/* $ Detailed_Input */

/*     ET             is the time at which to evaluate the state vector */
/*                    whose Z position component is requested. ET is */
/*                    expressed as seconds past J2000 TDB. */

/* $ Detailed_Output */

/*     This routine returns the Z component of the position vector */
/*     defined by the input ET value and the saved observer, target, */
/*     reference frame, and aberration correction values initialized */
/*     by the last call to T_STCINI. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any exceptions that may be incurred by SPKEZ may be incurred */
/*        by this routine. */

/* $ Files */

/*     See the header of SPKEZ. */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*     See the test family F_ABCORR for usage examples. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 21-DEC-2007 (NJB) */

/* -& */

/*     Look up the state. Return the Z component of position. */

    spkez_(&svtarg, et, svref, svcorr, &svobs, state, &lt, (ftnlen)32, (
	    ftnlen)5);
    ret_val = state[2];
    return ret_val;
/* $Procedure T_GETDX ( Test utility, get velocity X component ) */

L_t_getdx:
/* $ Abstract */

/*     Return X component of velocity vector at ET. */

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

/*     SPK */

/* $ Keywords */

/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      ET */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Epoch. */

/* $ Detailed_Input */

/*     ET             is the time at which to evaluate the state vector */
/*                    whose X velocity component is requested. ET is */
/*                    expressed as seconds past J2000 TDB. */

/* $ Detailed_Output */

/*     This routine returns the X component of the velocity vector */
/*     defined by the input ET value and the saved observer, target, */
/*     reference frame, and aberration correction values initialized */
/*     by the last call to T_STCINI. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any exceptions that may be incurred by SPKEZ may be incurred */
/*        by this routine. */

/* $ Files */

/*     See the header of SPKEZ. */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*     See the test family F_ABCORR for usage examples. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 21-DEC-2007 (NJB) */

/* -& */

/*     Look up the state. Return the X component of velocity. */

    spkez_(&svtarg, et, svref, svcorr, &svobs, state, &lt, (ftnlen)32, (
	    ftnlen)5);
    ret_val = state[3];
    return ret_val;
/* $Procedure T_GETDY ( Test utility, get velocity Y component ) */

L_t_getdy:
/* $ Abstract */

/*     Return Y component of velocity vector at ET. */

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

/*     SPK */

/* $ Keywords */

/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      ET */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Epoch. */

/* $ Detailed_Input */

/*     ET             is the time at which to evaluate the state vector */
/*                    whose Y velocity component is requested. ET is */
/*                    expressed as seconds past J2000 TDB. */

/* $ Detailed_Output */

/*     This routine returns the Y component of the velocity vector */
/*     defined by the input ET value and the saved observer, target, */
/*     reference frame, and aberration correction values initialized */
/*     by the last call to T_STCINI. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any exceptions that may be incurred by SPKEZ may be incurred */
/*        by this routine. */

/* $ Files */

/*     See the header of SPKEZ. */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*     See the test family F_ABCORR for usage examples. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 21-DEC-2007 (NJB) */

/* -& */

/*     Look up the state. Return the Y component of velocity. */

    spkez_(&svtarg, et, svref, svcorr, &svobs, state, &lt, (ftnlen)32, (
	    ftnlen)5);
    ret_val = state[4];
    return ret_val;
/* $Procedure T_GETDZ ( Test utility, get velocity Z component ) */

L_t_getdz:
/* $ Abstract */

/*     Return Z component of velocity vector at ET. */

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

/*     SPK */

/* $ Keywords */

/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      ET */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Epoch. */

/* $ Detailed_Input */

/*     ET             is the time at which to evaluate the state vector */
/*                    whose Z velocity component is requested. ET is */
/*                    expressed as seconds past J2000 TDB. */

/* $ Detailed_Output */

/*     This routine returns the Z component of the velocity vector */
/*     defined by the input ET value and the saved observer, target, */
/*     reference frame, and aberration correction values initialized */
/*     by the last call to T_STCINI. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any exceptions that may be incurred by SPKEZ may be incurred */
/*        by this routine. */

/* $ Files */

/*     See the header of SPKEZ. */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*     See the test family F_ABCORR for usage examples. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 21-DEC-2007 (NJB) */

/* -& */

/*     Look up the state. Return the Z component of velocity. */

    spkez_(&svtarg, et, svref, svcorr, &svobs, state, &lt, (ftnlen)32, (
	    ftnlen)5);
    ret_val = state[5];
    return ret_val;
/* $Procedure T_GETSX ( Test utility, get S.A. position X component ) */

L_t_getsx:
/* $ Abstract */

/*     Return X component of the stellar aberration correction */
/*     position vector at ET. */

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

/*     SPK */

/* $ Keywords */

/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      ET */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Epoch. */

/* $ Detailed_Input */

/*     ET             is the time at which to evaluate the state vector */
/*                    with which the specified stellar aberration */
/*                    correction is associated. ET is expressed as */
/*                    seconds past J2000 TDB. */

/* $ Detailed_Output */

/*     This function returns the X component of the stellar aberration */
/*     correction position vector of the state defined by the input time */
/*     ET and the parameters saved from the last call to the */
/*     initialization entry point T_STCINI. */

/*     The stellar aberration correction position vector is the */
/*     difference between the geometric or light time corrected position */
/*     computed by SPKTLC for the given inputs, and this position after */
/*     the stellar aberration correction has been applied. */

/*     Note that if the saved aberration correction is NONE, than the */
/*     stellar aberration correction will be applied to the geometric */
/*     state vector computed by SPKEZ. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any exceptions that may be incurred by T_GETSA may be incurred */
/*        by this routine. */

/* $ Files */

/*     See the header of SPKEZ. */

/* $ Particulars */

/*     See the test utility T_GETSA for details of how the stellar */
/*     aberration correction position vector is computed. */

/* $ Examples */

/*     See the test family F_ABCORR for usage examples. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 21-DEC-2007 (NJB) */

/* -& */

/*     Look up the stellar aberration correction offset PCORR and its */
/*     derivative with respect to time DPCORR. Return the X component of */
/*     the stellar aberration correction position offset. */

    t_getsa__(&svtarg, et, svref, svcorr, &svobs, pcorr, dpcorr, (ftnlen)32, (
	    ftnlen)5);
    ret_val = pcorr[0];
    return ret_val;
/* $Procedure T_GETSY ( Test utility, get S.A. position Y component ) */

L_t_getsy:
/* $ Abstract */

/*     Return Y component of the stellar aberration correction */
/*     position vector at ET. */

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

/*     SPK */

/* $ Keywords */

/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      ET */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Epoch. */

/* $ Detailed_Input */

/*     ET             is the time at which to evaluate the state vector */
/*                    with which the specified stellar aberration */
/*                    correction is associated. ET is expressed as */
/*                    seconds past J2000 TDB. */

/* $ Detailed_Output */

/*     This function returns the Y component of the stellar aberration */
/*     correction position vector of the state defined by the input time */
/*     ET and the parameters saved from the last call to the */
/*     initialization entry point T_STCINI. */

/*     The stellar aberration correction position vector is the */
/*     difference between the geometric or light time corrected position */
/*     computed by SPKTLC for the given inputs, and this position after */
/*     the stellar aberration correction has been applied. */

/*     Note that if the saved aberration correction is NONE, than the */
/*     stellar aberration correction will be applied to the geometric */
/*     state vector computed by SPKEZ. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any exceptions that may be incurred by T_GETSA may be incurred */
/*        by this routine. */

/* $ Files */

/*     See the header of SPKEZ. */

/* $ Particulars */

/*     See the test utility T_GETSA for details of how the stellar */
/*     aberration correction position vector is computed. */

/* $ Examples */

/*     See the test family F_ABCORR for usage examples. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 21-DEC-2007 (NJB) */

/* -& */

/*     Look up the stellar aberration correction offset PCORR and its */
/*     derivative with respect to time DPCORR. Return the Y component of */
/*     the stellar aberration correction position offset. */

    t_getsa__(&svtarg, et, svref, svcorr, &svobs, pcorr, dpcorr, (ftnlen)32, (
	    ftnlen)5);
    ret_val = pcorr[1];
    return ret_val;
/* $Procedure T_GETSZ ( Test utility, get S.A. position Z component ) */

L_t_getsz:
/* $ Abstract */

/*     Return Z component of the stellar aberration correction */
/*     position vector at ET. */

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

/*     SPK */

/* $ Keywords */

/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      ET */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Epoch. */

/* $ Detailed_Input */

/*     ET             is the time at which to evaluate the state vector */
/*                    with which the specified stellar aberration */
/*                    correction is associated. ET is expressed as */
/*                    seconds past J2000 TDB. */

/* $ Detailed_Output */

/*     This function returns the Z component of the stellar aberration */
/*     correction position vector of the state defined by the input time */
/*     ET and the parameters saved from the last call to the */
/*     initialization entry point T_STCINI. */

/*     The stellar aberration correction position vector is the */
/*     difference between the geometric or light time corrected position */
/*     computed by SPKTLC for the given inputs, and this position after */
/*     the stellar aberration correction has been applied. */

/*     Note that if the saved aberration correction is NONE, than the */
/*     stellar aberration correction will be applied to the geometric */
/*     state vector computed by SPKEZ. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any exceptions that may be incurred by T_GETSA may be incurred */
/*        by this routine. */

/* $ Files */

/*     See the header of SPKEZ. */

/* $ Particulars */

/*     See the test utility T_GETSA for details of how the stellar */
/*     aberration correction position vector is computed. */

/* $ Examples */

/*     See the test family F_ABCORR for usage examples. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 21-DEC-2007 (NJB) */

/* -& */

/*     Look up the stellar aberration correction offset PCORR and its */
/*     derivative with respect to time DPCORR. Return the Z component of */
/*     the stellar aberration correction position offset. */

    t_getsa__(&svtarg, et, svref, svcorr, &svobs, pcorr, dpcorr, (ftnlen)32, (
	    ftnlen)5);
    ret_val = pcorr[2];
    return ret_val;
/* $Procedure T_GETDSX ( Test utility, get S.A. velocity X component ) */

L_t_getdsx:
/* $ Abstract */

/*     Return X component of the stellar aberration correction */
/*     velocity vector at ET. */

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

/*     SPK */

/* $ Keywords */

/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      ET */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Epoch. */

/* $ Detailed_Input */

/*     ET             is the time at which to evaluate the state vector */
/*                    with which the specified stellar aberration */
/*                    correction is associated. ET is expressed as */
/*                    seconds past J2000 TDB. */

/* $ Detailed_Output */

/*     This function returns the X component of the stellar aberration */
/*     correction velocity vector of the state defined by the input time */
/*     ET and the parameters saved from the last call to the */
/*     initialization entry point T_STCINI. */

/*     The stellar aberration correction position vector is the */
/*     difference between the geometric or light time corrected position */
/*     computed by SPKTLC for the given inputs, and this position after */
/*     the stellar aberration correction has been applied. The stellar */
/*     aberration correction velocity vector is simply the derivative */
/*     with respect to time (TDB) of this position vector. */

/*     Note that if the saved aberration correction is NONE, than the */
/*     stellar aberration correction will be applied to the geometric */
/*     state vector computed by SPKEZ. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any exceptions that may be incurred by T_GETSA may be incurred */
/*        by this routine. */

/* $ Files */

/*     See the header of SPKEZ. */

/* $ Particulars */

/*     See the test utility T_GETSA for details of how the stellar */
/*     aberration correction velocity vector is computed. */

/* $ Examples */

/*     See the test family F_ABCORR for usage examples. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 21-DEC-2007 (NJB) */

/* -& */

/*     Look up the stellar aberration correction offset PCORR and its */
/*     derivative with respect to time DPCORR. Return the X component of */
/*     the stellar aberration correction velocity offset. */

    t_getsa__(&svtarg, et, svref, svcorr, &svobs, pcorr, dpcorr, (ftnlen)32, (
	    ftnlen)5);
    ret_val = dpcorr[0];
    return ret_val;
/* $Procedure T_GETDSY ( Test utility, get S.A. velocity Y component ) */

L_t_getdsy:
/* $ Abstract */

/*     Return Y component of the stellar aberration correction */
/*     velocity vector at ET. */

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

/*     SPK */

/* $ Keywords */

/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      ET */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Epoch. */

/* $ Detailed_Input */

/*     ET             is the time at which to evaluate the state vector */
/*                    with which the specified stellar aberration */
/*                    correction is associated. ET is expressed as */
/*                    seconds past J2000 TDB. */

/* $ Detailed_Output */

/*     This function returns the Y component of the stellar aberration */
/*     correction velocity vector of the state defined by the input time */
/*     ET and the parameters saved from the last call to the */
/*     initialization entry point T_STCINI. */

/*     The stellar aberration correction position vector is the */
/*     difference between the geometric or light time corrected position */
/*     computed by SPKTLC for the given inputs, and this position after */
/*     the stellar aberration correction has been applied. The stellar */
/*     aberration correction velocity vector is simply the derivative */
/*     with respect to time (TDB) of this position vector. */

/*     Note that if the saved aberration correction is NONE, than the */
/*     stellar aberration correction will be applied to the geometric */
/*     state vector computed by SPKEZ. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any exceptions that may be incurred by T_GETSA may be incurred */
/*        by this routine. */

/* $ Files */

/*     See the header of SPKEZ. */

/* $ Particulars */

/*     See the test utility T_GETSA for details of how the stellar */
/*     aberration correction velocity vector is computed. */

/* $ Examples */

/*     See the test family F_ABCORR for usage examples. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 21-DEC-2007 (NJB) */

/* -& */

/*     Look up the stellar aberration correction offset PCORR and its */
/*     derivative with respect to time DPCORR. Return the Y component of */
/*     the stellar aberration correction velocity offset. */

    t_getsa__(&svtarg, et, svref, svcorr, &svobs, pcorr, dpcorr, (ftnlen)32, (
	    ftnlen)5);
    ret_val = dpcorr[1];
    return ret_val;
/* $Procedure T_GETDSZ ( Test utility, get S.A. velocity Z component ) */

L_t_getdsz:
/* $ Abstract */

/*     Return Z component of the stellar aberration correction */
/*     velocity vector at ET. */

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

/*     SPK */

/* $ Keywords */

/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      ET */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Epoch. */

/* $ Detailed_Input */

/*     ET             is the time at which to evaluate the state vector */
/*                    with which the specified stellar aberration */
/*                    correction is associated. ET is expressed as */
/*                    seconds past J2000 TDB. */

/* $ Detailed_Output */

/*     This function returns the Z component of the stellar aberration */
/*     correction velocity vector of the state defined by the input time */
/*     ET and the parameters saved from the last call to the */
/*     initialization entry point T_STCINI. */

/*     The stellar aberration correction position vector is the */
/*     difference between the geometric or light time corrected position */
/*     computed by SPKTLC for the given inputs, and this position after */
/*     the stellar aberration correction has been applied. The stellar */
/*     aberration correction velocity vector is simply the derivative */
/*     with respect to time (TDB) of this position vector. */

/*     Note that if the saved aberration correction is NONE, than the */
/*     stellar aberration correction will be applied to the geometric */
/*     state vector computed by SPKEZ. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any exceptions that may be incurred by T_GETSA may be incurred */
/*        by this routine. */

/* $ Files */

/*     See the header of SPKEZ. */

/* $ Particulars */

/*     See the test utility T_GETSA for details of how the stellar */
/*     aberration correction velocity vector is computed. */

/* $ Examples */

/*     See the test family F_ABCORR for usage examples. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 21-DEC-2007 (NJB) */

/* -& */

/*     Look up the stellar aberration correction offset PCORR and its */
/*     derivative with respect to time DPCORR. Return the Z component of */
/*     the stellar aberration correction velocity offset. */

    t_getsa__(&svtarg, et, svref, svcorr, &svobs, pcorr, dpcorr, (ftnlen)32, (
	    ftnlen)5);
    ret_val = dpcorr[2];
    return ret_val;
/* $Procedure T_GETLT ( Test utility, get light time ) */

L_t_getlt:
/* $ Abstract */

/*     Return observer-target light time at ET. */

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

/*     SPK */

/* $ Keywords */

/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      ET */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Epoch. */

/* $ Detailed_Input */

/*     ET             is the time at which to evaluate the state vector */
/*                    with which the requested light time is associated. */
/*                    ET is expressed as seconds past J2000 TDB. */

/* $ Detailed_Output */

/*     This routine returns the one-way light time defined by the input */
/*     ET value and the saved observer, target, reference frame, and */
/*     aberration correction values initialized by the last call to */
/*     T_STCINI. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any exceptions that may be incurred by SPKLTC may be incurred */
/*        by this routine. */

/* $ Files */

/*     See the header of SPKEZ. */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*     See the test family F_ABCORR for usage examples. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 21-DEC-2007 (NJB) */

/* -& */

/*     Look up the light time corrected state, along with */
/*     the light time and the light time rate. Return the light */
/*     time. */

    spkssb_(&svobs, et, svref, stobs, (ftnlen)32);
    spkltc_(&svtarg, et, svref, svcorr, stobs, state, &lt, &dlt, (ftnlen)32, (
	    ftnlen)5);
    ret_val = lt;
    return ret_val;
/* $Procedure T_GETDLT ( Test utility, get light time rate ) */

L_t_getdlt:
/* $ Abstract */

/*     Return observer-target light time rate at ET. */

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

/*     SPK */

/* $ Keywords */

/*     TEST */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      ET */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ET         I   Epoch. */

/* $ Detailed_Input */

/*     ET             is the time at which to evaluate the state vector */
/*                    with which the requested light time rate is */
/*                    associated. ET is expressed as seconds past J2000 */
/*                    TDB. */

/* $ Detailed_Output */

/*     This function returns the rate---that is, the derivative with */
/*     respect to time (TDB)---of one way light time associated with the */
/*     state defined by the input time ET and the parameters saved from */
/*     the last call to the initialization entry point T_STCINI. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) Any exceptions that may be incurred by SPKLTC may be incurred */
/*        by this routine. */

/* $ Files */

/*     See the header of SPKEZ. */

/* $ Particulars */

/*     The terms "rate" and "derivative with respect to time" are */
/*     synonyms. */

/* $ Examples */

/*     See the test family F_ABCORR for usage examples. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */

/* $ Version */

/* -    TESTUTIL Version 1.0.0, 21-DEC-2007 (NJB) */

/* -& */

/*     Look up the light time corrected state, along with */
/*     the light time and the light time rate. Return the light */
/*     time rate. */

    spkssb_(&svobs, et, svref, stobs, (ftnlen)32);
    spkltc_(&svtarg, et, svref, svcorr, stobs, state, &lt, &dlt, (ftnlen)32, (
	    ftnlen)5);
    ret_val = dlt;
    return ret_val;
} /* t_trajfn__ */

doublereal t_trajfn__(integer *targ, doublereal *et, char *ref, char *abcorr, 
	integer *obs, ftnlen ref_len, ftnlen abcorr_len)
{
    return t_trajfn__0_(0, targ, et, ref, abcorr, obs, ref_len, abcorr_len);
    }

doublereal t_stcini__(integer *targ, char *ref, char *abcorr, integer *obs, 
	ftnlen ref_len, ftnlen abcorr_len)
{
    return t_trajfn__0_(1, targ, (doublereal *)0, ref, abcorr, obs, ref_len, 
	    abcorr_len);
    }

doublereal t_getx__(doublereal *et)
{
    return t_trajfn__0_(2, (integer *)0, et, (char *)0, (char *)0, (integer *)
	    0, (ftnint)0, (ftnint)0);
    }

doublereal t_gety__(doublereal *et)
{
    return t_trajfn__0_(3, (integer *)0, et, (char *)0, (char *)0, (integer *)
	    0, (ftnint)0, (ftnint)0);
    }

doublereal t_getz__(doublereal *et)
{
    return t_trajfn__0_(4, (integer *)0, et, (char *)0, (char *)0, (integer *)
	    0, (ftnint)0, (ftnint)0);
    }

doublereal t_getdx__(doublereal *et)
{
    return t_trajfn__0_(5, (integer *)0, et, (char *)0, (char *)0, (integer *)
	    0, (ftnint)0, (ftnint)0);
    }

doublereal t_getdy__(doublereal *et)
{
    return t_trajfn__0_(6, (integer *)0, et, (char *)0, (char *)0, (integer *)
	    0, (ftnint)0, (ftnint)0);
    }

doublereal t_getdz__(doublereal *et)
{
    return t_trajfn__0_(7, (integer *)0, et, (char *)0, (char *)0, (integer *)
	    0, (ftnint)0, (ftnint)0);
    }

doublereal t_getsx__(doublereal *et)
{
    return t_trajfn__0_(8, (integer *)0, et, (char *)0, (char *)0, (integer *)
	    0, (ftnint)0, (ftnint)0);
    }

doublereal t_getsy__(doublereal *et)
{
    return t_trajfn__0_(9, (integer *)0, et, (char *)0, (char *)0, (integer *)
	    0, (ftnint)0, (ftnint)0);
    }

doublereal t_getsz__(doublereal *et)
{
    return t_trajfn__0_(10, (integer *)0, et, (char *)0, (char *)0, (integer *
	    )0, (ftnint)0, (ftnint)0);
    }

doublereal t_getdsx__(doublereal *et)
{
    return t_trajfn__0_(11, (integer *)0, et, (char *)0, (char *)0, (integer *
	    )0, (ftnint)0, (ftnint)0);
    }

doublereal t_getdsy__(doublereal *et)
{
    return t_trajfn__0_(12, (integer *)0, et, (char *)0, (char *)0, (integer *
	    )0, (ftnint)0, (ftnint)0);
    }

doublereal t_getdsz__(doublereal *et)
{
    return t_trajfn__0_(13, (integer *)0, et, (char *)0, (char *)0, (integer *
	    )0, (ftnint)0, (ftnint)0);
    }

doublereal t_getlt__(doublereal *et)
{
    return t_trajfn__0_(14, (integer *)0, et, (char *)0, (char *)0, (integer *
	    )0, (ftnint)0, (ftnint)0);
    }

doublereal t_getdlt__(doublereal *et)
{
    return t_trajfn__0_(15, (integer *)0, et, (char *)0, (char *)0, (integer *
	    )0, (ftnint)0, (ftnint)0);
    }

