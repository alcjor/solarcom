package links;

import nodes.Node;

public class FictitiousLink extends Link {

    public FictitiousLink(Node src, Node dest, double weight) {
        super(src, dest);
        setWeight(weight);
    }
}
