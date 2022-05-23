/*

-Procedure zzpsbox_c ( Plate set, create box )

-Abstract
 
   Create a plate set representing a box centered at the origin. 
   The dimensions of the box are specified by the caller. 
 
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

   void zzpsbox_c ( SpiceDouble      a,
                    SpiceDouble      b,
                    SpiceDouble      c,
                    SpiceCell     *  vout,
                    SpiceCell     *  pout ) 

/*

-Brief_I/O
 
   Variable  I/O  Description 
   --------  ---  -------------------------------------------------- 
   a          I   Box edge length in the X direction. 
   b          I   Box edge length in the Y direction. 
   c          I   Box edge length in the Z direction. 
   vout      I-O  Vertex cell of the plate set. 
   pout      I-O  Plate cell of the plate set. 
 
-Detailed_Input
 
   a, 
   b, 
   c              are the edge lengths of the box in the 
                  X, Y, and Z directions, respectively. 
         
   vout           is an initialized CSPICE double precision cell.

   pout           is an initialized CSPICE integer cell.
               
-Detailed_Output
 
   vout           is a CSPICE double precision cell containing the 
                  vertices of a plate set representing the surface 
                  of a box having dimensions A x B x C. The edges of 
                  the box are parallel to the coordinate axes. The 
                  box is centered at the origin. 
 
   pout           is a CSPICE integer cell containing the plates 
                  of the plate set. The vertices of each plate are 
                  ordered so that they define an outward normal 
                  vector having positive dot product with the 
                  plate's vertices. (In other words, the normal 
                  vectors point outward.) 
                 
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
 
   4) If any of the box dimensions are non-positive, the error 
      SPICE(INVALIDEDGELENGTH) will be signaled. 
 
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
 
  -tutils_c Version 1.0.0 28-JAN-2016 (NJB)

-Index_Entries

  create plate set representing a box

-&
*/

{ /* Begin zzpsbox_c */

 
   /*
   Participate in error tracing.
   */
   chkin_c ( "zzpsbox_c" );

   /*
   Make sure we're working with a DP vertex cell.
   */
   CELLTYPECHK ( CHK_STANDARD, "zzpsbox_c", SPICE_DP, vout );

   /*
   Make sure we're working with an integer plate cell.
   */
   CELLTYPECHK ( CHK_STANDARD, "zzpsbox_c", SPICE_INT, pout );

   /*
   Initialize the cells if necessary.
   */
   CELLINIT ( vout );
   CELLINIT ( pout );


   /*
   Let the f2c'd routine do the work. 
   */
   zzpsbox_ ( ( doublereal  * ) &a,
              ( doublereal  * ) &b,
              ( doublereal  * ) &c,
              ( doublereal  * ) vout->base,
              ( integer     * ) pout->base   );
   /*
   Sync the cells.
   */
   zzsynccl_c ( F2C, vout );
   zzsynccl_c ( F2C, pout );

   chkout_c ( "zzpsbox_c" );

} /* End zzpsbox_c */
