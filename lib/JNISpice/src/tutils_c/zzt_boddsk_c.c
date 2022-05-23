/*

-Procedure zzt_boddsk_c ( Make type 2 DSK for body's reference ellipsoid )

-Abstract
 
   Create a DSK containing a tessellation of the reference  
   ellipsoid of a specified body. 
 
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
   PCK 
 
-Keywords
 
   BODY 
   ELLIPSOID 
   PLATE 
   TILE 
   TESSELLATE 
 
*/

   #include "SpiceUsr.h"
   #include "SpiceZfc.h"
   #include "SpiceZmc.h"
   #undef zzt_boddsk_c


   void zzt_boddsk_c ( ConstSpiceChar  * dsk,
                       ConstSpiceChar  * body,
                       ConstSpiceChar  * fixref,
                       SpiceBoolean      load,
                       SpiceInt        * handle ) 

/*

-Brief_I/O
 
   VARIABLE  I/O  DESCRIPTION 
   --------  ---  -------------------------------------------------- 
   dsk        I   Name of DSK file to create. 
   body       I   Name of central body and of surface. 
   fixref     I   Name of body-fixed, body-centered reference frame. 
   load       I   Flag indicating whether to load the DSK. 
   handle     O   DAS handle of DSK if loaded. 
 
-Detailed_Input
 
   dsk        is the name of a new DSK file to create. 
 
 
   body       is the name of a body for which a DSK file is to be 
              created. The ID code associated with `body' is used as 
              both the surface and body ID code in the DSK file. 
 
              Case and leading and trailing blanks in the name are 
              not significant.   
 
 
   fixref     is the name of a body-fixed, body-centered reference 
              frame associated with `body'. 
 
              Case and leading and trailing blanks in the name are 
              not significant.   
 
 
   load       is a logical flag that indicates whether to load the 
              DSK file for read access after the file has been 
              created. If `load' is set to SPICETRUE, the file is loaded 
              for read access by DASOPR. 
 
-Detailed_Output
 
   handle     is a DAS handle associated with the specified  
              DSK file, if the input flag `load' is SPICETRUE 
               
              `handle' is undefined if the input `load' is SPICEFALSE 
 
-Parameters
 
   None. 
 
-Exceptions
 
   1)  If the input body name cannot be mapped to an integer 
       ID code, the error SPICE(BODYIDNOTFOUND) will be signaled. 
 
   2)  If the input frame name cannot be mapped to an integer 
       ID code, the error SPICE(UNKNOWNFRAME) will be signaled. 
 
   3)  If the radii of the specified body are not available 
       in the kernel pool, the error will be diagnosed by 
       a routine in the call tree of this routine. 
 
   4)  If the reference frame designated by `fixref' is not 
       centered at `body', the error SPICE(BADFRAMECENTER)  
       will be signaled.  
 
   5)  If the specified DSK file already exists, it will not be 
       overwritten. An error will be signaled by a routine in the 
       call tree of this routine. 
 
   6)  If an error is encountered while writing the DSK file, the 
       error will be signaled by a routine in the call tree of this 
       routine. 
 
-Files
 
   1)  This routine requires radii for `body' to be available 
       in the kernel pool. Normally these radii are made  
       available by loading a PCK containing them. 
 
   2)  This routine creates a type 2 segment containing a  
       tessellation of the reference ellipsoid of a specified 
       body. The segment contains 
 
          1000   longitude bands 
           500   latitude bands 
 
       which yields 
 
          499002 vertices 
          998000 plates 
 
       The body and surface IDs of the segment are both the NAIF ID 
       corresponding to `body'. 
 
       The coordinate system of the segment is planetocentric. 
       The longitude range is 
 
         -180 : 180 degrees 
 
       The latitude range is 
 
          -90 :  90 degrees 
 
       Time coverage of the segment is J2000 TDB +/- 100 Julian 
       years. 
 
       The data class of the segment is 1 (spherically 
       parameterized surface). 
 
       The size of the file is about 47 Mb. 
 
 
-Particulars
  
   See Files above. 
 
-Examples
 
   See use in tspice_c test families. 
 
-Restrictions
 
   1) For use only by TSPICE_C. 
 
-Literature_References
 
   None. 
 
-Author_and_Institution
 
   N.J. Bachman    (JPL) 
 
-Version
 
   -TUTILS_C Version 1.0.0, 30-APR-2014 (NJB)

-Index_Entries
 
   tessellate reference ellipsoid of body 
 
-&
*/

{ /* Begin zzt_boddsk_c */

   /*
   Prototypes 
   */
   int zzt_boddsk__( char    *dsk, 
                     char    *body, 
                     char    *fixref, 
                     logical *load, 
                     integer *handle,
                     ftnlen   dsk_len, 
                     ftnlen   body_len,
                     ftnlen   fixref_len );

   /*
   Local variables
   */
   logical             fLoad;

   /*
   Participate in error tracing.
   */
   chkin_c ( "zzt_boddsk_c" );

   /*
   Check the input strings to make sure the pointers are non-null
   and the string lengths are non-zero.
   */
   CHKFSTR ( CHK_STANDARD, "zzt_boddsk_c", dsk    );
   CHKFSTR ( CHK_STANDARD, "zzt_boddsk_c", body   );
   CHKFSTR ( CHK_STANDARD, "zzt_boddsk_c", fixref );

   /*
   Cast the input SpiceBoolean flag to type logical,
   in case there's a size mismatch. 
   */
   fLoad = (logical)load;
   
   zzt_boddsk__ ( ( char     * ) dsk,
                  ( char     * ) body,
                  ( char     * ) fixref,
                  ( logical  * ) &fLoad,
                  ( integer  * ) handle,
                  ( ftnlen     ) strlen(dsk),
                  ( ftnlen     ) strlen(body),
                  ( ftnlen     ) strlen(fixref) );

   chkout_c ( "zzt_boddsk_c" );

} /* End zzt_boddsk_c */
