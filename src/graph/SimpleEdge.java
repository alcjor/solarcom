package graph;

public class SimpleEdge implements Edge{

    Vertex src;
    Vertex dest;
    double weight;

    public SimpleEdge(Vertex src, Vertex dest, double weight) {
        this.src = src;
        this.dest = dest;
        this.weight = weight;
    }

    @Override
    public Vertex getSrc() {
        return src;
    }

    @Override
    public Vertex getDest() {
        return dest;
    }

    @Override
    public double getWeight() {
        return weight;
    }

    @Override
    public void setWeight(double weight) {
        this.weight = weight;
    }
}
