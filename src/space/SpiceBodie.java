package space;

import spice.basic.*;

public class SpiceBodie extends Bodie {

    static {
        System.loadLibrary("JNISpice");
    }

    private String spiceID;
    private spice.basic.Body body;

    public SpiceBodie(String spiceID) throws SpiceException {
        super();
        this.spiceID = spiceID;
        body = new spice.basic.Body( spiceID   );
    }

    public void update(double time) {

    }

    public spice.basic.Body getBody() {
        return body;
    }

    public void calcPos() throws SpiceException {
        String timstr               = "2009 JUL 09 00:00:00 TDB";
        spice.basic.Body target                 = new spice.basic.Body ( "Moon" );
        TDBTime et                  = new TDBTime ( timstr );
        ReferenceFrame ref          = new ReferenceFrame( "J2000" );
        AberrationCorrection abcorr = new AberrationCorrection( "LT+S" );
        spice.basic.Body observer               = new spice.basic.Body ( 399    );

        //
        // Create a StateRecord and display it.
        //
        StateRecord s = new StateRecord ( target,  et,  ref,
                abcorr,  observer );
        System.out.println ( s );
    }
}
