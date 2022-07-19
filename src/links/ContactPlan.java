package links;

import spice.basic.Body;
import nodes.Node;

public class ContactPlan {

    private Body occultingBodies[];

    public ContactPlan(Body[] occultingBodies) {
        this.occultingBodies = occultingBodies.clone();
    }

    public boolean calcOccultation(Node observer, Node target) {
        return true;
    }



}
