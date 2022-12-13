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

//        new ReferenceFrame()


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
//        distanceOpTable = HashBasedTable.create();
//        elevationOpTable = HashBasedTable.create();
//        occultationObsOpTable = HashBasedTable.create();
//        occultationTargOpTable = HashBasedTable.create();
//        occultationOccOpTable = HashBasedTable.create();

        distanceOpMap = new HashMap<>();
        elevationOpMap = new HashMap<>();
        angularSepOpMap = new HashMap<>();
        occultationOpMap = new HashMap<>();

//        distanceOpTable.put(KernelBody.class, KernelBody.class, (x,y) -> {
//            return distanceKernel((KernelBody) x, (KernelBody) y);
//        });
//
//        elevationOpTable.put(KernelBody.class, KernelBody.class, (x,y) -> {
//           return elevationKernel((KernelBody) x, (KernelBody) y);
//        });

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

//        occultationObsOpTable.put(KernelBody.class, KernelBody.class, (x,y,z) -> {
//            return occultationKernel((KernelBody) x, (KernelBody) y, (KernelBody) z);
//        });

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
//
//            if (other.refName == "UNDEF") {
//            s = new StateRecord(other.body, time, this.ref,
//                    new AberrationCorrection("XLT+S"), this.body);
//            } else {
//                s = new StateRecord(thisBody.body, time, other.ref,
//                     new AberrationCorrection("XLT+S"), other.body);
//            }
//            return s.getPosition().norm();
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

//        ReferenceFrame emtpy = new ReferenceFrame(" ");
            double time = SpiceTime.getSpiceTime().getTime().getTDBSeconds();
            double[] aux = CSPICE.gfoclt("ANY", occulting.name, "ELLIPSOID", occulting.refName,
                    target.name, "POINT", " ", "XLT+S", obs.name, 1,
                    1, new double[] {time, time});
            if (aux.length != 0) return true;
            return false;

//            abcorr = new AberrationCorrection( "XLT+S" );
//            OccultationCode occ;
////        back = receiver, obsr = transmitter, front = occulting body
//            TDBTime time = SpiceTime.getSpiceTime().getTime();
//
//
//            if (target.refName == "UNDEF") {
//                occ = OccultationState.
//                    getOccultationState(
//                            occulting.body,  "ELLIPSOID", occulting.ref,
//                            obs.body,  "POINT", obs.ref,
//                            abcorr, target.body, time     );
//                switch (occ) {
//                    case ANNLR1:
//                    case PARTL1:
//                    case TOTAL1:
//    //                    System.out.println(other.getName() + " occulted from " + this.getName() + " by " + occulting.getName());
//    //                    System.out.println("Type of occultation: " + occ.name());
//                        return true;
//                    default:
//                        return false;
//                }
//            } else {
//                occ = OccultationState.
//                    getOccultationState(
//                            occulting.body,  "ELLIPSOID", occulting.ref,
//                            target.body,  "POINT", target.ref,
//                            abcorr, obs.body, time     );
//                switch (occ) {
//                    case ANNLR2:
//                    case PARTL2:
//                    case TOTAL2:
//    //                    System.out.println(other.getName() + " occulted from " + this.getName() + " by " + occulting.getName());
//    //                    System.out.println("Type of occultation: " + occ.name());
//                        return true;
//                    default:
//                        return false;
//                }
//
//            }


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
//            abcorr = new AberrationCorrection( "XLT" );
//            TDBTime time = SpiceTime.getSpiceTime().getTime();
//
//            if (thisBody.refName == "UNDEF") {
//                StateRecord s = new StateRecord(body1.body, time, thisBody.ref, abcorr, thisBody.body);
//
//                PositionVector v1 = s.getPosition();
//
//                StateRecord s2 = new StateRecord(body2.body, time, thisBody.ref, abcorr, thisBody.body);
//                PositionVector v2 = s2.getPosition();
//                return v1.sep(v2) * 180/3.14159;
//            } else {
//                StateRecord s = new StateRecord(body1.body, time, thisBody.ref, abcorr, thisBody.body);
//
//                PositionVector v1 = s.getPosition();
//
//                StateRecord s2 = new StateRecord(body2.body, time, thisBody.ref, abcorr, thisBody.body);
//                PositionVector v2 = s2.getPosition();
//                return v1.sep(v2) * 180/3.14159;
//            }

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

