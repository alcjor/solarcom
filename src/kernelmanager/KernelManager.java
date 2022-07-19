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




// optional argument for scanKernelDir: createInfoFile, bool, default is true
//    public void scanKernelDir() {
////        Set kernel list to empty
//        this.kernelFiles = Stream.of(new File(this.kernelDir).listFiles())
//                .filter(file -> !file.isDirectory())
//                .map(File::getName)
//                .filter(f -> FILE_EXTENSIONS.contains(f.substring(f.lastIndexOf(".") + 1)))
//                .collect(Collectors.toSet());
//
////        If non existent, create info dir
//        String infoPath = Paths.get(this.kernelDir, "info").toString();
//        File infoFolder = new File(infoPath);
//        infoFolder.mkdir();
//
//        Set<String> kernelNames = kernelFiles.stream().map(f -> f.substring(0, f.lastIndexOf(".")))
//                .collect(Collectors.toSet());
//
//        Set<String> existingKernelInfos = Stream.of(new File(infoPath).listFiles())
//                .filter(file -> !file.isDirectory())
//                .map(File::getName)
//                .map(f -> f.substring(0, f.lastIndexOf(".")))
//                .collect(Collectors.toSet());
////
//        Set<String> missingKernelInfos = kernelNames.stream()
//                .filter(f -> !existingKernelInfos.contains(f))
//                .collect(Collectors.toSet());
//
//        missingKernelInfos.forEach(f -> {
////            Create info xml file
//        });
//
////        kernelInfos.stream().map(f -> {
////            String a = f + ".xml";
////            System.out.println(a);
////            return a;
////        });
//
////        For every file:
//        for (String kernel: missingKernelInfos) {
////            String extension = kernel.substring(kernel.lastIndexOf(".") + 1);
//            System.out.println(kernel);
//        }
//
////              Check if the extension is valid, otherwise ignore
////              Add it to the kernel manager list
////              If xml info file does not exist, create it
//    }