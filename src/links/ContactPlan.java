package links;

import space.Body;
import space.KernelBody;
import spice.basic.SpiceException;

public class ContactPlan {

    private Body occultingBodies[];
    private RadioLink rl;

    public ContactPlan(RadioLink rl, Body[] occultingBodies) {
        this.occultingBodies = occultingBodies.clone();
        this.rl = rl;
    }

    public boolean calcOccultation() {
        boolean isOcc;
        for (Body occulting: occultingBodies) {
            isOcc = rl.src.getBody().occultation(rl.dest.getBody(), occulting);
            if (isOcc) return true;
        }
        return false;
    }

    public boolean calcSolarInterference(Body sun, double angle_param) {

        double angle = rl.src.getBody().angularSep(rl.dest.getBody(), sun);

        double dist_sun = rl.src.getBody().distance(sun);
        double dist_dest = rl.src.getBody().distance(rl.dest.getBody());
        boolean cond1 = (angle <= angle_param && dist_sun < dist_dest);
        boolean cond2 = angle >= 180 - angle_param;
        return (cond1 || cond2);
    }

    public boolean calcOccLgs(double el_parameter) {


    }

}
