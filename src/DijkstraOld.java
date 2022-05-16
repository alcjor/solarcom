import java.util.ArrayList;
import java.util.List;

public class DijkstraOld {

    private static void initialize_shortest_path(GraphOld g, NodeOld s) {
        for (NodeOld n: g.nodes) {
            n.setDist(Double.POSITIVE_INFINITY);
            n.setPrev(null);
            n.visited = false;
        }
        s.setDist(0);
    }

    private static void relax(NodeOld u, NodeOld v, double w) {
        if (v.dist > u.dist + w) {
            v.dist = u.dist + w;
            v.prev = u;
        }
    }

    private static NodeOld extract_min(GraphOld g) {
        NodeOld min_node = null;
        double min_dist = Double.POSITIVE_INFINITY;

        for (NodeOld n: g.nodes) {
            if (!n.visited && n.dist <= min_dist) {
                min_node = n;
                min_dist = n.dist;
            }
        }

        return min_node;
    }

    private static Boolean all_nodes_visited(GraphOld g) {
        for (NodeOld n: g.nodes) {
            if (!n.visited) {return false;}
        }
        return true;
    }

    private static List<NodeOld> get_adjacency(GraphOld g, NodeOld n) {
        List<NodeOld> adj = new ArrayList<>();
        for (EdgeOld e: g.edges) {
            if (e.src == n) {
                adj.add(e.dest);
            }
        }
        return adj;
    }

    private static EdgeOld find_edge(GraphOld g, NodeOld src, NodeOld dest) {

        for (EdgeOld e: g.edges) {
            if(e.src == src && e.dest == dest) {
                return e;
            }
        }
        return null;

    }

    public static double shortest_path(GraphOld g, NodeOld src, NodeOld dest) {
        initialize_shortest_path(g, src);

        while (true) {
            if (all_nodes_visited(g)) {return -1;}
            NodeOld u = extract_min(g);
            if (u.id == dest.id) {return u.dist;}
            u.visited = true;
            List<NodeOld> adj = get_adjacency(g,u);

            for(NodeOld v: adj) {
                EdgeOld e = find_edge(g,u,v);
                relax(u,v,e.weight);
            }
        }
    }

}
