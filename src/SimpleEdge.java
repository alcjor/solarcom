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
    public Vertex get_src() {
        return src;
    }

    @Override
    public Vertex get_dest() {
        return dest;
    }

    @Override
    public double get_weight() {
        return weight;
    }

    @Override
    public void set_weight(double weight) {
        this.weight = weight;
    }
}
