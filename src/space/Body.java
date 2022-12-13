package space;

import com.google.common.collect.Multimap;
import com.google.common.collect.Table;

import java.util.HashMap;

public abstract class Body {

    protected String name;
    public HashMap params;
    public boolean onSurface;

    protected HashMap<ClassTuple, DistanceHandler> distanceOpMap;
    protected HashMap<ClassTuple, ElevationHanlder> elevationOpMap;
    protected HashMap<ClassTuple, OccultationHanlder> occultationOpMap;
    protected HashMap<ClassTuple, AngularSepHandler> angularSepOpMap;

//    protected Table<Class, Class, DistanceHandler> distanceOpTable;
//    protected Table<Class, Class, ElevationHanlder> elevationOpTable;
//
//    protected Table<Class, Class, AngularSepHandler> angularSepOpTable;


    protected abstract void initOperationMap();

    public Body() {
        params = new HashMap();
        this.initOperationMap();
    }


    public String getName() {
        return name;
    }

    public double distance(Body other) {
        ClassTuple classes = ClassTuple.of(this.getClass(), other.getClass());
        ClassTuple classesInv = ClassTuple.of(other.getClass(), this.getClass());
        DistanceHandler handler = this.distanceOpMap.get(classes);
        if (handler != null) {
            return handler.distance(this, other);
        }
        handler = other.distanceOpMap.get(classesInv);
        return handler.distance(other, this);
    }

    public double elevation(Body other, boolean refraction) {
        ClassTuple classes = ClassTuple.of(this.getClass(), other.getClass());
        ElevationHanlder handler = this.elevationOpMap.get(classes);
        if (handler == null) {
            handler = other.elevationOpMap.get(classes);
        }
        return handler.elevation(this, other, refraction);
    }

    public boolean occultation(Body target, Body occulting) {

        Class obsClass = this.getClass();
        Class targClass = target.getClass();
        Class occClass = occulting.getClass();
        ClassTuple classes = ClassTuple.of(obsClass, targClass, occClass);
        OccultationHanlder handler = this.occultationOpMap.get(classes);
        if (handler != null) {
            return handler.occultation(this, target, occulting);
        }
        handler = target.occultationOpMap.get(classes);
        if (handler != null) {
            return handler.occultation(this, target, occulting);
        }
        handler = occulting.occultationOpMap.get(classes);
        return handler.occultation(this, target, occulting);

    }

    public double angularSep(Body body1, Body body2) {
        ClassTuple classes = ClassTuple.of(this.getClass(), body1.getClass(), body2.getClass());
        AngularSepHandler handler = this.angularSepOpMap.get(classes);
        if (handler != null) {
            return handler.angularSep(this, body1, body2);
        }
        handler = body1.angularSepOpMap.get(classes);
        if (handler != null) {
            return handler.angularSep(this, body1, body2);
        }
        handler = body2.angularSepOpMap.get(classes);
        return handler.angularSep(this, body1, body2);
    }


//    public Vector3 getPos(TDBTime time, Body observer) throws SpiceException {
//        throw new NotImplementedException();
//    };
//    public double getDist(TDBTime time, Body body) throws SpiceException {
//        throw new NotImplementedException();
//    };
}


