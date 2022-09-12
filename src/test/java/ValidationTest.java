package test.java;

import com.github.sh0nk.matplotlib4j.Plot;
import com.github.sh0nk.matplotlib4j.PythonConfig;
import com.github.sh0nk.matplotlib4j.PythonExecutionException;
import com.opencsv.CSVReader;
import com.opencsv.CSVWriter;
import kernelmanager.KernelManager;
import links.ContactPlan;
import links.RadioLink;
import nodes.BodyNode;
import org.junit.Test;
import space.*;
import spice.basic.Duration;
import spice.basic.SpiceException;
import spice.basic.TDBDuration;
import spice.basic.TDBTime;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ValidationTest {


    @Test
    public void test() throws SpiceException {

        CommunicationStrategy mrocomm = new SpacecraftComm("mro.csv");
        KernelBody mro = new KernelBody("MRO", "MRO_SPACECRAFT", false);
        BodyNode mronode = new BodyNode(mro, mrocomm);

        CommunicationStrategy dsncomm = new DSNComm("dss45.csv");
        KernelBody dsn = new KernelBody("DSS-45", "DSS-45_TOPO", true);
        BodyNode dsnnode = new BodyNode(dsn, dsncomm);

        KernelManager km = new KernelManager("/mnt/c/Users/jordi/Documents/SpiceKernels",
            "/home/jordi/SPICE");


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
        };
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
        TDBTime start = new TDBTime("2018 JAN 02 00:00:00 UTC");
        TDBTime end = new TDBTime("2018 JAN 15 00:00:00 UTC");

//        TDBTime start = new TDBTime("2018 JAN 01 08:20:00 UTC");
//        TDBTime end = new TDBTime("2018 JAN 01 00:50:00 UTC");
        SpiceTime.getSpiceTime().setTime(start);
        Duration step = new TDBDuration(60);
        List<Double> times = new ArrayList<>();
        List<Double> datarates = new ArrayList<>();

        while (end.getTDBSeconds() >= SpiceTime.getSpiceTime().getTime().getTDBSeconds()) {
            double dr = 0;
//            System.out.println("Visibility: ");

//            System.out.println(cp.calcVisibility(2.3,6));
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
            CSVWriter writer = new CSVWriter(new FileWriter("/mnt/c/Users/jordi/Desktop/solarCom_code/result_java.csv"));
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
