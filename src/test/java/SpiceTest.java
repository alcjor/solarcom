package src.test.java;

import org.junit.Test;
import spice.basic.KernelDatabase;

public class SpiceTest {

    static {
        System.loadLibrary("JNISpice");
    }

    @Test
    public void loadKernelTest() {
        try {
            KernelDatabase.load("/home/jordi/SPICE/kernels/naif0012.tls");
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
