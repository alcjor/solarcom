package space;

import com.github.sh0nk.matplotlib4j.Plot;
import com.github.sh0nk.matplotlib4j.PythonConfig;
import com.github.sh0nk.matplotlib4j.PythonExecutionException;
import com.opencsv.CSVWriter;
import graph.Graph;
import graph.JGraphTDijkstra;
import graph.JGraphTGraph;
import kernelmanager.KernelManager;
import links.ContactPlan;
import links.RadioLink;
import nodes.Node;
import links.Link;
import spice.basic.SpiceErrorException;
import spice.basic.SpiceException;
import spice.basic.TDBDuration;
import spice.basic.TDBTime;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class RunCase {

    private Node[] nodes;
    private Link[] links;
    private Body[] occulting;
    private ContactPlan[] contactPlans;
    private TDBTime start_time;
    private TDBTime end_time;
    private TDBDuration step;

    private List<Double> times = new ArrayList<>();
    List<Double> dataRates = new ArrayList<>();
    List<Double> widestDataRates = new ArrayList<>();

    List<String> shortestPath = new ArrayList<>();
    List<String> widestPath = new ArrayList<>();
    private Node transmitter;
    private Node receiver;

    private double Tk = 300;
    private double D = 12757;
    private double angle_solar_interf = 2.3;
    private double angle_occlgs = 6;
    private String pythonPath = "/usr/bin/python3";


    public RunCase() {
        System.out.println("CREATED!!");
    }

//    NOTE: all RadioLinks at the beginning!!!
    public void setLinks(Link[] links, Body[] occulting) {
        this.links = links.clone();
        this.occulting = occulting.clone();

        Body sun;
        try {
            sun = new KernelBody("SUN", "IAU_SUN", false);
        } catch (SpiceException e) {
            throw new RuntimeException(e);
        }

        List<ContactPlan> cps = new ArrayList();
        for (int i = 0; i < links.length; i++) {
            if (links[i].getClass() == RadioLink.class) {
                cps.add(new ContactPlan((RadioLink) links[i], occulting, sun));
            } else {
                break;
            }
        }

        contactPlans = new ContactPlan[cps.size()];
        cps.toArray(contactPlans);

    }

    public void setNodes(Node[] nodes) {
        this.nodes = nodes.clone();
        System.out.println("NODES (" + nodes.length + "):");
        for (Node n: nodes) {
            System.out.println(n.getName());
        }
        System.out.println("NODES SET!!");
    }

    public void setTransmitter(Node node) {
        this.transmitter = node;
    }

    public void setReceiver(Node node) {
        this.receiver = node;
    }

    public void setTime(String start, String end, double step) {
        try {
            this.start_time = new TDBTime(start);
            this.end_time = new TDBTime(end);
            this.step = new TDBDuration(step);
        } catch (SpiceErrorException e) {
            throw new RuntimeException(e);
        }
        System.out.println("TIME SET!!");
    }



    public void run() {

        times.clear();
        dataRates.clear();
        widestDataRates.clear();
        shortestPath.clear();
        widestPath.clear();


        System.out.println("LINKS:");
        for (Link l: links) {
            System.out.println(l.getSrc().getName() + " -> " + l.getDest().getName());
        }


        JGraphTGraph graph = new JGraphTGraph(List.of(nodes), List.of(links));
        saveNodes(graph);
        saveEntriesLinks();

        SpiceTime.getSpiceTime().setTime(start_time);
        double totalTime = 0;
        int numSteps = 0;
        try {
            totalTime = end_time.sub(start_time).getMeasure();
            numSteps = (int) Math.floor(totalTime / step.getMeasure());
        } catch (SpiceException e) {
            throw new RuntimeException(e);
        }

        for (int stepNum = 0; stepNum < numSteps; ++stepNum) {
            try {
                if (!(end_time.getTDBSeconds() >= SpiceTime.getSpiceTime().getTime().getTDBSeconds())) break;
                if (stepNum % 1 == 0) System.out.println("Step: " + stepNum + " of " + numSteps);

                TDBTime time = SpiceTime.getSpiceTime().getTime();
                for (int i = 0; i < contactPlans.length; i++) {

                    double dr = 0;
                    if (contactPlans[i].calcVisibility(angle_solar_interf, angle_occlgs)) {
                        dr = ((RadioLink) links[i]).calcDataRate(time, Tk, D);
                    }
                    links[i].setWeight(1/dr);
                }
//                RUN DIJKSTRA
                graph.updateWeights();
                JGraphTDijkstra dijkstra = new JGraphTDijkstra(graph);
                JGraphTDijkstra.ShortestPath sp = dijkstra.getShortestPath(transmitter, receiver);
                double sd = sp.distance;
//                if (sp.length != 2 && sp.length != 0) {
//                    System.out.println("WARNING: Shortest path length is not 2");
//                }


//                sd = dijkstra.calcShortestDistance(transmitter, receiver);
                saveInstantLinks(graph, sp.sources, sp.destinations, start_time);
                String ssp;
                ssp = "";
                if (sp.length > 0) {
                    for (Node n: sp.sources) {
                        ssp += n.getName() + "/";
                    }
                    ssp += sp.destinations.get(sp.destinations.size()-1).getName();
                }
                shortestPath.add(ssp);

//                Save times and dr, and move to the next step
                times.add(time.getTDBSeconds());
                dataRates.add(1/sd);
                for (Link l: graph.getLinks()) {
                    l.setWeight(1/l.getWeight());
                }
                graph.updateWeights();
                sp = dijkstra.getWidestPath(transmitter, receiver);
                widestDataRates.add(sp.distance);
                ssp = "";
                if (sp.length > 0) {
                    ssp += sp.sources.get(sp.sources.size()-1).getName();
                    for (int i = sp.destinations.size()-1; i >= 0; --i) {
                        ssp = ssp + "/" + sp.destinations.get(i).getName();
                    }
//                    for (Node n: sp.sources) {
//                        ssp += n.getName() + "/";
//                    }
                }
                widestPath.add(ssp);

                SpiceTime.getSpiceTime().setTime(time.add(step));

            } catch (SpiceException e) {
                throw new RuntimeException(e);
            }
        }


    }

    public List<Double> getDataRates() {
        return dataRates;
    }

    public List<Double> getWidestDataRates() {
        return widestDataRates;
    }

    public List<Double> getTimes() {
        return times;
    }

    public void saveInstantLinks(Graph g, List<Node> sp_sources, List<Node> sp_dest, TDBTime start_time) {
        try {
            CSVWriter linksWriter = new CSVWriter(new FileWriter("links.csv", true));
//            String[] linksEntries = {"time_start", "time_end", "Source", "Target"};
//            linksWriter.writeNext(linksEntries);
            List<Link> links = g.getLinks();
            int sp_count = 0;
            for (Link l : links) {
                if (l.getWeight() < Double.POSITIVE_INFINITY) {
                    TDBTime time = SpiceTime.getSpiceTime().getTime();
//                    int seconds = (int) (time.getTDBSeconds() - start_time.getTDBSeconds());
//                    int seconds_end = (int) (seconds+step.getMeasure());
                    boolean in_sp = false;
                    for (int i = 0; i < sp_sources.size(); i++) {
                        if (sp_sources.get(i) == l.getSrc() && sp_dest.get(i) == l.getDest()) {
                            in_sp = true;
                            sp_count++;
                            break;
                        }
                    }

                    linksWriter.writeNext(new String[]{time.toUTCString("ISOC", 9),
                            String.valueOf(l.getSrc().getId()), String.valueOf(l.getDest().getId()),
                            String.valueOf(1/ l.getWeight()), String.valueOf(in_sp)});
                }
            }
            linksWriter.close();
//            if (sp_count != 0 && sp_count != 2) {
//                System.out.println("WARNING! Incorrect shortest path lenght: " + sp_count);
//            }
        } catch (IOException e) {
//        } catch (IOException | SpiceException e) {
            throw new RuntimeException(e);
        } catch (SpiceErrorException e) {
            throw new RuntimeException(e);
        }
    }

    public void saveEntriesLinks() {
        CSVWriter linksWriter = null;
        try {
            linksWriter = new CSVWriter(new FileWriter("links.csv"));
            String[] linksEntries = {"Timeset", "Source", "Target", "DataRate", "InShortestPath"};
            linksWriter.writeNext(linksEntries);
            linksWriter.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }


    public void saveNodes(Graph g) {
        try {
            CSVWriter nodesWriter = new CSVWriter(new FileWriter("nodes.csv"));
            String[] nodesEntries = {"id", "label", "type"};
            nodesWriter.writeNext(nodesEntries);
            List<Node> nodes = g.getNodes();
            for (Node n: nodes) {
                nodesWriter.writeNext(new String[]{String.valueOf(n.getId()), n.getName(), String.valueOf(n.getClass())});
            }
            nodesWriter.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void saveResults(String csvFile) {
        List<String[]> data = new ArrayList<>();
        CSVWriter writer = null;
        try {
            writer = new CSVWriter(new FileWriter(csvFile), CSVWriter.DEFAULT_SEPARATOR,
                    CSVWriter.NO_QUOTE_CHARACTER, CSVWriter.DEFAULT_ESCAPE_CHARACTER,
                    CSVWriter.DEFAULT_LINE_END);
            data.add(new String[]{"Time", "Shortest Path Distance", "Widest Path Distance",
                    "Shortest Path", "Widest Path"});
            for (int i = 0; i < dataRates.size(); i++) {
                data.add(new String[]{times.get(i).toString(), dataRates.get(i).toString(),
                        widestDataRates.get(i).toString(), shortestPath.get(i), widestPath.get(i)});
            }
            writer.writeAll(data);
            writer.close();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
    public void plotResults() {

        List<Double> hours = new ArrayList<>();
        double t0 = times.get(0);
        times.stream().forEach(t -> hours.add((t-t0)/3600));

        List<Double> mbps = new ArrayList<>();
        dataRates.stream().forEach(x -> mbps.add(x/1e6));

        Plot plt = Plot.create(PythonConfig.pythonBinPathConfig(pythonPath));
        plt.plot().add(hours, mbps, "x");
        List<Double> non0mbps = new ArrayList<>();
        mbps.stream().filter(x -> x > 0).forEach(x -> non0mbps.add(x));
        double ymin = Collections.min(non0mbps);
        double ymax = Collections.max(mbps);

        plt.ylim(ymin*0.9,ymax*1.1);
//        plt.plot().
        plt.ylabel("Data rate [Mbps]");
        plt.xlabel("Hours since simulation start");
//        plt.title("Datarate");
        try {
            plt.show();
        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (PythonExecutionException e) {
            throw new RuntimeException(e);
        }
    }

    public void loadKernels(String kernelDir, String[] kernelUrls) {
        KernelManager km = new KernelManager(kernelDir, "");
        km.getKernels(kernelUrls);
    }
}
