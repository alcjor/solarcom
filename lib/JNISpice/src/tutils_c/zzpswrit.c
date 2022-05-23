/* zzpswrit.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

/* $Procedure ZZPSWRIT ( Plate set, write to file ) */
/* Subroutine */ int zzpswrit_(integer *unit, doublereal *v1, integer *p1)
{
    /* System generated locals */
    integer i__1;
    cilist ci__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    integer i__, j, k;
    extern integer cardd_(doublereal *), cardi_(integer *);
    extern /* Subroutine */ int chkin_(char *, ftnlen);
    integer np, nv;
    extern /* Subroutine */ int sigerr_(char *, ftnlen), chkout_(char *, 
	    ftnlen), setmsg_(char *, ftnlen);
    integer iostat, cp1;
    extern /* Subroutine */ int errint_(char *, integer *, ftnlen);
    integer cv1;

/* $ Abstract */

/*     Write a plate set to a DSK "plate-vertex" format text file (code */
/*     1 in the MKDSK schema) specified by a Fortran logical unit. */

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

/*     CELLS */
/*     DSK */

/* $ Keywords */

/*     DSK */
/*     PLATE */

/* $ Declarations */
/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     UNIT       I   Logical unit of output file. */
/*     V1         I   Vertex cell of a plate set. */
/*     P1         I   Plate cell of a plate set. */

/* $ Detailed_Input */

/*     UNIT           is a Fortran logical unit of a text for open */
/*                    for write access. The input plate set will be */
/*                    written to the file designated by this unit. */

/*     V1             is a SPICELIB double precision cell containing the */
/*                    vertices of a plate set. */

/*     P1             is a SPICELIB integer cell containing the */
/*                    plates of a plate set. */

/* $ Detailed_Output */

/*     None. See the Files section below. */

/* $ Parameters */

/*     LBCELL is the lower bound of the SPICELIB cell data structure. */

/* $ Exceptions */

/*     1) If the cardinality of V1 is not a multiple of 3, the error */
/*        SPICE(BADVERTEXARRAY) is signaled. */

/*     2) If the cardinality of P1 is not a multiple of 3, the error */
/*        SPICE(BADPLATEARRAY) is signaled. */

/*     3) If an I/O error occurs during a Fortran write operation, */
/*        the error SPICE(FILEWRITEFAILED) will be signaled. */

/* $ Files */

/*     The output file written by this routine */

/* $ Particulars */

/*     None. */

/* $ Examples */

/*     None. */

/* $ Restrictions */

/*     None. */

/* $ Literature_References */

/*     None. */

/* $ Author_and_Institution */

/*     N.J. Bachman    (JPL) */

/* $ Version */

/* -    DSKLIB Version 1.0.0, 03-SEP-2014 (NJB) */

/* -& */

/*     SPICELIB functions */


/*     Local parameters */


/*     Local variables */


/*     Saved variables */

    chkin_("ZZPSWRIT", (ftnlen)8);
    nv = cardd_(v1) / 3;
    np = cardi_(p1) / 3;

/*     Make sure the cardinality of the input vertex set is a */
/*     multiple of 3. */

    cv1 = cardd_(v1);
    nv = cv1 / 3;
    if (nv * 3 != cv1) {
	setmsg_("Input vertex set cardinality # is not a multiple of 3.", (
		ftnlen)54);
	errint_("#", &cv1, (ftnlen)1);
	sigerr_("SPICE(BADVERTEXARRAY)", (ftnlen)21);
	chkout_("ZZPSWRIT", (ftnlen)8);
	return 0;
    }

/*     Make sure the cardinality of the input plate set is a */
/*     multiple of 3. */

    cp1 = cardi_(p1);
    np = cp1 / 3;
    if (np * 3 != cp1) {
	setmsg_("Input plate set cardinality # is not a multiple of 3.", (
		ftnlen)53);
	errint_("#", &cp1, (ftnlen)1);
	sigerr_("SPICE(BADPLATEXARRAY)", (ftnlen)21);
	chkout_("ZZPSWRIT", (ftnlen)8);
	return 0;
    }
    ci__1.cierr = 1;
    ci__1.ciunit = *unit;
    ci__1.cifmt = "(1X,I10)";
    iostat = s_wsfe(&ci__1);
    if (iostat != 0) {
	goto L100001;
    }
    iostat = do_fio(&c__1, (char *)&nv, (ftnlen)sizeof(integer));
    if (iostat != 0) {
	goto L100001;
    }
    iostat = e_wsfe();
L100001:
    if (iostat != 0) {
	setmsg_("Write of NV failed; IOSTAT = #.", (ftnlen)31);
	errint_("#", &iostat, (ftnlen)1);
	sigerr_("SPICE(FILEWRITEFAILED)", (ftnlen)22);
	chkout_("ZZPSWRIT", (ftnlen)8);
	return 0;
    }
    i__1 = nv;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = (i__ - 1) * 3;
	ci__1.cierr = 1;
	ci__1.ciunit = *unit;
	ci__1.cifmt = "(1X,I11,3E26.17)";
	iostat = s_wsfe(&ci__1);
	if (iostat != 0) {
	    goto L100002;
	}
	iostat = do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	if (iostat != 0) {
	    goto L100002;
	}
	for (k = 1; k <= 3; ++k) {
	    iostat = do_fio(&c__1, (char *)&v1[j + k + 5], (ftnlen)sizeof(
		    doublereal));
	    if (iostat != 0) {
		goto L100002;
	    }
	}
	iostat = e_wsfe();
L100002:
	if (iostat != 0) {
	    setmsg_("Write of vertex # failed; IOSTAT = #.", (ftnlen)37);
	    errint_("#", &i__, (ftnlen)1);
	    errint_("#", &iostat, (ftnlen)1);
	    sigerr_("SPICE(FILEWRITEFAILED)", (ftnlen)22);
	    chkout_("ZZPSWRIT", (ftnlen)8);
	    return 0;
	}
    }
    ci__1.cierr = 1;
    ci__1.ciunit = *unit;
    ci__1.cifmt = "(1X,I10)";
    iostat = s_wsfe(&ci__1);
    if (iostat != 0) {
	goto L100003;
    }
    iostat = do_fio(&c__1, (char *)&np, (ftnlen)sizeof(integer));
    if (iostat != 0) {
	goto L100003;
    }
    iostat = e_wsfe();
