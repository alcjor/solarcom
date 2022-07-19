package nodes;

import spice.basic.Body;
import spice.basic.SpiceException;

public class BodyNode extends Node {

    static {
        System.loadLibrary("JNISpice");
    }

    private Body body;

    public BodyNode(Body body) throws SpiceException {
        super();
        this.body = body;
        this.name = body.getName();
    }

    public Body getBody() {
        return body;
    }
}
