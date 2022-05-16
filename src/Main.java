
public class Main {

    public static void main(String[] args) {

        SimpleVertex v1 = new SimpleVertex("A");
        SimpleVertex v2 = new SimpleVertex("B");
        SimpleVertex v3 = new SimpleVertex("C");
        SimpleVertex v4 = new SimpleVertex("D");
        SimpleVertex v5 = new SimpleVertex("E");
        SimpleVertex v6 = new SimpleVertex("F");

        Graph g = new Graph();

        g.add_vertex(v1);
        g.add_vertex(v2);
        g.add_vertex(v3);
        g.add_vertex(v4);
        g.add_vertex(v5);
        g.add_vertex(v6);

        g.add_edge(new SimpleEdge(v1, v2, 1.0));
        g.add_edge(new SimpleEdge(v1, v3, 2.0));
        g.add_edge(new SimpleEdge(v1, v4, 8.0));
        g.add_edge(new SimpleEdge(v2, v5, 3.0));
        g.add_edge(new SimpleEdge(v3, v5, 3.0));
        g.add_edge(new SimpleEdge(v3, v4, 9.0));
        g.add_edge(new SimpleEdge(v3, v6, 8.0));
        g.add_edge(new SimpleEdge(v4, v6, 20.0));
        g.add_edge(new SimpleEdge(v5, v6, 4.0));

        Dijkstra dijkstra = new Dijkstra();
        double dist = dijkstra.shortest_path(g, v1, v6);

        System.out.println("Finished!! dist: " + dist);

    }
}
