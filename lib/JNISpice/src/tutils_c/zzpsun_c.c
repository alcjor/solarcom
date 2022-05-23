/*

-Procedure zzpsun_c ( Plate set union )

-Abstract
 
   Compute the union of two plate sets. 
 
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


   void zzpsun_c ( SpiceCell   * v1,
                   SpiceCell   * p1,
                   SpiceCell   * v2,
                   SpiceCell   * p2,
                   SpiceCell   * vout,
                   SpiceCell   * pout ) 
/*

-Brief_I/O
 
   Variable  I/O  Description 
   --------  ---  -------------------------------------------------- 
   v1         I   Vertex cell of first plate set. 
   p1         I   Plate cell of first plate set. 
   v2         I   Vertex cell of second plate set. 
   p2         I   Plate cell of second plate set. 
   vout       O   Vertex cell of plate set union. 
   pout       O   Plate cell of plate set union. 
 
-Detailed_Input
 
   v1             is a CSPICE double precision cell containing the 
                  vertices of the first input plate set. The 
                  vertices are stored in increasing order of the 
                  vertex IDs, and the components of each vertex are 
                  stored consecutively in the order X, Y, Z. 
 
   p1             is a CSPICE integer cell containing the plates 
                  of the first input plate set. Each plate is a 
                  sequence of three vertex IDs. The vertex IDs 
                  are 1-based: they range from 1 to NV, where 
                  NV is the number of vertices stored in V1. 
                  The vertices of each plate are ordered in the 
                  positive (counterclockwise) sense about the 
                  plate's outward normal vector. The plates are 
                  store in increasing order of the plate IDs. 
 
   v2             is a CSPICE double precision cell containing the 
                  vertices of the second input plate set. 
 
   p2             is a CSPICE integer cell containing the plates 
                  of the second input plate set. 
 
-Detailed_Output
 
   vout           is a CSPICE double precision cell containing the 
                  "union" of the sets of vertices of the input plate 
                  sets. The union is constructed by appending the 
                  data of V2 to the data of V1; no attempt is made 
                  to identify and remove repeated vertices. The 
                  cardinality of VOUT is the sum of the cardinalities 
                  of V1 and V2. 
                   
   pout           is a CSPICE integer cell containing the plates 
                  of the union of the input plate sets. In POUT, 
                  each vertex ID from P2 is augmented by the number 
                  of vertices in V1. Each vertex ID from P1 is 
                  simply copied. The union is constructed by 
                  appending to the data from P1 the augmented 
                  versions of the plates from P2. The cardinality of 
                  POUT is the sum of the cardinalities of P1 and P2. 
 
-Parameters
 
  None.
 
-Exceptions
 
   1) If the size of VOUT is too small to contain the union 
      of the vertex sets, the error SPICE(VERTARRAYTOOSMALL) 
      is signaled. 
 
   2) If the size of POUT is too small to contain the union 
      of the plate sets, the error SPICE(PLTARRAYTOOSMALL) 
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
 
   TUTILS_C Version 1.0.0 28-JAN-2016 (NJB)

-Index_Entries

   compute union of two plate sets

-&
*/

{ /* Begin zzpsun_c */

 

   /*
   Participate in error tracing.
   */
   chkin_c ( "zzpsun_c" );

   /*
   Check vertex cell types. 
   */
   CELLTYPECHK ( CHK_STANDARD, "zzpsun_c", SPICE_DP, v1   );
   CELLTYPECHK ( CHK_STANDARD, "zzpsun_c", SPICE_DP, v2   );
   CELLTYPECHK ( CHK_STANDARD, "zzpsun_c", SPICE_DP, vout );

   /*
   Check plate cell types. 
   */
   CELLTYPECHK ( CHK_STANDARD, "zzpsbox_c", SPICE_INT, p1 );
   CELLTYPECHK ( CHK_STANDARD, "zzpsbox_c", SPICE_INT, p2 );
   CELLTYPECHK ( CHK_STANDARD, "zzpsbox_c", SPICE_INT, pout );  
 
   /*
   Initialize the cells if necessary.
   */
   CELLINIT ( v1   );
   CELLINIT ( p1   );
   CELLINIT ( v2   );
   CELLINIT ( p2   );
   CELLINIT ( vout );
   CELLINIT ( pout );
 
   /*
   Compute the union. 
   */
   zzpsun_ ( (doublereal    *) v1->base,
             (integer       *) p1->base,
             (doublereal    *) v2->base,
             (integer       *) p2->base,
             (doublereal    *) vout->base,
             (integer       *) pout->base  );

   /*
   Sync the output cells. 
   */
   if ( !failed_c() )
   {
      zzsynccl_c ( F2C, vout );
      zzsynccl_c ( F2C, pout );
   }


   chkout_c ( "zzpsun_c" );

} /* End zzpsun_c */
