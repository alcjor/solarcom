package graph;

import java.util.ArrayList;
import java.util.List;

public class Graph {

    List<Vertex> V;
    List<Edge> E;

    public Graph() {
        E = new ArrayList<>();
        V = new ArrayList<>();
    }

    public void addVertex(Vertex v) {
        // Check non-existence (as a function of id, not of object)
        V.add(v);
    }

    void removeVertex(Vertex v) {
        V.remove(v);
    }

    public void addEdge(Edge e) {
        // Check non-existence
        E.add(e);
    }

    void removeEdge(Edge e) {
        E.remove(e);
    }

    public Edge getEdge(Vertex src, Vertex dest) {

        for (Edge e: this.E) {
            if(e.getSrc().equals(src) && e.getDest().equals(dest)) {
                return e;
            }
        }
        return null;

    }

    List<Vertex> getAdjacency(Vertex v) {
        List<Vertex> adj = new ArrayList<>();

        for (Edge e: E) {
            if (e.getSrc() == v) {
                adj.add(e.getDest());
            }
        }

        return adj;
    }



}
