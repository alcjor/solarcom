package test.java;

import id.IDGenerator;
import org.junit.Test;

public class IDGeneratorTest {

    @Test
    public void test() {

        IDGenerator idg = IDGenerator.getInstance();
        System.out.println("ID1: " + idg.getId());
        System.out.println("ID2: " + idg.getId());
        System.out.println("ID3: " + idg.getId());
        System.out.println("ID4: " + idg.getId());
    }

}
