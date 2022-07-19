package test.java;

import kernelmanager.KernelManager;
import org.junit.Test;
import space.SpiceBodie;
import spice.basic.SpiceException;

public class SpaceTest {
    static {
        System.loadLibrary("JNISpice");
    }

    @Test
    public void spiceBodyTest() throws SpiceException {
//        KernelDatabase.load ( "naif0007.tls" );

        KernelManager km = new KernelManager("/home/jordi/SPICE/kernels", "/home/jordi/SPICE/JNISpice");

        km.loadKernel("de421.bsp");
        km.loadKernel("naif0012.tls");

        SpiceBodie sb = new SpiceBodie("MOON");
        sb.calcPos();
    }
}
