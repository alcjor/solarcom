/*
   tutils_c.h  --- prototypes for CSPICE test utility code


-Disclaimer

   THIS SOFTWARE AND ANY RELATED MATERIALS WERE CREATED BY THE
   CALIFORNIA INSTITUTE OF TECHNOLOGY (CALTECH) UNDER A U.S.
   GOVERNMENT CONTRACT WITH THE NATIONAL AERONAUTICS AND SPACE
   ADMINISTRATION (NASA). THE SOFTWARE IS TECHNOLOGY AND SOFTWARE
   PUBLICLY AVAILABLE UNDER U.S. EXPORT LAWS AND IS PROVIDED "AS-IS"
   TO THE RECIPIENT WITHOUT WARRANTY OF ANY KIND, INCLUDING ANY
   WARRANTIES OF PERFORMANCE OR MERCHANTABILITY OR FITNESS FOR A
   PARTICULAR USE OR PURPOSE (AS SET FORTH IN UNITED STATES UCC
   SECTIONS 2312-2313) OR FOR ANY PURPOSE WHATSOEVER, FOR THE
   SOFTWARE AND RELATED MATERIALS, HOWEVER USED.

   IN NO EVENT SHALL CALTECH, ITS JET PROPULSION LABORATORY, OR NASA
   BE LIABLE FOR ANY DAMAGES AND/OR COSTS, INCLUDING, BUT NOT
   LIMITED TO, INCIDENTAL OR CONSEQUENTIAL DAMAGES OF ANY KIND,
   INCLUDING ECONOMIC DAMAGE OR INJURY TO PROPERTY AND LOST PROFITS,
   REGARDLESS OF WHETHER CALTECH, JPL, OR NASA BE ADVISED, HAVE
   REASON TO KNOW, OR, IN FACT, SHALL KNOW OF THE POSSIBILITY.

   RECIPIENT BEARS ALL RISK RELATING TO QUALITY AND PERFORMANCE OF
   THE SOFTWARE AND ANY RELATED MATERIALS, AND AGREES TO INDEMNIFY
   CALTECH AND NASA FOR ALL THIRD-PARTY CLAIMS RESULTING FROM THE
   ACTIONS OF RECIPIENT IN THE USE OF THE SOFTWARE.

-Version

   -tutils_c Version 3.0.0, 09-FEB-2017 (NJB) (EDW)

      Added protypes for:

         natdsk_
         natdsk_c
         t_cg__
         t_cg_c
         t_elds2z__
         t_elds2z_c
         t_secds2__        
         t_secds2_c
         t_smldsk__
         t_smldsk_c
         t_torus__
         t_torus_c
         t_wrtplt__
         t_wrtplt_c
         t_wrtplz_
         t_wrtplz_c
         zzellplt_
         zzellplt_c
         zzpsball_
         zzpsball_c
         zzpsbox_
         zzpsbox_c     
         zzpspoly_
         zzpspoly_c
         zzpsscal_
         zzpsscal_c
         zzpstube_
         zzpstube_c
         zzpsun_
         zzpsun_c    
         zzpsxfrm_
         zzpsxfrm_c
         zzpsxlat_
         zzpsxlat_c
         zzt_boddsk_c

      Note that zzellplt_ is an f2c'd routine derived from
      a support library routine.

   -tutils_c Version 2.1.0, 24-MAY-2010 (EDW)

      Changed tsetup_c and tsetup_ prototypes to correspond to
      Version 2.0 of TSETUP (tsetup.for). This version has the command
      line sting as an input argument to the routines rather than
      obtain the string from a GETCML call in TSETUP.

      Added protype for:
      
         zztstek_

   -tutils_c Version 2.0.1, 29-JAN-2009 (EDW)

      Added protype for:
      
         zztstlsk_c
         zznatik_
         zznatpck_
         zznatspk_

   -TUTILS_C Version 2.0.0, 09-SEP-2008 (NJB)

      Added protypes for 

         natik_
         natpck_
         natspk_
         t_surfpv__
         
   -TUTILS_C Version 1.0.3, 06-NOV-2007 (EDW)

      Added protypes for:
      
         zztstck3_
         zztstsclk_, 
         t_randd__
         zztstspkcov
         zztstckcov.

   -TUTILS_C Version 1.0.2, 01-FEB-2006 (EDW)

      Added protypes for: 
      
         zztstlsk_
         zztstpck
         zztstspk_

   -TUTILS_C Version 1.0.1, 29-NOV-2004 (EDW)

      Wrapped long lines to allow delivery to NAIF Configuration
      Management system.

   -TUTILS_C Version 1.0.0, 15-JUL-1999 (NJB)
   
      Initial release.
   
*/

#include "SpiceUsr.h"
#include "SpiceZfc.h"

