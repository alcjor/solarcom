package links;

import nodes.Node;

public abstract class Link {

    Node src;
    Node dest;
    private double weight;

    protected Link(Node src, Node dest) {
        if (src == null) {
            throw new RuntimeException("SRC node is null");
        }
        if (dest == null) {
            throw new RuntimeException("DEST node is null");
        }
        this.src = src;
        this.dest = dest;
    }
    public Node getSrc() {
        return this.src;
    }
    public Node getDest() {
        return this.dest;
    }
    public double getWeight() {
        return this.weight;
    }
    public void setWeight(double weight) {this.weight = weight;}
}
