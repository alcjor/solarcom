package links;

import space.Body;
import space.DSNComm;
import space.KernelBody;
import spice.basic.SpiceException;

public class ContactPlan {

    private Body occultingBodies[];
    private Body sun;
    private RadioLink rl;

    public ContactPlan(RadioLink rl, Body[] occultingBodies, Body sun) {
        this.occultingBodies = occultingBodies.clone();
        this.sun = sun;
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

    public boolean calcSolarInterference(double angle_param) {

        double angle = rl.src.getBody().angularSep(rl.dest.getBody(), sun);

        double dist_sun = rl.src.getBody().distance(sun);
        double dist_dest = rl.src.getBody().distance(rl.dest.getBody());
        boolean cond1 = (angle <= angle_param && dist_sun < dist_dest);
        boolean cond2 = angle >= 180 - angle_param;
        return (cond1 || cond2);
    }

    public boolean calcOccLgs(double el_parameter) {

        double elev;
        if (rl.src.getBody().onSurface) {
            elev = rl.src.getBody().elevation(rl.dest.getBody());
            if (elev <= el_parameter) return true;
        }

        if (rl.dest.getBody().onSurface) {
            elev = rl.dest.getBody().elevation(rl.src.getBody());
            if (elev <= el_parameter) return true;
        }

        return false;
    }

    public boolean calcVisibility(double angle_solar_interf, double angle_occlgs) {
        if (calcOccultation()) return false;
        if (calcSolarInterference(angle_solar_interf)) return false;
        if (calcOccLgs(angle_occlgs)) return false;
        return true;
    }

}
