/*

-Procedure t_cg_c ( write simplified comet C-G DSK )

-Abstract
 
   Write a DSK containing an extremely simplified shape model 
   representing the nucleus of comet Churymov-Gerasimenko. The model 
   is a union of boxes. 
 
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
   #include "tutils_c.h"
   #undef t_cg_c

   void t_cg_c ( SpiceInt          bodyid,
                 SpiceInt          surfid,
                 ConstSpiceChar  * frame,
                 ConstSpiceChar  * dsk     )
         
/*

-Brief_I/O
 
   VARIABLE  I/O  DESCRIPTION 
   --------  ---  -------------------------------------------------- 
   bodyid     I   Body ID. 
   surfid     I   Surface ID. 
   frame      I   Reference frame name. 
   dsk        I   Name of DSK file to create. 
 
-Detailed_Input
 
   bodyid     is the body ID code of the segment to be written 
              to the output DSK file. 
 
   surfid     is surface ID code. 
 
   frame      is the name of the reference frame. 
 
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
 
   Output: see the description of DSK above. 
 
-Particulars
 
   This routine writes a DSK that contains a representation 
   of the shape similar to that of comet Churymov-Gerasimenko. 
   The model is composed of several boxes. 
 
   The output file contains a single type 2 segment.  
 
   The ID codes in the output file are provided by the user. 
   The user may wish to center the segment on a body other 
   than comet C-G. 
             
-Examples
 
   None. 
 
-Restrictions
 
   1) For use only by TSPICE. 
 
-Literature_References
 
   None. 
 
-Author_and_Institution
 
   N.J. Bachman    (JPL) 
 
-Version
 
   -CSPICE Version 1.0.0, 09-APR-2016 (NJB)

-Index_Entries
 
   write comet cg-like dsk 
 
-&
*/

{ /* Begin t_cg_c */

  

   /*
   Participate in error tracing.
   */
   chkin_c ( "t_cg_c" );

   t_cg__ ( (integer    *) &bodyid,
            (integer    *) &surfid,
            (char       *) frame,
            (char       *) dsk,
            (ftnlen      ) strlen(frame),
            (ftnlen      ) strlen(dsk)    );

   chkout_c ( "t_cg_c" );

} /* End t_cg_c */
