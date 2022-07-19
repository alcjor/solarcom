package test.java;
import kernelmanager.KernelManager;
import org.junit.Test;
import spice.basic.KernelDatabase;
import spice.basic.SpiceErrorException;
import spice.basic.SpiceKernelNotLoadedException;

public class KernelManagerTest {

    static {
        System.loadLibrary("JNISpice");
    }

    @Test
    public void test() {

        KernelManager km = new KernelManager("/home/jordi/SPICE/kernels",
                                                "/home/jordi/SPICE");

        String[] kernelUrls = {
                "https://naif.jpl.nasa.gov/pub/naif/pds/data/co-s_j_e_v-spice-6-v1.0/cosp_1000/data/lsk/naif0009.tls",
                "https://naif.jpl.nasa.gov/pub/naif/pds/data/co-s_j_e_v-spice-6-v1.0/cosp_1000/data/lsk/naif0009.tls"
        };
        km.getKernels(kernelUrls);

    }
}
