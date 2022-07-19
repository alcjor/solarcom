package graph;

import links.Link;
import nodes.Node;

public class SimpleLink extends Link {

    Node src;
    Node dest;
    double weight;

    public SimpleLink(Node src, Node dest, double weight) {
        super(src, dest);
        this.weight = weight;
    }

    @Override
    public Node getSrc() {
        return src;
    }

    @Override
    public Node getDest() {
        return dest;
    }

    @Override
    public double getWeight() {
        return weight;
    }

    @Override
    public void setWeight(double weight) {
        this.weight = weight;
    }
}
