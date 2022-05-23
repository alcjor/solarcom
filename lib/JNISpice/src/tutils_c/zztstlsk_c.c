/*
 
-Procedure  zztstlsk_c ( Create an LSK file for testing.)
 
-Abstract

  This test utility routine creates a leapsecond kernel 
  (valid as of July 1, 1997).
  
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
 
   TESTING
 
*/
   #include <assert.h>
   #include "SpiceUsr.h"
   #include "SpiceZfc.h"
   #include "SpiceZmc.h"
   #include "tutils_c.h"
 
   void zztstlsk_c ( ConstSpiceChar * namels )
 
/*
 
-Brief_I/O
 
   VARIABLE  I/O  DESCRIPTION
   --------  ---  --------------------------------------------------
   namels     I   The name for the test leapsecon kernel.
 
-Detailed_Input
 
   namels         the name of the leapsecond kernel created by the
                  routine. If 'namels' exists, this routine deletes
                  the original file.
 
-Detailed_Output
 
   None.
 
-Parameters
 
   None.
  
-Exceptions
 
   Error free.
 
-Files
 
   None.
 
-Particulars
 
   This routine serves a a CSPICE wrapper to the f2c'd version of
   zztstlsk.f to create a SPICE usable leapseconds kernel.
   
   Note, this routine only creates a test leapseconds kernel. The
   user must load/unload/delete the file after creation as needed.
 
-Examples
 
   This is intended to be used in those instances when you
   need a well defined leapseconds kernel for use in testing.
   
   /.
   Create a usable LSK for tests.
   ./
   #define LSK    "test.lsk"
   
   
   zztstlsk_c( LSK );
   furnsh_c( LSK );
   
   ... perform tests ...
   
   kclear_c()
   
   ... delete LSK ...
   
-Restrictions
 
   None.

-Literature_References
 
   None.

-Author_and_Institution
 
   N.J. Bachamn     (JPL)
   W.L. Taber       (JPL)
 
-Version
 
   -tutils_c Version 1.0.0, 14-AUG-2008 (NJB) (WLT) (EDW)

-Index_Entries

   test

-&
*/
 
{ /* Begin zztstlsk_c */
 
   /*
   Do NOT participate in error tracing; it confuses the underlying code.
   */

   assert ( namels         !=  NULLCPTR );
   assert ( strlen(namels) >   0        );
 
   zztstlsk_ (  ( char   * ) namels,
                ( ftnlen   ) strlen(namels)  );
 
 
} /* End zztstlsk_c */
