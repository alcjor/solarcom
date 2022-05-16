import java.util.List;


public class GraphOld {

    // TODO: implement as sets!! (if possible)
    public List<NodeOld> nodes;
    public List<EdgeOld> edges;

    public GraphOld(List<NodeOld> nodes, List<EdgeOld> edges) {
        this.nodes = nodes;
        this.edges = edges;
    }

    public void add_node(NodeOld node) {
        // TODO: Check that node does not exist!!
        nodes.add(node);
    }

    public void add_edge(EdgeOld edge) {
        // TODO: Check that edge does not exist!!
        // TODO: Check that its nodes belong to the graph!
        edges.add(edge);
    }

}
