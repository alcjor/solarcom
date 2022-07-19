package src.test.java;

import org.junit.Test;
import spice.basic.*;

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

    @Test
    public void timeWindowTest() throws SpiceErrorException {

        KernelDatabase.load("/home/jordi/SPICE/kernels/naif0012.tls");

        String tw1 = "2018 JAN 01 00:00:00";
        String tw2 = "2018 JAN 15 00:00:00";
        int step = 60;

        TDBTime t1 = new TDBTime(tw1);
        TDBTime t2 = new TDBTime(tw2);

        SpiceWindow sw = new SpiceWindow(new double[]{t1.getTDBSeconds(), t2.getTDBSeconds()});



    }
}
