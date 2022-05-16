package graph;

public interface Edge {
    Vertex getSrc();
    Vertex getDest();
    double getWeight();
    void setWeight(double weight);
}
