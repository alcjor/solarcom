/*

-Procedure t_secds2_c ( DSK test, write ellipsoid section DSK )

-Abstract
 
   Write a type 2 DSK containing a section of a tessellated 
   ellipsoid. 
 
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
 
   DSK 
 
-Keywords
 
   ELLIPSOID 
   PLATE 
   TILE 
   TESSELLATE 
   TEST 
   UTILITY 
 
*/

   #include "SpiceUsr.h"
   #include "SpiceZfc.h"
   #include "SpiceZst.h"
   #include "SpiceZmc.h"
   #include "tutils_c.h"
   #undef t_secds2_c



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
                     ConstSpiceChar  * dsk                       )
/*

-Brief_I/O
 
   VARIABLE  I/O  DESCRIPTION 
   --------  ---  -------------------------------------------------- 
   bodyid     I   Body ID. 
   surfid     I   Surface ID. 
   frname     I   Reference frame name. 
   first      I   Start time, TDB. 
   last       I   Stop time, TDB. 
   corsys     I   Coordinate system code. 
   corpar     I   Coordinate parameters. 
   bounds     I   Segment spatial bounds. 
   a          I   Length of ellipsoid semi-axis lying on the x-axis. 
   b          I   Length of ellipsoid semi-axis lying on the y-axis. 
   c          I   Length of ellipsoid semi-axis lying on the z-axis. 
   nlon       I   Number of longitude bands in plate set. 
   nlat       I   Number of latitude bands in plate set. 
   makvtl     I   Vertex-plate mapping flag. 
   usepad     I   Padding flag. 
   dsk        I   Name of DSK file to write. 
 
-Detailed_Input
 
   bodyid     is the body ID code of the segment to be written 
              to the output DSK file. 
 
   surfid     is surface ID code. 
 
   frname     is the name of the reference frame. 
 
   first, 
   last       are, respectively, the start and stop times of  
              the coverage interval of the segment. `first' and 
              `last' are expressed as seconds past J2000, TDB. 
 
   corsys     is an integer code designating the coordinate  
              system of the segment. 
  
 
   corpar     is an array of parameters associated with 
              the coordinate system.  
 
              For planetodetic coordinates,  
 
                 corpar[0] is the equatorial radius of the 
                           reference spheroid 
 
 
                 corpar[1] is the flattening coefficient of the 
                           reference spheroid 
 
 
   bounds     is a 2x2 array of bounds of the first two coordinates 
              of the segment's spatial coverage. bounds[i][0] is 
              the lower bound of the ith coordinate; bounds[i][1] is 
              the upper bound. 
 
   a, 
   b, 
   c          are the lengths of the semi-axes of a triaxial 
              ellipsoid. The ellipsoid is centered at the origin and 
              oriented so that its axes lie on the x, y and z axes. 
              `a', `b', and `c' are the lengths of the semi-axes that 
              point in the x, y, and z directions respectively. 
 
 
   nlon       is the number of longitude bands in the plate set to 
              be created by this routine. Each longitude band is 
              bounded by two meridians. All longitude bands have 
              equal angular extent in longitude. The vertices of any 
              plate lie on adjacent longitude band boundaries. 
 
              If padding is enabled, an extra longitude band will be 
              created at both longitude boundaries of the segment. 
 
 
   nlat       is the number of latitude bands in the plate set. The 
              vertices of each band are bounded by two cones of 
              constant planetocentric latitude. All latitude bands 
              have equal angular extent in planetocentric latitude. 
              The vertices of any plate lie on adjacent latitude 
              band boundaries. 
 
              Each polar "cap" consists of one longitude band. 
 
              If padding is enabled, and if the segment does not 
              span the X-Y plane, one or more extra latitude bands 
              will be created at the segment latitude boundary 
              closest to the X-Y plane. A single extra latitude band 
              will be created at the other latitude boundary. If the 
              segment spans the X-Y plane, then a single extra 
              latitude bound will be created at each latitude 
              boundary. 
                 
              
   makvtl     is a logical flag that controls whether a vertex-plate 
              mapping is created in the output segment. A mapping 
              is created if and only if `makvtl' is SPICETRUE.
 
              
   usepad     is a logical flag indicating whether segment padding 
              is to be created. When `usepad' is SPICETRUE, sections 
              having positive lower latitude bounds are padded at 
              the bottom to ensure coverage. This padding consists 
              of an integral number of extra latitude bands. Each of 
              the other boundaries are padded with a single latitude 
              or longitude band. Whe `usepad' is SPICEFALSE, no padding 
              is created. 
 
              See Restrictions below.       
        
 
   dsk        is the name of the DSK file to write. If the file 
              does not exist, it will be created. If the file 
              exists, this routine will append to it. 
 
-Detailed_Output
 
   None. This routine operates by side effects. 
 
-Parameters
 
   None. 
 
-Exceptions
 
   1)  If the input frame name cannot be converted to an ID code, 
       the error SPICE(FRAMEIDNOTFOUND) will be signaled. 
 
   2)  Any errors that occur during the process of creating the 
       output segment's spatial index or of writing the DSK will be 
       signaled by routines in the call tree of this routine. 
 
   3)  If the length of any semi-axis of the ellipsoid is 
       non-positive, the error SPICE(INVALIDAXISLENGTH) is signaled. 
 
   4)  If either the longitude or latitude band count is 
       non-positive, the error SPICE(VALUEOUTOFRANGE) is signaled. 
 
   5)  If the input latitude bounds are out of order, the error 
       SPICE(BOUNDSOUTOFORDER) is signaled. 
 
   6)  The error SPICE(EMPTYSTRING) is signaled if any input string
       argument does not contain at least one character, since the
       input string cannot be converted to a Fortran-style string in
       this case.
      
   7)  The error SPICE(NULLPOINTER) is signaled if any input
       string argument pointer is null.

-Files
 
   See the description of DSK above. 
 
-Particulars
 
   This routine creates a DSK containing a single type 2 segment. 
   The plate and vertex data in the segment represent a section of a 
   tessellated ellipsoid. The section covers a specified longitude/ 
   latitude rectangle. 
    
-Examples
 
   None. 
 
-Restrictions
 
   1) For use only by TSPICE. 
 
   2) Currently restricted to latitudinal coordinates. 
 
-Literature_References
 
   None. 
 
-Author_and_Institution
 
   N.J. Bachman    (JPL) 
 
-Version
 
   -CSPICE Version 1.0.0, 27-AUG-2016 (NJB)

-Index_Entries
 
   write type 2 dsk containing ellipsoid section 
 
-&
*/

