import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Dijkstra {

    HashMap<Vertex, VertexState> states;

    public Dijkstra() {
        states = new HashMap<>();
    }

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
    private void initialize_shortest_path(Graph g, Vertex s) {
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

    private VertexState extract_min() {
        VertexState min_vertex = null;
        double min_dist = Double.POSITIVE_INFINITY;

        for (VertexState v: states.values()) {
            System.out.println("Id: " + v.vertex.get_id());
            if (!v.visited && v.dist <= min_dist) {
                min_vertex = v;
                min_dist = v.dist;
            }
        }

        return min_vertex;
    }

    private boolean all_nodes_visited() {
        for (VertexState v: states.values()) {
            if (!v.visited) {return false;}
        }
        return true;
    }


    public double shortest_path(Graph g, Vertex src, Vertex dest) {
        initialize_shortest_path(g, src);

        while (true) {
            if (all_nodes_visited()) {return -1;}
            VertexState u = extract_min();
            System.out.println("min_vertex: " + u.vertex.get_id());
            if (u.vertex.equals(dest)) {return u.dist;}
            u.visited = true;
            List<Vertex> adj = g.get_adjacency(u.vertex);

            for(Vertex vv: adj) {
                VertexState v = states.get(vv);
                Edge e = g.get_edge(u.vertex,v.vertex);
                relax(u,v,e.get_weight());
            }
        }
    }

}
