package test.java;

import input.InputReader;
import jdk.jshell.JShell;
import nodes.FictitiousNode;
import org.junit.Test;
import nodes.Node;
import space.Body;
import space.CommunicationStrategy;
import space.KernelBody;
import space.SpacecraftComm;
import spice.basic.SpiceException;

public class InputTest {

    @Test
    public void envVarTest() {
        String user = System.getProperty("SOLARCOM");
        System.out.println("Environment variable is: "  + user);
    }

    @Test
    public void yamlTest() {
        InputReader ir = new InputReader("./provaInput.yaml");
        ir.readFile();
        String[] kernels = ir.getKernels();
//        for (String kernel: kernels) {
//            System.out.println(kernel);
//        }
    }

    @Test
    public void jshellTest() throws SpiceException {
        String cp = System.getProperty("java.class.path");
        JShell jshell = JShell.builder().build();
        jshell.addToClasspath(cp);
        jshell.eval("System.out.println(\"uep!\");");

        Node A = new FictitiousNode("A OUT");
        System.out.println(A.getName());

        jshell.eval("import nodes.Node;");
        jshell.eval("import nodes.FictitiousNode;");
        jshell.eval("Node A = new FictitiousNode(\"A IN\");");
        jshell.eval("System.out.println(A.getName());");

        KernelBody earth = new KernelBody("EARTH","IAU_EARTH", false);
        System.out.println("Earth code OUT: " + earth.body.getName());

        jshell.eval("import space.KernelBody;");
        jshell.eval("KernelBody earth = new KernelBody(\"EARTH\",\"IAU_EARTH\", false);");
        jshell.eval("System.out.println(\"Earth code IN: \" + earth.body.getName());");

        SpacecraftComm comms = new SpacecraftComm("mro.csv");
        System.out.println("Gt OUT: " + comms.get_Gt("X",8.439444445999999e9,null,null));

        jshell.eval("import space.SpacecraftComm;");
        jshell.eval("SpacecraftComm comms = new SpacecraftComm(\"mro.csv\");");
        jshell.eval("System.out.println(\"Gt IN: \" + comms.get_Gt(\"X\",8.439444445999999e9,null,null));\n");


    }
}
