package test.java;

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

public class ValidationTest {


    @Test
    public void test() throws SpiceException {

        CommunicationStrategy mrocomm = new SpacecraftComm("mro.csv");
        KernelBody mro = new KernelBody("MRO", "MRO_SPACECRAFT", false);
        BodyNode mronode = new BodyNode(mro, mrocomm);

        CommunicationStrategy dsncomm = new DSNComm("dss45.csv");
        KernelBody dsn = new KernelBody("DSS-45", "DSS-45_TOPO", true);
        BodyNode dsnnode = new BodyNode(dsn, dsncomm);

        KernelManager km = new KernelManager("/home/jordi/SPICE/kernels",
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
//        SpiceTime.getSpiceTime().setTime(new TDBTime("2018 JAN 01 00:00:00 UTC")); // Occultation by MARS

        SpiceTime.getSpiceTime().setTime(new TDBTime("2018 JAN 01 00:19:59.999999642 UTC")); // First time with visibility
// DR value: 1.466241347571773e+06

        Body[] occulting = {
                new KernelBody("PHOBOS", "IAU_PHOBOS", false),
                new KernelBody("DEIMOS", "IAU_DEIMOS", false),
                new KernelBody("MOON", "IAU_MOON", false),
                new KernelBody("MARS", "IAU_MARS", false),
        };

        ContactPlan cp = new ContactPlan(link, occulting, new KernelBody("SUN", "IAU_SUN", false));

//        System.out.println(cp.calcOccultation());
//        System.out.println(cp.calcSolarInterference(2.3));
//        System.out.println(cp.calcOccLgs(6));
        System.out.println("Visibility: ");
        System.out.println(cp.calcVisibility(2.3,6));

        System.out.println("DataRate: ");
        System.out.println(link.calcDataRate(SpiceTime.getSpiceTime().getTime()));

    }

}
