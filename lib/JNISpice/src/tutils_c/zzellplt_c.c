/*

-Procedure zzellplt_c ( Tessellate an ellipsoid with triangular plates )

-Abstract
 
   Create a set of triangular plates covering a specified triaxial 
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
 
*/

   #include "SpiceUsr.h"
   #include "SpiceZfc.h"
   #include "SpiceZmc.h"
   #include "tutils_c.h"


   void zzellplt_c ( SpiceDouble      a,
                     SpiceDouble      b,
                     SpiceDouble      c,
                     SpiceInt         nlon,
                     SpiceInt         nlat,
                     SpiceCell      * vout,
                     SpiceCell      * pout  ) 
/*

-Brief_I/O
 
   VARIABLE  I/O  DESCRIPTION 
   --------  ---  -------------------------------------------------- 
   a          I   Length of ellipsoid semi-axis lying on the x-axis. 
   b          I   Length of ellipsoid semi-axis lying on the y-axis. 
   c          I   Length of ellipsoid semi-axis lying on the z-axis. 
   nlon       I   Number of longitude bands in plate set. 
   nlat       I   Number of latitude bands in plate set. 
   vout      I-O  Vertex cell.
   pout      I-O  Plate cell.
 
-Detailed_Input
 
   a, 
   b, 
   c          are the lengths of the semi-axes of a triaxial 
              ellipsoid. The ellipsoid is centered at the origin and 
              oriented so that its axes lie on the x, y and z axes. 
              `a', `b', and `c' are the lengths of the semi-axes that 
              point in the x, y, and z directions respectively. 
 
 
   nlon       is the number of longitude bands in the output plate 
              set. Each longitude band is bounded by two meridians. 
              All longitude bands have equal angular extent in 
              longitude. The vertices of any plate lie on adjacent 
              longitude band boundaries. 
 
 
   nlat       is the number of latitude bands in the output plate 
              set. The vertices of each band are bounded by two 
              cones of constant planetocentric latitude. All 
              latitude bands have equal angular extent in 
              planetocentric latitude. The vertices of any plate lie 
              on adjacent latitude band boundaries. 
 
              Each polar "cap" consists of one longitude band. 
 
                         
   vout       is an initialized CSPICE double precision cell. The size
              of `vout' must be at least

                 3 *  (  ( nlon * ( nlat - 1 ) )  +  2  )


   pout       is an initialized CSPICE double precision cell. The size
              of `pout' must be at least

                 3 * (  2 * nlon * ( nlat - 1 )  )

 
-Detailed_Output 
 
 
   vout       is the input vertex cell, populated with vertex data.

              The cardinality of `vout' is 3*nv, where nv is the number
              of vertices in the plate set that represents the
              ellipsoid's surface. There is a vertex at each
              intersection of a latitude band boundary and a longitude
              band boundary. The vertices at the north and south poles
              are at indices `nv' and nv-1, respectively. the non-polar
              vertex indices start at 1. Non-polar vertices are indexed
              in top-down, left-to-right order, with vertices of each
              latitude band stored contiguously.
    
   pout       is the input plate cell, populated with vertex data.

              The cardinality of `pout' is 3*np, where np is the number
              of plates in the plate set that represents the
              ellipsoid's surface.

              Each plate is an array of three vertex indices, where 
              the indices range from 1 to `nv'. 
 
              The vertices of any plate are ordered in the 
              right-handed sense about the outward normal direction 
              for that plate. 
 
              The non-polar plates---those not having a vertex at 
              the north or south pole---are indexed in top-down, 
              left-to-right order, with plates belonging to each 
              latitude band stored contiguously. Plates constituting 
              the north polar cap follow the non-polar plate set, 
              and plates constituting the south polar cap follow 
              those. 
 
-Parameters
 
   None. 
 
-Exceptions
 
   1)  If the length of any semi-axis of the ellipsoid is 
       non-positive, the error SPICE(INVALIDAXISLENGTH) is signaled. 
 
   2)  If `nlat' is less than 2, the error SPICE(INVALIDCOUNT) is 
       signaled. 
 
   3)  If `nlon' is less than 3, the error SPICE(INVALIDCOUNT) is 
       signaled. 
 
   4)  If the number of vertices implied by the input values `nlon' and
       `nlat' exceeds the size of `vout', the error
       SPICE(ARRAYTOOSMALL) is signaled.
 
   5)  If the number of plates implied by the input values `nlon' and
       `nlat' exceeds the size of `pout', the error
       SPICE(ARRAYTOOSMALL) is signaled.
 
-Files
 
   None. 
 
-Particulars
 
   The vertex and plate sets created by this routine are suitable 
   for use in a type 2 DSK segment. 
 
   While the primary purpose of this routine is to support testing, 
   there may be some user applications for which a tessellated plate 
   model is valuable. For example, computing an estimate of the area 
   of a specified surface region may be simplified by using a plate 
   model. 
 
   Note that, for ellipsoids having three distinct radii, the Z 
   components of the vertices on any latitude band boundary (except 
   the poles themselves) will vary with longitude. 
 
   Also note that the horizontal edge of a plate may extend beyond 
   the boundaries of the latitude band containing the plate. 
    
-Examples
 
   See use of C language version in tspice_c test families. 
 
-Restrictions
 
   1) For use only by TSPICE_C. 
 
-Literature_References
 
   None. 
 
-Author_and_Institution
 
   N.J. Bachman    (JPL) 
 
-Version
 
   -tutils_c Version 1.0.0, 28-JAN-2016 (NJB)

-Index_Entries
 
   tessellate ellipsoid 
 
-&
*/

{ /* Begin zzellplt_c */

   /*
   Local variables
   */
   SpiceInt                maxp;
   SpiceInt                maxv;
   SpiceInt                np;
   SpiceInt                nv;

 
   /*
   Participate in error tracing.
   */
   chkin_c ( "zzellplt_c" );

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
   Extract size parameters from the input cells; convert
   to vertex and plate counts. 
   */
   maxv = size_c( vout ) / 3;
   maxp = size_c( pout ) / 3;

   /*
   Let the f2c'd routine do the work. Note that, currently, the
   Fortran version of the routine doesn't use cells.
   */
   zzellplt_ ( ( doublereal  * ) &a, 
               ( doublereal  * ) &b, 
               ( doublereal  * ) &c, 
               ( integer     * ) &nlon,
               ( integer     * ) &nlat,
               ( integer     * ) &maxv,
               ( integer     * ) &maxp,
               ( integer     * ) &nv,
               ( doublereal  * ) vout->data,
               ( integer     * ) &np,
               ( integer     * ) pout->data   );
   /*
   Set the cardinality of the cells. We can't do this via the
   usual sync calls because the Fortran code doesn't use cells.
   */
   scard_c ( 3*nv, vout );
   scard_c ( 3*np, pout );

   chkout_c ( "zzellplt_c" );

} /* End zzellplt_c */
