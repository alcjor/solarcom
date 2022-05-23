/*

-Procedure t_elds2z_c ( write tessellated ellipsoid type 2 DSK, easy )

-Abstract
 
   Write a type 2 DSK containing a tessellated ellipsoid.  
   Use default values to simplify the call. 
 
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
   #include "SpiceZmc.h"
   #include "tutils_c.h"


   void t_elds2z_c ( SpiceInt            bodyid,
                     SpiceInt            surfid,
                     ConstSpiceChar    * frame,
                     SpiceInt            nlon,
                     SpiceInt            nlat,
                     ConstSpiceChar    * dsk    ) 
/*

-Brief_I/O
 
   VARIABLE  I/O  DESCRIPTION 
   --------  ---  -------------------------------------------------- 
   bodyid     I   Body ID. 
   surfid     I   Surface ID. 
   frame      I   Reference frame name. 
   nlon       I   Number of longitude bands in plate set. 
   nlat       I   Number of latitude bands in plate set. 
   dsk        I   Name of DSK file to create. 
 
-Detailed_Input
 
   bodyid     is the body ID code of the segment to be written 
              to the output DSK file. 
 
 
   surfid     is surface ID code. 
 
 
   frame      is the name of the reference frame. 
 
 
   nlon       is the number of longitude bands in the plate set to 
              be created by this routine. Each longitude band is 
              bounded by two meridians. All longitude bands have 
              equal angular extent in longitude. The vertices of any 
              plate lie on adjacent longitude band boundaries. 
 
 
   nlat       is the number of latitude bands in the plate set. The 
              vertices of each band are bounded by two cones of 
              constant planetocentric latitude. All latitude bands 
              have equal angular extent in planetocentric latitude. 
              The vertices of any plate lie on adjacent latitude 
              band boundaries. 
 
              Each polar "cap" consists of one longitude band. 
 
 
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
 
   4)  If the length of any semi-axis of the ellipsoid is 
       non-positive, the error SPICE(INVALIDAXISLENGTH) is signaled. 
 
-Files
 
   Input: a PCK file must be loaded in order to provide radii of 
          the reference ellipsoid for the specified body. 
 
   Output: see the description of DSK above. 
 
-Particulars
 
   This is a simplified API for writing a tessellated ellipsoid 
   model to a DSK file. The following defaults are used 
 
      Time bounds:               -100 : 100 Julian years TDB 
 
      Coordinate system:         Latitudinal 
       
      Longitude bounds:          0     : 2*pi radians 
      Latitude bounds:           -pi/2 : pi/2 radians 
       
   This routine does not construct a vertex-plate mapping. 
 
   Ellipsoid radii for the specified body are obtained from the  
   kernel pool. 
    
   This routine creates a DSK containing a single type 2 segment. 
    
-Examples
 
   None. 
 
-Restrictions
 
   1) For use only by tspice_c. 
 
-Literature_References
 
   None. 
 
-Author_and_Institution
 
   N.J. Bachman    (JPL) 
 
-Version
 
   -CSPICE Version 1.0.0, 18-MAR-2016 (NJB)

-Index_Entries
 
   write type 2 dsk containing tessellated ellipsoid, easy 
 
-&
*/

{ /* Begin t_elds2z_c */

 

   /*
   Participate in error tracing.
   */
   chkin_c ( "t_elds2z_c" );

   /*
   Make sure each pointer is non-null and each string contains
   at least one data character: that is, one character 
   preceding the null terminator.
   */
   CHKFSTR ( CHK_STANDARD, "t_elds2z_c", frame );
   CHKFSTR ( CHK_STANDARD, "t_elds2z_c", dsk   );

   /*
   Call the f2c'd TESTUTILS function.
   */

   t_elds2z__ ( (integer      *) &bodyid,
                (integer      *) &surfid,
                (char         *) frame,
                (integer      *) &nlon,
                (integer      *) &nlat,
                (char         *) dsk,
                (ftnlen        ) strlen(frame),
                (ftnlen        ) strlen(dsk)    );
   

   chkout_c ( "t_elds2z_c" );

} /* End t_elds2z_c */
