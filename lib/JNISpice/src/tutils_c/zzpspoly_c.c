/*

-Procedure zzpspoly_c ( Plate set, create polygon )

-Abstract
 
   Create a plate set with a polygonal boundary in the X-Y plane. 
   The normal vectors of the plates point in the +Z direction. 
 
   The input vertices are required to be ordered in the positive 
   sense about the +Z axis. 
 
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
   #undef zzpspoly_c


   void zzpspoly_c ( SpiceInt        n,
                     SpiceDouble     vrtces[][2],
                     SpiceCell     * vout,
                     SpiceCell     * pout        ) 
/*

-Brief_I/O
 
   Variable  I/O  Description 
   --------  ---  -------------------------------------------------- 
   n          I   Number of vertices in the polygon. 
   vrtces     I   2-D vertices of the polygon. 
   vout       O   Vertex cell of the plate set. 
   pout       O   Plate cell of the plate set. 
 
-Detailed_Input
 
   n              is the number of vertices in the polygon. 
 
   vrtces         is an array of 2-D vertices. The vertices must be 
                  ordered in the positive (counterclockwise) sense 
                  about the +Z axis. 
                        
-Detailed_Output
 
   vout           is a CSPICE double precision cell containing the 
                  (3-D) vertices of a plate set representing planar 
                  region bounded by the polygon. 
    
   pout           is a CSPICE integer cell containing the plates 
                  of the plate set. The vertices of each plate are 
                  ordered so that they define a normal vector 
                  pointing in the +Z direction. 
                 
-Parameters
 
   None.
 
-Exceptions
 
   1) If the size of `vout' is too small to contain the output 
      plate set's vertices, the error SPICE(VERTARRAYTOOSMALL) is 
      signaled. 
 
   2) If the size of `pout' is too small to contain the output plate 
      set's plates, the error SPICE(PLTARRAYTOOSMALL) is signaled. 
 
   3) Any other errors that occur while accessing SPICE cells 
      will be diagnosed by routines in the call tree of this 
      routine. 
 
   4) If the vertices are not ordered in the positive sense  
      about the +Z axis, the error SPICE(BADVERTEXORDER) will be 
      signaled. 
  
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
 
   -tutils_c Version 1.0.0 25-OCT-2016 (NJB)

-Index_Entries
 
   create plate set representing a polygon

-&
*/

{ /* Begin zzpspoly_c */
 
   /*
   Participate in error tracing.
   */
   chkin_c ( "zzpspoly_c" );

   /*
   Check vertex cell types. 
   */
   CELLTYPECHK ( CHK_STANDARD, "zzpspoly_c", SPICE_DP,  vout );
   CELLTYPECHK ( CHK_STANDARD, "zzpspoly_c", SPICE_INT, pout );

   /*
   Initialize the cells if necessary.
   */
   CELLINIT ( vout );
   CELLINIT ( pout );

   zzpspoly_ ( ( integer      * ) &n,
               ( doublereal   * ) vrtces,
               ( doublereal   * ) vout->base,
               ( integer      * ) pout->base  );

   /*
   Sync the output cells. 
   */
   if ( !failed_c() )
   {
      zzsynccl_c ( F2C, vout );
      zzsynccl_c ( F2C, pout );
   }   

   chkout_c ( "zzpspoly_c" );

} /* End zzpspoly_c */
