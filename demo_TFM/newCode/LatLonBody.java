package newCode;

import space.ClassTuple;
import space.KernelBody;
import space.SpiceTime;
import spice.basic.*;

import java.util.HashMap;

import static java.lang.Math.*;

public class LatLonBody extends space.Body {

    double lat;
    double lon;
	KernelBody planet;

    public LatLonBody(String name, KernelBody planet, double latitude, double longitude) throws SpiceException {
        super();
        this.planet = planet;
        this.onSurface = true;
        this.lat = Math.toRadians(latitude);
        this.lon = Math.toRadians(longitude);
		this.name = name;
    }


    protected void initOperationMap() {

        distanceOpMap = new HashMap<>();
        elevationOpMap = new HashMap<>();
        angularSepOpMap = new HashMap<>();
        occultationOpMap = new HashMap<>();

        distanceOpMap.put(ClassTuple.of(LatLonBody.class, KernelBody.class), (x, y) -> {
            return y.distance(this.planet);
        });

        elevationOpMap.put(ClassTuple.of(LatLonBody.class, KernelBody.class), (x,y) -> {
            return elevationKernel((LatLonBody) x, (KernelBody) y);
        });

        angularSepOpMap.put(ClassTuple.of(KernelBody.class, LatLonBody.class, KernelBody.class), (x, y, z) -> {
            return x.angularSep(this.planet, z);
        });

        angularSepOpMap.put(ClassTuple.of(KernelBody.class, KernelBody.class, LatLonBody.class), (x, y, z) -> {
            return x.angularSep(y, this.planet);
        });

        occultationOpMap.put(ClassTuple.of(KernelBody.class, LatLonBody.class, KernelBody.class), (x,y,z) -> {
            return x.occultation(this.planet, z);
        });


    }

    protected double elevationKernel(LatLonBody thisBody, KernelBody other) {
        TDBTime time = SpiceTime.getSpiceTime().getTime();
        StateRecord sr;
        try {
            double[] radii = planet.body.getValues("RADII");
            double re = radii[0];
            double rp = radii[2];
            double re2 = re*re;
            double rp2 = rp*rp;
            double nom = pow(re2*cos(lat),2) + pow(rp2*sin(lat),2);
            double denom = pow(re*cos(lat),2) + pow(rp*sin(lat),2);
            double r = sqrt(nom/denom);
            Vector3 my_rec = new Vector3(CSPICE.latrec(r,lon,lat));
            sr = new StateRecord(other.body, time, thisBody.planet.ref, new AberrationCorrection("XLT+S"), thisBody.planet.body);
            double alpha = my_rec.sep(sr.getPosition());
            double d = sr.getPosition().norm();
            double x = r/cos(alpha);
            double s = sqrt(d*d + r*r - 2*d*r*cos(alpha));
            double sinElev = 1/s*(d-x)*sin(PI/2+alpha);
            double elevation =  Math.toDegrees(asin(sinElev));


            double R = atmRefraction(elevation);
            elevation = elevation + R;
            return elevation;
        } catch (SpiceException e) {
            throw new RuntimeException(e);
        }
    }

    double atmRefraction(double e) {
        double a = abs(e);
        a = e + 0.14 + 7.32 / (e+4);
        return 0.02 / Math.tan(Math.toRadians(a));
    }


}
