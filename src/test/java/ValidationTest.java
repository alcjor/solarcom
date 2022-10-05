package test.java;

import com.github.sh0nk.matplotlib4j.Plot;
import com.github.sh0nk.matplotlib4j.PythonConfig;
import com.github.sh0nk.matplotlib4j.PythonExecutionException;
import com.opencsv.CSVReader;
import com.opencsv.CSVWriter;
import input.InputYaml;
import input.RunYaml;
import jdk.jshell.JShell;
import jdk.jshell.JShellException;
import jdk.jshell.SnippetEvent;
import kernelmanager.KernelManager;
import links.ContactPlan;
import links.FictitiousLink;
import links.RadioLink;
import nodes.BodyNode;
import nodes.FictitiousNode;
import org.junit.Test;
import org.yaml.snakeyaml.Yaml;
import space.*;
import spice.basic.Duration;
import spice.basic.SpiceException;
import spice.basic.TDBDuration;
import spice.basic.TDBTime;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import nodes.Node;
import links.Link;

public class ValidationTest {


    String[] kernelUrls = {
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/co-s_j_e_v-spice-6-v1.0/cosp_1000/data/lsk/naif0012.tls",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ck/mro_crm_psp_180101_180131.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ck/mro_hga_psp_171226_180101.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ck/mro_hga_psp_180102_180108.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ck/mro_hga_psp_180109_180115.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ck/mro_hga_psp_180116_180122.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ck/mro_mcs_psp_180101_180131.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ck/mro_sa_psp_171226_180101.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ck/mro_sa_psp_180102_180108.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ck/mro_sa_psp_180109_180115.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ck/mro_sa_psp_180116_180122.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ck/mro_sc_psp_171226_180101.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ck/mro_sc_psp_180102_180108.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ck/mro_sc_psp_180109_180115.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ck/mro_sc_psp_180116_180122.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/fk/mro_v16.tf",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ik/mro_crism_v10.ti",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ik/mro_ctx_v11.ti",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ik/mro_hirise_v12.ti",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ik/mro_marci_v10.ti",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ik/mro_mcs_v10.ti",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/ik/mro_onc_v10.ti",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/lsk/naif0012.tls",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/pck/pck00008.tpc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/sclk/mro_sclkscet_00095_65536.tsc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/de421.bsp",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mar097.bsp",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp46.bsp",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp46_ssd_mro95a.bsp",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_struct_v10.bsp",
            "https://naif.jpl.nasa.gov/pck00008.tpc",
            "https://naif.jpl.nasa.gov/stations.bsp",
            "https://naif.jpl.nasa.gov/de421.bsp",
            "https://naif.jpl.nasa.gov/earth_topo_201023.tf",
            "https://naif.jpl.nasa.gov/earth_000101_220717_220423.bpc",
            "https://naif.jpl.nasa.gov/earthstn.bsp",
    };

