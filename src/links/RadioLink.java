package links;

import nodes.BodyNode;
import space.CommunicationStrategy;
import spice.basic.SpiceException;
import spice.basic.TDBTime;

public class RadioLink extends Link {

    private double dataRate;
    BodyNode src;
    BodyNode dest;
    String band;
    double freq;

    public RadioLink(BodyNode src, BodyNode dest, double freq, String band) {
        super(src, dest);
        this.src = src;
        this.dest = dest;
        this.band = band;
        this.freq = freq;
    }

    private double calcSpaceLoss(TDBTime time) throws SpiceException {
        double r = src.getBody().distance(dest.getBody()); // change
        return 147.56 - 20*Math.log10(r) - 20*Math.log10(freq);
    }

    private double calcPolarizationLoss() {
        return 0; // TODO
    }
    private double calcHotBodyNoiseTemp() {
        return 0; // TODO
    }

    public double calcDataRate(TDBTime time) throws SpiceException {
        CommunicationStrategy tx = this.src.comm;
        CommunicationStrategy rx = this.dest.comm;

        double EIRP = tx.get_Pt(band, freq, src.getBody(), dest.getBody())
                + tx.get_Gt(band, freq, src.getBody(), dest.getBody());

        System.out.println("OK EIRP: " + EIRP);

        double L = tx.get_loss(band, freq, src.getBody(), dest.getBody())
                + rx.get_loss(band, freq, dest.getBody(), src.getBody());
        L += calcSpaceLoss(time);
        L += calcPolarizationLoss();

        System.out.println("Loss: " + L);

        // change
        double Tsys = tx.get_Tamw(band, freq, src.getBody(), dest.getBody()) +
                rx.get_Tamw(band, freq, dest.getBody(), src.getBody());
        Tsys += calcHotBodyNoiseTemp();

        System.out.println("Tsys: " + Tsys);

        double Gr = rx.get_Gr(band, freq, dest.getBody(), src.getBody());

        System.out.println("OK Gr: " + Gr);

        double SNR = EIRP + Gr + L - Tsys + 228.6;

        System.out.println("SNR: " + SNR);
        double bandwidth = SNR - rx.get_SNRmin(band, freq, dest.getBody(), src.getBody());
        return 4*bandwidth;
    }




}
