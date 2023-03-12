package graph;

import links.Link;
import links.RadioLink;
import nodes.Node;
import org.apache.commons.collections.map.HashedMap;
import org.jgrapht.GraphPath;
import org.jgrapht.alg.shortestpath.DijkstraShortestPath;

import java.util.*;

public class JGraphTDijkstra implements Dijkstra {

    public class ShortestPath {
        public List<Node> sources;
        public List<Node> destinations;
        public double distance;
        public int length;

        public ShortestPath(List<Node> sources, List<Node> destinations, double distance, int length) {
            this.sources = sources;
            this.destinations = destinations;
            this.distance = distance;
            this.length = length;
        }
    }


    private class NodeInfo {
        double dist;
        boolean visited;
        Node parent;

        NodeInfo(double dist, boolean visited, Node parent) {
            this.dist = dist;
            this.visited = visited;
            this.parent = parent;
        }
    }

    JGraphTGraph graph;

    public JGraphTDijkstra(JGraphTGraph graph) {
        this.graph = graph;
    }

    public ShortestPath getShortestPath(Node src, Node target) {

        ShortestPath result = new ShortestPath(new ArrayList<>(), new ArrayList<>(), Double.POSITIVE_INFINITY, 0);
        DijkstraShortestPath dijkstraAlg =
                new DijkstraShortestPath<>(graph.getGraph());


        GraphPath shortest_path =  dijkstraAlg.findPathBetween(graph.getGraph(), src, target);

        if (shortest_path != null) {
            List edges = shortest_path.getEdgeList();
            result.length = shortest_path.getLength();
            result.distance = shortest_path.getWeight();
            for (Object e : edges) {
                result.sources.add((Node) graph.getGraph().getEdgeSource(e));
                result.destinations.add((Node) graph.getGraph().getEdgeTarget(e));
            }
        } 
        return result;
    }

    private List<Link> getSortedLinks(Node n) {
        List<Link> myLinks = new ArrayList<>();
        for (Link l: this.graph.links) {
            if (l.getSrc() == n) {
                myLinks.add(l);
            }
        }

        myLinks.sort((l1, l2) -> (int) Math.signum(l2.getWeight() - l1.getWeight()));
        return myLinks;
    }


    private List<Link> getLinks(Node n) {
        List<Link> links = new ArrayList<>();

        for (Link l: this.graph.links) {
            if (l.getSrc() == n) {
                links.add(l);
            }
        }

        return links;
    }
    public ShortestPath getWidestPath(Node src, Node target) {
        ShortestPath result = new ShortestPath(new ArrayList<>(), new ArrayList<>(), 0.0, 0);

        int nnodes = this.graph.nodes.size();
        Map<Node, NodeInfo> nodesInfo = new HashMap<>();

        for (Node n: graph.nodes) {
            nodesInfo.put(n, new NodeInfo(0.0, false, null));
        }

        nodesInfo.get(src).visited = true;

        List<Link> nodeLinks;
        nodeLinks = getLinks(src);
        NodeInfo aux;
        NodeInfo maxInfo = new NodeInfo(0.0, false, null);
        Node maxNode = null;
        for (Link l: nodeLinks) {
            aux = nodesInfo.get(l.getDest());
            aux.dist = l.getWeight();
            aux.parent = src;
            if (aux.dist > maxInfo.dist) {
                maxInfo = aux;
                maxNode = l.getDest();
            }
        }

        int iter = 0;
        boolean allVisited = false;
        NodeInfo foo = new NodeInfo(-42.0, true, null);
        while (!allVisited) {
            iter++;
            assert iter <= nnodes;
            maxInfo = foo;
            for (Node n: graph.getNodes()) {
                aux = nodesInfo.get(n);
                if (!aux.visited && aux.dist > maxInfo.dist) {
                    maxInfo = aux;
                    maxNode = n;
                }
            }
            if (maxInfo.dist == -42.0) {
                System.out.println("Can't reach destination");
                return result;
            }
            maxInfo.visited = true;

            nodeLinks = getLinks(maxNode);
            for (Link l: nodeLinks) {
                aux = nodesInfo.get(l.getDest());
                if (Math.min(maxInfo.dist, l.getWeight()) > aux.dist) {
                    aux.dist = Math.min(maxInfo.dist, l.getWeight());
                    aux.parent = maxNode;
                }
            }

            allVisited = true;
            for (NodeInfo ni: nodesInfo.values()) {
                allVisited = allVisited && ni.visited;
            }
        }


        aux = nodesInfo.get(target);
        if (aux.parent == null) {
            return result;
        }

        result.distance = aux.dist;
        Node auxNode = target;
        while (auxNode != src) {
            result.destinations.add(auxNode);
            result.sources.add(aux.parent);
            result.length += 1;
            auxNode = aux.parent;
            aux = nodesInfo.get(auxNode);
        }

        return result;
    }

    public double calcShortestDistance(Node src, Node target) {
        DijkstraShortestPath dijkstraAlg =
                new DijkstraShortestPath<>(graph.getGraph());
        GraphPath shortest_path =  dijkstraAlg.findPathBetween(graph.getGraph(), src, target);

        if (shortest_path == null) {
            return Double.POSITIVE_INFINITY;
        }
        return shortest_path.getWeight();
    }
}
