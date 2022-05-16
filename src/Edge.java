public interface Edge {
    Vertex get_src();
    Vertex get_dest();
    double get_weight();
    void set_weight(double weight);
}
