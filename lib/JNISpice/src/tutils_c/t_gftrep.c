/* t_gftrep.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c_b6 = 300000;
static integer c__20000 = 20000;
static integer c__20 = 20;
static integer c_b17 = 100000;

/* $Procedure      T_GFTREP ( GF, progress report test utilities ) */
/* Subroutine */ int t_gftrep__0_(int n__, doublereal *cnfine, char *msgpre, 
	char *msgsuf, doublereal *ivbeg, doublereal *ivend, doublereal *et, 
	integer *nmax, integer *mw, integer *ncalls, doublereal *cnflog, char 
	*msglog, doublereal *replog, integer *seqlog, ftnlen msgpre_len, 
	ftnlen msgsuf_len, ftnlen msglog_len)
{
    /* System generated locals */
    integer cnflog_dim1, cnflog_offset, i__1, i__2;

    /* Builtin functions */
    integer s_rnge(char *, integer, char *, integer);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int chkin_(char *, ftnlen), copyd_(doublereal *, 
	    doublereal *), movei_(integer *, integer *, integer *), cleard_(
	    integer *, doublereal *), cleari_(integer *, integer *), sigerr_(
	    char *, ftnlen);
    static doublereal svcnfn[400120]	/* was [20006][20] */;
    extern /* Subroutine */ int chkout_(char *, ftnlen), ssized_(integer *, 
	    doublereal *), setmsg_(char *, ftnlen);
    static integer svnfin, svnini, svfseq[20];
    extern /* Subroutine */ int errint_(char *, integer *, ftnlen);
    static integer sviseq[20];
    static char svmslg[32*2*20];
    static doublereal svulog[300000]	/* was [3][100000] */;
    static integer svnupd, svuseq[100000], svsqix;

/* $ Abstract */

/*     Umbrella routine for GF progress report test utilities. */

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

/*     GF */
/*     TIME */

/* $ Keywords */

/*     GEOMETRY */
/*     SEARCH */
/*     UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     VARIABLE  I/O  Entry points */
/*     --------  ---  -------------------------------------------------- */
/*     CNFINE     I   T_GFREPI */
/*     MSGPRE     I   T_GFREPI */
/*     MSGSUF     I   T_GFREPI */
/*     IVBEG      I   T_GFREPU */
/*     IVEND      I   T_GFREPU */
/*     ET         I   T_GFREPU */
/*     NMAX       I   T_GFRINI, T_GFRPLO, T_GFRTRM */
/*     MW         I   T_GFRINI */
/*     NCALLS     O   T_GFRINI, T_GFRPLO, T_GFRTRM */
/*     CNFLOG     O   T_GFRINI */
/*     MSGLOG     O   T_GFRINI */
/*     REPLOG     O   T_GFRPLO */
/*     SEQLOG     O   T_GFRINI, T_GFRPLO, T_GFRTRM */

/* $ Detailed_Input */

/*     See the entry points. */

/* $ Detailed_Output */

/*     See the entry points. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If this routine is called directly, the error SPICE(BOGUSENTRY) */
/*        is signaled. */

/*     See the entry points for discussions of exceptions handled by */
/*     those routines. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This test utility package enables TSPICE to verify that the GF */
/*     system makes correct calls to either the default progress */
/*     reporting routines */

/*        GFREPI */
/*        GFREPU */
/*        GFREPF */

/*     or to their user-supplied replacements. These utilities */
/*     support logging of and retrieval of arguments passed to */
/*     progress reporting routines. */

/*     This umbrella routine contains the following entry points: */
/*        T_GFUINI ( Utility initialization ) */
/*        T_GFREPI ( GFREPI replacement ) */
/*        T_GFREPU ( GFREPU replacement ) */
/*        T_GFREPF ( GFREPF replacement ) */
/*        T_GFRINI ( return progress report initial values ) */
/*        T_GFRPLO ( return progress report log ) */
/*        T_GFRTRM ( return termination log ) */

/* $ Examples */

/*     See usage in F_GFDIRP. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     E.D. Wright    (JPL) */

/* $ Version */

/* -    SPICELIB version 1.0.0 23-FEB-2009 (NJB) (EDW) */

/* -& */
/* $ Index_Entries */

/*     GF progress report test utilities */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     Saved variables */


/*     Save everything. */

    /* Parameter adjustments */
    if (cnfine) {
	}
    if (cnflog) {
	cnflog_dim1 = *mw + 6;
	cnflog_offset = cnflog_dim1 - 5;
	}
    if (msglog) {
	}
    if (replog) {
	}
    if (seqlog) {
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_t_gfuini;
	case 2: goto L_t_gfrepi;
	case 3: goto L_t_gfrini;
	case 4: goto L_t_gfrepu;
	case 5: goto L_t_gfrplo;
	case 6: goto L_t_gfrepf;
	case 7: goto L_t_gfrtrm;
	}

    chkin_("T_GFTREP", (ftnlen)8);
    sigerr_("SPICE(BOGUSENTRY)", (ftnlen)17);
    chkout_("T_GFTREP", (ftnlen)8);
    return 0;
/* $Procedure  T_GFUNIN ( GF, progress report test utility init ) */

L_t_gfuini:
/* $ Abstract */

/*     Initialize GF progress report test utilities. */

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

/*     GF */
/*     TIME */

/* $ Keywords */

/*     GEOMETRY */
/*     SEARCH */
/*     UTILITY */

/* $ Declarations */

/*     None. */

/* $ Brief_I/O */

/*     VARIABLE  I/O  Description */
/*     --------  ---  -------------------------------------------------- */

/*     None. */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     None. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine sets initial values for saved data shared */
/*     by routines in this test utility package. */

/*     This routine should be called prior to each GF search */
/*     conducted by any test program using these utilities. */

/* $ Examples */

/*     See usage in F_GFDIRP. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     E.D. Wright    (JPL) */

/* $ Version */

/* -    SPICELIB version 1.0.0 23-FEB-2009 (NJB) (EDW) */

/* -& */
/* $ Index_Entries */

/*     GF progress report test utility initialization */

/* -& */
    chkin_("T_GFUINI", (ftnlen)8);
    svnini = 0;
    svnupd = 0;
    svnfin = 0;
    cleard_(&c_b6, svulog);
    for (i__ = 1; i__ <= 20; ++i__) {
	ssized_(&c__20000, &svcnfn[(i__1 = i__ * 20006 - 20006) < 400120 && 0 
		<= i__1 ? i__1 : s_rnge("svcnfn", i__1, "t_gftrep__", (ftnlen)
		342)]);
	s_copy(svmslg + (((i__1 = (i__ << 1) - 2) < 40 && 0 <= i__1 ? i__1 : 
		s_rnge("svmslg", i__1, "t_gftrep__", (ftnlen)344)) << 5), 
		" ", (ftnlen)32, (ftnlen)1);
	s_copy(svmslg + (((i__1 = (i__ << 1) - 1) < 40 && 0 <= i__1 ? i__1 : 
		s_rnge("svmslg", i__1, "t_gftrep__", (ftnlen)345)) << 5), 
		" ", (ftnlen)32, (ftnlen)1);
    }
    svsqix = 0;
    cleari_(&c__20, sviseq);
    cleari_(&c_b17, svuseq);
    cleari_(&c__20, svfseq);
    chkout_("T_GFUINI", (ftnlen)8);
    return 0;
/* $Procedure  T_GFREPI ( GF, GFREPI stand-in ) */

L_t_gfrepi:
/* $ Abstract */

/*     This is an instrumented replacement for GFREPI: this routine */
/*     logs its inputs so they may be examined after the completion */
/*     of a GF search. */

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

/*     GF */
/*     TIME */

/* $ Keywords */

/*     GEOMETRY */
/*     SEARCH */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      CNFINE ( LBCELL : * ) */
/*     CHARACTER*(*)         MSGPRE */
/*     CHARACTER*(*)         MSGSUF */

/* $ Brief_I/O */

/*     VARIABLE  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     CNFINE     I   Confinement window. */
/*     MSGPRE     I   Message prefix. */
/*     MSGSUF     I   Message suffix. */

/* $ Detailed_Input */

/*     CNFINE     is the confinement window over which a GF search */
/*                is to be performed. */

/*     MSGPRE     is a progress report prefix. */

/*     MSGSUF     is a progress report suffix. */

/* $ Detailed_Output */

/*     None. See Particulars. */

/* $ Parameters */

/*     MXPASS     is the maximum number of calls that can be made to */
/*                this routine during one GF search. Normally this */
/*                routine is called once per search pass. */

/* $ Exceptions */

/*     1) If the input confinement window has cardinality larger */
/*        than the size of the windows in the confinement window */
/*        buffer, the error will be diagnosed by routines in */
/*        the call tree of this routine. */

/*     2) If more than MXPASS calls are made to this routine */
/*        since the last call to T_GFUINI, the error SPICE(OVERFLOW) */
/*        is signaled. */

/*     3) If this routine is called before the initialization */
/*        routine T_GFUINI is called, the behavior of this */
/*        system will be undefined. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine should be used in place of GFREPI by test families */
/*     that examine progress reports created by mid-level GF search */
/*     routines. */

/*     Values stored by this routine may be retrieved by calling */

/*        T_GFRINI */

/* $ Examples */

/*     See usage in F_GFDIRP. */

/* $ Restrictions */

/*     1) This routine relies on fixed dimension buffers. See the */
/*        implementation and declarations in the umbrella routine */
/*        for details. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     E.D. Wright    (JPL) */

/* $ Version */

/* -    SPICELIB version 1.0.0 23-FEB-2009 (NJB) (EDW) */

/* -& */
/* $ Index_Entries */

/*     GF progress report initialization stand-in */

/* -& */
    chkin_("T_GFREPI", (ftnlen)8);

/*     Increment the progress report initialization count. */

    ++svnini;
    if (svnini > 20) {
	setmsg_("Too many initialization calls: number of progress reporting"
		" initialization calls (to T_GRREPI) since setup is #; room i"
		"n static T_GFTREP buffers is #.", (ftnlen)150);
	errint_("#", &svnini, (ftnlen)1);
	errint_("#", &c__20, (ftnlen)1);
	sigerr_("SPICE(OVERFLOW)", (ftnlen)15);
	chkout_("T_GFREPI", (ftnlen)8);
	return 0;
    }

/*     Increment the call sequence index, and save this */
/*     index in the initialization sequence log. */

    ++svsqix;
    sviseq[(i__1 = svnini - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge("sviseq", 
	    i__1, "t_gftrep__", (ftnlen)526)] = svsqix;

/*     Store the inputs in the initialization log. */

    copyd_(cnfine, &svcnfn[(i__1 = svnini * 20006 - 20006) < 400120 && 0 <= 
	    i__1 ? i__1 : s_rnge("svcnfn", i__1, "t_gftrep__", (ftnlen)531)]);
    s_copy(svmslg + (((i__1 = (svnini << 1) - 2) < 40 && 0 <= i__1 ? i__1 : 
	    s_rnge("svmslg", i__1, "t_gftrep__", (ftnlen)533)) << 5), msgpre, 
	    (ftnlen)32, msgpre_len);
    s_copy(svmslg + (((i__1 = (svnini << 1) - 1) < 40 && 0 <= i__1 ? i__1 : 
	    s_rnge("svmslg", i__1, "t_gftrep__", (ftnlen)534)) << 5), msgsuf, 
	    (ftnlen)32, msgsuf_len);
    chkout_("T_GFREPI", (ftnlen)8);
    return 0;
/* $Procedure  T_GFRINI ( GF, return values passed to T_GFREPI ) */

L_t_gfrini:
/* $ Abstract */

/*     Return values passed to T_GFREPI during a search, along with */
/*     call sequence indices. */

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

/*     GF */
/*     TIME */

/* $ Keywords */

/*     GEOMETRY */
/*     SEARCH */
/*     UTILITY */

/* $ Declarations */

/*     INTEGER               NMAX */
/*     INTEGER               MW */
/*     INTEGER               NCALLS */
/*     INTEGER               SEQLOG ( * ) */
/*     DOUBLE PRECISION      CNFLOG ( LBCELL : MW, * ) */
/*     CHARACTER*(*)         MSGLOG ( 2, * ) */

/* $ Brief_I/O */

/*     VARIABLE  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     NMAX       I   Maximum number of log entries to return. */
/*     MW         I   Confinement window size. */
/*     NCALLS     O   Number of T_GFREPI calls made during run. */
/*     SEQLOG     O   Log of T_GFREPI call sequence numbers. */
/*     CNFLOG     O   Log of confinement windows. */
/*     MSGLOG     O   Log of progress report messages. */

/* $ Detailed_Input */

/*     NMAX       is the maximum number of log records that can be */
/*                accommodated in the output arrays. NMAX should always */
/*                be set to a value at least equal to MXPASS. */

/*     MW         is the declared length of the windows in the */
/*                output confinement window log. */


/* $ Detailed_Output */

/*     NCALLS     is the number of calls to T_GFREPI made during a */
/*                search. This count is reset to 0 every time the */
/*                utility initialization entry point T_GFUINI is */
/*                called. */

/*     SEQLOG     is a log of sequence numbers of the calls to */
/*                the routine T_GFREPI made during a test run. Sequence */
/*                numbers start at one and are monotone increasing. */
/*                Sequence numbers of the calls to to T_GFREPI, */
/*                T_GFREPU, and T_GFREPF form a consecutive sequence. */
/*                Normal GF progress reporting involves a sequence of */
/*                calls, for each search pass, having the pattern: */

/*                   T_GFREPI (once) */
/*                   T_GFREPU (multiple calls) */
/*                   T_GFREPF (once) */

/*     CNFLOG    is a log of confinement windows passed to T_GFREPI */
/*               during a search. This array has dimensions */

/*                  ( LBCELL : MW, * ) */

/*     MSGLOG    is a log of progress report prefix and suffix */
/*               messages. One pair of messages is stored for each */
/*               call made to T_GFREPI during a search pass. */


/* $ Parameters */

/*     MXPASS     is the maximum number of calls that can be made to */
/*                T_GFREPI during one GF search. Normally T_GFREPI */
/*                is called once per search pass. */

/* $ Exceptions */

/*     1) If NMAX is smaller than the declared length of the */
/*        static arrays used by this routine to store report */
/*        logs, the error SPICE(BUG) will be signaled. */

/*     2) If this routine is called before the initialization */
/*        routine T_GFUINI is called, the behavior of this */
/*        system will be undefined. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine enables checking of the progress report confinement */
/*     windows and messages passed into the progress report */
/*     initialization routine T_GFREPI. */

/* $ Examples */

/*     See usage in F_GFDIRP. */

/* $ Restrictions */

/*     1) This routine relies on fixed dimension buffers. See the */
/*        implementation and declarations in the umbrella routine */
/*        for details. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     E.D. Wright    (JPL) */

/* $ Version */

/* -    SPICELIB version 1.0.0 23-FEB-2009 (NJB) (EDW) */

/* -& */
/* $ Index_Entries */

/*     return GF progress report initialization log */

/* -& */
    chkin_("T_GFRINI", (ftnlen)8);

/*     Make sure we have room for the output. */

    if (svnini > *nmax) {
	setmsg_("Number of progress reporting initialization calls (to T_GRR"
		"EPI) since setup is #; room in output buffer is #.", (ftnlen)
		109);
	errint_("#", &svnini, (ftnlen)1);
	errint_("#", nmax, (ftnlen)1);
	sigerr_("SPICE(BUG)", (ftnlen)10);
	chkout_("T_GFRINI", (ftnlen)8);
	return 0;
    }

/*     Set the outputs: */

/*        - Number of calls to T_GFREPI */
/*        - Sequence numbers of the calls to T_GFREPI */
/*        - Input confinement windows */
/*        - Input messages */

    *ncalls = svnini;
    movei_(sviseq, &svnini, seqlog);
    i__1 = svnini;
    for (i__ = 1; i__ <= i__1; ++i__) {
	copyd_(&svcnfn[(i__2 = i__ * 20006 - 20006) < 400120 && 0 <= i__2 ? 
		i__2 : s_rnge("svcnfn", i__2, "t_gftrep__", (ftnlen)737)], &
		cnflog[i__ * cnflog_dim1 - 5 - cnflog_offset]);
	s_copy(msglog + ((i__ << 1) - 2) * msglog_len, svmslg + (((i__2 = (
		i__ << 1) - 2) < 40 && 0 <= i__2 ? i__2 : s_rnge("svmslg", 
		i__2, "t_gftrep__", (ftnlen)739)) << 5), msglog_len, (ftnlen)
		32);
	s_copy(msglog + ((i__ << 1) - 1) * msglog_len, svmslg + (((i__2 = (
		i__ << 1) - 1) < 40 && 0 <= i__2 ? i__2 : s_rnge("svmslg", 
		i__2, "t_gftrep__", (ftnlen)740)) << 5), msglog_len, (ftnlen)
		32);
    }
    chkout_("T_GFRINI", (ftnlen)8);
    return 0;
/* $Procedure  T_GFREPU ( GF, GFREPU stand-in ) */

L_t_gfrepu:
/* $ Abstract */

/*     This is an instrumented replacement for GFREPU: this routine */
/*     logs its inputs so they may be examined after the completion */
/*     of a GF search. */

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

/*     GF */
/*     TIME */

/* $ Keywords */

/*     GEOMETRY */
/*     SEARCH */
/*     UTILITY */

/* $ Declarations */

/*     DOUBLE PRECISION      IVBEG */
/*     DOUBLE PRECISION      IVEND */
/*     DOUBLE PRECISION      ET */

/* $ Brief_I/O */

/*     VARIABLE  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     IVBEG      I   Interval start time. */
/*     IVEND      I   Interval end time. */
/*     ET         I   Current time. */

/* $ Detailed_Input */

/*     IVBEG, */
/*     IVEND      are, respectively, the start and stop time of an */
/*                interval traversed during progress reporting. */

/*     ET         is a time within the interval [IVBEG, IVEND]. */

/* $ Detailed_Output */

/*     None. See Particulars. */

/* $ Parameters */

/*     MAXLOG     is the maximum number of calls that can be made to */
/*                this routine during one search. Normally this */
/*                routine is called multiple times per GF search pass. */

/* $ Exceptions */

/*     1) If more than MAXLOG calls are made to this routine */
/*        since the last call to T_GFUINI, the error SPICE(OVERFLOW) */
/*        is signaled. */

/*     2) If this routine is called before the initialization */
/*        routine T_GFUINI is called, the behavior of this */
/*        system will be undefined. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine should be used in place of GFREPU by test families */
/*     that examine progress reports created by mid-level GF search */
/*     routines. */

/*     Values stored by this routine may be retrieved by calling */

/*        T_GFRPLO */

/* $ Examples */

/*     See usage in F_GFDIRP. */

/* $ Restrictions */

/*     1) This routine relies on fixed dimension buffers. See the */
/*        implementation and declarations in the umbrella routine */
/*        for details. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     E.D. Wright    (JPL) */

/* $ Version */

/* -    SPICELIB version 1.0.0 23-FEB-2009 (NJB) (EDW) */

/* -& */
/* $ Index_Entries */

/*     GF progress report update stand-in */

/* -& */
    chkin_("T_GFREPU", (ftnlen)8);

/*     Increment the progress report update count. */

    ++svnupd;
    if (svnupd > 100000) {
	setmsg_("Too many update calls: number of progress reporting update "
		"calls (to T_GRREPU) since setup is #; room in static T_GFTRE"
		"P buffers is #.", (ftnlen)134);
	errint_("#", &svnupd, (ftnlen)1);
	errint_("#", &c_b17, (ftnlen)1);
	sigerr_("SPICE(OVERFLOW)", (ftnlen)15);
	chkout_("T_GFREPU", (ftnlen)8);
	return 0;
    }

/*     Increment the call sequence index, and save this */
/*     index in the update sequence log. */

    ++svsqix;
    svuseq[(i__1 = svnupd - 1) < 100000 && 0 <= i__1 ? i__1 : s_rnge("svuseq",
	     i__1, "t_gftrep__", (ftnlen)913)] = svsqix;

/*     Store the inputs in the update log. */

    svulog[(i__1 = svnupd * 3 - 3) < 300000 && 0 <= i__1 ? i__1 : s_rnge(
	    "svulog", i__1, "t_gftrep__", (ftnlen)918)] = *ivbeg;
    svulog[(i__1 = svnupd * 3 - 2) < 300000 && 0 <= i__1 ? i__1 : s_rnge(
	    "svulog", i__1, "t_gftrep__", (ftnlen)919)] = *ivend;
    svulog[(i__1 = svnupd * 3 - 1) < 300000 && 0 <= i__1 ? i__1 : s_rnge(
	    "svulog", i__1, "t_gftrep__", (ftnlen)920)] = *et;
    chkout_("T_GFREPU", (ftnlen)8);
    return 0;
/* $Procedure  T_GFRPLO ( GF, return values passed to T_GFREPU ) */

L_t_gfrplo:
/* $ Abstract */


/*     Return values passed to T_GFREPU, along with call sequence */
/*     indices. */

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

/*     GF */
/*     TIME */

/* $ Keywords */

/*     GEOMETRY */
/*     SEARCH */
/*     UTILITY */

/* $ Declarations */

/*     INTEGER               NMAX */
/*     INTEGER               NCALLS */
/*     INTEGER               SEQLOG ( * ) */
/*     DOUBLE PRECISION      REPLOG ( 3, * ) */

/* $ Brief_I/O */

/*     VARIABLE  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     NMAX       I   Maximum number of log entries to return. */
/*     NCALLS     O   Number of T_GFREPI calls made during run. */
/*     SEQLOG     O   Log of T_GFREPI call sequence numbers. */
/*     REPLOG     O   Log of progress update intervals and times. */

/* $ Detailed_Input */

/*     NMAX       is the maximum number of log records that can be */
/*                accommodated in the output arrays. NMAX should always */
/*                be set to a value at least equal to MAXLOG. */

/* $ Detailed_Output */

/*     NCALLS     is the number of calls to T_GFREPI made during a */
/*                search. This count is reset to 0 every time the */
/*                utility initialization entry point T_GFUINI is */
/*                called. */

/*     SEQLOG     is a log of sequence numbers of the calls to */
/*                the routine T_GFREPU made during a test run. Sequence */
/*                numbers start at one and are monotone increasing. */
/*                Sequence numbers of the calls to to T_GFREPI, */
/*                T_GFREPU, and T_GFREPF form a consecutive sequence. */
/*                Normal GF progress reporting involves a sequence of */
/*                calls, for each search pass, having the pattern: */

/*                   T_GFREPI (once) */
/*                   T_GFREPU (multiple calls) */
/*                   T_GFREPF (once) */

/*     REPLOG    is a log of update intervals and times passed to */
/*               T_GFREPU. The Ith row of this array contains the */
/*               values passed to T_GFREPU on the Ith call since */
/*               the last utility initialization call. Within */
/*               the Ith row of this array, the consecutive elements */
/*               contain the values of IVBEG, IVEND, and ET passed */
/*               into T_GFPREP on the Ith call to T_GFREPU since */
/*               the last utility initialization call. */


/* $ Parameters */

/*     MAXLOG     is the maximum number of calls that can be made to */
/*                T_GFREPU during a search. Normally T_GFREPU is */
/*                called multiple times during one GF search pass. */

/* $ Exceptions */

/*     1) If NMAX is smaller than the declared length of the */
/*        static arrays used by this routine to store report */
/*        logs, the error SPICE(BUG) will be signaled. */

/*     2) If this routine is called before the initialization */
/*        routine T_GFUINI is called, the behavior of this */
/*        system will be undefined. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine enables checking of the progress report confinement */
/*     windows and messages passed into the progress report */
/*     initialization routine T_GFREPU. */

/* $ Examples */

/*     See usage in F_GFDIRP. */

/* $ Restrictions */

/*     1) This routine relies on fixed dimension buffers. See the */
/*        implementation and declarations in the umbrella routine */
/*        for details. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     E.D. Wright    (JPL) */

/* $ Version */

/* -    SPICELIB version 1.0.0 23-FEB-2009 (NJB) (EDW) */

/* -& */
/* $ Index_Entries */

/*     return GF progress report update log */

/* -& */
    chkin_("T_GFRPLO", (ftnlen)8);

/*     Make sure we have room for the output. */

    if (svnupd > *nmax) {
	setmsg_("Number of progress reporting update calls (to T_GRREPU) sin"
		"ce setup is #; room in buffer is #.", (ftnlen)94);
	errint_("#", &svnupd, (ftnlen)1);
	errint_("#", nmax, (ftnlen)1);
	sigerr_("SPICE(BUG)", (ftnlen)10);
	chkout_("T_GFRPLO", (ftnlen)8);
	return 0;
    }

/*     Set the outputs: */

/*        - Number of calls to T_GFREPU */

/*        - Sequence numbers of the calls to T_GFREPU */

/*        - Update log, which contains */

/*            > interval begin times */
/*            > interval end times */
/*            > ET values */

    *ncalls = svnupd;
    movei_(svuseq, &svnupd, seqlog);
    i__1 = svnupd;
    for (i__ = 1; i__ <= i__1; ++i__) {
	replog[i__ * 3 - 3] = svulog[(i__2 = i__ * 3 - 3) < 300000 && 0 <= 
		i__2 ? i__2 : s_rnge("svulog", i__2, "t_gftrep__", (ftnlen)
		1123)];
	replog[i__ * 3 - 2] = svulog[(i__2 = i__ * 3 - 2) < 300000 && 0 <= 
		i__2 ? i__2 : s_rnge("svulog", i__2, "t_gftrep__", (ftnlen)
		1124)];
	replog[i__ * 3 - 1] = svulog[(i__2 = i__ * 3 - 1) < 300000 && 0 <= 
		i__2 ? i__2 : s_rnge("svulog", i__2, "t_gftrep__", (ftnlen)
		1125)];
    }
    chkout_("T_GFRPLO", (ftnlen)8);
    return 0;
/* $Procedure  T_GFREPF ( GF, GFREPF stand-in ) */

L_t_gfrepf:
/* $ Abstract */

/*     This is an instrumented replacement for GFREPF: this routine logs */
/*     the sequence numbers of calls made to it so they may be examined */
/*     after the completion of a GF search. */

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

/*     GF */
/*     TIME */

/* $ Keywords */

/*     GEOMETRY */
/*     SEARCH */
/*     UTILITY */

/* $ Declarations */

/*     None. */

/* $ Brief_I/O */

/*     VARIABLE  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     None. */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     None. See Particulars. */

/* $ Parameters */

/*     MAXLOG     is the maximum number of calls that can be made to */
/*                this routine during one GF search. */

/* $ Exceptions */

/*     1) If more than MAXLOG calls are made to this routine */
/*        since the last call to T_GFUINI, the error SPICE(OVERFLOW) */
/*        is signaled. */

/*     2) If this routine is called before the initialization */
/*        routine T_GFUINI is called, the behavior of this */
/*        system will be undefined. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine should be used in place of GFREPF by test families */
/*     that examine progress reports created by mid-level GF search */
/*     routines. */

/*     Values stored by this routine may be retrieved by calling */

/*        T_GFRTRM */

/* $ Examples */

/*     See usage in F_GFDIRP. */

/* $ Restrictions */

/*     1) This routine relies on fixed dimension buffers. See the */
/*        implementation and declarations in the umbrella routine */
/*        for details. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     E.D. Wright    (JPL) */

/* $ Version */

/* -    SPICELIB version 1.0.0 23-FEB-2009 (NJB) (EDW) */

/* -& */
/* $ Index_Entries */

/*     GF progress report termination stand-in */

/* -& */
    chkin_("T_GFREPF", (ftnlen)8);

/*     Increment the progress report termination count. */

    ++svnfin;
    if (svnfin > 100000) {
	setmsg_("Too many termination calls: number of progress reporting te"
		"rmination calls (to T_GRREPF) since setup is #; room in stat"
		"ic T_GFTREP buffers is #.", (ftnlen)144);
	errint_("#", &svnfin, (ftnlen)1);
	errint_("#", &c_b17, (ftnlen)1);
	sigerr_("SPICE(OVERFLOW)", (ftnlen)15);
	chkout_("T_GFREPF", (ftnlen)8);
	return 0;
    }

/*     Increment the call sequence index, and save this */
/*     index in the termination sequence log. */

    ++svsqix;
    svfseq[(i__1 = svnfin - 1) < 20 && 0 <= i__1 ? i__1 : s_rnge("svfseq", 
	    i__1, "t_gftrep__", (ftnlen)1289)] = svsqix;
    chkout_("T_GFREPF", (ftnlen)8);
    return 0;
/* $Procedure  T_GFRTRM ( GF, return values passed to T_GFREPU ) */

L_t_gfrtrm:
/* $ Abstract */

/*     Return call sequence indices for T_GFREPF calls. */

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

/*     GF */
/*     TIME */

/* $ Keywords */

/*     GEOMETRY */
/*     SEARCH */
/*     UTILITY */

/* $ Declarations */

/*     INTEGER               NMAX */
/*     INTEGER               NCALLS */
/*     INTEGER               SEQLOG ( * ) */

/* $ Brief_I/O */

/*     VARIABLE  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     NMAX       I   Maximum number of log entries to return. */
/*     NCALLS     O   Number of T_GFREPF calls made during run. */
/*     SEQLOG     O   Log of T_GFREPF call sequence numbers. */

/* $ Detailed_Input */

/*     NMAX       is the maximum number of log records that can be */
/*                accommodated in the output arrays. NMAX should always */
/*                be set to a value at least equal to MXPASS. */

/* $ Detailed_Output */

/*     NCALLS     is the number of calls to T_GFREPF made during a */
/*                search. This count is reset to 0 every time the */
/*                utility initialization entry point T_GFUINI is */
/*                called. */

/*     SEQLOG     is a log of sequence numbers of the calls to */
/*                the routine T_GFREPF made during a test run. Sequence */
/*                numbers start at one and are monotone increasing. */
/*                Sequence numbers of the calls to to T_GFREPI, */
/*                T_GFREPU, and T_GFREPF form a consecutive sequence. */
/*                Normal GF progress reporting involves a sequence of */
/*                calls, for each search pass, having the pattern: */

/*                   T_GFREPI (once) */
/*                   T_GFREPU (multiple calls) */
/*                   T_GFREPF (once) */


/* $ Parameters */

/*     MXPASS     is the maximum number of calls that can be made to */
/*                T_GFREPF during a search. Normally T_GFREPF is */
/*                called once per GF search pass. */

/* $ Exceptions */

/*     1) If NMAX is smaller than the declared length of the */
/*        static arrays used by this routine to store report */
/*        logs, the error SPICE(BUG) will be signaled. */

/*     2) If this routine is called before the initialization */
/*        routine T_GFUINI is called, the behavior of this */
/*        system will be undefined. */

/* $ Files */

/*     None. */

/* $ Particulars */

/*     This routine enables checking of the sequence of calls made to */
/*     the progress report termination routine T_GFREPF. */

/* $ Examples */

/*     See usage in F_GFDIRP. */

/* $ Restrictions */

/*     1) This routine relies on fixed dimension buffers. See the */
/*        implementation and declarations in the umbrella routine */
/*        for details. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman   (JPL) */
/*     E.D. Wright    (JPL) */

/* $ Version */

/* -    SPICELIB version 1.0.0 23-FEB-2009 (NJB) (EDW) */

/* -& */
/* $ Index_Entries */

/*     return GF progress report termination log */

/* -& */
    chkin_("T_GFRTRM", (ftnlen)8);

/*     Make sure we have room for the output. */

    if (svnfin > *nmax) {
	setmsg_("Number of progress reporting termination calls (to T_GRREPF"
		") since setup is #; room in buffer is #.", (ftnlen)99);
	errint_("#", &svnfin, (ftnlen)1);
	errint_("#", nmax, (ftnlen)1);
	sigerr_("SPICE(BUG)", (ftnlen)10);
	chkout_("T_GFRTRM", (ftnlen)8);
	return 0;
    }

/*     Set the outputs: */

/*        - Number of calls to T_GFRFIN */

/*        - Sequence numbers of the calls to T_GFRFIN */

    *ncalls = svnfin;
    movei_(svfseq, &svnfin, seqlog);
    chkout_("T_GFRTRM", (ftnlen)8);
    return 0;
} /* t_gftrep__ */

/* Subroutine */ int t_gftrep__(doublereal *cnfine, char *msgpre, char *
	msgsuf, doublereal *ivbeg, doublereal *ivend, doublereal *et, integer 
	*nmax, integer *mw, integer *ncalls, doublereal *cnflog, char *msglog,
	 doublereal *replog, integer *seqlog, ftnlen msgpre_len, ftnlen 
	msgsuf_len, ftnlen msglog_len)
{
    return t_gftrep__0_(0, cnfine, msgpre, msgsuf, ivbeg, ivend, et, nmax, mw,
	     ncalls, cnflog, msglog, replog, seqlog, msgpre_len, msgsuf_len, 
	    msglog_len);
    }

/* Subroutine */ int t_gfuini__(void)
{
    return t_gftrep__0_(1, (doublereal *)0, (char *)0, (char *)0, (doublereal 
	    *)0, (doublereal *)0, (doublereal *)0, (integer *)0, (integer *)0,
	     (integer *)0, (doublereal *)0, (char *)0, (doublereal *)0, (
	    integer *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

/* Subroutine */ int t_gfrepi__(doublereal *cnfine, char *msgpre, char *
	msgsuf, ftnlen msgpre_len, ftnlen msgsuf_len)
{
    return t_gftrep__0_(2, cnfine, msgpre, msgsuf, (doublereal *)0, (
	    doublereal *)0, (doublereal *)0, (integer *)0, (integer *)0, (
	    integer *)0, (doublereal *)0, (char *)0, (doublereal *)0, (
	    integer *)0, msgpre_len, msgsuf_len, (ftnint)0);
    }

/* Subroutine */ int t_gfrini__(integer *nmax, integer *mw, integer *ncalls, 
	integer *seqlog, doublereal *cnflog, char *msglog, ftnlen msglog_len)
{
    return t_gftrep__0_(3, (doublereal *)0, (char *)0, (char *)0, (doublereal 
	    *)0, (doublereal *)0, (doublereal *)0, nmax, mw, ncalls, cnflog, 
	    msglog, (doublereal *)0, seqlog, (ftnint)0, (ftnint)0, msglog_len)
	    ;
    }

/* Subroutine */ int t_gfrepu__(doublereal *ivbeg, doublereal *ivend, 
	doublereal *et)
{
    return t_gftrep__0_(4, (doublereal *)0, (char *)0, (char *)0, ivbeg, 
	    ivend, et, (integer *)0, (integer *)0, (integer *)0, (doublereal *
	    )0, (char *)0, (doublereal *)0, (integer *)0, (ftnint)0, (ftnint)
	    0, (ftnint)0);
    }

/* Subroutine */ int t_gfrplo__(integer *nmax, integer *ncalls, integer *
	seqlog, doublereal *replog)
{
    return t_gftrep__0_(5, (doublereal *)0, (char *)0, (char *)0, (doublereal 
	    *)0, (doublereal *)0, (doublereal *)0, nmax, (integer *)0, ncalls,
	     (doublereal *)0, (char *)0, replog, seqlog, (ftnint)0, (ftnint)0,
	     (ftnint)0);
    }

/* Subroutine */ int t_gfrepf__(void)
{
    return t_gftrep__0_(6, (doublereal *)0, (char *)0, (char *)0, (doublereal 
	    *)0, (doublereal *)0, (doublereal *)0, (integer *)0, (integer *)0,
	     (integer *)0, (doublereal *)0, (char *)0, (doublereal *)0, (
	    integer *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

/* Subroutine */ int t_gfrtrm__(integer *nmax, integer *ncalls, integer *
	seqlog)
{
    return t_gftrep__0_(7, (doublereal *)0, (char *)0, (char *)0, (doublereal 
	    *)0, (doublereal *)0, (doublereal *)0, nmax, (integer *)0, ncalls,
	     (doublereal *)0, (char *)0, (doublereal *)0, seqlog, (ftnint)0, (
	    ftnint)0, (ftnint)0);
    }

