package space;

import spice.basic.*;
import spice.basic.Body;

import java.util.HashMap;

import static java.lang.Math.abs;

public class KernelBody extends space.Body {

    Body body;
    ReferenceFrame ref;

    public KernelBody(String name, String ref, boolean onSurface) throws SpiceException {
        super();
        this.name = name;
        this.ref = new ReferenceFrame(ref);
        this.body = new Body(name);
        this.onSurface = onSurface;


    }

//    public Vector3 getPos(TDBTime time, KernelBody observer) throws SpiceException {
//        return new StateRecord(body, time, observer.ref,
//                new AberrationCorrection("XLT+S"), observer.body).getPosition();
//    }

//    public double getDist(KernelBody obs) throws SpiceException {
//        TDBTime time = SpiceTime.getSpiceTime().getTime();
//        StateRecord s = new StateRecord(body, time, obs.ref,
//                new AberrationCorrection("XLT+S"), obs.body);
//        return s.getPosition().norm();
//    }

    protected void initOperationMap() {
        distanceOpMap = new HashMap<>();
        elevationOpMap = new HashMap<>();
        occultationOpMap = new HashMap<>();
        angularSepOpMap = new HashMap<>();
        distanceOpMap.put(KernelBody.class, (x) -> {
            return distanceKernel((KernelBody) x);
        });
        elevationOpMap.put(KernelBody.class, (x) -> {
            return elevationKernel((KernelBody) x);
        });
        angularSepOpMap.put(KernelBody.class, (x, y) -> {
            return angularSepKernel((KernelBody) x, (KernelBody) y);
        });
        occultationOpMap.put(KernelBody.class, (x,y) -> {
            return occultationKernel((KernelBody) x, (KernelBody) y);
        });

    }

    protected double distanceKernel(KernelBody other) {
        try {
            TDBTime time = SpiceTime.getSpiceTime().getTime();
            StateRecord s = new StateRecord(body, time, other.ref,
                    new AberrationCorrection("XLT+S"), other.body);
            return s.getPosition().norm();
        } catch (SpiceException e) {
            throw new RuntimeException(e);
        }

    }

    protected double elevationKernel(KernelBody other) {
        TDBTime time = SpiceTime.getSpiceTime().getTime();
        StateRecord s = null;
        try {
            s = new StateRecord(other.body, time, this.ref, new AberrationCorrection("XLT+S"), this.body);
            double[] rec = CSPICE.reclat(s.getPosition().toArray());
            double elevation = rec[2] * 180 / 3.14159;
            double R = atmRefraction(elevation);
            elevation = elevation + R;
            return elevation;
        } catch (SpiceException e) {
            throw new RuntimeException(e);
        }
    }

    protected boolean occultationKernel(KernelBody other, KernelBody occulting) {
//        Checks if other body is occulted wrt this body
        AberrationCorrection
                abcorr = null;
        try {
            abcorr = new AberrationCorrection( "XLT+S" );
            OccultationCode occ;
//        back = receiver, obsr = transmitter, front = occulting body
            TDBTime time = SpiceTime.getSpiceTime().getTime();
            occ = OccultationState.
                    getOccultationState(
                            occulting.body,  "ELLIPSOID", occulting.ref,
                            other.body,  "POINT", other.ref,
                            abcorr, this.body, time     );

            switch (occ) {
                case ANNLR2:
                case PARTL2:
                case TOTAL2:
//                    System.out.println(other.getName() + " occulted from " + this.getName() + " by " + occulting.getName());
//                    System.out.println("Type of occultation: " + occ.name());
                    return true;
                default:
                    return false;
            }
        } catch (SpiceException e) {
            throw new RuntimeException(e);
        }
    }

    protected double angularSepKernel(KernelBody body1, KernelBody body2) {
//        Angular separation between two bodies as seen from this one
        AberrationCorrection
                abcorr = null;
        try {
            abcorr = new AberrationCorrection( "XLT" );
            TDBTime time = SpiceTime.getSpiceTime().getTime();

            StateRecord s = new StateRecord(body1.body, time, ref, abcorr, body);

            PositionVector v1 = s.getPosition();

            StateRecord s2 = new StateRecord(body2.body, time, ref, abcorr, body);
            PositionVector v2 = s2.getPosition();
            return v1.sep(v2) * 180/3.14159;
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

