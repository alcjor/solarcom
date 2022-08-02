package links;

public class OneHopLink {

    double fc;
    double bw;

    class Params {
        double EIRP;
        double GR;
        double L;
        double Tsys;

        double SNRmin;
    }

    public double calcDataRate(String node1type, String node2type, String modc, double freq, Params params) {

        if (node1type == "GROUND_STATION") {
            channelAllocation("DSN", "transmit", freq);
        } else if (node2type == "GROUND_STATION") {
            channelAllocation("DSN", "receive", freq);
        } else {
            bw = Double.POSITIVE_INFINITY;
        }

        double SNR = params.EIRP + params.GR + params.L - params.Tsys + 228.6;
        double B = SNR - params.SNRmin;
        B = Math.pow(10, B/10);
        B = B > bw ? bw : B;

        switch (modc) {
            case "QPSK":
                return 4*B;
            case "BPSK":
                return 2*B;
            default:
                throw new RuntimeException("This modulation is not included in the database, " +
                        "please choose another one (BPSK, QPSK) or update the database");
        }
    }

    public void channelAllocation(String user, String dir) {
//        Remove dir???

        if (user != "RELAY" || user != "SPACECRAFT") {
            throw new RuntimeException("Invalid user!");
        }

        fc  = 32000*1e6;
        bw = 650e6;
    }

    public void channelAllocation(String user, String dir, int channel) {
        if (user != "DSN") {
            throw new RuntimeException("Invalid user!");
        }

        switch (dir) {
            case "transmit":
                switch (channel) {
                    case 32:
                        fc = 7183.118057*1e6;
                        bw = 1.155864999999721*1e6;
                        break;
                    case 6:
                        fc = 7153.065586*1e6;
                        bw = 1.155862999999954*1e6;
                        break;
                }
                break;
            case "receive":
                switch (channel) {
                    case 32:
                        fc  = 8439.444446*1e6;
                        bw = 1.358025499999712e6;
                        break;
                    case 6:
                        fc = 8404.135802*1e6;
                        bw = 1.358022999999775*1e6;
                        break;
                }
                break;
        }

    }

    public void channelAllocation(String user, String dir, double freq) {
        if (user != "DSN") {
            throw new RuntimeException("Invalid user!");
        }

        switch (dir) {
            case "transmit":
                if (freq == 7183.118057*1e6) {
                    fc = 32;
                    bw = 1.155864999999721*1e6;
                } else if (freq == 7153.065586*1e6) {
                    fc = 6;
                    bw = 1.155862999999954*1e6;
                }
                break;
            case "receive":
                if (freq ==  8439.444446*1e6) {
                    fc  = 32;
                    bw = 1.358025499999712e6;
                } else if (freq == 8404.135802*1e6) {
                    fc = 6;
                    bw = 1.358022999999775*1e6;
                }
                break;
        }

    }

}
