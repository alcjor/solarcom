package src;
import graph.Dijkstra;
//import graph.Graph;
//import graph.SimpleEdge;
//import graph.SimpleVertex;
import input.InputReader;
import input.RunYaml;
import jdk.jshell.JShellException;
import kernelmanager.KernelManager;
import spice.basic.SpiceWindow;
//import spice.*;

import org.yaml.snakeyaml.TypeDescription;
import org.yaml.snakeyaml.Yaml;
import org.yaml.snakeyaml.constructor.Constructor;

import java.io.*;
import java.net.URISyntaxException;
import java.net.URL;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Map;

import nodes.Node;
import links.Link;

public class Main {
    public static void main(String[] args) throws JShellException {

        RunYaml runYaml = new RunYaml(args[0]);
        runYaml.readFile();
        runYaml.initJShell();
        runYaml.run();
    }
}
