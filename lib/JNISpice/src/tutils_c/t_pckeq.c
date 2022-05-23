/* t_pckeq.f -- translated by f2c (version 19980913).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__0 = 0;
static integer c_n10 = -10;
static integer c__10 = 10;
static integer c__199 = 199;
static integer c__299 = 299;
static integer c__399 = 399;
static integer c__499 = 499;
static integer c__599 = 599;
static integer c__699 = 699;
static integer c__799 = 799;
static integer c__899 = 899;
static integer c__999 = 999;
static integer c__301 = 301;
static integer c__401 = 401;
static integer c__402 = 402;
static integer c__501 = 501;
static integer c__502 = 502;
static integer c__503 = 503;
static integer c__504 = 504;
static integer c__505 = 505;
static integer c__514 = 514;
static integer c__515 = 515;
static integer c__516 = 516;
static integer c__601 = 601;
static integer c__602 = 602;
static integer c__603 = 603;
static integer c__604 = 604;
static integer c__605 = 605;
static integer c__606 = 606;
static integer c__608 = 608;
static integer c__609 = 609;
static integer c__610 = 610;
static integer c__611 = 611;
static integer c__612 = 612;
static integer c__613 = 613;
static integer c__614 = 614;
static integer c__615 = 615;
static integer c__616 = 616;
static integer c__617 = 617;
static integer c__618 = 618;
static integer c__701 = 701;
static integer c__702 = 702;
static integer c__703 = 703;
static integer c__704 = 704;
static integer c__705 = 705;
static integer c__706 = 706;
static integer c__707 = 707;
static integer c__708 = 708;
static integer c__709 = 709;
static integer c__710 = 710;
static integer c__711 = 711;
static integer c__712 = 712;
static integer c__713 = 713;
static integer c__714 = 714;
static integer c__715 = 715;
static integer c__801 = 801;
static integer c__803 = 803;
static integer c__804 = 804;
static integer c__805 = 805;
static integer c__806 = 806;
static integer c__807 = 807;
static integer c__808 = 808;
static integer c__901 = 901;
static integer c_b69 = 2000001;
static integer c_b70 = 2000002;
static integer c_b71 = 2000004;
static integer c_b72 = 2000021;
static integer c_b73 = 2431010;
static integer c_b74 = 2000433;
static integer c_b75 = 2000511;
static integer c_b76 = 9511010;
static integer c_b77 = 2002867;
static integer c_b78 = 2025143;
static integer c_b79 = 1000093;
static integer c_b80 = 1000005;
static integer c__506 = 506;
static integer c__507 = 507;
static integer c__508 = 508;
static integer c__509 = 509;
static integer c__510 = 510;
static integer c__511 = 511;
static integer c__512 = 512;
static integer c__513 = 513;
static integer c__607 = 607;
static integer c__632 = 632;
static integer c__633 = 633;
static integer c__634 = 634;
static integer c__635 = 635;
static integer c__649 = 649;
static integer c__802 = 802;
static integer c_b161 = 1000036;
static integer c_b163 = 1000107;
static integer c_b167 = 2000253;
static integer c_b171 = 2004179;
static doublereal c_b207 = 6.96e5;
static doublereal c_b210 = 2439.7;
static doublereal c_b213 = 6051.8;
static doublereal c_b216 = 6378.1366;
static doublereal c_b218 = 6356.7519;
static doublereal c_b219 = 3396.19;
static doublereal c_b221 = 3376.2;
static doublereal c_b222 = 71492.;
static doublereal c_b224 = 66854.;
static doublereal c_b225 = 60268.;
static doublereal c_b227 = 54364.;
static doublereal c_b228 = 25559.;
static doublereal c_b230 = 24973.;
static doublereal c_b231 = 24764.;
static doublereal c_b233 = 24341.;
static doublereal c_b234 = 1195.;
static doublereal c_b237 = 1737.4;
static doublereal c_b240 = 13.;
static doublereal c_b241 = 11.4;
static doublereal c_b242 = 9.1;
static doublereal c_b243 = 7.8;
static doublereal c_b244 = 6.;
static doublereal c_b245 = 5.1;
static doublereal c_b246 = 1829.4;
static doublereal c_b247 = 1819.4;
static doublereal c_b248 = 1815.7;
static doublereal c_b249 = 1562.6;
static doublereal c_b250 = 1560.3;
static doublereal c_b251 = 1559.5;
static doublereal c_b252 = 2631.2;
static doublereal c_b255 = 2410.3;
static doublereal c_b258 = 125.;
static doublereal c_b259 = 73.;
static doublereal c_b260 = 64.;
static doublereal c_b261 = 85.;
static doublereal c_b264 = 40.;
static doublereal c_b267 = 18.;
static doublereal c_b270 = 14.;
static doublereal c_b273 = 12.;
static doublereal c_b276 = 15.;
static doublereal c_b279 = 10.;
static doublereal c_b282 = 5.;
static doublereal c_b285 = 58.;
static doublereal c_b286 = 49.;
static doublereal c_b287 = 42.;
static doublereal c_b289 = 8.;
static doublereal c_b290 = 7.;
static doublereal c_b291 = 30.;
static doublereal c_b292 = 20.;
static doublereal c_b293 = 17.;
static doublereal c_b294 = 207.8;
static doublereal c_b295 = 196.7;
static doublereal c_b296 = 190.6;
static doublereal c_b297 = 256.6;
static doublereal c_b298 = 251.4;
static doublereal c_b299 = 248.3;
static doublereal c_b300 = 538.4;
static doublereal c_b301 = 528.3;
static doublereal c_b302 = 526.3;
static doublereal c_b303 = 563.4;
static doublereal c_b304 = 561.3;
static doublereal c_b305 = 559.6;
static doublereal c_b306 = 765.;
static doublereal c_b307 = 763.1;
static doublereal c_b308 = 762.4;
static doublereal c_b309 = 2575.15;
static doublereal c_b310 = 2574.78;
static doublereal c_b311 = 2574.47;
static doublereal c_b312 = 180.1;
static doublereal c_b313 = 133.;
static doublereal c_b314 = 102.7;
static doublereal c_b315 = 745.7;
static doublereal c_b317 = 712.1;
static doublereal c_b318 = 109.4;
static doublereal c_b319 = 108.5;
static doublereal c_b320 = 101.8;
static doublereal c_b321 = 101.5;
static doublereal c_b322 = 92.5;
static doublereal c_b323 = 76.3;
static doublereal c_b324 = 64.9;
static doublereal c_b325 = 57.;
static doublereal c_b326 = 53.1;
static doublereal c_b327 = 21.7;
static doublereal c_b328 = 19.1;
static doublereal c_b330 = 16.3;
static doublereal c_b331 = 11.8;
static doublereal c_b333 = 15.1;
static doublereal c_b334 = 11.5;
static doublereal c_b336 = 20.4;
static doublereal c_b337 = 17.7;
static doublereal c_b338 = 9.4;
static doublereal c_b339 = 67.8;
static doublereal c_b340 = 39.7;
static doublereal c_b341 = 29.7;
static doublereal c_b342 = 52.;
static doublereal c_b343 = 40.5;
static doublereal c_b344 = 32.;
static doublereal c_b345 = 17.2;
static doublereal c_b346 = 15.7;
static doublereal c_b347 = 10.4;
static doublereal c_b348 = 1.6;
static doublereal c_b351 = 2.9;
static doublereal c_b352 = 2.8;
static doublereal c_b353 = 2.;
static doublereal c_b354 = 1.5;
static doublereal c_b355 = 1.2;
static doublereal c_b356 = 1.;
static doublereal c_b357 = 4.3;
static doublereal c_b358 = 4.1;
static doublereal c_b359 = 3.2;
static doublereal c_b363 = 581.1;
static doublereal c_b364 = 577.9;
static doublereal c_b365 = 577.7;
static doublereal c_b366 = 584.7;
static doublereal c_b369 = 788.9;
static doublereal c_b372 = 761.4;
static doublereal c_b375 = 240.4;
static doublereal c_b376 = 234.2;
static doublereal c_b377 = 232.9;
static doublereal c_b384 = 21.;
static doublereal c_b387 = 31.;
static doublereal c_b390 = 27.;
static doublereal c_b396 = 54.;
static doublereal c_b402 = 33.;
static doublereal c_b405 = 77.;
static doublereal c_b408 = 1352.6;
static doublereal c_b411 = 170.;
static doublereal c_b414 = 29.;
static doublereal c_b420 = 74.;
static doublereal c_b423 = 79.;
static doublereal c_b426 = 96.;
static doublereal c_b429 = 218.;
static doublereal c_b430 = 208.;
static doublereal c_b431 = 201.;
static doublereal c_b432 = 605.;
static doublereal c_b435 = 4.22;
static doublereal c_b439 = 4.;
static doublereal c_b441 = 3.;
static doublereal c_b444 = 2.7;
static doublereal c_b445 = 1.9;
static doublereal c_b447 = 487.3;
static doublereal c_b449 = 454.7;
static doublereal c_b450 = 289.;
static doublereal c_b451 = 280.;
static doublereal c_b452 = 229.;
static doublereal c_b453 = 62.;
static doublereal c_b454 = 50.5;
static doublereal c_b455 = 46.5;
static doublereal c_b456 = 26.8;
static doublereal c_b458 = 7.6;
static doublereal c_b460 = 24.;
static doublereal c_b461 = 23.;
static doublereal c_b463 = 5.5;
static doublereal c_b465 = 180.;
static doublereal c_b466 = 147.;
static doublereal c_b467 = 127.;
static doublereal c_b469 = 5.2;
static doublereal c_b470 = 4.4;
static doublereal c_b471 = 3.24;
static doublereal c_b472 = 2.73;
static doublereal c_b473 = 2.04;
static doublereal c_b474 = 2.13;
static doublereal c_b475 = 1.015;
static doublereal c_b476 = .85;
static doublereal c_b477 = .535;
static doublereal c_b478 = .294;
static doublereal c_b479 = .209;

/* $Procedure      T_PCKEQ ( Text PCK equation implementation ) */
/* Subroutine */ int t_pckeq__0_(int n__, integer *body, doublereal *et, 
	doublereal *ra, doublereal *dec, doublereal *pm, integer *angset, 
	integer *radset, doublereal *radii)
{
    /* Builtin functions */
    double sin(doublereal), cos(doublereal);

    /* Local variables */
    doublereal d__, n, t, w;
    extern /* Subroutine */ int chkin_(char *, ftnlen), vpack_(doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    doublereal a0, d0, e1, e2, e3, e4, e5, e6, e7, e8, e9, j1, j2, j3, j4, j5,
	     j6, j7, j8, m1, m2, m3, n1, n2, n3, n4, n5, n6, n7, s1, s2, s3, 
	    s4, s5, s6, u1, u2, u3, u4, u5, u6, u7, u8, u9, e10, e11, e12, 
	    e13, ja, jb, jc, jd, je, u10, u11, u12, u13, u14, u15, u16;
    extern /* Subroutine */ int scardi_(integer *, integer *), sigerr_(char *,
	     ftnlen), chkout_(char *, ftnlen);
    doublereal mc1, mc2, mc3, mc4, mc5;
    extern /* Subroutine */ int setmsg_(char *, ftnlen), errint_(char *, 
	    integer *, ftnlen), insrti_(integer *, integer *);
    extern logical return_(void);
    extern doublereal rpd_(void), spd_(void);

/* $ Abstract */

/*     Umbrella routine for entry points that implement rotational */
/*     formulas and provide radii data from the current IAU/IAG working */
/*     group report. These data are meant to be compared against those */
/*     obtained from the corresponding NAIF text PCK. */

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

/*     PCK */

/* $ Keywords */

/*     UTILITY */

/* $ Declarations */
/* $ Brief_I/O */

/*     Entry Point  Description */
/*     -----------  -------------------------------------------------- */
/*     T_PCKAST     Return set of bodies with Euler angle data. */
/*     T_PCKRST     Return set of bodies with radii data. */
/*     T_PCKANG     Implement Euler angle equations. */
/*     T_PCKRAD     Return radii data. */

/* $ Detailed_Input */

/*     See the entry points. */

/* $ Detailed_Output */

/*     See the entry points. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If this routine is called directly, the error */
/*        SPICE(BOGUSENTRY) is signaled. */

/*     See the headers of the entry points for descriptions of */
/*     the exceptions specific to those entry points. */

/* $ Files */

/*     The data provided by the entry points of this routine are meant */
/*     to be consistent with the current IAU report [1] and should be */
/*     consistent with the NAIF text PCK */

/*        pck00009.tpc */

/*     This routine must be updated along with each NAIF text PCK update. */

/* $ Particulars */

/*     This routine supports testing of the current NAIF text PCK via the */
/*     entry points */

/*        T_PCKAST     Return set of bodies with Euler angle data. */
/*        T_PCKRST     Return set of bodies with radii data. */
/*        T_PCKANG     Implement Euler angle equations. */
/*        T_PCKRAD     Return radii data. */

/* $ Examples */

/*     See usage in F_RDPCK. */

/* $ Restrictions */

/*     1) This routine must be kept consistent with */
/*        the current NAIF text PCK. */

/*     2) For use in TSPICE testing, the equations implemented in */
/*        the entry point T_PCKANG must be modified to be consistent */
/*        with those that can be implemented by the SPICE text PCK */
/*        reader/evaluator algorithms. For example, the M2 nutation */
/*        precession angle for Mars must be zeroed out, since SPICELIB */
/*        can't make use of this term. */

/* $ Literature_References */

/*     [1]   Archinal, B.A., A'Hearn, M.F., Bowell, E., Conrad, A., */
/*           Consolmagno, G.J., Courtin, R., Fukushima, T., Hestroffer, */
/*           D., Hilton, J.L., Krasinsky, G.A., Neumann, G., Oberst, J., */
/*           Seidelmann, P.K., Stooke, P., Tholen, D.J., Thomas, P.C., */
/*           and Williams, I.P., "Report of the IAU Working Group on */
/*           Cartographic Coordinates and Rotational elements: 2009." */

/* $ Author_and_Institution */

/*     N.J. Bachman       (JPL) */

/* $ Version */

/* -    Test Utilities Version 3.0.0, 29-JAN-2011 (NJB) */

/*        Updated to reflect data from the 2009 IAU report. */

/* -    Test Utilities Version 2.0.0, 10-FEB-2010 (NJB) */

/* -& */

/*     SPICELIB functions */


/*     Local variables */

    /* Parameter adjustments */
    if (angset) {
	}
    if (radset) {
	}
    if (radii) {
	}

    /* Function Body */
    switch(n__) {
	case 1: goto L_t_pckast;
	case 2: goto L_t_pckrst;
	case 3: goto L_t_pckang;
	case 4: goto L_t_pckrad;
	}

    if (return_()) {
	return 0;
    }

/*     This routine should never be called. */

    chkin_("T_PCKEQ", (ftnlen)7);
    sigerr_("SPICE(BOGUSENTRY)", (ftnlen)17);
    chkout_("T_PCKEQ", (ftnlen)7);
    return 0;
/* $Procedure T_PCKAST ( Text PCK Euler angle body set ) */

L_t_pckast:
/* $ Abstract */

/*     Return the set of NAIF ID codes for those bodies */
/*     having Euler angles for their orientation. */

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

/*     PCK */

/* $ Keywords */

/*     UTILITY */

/* $ Declarations */

/*     INTEGER               ANGSET ( LBCELL : * ) */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     ANGSET    I-O  Set of ID code for bodies having Euler angle data. */

/* $ Detailed_Input */

/*     ANGSET         is an initialized SPICE set. */

/* $ Detailed_Output */

/*     ANGSET         is a SPICE set containing the ID codes of those */
/*                    bodies for which the current IAU report [1] */
/*                    contains Euler angle data. */

/*                    Note that this set does not necessarily contain, */
/*                    nor is it necessarily contained in, the set of */
/*                    bodies for which the current IAU report [1] */
/*                    contains radius data. */

/*                    In addition, ANGSET contains the body code -10, */
/*                    which is needed for tests performed by F_RDPCK. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If an error occurs while inserting ID codes into ANGSET, the */
/*        error will be diagnosed by routines in the call tree of this */
/*        routine. */

/* $ Files */

/*     The data provided by this routine are meant to be consistent with */
/*     the current IAU report [1] and should be consistent with the NAIF */
/*     text PCK */

/*        pck00009.tpc */

/*     This routine must be updated along with each NAIF text PCK update. */

/* $ Particulars */

/*     This routine enables comparison of the set of bodies having */
/*     orientation data in the current IAU report [1] against the */
/*     corresponding set of bodies in the current NAIF text PCK. */

/*     This comparison serves to minimize the chance of transcription */
/*     error when a new PCK version is created. */

/* $ Examples */

/*     See use in F_RDPCK. */

/* $ Restrictions */

/*     1) This routine must be kept consistent with the current IAU */
/*        report [1]. */

/* $ Literature_References */

/*     See header of the umbrella routine T_PCKEQ. */

/* $ Author_and_Institution */

/*     N.J. Bachman       (JPL) */

/* $ Version */

/* -    Test Utilities Version 3.0.0, 29-JAN-2011 (NJB) */

/*        Updated to reflect data from the 2009 IAU report. */

/* -    Test Utilities Version 2.0.0, 10-FEB-2010 (NJB) */

/* -& */
    chkin_("T_PCKAST", (ftnlen)8);
    scardi_(&c__0, angset);

/*     Body -10 is used for testing features */
/*     not exercised by the normal cases. */

    insrti_(&c_n10, angset);
    insrti_(&c__10, angset);
    insrti_(&c__199, angset);
    insrti_(&c__299, angset);
    insrti_(&c__399, angset);
    insrti_(&c__499, angset);
    insrti_(&c__599, angset);
    insrti_(&c__699, angset);
    insrti_(&c__799, angset);
    insrti_(&c__899, angset);
    insrti_(&c__999, angset);
    insrti_(&c__301, angset);
    insrti_(&c__401, angset);
    insrti_(&c__402, angset);
    insrti_(&c__501, angset);
    insrti_(&c__502, angset);
    insrti_(&c__503, angset);
    insrti_(&c__504, angset);
    insrti_(&c__505, angset);
    insrti_(&c__514, angset);
    insrti_(&c__515, angset);
    insrti_(&c__516, angset);
    insrti_(&c__601, angset);
    insrti_(&c__602, angset);
    insrti_(&c__603, angset);
    insrti_(&c__604, angset);
    insrti_(&c__605, angset);
    insrti_(&c__606, angset);
    insrti_(&c__608, angset);
    insrti_(&c__609, angset);
    insrti_(&c__610, angset);
    insrti_(&c__611, angset);
    insrti_(&c__612, angset);
    insrti_(&c__613, angset);
    insrti_(&c__614, angset);
    insrti_(&c__615, angset);
    insrti_(&c__616, angset);
    insrti_(&c__617, angset);
    insrti_(&c__618, angset);
    insrti_(&c__701, angset);
    insrti_(&c__702, angset);
    insrti_(&c__703, angset);
    insrti_(&c__704, angset);
    insrti_(&c__705, angset);
    insrti_(&c__706, angset);
    insrti_(&c__707, angset);
    insrti_(&c__708, angset);
    insrti_(&c__709, angset);
    insrti_(&c__710, angset);
    insrti_(&c__711, angset);
    insrti_(&c__712, angset);
    insrti_(&c__713, angset);
    insrti_(&c__714, angset);
    insrti_(&c__715, angset);
    insrti_(&c__801, angset);
    insrti_(&c__803, angset);
    insrti_(&c__804, angset);
    insrti_(&c__805, angset);
    insrti_(&c__806, angset);
    insrti_(&c__807, angset);
    insrti_(&c__808, angset);
    insrti_(&c__901, angset);
    insrti_(&c_b69, angset);
    insrti_(&c_b70, angset);
    insrti_(&c_b71, angset);
    insrti_(&c_b72, angset);
    insrti_(&c_b73, angset);
    insrti_(&c_b74, angset);
    insrti_(&c_b75, angset);
    insrti_(&c_b76, angset);
    insrti_(&c_b77, angset);
    insrti_(&c_b78, angset);
    insrti_(&c_b79, angset);
    insrti_(&c_b80, angset);

/*     607 is Hyperion. */


/*     802 is Nereid. */

    chkout_("T_PCKAST", (ftnlen)8);
    return 0;
/* $Procedure T_PCKRST ( Text PCK radii body set ) */

L_t_pckrst:
/* $ Abstract */

/*     Return the set of NAIF ID codes for those bodies having radii */
/*     data. */

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

/*     PCK */

/* $ Keywords */

/*     UTILITY */

/* $ Declarations */

/*     INTEGER               RADSET ( LBCELL : * ) */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     RADSET    I-O  Set of ID code for bodies having radii data. */

/* $ Detailed_Input */

/*     RADSET         is an initialized SPICE set. */

/* $ Detailed_Output */

/*     RADSET         is a SPICE set containing the ID codes of those */
/*                    bodies for which the current IAU report [1] */
/*                    contains radii data. */

/*                    Note that this set does not necessarily contain, */
/*                    nor is it necessarily contained in, the set of */
/*                    bodies for which the current IAU report [1] */
/*                    contains radii data. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If an error occurs while inserting ID codes into RADSET, the */
/*        error will be diagnosed by routines in the call tree of this */
/*        routine. */

/* $ Files */

/*     The data provided by this routine are meant to be consistent with */
/*     the current IAU report [1] and should be consistent with the NAIF */
/*     text PCK */

/*        pck00009.tpc */

/*     This routine must be updated along with each NAIF text PCK update. */

/* $ Particulars */

/*     This routine enables comparison of the set of bodies having */
/*     radii data in the current IAU report [1] against the */
/*     corresponding set of bodies in the current NAIF text PCK. */

/*     This comparison serves to minimize the chance of transcription */
/*     error when a new PCK version is created. */

/* $ Examples */

/*     See use in F_RDPCK. */

/* $ Restrictions */

/*     1) This routine must be kept consistent with the current IAU */
/*        report [1]. */

/* $ Literature_References */

/*     See header of the umbrella routine T_PCKEQ. */

/* $ Author_and_Institution */

/*     N.J. Bachman       (JPL) */

/* $ Version */

/* -    Test Utilities Version 3.0.0, 29-JAN-2011 (NJB) */

/*        Updated to reflect data from the 2009 IAU report. */

/* -    Test Utilities Version 2.0.0, 10-FEB-2010 (NJB) */

/* -& */
    chkin_("T_PCKRST", (ftnlen)8);
    scardi_(&c__0, radset);
    insrti_(&c__10, radset);
    insrti_(&c__199, radset);
    insrti_(&c__299, radset);
    insrti_(&c__399, radset);
    insrti_(&c__499, radset);
    insrti_(&c__599, radset);
    insrti_(&c__699, radset);
    insrti_(&c__799, radset);
    insrti_(&c__899, radset);
    insrti_(&c__999, radset);
    insrti_(&c__301, radset);
    insrti_(&c__401, radset);
    insrti_(&c__402, radset);
    insrti_(&c__501, radset);
    insrti_(&c__502, radset);
    insrti_(&c__503, radset);
    insrti_(&c__504, radset);
    insrti_(&c__505, radset);
    insrti_(&c__506, radset);
    insrti_(&c__507, radset);
    insrti_(&c__508, radset);
    insrti_(&c__509, radset);
    insrti_(&c__510, radset);
    insrti_(&c__511, radset);
    insrti_(&c__512, radset);
    insrti_(&c__513, radset);
    insrti_(&c__514, radset);
    insrti_(&c__515, radset);
    insrti_(&c__516, radset);
    insrti_(&c__601, radset);
    insrti_(&c__602, radset);
    insrti_(&c__603, radset);
    insrti_(&c__604, radset);
    insrti_(&c__605, radset);
    insrti_(&c__606, radset);
    insrti_(&c__607, radset);
    insrti_(&c__608, radset);
    insrti_(&c__609, radset);
    insrti_(&c__610, radset);
    insrti_(&c__611, radset);
    insrti_(&c__612, radset);
    insrti_(&c__613, radset);
    insrti_(&c__614, radset);
    insrti_(&c__615, radset);
    insrti_(&c__616, radset);
    insrti_(&c__617, radset);
    insrti_(&c__618, radset);
    insrti_(&c__632, radset);
    insrti_(&c__633, radset);
    insrti_(&c__634, radset);
    insrti_(&c__635, radset);
    insrti_(&c__649, radset);
    insrti_(&c__701, radset);
    insrti_(&c__702, radset);
    insrti_(&c__703, radset);
    insrti_(&c__704, radset);
    insrti_(&c__705, radset);
    insrti_(&c__706, radset);
    insrti_(&c__707, radset);
    insrti_(&c__708, radset);
    insrti_(&c__709, radset);
    insrti_(&c__710, radset);
    insrti_(&c__711, radset);
    insrti_(&c__712, radset);
    insrti_(&c__713, radset);
    insrti_(&c__714, radset);
    insrti_(&c__715, radset);
    insrti_(&c__801, radset);
    insrti_(&c__802, radset);
    insrti_(&c__803, radset);
    insrti_(&c__804, radset);
    insrti_(&c__805, radset);
    insrti_(&c__806, radset);
    insrti_(&c__807, radset);
    insrti_(&c__808, radset);
    insrti_(&c__901, radset);
    insrti_(&c_b80, radset);
    insrti_(&c_b161, radset);
    insrti_(&c_b79, radset);
    insrti_(&c_b163, radset);
    insrti_(&c_b69, radset);
    insrti_(&c_b71, radset);
    insrti_(&c_b72, radset);
    insrti_(&c_b167, radset);
    insrti_(&c_b74, radset);
    insrti_(&c_b75, radset);
    insrti_(&c_b77, radset);
    insrti_(&c_b171, radset);
    insrti_(&c_b78, radset);
    insrti_(&c_b73, radset);
    insrti_(&c_b76, radset);
    chkout_("T_PCKRST", (ftnlen)8);
    return 0;
/* $Procedure T_PCKANG ( Text PCK Euler angle equation implementation ) */

L_t_pckang:
/* $ Abstract */

/*     Generate Euler angles for body orientation directly from */
/*     in-line coding of equations from the IAU report [1]. */

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

/*     PCK */

/* $ Keywords */

/*     UTILITY */

/* $ Declarations */

/*     INTEGER               BODY */
/*     DOUBLE PRECISION      ET */
/*     DOUBLE PRECISION      RA */
/*     DOUBLE PRECISION      DEC */
/*     DOUBLE PRECISION      PM */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     BODY       I   BODY for which Euler angles are to be computed. */
/*     ET         I   ET for which Euler angles are to be computed. */
/*     RA         O   RA for BODY at ET. */
/*     DEC        O   DEC for BODY at ET. */
/*     PM         O   PM for BODY at ET. */

/* $ Detailed_Input */

/*     BODY           is the NAIF ID code of the body for which Euler */
/*                    angles are to be computed at time ET. */

/*     ET             is the epoch, expressed as seconds past J2000 */
/*                    TDB, at which Euler angles giving the */
/*                    orientation of the specified body are to be */
/*                    computed. */

/* $ Detailed_Output */

/*     RA             is the right ascension of the pole of the */
/*                    specified body, relative to the J2000 */
/*                    reference frame, at ET. */

/*     DEC            is the declination of the pole of the */
/*                    specified body, relative to the J2000 */
/*                    reference frame, at ET. */

/*     PM             is angle of the prime meridian, relative to the */
/*                    ascending node of the body's equator on the */
/*                    J2000 X-Y plane, at ET. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If an unrecognized ID code is provided via the input argument */
/*        BODY, the error SPICE(INVALIDBODYCODE) is signaled. */

/* $ Files */

/*     The data provided by this routine are meant to be consistent with */
/*     the current IAU report [1] and should be consistent with the NAIF */
/*     text PCK */

/*        pck00009.tpc */

/*     This routine must be updated along with each NAIF text PCK update. */

/* $ Particulars */

/*     This routine supports tests of the SPICELIB routines */

/*        BODEUL */
/*        BODMAT (indirectly, via call to TIPBOD) */
/*        TIPBOD */

/*     performed by the test family F_RDPCK. */

/*     Results of computations done by this routine are compared with */
/*     results of computations implemented in the above SPICELIB */
/*     routines.  This testing approach attempts to validate orientation */
/*     computations done using text PCK data by comparing their results */
/*     to those obtained via an alternate computational approach. */

/*     These tests also serve to minimize the chance of transcription */
/*     error when a new PCK version is created.  Entering the PCK */
/*     constants both in the new PCK file and in T_PCKANG enables */
/*     double-checking of the constants. */

/* $ Examples */

/*     See use in F_RDPCK. */

/* $ Restrictions */


/*     1) This routine must be kept consistent with the current IAU */
/*        report [1]. */

/*     2) For use in TSPICE testing, the equations implemented in the */
/*        entry point T_PCKANG must be modified to be consistent with */
/*        those that can be implemented by the SPICE text PCK */
/*        reader/evaluator algorithms. For example, the M2 nutation */
/*        precession angle for Mars must be zeroed out, since SPICELIB */
/*        can't make use of this term. */

/* $ Literature_References */

/*     See header of the umbrella routine T_PCKEQ. */

/* $ Author_and_Institution */

/*     N.J. Bachman       (JPL) */

/* $ Version */

/* -    Test Utilities Version 3.0.0, 29-JAN-2011 (NJB) */

/*        Updated to reflect data from the 2009 IAU report. */

/* -    Test Utilities Version 2.0.0, 10-FEB-2010 (NJB) */

/* -& */
    chkin_("T_PCKANG", (ftnlen)8);
    d__ = *et / spd_();
    t = d__ / 36525.;
    if (*body == 10) {
	a0 = 286.13;
	d0 = 63.87;
	w = d__ * 14.1844 + 84.176;
    } else if (*body == 199) {
	mc1 = (d__ * 4.092335 + 174.791086) * rpd_();
	mc2 = (d__ * 8.18467 + 349.582171) * rpd_();
	mc3 = (d__ * 12.277005 + 164.373257) * rpd_();
	mc4 = (d__ * 16.36934 + 339.164343) * rpd_();
	mc5 = (d__ * 20.461675 + 153.955429) * rpd_();
	a0 = 281.0097 - t * .0328;
	d0 = 61.4143 - t * .0049;
	w = d__ * 6.1385025 + 329.5469 + sin(mc1) * .00993822 - sin(mc2) * 
		.00104581 - sin(mc3) * 1.028e-4 - sin(mc4) * 2.364e-5 - sin(
		mc5) * 5.32e-6;
    } else if (*body == 299) {
	a0 = 272.76;
	d0 = 67.16;
	w = 160.2 - d__ * 1.4813688;
    } else if (*body == 399) {
	a0 = 0. - t * .641;
	d0 = 90. - t * .557;
	w = d__ * 360.9856235 + 190.147;
    } else if (*body == 499) {
	a0 = 317.68143 - t * .1061;
	d0 = 52.8865 - t * .0609;
	w = d__ * 350.89198226 + 176.63;
    } else if (*body == 599) {
	ja = (t * 4850.4046 + 99.360714) * rpd_();
	jb = (t * 1191.9605 + 175.895369) * rpd_();
	jc = (t * 262.5475 + 300.323162) * rpd_();
	jd = (t * 6070.2476 + 114.012305) * rpd_();
	je = (t * 64.3 + 49.511251) * rpd_();
	a0 = 268.056595 - t * .006499 + sin(ja) * 1.17e-4 + sin(jb) * 9.38e-4 
		+ sin(jc) * .001432 + sin(jd) * 3e-5 + sin(je) * .00215;
	d0 = t * .002413 + 64.495303 + cos(ja) * 5e-5 + cos(jb) * 4.04e-4 + 
		cos(jc) * 6.17e-4 - cos(jd) * 1.3e-5 + cos(je) * 9.26e-4;
	w = d__ * 870.536 + 284.95;
    } else if (*body == 699) {
	a0 = 40.589 - t * .036;
	d0 = 83.537 - t * .004;
	w = d__ * 810.7939024 + 38.9;
    } else if (*body == 799) {
	a0 = 257.311;
	d0 = -15.175;
	w = 203.81 - d__ * 501.1600928;
    } else if (*body == 899) {
	n = (t * 52.316 + 357.85) * rpd_();
	a0 = sin(n) * .7 + 299.36;
	d0 = 43.46 - cos(n) * .51;
	w = d__ * 536.3128492 + 253.18 - sin(n) * .48;
    } else if (*body == 999) {
	a0 = 132.993;
	d0 = -6.163;
	w = d__ * 56.3625225 + 302.695;
    } else if (*body == 301) {
	e1 = (125.045 - d__ * .0529921) * rpd_();
	e2 = (250.089 - d__ * .1059842) * rpd_();
	e3 = (d__ * 13.0120009 + 260.008) * rpd_();
	e4 = (d__ * 13.3407154 + 176.625) * rpd_();
	e5 = (d__ * .9856003 + 357.529) * rpd_();
	e6 = (d__ * 26.4057084 + 311.589) * rpd_();
	e7 = (d__ * 13.064993 + 134.963) * rpd_();
	e8 = (d__ * .3287146 + 276.617) * rpd_();
	e9 = (d__ * 1.7484877 + 34.226) * rpd_();
	e10 = (15.134 - d__ * .1589763) * rpd_();
	e11 = (d__ * .0036096 + 119.743) * rpd_();
	e12 = (d__ * .1643573 + 239.961) * rpd_();
	e13 = (d__ * 12.9590088 + 25.053) * rpd_();
	a0 = t * .0031 + 269.9949 - sin(e1) * 3.8787 - sin(e2) * .1204 + sin(
		e3) * .07 - sin(e4) * .0172 + sin(e6) * .0072 - sin(e10) * 
		.0052 + sin(e13) * .0043;
	d0 = t * .013 + 66.5392 + cos(e1) * 1.5419 + cos(e2) * .0239 - cos(e3)
		 * .0278 + cos(e4) * .0068 - cos(e6) * .0029 + cos(e7) * 9e-4 
		+ cos(e10) * 8e-4 - cos(e13) * 9e-4;
	w = d__ * 13.17635815 + 38.3213 - d__ * 1.4e-12 * d__ + sin(e1) * 
		3.561 + sin(e2) * .1208 - sin(e3) * .0642 + sin(e4) * .0158 + 
		sin(e5) * .0252 - sin(e6) * .0066 - sin(e7) * .0047 - sin(e8) 
		* .0046 + sin(e9) * .0028 + sin(e10) * .0052 + sin(e11) * 
		.004 + sin(e12) * .0019 - sin(e13) * .0044;
    } else if (*body / 100 == 4) {

/*        Two expressions for M2 are shown:  one with the quadratic */
/*        term, one without.  The kernel pool software cannot handle */
/*        the quadratic term; trying both of these expressions allows */
/*        the user to observe the effect of ignoring that term. */

	m1 = (169.51 - d__ * .435764) * rpd_();
/*         M2 = (    192.93D0  + 1128.4096700D0 * D */
/*     .                       +    8.864D0     * T**2 ) * RPD() */
	m2 = (d__ * 1128.40967 + 192.93) * rpd_();
	m3 = (53.47 - d__ * .018151) * rpd_();
	if (*body == 401) {
	    a0 = 317.68 - t * .108 + sin(m1) * 1.79;
	    d0 = 52.9 - t * .061 - cos(m1) * 1.08;
	    w = d__ * 1128.844585 + 35.06 + t * 8.864 * t - sin(m1) * 1.42 - 
		    sin(m2) * .78;
	} else if (*body == 402) {
	    a0 = 316.65 - t * .108 + sin(m3) * 2.98;
	    d0 = 53.52 - t * .061 - cos(m3) * 1.78;
	    w = d__ * 285.161897 + 79.41 - t * .52 * t - sin(m3) * 2.58 + cos(
		    m3) * .19;
	} else {
	    setmsg_("Body code # was not recognized.", (ftnlen)31);
	    errint_("#", body, (ftnlen)1);
	    sigerr_("SPICE(INVALIDBODYCODE)", (ftnlen)22);
	    chkout_("T_PCKANG", (ftnlen)8);
	    return 0;
	}
    } else if (*body / 100 == 5) {
	j1 = (t * 91472.9 + 73.32) * rpd_();
	j2 = (t * 45137.2 + 24.62) * rpd_();
	j3 = (t * 4850.7 + 283.9) * rpd_();
	j4 = (t * 1191.3 + 355.8) * rpd_();
	j5 = (t * 262.1 + 119.9) * rpd_();
	j6 = (t * 64.3 + 229.8) * rpd_();
	j7 = (t * 2382.6 + 352.25) * rpd_();
	j8 = (t * 6070. + 113.35) * rpd_();
	if (*body == 501) {
	    a0 = 268.05 - t * .009 + sin(j3) * .094 + sin(j4) * .024;
	    d0 = t * .003 + 64.5 + cos(j3) * .04 + cos(j4) * .011;
	    w = d__ * 203.4889538 + 200.39 - sin(j3) * .085 - sin(j4) * .022;
	} else if (*body == 502) {
	    a0 = 268.08 - t * .009 + sin(j4) * 1.086 + sin(j5) * .06 + sin(j6)
		     * .015 + sin(j7) * .009;
	    d0 = t * .003 + 64.51 + cos(j4) * .468 + cos(j5) * .026 + cos(j6) 
		    * .007 + cos(j7) * .002;
	    w = d__ * 101.3747235 + 36.022 - sin(j4) * .98 - sin(j5) * .054 - 
		    sin(j6) * .014 - sin(j7) * .008;
	} else if (*body == 503) {
	    a0 = 268.2 - t * .009 - sin(j4) * .037 + sin(j5) * .431 + sin(j6) 
		    * .091;
	    d0 = t * .003 + 64.57 - cos(j4) * .016 + cos(j5) * .186 + cos(j6) 
		    * .039;
	    w = d__ * 50.3176081 + 44.064 + sin(j4) * .033 - sin(j5) * .389 - 
		    sin(j6) * .082;
	} else if (*body == 504) {
	    a0 = 268.72 - t * .009 - sin(j5) * .068 + sin(j6) * .59 + sin(j8) 
		    * .01;
	    d0 = t * .003 + 64.83 - cos(j5) * .029 + cos(j6) * .254 - cos(j8) 
		    * .004;
	    w = d__ * 21.5710715 + 259.51 + sin(j5) * .061 - sin(j6) * .533 - 
		    sin(j8) * .009;
	} else if (*body == 505) {
	    a0 = 268.05 - t * .009 - sin(j1) * .84 + sin(j1 * 2) * .01;
	    d0 = t * .003 + 64.49 - cos(j1) * .36;
	    w = d__ * 722.631456 + 231.67 + sin(j1) * .76 - sin(j1 * 2) * .01;
	} else if (*body == 514) {
	    a0 = 268.05 - t * .009 - sin(j2) * 2.11 + sin(j2 * 2) * .04;
	    d0 = t * .003 + 64.49 - cos(j2) * .91 + cos(j2 * 2) * .01;
	    w = d__ * 533.70041 + 8.56 + sin(j2) * 1.91 - sin(j2 * 2) * .04;
	} else if (*body == 515) {
	    a0 = 268.05 - t * .009;
	    d0 = t * .003 + 64.49;
	    w = d__ * 1206.9986602 + 33.29;
	} else if (*body == 516) {
	    a0 = 268.05 - t * .009;
	    d0 = t * .003 + 64.49;
	    w = d__ * 1221.2547301 + 346.09;
	} else {
	    setmsg_("Body code # was not recognized.", (ftnlen)31);
	    errint_("#", body, (ftnlen)1);
	    sigerr_("SPICE(INVALIDBODYCODE)", (ftnlen)22);
	    chkout_("T_PCKANG", (ftnlen)8);
	    return 0;
	}
    } else if (*body / 100 == 6) {
	s1 = (t * 75706.7 + 353.32) * rpd_();
	s2 = (t * 75706.7 + 28.72) * rpd_();
	s3 = (177.4 - t * 36505.5) * rpd_();
	s4 = (300. - t * 7225.9) * rpd_();
	s5 = (t * 506.2 + 316.45) * rpd_();
	s6 = (345.2 - t * 1016.3) * rpd_();
	if (*body == 601) {
	    a0 = 40.66 - t * .036 + sin(s3) * 13.56;
	    d0 = 83.52 - t * .004 - cos(s3) * 1.53;
	    w = d__ * 381.994555 + 333.46 - sin(s3) * 13.48 - sin(s5) * 44.85;
	} else if (*body == 602) {
	    a0 = 40.66 - t * .036;
	    d0 = 83.52 - t * .004;
	    w = d__ * 262.7318996 + 6.32;
	} else if (*body == 603) {
	    a0 = 40.66 - t * .036 + sin(s4) * 9.66;
	    d0 = 83.52 - t * .004 - cos(s4) * 1.09;
	    w = d__ * 190.6979085 + 8.95 - sin(s4) * 9.6 + sin(s5) * 2.23;
	} else if (*body == 604) {
	    a0 = 40.66 - t * .036;
	    d0 = 83.52 - t * .004;
	    w = d__ * 131.5349316 + 357.6;
	} else if (*body == 605) {
	    a0 = 40.38 - t * .036 + sin(s6) * 3.1;
	    d0 = 83.55 - t * .004 - cos(s6) * .35;
	    w = d__ * 79.6900478 + 235.16 - sin(s6) * 3.08;
	} else if (*body == 606) {
	    a0 = 39.4827;
	    d0 = 83.4279;
	    w = d__ * 22.5769768 + 186.5855;
	} else if (*body == 608) {
	    a0 = 318.16 - t * 3.949;
	    d0 = 75.03 - t * 1.143;
	    w = d__ * 4.5379572 + 355.2;
	} else if (*body == 609) {
	    a0 = 356.9;
	    d0 = 77.8;
	    w = d__ * 931.639 + 178.58;
	} else if (*body == 610) {
	    a0 = 40.58 - t * .036 - sin(s2) * 1.623 + sin(s2 * 2) * .023;
	    d0 = 83.52 - t * .004 - cos(s2) * .183 + cos(s2 * 2) * .001;
	    w = d__ * 518.2359876 + 58.83 + sin(s2) * 1.613 - sin(s2 * 2) * 
		    .023;
	} else if (*body == 611) {
	    a0 = 40.58 - t * .036 - sin(s1) * 3.153 + sin(s1 * 2) * .086;
	    d0 = 83.52 - t * .004 - cos(s1) * .356 + cos(s1 * 2) * .005;
	    w = d__ * 518.4907239 + 293.87 + sin(s1) * 3.133 - sin(s1 * 2) * 
		    .086;
	} else if (*body == 612) {
	    a0 = 40.85 - t * .036;
	    d0 = 83.34 - t * .004;
	    w = d__ * 131.6174056 + 245.12;
	} else if (*body == 613) {
	    a0 = 50.51 - t * .036;
	    d0 = 84.06 - t * .004;
	    w = d__ * 190.6979332 + 56.88;
	} else if (*body == 614) {
	    a0 = 36.41 - t * .036;
	    d0 = 85.04 - t * .004;
	    w = d__ * 190.6742373 + 153.51;
	} else if (*body == 615) {
	    a0 = 40.58 - t * .036;
	    d0 = 83.53 - t * .004;
	    w = d__ * 598.306 + 137.88;
	} else if (*body == 616) {
	    a0 = 40.58 - t * .036;
	    d0 = 83.53 - t * .004;
	    w = d__ * 587.289 + 296.14;
	} else if (*body == 617) {
	    a0 = 40.58 - t * .036;
	    d0 = 83.53 - t * .004;
	    w = d__ * 572.7891 + 162.92;
	} else if (*body == 618) {
	    a0 = 40.6 - t * .036;
	    d0 = 83.5 - t * .004;
	    w = d__ * 626.044 + 48.8;
	} else {
	    setmsg_("Body code # was not recognized.", (ftnlen)31);
	    errint_("#", body, (ftnlen)1);
	    sigerr_("SPICE(INVALIDBODYCODE)", (ftnlen)22);
	    chkout_("T_PCKANG", (ftnlen)8);
	    return 0;
	}
    } else if (*body / 100 == 7) {
	u1 = (t * 54991.87 + 115.75) * rpd_();
	u2 = (t * 41887.66 + 141.69) * rpd_();
	u3 = (t * 29927.35 + 135.03) * rpd_();
	u4 = (t * 25733.59 + 61.77) * rpd_();
	u5 = (t * 24471.46 + 249.32) * rpd_();
	u6 = (t * 22278.41 + 43.86) * rpd_();
	u7 = (t * 20289.42 + 77.66) * rpd_();
	u8 = (t * 16652.76 + 157.36) * rpd_();
	u9 = (t * 12872.63 + 101.81) * rpd_();
	u10 = (t * 8061.81 + 138.64) * rpd_();
	u11 = (102.23 - t * 2024.22) * rpd_();
	u12 = (t * 2863.96 + 316.41) * rpd_();
	u13 = (304.01 - t * 51.94) * rpd_();
	u14 = (308.71 - t * 93.17) * rpd_();
	u15 = (340.82 - t * 75.32) * rpd_();
	u16 = (259.14 - t * 504.81) * rpd_();
	if (*body == 701) {
	    a0 = sin(u13) * .29 + 257.43;
	    d0 = cos(u13) * .28 - 15.1;
	    w = 156.22 - d__ * 142.8356681 + sin(u12) * .05 + sin(u13) * .08;
	} else if (*body == 702) {
	    a0 = sin(u14) * .21 + 257.43;
	    d0 = cos(u14) * .2 - 15.1;
	    w = 108.05 - d__ * 86.8688923 - sin(u12) * .09 + sin(u14) * .06;
	} else if (*body == 703) {
	    a0 = sin(u15) * .29 + 257.43;
	    d0 = cos(u15) * .28 - 15.1;
	    w = 77.74 - d__ * 41.3514316 + sin(u15) * .08;
	} else if (*body == 704) {
	    a0 = sin(u16) * .16 + 257.43;
	    d0 = cos(u16) * .16 - 15.1;
	    w = 6.77 - d__ * 26.7394932 + sin(u16) * .04;
	} else if (*body == 705) {
	    a0 = sin(u11) * 4.41 + 257.43 - sin(u11 * 2) * .04;
	    d0 = cos(u11) * 4.25 - 15.08 - cos(u11 * 2) * .02;
	    w = 30.7 - d__ * 254.6906892 - sin(u12) * 1.27 + sin(u12 * 2) * 
		    .15 + sin(u11) * 1.15 - sin(u11 * 2) * .09;
	} else if (*body == 706) {
	    a0 = 257.31 - sin(u1) * .15;
	    d0 = cos(u1) * .14 - 15.18;
	    w = 127.69 - d__ * 1074.520573 - sin(u1) * .04;
	} else if (*body == 707) {
	    a0 = 257.31 - sin(u2) * .09;
	    d0 = cos(u2) * .09 - 15.18;
	    w = 130.35 - d__ * 956.406815 - sin(u2) * .03;
	} else if (*body == 708) {
	    a0 = 257.31 - sin(u3) * .16;
	    d0 = cos(u3) * .16 - 15.18;
	    w = 105.46 - d__ * 828.391476 - sin(u3) * .04;
	} else if (*body == 709) {
	    a0 = 257.31 - sin(u4) * .04;
	    d0 = cos(u4) * .04 - 15.18;
	    w = 59.16 - d__ * 776.581632 - sin(u4) * .01;
	} else if (*body == 710) {
	    a0 = 257.31 - sin(u5) * .17;
	    d0 = cos(u5) * .16 - 15.18;
	    w = 95.08 - d__ * 760.053169 - sin(u5) * .04;
	} else if (*body == 711) {
	    a0 = 257.31 - sin(u6) * .06;
	    d0 = cos(u6) * .06 - 15.18;
	    w = 302.56 - d__ * 730.125366 - sin(u6) * .02;
	} else if (*body == 712) {
	    a0 = 257.31 - sin(u7) * .09;
	    d0 = cos(u7) * .09 - 15.18;
	    w = 25.03 - d__ * 701.486587 - sin(u7) * .02;
	} else if (*body == 713) {
	    a0 = 257.31 - sin(u8) * .29;
	    d0 = cos(u8) * .28 - 15.18;
	    w = 314.9 - d__ * 644.631126 - sin(u8) * .08;
	} else if (*body == 714) {
	    a0 = 257.31 - sin(u9) * .03;
	    d0 = cos(u9) * .03 - 15.18;
	    w = 297.46 - d__ * 577.362817 - sin(u9) * .01;
	} else if (*body == 715) {
	    a0 = 257.31 - sin(u10) * .33;
	    d0 = cos(u10) * .31 - 15.18;
	    w = 91.24 - d__ * 472.545069 - sin(u10) * .09;
	} else {
	    setmsg_("Body code # was not recognized.", (ftnlen)31);
	    errint_("#", body, (ftnlen)1);
	    sigerr_("SPICE(INVALIDBODYCODE)", (ftnlen)22);
	    chkout_("T_PCKANG", (ftnlen)8);
	    return 0;
	}
    } else if (*body / 100 == 8) {
	n = (t * 52.316 + 357.85) * rpd_();
	n1 = (t * 62606.6 + 323.92) * rpd_();
	n2 = (t * 55064.2 + 220.51) * rpd_();
	n3 = (t * 46564.5 + 354.27) * rpd_();
	n4 = (t * 26109.4 + 75.31) * rpd_();
	n5 = (t * 14325.4 + 35.36) * rpd_();
	n6 = (t * 2824.6 + 142.61) * rpd_();
	n7 = (t * 52.316 + 177.85) * rpd_();
	if (*body == 801) {
	    a0 = 299.36 - sin(n7) * 32.35 - sin(n7 * 2) * 6.28 - sin(n7 * 3) *
		     2.08 - sin(n7 * 4) * .74 - sin(n7 * 5) * .28 - sin(n7 * 
		    6) * .11 - sin(n7 * 7) * .07 - sin(n7 * 8) * .02 - sin(n7 
		    * 9) * .01;
	    d0 = cos(n7) * 22.55 + 41.17 + cos(n7 * 2) * 2.1 + cos(n7 * 3) * 
		    .55 + cos(n7 * 4) * .16 + cos(n7 * 5) * .05 + cos(n7 * 6) 
		    * .02 + cos(n7 * 7) * .01;
	    w = 296.53 - d__ * 61.2572637 + sin(n7) * 22.25 + sin(n7 * 2) * 
		    6.73 + sin(n7 * 3) * 2.05 + sin(n7 * 4) * .74 + sin(n7 * 
		    5) * .28 + sin(n7 * 6) * .11 + sin(n7 * 7) * .05 + sin(n7 
		    * 8) * .02 + sin(n7 * 9) * .01;
	} else if (*body == 803) {
	    a0 = sin(n) * .7 + 299.36 - sin(n1) * 6.49 + sin(n1 * 2) * .25;
	    d0 = 43.36 - cos(n) * .51 - cos(n1) * 4.75 + cos(n1 * 2) * .09;
	    w = d__ * 1222.8441209 + 254.06 - sin(n) * .48 + sin(n1) * 4.4 - 
		    sin(n1 * 2) * .27;
	} else if (*body == 804) {
	    a0 = sin(n) * .7 + 299.36 - sin(n2) * .28;
	    d0 = 43.45 - cos(n) * .51 - cos(n2) * .21;
	    w = d__ * 1155.7555612 + 102.06 - sin(n) * .48 + sin(n2) * .19;
	} else if (*body == 805) {
	    a0 = sin(n) * .7 + 299.36 - sin(n3) * .09;
	    d0 = 43.45 - cos(n) * .51 - cos(n3) * .07;
	    w = d__ * 1075.7341562 + 306.51 - sin(n) * .49 + sin(n3) * .06;
	} else if (*body == 806) {
	    a0 = sin(n) * .7 + 299.36 - sin(n4) * .07;
	    d0 = 43.43 - cos(n) * .51 - cos(n4) * .05;
	    w = d__ * 839.6597686 + 258.09 - sin(n) * .48 + sin(n4) * .05;
	} else if (*body == 807) {
	    a0 = sin(n) * .7 + 299.36 - sin(n5) * .27;
	    d0 = 43.41 - cos(n) * .51 - cos(n5) * .2;
	    w = d__ * 649.053447 + 179.41 - sin(n) * .48 + sin(n5) * .19;
	} else if (*body == 808) {
	    a0 = sin(n) * .7 + 299.27 - sin(n6) * .05;
	    d0 = 42.91 - cos(n) * .51 - cos(n6) * .04;
	    w = d__ * 320.7654228 + 93.38 - sin(n) * .48 + sin(n6) * .04;
	} else {
	    setmsg_("Body code # was not recognized.", (ftnlen)31);
	    errint_("#", body, (ftnlen)1);
	    sigerr_("SPICE(INVALIDBODYCODE)", (ftnlen)22);
	    chkout_("T_PCKANG", (ftnlen)8);
	    return 0;
	}
    } else if (*body / 100 == 9) {
	if (*body == 901) {
	    a0 = 132.993;
	    d0 = -6.163;
	    w = d__ * 56.3625225 + 122.695;
	} else {
	    setmsg_("Body code # was not recognized.", (ftnlen)31);
	    errint_("#", body, (ftnlen)1);
	    sigerr_("SPICE(INVALIDBODYCODE)", (ftnlen)22);
	    chkout_("T_PCKANG", (ftnlen)8);
	    return 0;
	}
    } else if (*body == 2000001) {

/*        Ceres. */

	a0 = 291.;
	d0 = 59.;
	w = d__ * 952.1532 + 170.9;
    } else if (*body == 2000002) {

/*        Pallas. */

	a0 = 33.;
	d0 = -3.;
	w = d__ * 1105.8036 + 38.;
    } else if (*body == 2000004) {

/*        Vesta. */

	a0 = 305.8;
	d0 = 41.4;
	w = d__ * 1617.332776 + 292.;
    } else if (*body == 2000021) {

/*        Lutetia. */

	a0 = 52.;
	d0 = 12.;
	w = d__ * 1057.7515 + 94.;
    } else if (*body == 2431010) {

/*        Ida. */

	a0 = 168.76;
	d0 = -2.88;
	w = d__ * 1864.628007 + 274.05;
    } else if (*body == 2000433) {

/*        Eros. */

	a0 = 11.35;
	d0 = 17.22;
	w = d__ * 1639.38864745 + 326.07;
    } else if (*body == 2000511) {

/*        Davida. */

	a0 = 297.;
	d0 = 5.;
	w = d__ * 1684.4193549 + 268.1;
    } else if (*body == 9511010) {

/*        Gaspra. */

	a0 = 9.47;
	d0 = 26.7;
	w = d__ * 1226.911485 + 83.67;
    } else if (*body == 2002867) {

/*        Steins. */

	a0 = 90.;
	d0 = -62.;
	w = d__ * 1428.852332 + 93.94;
    } else if (*body == 2025143) {

/*        Itokawa. */

	a0 = 90.53;
	d0 = -66.3;
	w = d__ * 712.143 + 0.;
    } else if (*body == 1000093) {

/*        Tempel 1. */

	a0 = 294.;
	d0 = 73.;
	w = d__ * 212.064 + 252.63;
    } else if (*body == 1000005) {

/*        19/P Borrelly. */

	a0 = 218.5;
	d0 = -12.5;
	w = d__ * 390. + 0.;
    } else {
	setmsg_("Body code # was not recognized.", (ftnlen)31);
	errint_("#", body, (ftnlen)1);
	sigerr_("SPICE(INVALIDBODYCODE)", (ftnlen)22);
	chkout_("T_PCKANG", (ftnlen)8);
	return 0;
    }
    *ra = rpd_() * a0;
    *dec = rpd_() * d0;
    *pm = rpd_() * w;
    chkout_("T_PCKANG", (ftnlen)8);
    return 0;
/* $Procedure T_PCKRAD ( Text PCK body radii ) */

L_t_pckrad:
/* $ Abstract */

/*     Return reference ellipsoid radii provided for a specified */
/*     extended body by the IAU report [1]. */

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

/*     PCK */

/* $ Keywords */

/*     UTILITY */

/* $ Declarations */

/*     INTEGER               BODY */
/*     DOUBLE PRECISION      RADII  ( 3 ) */

/* $ Brief_I/O */

/*     Variable  I/O  Description */
/*     --------  ---  -------------------------------------------------- */
/*     BODY       I   BODY for which radii are to be returned. */
/*     RADII      O   Radii of reference ellipsoid for BODY. */

/* $ Detailed_Input */

/*     BODY           is the NAIF ID code of the body for radii */
/*                    are to be returned. */

/* $ Detailed_Output */

/*     RADII          are the three radii of the reference ellipsoid */
/*                    associated with the object designated by BODY. */
/*                    This radii are provided by the IAU report [1]. */

/* $ Parameters */

/*     None. */

/* $ Exceptions */

/*     1) If an unrecognized ID code is provided via the input argument */
/*        BODY, the error SPICE(INVALIDBODYCODE) is signaled. */

/* $ Files */

/*     The data provided by this routine are meant to be consistent with */
/*     the current IAU report [1] and should be consistent with the NAIF */
/*     text PCK */

/*        pck00009.tpc */

/*     This routine must be updated along with each NAIF text PCK update. */

/* $ Particulars */

/*     This routine supports comparison of reference ellipsoid radii */
/*     provided by the current NAIF text PCK against those provided by */
/*     the IAU report [1]. These tests serve to minimize the chance of */
/*     transcription error when a new PCK version is created.  Entering */
/*     the PCK constants both in the new PCK file and in T_PCKRAD */
/*     enables double-checking of the constants. */

/* $ Examples */

/*     See use in F_RDPCK. */

/* $ Restrictions */


/*     1) This routine must be kept consistent with the current IAU */
/*        report [1]. */

/* $ Literature_References */

/*     See header of the umbrella routine T_PCKEQ. */

/* $ Author_and_Institution */

/*     N.J. Bachman       (JPL) */

/* $ Version */

/* -    Test Utilities Version 3.0.0, 29-JAN-2011 (NJB) */

/*        Updated to reflect data from the 2009 IAU report. */

/* -    Test Utilities Version 2.0.0, 10-FEB-2010 (NJB) */

/* -& */
    chkin_("T_PCKRAD", (ftnlen)8);
    if (*body == 10) {
	vpack_(&c_b207, &c_b207, &c_b207, radii);
    } else if (*body == 199) {
	vpack_(&c_b210, &c_b210, &c_b210, radii);
    } else if (*body == 299) {
	vpack_(&c_b213, &c_b213, &c_b213, radii);
    } else if (*body == 399) {
	vpack_(&c_b216, &c_b216, &c_b218, radii);
    } else if (*body == 499) {
	vpack_(&c_b219, &c_b219, &c_b221, radii);
    } else if (*body == 599) {
	vpack_(&c_b222, &c_b222, &c_b224, radii);
    } else if (*body == 699) {
	vpack_(&c_b225, &c_b225, &c_b227, radii);
    } else if (*body == 799) {
	vpack_(&c_b228, &c_b228, &c_b230, radii);
    } else if (*body == 899) {
	vpack_(&c_b231, &c_b231, &c_b233, radii);
    } else if (*body == 999) {
	vpack_(&c_b234, &c_b234, &c_b234, radii);
    } else if (*body == 301) {
	vpack_(&c_b237, &c_b237, &c_b237, radii);
    } else if (*body == 401) {
	vpack_(&c_b240, &c_b241, &c_b242, radii);
    } else if (*body == 402) {
	vpack_(&c_b243, &c_b244, &c_b245, radii);
    } else if (*body == 501) {
	vpack_(&c_b246, &c_b247, &c_b248, radii);
    } else if (*body == 502) {
	vpack_(&c_b249, &c_b250, &c_b251, radii);
    } else if (*body == 503) {
	vpack_(&c_b252, &c_b252, &c_b252, radii);
    } else if (*body == 504) {
	vpack_(&c_b255, &c_b255, &c_b255, radii);
    } else if (*body == 505) {
	vpack_(&c_b258, &c_b259, &c_b260, radii);
    } else if (*body == 506) {
	vpack_(&c_b261, &c_b261, &c_b261, radii);
    } else if (*body == 507) {
	vpack_(&c_b264, &c_b264, &c_b264, radii);
    } else if (*body == 508) {
	vpack_(&c_b267, &c_b267, &c_b267, radii);
    } else if (*body == 509) {
	vpack_(&c_b270, &c_b270, &c_b270, radii);
    } else if (*body == 510) {
	vpack_(&c_b273, &c_b273, &c_b273, radii);
    } else if (*body == 511) {
	vpack_(&c_b276, &c_b276, &c_b276, radii);
    } else if (*body == 512) {
	vpack_(&c_b279, &c_b279, &c_b279, radii);
    } else if (*body == 513) {
	vpack_(&c_b282, &c_b282, &c_b282, radii);
    } else if (*body == 514) {
	vpack_(&c_b285, &c_b286, &c_b287, radii);
    } else if (*body == 515) {
	vpack_(&c_b279, &c_b289, &c_b290, radii);
    } else if (*body == 516) {
	vpack_(&c_b291, &c_b292, &c_b293, radii);
    } else if (*body == 601) {
	vpack_(&c_b294, &c_b295, &c_b296, radii);
    } else if (*body == 602) {
	vpack_(&c_b297, &c_b298, &c_b299, radii);
    } else if (*body == 603) {
	vpack_(&c_b300, &c_b301, &c_b302, radii);
    } else if (*body == 604) {
	vpack_(&c_b303, &c_b304, &c_b305, radii);
    } else if (*body == 605) {
	vpack_(&c_b306, &c_b307, &c_b308, radii);
    } else if (*body == 606) {
	vpack_(&c_b309, &c_b310, &c_b311, radii);
    } else if (*body == 607) {
	vpack_(&c_b312, &c_b313, &c_b314, radii);
    } else if (*body == 608) {
	vpack_(&c_b315, &c_b315, &c_b317, radii);
    } else if (*body == 609) {
	vpack_(&c_b318, &c_b319, &c_b320, radii);
    } else if (*body == 610) {
	vpack_(&c_b321, &c_b322, &c_b323, radii);
    } else if (*body == 611) {
	vpack_(&c_b324, &c_b325, &c_b326, radii);
    } else if (*body == 612) {
	vpack_(&c_b327, &c_b328, &c_b240, radii);
    } else if (*body == 613) {
	vpack_(&c_b330, &c_b331, &c_b279, radii);
    } else if (*body == 614) {
	vpack_(&c_b333, &c_b334, &c_b290, radii);
    } else if (*body == 615) {
	vpack_(&c_b336, &c_b337, &c_b338, radii);
    } else if (*body == 616) {
	vpack_(&c_b339, &c_b340, &c_b341, radii);
    } else if (*body == 617) {
	vpack_(&c_b342, &c_b343, &c_b344, radii);
    } else if (*body == 618) {
	vpack_(&c_b345, &c_b346, &c_b347, radii);
    } else if (*body == 632) {
	vpack_(&c_b348, &c_b348, &c_b348, radii);
    } else if (*body == 633) {
	vpack_(&c_b351, &c_b352, &c_b353, radii);
    } else if (*body == 634) {
	vpack_(&c_b354, &c_b355, &c_b356, radii);
    } else if (*body == 635) {
	vpack_(&c_b357, &c_b358, &c_b359, radii);
    } else if (*body == 649) {
	vpack_(&c_b356, &c_b356, &c_b356, radii);
    } else if (*body == 701) {
	vpack_(&c_b363, &c_b364, &c_b365, radii);
    } else if (*body == 702) {
	vpack_(&c_b366, &c_b366, &c_b366, radii);
    } else if (*body == 703) {
	vpack_(&c_b369, &c_b369, &c_b369, radii);
    } else if (*body == 704) {
	vpack_(&c_b372, &c_b372, &c_b372, radii);
    } else if (*body == 705) {
	vpack_(&c_b375, &c_b376, &c_b377, radii);
    } else if (*body == 706) {
	vpack_(&c_b240, &c_b240, &c_b240, radii);
    } else if (*body == 707) {
	vpack_(&c_b276, &c_b276, &c_b276, radii);
    } else if (*body == 708) {
	vpack_(&c_b384, &c_b384, &c_b384, radii);
    } else if (*body == 709) {
	vpack_(&c_b387, &c_b387, &c_b387, radii);
    } else if (*body == 710) {
	vpack_(&c_b390, &c_b390, &c_b390, radii);
    } else if (*body == 711) {
	vpack_(&c_b287, &c_b287, &c_b287, radii);
    } else if (*body == 712) {
	vpack_(&c_b396, &c_b396, &c_b396, radii);
    } else if (*body == 713) {
	vpack_(&c_b390, &c_b390, &c_b390, radii);
    } else if (*body == 714) {
	vpack_(&c_b402, &c_b402, &c_b402, radii);
    } else if (*body == 715) {
	vpack_(&c_b405, &c_b405, &c_b405, radii);
    } else if (*body == 801) {
	vpack_(&c_b408, &c_b408, &c_b408, radii);
    } else if (*body == 802) {
	vpack_(&c_b411, &c_b411, &c_b411, radii);
    } else if (*body == 803) {
	vpack_(&c_b414, &c_b414, &c_b414, radii);
    } else if (*body == 804) {
	vpack_(&c_b264, &c_b264, &c_b264, radii);
    } else if (*body == 805) {
	vpack_(&c_b420, &c_b420, &c_b420, radii);
    } else if (*body == 806) {
	vpack_(&c_b423, &c_b423, &c_b423, radii);
    } else if (*body == 807) {
	vpack_(&c_b426, &c_b426, &c_b426, radii);
    } else if (*body == 808) {
	vpack_(&c_b429, &c_b430, &c_b431, radii);
    } else if (*body == 901) {
	vpack_(&c_b432, &c_b432, &c_b432, radii);
    } else if (*body == 1000005) {

/*        Borrelly. (Effective radius) */

	vpack_(&c_b435, &c_b435, &c_b435, radii);
    } else if (*body == 1000036) {

/*        Halley. */

	vpack_(&c_b289, &c_b439, &c_b439, radii);
    } else if (*body == 1000093) {

/*        Tempel 1.  (Effective radius) */

	vpack_(&c_b441, &c_b441, &c_b441, radii);
    } else if (*body == 1000107) {

/*        Wild 2. */

	vpack_(&c_b444, &c_b445, &c_b354, radii);
    } else if (*body == 2000001) {

/*        Ceres. */

	vpack_(&c_b447, &c_b447, &c_b449, radii);
    } else if (*body == 2000004) {

/*        Vesta. */

	vpack_(&c_b450, &c_b451, &c_b452, radii);
    } else if (*body == 2000021) {

/*        Lutetia. */

	vpack_(&c_b453, &c_b454, &c_b455, radii);
    } else if (*body == 2431010) {

/*        Ida. */

	vpack_(&c_b456, &c_b273, &c_b458, radii);
    } else if (*body == 2000253) {

/*        Mathilde. */

	vpack_(&c_b402, &c_b460, &c_b461, radii);
    } else if (*body == 2000433) {

/*        Eros. */

	vpack_(&c_b293, &c_b463, &c_b463, radii);
    } else if (*body == 2000511) {

/*        Davida. */

	vpack_(&c_b465, &c_b466, &c_b467, radii);
    } else if (*body == 9511010) {

/*        Gaspra. */

	vpack_(&c_b242, &c_b469, &c_b470, radii);
    } else if (*body == 2002867) {

/*        Steins. */

	vpack_(&c_b471, &c_b472, &c_b473, radii);
    } else if (*body == 2004179) {

/*        Toutatis. */

	vpack_(&c_b474, &c_b475, &c_b476, radii);
    } else if (*body == 2025143) {

/*        Itokawa. */

	vpack_(&c_b477, &c_b478, &c_b479, radii);
    } else {
	setmsg_("Body code # was not recognized.", (ftnlen)31);
	errint_("#", body, (ftnlen)1);
	sigerr_("SPICE(INVALIDBODYCODE)", (ftnlen)22);
	chkout_("T_PCKRAD", (ftnlen)8);
	return 0;
    }
    chkout_("T_PCKRAD", (ftnlen)8);
    return 0;
} /* t_pckeq__ */

/* Subroutine */ int t_pckeq__(integer *body, doublereal *et, doublereal *ra, 
	doublereal *dec, doublereal *pm, integer *angset, integer *radset, 
	doublereal *radii)
{
    return t_pckeq__0_(0, body, et, ra, dec, pm, angset, radset, radii);
    }

/* Subroutine */ int t_pckast__(integer *angset)
{
    return t_pckeq__0_(1, (integer *)0, (doublereal *)0, (doublereal *)0, (
	    doublereal *)0, (doublereal *)0, angset, (integer *)0, (
	    doublereal *)0);
    }

/* Subroutine */ int t_pckrst__(integer *radset)
{
    return t_pckeq__0_(2, (integer *)0, (doublereal *)0, (doublereal *)0, (
	    doublereal *)0, (doublereal *)0, (integer *)0, radset, (
	    doublereal *)0);
    }

/* Subroutine */ int t_pckang__(integer *body, doublereal *et, doublereal *ra,
	 doublereal *dec, doublereal *pm)
{
    return t_pckeq__0_(3, body, et, ra, dec, pm, (integer *)0, (integer *)0, (
	    doublereal *)0);
    }

/* Subroutine */ int t_pckrad__(integer *body, doublereal *radii)
{
    return t_pckeq__0_(4, body, (doublereal *)0, (doublereal *)0, (doublereal 
	    *)0, (doublereal *)0, (integer *)0, (integer *)0, radii);
    }

