/*

-Procedure zztstspkcov (Create an SPK for spk[cov|obj] tests)

-Abstract

   Write an SPK containing appropriate data for a test of the
   spkcov_c and spkobj_c routines.
 
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
 
    None. 
 
-Keywords

   C TEST UTILITIES 

*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "SpiceUsr.h"
#include "SpiceZmc.h"
#include "tutils_c.h"

/*

-Brief_I/O
 
    VARIABLE  I/O  DESCRIPTION 
    --------  ---  -------------------------------------------------- 
    file       I   The name of an SPK file to create. 
 
-Detailed_Input
 
   file        is the name of an SPK file to create for use in 
               software testing. 
 
-Detailed_Output
 
   None. 
 
-Parameters
 
    None. 
 
-Exceptions
 
   1) If the specified file already exists, it is deleted and 
      replaced by the file created by this routine. 
 
   2) All other exceptions are diagnosed by routines in the call tree 
      of this routine. 
 
-Files

   None.

-Particulars
 
      This routine creates an SPK file with ephemeris information
      for the following objects.

           MARS BARYCENTER
           JUPITER BARYCENTER
           SATURN BARYCENTER

      The ephemeris information has no physical meaning since the
      cov/obj tests need only the segment time coverage for the bodies.

      "brief -c" outputs the followng:

      Body: MARS BARYCENTER (4) w.r.t. EARTH (399)
           Start of Interval (ET)              End of Interval (ET)
           --------------------------------    --------------------------------
           2000 JAN 01 11:59:49.000            2000 JAN 01 11:59:59.000
           2000 JAN 01 12:00:00.000            2000 JAN 01 12:00:10.000
           2000 JAN 01 12:00:11.000            2000 JAN 01 12:00:21.000
           2000 JAN 01 12:00:22.000            2000 JAN 01 12:00:32.000
           2000 JAN 01 12:00:33.000            2000 JAN 01 12:00:43.000
           2000 JAN 01 12:00:44.000            2000 JAN 01 12:00:54.000
           2000 JAN 01 12:00:55.000            2000 JAN 01 12:01:05.000
           2000 JAN 01 12:01:06.000            2000 JAN 01 12:01:16.000
           2000 JAN 01 12:01:17.000            2000 JAN 01 12:01:27.000
           2000 JAN 01 12:01:28.000            2000 JAN 01 12:01:38.000
    
     Body: JUPITER BARYCENTER (5) w.r.t. EARTH (399)
           Start of Interval (ET)              End of Interval (ET)
           --------------------------------    --------------------------------
           2000 JAN 01 12:01:41.000            2000 JAN 01 12:03:21.000
           2000 JAN 01 12:03:22.000            2000 JAN 01 12:05:02.000
           2000 JAN 01 12:05:03.000            2000 JAN 01 12:06:43.000
           2000 JAN 01 12:06:44.000            2000 JAN 01 12:08:24.000
           2000 JAN 01 12:08:25.000            2000 JAN 01 12:10:05.000
           2000 JAN 01 12:10:06.000            2000 JAN 01 12:11:46.000
           2000 JAN 01 12:11:47.000            2000 JAN 01 12:13:27.000
           2000 JAN 01 12:13:28.000            2000 JAN 01 12:15:08.000
           2000 JAN 01 12:15:09.000            2000 JAN 01 12:16:49.000
           2000 JAN 01 12:16:50.000            2000 JAN 01 12:18:30.000
           2000 JAN 01 12:18:31.000            2000 JAN 01 12:20:11.000
           2000 JAN 01 12:20:12.000            2000 JAN 01 12:21:52.000
           2000 JAN 01 12:21:53.000            2000 JAN 01 12:23:33.000
           2000 JAN 01 12:23:34.000            2000 JAN 01 12:25:14.000
           2000 JAN 01 12:25:15.000            2000 JAN 01 12:26:55.000
           2000 JAN 01 12:26:56.000            2000 JAN 01 12:28:36.000
           2000 JAN 01 12:28:37.000            2000 JAN 01 12:30:17.000
           2000 JAN 01 12:30:18.000            2000 JAN 01 12:31:58.000
           2000 JAN 01 12:31:59.000            2000 JAN 01 12:33:39.000
           2000 JAN 01 12:33:40.000            2000 JAN 01 12:35:20.000
    
     Body: SATURN BARYCENTER (6) w.r.t. EARTH (399)
           Start of Interval (ET)              End of Interval (ET)
           --------------------------------    --------------------------------
           2000 JAN 01 11:43:20.000            2000 JAN 01 20:03:20.000 

  
-Examples

   int main()
      {
      SpiceChar * SPK = "test.spk";
      zztstspkcov( SPK );
   
      return( 0 );
      }

-Restrictions
 
   None. 
 
-Author_and_Institution
 
   N.J. Bachman    (JPL)
   W.L. Taber      (JPL) 
 
-Literature_References
 
   None. 
 
-Version
 
   -tutils_c Version 1.0.0, 05-NOV-2007 (NJB) (WLT) (EDW)
   
      Reimplementation of code take from f_spkcov_c. This routine
      only creates the SPK test file.

-Index_Entries
  
-&
*/

