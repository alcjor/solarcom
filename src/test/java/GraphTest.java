package test.java;

import graph.Graph;
import graph.JGraphTDijkstra;
import graph.JGraphTGraph;
import links.FictitiousLink;
import links.Link;
import nodes.FictitiousNode;
import nodes.Node;
//import org.jgrapht.Graph;
import org.jgrapht.GraphPath;
import org.jgrapht.alg.shortestpath.DijkstraShortestPath;
import org.jgrapht.graph.DefaultDirectedWeightedGraph;
import org.jgrapht.graph.DefaultWeightedEdge;
import org.junit.Test;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;

public class GraphTest {

    @Test
    public void shortestPathTest() {
//        Graph<Node, DefaultWeightedEdge> graph  =
//                new DefaultDirectedWeightedGraph(DefaultWeightedEdge.class);

        Node na = new FictitiousNode("A");
        Node nb = new FictitiousNode("B");
        Node nc = new FictitiousNode("C");
        Node nd = new FictitiousNode("D");
        Node ne = new FictitiousNode("E");
        Node nf = new FictitiousNode("F");

        List<Node> nodes = new ArrayList<>();
        nodes.add(na);
        nodes.add(nb);
        nodes.add(nc);
        nodes.add(nd);
        nodes.add(ne);
        nodes.add(nf);

        List<Link> links = new ArrayList<>();
        links.add(new FictitiousLink(na, nb, 1));
        links.add(new FictitiousLink(na, nc, 2));
        links.add(new FictitiousLink(na, nd, 8));
        links.add(new FictitiousLink(nb, ne, 3));
        links.add(new FictitiousLink(nc, nd, 9));
        links.add(new FictitiousLink(nc, ne, 3));
        links.add(new FictitiousLink(nc, nf, 8));
        links.add(new FictitiousLink(nd, nf, 20));
        links.add(new FictitiousLink(ne, nf, 4));

        JGraphTGraph graph = new JGraphTGraph(nodes, links);

//        System.out.println(graph.getNodes());

        JGraphTDijkstra dijkstra = new JGraphTDijkstra(graph);


        assert dijkstra.calcShortestDistance(na, nf) == 8;


    }
}