#ifndef TUTILS_C

   #define TUTILS_C
   
   /*
   Prototypes of test utility wrappers:
   */

   void chckad_c ( ConstSpiceChar    * name,
                   SpiceDouble       * array,
                   ConstSpiceChar    * comp,
                   SpiceDouble       * exp,
                   SpiceInt            size,
                   SpiceDouble         tol,
                   SpiceBoolean      * ok   );
                   
                    
   void chckai_c ( ConstSpiceChar    * name,
                   SpiceInt          * array,
                   ConstSpiceChar    * comp,
                   SpiceInt          * exp,
                   SpiceInt            size,
                   SpiceBoolean      * ok   );
                   
                   
   void chcksc_c ( ConstSpiceChar    * name,
                   ConstSpiceChar    * val,
                   ConstSpiceChar    * comp,
                   ConstSpiceChar    * exp,
                   SpiceBoolean      * ok    ); 

   
   void chcksd_c ( ConstSpiceChar   * name,
                   SpiceDouble        val,
                   ConstSpiceChar   * comp,
                   SpiceDouble        exp,
                   SpiceDouble        tol,
                   SpiceBoolean     * ok    );
                   
   void chcksi_c ( ConstSpiceChar    * name,
                   SpiceInt            val,
                   ConstSpiceChar    * comp,
                   SpiceInt            exp,
                   SpiceInt            tol,
                   SpiceBoolean      * ok   ); 


   void chcksl_c ( ConstSpiceChar    * name,
                   SpiceBoolean        val,
                   SpiceBoolean        exp,
                   SpiceBoolean      * ok   ); 


   void chckxc_c ( SpiceBoolean        except,
                   ConstSpiceChar    * shmsg,
                   SpiceBoolean      * ok     ); 


   void natdsk_c ( ConstSpiceChar      * dsk,
                   ConstSpiceChar      * aframe,
                   SpiceInt              anlon,
                   SpiceInt              anlat,
                   ConstSpiceChar      * bframe,
                   SpiceInt              bnlon,
                   SpiceInt              bnlat   );


   SpiceDouble rand_c ( SpiceDouble     lb, 
                        SpiceDouble     ub  );
                     
                     
   SpiceInt    rani_c ( SpiceInt        lb, 
                        SpiceInt        ub  );
                     
                     
   void tcase_c  ( ConstSpiceChar    * title ); 


   void tclose_c ( void ); 


   void topen_c  ( ConstSpiceChar    * name ); 
   
   
   void tsetup_c ( ConstSpiceChar    * cmline,
                   ConstSpiceChar    * lognam,
                   ConstSpiceChar    * versn  ); 
   
   
   void tstatd_c ( SpiceDouble         et,
                   SpiceDouble         matrix[3][3],
                   SpiceDouble         angvel[3]    );
                   
                    
   void tstck3_c ( ConstSpiceChar    * cknm,
                   ConstSpiceChar    * sclknm,
                   SpiceBoolean        loadck,
                   SpiceBoolean        loadsc,
                   SpiceBoolean        keepsc,
                   SpiceInt          * handle  );
                   
                   
   void tstek_c ( ConstSpiceChar     * file,
                  SpiceInt             fileno,
                  SpiceInt             mxrows,
                  SpiceBoolean         load,
                  SpiceInt           * handle,
                  SpiceBoolean       * ok     );
                  

   void tstent_c ( SpiceInt           fileno,
                   ConstSpiceChar   * table,
                   SpiceInt           segno,
                   ConstSpiceChar   * column,
                   SpiceInt           rowno,
                   SpiceInt           nmax,
                   SpiceInt           vallen,
                   SpiceInt         * nelts,
                   void             * cvals,
                   SpiceDouble      * dvals,
                   SpiceInt         * ivals,
                   SpiceDouble      * tvals,
                   SpiceBoolean     * isnull  );
                   

   void tstlsk_c ( void );


   void tstmsg_c ( ConstSpiceChar    * marker,
                   ConstSpiceChar    * message );
  

   void tstmsi_c ( SpiceInt            ival );


   void tstmsd_c ( SpiceDouble         dval );


   void tstmsc_c ( ConstSpiceChar    * msg );


   void tstmsf_c ( SpiceDouble         dval );


   void tstmso_c ( SpiceInt            ival,
                   ConstSpiceChar    * marker );
                    
                    
   void tstmst_c ( SpiceInt            ival,
                   ConstSpiceChar    * marker );
                    
                    
   void tstpck_c ( ConstSpiceChar    * namepc,
                   SpiceBoolean        loadpc,
                   SpiceBoolean        keeppc ); 
                   
                   
   void tstsch_c ( ConstSpiceChar     * table,
                   SpiceInt             mxrows,
                   SpiceInt             namlen,
                   SpiceInt             declen,
                   SpiceInt           * segtyp,
                   SpiceInt           * nrows,
                   SpiceInt           * ncols,
                   void               * cnames,
                   SpiceInt           * cclass,
                   SpiceEKDataType    * dtypes,
                   SpiceInt           * stlens,
                   SpiceInt           * dims,
                   SpiceBoolean       * indexd,
                   SpiceBoolean       * nullok,
                   void               * decls   );
                   
                   
   void tstspk_c ( ConstSpiceChar    * file,
                   SpiceBoolean        load,
                   SpiceInt          * handle );
                   
                   
   void tsttxt_c ( ConstSpiceChar    * namtxt,
                   void              * txt,
                   SpiceInt            nlines,
                   SpiceInt            lenvals,
                   SpiceBoolean        load,
                   SpiceBoolean        keep     ); 


   void t_cg_c   ( SpiceInt          bodyid,
                   SpiceInt          surfid,
                   ConstSpiceChar  * frame,
                   ConstSpiceChar  * dsk     );


   void t_elds2z_c ( SpiceInt            bodyid,
                     SpiceInt            surfid,
                     ConstSpiceChar    * frame,
                     SpiceInt            nlon,
                     SpiceInt            nlat,
                     ConstSpiceChar    * dsk    );


   void t_pck08_c (   ConstSpiceChar    * namepc,
                      SpiceBoolean        loadpc,
                      SpiceBoolean        keeppc ); 


   void t_secds2_c ( SpiceInt          bodyid,
                     SpiceInt          surfid,
                     ConstSpiceChar  * frname,
                     SpiceDouble       first,
                     SpiceDouble       last,
                     SpiceInt          corsys,
                     ConstSpiceDouble  corpar [SPICE_DSK_NSYPAR],
                     ConstSpiceDouble  bounds [2][2],
                     SpiceDouble       a,
                     SpiceDouble       b,
                     SpiceDouble       c,
                     SpiceInt          nlon,
                     SpiceInt          nlat,
                     SpiceBoolean      makvtl,
                     SpiceBoolean      usepad,
                     ConstSpiceChar  * dsk                       );


   void t_smldsk_c ( SpiceInt            bodyid,
                     SpiceInt            surfid,
                     ConstSpiceChar    * frame,
                     ConstSpiceChar    * dsk    );


   int t_success__  ( logical        * ok );

   
   void t_success_c ( SpiceBoolean   * ok );


   void t_torus_c ( SpiceInt          bodyid,
                    SpiceInt          surfid,
                    ConstSpiceChar  * frname,
                    SpiceInt          npolyv,
                    SpiceInt          ncross,
                    SpiceDouble       r,
                    SpiceDouble       rcross,
                    SpiceDouble       center [3],
                    SpiceDouble       normal [3],
                    ConstSpiceChar  * dsk         );


   void t_wrtplt_c ( SpiceInt            bodyid,
                     SpiceInt            surfid,
                     ConstSpiceChar    * frame,
                     SpiceDouble         first,
                     SpiceDouble         last,
                     SpiceInt            corsys,
                     ConstSpiceDouble    corpar [],
                     ConstSpiceDouble    bounds [2][2],
                     SpiceInt            nv,
                     SpiceInt            np,
                     ConstSpiceDouble    usrvrt [][3],
                     ConstSpiceInt       usrplt [][3],
                     SpiceBoolean        makvtl,
                     ConstSpiceChar    * dsk           );


   void t_wrtplz_c ( SpiceInt            bodyid,
                     SpiceInt            surfid,
                     ConstSpiceChar    * frame,
                     SpiceInt            nv,
                     SpiceInt            np,
                     ConstSpiceDouble    usrvrt [][3],
                     ConstSpiceInt       usrplt [][3],
                     ConstSpiceChar    * dsk           );


   void zzellplt_c ( SpiceDouble      a,
                     SpiceDouble      b,
                     SpiceDouble      c,
                     SpiceInt         nlon,
                     SpiceInt         nlat,
                     SpiceCell      * vout,
                     SpiceCell      * pout  );

   void zzpsball_c ( SpiceDouble     r,
                     SpiceInt        nlon,
                     SpiceInt        nlat,
                     SpiceCell     * vout,
                     SpiceCell     * pout  );

   void zzpsbox_c ( SpiceDouble      a,
                    SpiceDouble      b,
                    SpiceDouble      c,
                    SpiceCell     *  vout,
                    SpiceCell     *  pout );


   void zzpspoly_c ( SpiceInt        n,
                     SpiceDouble     vrtces[][2],
                     SpiceCell     * vout,
                     SpiceCell     * pout        );


   void zzpsscal_c ( SpiceDouble    scale,
                     SpiceCell    * v1,
                     SpiceCell    * vout  );


   void zzpstube_c ( SpiceInt            n,
                     ConstSpiceDouble    vrtces[][3],
                     void             (* crvsub)( SpiceDouble   t,
                                                  SpiceDouble   curve[3],
                                                  SpiceDouble   deriv[3],
                                                  SpiceDouble  *twist    ),
                     SpiceInt            nsamp,
                     SpiceBoolean        closed,
                     SpiceCell         * vout,
                     SpiceCell         * pout                              );


   void zzpsun_c ( SpiceCell        * v1,
                   SpiceCell        * p1,
                   SpiceCell        * v2,
                   SpiceCell        * p2,
                   SpiceCell        * vout,
                   SpiceCell        * pout );

   void zzpsxfrm_c ( SpiceCell         * v1,
                     ConstSpiceDouble    xform[3][3],
                     SpiceCell         * vout        );


   void zzpsxlat_c ( SpiceCell         * v1,
                     ConstSpiceDouble    offset[3],
                     SpiceCell         * vout       );


   void zztstlsk_c ( ConstSpiceChar * namels );

   void zztstspkcov( ConstSpiceChar * SPK );


   void zztstckcov( ConstSpiceChar * CK );


   void zzt_boddsk_c ( ConstSpiceChar  * dsk,
                       ConstSpiceChar  * body,
                       ConstSpiceChar  * fixref,
                       SpiceBoolean      load,
                       SpiceInt        * handle );


   /*
   The following mess is the concatenation of the prototypes for each
   C routine generated by running f2c on the Fortran test utilities.
   */

 