void zztstspkcov( ConstSpiceChar * SPK )
   {

   #define DELTA            ( 1.e-6  )
   #define MAXCOV           10000
   #define WINSIZ           ( 2 * MAXCOV )


   #define FILSIZ           256
   #define LNSIZE           81
   #define NBOD             3


   /*
   Local variables
   */
   SPICEDOUBLE_CELL      ( xcover0, WINSIZ );
   SPICEDOUBLE_CELL      ( xcover1, WINSIZ );
   SPICEDOUBLE_CELL      ( xcover2, WINSIZ );

   static SpiceCell      * xcov     [ NBOD ] = { &xcover0,
                                                 &xcover1,
                                                 &xcover2 };
   SpiceDouble             states   [2][6];
   SpiceDouble             first;
   SpiceDouble             last;

   static SpiceInt         body     [ NBOD ]  =  { 4, 5, 6 };

   SpiceInt                handle;
   SpiceInt                i;
   SpiceInt                j;
   static SpiceInt         nseg     [ NBOD ]  =  { 10, 20, 30 };


   /*
   Delete the old version of the SPK, if it exists.
   */
   if ( exists_c( SPK ) )
      {
      remove ( SPK );
      }


   /*
   Create an SPK file with data for three bodies. 
   */
   spkopn_c ( SPK, SPK, 0, &handle );

   j = 12;
   cleard_ ( &j, (SpiceDouble *)states );


   for ( i = 0;  i < NBOD;  i++  )
      {
      for ( j = 0;  j < nseg[i];  j++  )
         {
         /*
         Create segments for body I.
         */
         if ( i == 0  )
            {
            /*
            Create nseg[0] segments, each one separated by a 1 second gap.
            */
            first = (j-1) * 11.0; 
            last  = first + 10.0; 
            } 

         else if ( i == 1 )
            {
            /*
            Create nseg[1] segments, each one separated
            by a 1 second gap.  This time, create the 
            segments in decreasing time order.
            */
            first = ( nseg[1] - j ) * 101.0;
            last  = first + 100.0;
            }

         else
            {
            /*
            i == 3 

            Create nseg[2] segments with no gaps.
            */
            first = (j-1) * 1000.0;
            last  = first + 1000.0;
            }

         /*
         Add to the expected coverage window for this body. This file does
         not contain realistic data.
         */
         wninsd_c ( first, last, xcov[i] );

         spkw08_c ( handle,  body[i],  399,    "J2000",
                    first,   last,     "TEST",  1,
                    2,       states,   first,   last-first+DELTA );

         }

      }

   spkcls_c ( handle );

   }



   
