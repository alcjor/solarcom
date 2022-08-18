package links;

import spice.basic.*;

import static java.lang.Math.abs;

public class ContactPlanOld {

    private Body occultingBodies[];
    private SpiceWindow tw;
    private AberrationCorrection abCorr;
    private double step;
    private String occType;

    public ContactPlanOld(Body[] occultingBodies) {
        this.occultingBodies = occultingBodies.clone();
    }

    public boolean calcOccultation(Body front, ReferenceFrame frameFront,
                                   Body back, ReferenceFrame frameBack,
                                   Body obsr, TDBTime time) throws SpiceException {

        AberrationCorrection
                abcorr = new AberrationCorrection( "XLT+S" );

        OccultationCode occ;
//        back = receiver, obsr = transmitter, front = occulting body
        occ = OccultationState.
                        getOccultationState( back,  "POINT", frameBack,
                                front,  "ELLIPSOID", frameFront,
                                abcorr, obsr, time     );

        switch (occ) {
            case ANNLR2:
            case PARTL2:
            case TOTAL2:
                return true;
            default:
                return false;
        }
    }

    static String[]   relation = { "LOCMIN", "ABSMIN",
            "LOCMAX", "ABSMAX" };

    public boolean calcSolarInterference(Body target, Body obsrvr, double angle_param, Time time)
            throws SpiceException {
//        Returns true if solar interference exists

        AberrationCorrection
                abcorr = new AberrationCorrection( "XLT" );
        Body            illum  = new Body ( "SUN" );

        ReferenceFrame frame  = new ReferenceFrame( "J2000"    );

        StateRecord s = new StateRecord(target, time, frame, abcorr, obsrvr);

        PositionVector v1 = s.getPosition();

        StateRecord s2 = new StateRecord(illum, time, frame, abcorr, obsrvr);
        PositionVector v2 = s2.getPosition();

        double angle = v1.sep(v2) * 180/3.14159;
        double dist_target = v1.norm();
        double dist_sun = v2.norm();

        boolean cond1 = (angle <= angle_param && dist_sun < dist_target);
        boolean cond2 = angle >= 180 - angle_param;

        return (cond1 || cond2);
    }


    public boolean calcOccLgs(
            Body node1, ReferenceFrame node1ref, String node1typ,
            Body node2, ReferenceFrame node2ref, String node2typ,
            double el_parameter, Time time) throws SpiceException {

        if (!(node1typ == "LANDER") && !(node1typ == "GROUND_STATION") &&
                !(node2typ == "LANDER") && !(node2typ == "GROUND_STATION")) {
            return false;
        }


//        CASE 1: Both nodes are landers or ground stations
        double[] rec;
        if (
                (node1typ == "LANDER" || node1typ == "GROUND_STATION") &&
                        (node2typ == "LANDER" || node2typ == "GROUND_STATION")
        ) {
            AberrationCorrection
                    abcorr = new AberrationCorrection("XLT+S");
            StateRecord s = new StateRecord(node2, time, node1ref, abcorr, node1);

            rec = CSPICE.reclat(s.getPosition().toArray());
            double el_node1 = rec[2] * 180 / 3.14159;
            double R = atmRefraction(el_node1);
            el_node1 = el_node1 + R;

            abcorr = new AberrationCorrection("LT+S");
            s = new StateRecord(node1, time, node2ref, abcorr, node2);
            rec = CSPICE.reclat(s.getPosition().toArray());
            double el_node2 = rec[2] * 180 / 3.14159;
            R = atmRefraction(el_node2);
            el_node2 = el_node2 + R;

            return el_node1 <= el_parameter || el_node2 <= el_parameter;
        }

        //  CASE 2: ONLY ONE NODE IS A LANDER OR A GROUND STATION
        StateRecord s;
        AberrationCorrection abcorr;
        if (node1typ == "LANDER" || node1typ == "GROUND_STATION") {
            abcorr = new AberrationCorrection("XLT+S");
            s = new StateRecord(node2, time, node1ref, abcorr, node1);
        } else {
            abcorr = new AberrationCorrection("LT+S");
            s = new StateRecord(node1, time, node2ref, abcorr, node2);
        }
        rec = CSPICE.reclat(s.getPosition().toArray());
        double el = rec[2] * 180 / 3.14159;
        double R = atmRefraction(el);
        el = el + R;
        return el <= el_parameter;
    }

    double atmRefraction(double e) {
        double a = abs(e);
        a = e + 0.14 + 7.32 / (e+4);
        return 0.02 / Math.tan(Math.toRadians(a));
    }


}
