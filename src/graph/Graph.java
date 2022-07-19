package graph;

import links.Link;
import nodes.Node;
public interface Graph {

    public void updateWeights();

    public void addNode(Node node);
    public void removeNode(Node node);
    public void addLink(Link link);
    public void removeLink(Link link);

    public Node[] getNodes();
    public Link[] getLinks();


}
