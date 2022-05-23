import spice.basic.*;
import static spice.basic.GFOccultationSearch.*;


class GFOccultationSearchEx1
{
//
// Load the JNISpice shared object library
// at initialization time.
//
   static { System.loadLibrary( "JNISpice" ); }

   public static void main ( String[] args )
   {
      try {

         //
         // Constants
         //
         final String META    = "GFOccultationSearchEx1.tm";

         final String TIMFMT  =
            "YYYY MON DD HR:MN:SC.###### (TDB)::TDB";

         final int    NINTVLS = 100;

         //
         // Declare the SPICE windows we'll need for the searches
         // and window arithmetic. The result window will be
         // assigned values later; the confinement window must
         // be non-null before it's used.
         //
         SpiceWindow result     = null;
         SpiceWindow cnfine     = new SpiceWindow();

         //
         // Declare and assign values to variables required to
         // specify the geometric condition to search for.
         //

         AberrationCorrection
            abcorr = new AberrationCorrection( "CN" );
         Body back              = new Body ( "Sun" );
         Body front             = new Body ( "Moon" );
         Body observer          = new Body ( "Earth"   );
         ReferenceFrame bframe  = new ReferenceFrame( "IAU_SUN" );
         ReferenceFrame fframe  = new ReferenceFrame( "IAU_MOON" );
         String bshape          = GF.EDSHAP;
         String fshape          = GF.EDSHAP;

         //
         // Load kernels.
         //
         KernelDatabase.load ( META );

         //
         // Store the time bounds of our search interval in
         // the `cnfine' confinement window.
         //
         TDBTime et0 = new TDBTime ( "2001 Dec 1 00:00:00" );
         TDBTime et1 = new TDBTime ( "2002 Jan 1 00:00:00" );

         cnfine.insert( et0.getTDBSeconds(),
                        et1.getTDBSeconds() );
         //
         // Select a 3-minute step. We'll ignore any occultations
         // lasting less than 3 minutes.  Units are TDB seconds.
         //
         double step = 3 * 60.0;

         GFOccultationSearch occultationSearch =

            new GFOccultationSearch ( ANY,
                                       front,  fshape,  fframe,
                                       back,   bshape,  bframe,
                                       abcorr, observer         );

         //
         // Run the search.
         //
         // Specify the maximum number of intervals in the result
         // window.
         //
         result = occultationSearch.run( cnfine, step, NINTVLS );

         //
         // Display results.
         //
         int count = result.card();

         if ( count == 0 )
         {
            System.out.format ( "No occultation was found.%n%n" );
         }
         else
         {
            //
            // Fetch and display each occultation interval.
            //
            double[] interval = new double[2];
            String   begstr;
            String   endstr;

            for ( int i = 0;  i < count;  i++ )
            {
               //
               // Fetch the endpoints of the Ith interval
               // of the result window.
               //
               interval = result.getInterval( i );

               begstr = ( new TDBTime(interval[0]) ).toString(TIMFMT);
               endstr = ( new TDBTime(interval[1]) ).toString(TIMFMT);

               System.out.format( "Interval %d%n", i );
               System.out.format( "   Start time: %s %n",   begstr );
               System.out.format( "   Stop time:  %s %n",   endstr );
            }
         }
      }
      catch ( SpiceException exc ) {
         exc.printStackTrace();
      }
   }  
}
