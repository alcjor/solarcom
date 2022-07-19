package graph;

import nodes.Node;
import org.jgrapht.GraphPath;
import org.jgrapht.alg.shortestpath.DijkstraShortestPath;

public class JGraphTDijkstra implements Dijkstra {

    JGraphTGraph graph;

    public JGraphTDijkstra(JGraphTGraph graph) {
        this.graph = graph;
    }

    public double calcShortestDistance(Node src, Node target) {
        DijkstraShortestPath dijkstraAlg =
                new DijkstraShortestPath<>(graph.getGraph());
        GraphPath shortest_path =  dijkstraAlg.findPathBetween(graph.getGraph(), src, target);

        return shortest_path.getWeight();
    }
}
