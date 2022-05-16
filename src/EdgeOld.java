public class EdgeOld {

    NodeOld src;
    NodeOld dest;
    Double weight;

    public EdgeOld(NodeOld src, NodeOld dest, Double weight) {
        this.src = src;
        this.dest = dest;
        this.weight = weight;
    }

    public NodeOld getSrc() {
        return src;
    }

    public NodeOld getDest() {
        return dest;
    }

    public void setWeight(Double weight) {
        this.weight = weight;
    }

    public Double getWeight() {
        return weight;
    }
}
