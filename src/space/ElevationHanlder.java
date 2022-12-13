package space;

public interface ElevationHanlder {
    //    double elevation(Body other);
    double elevation(Body thisBody, Body other, boolean refraction);
}
