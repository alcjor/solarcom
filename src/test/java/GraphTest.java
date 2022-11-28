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
    public void widestPathTest() {
        Node na = new FictitiousNode("A");
        Node nb = new FictitiousNode("B");
        Node nc = new FictitiousNode("C");
        Node nd = new FictitiousNode("D");
        Node ne = new FictitiousNode("E");
        Node nf = new FictitiousNode("F");
        Node ng = new FictitiousNode("G");

        List<Node> nodes = new ArrayList<>();
        nodes.add(na);
        nodes.add(nb);
        nodes.add(nc);
        nodes.add(nd);
        nodes.add(ne);
        nodes.add(nf);
        nodes.add(ng);

        List<Link> links = new ArrayList<>();
        links.add(new FictitiousLink(na, nc, 4));
        links.add(new FictitiousLink(na, ne, 9));
        links.add(new FictitiousLink(nb, nd, 8));
        links.add(new FictitiousLink(nb, nf, 7));
        links.add(new FictitiousLink(nc, nb, 5));
        links.add(new FictitiousLink(nc, nd, 8));
        links.add(new FictitiousLink(nd, nf, 6));
        links.add(new FictitiousLink(nd, ng, 5));
        links.add(new FictitiousLink(ne, nd, 10));
        links.add(new FictitiousLink(ng, nf, 7));

        JGraphTGraph graph = new JGraphTGraph(nodes, links);
        JGraphTDijkstra dijkstra = new JGraphTDijkstra(graph);

        JGraphTDijkstra.ShortestPath sp = dijkstra.getWidestPath(na, nf);
        System.out.println("Widest path dist: " + sp.distance);

        for (Node d: sp.destinations) {
            System.out.println(d.getName());
        }


//        DijkstraShortestPath dijkstraAlg =
//                new DijkstraShortestPath<Node, Link>(graph.getGraph());
//        GraphPath shortest_path =  dijkstraAlg.findPathBetween(graph.getGraph(), na, nf);
//        System.out.println("Shortest path: ");
//        List sp_links = shortest_path.getEdgeList();
//
//        for (Object l: sp_links) {
//            System.out.println(((Node) graph.getGraph().getEdgeSource(l)).getName());
//        }
    }

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

        DijkstraShortestPath dijkstraAlg =
                new DijkstraShortestPath<Node, Link>(graph.getGraph());
        GraphPath shortest_path =  dijkstraAlg.findPathBetween(graph.getGraph(), na, nf);
        System.out.print("Shortest path: ");
        List sp_links = shortest_path.getEdgeList();

        for (Object l: sp_links) {
            System.out.println(graph.getGraph().getEdgeSource(l));
        }
//        DefaultWeightedEdge l =  sp_links.get(0);

//        System.out.println(graph.getGraph().getEdgeSource(l));
//        for (Link l: sp_links) {
//            System.out.print(l.getSrc().getName() + "->" + l.getDest().getName() + "  ");
//        }

        System.out.println();
//        GraphPath path = dijkstra.
        assert dijkstra.calcShortestDistance(na, nf) == 8;

//        dijkstra.

    }
}
