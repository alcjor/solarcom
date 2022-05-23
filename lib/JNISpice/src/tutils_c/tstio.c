/* tstio.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__4 = 4;

/* $Procedure TSTIO (Test utilities IO Manager) */
/* Subroutine */ int tstio_0_(int n__, char *line, char *name__, char *port, 
	logical *ok, logical *status, ftnlen line_len, ftnlen name_len, 
	ftnlen port_len)
{
    /* Initialized data */

    static char ports[32*4] = "LOG                             " "SCREEN    "
	    "                      " "SAVE                            " "UTIL"
	    "ITY                         ";
    static char files[127*4] = "                                            "
	    "                                                                "
	    "                   " "                                          "
	    "                                                                "
	    "                     " "                                        "
	    "                                                                "
	    "                       " "                                      "
	    "                                                                "
	    "                         ";
    static integer units[4] = { 0,6,0,0 };
    static logical active[4] = { FALSE_,TRUE_,FALSE_,FALSE_ };
    static logical open[4] = { FALSE_,TRUE_,FALSE_,FALSE_ };
    static logical suspnd[4] = { FALSE_,FALSE_,FALSE_,FALSE_ };
    static logical lkport[4] = { FALSE_,FALSE_,FALSE_,FALSE_ };

    /* System generated locals */
    integer i__1, i__2;
    cllist cl__1;

    /* Builtin functions */
    integer s_rnge(char *, integer, char *, integer);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer f_clos(cllist *);

    /* Local variables */
    extern /* Subroutine */ int zztstre_(void);
    static integer r__;
    extern /* Subroutine */ int chkin_(char *, ftnlen), errch_(char *, char *,
	     ftnlen, ftnlen), repmc_(char *, char *, char *, char *, ftnlen, 
	    ftnlen, ftnlen, ftnlen), repmi_(char *, char *, integer *, char *,
	     ftnlen, ftnlen, ftnlen);
    extern integer rtrim_(char *, ftnlen);
    static integer id;
    extern logical failed_(void);
    static integer to;
    extern integer isrchc_(char *, integer *, char *, ftnlen, ftnlen);
    static char messge[400];
    extern /* Subroutine */ int sigerr_(char *, ftnlen), chkout_(char *, 
	    ftnlen), setmsg_(char *, ftnlen);
    static integer iostat;
    extern /* Subroutine */ int tostdo_(char *, ftnlen), writln_(char *, 
	    integer *, ftnlen), txtopn_(char *, integer *, ftnlen);

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


/* $ Keywords */


/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) */

/* $ Files */

/*     None. */

/* $ Particulars */


/* $ Examples */


/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */


/* $ Version */

/* -     Testing Utilities Version 1.2.1, 18-JAN-2007 (EDW) */

/*         Added addition lockout blocks to TSTPST and TSTIOC. */

/*         FINISH now calls ZZTSTRE prior to return to ensure */
/*         OPNERR has value TRUE after TCLOSE call. */

/* -     Testing Utilities Version 1.2.0, 09-MAY-2002 (EDW) */

/*         Added the LCKOUT entry mode. Routine inhibits */
/*         all output to the specified port. Primary use */
/*         prevents tspice from printing to the screen - */
/*         a quiet mode. */

/* -     Testing Utilities Version 1.1.0, 18-JUN-1999 (WLT) */

/*         Added a RETURN before the first entry point. */

/* -     Testing Utilities Version 1.0.0, 03-NOV-1994 (WLT) */

/*         This is the configured version of the Test Utility */
/*         software as of Nov 3, 1994 */

/* -& */
/* $ Index_Entries */


/* -& */

/*     Below are the various types of output files that */
/*     might be open. */


/*     Define tags for the PORTS array (defined in tstlgr.f) */
/*     indices corresponding to the log file, LOG ('LOG'), */
/*     the screen or standard out, STDOUT ('SCREEN'), */
/*     and the error log file SPOOL ('SAVE'). Note the 'SAVE' */
/*     port as defined in PORTS use the SPOOL tag because SAVE */
/*     is a FORTRAN intrinsic function. */


