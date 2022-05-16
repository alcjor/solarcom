import java.util.Objects;

public class SimpleVertex implements Vertex {
    String id;

    public boolean equals(Vertex v) {
        return Objects.equals(this.get_id(), v.get_id());
    }


    public SimpleVertex(String id) {
        this.id = id;
    }

    public String get_id() {
        return id;
    }
}