L100003:
    if (iostat != 0) {
	setmsg_("Write of NP failed; IOSTAT = #.", (ftnlen)31);
	errint_("#", &iostat, (ftnlen)1);
	sigerr_("SPICE(FILEWRITEFAILED)", (ftnlen)22);
	chkout_("ZZPSWRIT", (ftnlen)8);
	return 0;
    }
    i__1 = np;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = (i__ - 1) * 3;
	ci__1.cierr = 1;
	ci__1.ciunit = *unit;
	ci__1.cifmt = "(1X,4I10)";
	iostat = s_wsfe(&ci__1);
	if (iostat != 0) {
	    goto L100004;
	}
	iostat = do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	if (iostat != 0) {
	    goto L100004;
	}
	for (k = 1; k <= 3; ++k) {
	    iostat = do_fio(&c__1, (char *)&p1[j + k + 5], (ftnlen)sizeof(
		    integer));
	    if (iostat != 0) {
		goto L100004;
	    }
	}
	iostat = e_wsfe();
L100004:
	if (iostat != 0) {
	    setmsg_("Write of plate # failed; IOSTAT = #.", (ftnlen)36);
	    errint_("#", &i__, (ftnlen)1);
	    errint_("#", &iostat, (ftnlen)1);
	    sigerr_("SPICE(FILEWRITEFAILED)", (ftnlen)22);
	    chkout_("ZZPSWRIT", (ftnlen)8);
	    return 0;
	}
    }
    chkout_("ZZPSWRIT", (ftnlen)8);
    return 0;
} /* zzpswrit_ */

