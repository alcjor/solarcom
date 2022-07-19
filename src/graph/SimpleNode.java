package graph;

import nodes.Node;

import java.util.Objects;

public class SimpleNode extends Node {
    public boolean equals(Node v) {
        return Objects.equals(this.getId(), v.getId());
    }


    public SimpleNode(int id) {
//        this.id = id;
        this.name = "";
    }

}