    String[] imports = {
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

    @Test
    public void yamlTest() throws JShellException  {
        RunYaml runYaml = new RunYaml("network.yaml");
        runYaml.readFile();
        runYaml.initJShell();
        runYaml.run();
        runYaml.jshell.eval("System.out.println(\"First occulting:\");");
        runYaml.jshell.eval("System.out.println(occulting[0].getName());");
    }

    @Test
    public void yamlTestOld() throws JShellException {

        InputStream inputStream;
        try {
            File tempFile = File.createTempFile("buffer", ".tmp");
            FileWriter fw = new FileWriter(tempFile);
            Reader fr = new FileReader("testCase.yaml");
            BufferedReader br = new BufferedReader(fr);
            while(br.ready()) {
                fw.write(br.readLine().replaceAll("\"", "\\\\\"") + "\n");
            }
            fw.close();
            br.close();
            fr.close();
            tempFile.renameTo(new File("/home/jordi/solarcom2/testCasePreproc.yaml"));
            inputStream = new FileInputStream(new File("testCasePreproc.yaml"));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        Yaml yaml = new Yaml();
        Map<String,Object> data = yaml.load(inputStream);
//        List<Object> kernelBodies = (List<Object>) data.get("KernelBody");
//        System.out.println(data.keySet());
//        Map<String,Object> mro = (Map<String, Object>) kernelBodies.get(0);
//        mro = (Map<String, Object>) mro.get("mro");
//        System.out.println(mro);

        String cp = System.getProperty("java.class.path");
        JShell jshell = JShell.builder().remoteVMOptions("-Djava.library.path=/home/jordi/SPICE/JNISpice/lib").build();
        jshell.addToClasspath(cp);
        for (String imp: imports) {
            jshell.eval(imp);
        }

        String instanceCreation = "";
        for (String type: data.keySet()) {
            List<Object> objects = (List<Object>) data.get(type);
            for (Object obj: objects) {
                Map<String, Object> objectMap = (Map<String, Object>) obj;
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
//                System.out.println(attributeString);
                System.out.println(instanceCreation);
                instanceCreation = type + " " + identifier +
                        " = new " + type + "(" + attributeString + ");";
                jshell.eval(instanceCreation);
            }
        }
        System.out.println(instanceCreation);
        jshell.eval("System.out.println(\"Hi I'm SOURCE:\");");
        jshell.eval("System.out.println(mylink.getSrc().getName());");

    }

    @Test
    public void onlyNodesTest() throws SpiceException, JShellException {
        String cp = System.getProperty("java.class.path");
        JShell jshell = JShell.builder().remoteVMOptions("-Djava.library.path=/home/jordi/SPICE/JNISpice/lib").build();
        jshell.addToClasspath(cp);
        for (String imp: imports) {
            jshell.eval(imp);
        }

        jshell.eval("System.out.println(FictitiousNode.class);");
        jshell.eval("FictitiousNode Anode = new FictitiousNode(\"A\");");
        jshell.eval("System.out.println(\"Hi I'm Anode:\");\n");
        jshell.eval("System.out.println(Anode.getName());");

        CommunicationStrategy mrocomm = new SpacecraftComm("mro.csv");
        KernelBody mro = new KernelBody("MRO", "MRO_SPACECRAFT", false);
        BodyNode mronode = new BodyNode(mro, mrocomm);
        System.out.println("OOUT name: " + mronode.getName());

        jshell.eval("KernelBody mro = new KernelBody(\"MRO\", \"MRO_SPACECRAFT\", false);");
        jshell.eval("System.out.println(\"First BODY is: \");\n" +
                "        System.out.println(mro.getName());");
        jshell.eval("CommunicationStrategy mrocomm = new SpacecraftComm(\"mro.csv\");");
        jshell.eval("System.out.println(\"Gt from mro is: \");\n" +
                "        System.out.println(mrocomm.get_Gt(\"X\",8.439444445999999e9,null,null));");
        jshell.eval("System.out.println(BodyNode.class);");
        List<SnippetEvent> whatDaHeck = jshell.eval("BodyNode mronode = new BodyNode(mro, mrocomm);");
        if (whatDaHeck.get(0).exception() != null)
            throw whatDaHeck.get(0).exception();
        jshell.eval("FictitiousNode Bnode = new FictitiousNode(\"Bb\");");
        jshell.eval("System.out.println(mronode.getName());");
        jshell.eval("System.out.println(Bnode.getName());");

//        jshell.eval("System.out.println(\"IIIIN name: \");");
//        jshell.eval("System.out.println(\"Hi I'm Bnode:\");\n");


    }

    @Test
    public void jshellTest() throws JShellException {
        String cp = System.getProperty("java.class.path");
        JShell jshell = JShell.builder().remoteVMOptions("-Djava.library.path=/home/jordi/SPICE/JNISpice/lib").build();
        jshell.addToClasspath(cp);

//        Load imports
        for (String imp: imports) {
            jshell.eval(imp);
        }

//      Instantiate anything
        jshell.eval("KernelBody mro = new KernelBody(\"MRO\", \"MRO_SPACECRAFT\", false);");
        jshell.eval("KernelBody dsn = new KernelBody(\"DSS-45\", \"DSS-45_TOPO\", true);");

        jshell.eval("Body[] occulting = {\n" +
                "                new KernelBody(\"PHOBOS\", \"IAU_PHOBOS\", false),\n" +
                "                new KernelBody(\"DEIMOS\", \"IAU_DEIMOS\", false),\n" +
                "                new KernelBody(\"MOON\", \"IAU_MOON\", false),\n" +
                "                new KernelBody(\"MARS\", \"IAU_MARS\", false),\n" +
                "        };");


        jshell.eval("CommunicationStrategy mrocomm = new SpacecraftComm(\"mro.csv\");");
        jshell.eval("CommunicationStrategy dsncomm = new DSNComm(\"dss45.csv\");");

//      Create nodes
        jshell.eval("BodyNode mronode = new BodyNode(mro, mrocomm);");
        jshell.eval("BodyNode dsnnode = new BodyNode(dsn, dsncomm);");
        jshell.eval("Node[] nodes = {mronode, dsnnode};");

//      Create links
        jshell.eval("RadioLink link = new RadioLink(mronode, dsnnode, 8.439444445999999e9, \"X\");");
        jshell.eval("Link[] links = {link};");

//      Run the case
//        List<SnippetEvent> whatDaHeck =
        jshell.eval("RunCase run = new RunCase();");
       jshell.eval("System.out.println(\"HEEEY\");\n");
       jshell.eval("run.setNodes(nodes);");
       jshell.eval("run.setLinks(links, occulting);");
       jshell.eval("run.setTransmitter(mronode);");
       jshell.eval("String[] kernelUrls = new String["+kernelUrls.length+"];");
        for (int i = 0; i < kernelUrls.length; i++) {
            jshell.eval("kernelUrls[" + i + "] = \"" + kernelUrls[i] + "\";");
        }
        jshell.eval("run.loadKernels(\"/mnt/c/Users/jordi/Documents/SpiceKernels\", kernelUrls);");
      jshell.eval(          "        run.setNodes(nodes);\n" +
                "        run.setLinks(links, occulting);\n" +
                "        run.setTransmitter(mronode);\n" +
                "        run.setReceiver(dsnnode);\n" +
                "        run.loadKernels(\"/mnt/c/Users/jordi/Documents/SpiceKernels\", kernelUrls);\n" +
                "        run.setTime(\"2018 JAN 01 15:00:00 UTC\",\"2018 JAN 02 6:00:00 UTC\", 60);\n" +
                "        run.run();\n" +
                "        System.out.println(run.getDataRates());\n" +
                "        run.plotResults();");



    }

    @Test
    public void runTest() throws SpiceException {
        CommunicationStrategy mrocomm = new SpacecraftComm("mro.csv");
        KernelBody mro = new KernelBody("MRO", "MRO_SPACECRAFT", false);
        BodyNode mronode = new BodyNode(mro, mrocomm);

        CommunicationStrategy dsncomm = new DSNComm("dss45.csv");

        KernelBody canberra = new KernelBody("DSS-45", "DSS-45_TOPO", true);
        KernelBody madrid = new KernelBody("DSS-63", "DSS-63_TOPO", true);
        KernelBody goldstone = new KernelBody("DSS-26", "DSS-26_TOPO", true);

        BodyNode goldstoneNode = new BodyNode(goldstone, dsncomm);
        BodyNode madridNode = new BodyNode(madrid, dsncomm);
        BodyNode canberraNode = new BodyNode(canberra, dsncomm);

        FictitiousNode dsnNode = new FictitiousNode("DSN");

        Node[] nodes = {mronode, goldstoneNode, madridNode, canberraNode, dsnNode};

        RadioLink goldstoneMRO = new RadioLink(mronode, goldstoneNode, 8.439444445999999e9, "X");
        RadioLink madridMRO = new RadioLink(mronode, madridNode, 8.439444445999999e9, "X");
        RadioLink canberraMRO = new RadioLink(mronode, canberraNode, 8.439444445999999e9, "X");

        FictitiousLink goldstoneDSN = new FictitiousLink(goldstoneNode, dsnNode, 0);
        FictitiousLink madridDSN = new FictitiousLink(madridNode, dsnNode, 0);
        FictitiousLink canberraDSN = new FictitiousLink(canberraNode, dsnNode, 0);

        Link[] links = {goldstoneMRO,madridMRO,canberraMRO,
                        goldstoneDSN,madridDSN,canberraDSN};

        Body[] occulting = {
                new KernelBody("PHOBOS", "IAU_PHOBOS", false),
                new KernelBody("DEIMOS", "IAU_DEIMOS", false),
                new KernelBody("MOON", "IAU_MOON", false),
                new KernelBody("MARS", "IAU_MARS", false),
        };

        RunCase run = new RunCase();
        run.setNodes(nodes);
        run.setLinks(links, occulting);
        run.setTransmitter(mronode);
        run.setReceiver(dsnNode);
        run.loadKernels("/mnt/c/Users/jordi/Documents/SpiceKernels", kernelUrls);
        run.setTime("2018 JAN 01 15:00:00 UTC","2018 JAN 05 15:00:00 UTC", 60);
        run.run();
        run.plotResults();
    }


    @Test
    public void libraryTest() throws SpiceException {

        CommunicationStrategy mrocomm = new SpacecraftComm("mro.csv");
        KernelBody mro = new KernelBody("MRO", "MRO_SPACECRAFT", false);
        BodyNode mronode = new BodyNode(mro, mrocomm);

        CommunicationStrategy dsncomm = new DSNComm("dss45.csv");
        KernelBody dsn = new KernelBody("DSS-45", "DSS-45_TOPO", true);
        BodyNode dsnnode = new BodyNode(dsn, dsncomm);

        KernelManager km = new KernelManager("/mnt/c/Users/jordi/Documents/SpiceKernels",
            "/home/jordi/SPICE");

        km.getKernels(kernelUrls);
        km.loadKernel("pck00008.tpc");
        km.loadKernel("stations.bsp");
        km.loadKernel("de421.bsp");
        km.loadKernel("earth_topo_201023.tf");
        km.loadKernel("earth_000101_220717_220423.bpc");
        km.loadKernel("earthstn.bsp");

        RadioLink link = new RadioLink(mronode, dsnnode, 8.439444445999999e9, "X");
        SpiceTime.getSpiceTime().setTime(new TDBTime("2018 JAN 01 00:00:00 UTC")); // Occultation by MARS

//        SpiceTime.getSpiceTime().setTime(new TDBTime("2018 JAN 01 00:19:59.9999996423721 UTC")); // First time with visibility
// DR value: 1.466241347571773e+06

        Body[] occulting = {
                new KernelBody("PHOBOS", "IAU_PHOBOS", false),
                new KernelBody("DEIMOS", "IAU_DEIMOS", false),
                new KernelBody("MOON", "IAU_MOON", false),
                new KernelBody("MARS", "IAU_MARS", false),
        };

        ContactPlan cp = new ContactPlan(link, occulting, new KernelBody("SUN", "IAU_SUN", false));

//        double dr = link.calcDataRate(SpiceTime.getSpiceTime().getTime());
//        System.out.println(dr);

//        TDBTime start = new TDBTime("2018 JAN 01 21:58:50 UTC");
        TDBTime start = new TDBTime("2018 JAN 01 15:00:00 UTC");
        TDBTime end = new TDBTime("2018 JAN 02 6:00:00 UTC");

//        TDBTime start = new TDBTime("2018 JAN 01 08:20:00 UTC");
//        TDBTime end = new TDBTime("2018 JAN 01 00:50:00 UTC");
        SpiceTime.getSpiceTime().setTime(start);
        Duration step = new TDBDuration(60);
        List<Double> times = new ArrayList<>();
        List<Double> datarates = new ArrayList<>();

        while (end.getTDBSeconds() >= SpiceTime.getSpiceTime().getTime().getTDBSeconds()) {
            double dr = 0;
//            System.out.println("Visibility: ");

            if (cp.calcVisibility(2.3,6))
//            System.out.println("DataRate: ");
                dr = link.calcDataRate(SpiceTime.getSpiceTime().getTime(), 300, 12757);
//            System.out.println(dr);

            times.add(SpiceTime.getSpiceTime().getTime().getTDBSeconds());
            datarates.add(dr);

            SpiceTime.getSpiceTime().setTime(SpiceTime.getSpiceTime().getTime().add(step));
//            break;
        }

        System.out.println(datarates.get(0));

        try {
            System.out.println("WRITING CSV");
            List<String[]> data = new ArrayList<>();
            CSVWriter writer = new CSVWriter(new FileWriter("/mnt/c/Users/jordi/Desktop/solarCom_code/result_java.csv"),
                    CSVWriter.DEFAULT_SEPARATOR, CSVWriter.NO_QUOTE_CHARACTER, CSVWriter.DEFAULT_ESCAPE_CHARACTER,
                    CSVWriter.DEFAULT_LINE_END);
            for (int i = 0; i < datarates.size(); i++) {
                data.add(new String[]{times.get(i).toString(), datarates.get(i).toString()});
            }
            writer.writeAll(data);
            writer.close();
            System.out.println("WROTE CSV");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        Plot plt = Plot.create(PythonConfig.pythonBinPathConfig("/usr/bin/python3"));
        plt.plot().add(times, datarates, "x");
//        plt.legend().loc("upper right");
        plt.title("scatter");
        try {
            plt.show();
        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (PythonExecutionException e) {
            throw new RuntimeException(e);
        }


    }

}
