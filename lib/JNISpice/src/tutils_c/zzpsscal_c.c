/*

-Procedure zzpsscal_c ( Plate set, scale )

-Abstract
 
   Scale a plate set: multiply the vertices of a plate set by a 
   specified factor. 
 
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
 
   CELLS 
   DSK 
 
-Keywords
 
   DSK 
   PLATE 
 
*/

   #include "SpiceUsr.h"
   #include "SpiceZfc.h"
   #include "SpiceZmc.h"
   #include "tutils_c.h"
   #undef zzpsscal_c


   void zzpsscal_c ( SpiceDouble    scale,
                     SpiceCell    * v1,
                     SpiceCell    * vout  ) 
/*

-Brief_I/O
 
   Variable  I/O  Description 
   --------  ---  -------------------------------------------------- 
   v1         I   Vertex cell of a plate set. 
   scale      I   Scale factor. 
   vout       O   Vertex cell of the translated plate set. 
 
-Detailed_Input
 
   v1             is a CSPICE double precision cell containing the 
                  vertices of a plate set. 
 
   scale          is a double precision scale factor. All vertices  
                  in `v1' are to be multiplied by `scale'. 
 
-Detailed_Output
 
   vout           is a CSPICE double precision cell containing the 
                  vertices of a plate set resulting from multiplying 
                  each vertex of `v1' by `scale'. 
                 
-Parameters
 
   LBCELL is the lower bound of the CSPICE cell data structure. 
 
-Exceptions
 
   1) If the cardinality of `v1' is not a multiple of 3, the error  
      SPICE(BADVERTEXARRAY) is signaled. 
 
   2) If the size of `vout' is too small to contain the vertices 
      of the output plate set, the error SPICE(VERTARRAYTOOSMALL) 
      is signaled. 
 
   3) Any other errors that occur while accessing SPICE cells 
      will be diagnosed by routines in the call tree of this 
      routine. 
 
-Files
 
   None. 
 
-Particulars
 
   None. 
 
-Examples
 
   None. 
    
-Restrictions
 
   None. 
 
-Literature_References
 
   None. 
 
-Author_and_Institution
 
   N.J. Bachman    (JPL) 
 
-Version
 
   -tutils_c Version 1.0.0 01-FEB-2016 (NJB)

-Index_Entries
 
   scale the vertices of plate set

-&
*/

{ /* Begin zzpsscal_c */

 


   /*
   Participate in error tracing.
   */

   chkin_c ( "zzpsscal_c" );

   /*
   Check vertex cell types. 
   */
   CELLTYPECHK ( CHK_STANDARD, "zzpsscal_c", SPICE_DP, v1   );
   CELLTYPECHK ( CHK_STANDARD, "zzpsscal_c", SPICE_DP, vout );

   /*
   Initialize the cells if necessary.
   */
   CELLINIT ( v1   );
   CELLINIT ( vout );


   zzpsscal_ ( ( doublereal * ) &scale, 
               ( doublereal * ) v1->base,                             
               ( doublereal * ) vout->base );               

   /*
   Sync the output cell. 
   */
   if ( !failed_c() )
   {
      zzsynccl_c ( F2C, vout );
   }   


   chkout_c ( "zzpsscal_c" );

} /* End zzpsscal_c */
