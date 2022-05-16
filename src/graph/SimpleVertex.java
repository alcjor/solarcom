package graph;

import java.util.Objects;

public class SimpleVertex implements Vertex {
    String id;

    public boolean equals(Vertex v) {
        return Objects.equals(this.getId(), v.getId());
    }


    public SimpleVertex(String id) {
        this.id = id;
    }

    public String getId() {
        return id;
    }
}