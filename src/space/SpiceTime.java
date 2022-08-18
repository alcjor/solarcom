package space;

import spice.basic.Duration;
import spice.basic.SpiceException;
import spice.basic.TDBDuration;
import spice.basic.TDBTime;

public class SpiceTime {

    private TDBTime time;

    private static SpiceTime spiceTime = new SpiceTime();

    private SpiceTime() {}

    public static SpiceTime getSpiceTime() {
        return spiceTime;
    }

    public void setTime(TDBTime time) {
        this.time = time;
    }

    public void update(double step) throws SpiceException {
        this.time.add(new TDBDuration(step));
    }

    public TDBTime getTime() {
        return this.time;
    }


}
