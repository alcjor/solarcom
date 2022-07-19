package test.java;

import org.junit.Test;
import spice.basic.*;

import static spice.basic.GF.ANY;

// Code examples from SPICE documentation
public class ExamplesTest {
    //
    // Load the JNISpice shared object library
    // at initialization time.
    //
    static { System.loadLibrary( "JNISpice" ); }

    @Test
    public void occultationStateEx1Test ()
    {
        try
        {
            //
            // Constants
            //
            final String META    = "/home/jordi/solarcom2/src/test/metakernels/OccultationStateEx1.tm";

            final String OUTFMT  =  "%s %s %s %s wrt %s%n";

            final String TIMFMT  =
                    "YYYY-MON-DD HR:MN ::UTC-8";
            //
            // Declare and assign values to variables required to
            // specify the geometric condition to search for.
            //

            AberrationCorrection
                    abcorr = new AberrationCorrection( "CN" );

            Body targ2             = new Body ( "Mars"   );
            Body targ1             = new Body ( "MRO"    );
            Body obsrvr            = new Body ( "DSS-13" );

            OccultationCode occ;

            // For point targets, the frame is not used. We
            // can provide the name of an arbitrary built-in
            // frame.
            //
            ReferenceFrame frame1  = new ReferenceFrame( "J2000"    );
            ReferenceFrame frame2  = new ReferenceFrame( "IAU_MARS" );

            String[] outputStr     = { "totally occulted by",
                    "transited by",
                    "partially occulted by",
                    "not occulted by"        };

            String   shape1        = GF.PTSHAP;
            String   shape2;
            String[] shapes        = {GF.EDSHAP, "DSK/UNPRIORITIZED"};
            String   timstr;

            TDBDuration dt         = new TDBDuration( 1000.0 );

            TDBTime et;
            TDBTime etStart;
            TDBTime etStop;

            int     i;

            //
            // Load kernels.
            //
            KernelDatabase.load ( META );

            //
            // Convert the time bounds of our computation interval
            // to TDB.
            //
            etStart = new TDBTime ( "2015-FEB-28 1:15:00 UTC" );
            etStop  = new TDBTime ( "2015-FEB-28 2:50:00 UTC" );

            //
            // Loop over the Mars shapes.
            //
            for ( i = 0;  i < 1;  i++ )
            {
                shape2 = shapes[i];

                System.out.format ( "%nMars shape: %s%n%n", shape2 );

                //
                // Step through the interval, computing the occultation
                // state at intervals of `dt' TDB seconds.
                //

                et = etStart;

                while(  et.getTDBSeconds() < etStop.getTDBSeconds() )
                {
                    //
                    // Calculate the type of occultation that
                    // corresponds to time `et'.

                    occ =

                            OccultationState.
                                    getOccultationState( targ1,  shape1, frame1,
                                            targ2,  shape2, frame2,
                                            abcorr, obsrvr, et     );
                    //
                    // Display the results.
                    //
                    timstr = et.toString( TIMFMT );

                    switch( occ )
                    {
                        case TOTAL1:

                            System.out.format( OUTFMT,          timstr,
                                    targ1.getName(), outputStr[0],
                                    targ2.getName(), obsrvr.getName() );
                            break;

                        case ANNLR1:

                            System.out.format( OUTFMT,          timstr,
                                    targ1.getName(), outputStr[1],
                                    targ2.getName(), obsrvr.getName() );
                            break;

                        case PARTL1:

                            System.out.format( OUTFMT,          timstr,
                                    targ1.getName(), outputStr[2],
                                    targ2.getName(), obsrvr.getName() );
                            break;

                        case TOTAL2:

                            System.out.format( OUTFMT,          timstr,
                                    targ2.getName(), outputStr[0],
                                    targ1.getName(), obsrvr.getName() );
                            break;

                        case ANNLR2:

                            System.out.format( OUTFMT,          timstr,
                                    targ2.getName(), outputStr[1],
                                    targ1.getName(), obsrvr.getName() );
                            break;

                        case PARTL2:

                            System.out.format( OUTFMT,          timstr,
                                    targ2.getName(), outputStr[2],
                                    targ1.getName(), obsrvr.getName() );
                            break;

                        case NOOCC:

                            System.out.format( OUTFMT,          timstr,
                                    targ1.getName(), outputStr[3],
                                    targ2.getName(), obsrvr.getName() );
                            break;
                    }

                    et = et.add( dt );
                }
                //
                // End of time loop.
                //
            }
            //
            // End of shape loop.
            //
        }
        catch ( SpiceException exc ) {
            exc.printStackTrace();
        }

        System.out.format( "%n" );
    }

    @Test
    public void GFOccultationSearchEx1() {
        try {

            //
            // Constants
            //
            final String META    = "/home/jordi/solarcom2/src/test/metakernels/GFOccultationSearchEx1.tm";

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
