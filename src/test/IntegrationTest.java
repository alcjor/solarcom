package test;

import kernelmanager.KernelManager;
import links.RadioLink;
import nodes.BodyNode;
import org.junit.Test;
import space.*;
import spice.basic.SpiceException;
import spice.basic.TDBTime;

public class IntegrationTest {

    @Test
    public void test() throws SpiceException {


        CommunicationStrategy junocomm = new SpacecraftComm("juno.csv");
        KernelBody juno = new KernelBody("JUNO", "JUNO_SPACECRAFT");
        BodyNode junonode = new BodyNode(juno, junocomm);

        CommunicationStrategy dsncomm = new DSNComm("dss43.csv");
        KernelBody dsn = new KernelBody("DSS-43", "DSS-43_TOPO");
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
                "https://naif.jpl.nasa.gov/pub/naif/pds/data/jno-j_e_ss-spice-6-v1.0/jnosp_1000/data/spk/jup380s.bsp"
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


        System.out.println(link.calcDataRate(new TDBTime("2016-JUL-5 03:53:00 UTC")));

//        Body[] occultingBodies = {
//                new KernelBody("JUPITER", null),
//                new KernelBody("IO", null),
//                new KernelBody("EUROPA",null),
//                new KernelBody("GANYMEDE", null),
//                new KernelBody("CALLISTO", null),
//                new KernelBody("MOON", null),
//        };

//        ContactPlan cp = new ContactPlan(occultingBodies);









    }
}
