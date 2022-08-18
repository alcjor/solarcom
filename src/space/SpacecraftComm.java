package space;

import com.google.common.collect.Table;
import input.TableReader;

public class SpacecraftComm implements CommunicationStrategy {

    Table<String, String, Double> params;
    public SpacecraftComm(String params_file) {
        params = TableReader.read(params_file);
    }

    public double get_loss(String band, double freq, Body self, Body other) {
        return params.get("L", band);
    }

    public double get_HPBW(String band, double freq, Body self, Body other) {
        return params.get("HPBW", band);
    }

    public double get_Pt(String band, double freq, Body self, Body other) {
        return params.get("Pt", band);
    }

    public double get_Gt(String band, double freq, Body self, Body other) {
        return params.get("Gt", band);
    }

    public double get_Gr(String band, double freq, Body self, Body other) {
        return params.get("Gr", band);
    }

    public double get_ARt(String band, double freq, Body self, Body other) {
        return params.get("ARt", band);
    }

    public double get_ARr(String band, double freq, Body self, Body other) {
        return params.get("ARr", band);
    }

    public double get_Tamw(String band, double freq, Body self, Body other) {
        return params.get("Tamw", band);
    }

    public double get_SNRmin(String band, double freq, Body self, Body other) {
        return params.get("SNRmin", band);
    }
}
