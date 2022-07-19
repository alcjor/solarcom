package test.java;

import input.InputReader;
import org.junit.Test;

public class InputTest {

    @Test
    public void test() {
        InputReader ir = new InputReader("./provaInput.yaml");
        ir.readFile();
        String[] kernels = ir.getKernels();
//        for (String kernel: kernels) {
//            System.out.println(kernel);
//        }
    }
}
