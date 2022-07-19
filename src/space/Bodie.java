package space;

import id.IDGenerator;

public abstract class Bodie {

//
//    static {
//        System.loadLibrary("JNISpice");
//    }
//
    private int id;
    private String name;

    public Bodie() {
        id = IDGenerator.getInstance().getId();
    }

    public abstract void update(double time);

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }
}
