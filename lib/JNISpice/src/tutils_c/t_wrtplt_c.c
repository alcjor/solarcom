/*

-Procedure t_wrtplt_c ( DSK test, write caller-supplied plate data )

-Abstract
 
   Write a type 2 DSK containing vertices and plates passed 
   in by the caller. 
 
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
 
   PLATE 
   TEST 
   UTILITY 
   VERTEX 
 
*/

   #include "SpiceUsr.h"
   #include "SpiceZfc.h"
   #include "SpiceZmc.h"
   #include "tutils_c.h"
   #undef t_wrtplt_c


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
                     ConstSpiceChar    * dsk           )
/*

-Brief_I/O
 
   VARIABLE  I/O  DESCRIPTION 
   --------  ---  -------------------------------------------------- 
   bodyid     I   Body ID. 
   surfid     I   Surface ID. 
   frame      I   Reference frame name. 
   first      I   Start time, TDB. 
   last       I   Stop time, TDB. 
   corsys     I   Coordinate system code. 
   corpar     I   Coordinate parameters. 
   bounds     I   Segment spatial bounds. 
   nv         I   Number of vertices in input array. 
   np         I   Number of plates in input array. 
   usrvrt     I   Vertex array. 
   usrplt     I   Plate array. 
   maxvtl     I   Vertex-plate mapping flag. 
   dsk        I   Name of DSK file to create. 
 
-Detailed_Input
 
   bodyid     is the body ID code of the segment to be written 
              to the output DSK file. 
 
   surfid     is surface ID code. 
 
   frame      is the name of the reference frame. 
 
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
              the lower bound of the Ith coordinate; bounds[i][1] is 
              the upper bound. 
 
   nv         is the number of vertices in the input vertex array. 
 
   np         is the number of plates in the input plate array. 
 
   usrvrt     is an array of vertices. Elements 
 
                 usrvrt[i][j], j = 0 : 2
 
              are the components of the ith vertex. Vertex indices 
              range from 1 to `nv'. 
 
 
   usrplt     is an array of plates. Elements 
 
                 usrplt[i][j], j = 0 : 2 
 
              are the components of the ith plate. Each component 
              is a vertex index. Plate indices range from 1 to `np'. 
              
   maxvtl     is a logical flag that controls whether a vertex-plate 
              mapping is created in the output segment. A mapping 
              is created if and only if `maxvtl' is SPICETRUE.
 
   dsk        is the name of the new DSK file to create. The file 
              must not exist prior to a call to this routine. 
 
-Detailed_Output
 
   None. This routine operates by side effects. 
 
-Parameters
 
   None. 
 
-Exceptions
 
   1)  If a file having the name DSK already exists, the error 
       SPICE(DSKFILEEXISTS) is signaled. 
 
   2)  If the input frame name cannot be converted to an ID code, 
       the error SPICE(FRAMEIDNOTFOUND) will be signaled. 
 
   3)  Any errors that occur during the process of creating the 
       output segment's spatial index or of writing the DSK will be 
       signaled by routines in the call tree of this routine. 
 
-Files
 
   See the description of DSK above. 
 
-Particulars
 
   This is the general test API for writing plate-vertex 
   data to a DSK file. 
    
-Examples
 
   None. 
 
-Restrictions
 
   1) For use only by TSPICE. 
 
-Literature_References
 
   None. 
 
-Author_and_Institution
 
   N.J. Bachman    (JPL) 
 
-Version
 
   -CSPICE Version 1.0.0, 27-AUG-2016 (NJB)

-Index_Entries
 
   testutil type 2 dsk plate-vertex writer 
 
-&
*/

{ /* Begin t_wrtplt_c */



   /*
   Local variables
   */
   logical                 mkvtmap;

   /*
   Participate in error tracing.
   */
   chkin_c ( "t_wrtplt_c" );

   /*
   Make sure each pointer is non-null and each string contains
   at least one data character: that is, one character 
   preceding the null terminator.
   */
   CHKFSTR ( CHK_STANDARD, "t_wrtplt_c", frame );
   CHKFSTR ( CHK_STANDARD, "t_wrtplt_c", dsk   );

   /*
   Cast the input vertex-plate mapping flag to type logical. 
   */
   mkvtmap = (logical)makvtl;

   /*
   Call the f2c'd TESTUTILS function.
   */
   t_wrtplt__ ( (integer      *) &bodyid,
                (integer      *) &surfid,
                (char         *) frame,
                (doublereal   *) &first,
                (doublereal   *) &last,
                (integer      *) &corsys,
                (doublereal   *) corpar,
                (doublereal   *) bounds,
                (integer      *) &nv,
                (integer      *) &np,
                (doublereal   *) usrvrt,
                (integer      *) usrplt,
                (logical      *) &mkvtmap,
                (char         *) dsk,
                (ftnlen        ) strlen(frame),
                (ftnlen        ) strlen(dsk)    );

   chkout_c ( "t_wrtplt_c" );

} /* End t_wrtplt_c */
