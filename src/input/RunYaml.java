package input;

import jdk.jshell.JShell;
import jdk.jshell.JShellException;
import jdk.jshell.SnippetEvent;
import org.yaml.snakeyaml.Yaml;

import java.io.*;
import java.util.*;

public class RunYaml {

    String filePath;
    public Map<String,Object> data;
    public JShell jshell;
    private String[] imports = {
            "import com.github.sh0nk.matplotlib4j.Plot;",
            "import com.github.sh0nk.matplotlib4j.PythonConfig;",
            "import com.github.sh0nk.matplotlib4j.PythonExecutionException;",
            "import com.opencsv.CSVReader;",
            "import com.opencsv.CSVWriter;",
            "import jdk.jshell.JShell;",
            "import kernelmanager.KernelManager;",
            "import links.*;",
            "import nodes.*;",
            "import space.*;",
            "import spice.basic.Duration;",
            "import spice.basic.SpiceException;",
            "import spice.basic.TDBDuration;",
            "import spice.basic.TDBTime;",
            "import java.io.FileNotFoundException;",
            "import java.io.FileReader;",
            "import java.io.FileWriter;",
            "import java.io.IOException;",
            "import java.util.ArrayList;",
            "import java.util.List;",
    };

    public RunYaml(String filePath) {
        this.filePath = filePath;
    }

    public void readFile() {
        InputStream inputStream;
        try {
            File tempFile = File.createTempFile("buffer", ".tmp");
            FileWriter fw = new FileWriter(tempFile);
            Reader fr = new FileReader(filePath);
            BufferedReader br = new BufferedReader(fr);
            while(br.ready()) {
                fw.write(br.readLine().replaceAll("\"", "\\\\\"") + "\n");
            }
            fw.close();
            br.close();
            fr.close();
            tempFile.renameTo(new File("Preproc.yaml"));
            inputStream = new FileInputStream(new File("Preproc.yaml"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Yaml yaml = new Yaml();
        data = yaml.load(inputStream);
    }

    public void initJShell() {
        String cp = System.getProperty("java.class.path");
        String spice_path = (String) data.get("spicePath");
        spice_path = spice_path.substring(2, spice_path.length()-2);
        jshell = JShell.builder().remoteVMOptions("-Djava.library.path=" + spice_path).build();
        jshell.addToClasspath(cp);
        for (String imp: imports) {
            jshell.eval(imp);
        }
    }

    public void createInstance(String type, Map<String, Object> objectMap) {
        String instanceCreation;
        String identifier = (String) objectMap.keySet().toArray()[0];
        Map<String, Object> attributeMap = (Map<String, Object>) objectMap.get(identifier);
        String[] attributeNames = attributeMap.keySet().toArray(new String[0]);
        Object[] attributeValues = new Object[attributeNames.length];
        String attributeString = "";
        for (int i = 0; i < attributeValues.length; i++) {
            attributeValues[i] = attributeMap.get(attributeNames[i]);
            attributeString = attributeString.concat(attributeValues[i] + ",");
        }
        attributeString = attributeString.substring(0, attributeString.length() - 1);
        attributeString = attributeString.replaceAll("\\\\", "");
        instanceCreation = type + " " + identifier +
                " = new " + type + "(" + attributeString + ");";
        jshell.eval(instanceCreation);
    }

    public void createInstances(String type, Map<String, Object> data) {
        List<Object> objects = (List<Object>) data.get(type);
        for (Object obj: objects) {
            createInstance(type, (Map<String, Object>) obj);
        }
    }

    public void run() throws JShellException {
        Set<String> keywords = Set.of("spicePath", "kernelPath", "kernelUrls",
                                "nodes", "links", "startTime", "endTime",
                                "step", "transmitter", "receiver", "occulting",
                                "outputFile");

        String kernelPath = (String) data.get("kernelPath");
        kernelPath = kernelPath.replaceAll("\\\\", "");
        String outputFile = (String) data.get("outputFile");
        outputFile = outputFile.replaceAll("\\\\", "");
        ArrayList<String> kernelList = (ArrayList<String>) data.get("kernelUrls");
        String kernelUrls = kernelList.toString();
        kernelUrls = kernelUrls.substring(1,kernelUrls.length()-1);
        kernelUrls = kernelUrls.replaceAll("\\\\","");
        String startTime = (String) data.get("startTime");
        startTime = startTime.replaceAll("\\\\", "");
        String endTime = (String) data.get("endTime");
        endTime = endTime.replaceAll("\\\\", "");
        String transmitter = (String) data.get("transmitter");
        String receiver = (String) data.get("receiver");
        int step = (int) data.get("step");



        for (String type: data.keySet()) {
            if (keywords.contains(type)) continue;
//            System.out.println(type);
            createInstances(type, data);
        }

        ArrayList<String> occultingList = (ArrayList<String>) data.get("occulting");
        String occulting = occultingList.toString();
        occulting = occulting.substring(1, occulting.length()-1);
        jshell.eval("Body[] occulting = {" + occulting + "};");

//      Nodes
        Map<String, Object> nodeMap = (Map<String, Object>) data.get("nodes");
        String nodes = "";
        for (String type: nodeMap.keySet()) {
            List<Object> objects = (List<Object>) nodeMap.get(type);
            for (Object obj: objects) {
                createInstance(type, (Map<String, Object>) obj);
                String identifier = (String) ((Map<String, Object>) obj).keySet().toArray()[0];
                nodes = nodes.concat(identifier + ",");
            }
        }
        jshell.eval("Node[] nodes = {" + nodes + "};");

//      Links
        Map<String, Object> linkMap = (Map<String, Object>) data.get("links");
        String links = "";
        for (String type: linkMap.keySet()) {
            List<Object> objects = (List<Object>) linkMap.get(type);
            for (Object obj: objects) {
                createInstance(type, (Map<String, Object>) obj);
                String identifier = (String) ((Map<String, Object>) obj).keySet().toArray()[0];
                links = links.concat(identifier + ",");
            }
        }
        jshell.eval("Link[] links = {" + links + "};");

//       Run the code
        jshell.eval("String[] kernelUrls = {" + kernelUrls + "};");
        jshell.eval("RunCase run = new RunCase();");
        jshell.eval("run.loadKernels("+kernelPath+",kernelUrls);");
        jshell.eval("run.setTime(" + startTime + "," + endTime + "," + step + ");");
        jshell.eval("run.setNodes(nodes);");
        jshell.eval("run.setLinks(links, occulting);");
        jshell.eval("run.setTransmitter(" + transmitter + ");");
        jshell.eval("run.setReceiver(" + receiver + ");");
        jshell.eval("run.run();");
        jshell.eval("run.saveResults(" + outputFile + ");");
        jshell.eval("run.plotResults();");
    }






}
