package graph;

import java.util.HashMap;
import java.util.List;

class VertexState {

    double dist;
    boolean visited;
    Vertex prev;

    Vertex vertex;

    VertexState(Vertex v) {
        this.vertex = v;
        reset();
    }

    public void reset() {
        this.dist = Double.POSITIVE_INFINITY;
        this.visited = false;
        this.prev = null;
    }
}

public class Dijkstra {

    HashMap<Vertex, VertexState> states;

    public Dijkstra() {
        states = new HashMap<>();
    }


    private void initializeShortestPath(Graph g, Vertex s) {
        states = new HashMap<>();
        for (Vertex v: g.V) {
            states.put(v, new VertexState(v));
        }
        states.get(s).dist = 0.0;
    }

    private void relax(VertexState u, VertexState v, double w) {
        if (v.dist > u.dist + w) {
            v.dist = u.dist + w;
            v.prev = u.vertex;
        }
    }

    private VertexState extractMin() {
        VertexState minVertex = null;
        double minDist = Double.POSITIVE_INFINITY;

        for (VertexState v: states.values()) {
            if (!v.visited && v.dist <= minDist) {
                minVertex = v;
                minDist = v.dist;
            }
        }

        return minVertex;
    }

    private boolean all_nodes_visited() {
        for (VertexState v: states.values()) {
            if (!v.visited) {return false;}
        }
        return true;
    }


    public double shortestPath(Graph g, Vertex src, Vertex dest) {
        initializeShortestPath(g, src);

        while (true) {
            if (all_nodes_visited()) {return -1;}
            VertexState u = extractMin();
            if (u.vertex.equals(dest)) {return u.dist;}
            u.visited = true;
            List<Vertex> adj = g.getAdjacency(u.vertex);

            for(Vertex vv: adj) {
                VertexState v = states.get(vv);
                Edge e = g.getEdge(u.vertex,v.vertex);
                relax(u,v,e.getWeight());
            }
        }
    }

}