extern H_f begdat_(char *ret_val, ftnlen ret_val_len); 
extern H_f begtxt_(char *ret_val, ftnlen ret_val_len); 
extern int chckac_(char *name__, char *array, char *comp, char *exp__, 
integer *size, logical *ok, ftnlen name_len, ftnlen array_len, 
ftnlen comp_len, ftnlen exp_len);
/*:ref: tststy_ 14 4 13 13 124 124 */
/*:ref: tstlgs_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: tstlog_ 14 3 13 12 124 */
/*:ref: verbos_ 12 0 */
extern int chckad_(char *name__, doublereal *array, char *comp,
doublereal *exp__, integer *size, doublereal *tol, logical *ok, ftnlen
name_len, ftnlen comp_len);
/*:ref: tststy_ 14 4 13 13 124 124 */
/*:ref: tstlgs_ 14 4 13 13 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: repmd_ 14 8 13 13 7 4 13 124 124 124 */
/*:ref: tstlog_ 14 3 13 12 124 */
/*:ref: vsepg_ 7 3 7 7 4 */
/*:ref: vdistg_ 7 3 7 7 4 */
/*:ref: vnormg_ 7 2 7 4 */
/*:ref: halfpi_ 7 0 */
/*:ref: verbos_ 12 0 */
extern int chckai_(char *name__, integer *array, char *comp, integer
*exp__, integer *size, logical *ok, ftnlen name_len, ftnlen comp_len);
/*:ref: tststy_ 14 4 13 13 124 124 */
/*:ref: tstlgs_ 14 4 13 13 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: tstlog_ 14 3 13 12 124 */
/*:ref: verbos_ 12 0 */
extern int chckoc_(char *name__, char *array, char *order, integer
*size, logical *ok, ftnlen name_len, ftnlen array_len, ftnlen
order_len);
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: tststy_ 14 4 13 13 124 124 */
/*:ref: tstlgs_ 14 4 13 13 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: tstlog_ 14 3 13 12 124 */
/*:ref: verbos_ 12 0 */
extern int chckod_(char *name__, doublereal *array, char *order,
integer *size, logical *ok, ftnlen name_len, ftnlen order_len);
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: tststy_ 14 4 13 13 124 124 */
/*:ref: tstlgs_ 14 4 13 13 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: repmd_ 14 8 13 13 7 4 13 124 124 124 */
/*:ref: tstlog_ 14 3 13 12 124 */
/*:ref: verbos_ 12 0 */
extern int chckoi_(char *name__, integer *array, char *order, integer
*size, logical *ok, ftnlen name_len, ftnlen order_len);
/*:ref: tststy_ 14 4 13 13 124 124 */
/*:ref: tstlgs_ 14 4 13 13 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: tstlog_ 14 3 13 12 124 */
/*:ref: verbos_ 12 0 */
extern int chcksc_(char *name__, char *val, char *comp, char *exp__,
logical *ok, ftnlen name_len, ftnlen val_len, ftnlen comp_len, ftnlen
exp_len);
/*:ref: tststy_ 14 4 13 13 124 124 */
/*:ref: tstlgs_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: verbos_ 12 0 */
/*:ref: tstlog_ 14 3 13 12 124 */
extern int chcksd_(char *name__, doublereal *val, char *comp,
doublereal *exp__, doublereal *tol, logical *ok, ftnlen name_len,
ftnlen comp_len);
/*:ref: tststy_ 14 4 13 13 124 124 */
/*:ref: tstlgs_ 14 4 13 13 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: repmd_ 14 8 13 13 7 4 13 124 124 124 */
/*:ref: verbos_ 12 0 */
/*:ref: tstlog_ 14 3 13 12 124 */
extern int chcksi_(char *name__, integer *val, char *comp, integer
*exp__, integer *tol, logical *ok, ftnlen name_len, ftnlen comp_len);
/*:ref: tststy_ 14 4 13 13 124 124 */
/*:ref: tstlgs_ 14 4 13 13 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: verbos_ 12 0 */
/*:ref: tstlog_ 14 3 13 12 124 */
extern int chcksl_(char *name__, logical *val, logical *exp__, logical
*ok, ftnlen name_len);
/*:ref: tststy_ 14 4 13 13 124 124 */
/*:ref: tstlgs_ 14 4 13 13 124 124 */
/*:ref: verbos_ 12 0 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: tstlog_ 14 3 13 12 124 */
extern int chckxc_(logical *except, char *short__, logical *ok, ftnlen
short_len);
/*:ref: tststy_ 14 4 13 13 124 124 */
/*:ref: tstlgs_ 14 4 13 13 124 124 */
/*:ref: seton_ 12 2 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: getmsg_ 14 4 13 13 124 124 */
/*:ref: qcktrc_ 14 2 13 124 */
/*:ref: reset_ 14 0 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: tstlog_ 14 3 13 12 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: verbos_ 12 0 */
extern int cstart_(void);
/*:ref: clpool_ 14 0 */
/*:ref: zzbodrst_ 14 0 */
/*:ref: ssizei_ 14 2 4 4 */
/*:ref: dafhof_ 14 1 4 */
/*:ref: cardi_ 4 1 4 */
/*:ref: spkuef_ 14 1 4 */
/*:ref: ckupf_ 14 1 4 */
/*:ref: pckuof_ 14 1 4 */
/*:ref: dafcls_ 14 1 4 */
/*:ref: dashof_ 14 1 4 */
/*:ref: ekuef_ 14 1 4 */
/*:ref: zzekscln_ 14 0 */
/*:ref: dascls_ 14 1 4 */
/*:ref: kfiles_ 14 0 */
extern int filreg_(char *file, ftnlen file_len);
extern int tfiles_(char *file, ftnlen file_len);
extern int kfiles_(void);
/*:ref: ison_ 12 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: kilfil_ 14 2 13 124 */
extern logical ison_(char *system, ftnlen system_len);
extern logical isoff_(char *system, ftnlen system_len);
extern logical seton_(char *system, ftnlen system_len);
extern logical setoff_(char *system, ftnlen system_len);
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
extern int kilfil_(char *filnam, ftnlen filnam_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: exists_ 12 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: getlun_ 14 1 4 */
extern int mprint_(doublereal *mat, integer *rows, integer *cols, char
*fmt, ftnlen fmt_len);
/*:ref: nblen_ 4 2 13 124 */
/*:ref: dpfmt_ 14 5 7 13 13 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: dpstrf_ 14 6 7 4 13 13 124 124 */
/*:ref: tostdo_ 14 2 13 124 */
extern int multix_(integer *basidx, integer *n, integer *dims__,
integer *offset, integer *coords);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rmaini_ 14 4 4 4 4 4 */
extern int natdsk_(char *dsk, char *aframe, integer *anlon, integer
*anlat, char *bframe, integer *bnlon, integer *bnlat, ftnlen dsk_len,
ftnlen aframe_len, ftnlen bframe_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: exists_ 12 2 13 124 */
/*:ref: delfil_ 14 2 13 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: jyear_ 7 0 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: twopi_ 7 0 */
/*:ref: halfpi_ 7 0 */
/*:ref: t_eldsk2__ 14 17 4 4 13 7 7 4 7 7 7 7 7 4 4 12 13 124 124 */
extern int natik_(char *ik, char *spk, char *pck, logical *loadik,
logical *keepik, ftnlen ik_len, ftnlen spk_len, ftnlen pck_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: spklef_ 14 3 13 4 124 */
/*:ref: ldpool_ 14 2 13 124 */
/*:ref: bodvrd_ 14 7 13 13 4 4 7 124 124 */
/*:ref: spkpos_ 14 11 13 7 13 13 13 7 7 124 124 124 124 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: edlimb_ 14 5 7 7 7 7 7 */
/*:ref: el2cgv_ 14 4 7 7 7 7 */
/*:ref: pxform_ 14 6 13 13 7 7 124 124 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vlcom3_ 14 7 7 7 7 7 7 7 7 */
/*:ref: begdat_ 13 2 13 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: begtxt_ 13 2 13 124 */
/*:ref: repmd_ 14 8 13 13 7 4 13 124 124 124 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: writln_ 14 3 13 4 124 */
/*:ref: tfiles_ 14 2 13 124 */
/*:ref: spkuef_ 14 1 4 */
/*:ref: chkout_ 14 2 13 124 */
extern int natpck_(char *namepc, logical *loadpc, logical *keeppc,
ftnlen namepc_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: begdat_ 13 2 13 124 */
/*:ref: begtxt_ 13 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: writln_ 14 3 13 4 124 */
/*:ref: ldpool_ 14 2 13 124 */
/*:ref: tfiles_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
extern int natspk_(char *file, logical *load, integer *handle, ftnlen file_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: spcopn_ 14 5 13 13 4 124 124 */
/*:ref: clight_ 7 0 */
/*:ref: twopi_ 7 0 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: vrotv_ 14 4 7 7 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: jyear_ 7 0 */
/*:ref: spkw05_ 14 13 4 4 4 13 7 7 13 7 4 7 7 124 124 */
/*:ref: spd_ 7 0 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: spkw08_ 14 14 4 4 4 13 7 7 13 4 4 7 7 7 124 124 */
/*:ref: dafcls_ 14 1 4 */
/*:ref: spklef_ 14 3 13 4 124 */
/*:ref: tfiles_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
extern int shoerr_(void);
/*:ref: errdev_ 14 4 13 13 124 124 */
extern int t_chbigr__(integer *ndim, integer *degp, doublereal *cp,
doublereal *x2s, doublereal *x, doublereal *work, doublereal *p,
doublereal *itgrlp);
/*:ref: return_ 12 0 */
extern int t_dcheb__(D_fp func, doublereal *x, doublereal *delta,
integer *nterms, integer *nrtain, doublereal *f, doublereal *df);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: chbfit_ 14 6 207 7 7 4 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: chbint_ 14 6 7 4 7 7 7 7 */
extern int t_getsa__(integer *targ, doublereal *et, char *ref, char
*abcorr, integer *obs, doublereal *pcorr, doublereal *dpcorr, ftnlen
ref_len, ftnlen abcorr_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzprscor_ 14 3 13 12 124 */
/*:ref: spkgeo_ 14 7 4 7 13 4 7 7 124 */
/*:ref: qderiv_ 14 5 4 7 7 7 7 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: spkltc_ 14 10 4 7 13 13 7 7 7 7 124 124 */
/*:ref: zzstelab_ 14 6 12 7 7 7 7 7 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: failed_ 12 0 */
/*:ref: sxform_ 14 6 13 13 7 7 124 124 */
/*:ref: vsclip_ 14 2 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: mxvg_ 14 5 7 7 4 4 7 */
extern int t_gftrep__(doublereal *cnfine, char *msgpre, char *msgsuf,
doublereal *ivbeg, doublereal *ivend, doublereal *et, integer *nmax,
integer *mw, integer *ncalls, doublereal *cnflog, char *msglog,
doublereal *replog, integer *seqlog, ftnlen msgpre_len, ftnlen 
msgsuf_len, ftnlen msglog_len);
extern int t_gfuini__(void);
extern int t_gfrepi__(doublereal *cnfine, char *msgpre, char *msgsuf,
ftnlen msgpre_len, ftnlen msgsuf_len);
extern int t_gfrini__(integer *nmax, integer *mw, integer *ncalls,
integer *seqlog, doublereal *cnflog, char *msglog, ftnlen msglog_len);
extern int t_gfrepu__(doublereal *ivbeg, doublereal *ivend, doublereal *et);
extern int t_gfrplo__(integer *nmax, integer *ncalls, integer *seqlog,
doublereal *replog);
extern int t_gfrepf__(void);
extern int t_gfrtrm__(integer *nmax, integer *ncalls, integer *seqlog);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: ssized_ 14 2 4 7 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: copyd_ 14 2 7 7 */
/*:ref: movei_ 14 3 4 4 4 */
extern int t_ilumin__(char *method, char *target, doublereal *et, char *fixref,
 char *abcorr, char *obsrvr, doublereal *spoint, doublereal *trgepc,
 doublereal *srfvec, doublereal *phase, doublereal *solar, doublereal *emissn, 
ftnlen method_len, ftnlen target_len, ftnlen fixref_len, ftnlen abcorr_len,
 ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: zzprscor_ 14 3 13 12 124 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: bods2c_ 14 4 13 4 12 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: cmprss_ 14 7 13 4 13 13 124 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: spkezp_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: clight_ 7 0 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: pxform_ 14 6 13 13 7 7 124 124 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: mtxv_ 14 3 7 7 7 */
/*:ref: stelab_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vdist_ 7 2 7 7 */
/*:ref: touchd_ 7 1 7 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: surfnm_ 14 5 7 7 7 7 7 */
/*:ref: vsep_ 7 2 7 7 */
extern int t_pck08__(char *namepc, logical *loadpc, logical *keeppc,
 ftnlen namepc_len);
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: begdat_ 13 2 13 124 */
/*:ref: begtxt_ 13 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: writln_ 14 3 13 4 124 */
/*:ref: ldpool_ 14 2 13 124 */
/*:ref: tfiles_ 14 2 13 124 */
extern int t_pck09__(char *namepc, logical *loadpc, logical *keeppc,
 ftnlen namepc_len);
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: clearc_ 14 3 4 13 124 */
/*:ref: begtxt_ 13 2 13 124 */
/*:ref: begdat_ 13 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: writln_ 14 3 13 4 124 */
/*:ref: ldpool_ 14 2 13 124 */
/*:ref: tfiles_ 14 2 13 124 */
extern int t_pck10__(char *namepc, logical *loadpc, logical *keeppc, 
ftnlen namepc_len);
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: clearc_ 14 3 4 13 124 */
/*:ref: begdat_ 13 2 13 124 */
/*:ref: begtxt_ 13 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: writln_ 14 3 13 4 124 */
/*:ref: ldpool_ 14 2 13 124 */
/*:ref: tfiles_ 14 2 13 124 */
extern int t_pckeq__(integer *body, doublereal *et, doublereal *ra,
doublereal *dec, doublereal *pm, integer *angset, integer *radset,
doublereal *radii);
extern int t_pckast__(integer *angset);
extern int t_pckrst__(integer *radset);
extern int t_pckang__(integer *body, doublereal *et, doublereal *ra,
doublereal *dec, doublereal *pm);
extern int t_pckrad__(integer *body, doublereal *radii);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: scardi_ 14 2 4 4 */
/*:ref: insrti_ 14 2 4 4 */
/*:ref: spd_ 7 0 */
/*:ref: rpd_ 7 0 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: vpack_ 14 4 7 7 7 7 */
extern doublereal t_randd__(doublereal *lower, doublereal *upper,
integer *seed);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: t_urand__ 7 1 4 */
extern integer t_randsign__(integer *seed);
/*:ref: t_urand__ 7 1 4 */
extern int t_spkchb__(char *target, char *center, char *frame, doublereal
*first, doublereal *last, integer *npos, integer *nvel, doublereal *work,
doublereal *poscof, doublereal *velcof, ftnlen target_len, ftnlen 
center_len, ftnlen frame_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: bods2c_ 14 4 13 4 12 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: t_stcini__ 7 6 4 13 13 4 124 124 */
/*:ref: chbfit_ 14 6 207 7 7 4 7 7 */
/*:ref: t_getx__ 7 :*/
/*:ref: t_gety__ 7 :*/
/*:ref: t_getz__ 7 :*/
/*:ref: t_getdx__ 7 :*/
/*:ref: t_getdy__ 7 :*/
/*:ref: t_getdz__ 7 :*/
extern int t_stat__(char *act, char *name__, logical *ok, integer
*number, ftnlen act_len, ftnlen name_len);
extern int t_begin__(char *name__, ftnlen name_len);
extern int t_name__(char *name__, ftnlen name_len);
extern int t_success__(logical *ok);
extern int t_fcount__(integer *number);
extern int t_case__(char *name__, ftnlen name_len);
extern int t_cfail__(void);
extern int t_cpass__(logical *ok);
extern int t_cnum__(integer *number);
extern int t_cname__(char *name__, ftnlen name_len);
extern int t_anybad__(logical *ok);
extern int t_trace__(char *act, char *name__, ftnlen act_len, ftnlen name_len);
/*:ref: reset_ 14 0 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
extern int t_subsol__(char *method, char *target, doublereal *et, char
*abcorr, char *obsrvr, doublereal *spoint, ftnlen method_len, ftnlen
target_len, ftnlen abcorr_len, ftnlen obsrvr_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: bods2c_ 14 4 13 4 12 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: bodvar_ 14 5 4 13 4 7 124 */
/*:ref: cidfrm_ 14 5 4 4 13 12 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: ltime_ 14 7 7 4 13 4 7 7 124 */
/*:ref: spkpos_ 14 11 13 7 13 13 13 7 7 124 124 124 124 */
/*:ref: nearpt_ 14 6 7 7 7 7 7 7 */
/*:ref: surfpt_ 14 7 7 7 7 7 7 7 12 */
extern int t_surfpv__(doublereal *stvrtx, doublereal *stdir, doublereal
*a, doublereal *b, doublereal *c__, doublereal *stx, logical *found);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: vzero_ 12 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: dpmax_ 7 0 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: dvhat_ 14 2 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: touchd_ 7 1 7 */
/*:ref: vlcom3_ 14 7 7 7 7 7 7 7 7 */
extern int t_topker__(char *fk, char *spk, char *target, char *trgref, 
integer *nsites, integer *sitids, char *sitnms, doublereal *sitpos,
 char *sitfnm, integer *sitfid, doublereal *first, doublereal *last,
 integer *axes, doublereal *angles, ftnlen fk_len, ftnlen spk_len, 
ftnlen target_len, ftnlen trgref_len, ftnlen sitnms_len, ftnlen sitfnm_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: bods2c_ 14 4 13 4 12 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: spkopn_ 14 6 13 13 4 4 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: spkw08_ 14 14 4 4 4 13 7 7 13 4 4 7 7 7 124 124 */
/*:ref: spkcls_ 14 1 4 */
/*:ref: exists_ 12 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: writln_ 14 3 13 4 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: intstr_ 14 3 4 13 124 */
/*:ref: ljucrs_ 14 5 4 13 13 124 124 */
/*:ref: dpr_ 7 0 */
extern int t_torutl__(doublereal *r__, doublereal *center, doublereal
*normal, doublereal *t, doublereal *curve, doublereal *deriv,
doublereal *twist);
extern int t_torcrv__(doublereal *t, doublereal *curve, doublereal
*deriv, doublereal *twist);
extern int t_torset__(doublereal *r__, doublereal *center, doublereal *normal);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: return_ 12 0 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: twopi_ 7 0 */
/*:ref: vlcom3_ 14 7 7 7 7 7 7 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: frame_ 14 3 7 7 7 */
extern doublereal t_trajfn__(integer *targ, doublereal *et, char *ref,
char *abcorr, integer *obs, ftnlen ref_len, ftnlen abcorr_len);
extern doublereal t_stcini__(integer *targ, char *ref, char *abcorr,
integer *obs, ftnlen ref_len, ftnlen abcorr_len);
extern doublereal t_getx__(doublereal *et);
extern doublereal t_gety__(doublereal *et);
extern doublereal t_getz__(doublereal *et);
extern doublereal t_getdx__(doublereal *et);
extern doublereal t_getdy__(doublereal *et);
extern doublereal t_getdz__(doublereal *et);
extern doublereal t_getsx__(doublereal *et);
extern doublereal t_getsy__(doublereal *et);
extern doublereal t_getsz__(doublereal *et);
extern doublereal t_getdsx__(doublereal *et);
extern doublereal t_getdsy__(doublereal *et);
extern doublereal t_getdsz__(doublereal *et);
extern doublereal t_getlt__(doublereal *et);
extern doublereal t_getdlt__(doublereal *et);
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: spkez_ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: t_getsa__ 14 9 4 7 13 13 4 7 7 124 124 */
/*:ref: spkssb_ 14 5 4 7 13 7 124 */
/*:ref: spkltc_ 14 10 4 7 13 13 7 7 7 7 124 124 */
extern doublereal t_urand__(integer *seed);
extern int t_wclk01__(char *fname, char *coms, integer *clkid, char *kerid, 
char *timsys, integer *nfield, doublereal *moduli, doublereal *offset,
char *delim, integer *nparts, doublereal *pstart, doublereal *pstop, 
integer *ncoeff, doublereal *coeffs, ftnlen fname_len, ftnlen coms_len, 
ftnlen kerid_len, ftnlen timsys_len, ftnlen delim_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: exists_ 12 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: writln_ 14 3 13 4 124 */
/*:ref: cardc_ 4 2 13 124 */
/*:ref: begdat_ 13 2 13 124 */
/*:ref: ljust_ 14 4 13 13 124 124 */
/*:ref: lastnb_ 4 2 13 124 */
/*:ref: tparse_ 14 5 13 7 13 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: eqstr_ 12 4 13 13 124 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: dpfmt_ 14 5 7 13 13 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: begtxt_ 13 2 13 124 */
extern int t_wrdsk2__(integer *bodyid, integer *surfid, char *frname, 
doublereal *first, doublereal *last, doublereal *a, doublereal *b, 
doublereal *c__, integer *corsys, doublereal *corpar, doublereal *bounds, 
integer *nlon, integer *nlat, integer *nv, integer *np, doublereal *usrvrt, 
integer *usrplt, logical *makvtl, logical *usepad, integer *npolyv, 
integer *ncross, doublereal *r__, doublereal *rcross, doublereal *center, 
doublereal *normal, char *dsk, ftnlen frname_len, ftnlen dsk_len);
extern int t_wrtplt__(integer *bodyid, integer *surfid, char *frname, 
doublereal *first, doublereal *last, integer *corsys, doublereal *corpar, 
doublereal *bounds, integer *nv, integer *np, doublereal *usrvrt, 
integer *usrplt, logical *makvtl, char *dsk, ftnlen frname_len, ftnlen dsk_len);
extern int t_wrtplz__(integer *bodyid, integer *surfid, char *frname, 
integer *nv, integer *np, doublereal *usrvrt, integer *usrplt, char *dsk, 
ftnlen frname_len, ftnlen dsk_len);
extern int t_eldsk2__(integer *bodyid, integer *surfid, char *frname, 
doublereal *first, doublereal *last, integer *corsys, doublereal *corpar, 
doublereal *bounds, doublereal *a, doublereal *b, doublereal *c__, 
integer *nlon, integer *nlat, logical *makvtl, char *dsk, ftnlen frname_len, 
ftnlen dsk_len);
extern int t_elds2z__(integer *bodyid, integer *surfid, char *frname, 
integer *nlon, integer *nlat, char *dsk, ftnlen frname_len, ftnlen dsk_len);
extern int t_smldsk__(integer *bodyid, integer *surfid, char *frname, 
char *dsk, ftnlen frname_len, ftnlen dsk_len);
extern int t_cg__(integer *bodyid, integer *surfid, char *frname, 
char *dsk, ftnlen frname_len, ftnlen dsk_len);
extern int t_secds2__(integer *bodyid, integer *surfid, char *frname, 
doublereal *first, doublereal *last, integer *corsys, doublereal *corpar, 
doublereal *bounds, doublereal *a, doublereal *b, doublereal *c__, 
integer *nlon, integer *nlat, logical *makvtl, logical *usepad, 
char *dsk, ftnlen 
frname_len, ftnlen dsk_len);
extern int t_torus__(integer *bodyid, integer *surfid, char *frname, 
integer *npolyv, integer *ncross, doublereal *r__, doublereal *rcross, 
doublereal *center, doublereal *normal, char *dsk, ftnlen frname_len, 
ftnlen dsk_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: return_ 12 0 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: dskmi2_ 14 14 4 7 4 4 7 4 4 4 4 12 4 4 7 4 */
/*:ref: dskrb2_ 14 8 4 7 4 4 4 7 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: exists_ 12 2 13 124 */
/*:ref: dasopw_ 14 3 13 4 124 */
/*:ref: dskopn_ 14 6 13 13 4 4 124 124 */
/*:ref: dskw02_ 14 22 4 4 4 4 13 4 7 7 7 7 7 7 7 7 7 4 7 4 4 7 4 124 */
/*:ref: dskcls_ 14 2 4 12 */
/*:ref: twopi_ 7 0 */
/*:ref: halfpi_ 7 0 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: jyear_ 7 0 */
/*:ref: zzellplt_ 14 11 7 7 7 4 4 4 4 4 7 4 4 */
/*:ref: bodvcd_ 14 6 4 13 4 4 7 124 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: ssized_ 14 2 4 7 */
/*:ref: ssizei_ 14 2 4 4 */
/*:ref: zzt_cg__ 14 2 7 4 */
/*:ref: cardd_ 4 1 7 */
/*:ref: cardi_ 4 1 4 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: zzchrlat_ 14 3 7 7 7 */
/*:ref: zzellsec_ 14 15 7 7 7 7 7 7 7 4 4 4 4 4 7 4 4 */
/*:ref: t_torset__ 14 3 7 7 7 */
/*:ref: t_torcrv__ 14 4 7 7 7 7 */
/*:ref: frame_ 14 3 7 7 7 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vrotv_ 14 4 7 7 7 7 */
/*:ref: zzpstube_ 14 7 4 7 214 4 12 7 4 */
extern int t_xform__(doublereal *xform, doublereal *rminus, doublereal
*rplus, doublereal *delta, doublereal *nrmerr, doublereal *deterr,
doublereal *drverr, doublereal *drlerr, doublereal *drdiff);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: vdistg_ 7 3 7 7 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: xpose_ 14 2 7 7 */
/*:ref: det_ 7 1 7 */
/*:ref: qderiv_ 14 5 4 7 7 7 7 */
/*:ref: failed_ 12 0 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: dvhat_ 14 2 7 7 */
/*:ref: vrelg_ 7 3 7 7 4 */
/*:ref: vsubg_ 14 4 7 7 4 7 */
extern int t_zzstelab__(logical *xmit, doublereal *accobs, doublereal *vobs, 
doublereal *starg, doublereal *scorr, doublereal *dscorr);
/*:ref: vsep_ 7 2 7 7 */
/*:ref: pi_ 7 0 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: dpr_ 7 0 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: dvhat_ 14 2 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vperp_ 14 3 7 7 7 */
/*:ref: unorm_ 14 3 7 7 7 */
/*:ref: vlcom3_ 14 7 7 7 7 7 7 7 7 */
/*:ref: clight_ 7 0 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
extern int t_zzstlabn__(logical *xmit, doublereal *accobs, doublereal *vobs, 
doublereal *starg, doublereal *scorr, doublereal *dscorr);
/*:ref: return_ 12 0 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: dvhat_ 14 2 7 7 */
/*:ref: vperp_ 14 3 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: clight_ 7 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: vzero_ 12 1 7 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: vlcom3_ 14 7 7 7 7 7 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: qderiv_ 14 5 4 7 7 7 7 */
extern int tcase_(char *title, ftnlen title_len);
/*:ref: isoff_ 12 2 13 124 */
/*:ref: chckxc_ 14 4 12 13 12 124 */
/*:ref: setoff_ 12 2 13 124 */
/*:ref: tstmof_ 14 0 */
/*:ref: qcktrc_ 14 2 13 124 */
/*:ref: t_trace__ 14 4 13 13 124 124 */
/*:ref: chcksc_ 14 9 13 13 13 13 12 124 124 124 124 */
/*:ref: tstlip_ 14 0 */
/*:ref: t_case__ 14 2 13 124 */
/*:ref: tstrul_ 14 0 */
/*:ref: verbos_ 12 0 */
/*:ref: tststy_ 14 4 13 13 124 124 */
/*:ref: tstlgs_ 14 4 13 13 124 124 */
/*:ref: t_cname__ 14 2 13 124 */
/*:ref: tstlog_ 14 3 13 12 124 */
/*:ref: reset_ 14 0 */
/*:ref: errdev_ 14 4 13 13 124 124 */
extern int tclose_(void);
/*:ref: isoff_ 12 2 13 124 */
/*:ref: chckxc_ 14 4 12 13 12 124 */
/*:ref: setoff_ 12 2 13 124 */
/*:ref: reset_ 14 0 */
/*:ref: errdev_ 14 4 13 13 124 124 */
/*:ref: tststy_ 14 4 13 13 124 124 */
/*:ref: tstlip_ 14 0 */
/*:ref: tstrul_ 14 0 */
/*:ref: tstcbl_ 14 0 */
/*:ref: t_name__ 14 2 13 124 */
/*:ref: t_fcount__ 14 1 4 */
/*:ref: t_cnum__ 14 1 4 */
/*:ref: t_success__ 14 1 12 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: tstlog_ 14 3 13 12 124 */
/*:ref: tstlgs_ 14 4 13 13 124 124 */
/*:ref: repmct_ 14 9 13 13 4 13 13 124 124 124 124 */
/*:ref: curtim_ 14 2 13 124 */
/*:ref: t_anybad__ 14 1 12 */
/*:ref: tstglf_ 14 2 13 124 */
/*:ref: tstfil_ 14 6 13 13 13 124 124 124 */
/*:ref: tstslf_ 14 2 13 124 */
/*:ref: tstget_ 14 6 13 13 13 124 124 124 */
/*:ref: tstioa_ 14 2 13 124 */
/*:ref: tstioh_ 14 2 13 124 */
/*:ref: tstwln_ 14 2 13 124 */
/*:ref: tbegf_ 14 0 */
/*:ref: tfname_ 14 2 13 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: tstioc_ 14 2 13 124 */
/*:ref: cstart_ 14 0 */
/*:ref: finish_ 14 0 */
extern int topen_(char *name__, ftnlen name_len);
extern int tbegf_(void);
extern int tfname_(char *name__, ftnlen name_len);
/*:ref: isoff_ 12 2 13 124 */
/*:ref: chckxc_ 14 4 12 13 12 124 */
/*:ref: setoff_ 12 2 13 124 */
/*:ref: tstmof_ 14 0 */
/*:ref: qcktrc_ 14 2 13 124 */
/*:ref: t_trace__ 14 4 13 13 124 124 */
/*:ref: reset_ 14 0 */
/*:ref: errdev_ 14 4 13 13 124 124 */
/*:ref: cstart_ 14 0 */
/*:ref: chcksc_ 14 9 13 13 13 13 12 124 124 124 124 */
/*:ref: tstlip_ 14 0 */
/*:ref: tstrul_ 14 0 */
/*:ref: tstcbl_ 14 0 */
/*:ref: t_name__ 14 2 13 124 */
/*:ref: t_fcount__ 14 1 4 */
/*:ref: t_cnum__ 14 1 4 */
/*:ref: t_success__ 14 1 12 */
/*:ref: tststy_ 14 4 13 13 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: tstlog_ 14 3 13 12 124 */
/*:ref: tstlgs_ 14 4 13 13 124 124 */
/*:ref: repmct_ 14 9 13 13 4 13 13 124 124 124 124 */
/*:ref: t_begin__ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
extern int tsetup_(char *cmline, char *lognam, char *versn, ftnlen cmline_len, 
ftnlen lognam_len, ftnlen versn_len);
/*:ref: setoff_ 12 2 13 124 */
/*:ref: tstlgs_ 14 4 13 13 124 124 */
/*:ref: nextwd_ 14 6 13 13 13 124 124 124 */
/*:ref: ucase_ 14 4 13 13 124 124 */
/*:ref: verbon_ 12 0 */
/*:ref: tstlcy_ 14 0 */
/*:ref: seton_ 12 2 13 124 */
/*:ref: lckout_ 14 2 13 124 */
/*:ref: tstopl_ 14 4 13 13 124 124 */
/*:ref: erract_ 14 4 13 13 124 124 */
/*:ref: errdev_ 14 4 13 13 124 124 */
extern int tstatd_(doublereal *et, doublereal *matrix, doublereal *angvel);
/*:ref: axisar_ 14 3 7 7 7 */
/*:ref: mxm_ 14 3 7 7 7 */
/*:ref: lstled_ 4 3 7 4 7 */
/*:ref: xpose_ 14 2 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vscl_ 14 3 7 7 7 */
extern int tstck3_(char *cknm, char *sclknm, logical *loadck, logical *loadsc, 
logical *keepsc, integer *handle, ftnlen cknm_len, ftnlen sclknm_len);
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: begdat_ 13 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: tparse_ 14 5 13 7 13 124 124 */
/*:ref: shelld_ 14 2 4 7 */
/*:ref: tstatd_ 14 3 7 7 7 */
/*:ref: m2q_ 14 2 7 7 */
/*:ref: spcopn_ 14 5 13 13 4 124 124 */
/*:ref: ckw03_ 14 15 4 7 7 4 13 12 13 4 7 7 7 4 7 124 124 */
/*:ref: dafcls_ 14 1 4 */
/*:ref: ldpool_ 14 2 13 124 */
/*:ref: cklpf_ 14 3 13 4 124 */
/*:ref: tfiles_ 14 2 13 124 */
extern int tstckn_(char *cknm, char *sclknm, logical *loadck, logical *loadsc, 
logical *keepsc, integer *handle, ftnlen cknm_len, ftnlen sclknm_len);
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: begdat_ 13 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: tparse_ 14 5 13 7 13 124 124 */
/*:ref: shelld_ 14 2 4 7 */
/*:ref: tstatd_ 14 3 7 7 7 */
/*:ref: m2q_ 14 2 7 7 */
/*:ref: spcopn_ 14 5 13 13 4 124 124 */
/*:ref: ckw03_ 14 15 4 7 7 4 13 12 13 4 7 7 7 4 7 124 124 */
/*:ref: dafcls_ 14 1 4 */
/*:ref: ldpool_ 14 2 13 124 */
/*:ref: cklpf_ 14 3 13 4 124 */
/*:ref: tfiles_ 14 2 13 124 */
extern int tstek_(char *file, integer *fileno, integer *mxrows, logical *load, 
integer *handle, ftnlen file_len);
/*:ref: exists_ 12 2 13 124 */
/*:ref: delfil_ 14 2 13 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: ekopn_ 14 6 13 13 4 4 124 124 */
/*:ref: tstsch_ 14 16 13 4 4 4 4 13 4 4 4 4 12 12 13 124 124 124 */
/*:ref: maxai_ 14 4 4 4 4 4 */
/*:ref: erract_ 14 4 13 13 124 124 */
/*:ref: errdev_ 14 4 13 13 124 124 */
/*:ref: errprt_ 14 4 13 13 124 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ekifld_ 14 11 4 13 4 4 13 13 4 4 124 124 124 */
/*:ref: tstent_ 14 15 4 13 4 13 4 4 4 13 7 4 7 12 124 124 124 */
/*:ref: ekaclc_ 14 10 4 4 13 13 4 12 4 4 124 124 */
/*:ref: ekacld_ 14 9 4 4 13 7 4 12 4 4 124 */
/*:ref: ekacli_ 14 9 4 4 13 4 4 12 4 4 124 */
/*:ref: ekffld_ 14 3 4 4 4 */
/*:ref: ekcls_ 14 1 4 */
/*:ref: eklef_ 14 3 13 4 124 */
/*:ref: tfiles_ 14 2 13 124 */
extern int tstent_(integer *fileno, char *table, integer *segno, char *column, 
integer *rowno, integer *nmax, integer *nelts, char *cvals, doublereal *dvals, 
integer *ivals, doublereal *tvals, logical *isnull, ftnlen table_len, 
ftnlen column_len, ftnlen cvals_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: tstsch_ 14 16 13 4 4 4 4 13 4 4 4 4 12 12 13 124 124 124 */
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: prefix_ 14 5 13 4 13 124 124 */
/*:ref: odd_ 12 1 4 */
/*:ref: rtrim_ 4 2 13 124 */
extern int tstfil_(char *pattrn, char *port, char *file, ftnlen pattrn_len, 
ftnlen port_len, ftnlen file_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: fststr_ 14 4 13 13 124 124 */
/*:ref: exists_ 12 2 13 124 */
/*:ref: nxtstr_ 14 6 13 13 13 124 124 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: tstopn_ 14 4 13 13 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: reset_ 14 0 */
/*:ref: tstslf_ 14 2 13 124 */
extern int tstio_(char *line, char *name__, char *port, logical *ok, 
logical *status, ftnlen line_len, ftnlen name_len, ftnlen port_len);
extern int tstopn_(char *port, char *name__, ftnlen port_len, ftnlen name_len);
extern int tstioh_(char *port, ftnlen port_len);
extern int tstioa_(char *port, ftnlen port_len);
extern int tstgst_(char *port, logical *status, ftnlen port_len);
extern int tstpst_(char *port, logical *status, ftnlen port_len);
extern int tstioc_(char *port, ftnlen port_len);
extern int tstios_(char *port, ftnlen port_len);
extern int tstior_(char *port, logical *ok, ftnlen port_len);
extern int tstwln_(char *line, ftnlen line_len);
extern int finish_(void);
extern int lckout_(char *port, ftnlen port_len);
/*:ref: isrchc_ 4 5 13 4 13 124 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: failed_ 12 0 */
/*:ref: writln_ 14 3 13 4 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: tostdo_ 14 2 13 124 */
/*:ref: zztstre_ 14 0 */
extern int tstlgr_(char *messge, logical *errlog, char *gstyle, char *fstyle, 
char *marker, integer *int__, doublereal *dp, ftnlen messge_len, 
ftnlen gstyle_len, ftnlen fstyle_len, ftnlen marker_len);
extern int tstlog_(char *messge, logical *errlog, ftnlen messge_len);
extern int tstlgs_(char *gstyle, char *fstyle, ftnlen gstyle_len, 
ftnlen fstyle_len);
extern int tststy_(char *gstyle, char *fstyle, ftnlen gstyle_len, 
ftnlen fstyle_len);
extern int vrblog_(char *messge, logical *errlog, ftnlen messge_len);
extern int tstmsg_(char *marker, char *messge, ftnlen marker_len, 
ftnlen messge_len);
extern int tstmsi_(integer *int__);
extern int tstmsd_(doublereal *dp);
extern int tstmsf_(doublereal *dp);
extern int tstmsc_(char *messge, ftnlen messge_len);
extern int tstmso_(integer *int__, char *marker, ftnlen marker_len);
extern int tstmst_(integer *int__, char *marker, ftnlen marker_len);
extern int tstmof_(void);
extern int zztstre_(void);
/*:ref: t_name__ 14 2 13 124 */
/*:ref: t_cname__ 14 2 13 124 */
/*:ref: t_fcount__ 14 1 4 */
/*:ref: t_cfail__ 14 0 */
/*:ref: tstfil_ 14 6 13 13 13 124 124 124 */
/*:ref: tstget_ 14 6 13 13 13 124 124 124 */
/*:ref: tstioa_ 14 2 13 124 */
/*:ref: tstioh_ 14 2 13 124 */
/*:ref: tstwln_ 14 2 13 124 */
/*:ref: nicepr_1__ 14 5 13 13 214 124 124 */
/*:ref: verbos_ 12 0 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: repmd_ 14 8 13 13 7 4 13 124 124 124 */
/*:ref: repmf_ 14 10 13 13 7 4 13 13 124 124 124 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: repmot_ 14 9 13 13 4 13 13 124 124 124 124 */
/*:ref: repmct_ 14 9 13 13 4 13 13 124 124 124 124 */
extern int tstlip_(void);
extern int tstcbl_(void);
extern int tstlcy_(void);
extern int tstlcn_(void);
/*:ref: verbos_ 12 0 */
/*:ref: tststy_ 14 4 13 13 124 124 */
/*:ref: t_cpass__ 14 1 12 */
/*:ref: t_cnum__ 14 1 4 */
/*:ref: tstlog_ 14 3 13 12 124 */
/*:ref: tstlgs_ 14 4 13 13 124 124 */
/*:ref: t_cname__ 14 2 13 124 */
extern int tstlsk_(void);
/*:ref: begdat_ 13 2 13 124 */
/*:ref: newfil_1__ 14 4 13 13 124 124 */
/*:ref: tsttxt_ 14 7 13 13 4 12 12 124 124 */
extern int tstopl_(char *lognam, char *versn, ftnlen lognam_len, 
ftnlen versn_len);
/*:ref: tstfil_ 14 6 13 13 13 124 124 124 */
/*:ref: failed_ 12 0 */
/*:ref: curtim_ 14 2 13 124 */
/*:ref: pltfrm_ 14 4 4 4 13 124 */
/*:ref: tkvrsn_ 14 4 13 13 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: tstlog_ 14 3 13 12 124 */
/*:ref: tstsav_ 14 6 13 13 13 124 124 124 */
extern int tstpck_(char *namepc, logical *loadpc, logical *keeppc, 
ftnlen namepc_len);
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: begdat_ 13 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: ldpool_ 14 2 13 124 */
/*:ref: tfiles_ 14 2 13 124 */
extern int tstrul_(void);
/*:ref: verbos_ 12 0 */
/*:ref: tstlog_ 14 3 13 12 124 */
extern int tstsav_(char *env, char *versn, char *time, ftnlen env_len, 
ftnlen versn_len, ftnlen time_len);
extern int tstget_(char *env, char *versn, char *time, ftnlen env_len, 
ftnlen versn_len, ftnlen time_len);
extern int tstslf_(char *env, ftnlen env_len);
extern int tstglf_(char *env, ftnlen env_len);
extern int tstsch_(char *table, integer *mxrows, integer *segtyp, 
integer *nrows, integer *ncols, char *cnames, integer *cclass, 
integer *dtypes, integer *stlens, integer *dims__, logical *indexd, 
logical *nullok, char *decls, ftnlen table_len, ftnlen cnames_len, 
ftnlen decls_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cleari_ 14 2 4 4 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: suffix_ 14 5 13 4 13 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
extern int tstspk_(char *file, logical *load, integer *handle, 
ftnlen file_len);
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: spcopn_ 14 5 13 13 4 124 124 */
/*:ref: tststc_ 14 2 4 4 */
/*:ref: tstst_ 14 8 4 7 13 4 7 4 7 124 */
/*:ref: frmnam_ 14 3 4 13 124 */
/*:ref: spkw05_ 14 13 4 4 4 13 7 7 13 7 4 7 7 124 124 */
/*:ref: spkw08_ 14 14 4 4 4 13 7 7 13 4 4 7 7 7 124 124 */
/*:ref: dafcls_ 14 1 4 */
/*:ref: spklef_ 14 3 13 4 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: tfiles_ 14 2 13 124 */
extern int tstst_(integer *body, doublereal *et, char *segid, integer *frame, 
doublereal *state, integer *center, doublereal *gm, ftnlen segid_len);
extern int tststc_(integer *body, integer *center);
/*:ref: prop2b_ 14 4 7 7 7 7 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: pi_ 7 0 */
/*:ref: conics_ 14 3 7 7 7 */
/*:ref: dpr_ 7 0 */
/*:ref: latrec_ 14 4 7 7 7 7 */
extern int tsttxt_(char *namtxt, char *txt, integer *nlines, logical *load, 
logical *keep, ftnlen namtxt_len, ftnlen txt_len);
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: writla_ 14 4 4 13 4 124 */
/*:ref: ldpool_ 14 2 13 124 */
/*:ref: tfiles_ 14 2 13 124 */
extern int tstvrs_(char *verstr, ftnlen verstr_len);
extern logical verbos_(void);
extern logical verbon_(void);
extern logical verboff_(void);
extern int zzellplt_(doublereal *a, doublereal *b, doublereal *c__, 
integer *nlon, integer *nlat, integer *maxv, integer *maxp, integer *nv, 
doublereal *verts, integer *np, integer *plates);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: vpack_ 14 4 7 7 7 7 */
/*:ref: pi_ 7 0 */
/*:ref: latrec_ 14 4 7 7 7 7 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: zzgrdplt_ 14 5 4 4 12 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: zzcapplt_ 14 7 4 12 12 4 4 4 4 */
extern int zznatik_(char *nameik, char *spk, char *pck, ftnlen nameik_len, 
ftnlen spk_len, ftnlen pck_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: furnsh_ 14 2 13 124 */
/*:ref: bodvrd_ 14 7 13 13 4 4 7 124 124 */
/*:ref: spkpos_ 14 11 13 7 13 13 13 7 7 124 124 124 124 */
/*:ref: vminus_ 14 2 7 7 */
/*:ref: edlimb_ 14 5 7 7 7 7 7 */
/*:ref: el2cgv_ 14 4 7 7 7 7 */
/*:ref: pxform_ 14 6 13 13 7 7 124 124 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: vhat_ 14 2 7 7 */
/*:ref: vlcom3_ 14 7 7 7 7 7 7 7 7 */
/*:ref: begdat_ 13 2 13 124 */
/*:ref: repmc_ 14 8 13 13 13 13 124 124 124 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: begtxt_ 13 2 13 124 */
/*:ref: repmd_ 14 8 13 13 7 4 13 124 124 124 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: vlcom_ 14 5 7 7 7 7 7 */
/*:ref: unload_ 14 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: writln_ 14 3 13 4 124 */
/*:ref: chkout_ 14 2 13 124 */
extern int zznatpck_(char *namepc, ftnlen namepc_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: begdat_ 13 2 13 124 */
/*:ref: begtxt_ 13 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: writln_ 14 3 13 4 124 */
/*:ref: chkout_ 14 2 13 124 */
extern int zznatspk_(char *file, ftnlen file_len);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: spcopn_ 14 5 13 13 4 124 124 */
/*:ref: clight_ 7 0 */
/*:ref: twopi_ 7 0 */
/*:ref: vscl_ 14 3 7 7 7 */
/*:ref: vrotv_ 14 4 7 7 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: jyear_ 7 0 */
/*:ref: spkw05_ 14 13 4 4 4 13 7 7 13 7 4 7 7 124 124 */
/*:ref: spd_ 7 0 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: spkw08_ 14 14 4 4 4 13 7 7 13 4 4 7 7 7 124 124 */
/*:ref: dafcls_ 14 1 4 */
/*:ref: chkout_ 14 2 13 124 */
extern int zzpsball_(doublereal *r__, integer *nlon, integer *nlat, 
doublereal *vout, integer *pout);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: sizei_ 4 1 4 */
/*:ref: zzellplt_ 14 11 7 7 7 4 4 4 4 4 7 4 4 */
/*:ref: failed_ 12 0 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: scardi_ 14 2 4 4 */
extern int zzpsbox_(doublereal *a, doublereal *b, doublereal *c__, 
doublereal *vout, integer *pout);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sizei_ 4 1 4 */
/*:ref: errdp_ 14 3 13 7 124 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: movei_ 14 3 4 4 4 */
/*:ref: scardi_ 14 2 4 4 */
extern int zzpspoly_(integer *n, doublereal *vrtces, doublereal *vout, 
integer *pout);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sizei_ 4 1 4 */
/*:ref: vdotg_ 7 3 7 7 4 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: scardi_ 14 2 4 4 */
extern int zzpspyr_(integer *n, doublereal *vrtces, doublereal *h__, 
doublereal *vout, integer *pout);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sizei_ 4 1 4 */
/*:ref: vdotg_ 7 3 7 7 4 */
/*:ref: cleard_ 14 2 4 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: scardi_ 14 2 4 4 */
extern int zzpsscal_(doublereal *scale, doublereal *v1, doublereal *vout);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: scardd_ 14 2 4 7 */
extern int zzpstube_(integer *n, doublereal *vrtces, S_fp crvsub, 
integer *nsamp, logical *closed, doublereal *vout, integer *pout);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: sizei_ 4 1 4 */
/*:ref: vhatip_ 14 1 7 */
/*:ref: vcrss_ 14 3 7 7 7 */
/*:ref: vdot_ 7 2 7 7 */
/*:ref: vrotv_ 14 4 7 7 7 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: vnorm_ 7 1 7 */
/*:ref: vsub_ 14 3 7 7 7 */
/*:ref: vequ_ 14 2 7 7 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: scardi_ 14 2 4 4 */
extern int zzpsun_(doublereal *v1, integer *p1, doublereal *v2, integer *p2, 
doublereal *vout, integer *pout);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: sized_ 4 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: cardi_ 4 1 4 */
/*:ref: sizei_ 4 1 4 */
/*:ref: copyd_ 14 2 7 7 */
/*:ref: copyi_ 14 2 4 4 */
/*:ref: moved_ 14 3 7 4 7 */
/*:ref: scardd_ 14 2 4 7 */
/*:ref: scardi_ 14 2 4 4 */
extern int zzpswrit_(integer *unit, doublereal *v1, integer *p1);
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: cardi_ 4 1 4 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
extern int zzpsxfrm_(doublereal *v1, doublereal *xform, doublereal *vout);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: mxv_ 14 3 7 7 7 */
/*:ref: scardd_ 14 2 4 7 */
extern int zzpsxlat_(doublereal *v1, doublereal *offset, doublereal *vout);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: cardd_ 4 1 7 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: sized_ 4 1 7 */
/*:ref: vadd_ 14 3 7 7 7 */
/*:ref: scardd_ 14 2 4 7 */
extern int zzt_boddsk__(char *dsk, char *body, char *fixref, logical *load, 
integer *handle, ftnlen dsk_len, ftnlen body_len, ftnlen fixref_len);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: bods2c_ 14 4 13 4 12 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errch_ 14 4 13 13 124 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: namfrm_ 14 3 13 4 124 */
/*:ref: frinfo_ 14 5 4 4 4 4 12 */
/*:ref: failed_ 12 0 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: t_elds2z__ 14 8 4 4 13 4 4 13 124 124 */
/*:ref: dasopr_ 14 3 13 4 124 */
extern int zzt_cg__(doublereal *vout, integer *pout);
/*:ref: return_ 12 0 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: ssized_ 14 2 4 7 */
/*:ref: ssizei_ 14 2 4 4 */
/*:ref: zzpsbox_ 14 5 7 7 7 7 4 */
/*:ref: zzpsxlat_ 14 3 7 7 7 */
/*:ref: copyd_ 14 2 7 7 */
/*:ref: zzpsun_ 14 6 7 4 7 4 7 4 */
/*:ref: copyi_ 14 2 4 4 */
/*:ref: chkout_ 14 2 13 124 */
extern int zzt_pck08__(char *namepc, ftnlen namepc_len);
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: begdat_ 13 2 13 124 */
/*:ref: begtxt_ 13 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: writln_ 14 3 13 4 124 */
extern int zztstck3_(char *ck, ftnlen ck_len);
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: tparse_ 14 5 13 7 13 124 124 */
/*:ref: shelld_ 14 2 4 7 */
/*:ref: tstatd_ 14 3 7 7 7 */
/*:ref: m2q_ 14 2 7 7 */
/*:ref: spcopn_ 14 5 13 13 4 124 124 */
/*:ref: ckw03_ 14 15 4 7 7 4 13 12 13 4 7 7 7 4 7 124 124 */
/*:ref: dafcls_ 14 1 4 */
extern int zztstek_(char *file, integer *fileno, integer *mxrows, 
ftnlen file_len);
/*:ref: exists_ 12 2 13 124 */
/*:ref: delfil_ 14 2 13 124 */
/*:ref: repmi_ 14 7 13 13 4 13 124 124 124 */
/*:ref: ekopn_ 14 6 13 13 4 4 124 124 */
/*:ref: tstsch_ 14 16 13 4 4 4 4 13 4 4 4 4 12 12 13 124 124 124 */
/*:ref: maxai_ 14 4 4 4 4 4 */
/*:ref: erract_ 14 4 13 13 124 124 */
/*:ref: errdev_ 14 4 13 13 124 124 */
/*:ref: errprt_ 14 4 13 13 124 124 */
/*:ref: chkin_ 14 2 13 124 */
/*:ref: setmsg_ 14 2 13 124 */
/*:ref: errint_ 14 3 13 4 124 */
/*:ref: sigerr_ 14 2 13 124 */
/*:ref: chkout_ 14 2 13 124 */
/*:ref: ekifld_ 14 11 4 13 4 4 13 13 4 4 124 124 124 */
/*:ref: tstent_ 14 15 4 13 4 13 4 4 4 13 7 4 7 12 124 124 124 */
/*:ref: ekaclc_ 14 10 4 4 13 13 4 12 4 4 124 124 */
/*:ref: ekacld_ 14 9 4 4 13 7 4 12 4 4 124 */
/*:ref: ekacli_ 14 9 4 4 13 4 4 12 4 4 124 */
/*:ref: ekffld_ 14 3 4 4 4 */
/*:ref: ekcls_ 14 1 4 */
extern int zztstlsk_(char *namels, ftnlen namels_len);
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: begdat_ 13 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: writln_ 14 3 13 4 124 */
extern int zztstpck_(char *namepc, ftnlen namepc_len);
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: begdat_ 13 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: rtrim_ 4 2 13 124 */
/*:ref: writln_ 14 3 13 4 124 */
extern int zztstsclk_(char *sclknm, ftnlen sclknm_len);
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: begdat_ 13 2 13 124 */
/*:ref: txtopn_ 14 3 13 4 124 */
/*:ref: rtrim_ 4 2 13 124 */
extern int zztstspk_(char *file, ftnlen file_len);
/*:ref: kilfil_ 14 2 13 124 */
/*:ref: spcopn_ 14 5 13 13 4 124 124 */
/*:ref: tststc_ 14 2 4 4 */
/*:ref: tstst_ 14 8 4 7 13 4 7 4 7 124 */
/*:ref: frmnam_ 14 3 4 13 124 */
/*:ref: spkw05_ 14 13 4 4 4 13 7 7 13 7 4 7 7 124 124 */
/*:ref: spkw08_ 14 14 4 4 4 13 7 7 13 4 4 7 7 7 124 124 */
/*:ref: dafcls_ 14 1 4 */




#endif