{ /* Begin t_secds2_c */

 
   /*
   Local variables 
   */
   logical                 Fmakvtl;
   logical                 Fusepad;

   /*
   Participate in error tracing.
   */
   chkin_c ( "t_secds2_c" );


   /*
   Check input pointers and string lengths. 
   */
   CHKFSTR ( CHK_STANDARD, "t_secds2_c", frname );
   CHKFSTR ( CHK_STANDARD, "t_secds2_c", dsk    );

   /*
   Cast SpiceBolean inputs to logical. 
   */
   Fmakvtl = (logical)makvtl;
   Fusepad = (logical)usepad;


   t_secds2__ ( (integer      *) &bodyid,
                (integer      *) &surfid,
                (char         *) frname,
                (doublereal   *) &first,
                (doublereal   *) &last,
                (integer      *) &corsys,
                (doublereal   *) corpar,
                (doublereal   *) bounds,
                (doublereal   *) &a,
                (doublereal   *) &b,
                (doublereal   *) &c,
                (integer      *) &nlon,
                (integer      *) &nlat,
                (logical      *) &Fmakvtl,
                (logical      *) &Fusepad,
                (char         *) dsk,
                (ftnlen        ) strlen(frname),
                (ftnlen        ) strlen(dsk)     );


   chkout_c ( "t_secds2_c" );

} /* End t_secds2_c */
