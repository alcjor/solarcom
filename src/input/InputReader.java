package input;

import org.yaml.snakeyaml.TypeDescription;
import org.yaml.snakeyaml.Yaml;
import org.yaml.snakeyaml.constructor.Constructor;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.util.Map;

public class InputReader {

    String filePath;
    public InputYaml data;

    public InputReader(String filePath) {
        this.filePath = filePath;
    }

    public void readFile() {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream(new File(this.filePath));
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
        Constructor constructor = new Constructor(InputYaml.class);
        TypeDescription InfoDescription = new TypeDescription(InputYaml.class);
        constructor.addTypeDescription(InfoDescription);
        Yaml yaml = new Yaml(constructor);
        this.data = yaml.load(inputStream);
    }

    public String[] getKernels() {
        return this.data.getKernels();
    }

}
