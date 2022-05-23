/*

-Procedure zzpstube_c ( Plate set, create tube )

-Abstract
 
   Create a plate set representing a tube with specified 3-D 
   polygonal cross section. A user-defined callback subroutine is 
   supplied to define the central curve of the tube, its derivative 
   vector, and twist. 
 
   An input logical flag indicates whether the tube is closed. 
 
   Polygon vertices are required to be ordered in the positive 
   sense about the initial central curve derivative. 
 
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
   #undef zzpstube_c


   void zzpstube_c ( SpiceInt            n,
                     ConstSpiceDouble    vrtces[][3],
                     void             (* crvsub)( SpiceDouble   t,
                                                  SpiceDouble   curve[3],
                                                  SpiceDouble   deriv[3],
                                                  SpiceDouble  *twist    ),
                     SpiceInt            nsamp,
                     SpiceBoolean        closed,
                     SpiceCell         * vout,
                     SpiceCell         * pout                              )
/*

-Brief_I/O
 
   Variable  I/O  Description 
   --------  ---  -------------------------------------------------- 
   n          I   Number of vertices in the base polygon. 
   vrtces     I   3-D vertices of the base polygon. 
   crvsub     I   Subroutine defining central curve. 
   nsamp      I   Number of samples to use to define cross sections. 
   closed     I   Flag indicating whether tube is closed. 
   vout       O   Vertex cell of the plate set. 
   pout       O   Plate cell of the plate set. 
 
-Detailed_Input
 
   n              is the number of vertices in the polygonal cross
                  section of the tube.
 
 
   vrtces         is an array of 3-D vertices representing the initial
                  cross section of the tube. This is the cross section
                  of the tube evaluated at the parameter value t = 0
                  (see the description of `cursub' below).
 
                  The vertices must be ordered in the positive
                  (counterclockwise) sense about the curve's derivative
                  vector at the parameter value t = 0 (see the
                  description of `cursub' below).
 
 
   crvsub         is the name of a subroutine to be called to generate
                  a curve that runs through the tube shape created by
                  this routine. `cursub' maps the interval
 
                     [0, 1] 
 
                  to a curve in 3-dimensional space. For each value `t'
                  in the interval [0, 1], `cursub' returns a 3-D vector
                  representing the curve at that value of `t', a 3-D
                  derivative vector giving the curve's direction at
                  `t', and a twist angle that defines the orientation
                  of the tube's cross section at `t'.
 
                  The subroutine `cursub' has the calling sequence 
 
                     crvsub ( t, curve, deriv, twist ) 
 
                  The range of the input `t' is 0.0 : 1.0 
  
                  The `twist' angle has units of radians. The `twist' 
                  angle must be either monotonically increasing or 
                  monotonically decreasing; it must not have branch 
                  discontinuities.  
 
                  The vertices of the surface of the tube are 
                  generated by sampling the curve at evenly spaced 
                  values of `t' and adding (suitably rotated) cross 
                  section vectors to the curve at each sample. 
 
                  The orientation of cross sections is determined as 
                  follows: if the curve's derivatives at samples 
                  t(i+1) and t(i) have cross product zero, the cross 
                  section vectors for sample t(i+1) are copied from 
                  the those at sample t(i). If the twist angle 
                  changes by `delta' between the two samples, the 
                  cross section vectors are rotated by `delta' about 
                  the derivative at t(i+1). For the cross section 
                  at t = 0, the value of `twist' at t = 0 is applied. 
 
                  If the cross product is non-zero, the cross 
                  section at t(i+1) is created by rotating the cross 
                  section vectors at t(i) about the cross product 
                  vector by the angle between the curve's 
                  derivatives at the two values of `t'. This creates a 
                  set of cross section vectors lying in a plane 
                  orthogonal to the derivative at t(i+1). Next, 
                  twist is applied to the cross section at t(i+1) as 
                  described above. 
 
 
   nsamp          is the number of "samples" taken to define the 
                  tube's cross-sectional shape. For each sample, a 
                  call to `cursub' is made. Samples are taken at t = 0, 
                  t = 1, and at nsamp-2 equally spaced points in 
                  between. The samples are taken at increasing values 
                  of `t'. 
 
 
   closed         is a logical flag indicating whether the tube is 
                  "closed": that is, the boundary of the tube at t = 
                  1 matches that at t = 0. If `closed' is SPICETRUE, the 
                  cross section vectors at t = 1 are simply copied 
                  from those at t = 0. Otherwise, the cross section 
                  vectors at t = 1 are computed as for the other 
                  cross sections. 
                        
-Detailed_Output
 
   vout           is a CSPICE double precision cell containing the 
                  vertices of a plate set representing the surface 
                  of the tube.  
 
   pout           is a CSPICE integer cell containing the plates 
                  of the tube. The vertices of each plate are 
                  ordered so that they define an outward normal 
                  vector pointing away from the central curve of the 
                  tube. 
                 
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
 
   5) The number of cross section samples must be sufficient to 
      allow the output plate set to follow the shape of the curve. 
      There is no check for this. 
 
   6) The number of cross section samples must be sufficient to 
      allow the output plate set to model the twist angle. 
      There is no check for this. 
 
   7) The twist angle returned by `cursub' must be either monotonically 
      increasing or monotonically decreasing. There is no check for 
      this.  
  
-Files
 
   None. 
 
-Particulars
 
   This routine can be used to generate plate sets representing 
   simple planetary ring models.  
 
-Examples
 
    1)  Make a plate set representing a twisted ring with triangular 
        cross section. The ring twists by 2*pi radians from start to 
        end and is closed. 
 
        Write the plate set to a MKDSK input file. 
  
 
   Example code begins here. 
 
      {to be added later}
  
    
-Restrictions
 
   1) Various input errors cannot be checked by this routine. See 
      the Exceptions section above. 
 
-Literature_References
 
   None. 
 
-Author_and_Institution
 
   N.J. Bachman    (JPL) 
 
-Version

   -tutils_c Version 1.0.0 01-FEB-2016 (NJB)

-Index_Entries
 
   create plate set tube with polygonal cross section

 
-&
*/

{ /* Begin zzpstube_c */

 
   /*
   Local variables 
   */
   logical                 isClosed;


   /*
   Participate in error tracing.
   */
   chkin_c ( "zzpstube_c" );


   /*
   Check vertex cell types. 
   */
   CELLTYPECHK ( CHK_STANDARD, "zzpstube_c", SPICE_DP,  vout  );
   CELLTYPECHK ( CHK_STANDARD, "zzpstube_c", SPICE_INT, pout );

   /*
   Initialize the cells if necessary.
   */
   CELLINIT ( vout );
   CELLINIT ( pout );


   /*
   Call the f2c'd version of ZZPSTUBE. Note the type cast of `crvsub';
   this cast is used by f2c for pointers to subroutines. 
   */
   isClosed = (logical) closed;

   zzpstube_ ( (integer       *) &n,
               (doublereal    *) vrtces,
               (S_fp           ) crvsub,
               (integer       *) &nsamp,
               (logical       *) &isClosed,
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

   chkout_c ( "zzpstube_c" );

} /* End zzpstube_c */
