package graph;

import links.Link;
import nodes.Node;
import org.jgrapht.graph.DefaultDirectedWeightedGraph;
import org.jgrapht.graph.DefaultWeightedEdge;

import java.util.Collection;
import java.util.LinkedList;
import java.util.List;


public class JGraphTGraph implements Graph{

    org.jgrapht.Graph<Node, DefaultWeightedEdge> graph;
    List<Link> links;
    List<Node> nodes;

    public JGraphTGraph(Collection<Node> nodes, Collection<Link> links) {

        this.nodes = new LinkedList<Node>();
        this.links = new LinkedList<Link>();

        this.nodes.addAll(nodes);
        this.links.addAll(links);

        this.graph = new DefaultDirectedWeightedGraph(DefaultWeightedEdge.class);

        for (Node node: nodes) {
            this.graph.addVertex(node);
        }

        for (Link link: links) {
            this.graph.setEdgeWeight(
                    this.graph.addEdge(link.getSrc(), link.getDest()), link.getWeight());
        }

    }


    public void updateWeights() {
        for (Link link: links) {
            DefaultWeightedEdge edge = this.graph.getEdge(link.getSrc(), link.getDest());
            this.graph.setEdgeWeight(edge, link.getWeight());
        }

    }

    public void addNode(Node node) {
        this.graph.addVertex(node);
    }

    public void removeNode(Node node) {
        this.graph.removeVertex(node);
    }

    public void addLink(Link link) {
        this.graph.setEdgeWeight(
                this.graph.addEdge(link.getSrc(), link.getDest()),
                link.getWeight()
        );
    }

    public void removeLink(Link link) {
        this.graph.removeEdge(link.getSrc(), link.getDest());
    }

    public List<Node> getNodes() {
        return this.nodes;
    }

    public List<Link> getLinks() {
        return this.links;
    }

    public org.jgrapht.Graph getGraph() {
        return this.graph;
    }
}
