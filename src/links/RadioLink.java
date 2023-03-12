package links;

import nodes.BodyNode;
import space.CommunicationStrategy;
import space.KernelBody;
import space.SpiceTime;
import spice.basic.*;

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

        double r;
        try {
            KernelBody sb = (KernelBody) src.getBody();
            KernelBody db = (KernelBody) dest.getBody();
            if (!sb.onSurface) {
                ReferenceFrame J2000 = new ReferenceFrame("J2000");
                AberrationCorrection abcorr = new AberrationCorrection("XLT+S");
                Body earth = new Body("EARTH");
                PositionVector s1 = (new StateRecord(db.body, time, J2000, abcorr, sb.body)).getPosition();
                r = s1.norm();
            } else {
                r = src.getBody().distance(dest.getBody());
            }
        } catch (SpiceException e) {
            throw new RuntimeException(e);
        } catch (Exception e) {
            r = dest.getBody().distance(src.getBody());
        }
        return 147.56 - 20*Math.log10(r*1e3) - 20*Math.log10(freq);
    }

    private double calcPolarizationLoss() {

        double ar = Math.pow(10, dest.comm.get_ARr(band, freq, dest.getBody(), src.getBody())/10);
        double at = Math.pow(10, src.comm.get_ARt(band, freq, src.getBody(), dest.getBody())/10);

        double f1 = (1 + Math.pow(ar,2))*(1 + Math.pow(at,2));
        double f2 = (1 - Math.pow(ar,2))*(1 - Math.pow(at,2));

        double psi = Math.random()*Math.PI/2;
        double Lp = (f1 + 4*ar*at + f2*Math.cos(2*psi)) / (2*f1);

        return 10*Math.log10(Lp);

    }
    private double calcHotBodyNoiseTemp(double Tk, double D) {

        double G = Math.pow(10, src.comm.get_Gt(band,freq,src.getBody(),dest.getBody())/10);
        double dist = src.getBody().distance(dest.getBody());
        try {
            double angle = src.getBody().angularSep(new KernelBody("EARTH", "IAU_EARTH", false), dest.getBody());
            double HPBW = src.comm.get_HPBW(band,freq,src.getBody(), dest.getBody());
            double T;
            T = (Tk*G*Math.pow(D,2))/(16*Math.pow(dist,2));
            T = T*Math.exp(-2.77*Math.pow(angle/HPBW,2));
            return T;
        } catch (SpiceException e) {
            throw new RuntimeException(e);
        }

    }

    public double calcDataRate(TDBTime time, double Tk, double D) throws SpiceException {
        CommunicationStrategy tx = this.src.comm;
        CommunicationStrategy rx = this.dest.comm;

        double EIRP = tx.get_Pt(band, freq, src.getBody(), dest.getBody())
                + tx.get_Gt(band, freq, src.getBody(), dest.getBody());

        double L = tx.get_loss(band, freq, src.getBody(), dest.getBody())
                + rx.get_loss(band, freq, dest.getBody(), src.getBody());

        L += calcSpaceLoss(time);


        // change
        double Tsys = tx.get_Tamw(band, freq, src.getBody(), dest.getBody()) +
                rx.get_Tamw(band, freq, dest.getBody(), src.getBody());


        Tsys += calcHotBodyNoiseTemp(Tk, D);

        Tsys = 10*Math.log10(Tsys);

        double Gr = rx.get_Gr(band, freq, dest.getBody(), src.getBody());


        double SNR = EIRP + L + Gr - Tsys + 228.6;

        double bandwidth = SNR - rx.get_SNRmin(band, freq, dest.getBody(), src.getBody());
        bandwidth = Math.pow(10, bandwidth/10);


        double bmax;
        try { // TODO: remove
            bmax = src.comm.get_Bmax(band, freq, src.getBody(), dest.getBody());
        } catch (NullPointerException e) {
            bmax = Double.POSITIVE_INFINITY;
        }
        double bmax_;
        try {
            bmax_ = dest.comm.get_Bmax(band, freq, dest.getBody(), src.getBody());
        } catch (NullPointerException e) {
            bmax_ = Double.POSITIVE_INFINITY;
        }
        bmax = bmax > bmax_ ? bmax_ : bmax;


        return bandwidth < bmax ?  4*bandwidth : 4*bmax;
    }




}
