package test.java;

import com.google.common.collect.HashBasedTable;
import com.google.common.collect.Table;
import com.opencsv.CSVReader;
import com.opencsv.exceptions.CsvException;
import input.TableReader;
import org.junit.Test;

import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.List;

public class GuavaTest {

    @Test
    public void test() {

        Table<String, String, Double> table = HashBasedTable.create();
        table.put("fmin", "L", 1e9);
        table.put("fmax", "L", 2e9);
        table.put("fmin", "S", 2.11e9);
        table.put("fmax", "S", 2.12e9);
        table.put("fmin", "X", 7.15e9);
        table.put("fmax", "X", 7.19e9);
        table.put("fmin", "Ka", 3.42e9);
        table.put("fmax", "Ka", 3.47e9);

        System.out.println(table.row("fmin"));
        System.out.println(table.column("L"));
        System.out.println(table.get("fmin", "L"));
    }

}
