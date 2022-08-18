package links;

import nodes.Node;

public abstract class Link {

    Node src;
    Node dest;
    private double weight;

    protected Link(Node src, Node dest) {
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
    protected void setWeight(double weight) {this.weight = weight;}
}
