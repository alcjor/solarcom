package test.java;

import links.Link;
import nodes.FictitiousNode;
import org.jgrapht.Graph;
import org.jgrapht.GraphPath;
import org.jgrapht.alg.interfaces.ShortestPathAlgorithm;
import org.jgrapht.alg.shortestpath.DijkstraShortestPath;
import org.jgrapht.graph.*;
import org.junit.Test;

import nodes.Node;

import java.util.List;

public class GraphLibraryTest {

    @Test
    public void test() {

        Graph<String, DefaultEdge> stringGraph = createStringGraph();
        Graph<Node, DefaultWeightedEdge> g2 = new DefaultDirectedWeightedGraph<>(DefaultWeightedEdge.class);
//        DirectedGraph
//
        Node n1 = new FictitiousNode("n1");
        Node n2 = new FictitiousNode("n2");
        g2.addVertex(n1);
        g2.addVertex(n2);
        DefaultWeightedEdge e = g2.addEdge(n1, n2);
        g2.setEdgeWeight(e, 5.2);
//        System.out.println(g2. );
        g2.setEdgeWeight(e, 4.2);
        System.out.println(e.toString());



        // note undirected edges are printed as: {<v1>,<v2>}
        System.out.println("-- toString output");
        System.out.println(stringGraph.toString());
        System.out.println();

        DijkstraShortestPath<String, DefaultEdge> dijkstraAlg =
                new DijkstraShortestPath<>(stringGraph);
        ShortestPathAlgorithm.SingleSourcePaths<String, DefaultEdge> iPaths = dijkstraAlg.getPaths("v1");
        System.out.println(iPaths.getPath("v4") + "\n");


    }

    private static Graph<String, DefaultEdge> createStringGraph() {
        Graph<String, DefaultEdge> g = new DefaultDirectedGraph<>(DefaultEdge.class);

        String v1 = "v1";
        String v2 = "v2";
        String v3 = "v3";
        String v4 = "v4";

        // add the vertices
        g.addVertex(v1);
        g.addVertex(v2);
        g.addVertex(v3);
        g.addVertex(v4);

        // add edges to create a circuit
        g.addEdge(v1, v2);
        g.addEdge(v2, v3);
        g.addEdge(v3, v4);
        g.addEdge(v4, v1);

        return g;
    }

    @Test
    public void stackoverflowtest() {
        SimpleDirectedWeightedGraph<String, DefaultWeightedEdge>  graph =
                new SimpleDirectedWeightedGraph<String, DefaultWeightedEdge>
                        (DefaultWeightedEdge.class);
        graph.addVertex("vertex1");
        graph.addVertex("vertex2");
        graph.addVertex("vertex3");
        graph.addVertex("vertex4");
        graph.addVertex("vertex5");


        DefaultWeightedEdge e1 = graph.addEdge("vertex1", "vertex2");
        graph.setEdgeWeight(e1, 5);

        DefaultWeightedEdge e2 = graph.addEdge("vertex2", "vertex3");
        graph.setEdgeWeight(e2, 3);

        DefaultWeightedEdge e3 = graph.addEdge("vertex4", "vertex5");
        graph.setEdgeWeight(e3, 6);

        DefaultWeightedEdge e4 = graph.addEdge("vertex2", "vertex4");
        graph.setEdgeWeight(e4, 2);

        DefaultWeightedEdge e5 = graph.addEdge("vertex5", "vertex4");
        graph.setEdgeWeight(e5, 4);


        DefaultWeightedEdge e6 = graph.addEdge("vertex2", "vertex5");
        graph.setEdgeWeight(e6, 9);

        DefaultWeightedEdge e7 = graph.addEdge("vertex4", "vertex1");
        graph.setEdgeWeight(e7, 7);

        DefaultWeightedEdge e8 = graph.addEdge("vertex3", "vertex2");
        graph.setEdgeWeight(e8, 2);

        DefaultWeightedEdge e9 = graph.addEdge("vertex1", "vertex3");
        graph.setEdgeWeight(e9, 10);

        DefaultWeightedEdge e10 = graph.addEdge("vertex3", "vertex5");
        graph.setEdgeWeight(e10, 1);


        System.out.println("Shortest path from vertex1 to vertex5:");
        DijkstraShortestPath dijkstraAlg =
                new DijkstraShortestPath<>(graph);
        GraphPath shortest_path =   dijkstraAlg.findPathBetween(graph, "vertex1", "vertex5");
        System.out.println("total: " + shortest_path.getWeight());
        System.out.println(shortest_path);

    }
}
