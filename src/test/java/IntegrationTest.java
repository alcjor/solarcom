package test.java;

import com.github.sh0nk.matplotlib4j.NumpyUtils;
import com.github.sh0nk.matplotlib4j.Plot;
import com.github.sh0nk.matplotlib4j.PythonConfig;
import com.github.sh0nk.matplotlib4j.PythonExecutionException;
import kernelmanager.KernelManager;
import links.ContactPlan;
import links.RadioLink;
import nodes.BodyNode;
import org.junit.Test;
import space.*;
import spice.basic.SpiceException;
import spice.basic.TDBTime;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class IntegrationTest {

    @Test
    public void test() throws SpiceException {


        CommunicationStrategy junocomm = new SpacecraftComm("juno.csv");
        KernelBody juno = new KernelBody("JUNO", "JUNO_SPACECRAFT", false);
        BodyNode junonode = new BodyNode(juno, junocomm);

        CommunicationStrategy dsncomm = new DSNComm("dss43.csv");
        KernelBody dsn = new KernelBody("DSS-43", "DSS-43_TOPO", true);
        BodyNode dsnnode = new BodyNode(dsn, dsncomm);

        KernelManager km = new KernelManager("/home/jordi/SPICE/kernels",
                "/home/jordi/SPICE");

        String[] kernelUrls = {
//                Leap seconds
                "https://naif.jpl.nasa.gov/pub/naif/pds/data/co-s_j_e_v-spice-6-v1.0/cosp_1000/data/lsk/naif0012.tls",
//                Juno ref frame
                "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/fk/juno_v12.tf",
//                Juno spk
                "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/spk/de440s.bsp",
                "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/spk/juno_rec_160522_160729_160909.bsp",
                "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/spk/juno_rec_160729_160923_161027.bsp",
                "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/spk/juno_struct_v04.bsp",
                "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/spk/jup380s.bsp",
                "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/sclk/jno_sclkscet_00128.tsc",

                "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/ck/juno_chua_ali_110825_161019_avg_v01.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/ck/juno_chub_ali_110825_161019_avg_v01.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/ck/juno_chuc_ali_110825_161019_avg_v01.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/ck/juno_chud_ali_110825_161019_avg_v01.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/ck/juno_mobib_ali_110825_161019_avg_v01.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/ck/juno_mobob_ali_110825_161019_avg_v01.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/ck/juno_sc_raw_160705_160705.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/ck/juno_sc_rec_160626_160702_v01.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/ck/juno_sc_rec_160703_160705_v01.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/ck/juno_sc_rec_160705_160709_v01.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/ck/juno_sc_rec_160710_160716_v01.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/ck/juno_sc_rec_160717_160723_v01.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/ck/juno_sc_rec_160724_160730_v01.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/ck/juno_sc_rec_160731_160731_v01.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/ck/juno_sc_rec_160731_160806_v01.bc",
            "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/ck/juno_uvs_rec_121021_160827_v01.bc",
//                DSN
        };
        km.getKernels(kernelUrls);
        km.loadKernel("pck00008.tpc");
        km.loadKernel("stations.bsp");
        km.loadKernel("de421.bsp");
        km.loadKernel("earth_topo_201023.tf");
        km.loadKernel("earth_000101_220717_220423.bpc");
        km.loadKernel("earthstn.bsp");

        RadioLink link = new RadioLink(junonode, dsnnode, 7.15e9, "X");
        SpiceTime.getSpiceTime().setTime(new TDBTime("2016-JUL-5 03:53:00 UTC"));

//DATA FROM 2016-JUL-1 TO 2016-AUG-1
        System.out.println(link.calcDataRate(new TDBTime("2016-JUL-5 03:53:00 UTC")));


        Body[] occulting = {
                new KernelBody("JUPITER", "IAU_JUPITER", false),
                new KernelBody("IO", "IAU_IO", false),
                new KernelBody("EUROPA", "IAU_EUROPA", false),
                new KernelBody("GANYMEDE", "IAU_GANYMEDE", false),
                new KernelBody("CALLISTO", "IAU_CALLISTO", false),
                new KernelBody("EARTH", "IAU_EARTH", false),
                new KernelBody("MOON", "IAU_MOON", false),
        };

        ContactPlan cp = new ContactPlan(link, occulting, new KernelBody("SUN", "IAU_SUN", false));

        System.out.println(cp.calcOccultation());
        System.out.println(cp.calcSolarInterference(5));
        System.out.println(cp.calcOccLgs(5));
        System.out.println(cp.calcVisibility(5,5));


        List<Double> dataRates = new ArrayList<>();
        List<Double> times = new ArrayList<>();

        for (int i=0; i < 40000; ++i) {
            times.add((double) i);
            if (cp.calcVisibility(5,5)) {
                System.out.println("HEEEEEEY");
                dataRates.add(link.calcDataRate(SpiceTime.getSpiceTime().getTime()));
            } else {
                dataRates.add(0.0);
            }
            SpiceTime.getSpiceTime().update(60);
        }
//        System.out.println("Done!");

//        List<Double> x = NumpyUtils.linspace(-3, 3, 100);
//        List<Double> y = x.stream().map(xi -> Math.sin(xi) + Math.random()).collect(Collectors.toList());
////        Plot plt = Plot.create();
        Plot plt = Plot.create(PythonConfig.pythonBinPathConfig("/usr/bin/python3"));
        plt.plot().add(times, dataRates, "o").label("sin");
        plt.legend().loc("upper right");
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
