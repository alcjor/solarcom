package src;
import input.RunYaml;
import jdk.jshell.JShellException;


public class Main {
    public static void main(String[] args) throws JShellException {

        RunYaml runYaml = new RunYaml(args[0]);
        runYaml.readFile();
        runYaml.initJShell();
        runYaml.run();
    }
}
