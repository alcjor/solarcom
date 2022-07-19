package src;
import graph.Dijkstra;
//import graph.Graph;
//import graph.SimpleEdge;
//import graph.SimpleVertex;
import input.InputReader;
import kernelmanager.KernelManager;
import spice.basic.SpiceWindow;
//import spice.*;

import org.yaml.snakeyaml.TypeDescription;
import org.yaml.snakeyaml.Yaml;
import org.yaml.snakeyaml.constructor.Constructor;

import java.io.*;
import java.net.URL;
import java.util.Arrays;
import java.util.Map;


public class Main {

    static {
        System.loadLibrary( "JNISpice" );
    }

    public static void main(String[] args) {

        InputReader ir = new InputReader("/home/jordi/solarcom2/provaInput.yaml");
        ir.readFile();
        String[] kernels = ir.getKernels();

        KernelManager kr = new KernelManager("/home/jordi/SPICE/kernels",
                                                "/home/jordi/SPICE");

        kr.getKernels(kernels);

        

//
//        InputStream inputStream;
//        try {
//            inputStream = new FileInputStream(new File("/home/jordi/solarcom2/prova.yaml"));
////            InputStream inputStream = new FileInputStream(new File("/home/jordi/pene.txt"));
//        } catch (FileNotFoundException e) {
//            throw new RuntimeException(e);
//        }
////
//        Yaml yaml = new Yaml();
//        Map<String, Object> data = yaml.load(inputStream);
//        System.out.println(data);
//
//        String FILE_URL = (String) data.get("url");
//        String[] arr = FILE_URL.split("/");
//        String FILE_NAME = arr[arr.length-1];
//        System.out.println(FILE_NAME);
//        try (BufferedInputStream in = new BufferedInputStream(new URL(FILE_URL).openStream());
//             FileOutputStream fileOutputStream = new FileOutputStream(FILE_NAME)) {
//            byte dataBuffer[] = new byte[1024];
//            int bytesRead;
//            while ((bytesRead = in.read(dataBuffer, 0, 1024)) != -1) {
//                fileOutputStream.write(dataBuffer, 0, bytesRead);
//            }
//        } catch (IOException e) {
//            // handle exception
//        }
//
//        Process process = null;
//        try {
//            process = new ProcessBuilder("echo","hi, Mark").start();
//        } catch (IOException e) {
//            throw new RuntimeException(e);
//        }
//        InputStream is = process.getInputStream();
//        InputStreamReader isr = new InputStreamReader(is);
//        BufferedReader br = new BufferedReader(isr);
//        String line;
//
//        System.out.printf("Output of running %s is:", Arrays.toString(args));
//
//        while (true) {
//            try {
//                if (!((line = br.readLine()) != null)) break;
//            } catch (IOException e) {
//                throw new RuntimeException(e);
//            }
//            System.out.println(line);
//        }
//        System.out.println("Hello, World!");

    }
}
