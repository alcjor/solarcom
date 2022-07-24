package test.java;

import kernelmanager.KernelManager;
import links.ContactPlan;
import org.junit.Test;
import spice.basic.Body;
import spice.basic.ReferenceFrame;
import spice.basic.SpiceException;
import spice.basic.TDBTime;

public class SpaceTest {
    static {
        System.loadLibrary("JNISpice");
    }

    @Test
    public void spiceBodyTest() throws SpiceException {
        KernelManager km = new KernelManager("/home/jordi/SPICE/kernels", "/home/jordi/SPICE");
        km.loadKernel("naif0012.tls");
        km.loadKernel("mar063.bsp");
        km.loadKernel("mro_psp30.bsp");
        km.loadKernel("pck00008.tpc");
        km.loadKernel("stations.bsp");
        km.loadKernel("de421.bsp");


        Body front             = new Body ( "MOON"   );
        Body back             = new Body ( "MARS"    );


        Body obsr            = new Body ( "EARTH" );

        ReferenceFrame frameBack  = new ReferenceFrame( "IAU_MARS"    );
        ReferenceFrame frameFront  = new ReferenceFrame( "IAU_MOON" );

        TDBTime et = new TDBTime( "2014-JAN-2 1:15:00 UTC" );

        ContactPlan cp = new ContactPlan(new Body[]{front});

        boolean occult = cp.calcOccultation(front, frameFront, back, frameBack, obsr, et);
        assert occult == false;

    }

    @Test
    public void solarInterferenceTest() throws SpiceException {
        KernelManager km = new KernelManager("/home/jordi/SPICE/kernels", "/home/jordi/SPICE");
        km.loadKernel("naif0012.tls");
        km.loadKernel("mar063.bsp");
        km.loadKernel("mro_psp30.bsp");
        km.loadKernel("pck00008.tpc");
        km.loadKernel("stations.bsp");
        km.loadKernel("de421.bsp");

        ContactPlan cp = new ContactPlan(new Body[]{});

        boolean solarInterf = cp.calcSolarInterference(
                new Body("MOON"),
                new Body("EARTH"),
                5,
                new TDBTime("2014-JAN-2 1:15:00 UTC")
        );

        assert solarInterf == false;
    }

    @Test
    public void occLgsTest() throws SpiceException {
        KernelManager km = new KernelManager("/home/jordi/SPICE/kernels", "/home/jordi/SPICE");
        km.loadKernel("naif0012.tls");
        km.loadKernel("mar063.bsp");
        km.loadKernel("mro_psp30.bsp");
        km.loadKernel("pck00008.tpc");
        km.loadKernel("stations.bsp");
        km.loadKernel("de421.bsp");
        km.loadKernel("earth_topo_201023.tf");
        km.loadKernel("earth_000101_220717_220423.bpc");
        km.loadKernel("earthstn.bsp");

        ContactPlan cp = new ContactPlan(new Body[]{});
        boolean occ1 = cp.calcOccLgs(
                new Body("DSS-45"), new ReferenceFrame("DSS-45_TOPO"), "GROUND_STATION",
                new Body("MRO"), new ReferenceFrame("MRO_SPACECRAFT"), "SATELLITE",
                6, new TDBTime("2014-JAN-2 1:15:00 UTC")
        );

        assert occ1 == false;

        boolean occ2 = cp.calcOccLgs(
                new Body("DSS-45"), new ReferenceFrame("DSS-45_TOPO"), "GROUND_STATION",
                new Body("DSS-15"), new ReferenceFrame("DSS-15_TOPO"), "GROUND_STATION",
                6, new TDBTime("2014-JAN-2 1:15:00 UTC")
        );

        assert occ2 == true;
    }

}
