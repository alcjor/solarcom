package space;

import java.util.HashMap;

public abstract class Body {

    protected String name;
    public HashMap params;
    public boolean onSurface;

    protected HashMap<Class, DistanceHandler> distanceOpMap;
    protected HashMap<Class, ElevationHanlder> elevationOpMap;
    protected HashMap<Class, OccultationHanlder> occultationOpMap;
    protected HashMap<Class, AngularSepHandler> angularSepOpMap;

    protected abstract void initOperationMap();

    public Body() {
        params = new HashMap();
        this.initOperationMap();
    }


    public String getName() {
        return name;
    }

    public double distance(Body other) {
        DistanceHandler handler = this.distanceOpMap.get(other.getClass());
        if (handler == null) {
            handler = other.distanceOpMap.get(this.getClass());
        }
        return handler.distance(other);
    }

    public double elevation(Body other) {
        ElevationHanlder handler = this.elevationOpMap.get(other.getClass());
        return handler.elevation(other);
    }

    public boolean occultation(Body other, Body occulting) {
        OccultationHanlder handler = this.occultationOpMap.get(other.getClass());
        return handler.occultation(other, occulting);
    }

    public double angularSep(Body body1, Body body2) {
        AngularSepHandler handler = this.angularSepOpMap.get(body1.getClass());
        return handler.angularSep(body1, body2);
    }


//    public Vector3 getPos(TDBTime time, Body observer) throws SpiceException {
//        throw new NotImplementedException();
//    };
//    public double getDist(TDBTime time, Body body) throws SpiceException {
//        throw new NotImplementedException();
//    };
}

interface DistanceHandler {
    double distance(Body other);
}

interface ElevationHanlder {
    double elevation(Body other);
}

interface OccultationHanlder {
    boolean occultation(Body other, Body occulting);
}

interface AngularSepHandler {
    double angularSep(Body body1, Body body2);
}