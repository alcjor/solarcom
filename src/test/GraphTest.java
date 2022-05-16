package test;

import graph.Dijkstra;
import graph.Graph;
import graph.SimpleEdge;
import graph.SimpleVertex;
import org.junit.jupiter.api.Test;

public class GraphTest {

    @Test
    public void dijkstraTest() {

        SimpleVertex v1 = new SimpleVertex("A");
        SimpleVertex v2 = new SimpleVertex("B");
        SimpleVertex v3 = new SimpleVertex("C");
        SimpleVertex v4 = new SimpleVertex("D");
        SimpleVertex v5 = new SimpleVertex("E");
        SimpleVertex v6 = new SimpleVertex("F");

        Graph g = new Graph();

        g.addVertex(v1);
        g.addVertex(v2);
        g.addVertex(v3);
        g.addVertex(v4);
        g.addVertex(v5);
        g.addVertex(v6);

        g.addEdge(new SimpleEdge(v1, v2, 1.0));
        g.addEdge(new SimpleEdge(v1, v3, 2.0));
        g.addEdge(new SimpleEdge(v1, v4, 8.0));
        g.addEdge(new SimpleEdge(v2, v5, 3.0));
        g.addEdge(new SimpleEdge(v3, v5, 3.0));
        g.addEdge(new SimpleEdge(v3, v4, 9.0));
        g.addEdge(new SimpleEdge(v3, v6, 8.0));
        g.addEdge(new SimpleEdge(v4, v6, 20.0));
        g.addEdge(new SimpleEdge(v5, v6, 4.0));

        Dijkstra dijkstra = new Dijkstra();
        double dist = dijkstra.shortestPath(g, v1, v6);

        assert dist == 8.0;
    }
}
