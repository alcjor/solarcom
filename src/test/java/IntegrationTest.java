package test.java;

import com.github.sh0nk.matplotlib4j.Plot;
import com.github.sh0nk.matplotlib4j.PythonConfig;
import com.github.sh0nk.matplotlib4j.PythonExecutionException;
import com.github.sh0nk.matplotlib4j.builder.PlotBuilder;
import kernelmanager.KernelManager;
import links.ContactPlan;
import links.RadioLink;
import nodes.BodyNode;
import org.junit.Test;
import space.*;
import space.Body;
import spice.basic.*;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class IntegrationTest {

    static {
        System.loadLibrary("JNISpice");
    }

    String[] kernelList = {
        "https://naif.jpl.nasa.gov/pub/naif/CASSINI/kernels/lsk/naif0012.tls",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/stations/earthstns_fx_201023.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/stations/earthstns_itrf93_201023.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/stations/ndosl_140530_v01.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/satellites/mar097.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/stations/ndosl_190716_v01.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/pck/earth_000101_230211_221118.bpc",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/pck/earth_720101_070426.bpc",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/pck/earth_200101_990628_predict.bpc",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/stations/a_old_versions/earthstn.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/stations/a_old_versions/stations.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/fk/stations/earth_topo_201023.tf",
        "http://naif.jpl.nasa.gov/pub/naif/generic_kernels/fk/satellites/moon_assoc_pa.tf",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/pck/earth_latest_high_prec.bpc",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/pck/earth_fixed.tf",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/de421.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mar063.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/pck/pck00008.tpc",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/sclk/mro_sclkscet_00094_65536.tsc",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mar063.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp14.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp14_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp15.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp15_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp16.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp16_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp17.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp17_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp18.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp18_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp19.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp19_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp20.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp20_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp21.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp21_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp22.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp22_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp23.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp23_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp24.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp24_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp25.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp25_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp26.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp26_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp27.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp27_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp28.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp28_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp29.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp29_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp30.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp30_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp31.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp31_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp32.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp32_ssd_mro110c.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp33.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp33_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp34.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp34_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp35.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp35_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp36.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp36_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp37.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp37_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp38.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp38_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp39.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp39_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp40.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp40_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp41.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp41_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp42.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp42_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp43.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp43_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp44.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp44_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp45.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp45_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp46.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp46_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp47.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp47_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp48.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp48_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp49.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp49_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp50.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp50_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp51.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp51_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp52.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp52_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp53.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp53_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_struct_v10.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp54.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp54_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp55.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp55_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp56.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_psp56_ssd_mro95a.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/pds/data/mro-m-spice-6-v1.0/mrosp_1000/data/spk/mro_struct_v10.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/lagrange_point/L1_de431.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/lagrange_point/L2_de431.bsp",
        "https://L3_de431.bsp",
        "https://N4_S1.bsp",
        "https://N4_S2.bsp",
        "https://N4_S3.bsp",
        "https://N4_S4.bsp",
        "https://N3_S1.bsp",
        "https://N3_S2.bsp",
        "https://N3_S3.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/lagrange_point/L4_de431.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/lagrange_point/L5_de431.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/stations/earthstns_itrf93_050714.bsp",
        "https://naif.jpl.nasa.gov/pub/naif/generic_kernels/spk/planets/de430.bsp",
    };

    String kernelDir = "/mnt/c/Users/jordi/Documents/SpiceKernels";

    @Test
    public void occultationTest() throws SpiceErrorException {
        KernelManager km = new KernelManager(kernelDir, "");
        km.getKernels(kernelList);

        double[] aux = CSPICE.gfoclt("ANY", "MARS", "ELLIPSOID", "IAU_MARS",
                "393", "POINT", " ", "XLT+S", "MRO", 1,
                1, new double[] {5.468688691854798e8, 5.468688691854798e8});

        for (double a: aux) {
            System.out.println("Num: " + a);
        }

    }

    @Test
    public void testLinks() throws SpiceException, PythonExecutionException, IOException {

        KernelManager km = new KernelManager(kernelDir, "");
        km.getKernels(kernelList);

        KernelBody mro = new KernelBody("MRO", "MRO_SPACECRAFT", false);
        KernelBody relay393 = new KernelBody("393", "UNDEF", false);
        KernelBody relay394 = new KernelBody("394", "UNDEF", false);
        KernelBody relay395 = new KernelBody("395", "UNDEF", false);
        KernelBody relay1041 = new KernelBody("1041", "UNDEF", false);
        KernelBody dss15 = new KernelBody("DSS-15", "DSS-15_TOPO", true);
        KernelBody dss45 = new KernelBody("DSS-45", "DSS-45_TOPO", true);
        KernelBody dss65 = new KernelBody("DSS-65", "DSS-65_TOPO", true);

//        Occulting
        KernelBody mars = new KernelBody("MARS", "IAU_MARS", false);
        KernelBody phobos = new KernelBody("PHOBOS", "IAU_PHOBOS", false);
        KernelBody deimos = new KernelBody("DEIMOS", "IAU_DEIMOS", false);
        Body[] occulting = {mars, phobos, deimos};

//      Comm Strategy
        CommunicationStrategy mrocomm = new SpacecraftComm("mro.csv");
        CommunicationStrategy relaycomm = new SpacecraftComm("relay.csv");
        CommunicationStrategy dss15comm = new DSNComm("dss15.csv");
        CommunicationStrategy dss45comm = new DSNComm("dss45.csv");
        CommunicationStrategy dss65comm = new DSNComm("dss65.csv");

//      Nodes
        BodyNode mronode = new BodyNode(mro, mrocomm);
        BodyNode relay393node = new BodyNode(relay393, relaycomm);
        BodyNode relay394node = new BodyNode(relay394, relaycomm);
        BodyNode relay395node = new BodyNode(relay395, relaycomm);
        BodyNode relay1041node = new BodyNode(relay1041, relaycomm);
        BodyNode dss15node = new BodyNode(dss15, dss15comm);
        BodyNode dss45node = new BodyNode(dss45, dss45comm);
        BodyNode dss65node = new BodyNode(dss65, dss65comm);

//      Links
        RadioLink mro393 = new RadioLink(mronode, relay393node, 32e9, "Ka");
        RadioLink mro394 = new RadioLink(mronode, relay394node, 32e9, "Ka");
        RadioLink mro395 = new RadioLink(mronode, relay395node, 32e9, "Ka");


        RadioLink mro1041 = new RadioLink(mronode, relay1041node, 32e9, "Ka");

        RadioLink mrodsn15 = new RadioLink(mronode, dss15node, 8.439444445999999e9, "X");
        RadioLink mrodsn45 = new RadioLink(mronode, dss45node, 8.439444445999999e9, "X");
        RadioLink mrodsn65 = new RadioLink(mronode, dss65node, 8.439444445999999e9, "X");

        RadioLink r393dsn15 = new RadioLink(relay393node, dss15node, 8.439444445999999e9, "X");
        RadioLink r393dsn45 = new RadioLink(relay393node, dss45node, 8.439444445999999e9, "X");
        RadioLink r393dsn65 = new RadioLink(relay393node, dss65node, 8.439444445999999e9, "X");

        RadioLink r394dsn15 = new RadioLink(relay394node, dss15node, 8.439444445999999e9, "X");
        RadioLink r394dsn45 = new RadioLink(relay394node, dss45node, 8.439444445999999e9, "X");
        RadioLink r394dsn65 = new RadioLink(relay394node, dss65node, 8.439444445999999e9, "X");

        RadioLink r395dsn15 = new RadioLink(relay395node, dss15node, 8.439444445999999e9, "X");
        RadioLink r395dsn45 = new RadioLink(relay395node, dss45node, 8.439444445999999e9, "X");
        RadioLink r395dsn65 = new RadioLink(relay395node, dss65node, 8.439444445999999e9, "X");

        RadioLink r1041dsn45 = new RadioLink(relay1041node, dss45node, 8.439444445999999e9, "X");

        RadioLink r393r394 = new RadioLink(relay393node, relay394node, 32e9, "Ka"); // These two are inverted in plot
        RadioLink r393r395 = new RadioLink(relay393node, relay395node, 32e9, "Ka");

        RadioLink r394r393 = new RadioLink(relay394node, relay393node, 32e9, "Ka");
        RadioLink r394r395 = new RadioLink(relay394node, relay395node, 32e9, "Ka");

        RadioLink r395r393 = new RadioLink(relay395node, relay393node, 32e9, "Ka");
        RadioLink r395r394 = new RadioLink(relay395node, relay394node, 32e9, "Ka");




//        RadioLink[] links = { r393r394
//                r393r394, r393r395,
//                r394r393, r394r395,
//                r395r393, r395r394,
//        };
//        int num_pairs = 0;

        RadioLink[] links = {
            r1041dsn45
        };

        TDBTime start_time = new TDBTime("2018 OCT 23 20:30:00.0024849176407");
        TDBTime end_time = new TDBTime("2018 OCT 23 21:30:00.0024849176407");
        SpiceTime.getSpiceTime().setTime(start_time);

        TDBDuration step = new TDBDuration(5*60);

        double Tk = 300;
        double D = 12757;
        double angle_solar_interf = 2.3;
        double angle_occlgs = 6;
        String pythonPath = "/usr/bin/python3";

        KernelBody sun = new KernelBody("SUN", "IAU_SUN", false);

//        ContactPlans
        List<ContactPlan> cps = new ArrayList();
        for (RadioLink l: links) {
            cps.add(new ContactPlan(l, occulting, sun));
        }

        List<List<Double>> dataRates = new ArrayList<>();
        for (int i = 0; i < links.length; i++) {
            dataRates.add(new ArrayList<>());
        }

        List<Double> times = new ArrayList<>();
        while (end_time.getTDBSeconds() >= SpiceTime.getSpiceTime().getTime().getTDBSeconds()) {
            TDBTime time = SpiceTime.getSpiceTime().getTime();
            for (int i = 0; i < cps.size(); i++) {

                double dr = 0;
                if (cps.get(i).calcVisibility(angle_solar_interf, angle_occlgs)) {
                    dr = links[i].calcDataRate(time, Tk, D);
                }
                dataRates.get(i).add(dr * 1e-6);
            }

            times.add(time.getTDBSeconds());
            SpiceTime.getSpiceTime().setTime(time.add(step));
        }

        List<Double> hours = new ArrayList<>();
        double t0 = times.get(0);
        times.stream().forEach(t -> hours.add((t-t0)/3600));

//        List<Double> mbps = new ArrayList<>();
//        dataRates.stream().forEach(x -> mbps.add(x/1e6));

        Plot plt = Plot.create(PythonConfig.pythonBinPathConfig(pythonPath));
        PlotBuilder plb = plt.plot();
//        for (int j = 0; j < num_pairs; j++) {
//            List<Double> diff = new ArrayList<>();
//            for (int i = 0; i < hours.size(); i++) {
//                diff.add(dataRates.get(2*j+1).get(i)-dataRates.get(2*j).get(i));
//            }
//            plb.add(hours, diff, "x");
//        }

        List<String> labels = new ArrayList<>();
        for (int i = 0; i < links.length; i++) {
            String label = links[i].getSrc().getName() + "/" + links[i].getDest().getName();
            labels.add(label);
            plb.add(hours, dataRates.get(i), "x").label(label+" " +i);
        }

//        plt.plot()
//        plt.plot().add(hours, mbps, "x");

//        List<Double> non0mbps = new ArrayList<>();
//        mbps.stream().filter(x -> x > 0).forEach(x -> non0mbps.add(x));
//        double ymin = Collections.min(non0mbps);
//        double ymax = Collections.max(mbps);

//        plt.ylim(ymin*0.9,ymax*1.1);
//        plt.plot().
        plt.legend().loc("upper right");
        plt.ylabel("Data rate [Mbps]");
        plt.xlabel("Hours since simulation start");
        plt.show();
//        System.out.println("Labels:");
//        for (String label: labels) {
//            System.out.println(label);
//        }
    }


    @Test
    public void test() throws SpiceException {


        CommunicationStrategy junocomm = new SpacecraftComm("juno.csv");
        KernelBody juno = new KernelBody("JUNO", "JUNO_SPACECRAFT", false);
        BodyNode junonode = new BodyNode(juno, junocomm);

        CommunicationStrategy dsncomm = new DSNComm("dss45.csv");
        KernelBody dsn = new KernelBody("DSS-45", "DSS-45_TOPO", true);
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
        System.out.println(link.calcDataRate(new TDBTime("2016-JUL-5 03:53:00 UTC"),0,0));


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
                dataRates.add(link.calcDataRate(SpiceTime.getSpiceTime().getTime(),0,0));
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
