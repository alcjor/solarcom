package id;

public class IDGenerator {
    private int id;
    private static IDGenerator idGenerator = new IDGenerator();

    private IDGenerator(){
        id = 0;
    }

    public int getId() {
        id++;
        return id;
    }

    public static IDGenerator getInstance() {
        return idGenerator;
    }
}
