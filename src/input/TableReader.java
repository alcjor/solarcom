package input;

import com.google.common.collect.HashBasedTable;
import com.google.common.collect.Table;
import com.opencsv.CSVReader;
import com.opencsv.exceptions.CsvException;

import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.List;

public class TableReader {

    public static Table read(String fileName) {
        try (CSVReader reader = new CSVReader(new FileReader(fileName))) {
            List<String[]> dataRows = reader.readAll();
            String[] columns = dataRows.get(0);

            Table<String, String, Double> table = HashBasedTable.create();
            dataRows.subList(1,dataRows.size()).forEach(row -> {
                String param = row[0];
                for (int i = 1; i < row.length; i++) {
                    if (!row[i].isEmpty()) {
                        table.put(param, columns[i], Double.valueOf(row[i]));
                    }
                }
            });
            return table;

        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (CsvException e) {
            throw new RuntimeException(e);
        }
    }

}
