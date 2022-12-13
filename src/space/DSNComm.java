package space;

import com.google.common.collect.Table;
import input.TableReader;
import spice.basic.CSPICE;
import spice.basic.SpiceErrorException;
import spice.basic.StateRecord;
import spice.basic.TDBTime;

public class DSNComm implements CommunicationStrategy {

    Table<String, String, Double> params;
    public DSNComm(String params_file) {
        params = TableReader.read(params_file);
    }
    public double get_loss(String band, double freq, Body self, Body other) {
        return 0; // Is 0 for DSN antennae
    }

    public double get_HPBW(String band, double freq, Body self, Body other) {
        return params.get("HPBW", band);
    }

    public double get_Pt(String band, double freq, Body self, Body other) {
        return params.get("Pt", band);
    }

    private double calcAtmosphericAttenuation(String band, double CD, double elevation) {
        String Azen = String.format("Azen(CD=%.1f)", CD);
        return params.get(Azen, band) / Math.sin(elevation * Math.PI / 180);
    }

    private double calcAtmosphericAttenuation(String band, double elevation) {
        return params.get("Azen(no CD)", band) / Math.sin(elevation * Math.PI / 180);
    }



    public double get_Gt(String band, double freq, Body self, Body other) {
//        Requires frequency, CD, and elevation

//        TODO: remove!!
//        double freq = 0;
//        double CD = 0;
//        double elevation = 10;
        double CD = 0.9;
        double a;
        double elevation = self.elevation(other, false);
        try {
            CD = this.params.get("CD", band);
            a = calcAtmosphericAttenuation(band, CD, elevation);
        } catch (NullPointerException e) {
            a = calcAtmosphericAttenuation(band, elevation);
        }

        double G = params.get("G0t", band) - Math.pow(params.get("G1", band)
                *(elevation - params.get("gamma", band)),2) - a;

        return G + 20*Math.log10(freq*1e-6/params.get("f0t", band));
    }

    public double get_Gr(String band, double freq, Body self, Body other) {
//        Requires frequency, CD, and elevation

//        TODO: remove!!
//        double freq = 7.15e9;
//        double CD = 0;
//        double elevation = 0;
        double CD;
        double a;
        double elevation = self.elevation(other, false);

        try {
            CD = this.params.get("CD", band);
            a = calcAtmosphericAttenuation(band, CD, elevation);
        } catch (NullPointerException e) {
            a = calcAtmosphericAttenuation(band, elevation);
        }
//                System.out.println("atmos: " + a);
//        System.out.println("elev: " + elevation);
//        System.out.println("dist: " + self.distance(other));

        double G = params.get("G0r", band) -params.get("G1", band)*Math.pow(
                elevation - params.get("gamma", band),2) - a;
//        System.out.println("G pre: " + G);
//        System.out.println("G0r: " + params.get("G0r", band));
//        System.out.println("G1: " + params.get("G1", band));
//        System.out.println("gamma: " + params.get("gamma", band));

        return G + 20*Math.log10(freq*1e-6/params.get("f0r", band));
    }

    public double get_ARt(String band, double freq, Body self, Body other) {
        return params.get("Et", band);
    }

    public double get_ARr(String band, double freq, Body self, Body other) {
        return params.get("Er", band);
    }

    public double get_Tamw(String band, double freq, Body self, Body other) {
        double CD = 0.9;
        double A;
        double elevation = self.elevation(other, false);
        try {
            CD = this.params.get("CD", band);
            A = calcAtmosphericAttenuation(band, CD, elevation);
        } catch (NullPointerException e) {
            A = calcAtmosphericAttenuation(band, elevation);
        }


        double lossFactor = Math.pow(10, A/10);
        double a = params.get("a", band);
        double Tamw = params.get("T1", band) +
                params.get("T2", band) * Math.exp(-a*elevation);

        double Tatm = (255 +25*CD)*(1-1/lossFactor);
        double Tcmb = 2.725/lossFactor;
        return Tamw + Tatm + Tcmb;
    }

    public double get_SNRmin(String band, double freq, Body self, Body other) {
        return params.get("SNRmin", band);
    }

    public double get_Bmax(String band, double freq, Body self, Body other) {
        return params.get("Bmax", band);
    }
}
