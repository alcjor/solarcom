package graph;

import links.Link;
import nodes.Node;

import java.util.List;

public interface Graph {

    public void updateWeights();

    public void addNode(Node node);
    public void removeNode(Node node);
    public void addLink(Link link);
    public void removeLink(Link link);

    public List<Node> getNodes();
    public List<Link> getLinks();


}