/*     SPICELIB functions */

    /* Parameter adjustments */
    if (status) {
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_tstopn;
	case 2: goto L_tstioh;
	case 3: goto L_tstioa;
	case 4: goto L_tstgst;
	case 5: goto L_tstpst;
	case 6: goto L_tstioc;
	case 7: goto L_tstios;
	case 8: goto L_tstior;
	case 9: goto L_tstwln;
	case 10: goto L_finish;
	case 11: goto L_lckout;
	}

    return 0;

/*     Open a new port */


L_tstopn:
/* $ Version */

/* -     Testing Utilities Version 1.0.0, 3-NOV-1994 (WLT) */

/*         This is the configured version of the Test Utility */
/*         software as of Nov 3, 1994 */

    id = isrchc_(port, &c__4, ports, port_len, (ftnlen)32);
    if (id == 0) {
	chkin_("TSTOPN", (ftnlen)6);
	setmsg_("Unrecognized port: #", (ftnlen)20);
	errch_("#", port, (ftnlen)1, port_len);
	sigerr_("TESTUTIL(BUG)", (ftnlen)13);
	chkout_("TSTOPN", (ftnlen)6);
	return 0;
    }

/*        Check for an ID lockout. */

    if (lkport[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("lkport", 
	    i__1, "tstio_", (ftnlen)221)]) {
	return 0;
    }
    r__ = rtrim_(name__, name_len);
    txtopn_(name__, &units[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge(
	    "units", i__1, "tstio_", (ftnlen)227)], r__);
    if (failed_()) {
	open[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("open", i__1, 
		"tstio_", (ftnlen)230)] = FALSE_;
	active[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("active", 
		i__1, "tstio_", (ftnlen)231)] = FALSE_;
	suspnd[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("suspnd", 
		i__1, "tstio_", (ftnlen)232)] = FALSE_;
	s_copy(files + ((i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge(
		"files", i__1, "tstio_", (ftnlen)233)) * 127, " ", (ftnlen)
		127, (ftnlen)1);
	return 0;
    }
    open[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("open", i__1, "tst"
	    "io_", (ftnlen)237)] = TRUE_;
    active[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("active", i__1, 
	    "tstio_", (ftnlen)238)] = TRUE_;
    suspnd[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("suspnd", i__1, 
	    "tstio_", (ftnlen)239)] = FALSE_;
    s_copy(files + ((i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("files", 
	    i__1, "tstio_", (ftnlen)240)) * 127, name__, (ftnlen)127, 
	    name_len);
    return 0;

/*     Inhibit output to a port. */


L_tstioh:
/* $ Version */

/* -     Testing Utilities Version 1.0.0, 3-NOV-1994 (WLT) */

/*         This is the configured version of the Test Utility */
/*         software as of Nov 3, 1994 */

    id = isrchc_(port, &c__4, ports, port_len, (ftnlen)32);
    if (id == 0) {
	chkin_("TSTIOH", (ftnlen)6);
	setmsg_("Unrecognized port: #", (ftnlen)20);
	errch_("#", port, (ftnlen)1, port_len);
	sigerr_("TESTUTIL(BUG)", (ftnlen)13);
	chkout_("TSTIOH", (ftnlen)6);
	return 0;
    }
    active[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("active", i__1, 
	    "tstio_", (ftnlen)270)] = FALSE_;
    return 0;

/*     Activate a port */


L_tstioa:
/* $ Version */

/* -     Testing Utilities Version 1.0.0, 3-NOV-1994 (WLT) */

/*         This is the configured version of the Test Utility */
/*         software as of Nov 3, 1994 */

    id = isrchc_(port, &c__4, ports, port_len, (ftnlen)32);
    if (id == 0) {
	chkin_("TSTIOA", (ftnlen)6);
	setmsg_("Unrecognized port: #", (ftnlen)20);
	errch_("#", port, (ftnlen)1, port_len);
	sigerr_("TESTUTIL(BUG)", (ftnlen)13);
	chkout_("TSTIOA", (ftnlen)6);
	return 0;
    }

/*        Check for an ID lockout. */

    if (lkport[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("lkport", 
	    i__1, "tstio_", (ftnlen)302)]) {
	return 0;
    }
    active[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("active", i__1, 
	    "tstio_", (ftnlen)306)] = TRUE_;
    return 0;

/*     Get the current status of a port. */


L_tstgst:
/* $ Version */

/* -     Testing Utilities Version 1.0.0, 3-NOV-1994 (WLT) */

/*         This is the configured version of the Test Utility */
/*         software as of Nov 3, 1994 */

    id = isrchc_(port, &c__4, ports, port_len, (ftnlen)32);
    if (id == 0) {
	chkin_("TSTGST", (ftnlen)6);
	setmsg_("Unrecognized port: #", (ftnlen)20);
	errch_("#", port, (ftnlen)1, port_len);
	sigerr_("TESTUTIL(BUG)", (ftnlen)13);
	chkout_("TSTGST", (ftnlen)6);
	return 0;
    }
    status[0] = active[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("act"
	    "ive", i__1, "tstio_", (ftnlen)338)];
    status[1] = open[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("open", 
	    i__1, "tstio_", (ftnlen)339)];
    status[2] = suspnd[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("sus"
	    "pnd", i__1, "tstio_", (ftnlen)340)];
    return 0;
/* $Procedure TSTPST ( Put the status of a port ) */

L_tstpst:
/* $ Required_Reading */


/* $ Keywords */


/* $ Declarations */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) SPICE signals a TESTUTIL(BUG) for all unrecognized */
/*        PORT values. The PORTS defines acceptable ports. */

/* $ Files */

/*     None. */

/* $ Particulars */


/* $ Examples */


/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */


/* $ Version */

/* -     Testing Utilities Version 1.0.0, 3-NOV-1994 (WLT) */

/*         This is the configured version of the Test Utility */
/*         software as of Nov 3, 1994 */

/* -& */
    id = isrchc_(port, &c__4, ports, port_len, (ftnlen)32);
    if (id == 0) {
	chkin_("TSTPST", (ftnlen)6);
	setmsg_("Unrecognized port: #", (ftnlen)20);
	errch_("#", port, (ftnlen)1, port_len);
	sigerr_("TESTUTIL(BUG)", (ftnlen)13);
	chkout_("TSTPST", (ftnlen)6);
	return 0;
    }

/*        Check for an ID lockout. */

    if (lkport[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("lkport", 
	    i__1, "tstio_", (ftnlen)426)]) {
	return 0;
    }
    active[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("active", i__1, 
	    "tstio_", (ftnlen)430)] = status[0];
    open[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("open", i__1, "tst"
	    "io_", (ftnlen)431)] = status[1];
    suspnd[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("suspnd", i__1, 
	    "tstio_", (ftnlen)432)] = status[2];
    return 0;

/*     Close a port. */


L_tstioc:

/* $ Version */

/* -     Testing Utilities Version 1.0.0, 3-NOV-1994 (WLT) */

/*         This is the configured version of the Test Utility */
/*         software as of Nov 3, 1994 */

    id = isrchc_(port, &c__4, ports, port_len, (ftnlen)32);
    if (id == 0) {
	chkin_("TSTIOC", (ftnlen)6);
	setmsg_("Unrecognized port: #", (ftnlen)20);
	errch_("#", port, (ftnlen)1, port_len);
	sigerr_("TESTUTIL(BUG)", (ftnlen)13);
	chkout_("TSTIOC", (ftnlen)6);
	return 0;
    }

/*        Check for an ID lockout. */

    if (lkport[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("lkport", 
	    i__1, "tstio_", (ftnlen)465)]) {
	return 0;
    }
    cl__1.cerr = 0;
    cl__1.cunit = units[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge(
	    "units", i__1, "tstio_", (ftnlen)469)];
    cl__1.csta = 0;
    f_clos(&cl__1);
    active[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("active", i__1, 
	    "tstio_", (ftnlen)471)] = FALSE_;
    open[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("open", i__1, "tst"
	    "io_", (ftnlen)472)] = FALSE_;
    s_copy(files + ((i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("files", 
	    i__1, "tstio_", (ftnlen)473)) * 127, " ", (ftnlen)127, (ftnlen)1);
    suspnd[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("suspnd", i__1, 
	    "tstio_", (ftnlen)474)] = FALSE_;
    return 0;

/*     Suspend a port (possibly to be reopened later) */


L_tstios:

/* $ Version */

/* -     Testing Utilities Version 1.0.0, 3-NOV-1994 (WLT) */

/*         This is the configured version of the Test Utility */
/*         software as of Nov 3, 1994 */

    id = isrchc_(port, &c__4, ports, port_len, (ftnlen)32);
    if (id == 0) {
	chkin_("TSTIOS", (ftnlen)6);
	setmsg_("Unrecognized port: #", (ftnlen)20);
	errch_("#", port, (ftnlen)1, port_len);
	sigerr_("TESTUTIL(BUG)", (ftnlen)13);
	chkout_("TSTIOS", (ftnlen)6);
	return 0;
    }

/*        Check for an ID lockout. */

    if (lkport[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("lkport", 
	    i__1, "tstio_", (ftnlen)508)]) {
	return 0;
    }

/*        close ( units(id) ) */

    open[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("open", i__1, "tst"
	    "io_", (ftnlen)516)] = FALSE_;
    suspnd[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("suspnd", i__1, 
	    "tstio_", (ftnlen)517)] = TRUE_;
    return 0;

/*     Reopen a suspended port. */


L_tstior:

/* $ Version */

/* -     Testing Utilities Version 1.0.0, 3-NOV-1994 (WLT) */

/*         This is the configured version of the Test Utility */
/*         software as of Nov 3, 1994 */

    id = isrchc_(port, &c__4, ports, port_len, (ftnlen)32);
    if (id == 0) {
	chkin_("TSTIOR", (ftnlen)6);
	setmsg_("Unrecognized port: #", (ftnlen)20);
	errch_("#", port, (ftnlen)1, port_len);
	sigerr_("TESTUTIL(BUG)", (ftnlen)13);
	chkout_("TSTIOR", (ftnlen)6);
	return 0;
    }

/*        Check for an ID lockout. */

    if (lkport[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("lkport", 
	    i__1, "tstio_", (ftnlen)549)]) {
	return 0;
    }
    if (! suspnd[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("suspnd", 
	    i__1, "tstio_", (ftnlen)553)]) {
	*ok = FALSE_;
	return 0;
    }
    open[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("open", i__1, "tst"
	    "io_", (ftnlen)558)] = TRUE_;
    suspnd[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("suspnd", i__1, 
	    "tstio_", (ftnlen)559)] = FALSE_;
    *ok = TRUE_;
    return 0;

/*     Write a line to all open and active ports. */


L_tstwln:

/* $ Version */

/* -     Testing Utilities Version 1.0.0, 3-NOV-1994 (WLT) */

/*         This is the configured version of the Test Utility */
/*         software as of Nov 3, 1994 */

    for (id = 1; id <= 4; ++id) {
	if (active[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("active", 
		i__1, "tstio_", (ftnlen)580)] && open[(i__2 = id - 1) < 4 && 
		0 <= i__2 ? i__2 : s_rnge("open", i__2, "tstio_", (ftnlen)580)
		]) {
	    to = units[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("uni"
		    "ts", i__1, "tstio_", (ftnlen)582)];
	    writln_(line, &to, rtrim_(line, line_len));
	    if (id != 2 && failed_()) {
		r__ = rtrim_(files + ((i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 
			: s_rnge("files", i__1, "tstio_", (ftnlen)588)) * 127,
			 (ftnlen)127);
		s_copy(messge, "I was unable to write to the file #.  The va"
			"lue of IOSTAT returned was #. ", (ftnlen)400, (ftnlen)
			74);
		repmc_(messge, "#", files + ((i__1 = id - 1) < 4 && 0 <= i__1 
			? i__1 : s_rnge("files", i__1, "tstio_", (ftnlen)594))
			 * 127, messge, (ftnlen)400, (ftnlen)1, r__, (ftnlen)
			400);
		repmi_(messge, "#", &iostat, messge, (ftnlen)400, (ftnlen)1, (
			ftnlen)400);
		tostdo_(messge, (ftnlen)400);
		cl__1.cerr = 0;
		cl__1.cunit = units[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : 
			s_rnge("units", i__1, "tstio_", (ftnlen)599)];
		cl__1.csta = 0;
		f_clos(&cl__1);
		active[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("act"
			"ive", i__1, "tstio_", (ftnlen)601)] = FALSE_;
		open[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("open", 
			i__1, "tstio_", (ftnlen)602)] = FALSE_;
		suspnd[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("sus"
			"pnd", i__1, "tstio_", (ftnlen)603)] = FALSE_;
		s_copy(files + ((i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : 
			s_rnge("files", i__1, "tstio_", (ftnlen)604)) * 127, 
			" ", (ftnlen)127, (ftnlen)1);
	    }
	}
    }
    return 0;
/* $Procedure */

L_finish:
/* $ Abstract */

/*     The entry point handles closing files and informing the */
/*     user of the location of these files. */

/* $ Required_Reading */


/* $ Keywords */


/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */

/* $ Detailed_Input */

/*     None. */

/* $ Detailed_Output */

/*     None. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) */

/* $ Files */

/*     None. */

/* $ Particulars */


/* $ Examples */


/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */


/* $ Version */

/* -     Testing Utilities Version 1.1.0, 18-JAN-2007 (WLT) */

/*         Added a call to ZZTSTRE to force a reset of the OPNERR flag. */

/* -     Testing Utilities Version 1.0.0, 3-NOV-1994 (WLT) */

/*         This is the configured version of the Test Utility */
/*         software as of Nov 3, 1994 */


/*        Obtain the port ID for the SCREEN. */

    id = isrchc_("SCREEN", &c__4, ports, (ftnlen)6, (ftnlen)32);
    if (open[0]) {
/*           If a log file exists and a screen lockout is */
/*           not active, output the log file information message */
/*           to standard-out. */

	if (active[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("active", 
		i__1, "tstio_", (ftnlen)698)] && open[(i__2 = id - 1) < 4 && 
		0 <= i__2 ? i__2 : s_rnge("open", i__2, "tstio_", (ftnlen)698)
		]) {
	    s_copy(messge, "The log file was written to: ", (ftnlen)400, (
		    ftnlen)29);
	    tostdo_(messge, rtrim_(messge, (ftnlen)400));
	    tostdo_(files, rtrim_(files, (ftnlen)127));
	    tostdo_(" ", (ftnlen)1);
	}
	cl__1.cerr = 0;
	cl__1.cunit = units[0];
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (open[2]) {

/*           If a log file exists and a screen lockout is */
/*           not active, output the error log file information message */
/*           to standard-out. */

/*           Recall SPOOL indicates the error log file identified */
/*           in the tstlgr.f PORTS array as 'SAVE'. */

	if (active[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("active", 
		i__1, "tstio_", (ftnlen)719)] && open[(i__2 = id - 1) < 4 && 
		0 <= i__2 ? i__2 : s_rnge("open", i__2, "tstio_", (ftnlen)719)
		]) {
	    s_copy(messge, "The list of test failures was written to: ", (
		    ftnlen)400, (ftnlen)42);
	    tostdo_(messge, rtrim_(messge, (ftnlen)400));
	    tostdo_(files + 254, rtrim_(files + 254, (ftnlen)127));
	    tostdo_(" ", (ftnlen)1);
	}
	cl__1.cerr = 0;
	cl__1.cunit = units[2];
	cl__1.csta = 0;
	f_clos(&cl__1);
    }

/*        Reset the OPNERR boolean flag in tstlgr.f to TRUE. This action */
/*        is required for those situations where the test system does */
/*        not run in a single run environment (e.g. IDL, MATLAB). */

    zztstre_();
    return 0;
/* $Procedure LCKOUT (lock out a port from use ) */

L_lckout:
/* $ Abstract */

/*   Lockout a spcific port for all use (ports defined by PORTS */
/*   assignment in tstlgr.f). */

/* $ Particulars */

/*   Use of LCKOUT occurs only for situations when output to */
/*   standard out (STDOUT) must be prevented. */

/*   Not a subtle implementation, but effective. */

/* $ Required_Reading */


/* $ Keywords */


/* $ Declarations */



/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */

/* $ Detailed_Input */


/* $ Detailed_Output */


/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) SPICE signals a TESTUTIL(BUG) for all unrecognized */
/*        PORT values. The PORTS defines acceptable ports. */

/* $ Files */

/*     None. */

/* $ Particulars */


/* $ Examples */


/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */


/* $ Version */

/* -  Test Utilities Version 1.0.0, 09-MAY-2002 (EDW) */

/* -& */

/*        Get the port ID. */

    id = isrchc_(port, &c__4, ports, port_len, (ftnlen)32);
    if (id == 0) {
	chkin_("LCKOUT", (ftnlen)6);
	setmsg_("Unrecognized port: #", (ftnlen)20);
	errch_("#", port, (ftnlen)1, port_len);
	sigerr_("TESTUTIL(BUG)", (ftnlen)13);
	chkout_("LCKOUT", (ftnlen)6);
	return 0;
    }

/*        Close everything. */

    active[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("active", i__1, 
	    "tstio_", (ftnlen)830)] = FALSE_;
    open[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("open", i__1, "tst"
	    "io_", (ftnlen)831)] = FALSE_;
    suspnd[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("suspnd", i__1, 
	    "tstio_", (ftnlen)832)] = FALSE_;
    lkport[(i__1 = id - 1) < 4 && 0 <= i__1 ? i__1 : s_rnge("lkport", i__1, 
	    "tstio_", (ftnlen)833)] = TRUE_;
    return 0;
} /* tstio_ */

/* Subroutine */ int tstio_(char *line, char *name__, char *port, logical *ok,
	 logical *status, ftnlen line_len, ftnlen name_len, ftnlen port_len)
{
    return tstio_0_(0, line, name__, port, ok, status, line_len, name_len, 
	    port_len);
    }

/* Subroutine */ int tstopn_(char *port, char *name__, ftnlen port_len, 
	ftnlen name_len)
{
    return tstio_0_(1, (char *)0, name__, port, (logical *)0, (logical *)0, (
	    ftnint)0, name_len, port_len);
    }

/* Subroutine */ int tstioh_(char *port, ftnlen port_len)
{
    return tstio_0_(2, (char *)0, (char *)0, port, (logical *)0, (logical *)0,
	     (ftnint)0, (ftnint)0, port_len);
    }

/* Subroutine */ int tstioa_(char *port, ftnlen port_len)
{
    return tstio_0_(3, (char *)0, (char *)0, port, (logical *)0, (logical *)0,
	     (ftnint)0, (ftnint)0, port_len);
    }

/* Subroutine */ int tstgst_(char *port, logical *status, ftnlen port_len)
{
    return tstio_0_(4, (char *)0, (char *)0, port, (logical *)0, status, (
	    ftnint)0, (ftnint)0, port_len);
    }

/* Subroutine */ int tstpst_(char *port, logical *status, ftnlen port_len)
{
    return tstio_0_(5, (char *)0, (char *)0, port, (logical *)0, status, (
	    ftnint)0, (ftnint)0, port_len);
    }

/* Subroutine */ int tstioc_(char *port, ftnlen port_len)
{
    return tstio_0_(6, (char *)0, (char *)0, port, (logical *)0, (logical *)0,
	     (ftnint)0, (ftnint)0, port_len);
    }

/* Subroutine */ int tstios_(char *port, ftnlen port_len)
{
    return tstio_0_(7, (char *)0, (char *)0, port, (logical *)0, (logical *)0,
	     (ftnint)0, (ftnint)0, port_len);
    }

/* Subroutine */ int tstior_(char *port, logical *ok, ftnlen port_len)
{
    return tstio_0_(8, (char *)0, (char *)0, port, ok, (logical *)0, (ftnint)
	    0, (ftnint)0, port_len);
    }

/* Subroutine */ int tstwln_(char *line, ftnlen line_len)
{
    return tstio_0_(9, line, (char *)0, (char *)0, (logical *)0, (logical *)0,
	     line_len, (ftnint)0, (ftnint)0);
    }

/* Subroutine */ int finish_(void)
{
    return tstio_0_(10, (char *)0, (char *)0, (char *)0, (logical *)0, (
	    logical *)0, (ftnint)0, (ftnint)0, (ftnint)0);
    }

/* Subroutine */ int lckout_(char *port, ftnlen port_len)
{
    return tstio_0_(11, (char *)0, (char *)0, port, (logical *)0, (logical *)
	    0, (ftnint)0, (ftnint)0, port_len);
    }

