package links;

import nodes.Node;

public class RadioLink extends Link {

    private double dataRate;

    public RadioLink(Node src, Node dest) {
        super(src, dest);
    }

    public double getDataRate() {
        return dataRate;
    }
}
