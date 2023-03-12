package nodes;

import id.IDGenerator;

public abstract class Node {

    private int id;
    protected String name;

    protected Node() {
        id = IDGenerator.getInstance().getId();
    }

    public int getId() {
        return this.id;
    }
    public String getName() {
        return this.name;
    }

}

