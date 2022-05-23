/*

-Procedure t_torus_c ( write DSK containing torus plate model )

-Abstract
 
   Write a DSK containing a plate model representing a torus. 
 
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
 
*/

   #include "SpiceUsr.h"
   #include "SpiceZfc.h"
   #include "SpiceZst.h"
   #include "SpiceZmc.h"
   #include "tutils_c.h"
   #undef t_torus_c

   void t_torus_c ( SpiceInt          bodyid,
                    SpiceInt          surfid,
                    ConstSpiceChar  * frname,
                    SpiceInt          npolyv,
                    SpiceInt          ncross,
                    SpiceDouble       r,
                    SpiceDouble       rcross,
                    SpiceDouble       center [3],
                    SpiceDouble       normal [3],
                    ConstSpiceChar  * dsk         )
/*

-Brief_I/O
 
   VARIABLE  I/O  DESCRIPTION 
   --------  ---  -------------------------------------------------- 
   bodyid     I   Body ID. 
   surfid     I   Surface ID. 
   frname     I   Reference frame name. 
   npolyv     I   Number of vertices in polygonal cross section. 
   ncross     I   Number of cross sections. 
   r          I   Radius of central curve. 
   rcross     I   Radius of cross section. 
   center     I   Center of the torus. 
   normal     I   Normal vector to plane of central curve. 
   dsk        I   Name of DSK file to write. 
 
-Detailed_Input
 
   bodyid     is the body ID code of the segment to be written 
              to the output DSK file. 
 
   surfid     is surface ID code. 
 
   frname     is the name of the reference frame. 
 
   npolyv     is the number of vertices per polygonal cross section 
              of the torus. Each cross section is the set of 
              vertices of a regular polygon inscribed in a circle of 
              radius `rcross' (see below). Each cross section lies in 
              a plane normal to the derivative of the central curve 
              at its point of intersection with the plane. 
 
   ncross     is the number of cross sections of the torus. 
 
   r          is the radius of the central curve of the torus. 
              Each cross section is centered on this curve and 
              is normal to the derivative of the curve at the point 
              of intersection. 
 
   rcross     is the radius of each circular cross section of the  
              torus. 
 
   center     is the center of the torus. The is the center of the 
              central curve of the torus. The line normal to the  
              plane of the central curve and passing through `center' 
              is the axis of azimuthal symmetry of the torus. 
 
   normal     is a vector normal to the plane containing the  
              central curve of the torus. 
 
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

   3)  The error SPICE(EMPTYSTRING) is signaled if any input string
       argument does not contain at least one character, since the
       input string cannot be converted to a Fortran-style string in
       this case.
      
   4)  The error SPICE(NULLPOINTER) is signaled if any input
       string argument pointer is null.

-Files
 
   Output: see the description of DSK above. 
 
-Particulars
 
   In a Cartesian coordinate system having the Z axis parallel to  
   `normal', and having an origin coincident with `center', the torus 
   is the set of points 
 
                              2   2  1/2  2     2           2 
      { (x,y,z) : (  R  -  ( x + y  )    )  +  z   =  rcross  } 
    
 
   This routine can be used to create shape models suitable for 
   testing limb finding and terminator finding routines. 
        
-Examples
 
   None. 
 
-Restrictions
 
   1) For use only by tspice_c. 
 
-Literature_References
 
   None. 
 
-Author_and_Institution
 
   N.J. Bachman    (JPL) 
 
-Version
 
   -CSPICE Version 1.0.0, 29-AUG-2016 (NJB)

-Index_Entries
 
   write dsk containing torus plate model 
 
-&
*/

{ /* Begin t_torus_c */

 
 
   /*
   Participate in error tracing.
   */
   chkin_c ( "t_torus_c" );

   /*
   Check input pointers and string lengths. 
   */
   CHKFSTR ( CHK_STANDARD, "t_torus_c", frname );
   CHKFSTR ( CHK_STANDARD, "t_torus_c", dsk    );

   t_torus__ ( (integer      *) &bodyid,
               (integer      *) &surfid,
               (char         *) frname,
               (integer      *) &npolyv,
               (integer      *) &ncross,
               (doublereal   *) &r,
               (doublereal   *) &rcross,
               (doublereal   *) center,
               (doublereal   *) normal,
               (char         *) dsk,
               (ftnlen        ) strlen(frname),
               (ftnlen        ) strlen(dsk)     );
   

   chkout_c ( "t_torus_c" );

} /* End t_torus_c */
