public class NodeOld {

    String id;
    double dist;
    NodeOld prev;
    Boolean visited;

    public NodeOld(String id) {
        this.id = id;
    }

    public String getId() {
        return id;
    }

    public void setDist(double dist) {
        this.dist = dist;
    }

    public double getDist() {
        return dist;
    }

    public void setPrev(NodeOld prev) {
        this.prev = prev;
    }

    public NodeOld getPrev() {
        return prev;
    }
}
