package links;

import space.Body;
import space.DSNComm;
import space.KernelBody;
import space.SpiceTime;
import spice.basic.CSPICE;
import spice.basic.SpiceErrorException;
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
        try {
            KernelBody body1 = (KernelBody) rl.src.getBody();
            KernelBody body2 = (KernelBody) rl.dest.getBody();
            KernelBody bodySun = (KernelBody) sun;
            double[] state = new double[6];
            double[] lt = new double[1];

            CSPICE.spkezr(body2.getName(), SpiceTime.getSpiceTime().getTime().getTDBSeconds(),
                    "J2000", "XLT", body1.getName(), state, lt);

            double dist_target = Math.sqrt(state[0]*state[0] + state[1]*state[1] + state[2]*state[2]);
            double[] d_ = new double[3];
            d_[0] =state[0];
            d_[1] =state[1];
            d_[2] =state[2];
            CSPICE.spkezr("SUN", SpiceTime.getSpiceTime().getTime().getTDBSeconds(),
                    "J2000", "XLT", body1.getName(), state, lt);
            double dist_sun = Math.sqrt(state[0]*state[0] + state[1]*state[1] + state[2]*state[2]);
            double angle = CSPICE.vsep(d_, new double[]{state[0],state[1],state[2]});
            angle = Math.toDegrees(angle);
            boolean condition1 = (angle <= angle_param & dist_sun < dist_target);
            boolean condition2 = (angle >= 180 - angle_param);
            return (condition1 || condition2);
        } catch (SpiceErrorException e) {
            throw new RuntimeException(e);
        } catch (Exception e) {
            KernelBody bodySun = (KernelBody) sun;
            double angle = rl.src.getBody().angularSep(rl.dest.getBody(), sun);
            double dist_sun = rl.src.getBody().distance(sun);
            double dist_dest = rl.src.getBody().distance(rl.dest.getBody());
            boolean cond1 = (angle <= angle_param && dist_sun < dist_dest);
            boolean cond2 = angle >= 180 - angle_param;
            return (cond1 || cond2);
        }

    }

    public boolean calcOccLgs(double el_parameter) {

        double elev;
        if (rl.src.getBody().onSurface) {
            elev = rl.src.getBody().elevation(rl.dest.getBody(), true);
            if (elev <= el_parameter) return true;
        }

        if (rl.dest.getBody().onSurface) {
            elev = rl.dest.getBody().elevation(rl.src.getBody(), true);
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
