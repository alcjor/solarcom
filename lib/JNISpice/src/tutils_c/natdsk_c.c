/*

-Procedure natdsk_c (Create a DSK for Nat's solar system)

-Abstract
 
   Create and if appropriate load a DSK containing shape data 
   for the objects in Nat's solar system. 
 
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
 
-Required_Reading
 
   None. 
 
-Keywords
 
   TESTING 
 
*/

   #include "SpiceUsr.h"
   #include "SpiceZfc.h"
   #include "SpiceZst.h"
   #include "SpiceZmc.h"
   #include "tutils_c.h"
   #undef natdsk_c


   void natdsk_c ( ConstSpiceChar      * dsk,
                   ConstSpiceChar      * aframe,
                   SpiceInt              anlon,
                   SpiceInt              anlat,
                   ConstSpiceChar      * bframe,
                   SpiceInt              bnlon,
                   SpiceInt              bnlat   ) 

/*

-Brief_I/O
 
   VARIABLE  I/O  DESCRIPTION 
   --------  ---  -------------------------------------------------- 
   dsk        I   The name of the DSK file to create. 
   aframe     I   Body-fixed frame for body Alpha. 
   anlon      I   Number of longitude bands in model for Alpha. 
   anlat      I   Number of latitude bands in model for Alpha. 
   bframe     I   Body-fixed frame for body Beta. 
   bnlon      I   Number of longitude bands in model for Beta. 
   bnlat      I   Number of latitude bands in model for Beta. 
    
-Detailed_Input
 
   dsk        is the name of a DSK file to create. If a DSK  
              of the same name already exists, it is deleted.

 
   aframe     is the name of the body-fixed frame to be used in 
              the segment for body Alpha.      
 
   anlon      is the number of longitude bands in the plate set for 
              body Alpha. Each longitude band is bounded by two 
              meridians. All longitude bands have equal angular 
              extent in longitude. The vertices of any plate lie on 
              adjacent longitude band boundaries. 
 
   anlat      is the number of latitude bands in the plate set for 
              body Alpha. The vertices of each band are bounded by 
              two cones of constant planetocentric latitude. All 
              latitude bands have equal angular extent in 
              planetocentric latitude. The vertices of any plate lie 
              on adjacent latitude band boundaries. 
 
              Each polar "cap" consists of one longitude band. 
 
   bframe     is the name of the body-fixed frame to be used in 
              the segment for body Beta.      
 
   bnlon      is the number of longitude bands in the plate set for 
              body Beta. See description of `anlon' for details.   
 
   bnlat      is the number of latitude bands in the plate set for 
              body Beta. See description of `anlat' for details. 
 
 
-Detailed_Output
 
   None. This routine creates an output file. 
 
-Parameters
 
   The maximum plate and column counts for each segment are defined by
   the parameters in the Fortran test utility routine T_WRDSK2. These
   values are considerably smaller than those used in the Fortran
   include file dsk02.inc.
 
-Exceptions
 
   1) Any error occurring during the creation of spatial indexes 
      for the segments in the output DSK will be signaled by  
      routines in the call tree of this routine. 
 
   2) Any I/O errors occurring in the creation of the DSK file 
      will be signaled by routines in the call tree of this 
      routine.   
 
   3) If any input string has length zero, the error
      SPICE(EMPTYSTRING) will be signaled.

   4) If any input string pointer is null, the error
      SPICE(NULLPOINTER) will be signaled.

   Since this routine is normally used within the TSPICE system, 
   it's up the caller to call chckxc_c to catch errors signaled by 
   this routine. 
  
-Files
 
   Input 
   ===== 
 
   This routine requires the kernel pool variables defined by  
   the PCK file created by natpck_c. That kernel should be loaded 
   by the caller. 
 
   Output 
   ====== 
 
   This routine creates a DSK file meant for use with the SPK file 
   and PCK file created by the respective test utilities natspk_c and 
   natpck_c. 
 
   The DSK file contains tessellated ellipsoid shape models for  
   bodies ALPHA and BETA. Radii for the ellipsoids are obtained from 
   the PCK created by natpck_c.  
 
   Each model is contained in a single segment. The surface IDs 
   for both segments are set to 1. The coordinate systems of both 
   segments are latitudinal. 
 
   The body-fixed frames associated with ALPHA and BETA are specified 
   by the caller. 
 
-Particulars
 
   This routine creates a DSK file for use in testing. See the Files 
   section above. 
 
   The DSK created by this routine in particular supports testing 
   the routines 
 
      gfoclt_c
      occult_c
 
-Examples
 
   The normal way to use this routine is shown below. 
 
      natpck_c ( "nat.tpc" ) 
 
         ... 
 
      natspk_c ( "nat.bds",  
                 "ALPHAFIXED", anlon, anlat, 
                 "BETAFIXED",  bnlon, bnlat );
 
-Restrictions
 
   None. 
 
-Literature_References
 
   None. 
 
-Author_and_Institution
 
   N.J. Bachman    (JPL) 
 
-Version
 
   -CSPICE Version 1.0.0, 23-MAY-2016 (NJB)

-Index_Entries
 
   Create a "Nat's solar system" DSK file 
 
-&
*/

{ /* Begin natdsk_c */

  


   /*
   Participate in error tracing.
   */
   chkin_c ( "natdsk_c" );


   CHKFSTR( CHK_STANDARD, "natdsk_c", dsk    );
   CHKFSTR( CHK_STANDARD, "natdsk_c", aframe );
   CHKFSTR( CHK_STANDARD, "natdsk_c", bframe );


   natdsk_( (char          *) dsk,
            (char          *) aframe,
            (integer       *) &anlon,
            (integer       *) &anlat,
            (char          *) bframe,
            (integer       *) &bnlon,
            (integer       *) &bnlat,
            (ftnlen         ) strlen(dsk),
            (ftnlen         ) strlen(aframe),
            (ftnlen         ) strlen(bframe)  );

   chkout_c ( "natdsk_c" );

} /* End natdsk_c */
