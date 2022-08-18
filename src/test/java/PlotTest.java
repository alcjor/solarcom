package test.java;

import com.github.sh0nk.matplotlib4j.NumpyUtils;
import com.github.sh0nk.matplotlib4j.Plot;
import com.github.sh0nk.matplotlib4j.PythonConfig;
import com.github.sh0nk.matplotlib4j.PythonExecutionException;
import org.junit.Test;

import java.io.IOException;
import java.util.List;
import java.util.stream.Collectors;

public class PlotTest {

    @Test
    public void test() throws PythonExecutionException, IOException {
        List<Double> x = NumpyUtils.linspace(-3, 3, 100);
        List<Double> y = x.stream().map(xi -> Math.sin(xi) + Math.random()).collect(Collectors.toList());
//        Plot plt = Plot.create();
        Plot plt = Plot.create(PythonConfig.pythonBinPathConfig("/usr/bin/python3"));
        plt.plot().add(x, y, "o").label("sin");
        plt.legend().loc("upper right");
        plt.title("scatter");
        plt.show();
    }

}
