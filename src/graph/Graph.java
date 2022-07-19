package graph;

import links.Link;
import nodes.Node;

import java.util.ArrayList;
import java.util.List;
//import src.graph.*;

public class Graph {

    List<Node> V;
    List<Link> E;

    public Graph() {
        E = new ArrayList<>();
        V = new ArrayList<>();
    }

    public void addVertex(Node v) {
        // Check non-existence (as a function of id, not of object)
        V.add(v);
    }

    void removeVertex(Node v) {
        V.remove(v);
    }

    public void addEdge(Link e) {
        // Check non-existence
        E.add(e);
    }

    void removeEdge(Link e) {
        E.remove(e);
    }

    public Link getEdge(Node src, Node dest) {

        for (Link e: this.E) {
            if(e.getSrc().equals(src) && e.getDest().equals(dest)) {
                return e;
            }
        }
        return null;

    }

    List<Node> getAdjacency(Node v) {
        List<Node> adj = new ArrayList<>();

        for (Link e: E) {
            if (e.getSrc() == v) {
                adj.add(e.getDest());
            }
        }

        return adj;
    }



}
