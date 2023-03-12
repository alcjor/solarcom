package space;

import com.google.common.collect.HashBasedTable;
import com.google.common.collect.Table;
import spice.basic.*;
import spice.basic.Body;

import java.awt.image.Kernel;
import java.util.HashMap;

import static java.lang.Math.abs;

public class KernelBody extends space.Body {

    public Body body;
    public ReferenceFrame ref;
    private String refName;

    public KernelBody(String name, String ref, boolean onSurface) throws SpiceException {
        super();
        this.name = name;
        this.refName = ref;
        this.ref = new ReferenceFrame(ref);
        this.body = new Body(name);
        this.onSurface = onSurface;


    }


    protected void initOperationMap() {

        distanceOpMap = new HashMap<>();
        elevationOpMap = new HashMap<>();
        angularSepOpMap = new HashMap<>();
        occultationOpMap = new HashMap<>();


        distanceOpMap.put(ClassTuple.of(KernelBody.class, KernelBody.class), (x,y) -> {
            return distanceKernel((KernelBody) x, (KernelBody) y);
        });

        elevationOpMap.put(ClassTuple.of(KernelBody.class, KernelBody.class), (x,y, ref) -> {
           return elevationKernel((KernelBody) x, (KernelBody) y, (boolean) ref);
        });

        angularSepOpMap.put(ClassTuple.of(KernelBody.class, KernelBody.class, KernelBody.class), (x, y, z) -> {
            return angularSepKernel((KernelBody) x, (KernelBody) y, (KernelBody) z);
        });

        occultationOpMap.put(ClassTuple.of(KernelBody.class, KernelBody.class, KernelBody.class), (x,y,z) -> {
            return occultationKernel((KernelBody) x, (KernelBody) y, (KernelBody) z);
        });

    }

    protected double distanceKernel(KernelBody thisBody, KernelBody other) {
        try {
            TDBTime time = SpiceTime.getSpiceTime().getTime();
            ReferenceFrame J2000 = new ReferenceFrame("J2000");
            AberrationCorrection abcorr = new AberrationCorrection("XLT+S");
            Body earth = new Body("EARTH");
            PositionVector s1 = (new StateRecord(thisBody.body, time, J2000, abcorr, earth)).getPosition();
            PositionVector s2 = (new StateRecord(other.body, time, J2000, abcorr, earth)).getPosition();
            return s1.dist(s2);

        } catch (SpiceException e) {
            throw new RuntimeException(e);
        }

    }

    protected double elevationKernel(KernelBody thisBody, KernelBody other, boolean refraction) {
        TDBTime time = SpiceTime.getSpiceTime().getTime();
        StateRecord s = null;
        try {
            s = new StateRecord(other.body, time, thisBody.ref, new AberrationCorrection("LT+S"), thisBody.body);
            double[] rec = CSPICE.reclat(s.getPosition().toArray());
            double elevation = Math.toDegrees(rec[2]);
            if (refraction) {
                double R = atmRefraction(elevation);
                elevation = elevation + R;
            }
            return elevation;
        } catch (SpiceException e) {
            throw new RuntimeException(e);
        }
    }

    protected boolean occultationKernel(KernelBody obs, KernelBody target, KernelBody occulting) {


        if (obs.refName == "UNDEF" && target.refName == "UNDEF") return false;
//        Checks if other body is occulted wrt this body
        AberrationCorrection
                abcorr = null;
        try {

            double time = SpiceTime.getSpiceTime().getTime().getTDBSeconds();
            double[] aux = CSPICE.gfoclt("ANY", occulting.name, "ELLIPSOID", occulting.refName,
                    target.name, "POINT", " ", "XLT+S", obs.name, 1,
                    1, new double[] {time, time});
            if (aux.length != 0) return true;
            return false;


        } catch (SpiceException e) {
            throw new RuntimeException(e);
        }
    }

    protected double angularSepKernel(KernelBody thisBody, KernelBody body1, KernelBody body2) {
//        Angular separation between two bodies as seen from this one

        try {
            TDBTime time = SpiceTime.getSpiceTime().getTime();
            ReferenceFrame J2000 = new ReferenceFrame("J2000");
            AberrationCorrection abcorr = new AberrationCorrection("XLT");
            Body earth = new Body("EARTH");
            PositionVector p1 = (new StateRecord(body1.body, time, J2000, abcorr, earth)).getPosition();
            PositionVector p2 = (new StateRecord(body2.body, time, J2000, abcorr, earth)).getPosition();
            PositionVector p3 = (new StateRecord(thisBody.body, time, J2000, abcorr, earth)).getPosition();
            return Math.toDegrees(p1.sub(p3).sep(p2.sub(p3)));


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

