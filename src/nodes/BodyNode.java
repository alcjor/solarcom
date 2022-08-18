package nodes;
//
//import spice.basic.Body;
//import spice.basic.SpiceException;

import space.Body;
import space.CommunicationStrategy;

public class BodyNode extends Node {

    static {
        System.loadLibrary("JNISpice");
    }

    private Body body;
    public CommunicationStrategy comm;

    public BodyNode(Body body, CommunicationStrategy comm) {
        super();
        this.body = body;
        this.name = body.getName();
        this.comm = comm;
    }
    public Body getBody() {
        return body;
    }


}
