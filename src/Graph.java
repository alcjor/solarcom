import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class Graph {

    List<Vertex> V;
    List<Edge> E;

    public Graph() {
        E = new ArrayList<>();
        V = new ArrayList<>();
    }

    void add_vertex(Vertex v) {
        // Check non-existence (as a function of id, not of object)
        V.add(v);
    }

    void remove_vertex(Vertex v) {
        V.remove(v);
    }

    void add_edge(Edge e) {
        // Check non-existence
        E.add(e);
    }

    void remove_edge(Edge e) {
        E.remove(e);
    }

    Edge get_edge(Vertex src, Vertex dest) {

        for (Edge e: this.E) {
            if(e.get_src().equals(src) && e.get_dest().equals(dest)) {
                return e;
            }
        }
        return null;

    }

    List<Vertex> get_adjacency(Vertex v) {
        List<Vertex> adj = new ArrayList<Vertex>();

        for (Edge e: E) {
            if (e.get_src() == v) {
                adj.add(e.get_dest());
            }
        }

        return adj;
    }



}
