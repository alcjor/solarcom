package kernelmanager;

import spice.basic.KernelDatabase;

import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.URL;
import java.nio.file.Paths;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class KernelManager {

    static {
        System.loadLibrary("JNISpice");
    }

    String kernelDir;
    String spiceDir;
    Set<String> kernelFiles;
    Set<String> FILE_EXTENSIONS = Set.of(new String[]{"bsp", "tls"});

    public KernelManager(String kernelDir, String spiceDir) {
        this.kernelDir = kernelDir;
        this.spiceDir = spiceDir;
    }

    public boolean kernelExists(String name) {
        Set<String> kernelFiles = Stream.of(new File(this.kernelDir).listFiles())
                .filter(file -> !file.isDirectory())
                .map(File::getName)
                .collect(Collectors.toSet());
        return kernelFiles.contains(name);
    }

    public void loadKernel(String fileName) {
        try {
            String kernelPath = Paths.get(this.kernelDir, fileName).toString();
            KernelDatabase.load(kernelPath);
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    public void downloadKernel(String url) {
        String[] arr = url.split("/");
        String fileName = Paths.get(this.kernelDir, arr[arr.length-1]).toString();
        try (BufferedInputStream in = new BufferedInputStream(new URL(url).openStream());
             FileOutputStream fileOutputStream = new FileOutputStream(fileName)) {
            byte dataBuffer[] = new byte[1024];
            int bytesRead;
            while ((bytesRead = in.read(dataBuffer, 0, 1024)) != -1) {
                fileOutputStream.write(dataBuffer, 0, bytesRead);
            }
        } catch (IOException e) {
            // handle exception
            throw new RuntimeException(e);
        }
    }

    public void getKernels(String[] urls) {
        for (String url: urls) {
            String fileName = url.substring(url.lastIndexOf("/") +1);
            if (!this.kernelExists(fileName)) {
                System.out.println("Downloading kernel " + fileName);
                this.downloadKernel(url);
            }
            System.out.println("Loading kernel " + fileName);
            this.loadKernel(fileName);
        }
    }

}