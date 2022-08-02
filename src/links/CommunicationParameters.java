package links;

import spice.basic.*;
import sun.jvm.hotspot.gc.shared.Space;

public class CommunicationParameters {

    Body node1;
    Body node2;
    Time time;
    double freq;
    double dist;
    double EIRP;
    double Gr;
    double L;
    double Tsys;

    String node1type;
    String node2type;

    ReferenceFrame node1ref;
    ReferenceFrame node2ref;

    public CommunicationParameters(Body node1, String node1type, ReferenceFrame node1ref, Body node2, String node2type, ReferenceFrame node2ref, double freq) {
        this.node1 = node1;
        this.node2 = node2;
        this.freq = freq;
        this.node1type = node1type;
        this.node2type = node2type;
        this.node1ref = node1ref;
        this.node2ref = node2ref;
    }

    public void update(Time time) throws SpiceException {
        this.time = time;

        AberrationCorrection abcorr = new AberrationCorrection("XLT+S");
        double CD = 0.9;

        // Transmitter parameters
        String band = ITUBand(freq, "receive"); // Are you sure??
        if (node1type == "GROUND_STATION") {
            StateRecord s = new StateRecord(node2, time, node1ref, abcorr, node1);
            double r = s.norm();
            double[] reclat = CSPICE.reclat(s.getPosition().toArray());
            double latB = reclat[2];
            double elev = latB * 180/Math.PI;
            DSNLinkParameters dsnlp = new DSNLinkParameters(node1.getName(), band, "transmit", elev, freq, CD);
            double Lt = 0;
        }


    }


    class SpacecraftLinkParameters {
        double G;
        double AR;
        double HPBW;
        double L;
        double Pt;
        double Tambw;

        public SpacecraftLinkParameters(String sc_id, String sctype, String band, String dir) {
            Tambw = 40;
            double Gt = 0, Lp = 0, Lc = 0;
            double ARt = 0, ARr = 0;
            switch (sc_id) {
                case "JUNO":
                    switch (band) {
                        case "X":
                            Gt = 44.5;
                            Gr = 43;
                            Lp = -0.93;
                            Lc = -0.9;
                            Pt = 44.40 - 30;
                            HPBW = 0.25;
                            AR = 2;
                            break;
                        case "Ka":
                            Gt = 47.5;
                            Gr = 47;
                            Lp = -3.65;
                            Lc = -2.2;
                            Pt = 34 - 30;
                            HPBW = 0.25;
                            AR = 2;
                            break;
                        default:
                            throw new RuntimeException("This spacecraft does not communicate in this band, please choose another one: X or Ka");
                    }
                    switch (dir) {
                        case "transmit":
                            G = Gt;
                            break;
                        case "receive":
                            G = Gr;
                            break;
                    }
                    L = Lc + Lp;
                    break;
                case "MARS RECON ORBITER": case "MRO": case "VCO":
                    switch (band) {
                        case "X":
                            Gt = 46.7;
                            Gr = 45.2;
                            Lp = -0.3;
                            Lc = -0.9;
                            Pt = 10*Math.log10(100);
                            HPBW = 0.69;
                            ARt = 1.1;
                            ARr = 2.2;
                            break;
                        case "Ka":
                            Gt = 56.4;
                            Lp = -5;
                            Lc = -2.2;
                            Pt = 10*Math.log10(35);
                            HPBW = 0.18;
                            ARt = 2.3;
                            break;
                        default:
                            throw new RuntimeException("This spacecraft does not communicate in this band, please choose another one: X or Ka");
                    }
                    switch (dir) {
                        case "transmit":
                            G = Gt;
                            AR = ARt;
                            break;
                        case "receive":
                            if (band == "Ka") {
                                throw new RuntimeException("This spacecraft does not receive in Ka band");
                            }
                            G = Gr;
                            AR = ARr;
                            break;
                    }
                    L = Lp + Lc;
                    break;

                case "MSL":
                    Gt = 25.5;
                    Gr = 20.2;
                    Lp = -1.2;
                    Lc = -0.9;
                    Pt = 10*Math.log10(15);
                    HPBW = 0.69;
                    switch (dir) {
                        case "transmit":
                            G = Gt;
                            AR = 3;
                            break;
                        case "receive":
                            G = Gr;
                            AR = 2.4;
                    }
                    L = Lp + Lc;
                    break;
                default:
                    throw new RuntimeException("This spacecraft has not been implemented");
            }

           if  (sctype == "RELAY") {
               switch (band) {
                   case "S":
                       Gt = 36;
                       Gr = 37;
                       Pt = 37-30;
                       HPBW = 0.9;
                       break;
                   case "X":
                       Gt = 46.7;
                       Gr = 45.2;
                       Pt = 20;
                       HPBW = 0.69;
                       break;
                   case "Ku":
                       Gt = 54;
                       Gr = 54;
                       Pt = 20;
                       HPBW = 0.4;
                       break;
                   case "Ka":
                       Gt = 58.5;
                       Gr = 59;
                       Pt = 10*Math.log10(35);
                       HPBW = 0.18;
                       break;
               }
               switch (dir) {
                   case "transmit":
                       G = Gt;
                       break;
                   case "receive":
                       G = Gr;
               }
               L = -3.2;
               AR = 0;

           }



        }


    }


    class DSNLinkParameters {
        double Pt;
        double AR;
        double HPBW;
        double G;
        double Tsys;

        DSNLinkParameters(String station, String band, String dir) {
//            3 outputs: Pt, AR, HPBW
//TODO
        }
        DSNLinkParameters(String station, String band, String dir, double elev, double freq, double CD) {
//          5 outputs: All
            switch (station) {
                case "DSS-14": case "DSS-43": case "DSS-63":
                    this.Pt = power70(band, station, "off");
                    this.AR = ellipticity70(band, dir);
                    this.HPBW = hpbw70(band);
                    this.G = eff_gain70(band,freq,elev,CD,station,dir);
                    this.Tsys = noise_temperature70(elev,band,CD,station);
                    break;
//                    TODO!!!
                case "DSS-15":
                case "DSS-45":
                case "DSS-65":
                    break;
            }
        }

        private double noise_temperature70(double elev, String band, double CD, String antenna) {
            double T1 = 0, T2 = 0, a = 0;
            switch (band) {
                case "L":
                    T1 = 26.67; T2 = 15.66; a = 0.09;
                    break;
                case "S":
                    switch (antenna) {
                        case "DSS-14":
                            T1 = 23.69; T2 = 4.67; a = 0.05;
                            break;
                        case "DSS-43":
                            T1 = 24.72; T2 = 22.83; a = 0.14;
                            break;
                        case "DSS-63":
                            T1 = 26.82; T2 = 4.88; a = 0.057;
                            break;
                    }
                    break;
                case "X":
                    switch (antenna) {
                        case "DSS-14":
                            T1 = 12.57; T2 = 7.11; a = 0.065;
                        case "DSS-43":
                            T1 = 13.32; T2 = 10.49; a = 0.1;
                        case "DSS-63":
                            T1 = 12.62; T2 = 4.84; a = 0.06;
                    }
                    break;
            }

            double Tamw = T1 + T2*Math.exp(-a*elev);
            double A = atm_attenuation70(band,CD,elev,antenna);
            double L = Math.pow(10,(A/10));
            double Tm = 255 + 25*CD;
            double Tatm = Tm*(1-1/L);
            double Tcmb = 2.725;
            double Tcmb_ = Tcmb/L;
            return Tamw + Tatm + Tcmb_;
        }

        private double eff_gain70(String band, double f, double elev, double cd, String antenna, String dir) {
            double G0 = 0, G1 = 0, gamma = 0, f0 = 0;
            switch (band) {
                case "L":
                    f0 = 1668;
                    switch (dir) {
                        case "transmit":
                            throw new RuntimeException("This band is not used for tranmission");
                            break;
                        case "receive":
                            G0 = 61.04;
                            break;
                        default:
                            throw new RuntimeException("State the direction of the communication, please. It can be either 'transmit' or 'receive'");
                    }
                    G1 = 0.000084;
                    gamma = 45;
                    break;
                case "S":
                    f0 = 2115;
                    switch (dir) {
                        case "transmit":
                            G0 = 62.95;
                            break;
                        case "receive":
                            G0 = 63.59;
                            break;
                        default:
                            throw new RuntimeException("State the direction of the communication, please. It can be either 'transmit' or 'receive'");
                    }
                    G1 = 0.0001;
                    gamma = 37;
                    break;
                case "X":
                    f0 = 7145;
                    switch (antenna) {
                        case "DSS-14":
                            switch (dir) {
                                case "transmit":
                                    G0 = 73.17;
                                    break;
                                case "receive":
                                    G0 = 74.55;
                                    break;
                                default:
                                    throw new RuntimeException("State the direction of the communication, please. It can be either 'transmit' or 'receive'");
                            }
                            G1 = 0.000285;
                            gamma = 38.35;
                            break;
                        case "DSS-43":
                            switch (dir) {
                                case "transmit":
                                    G0 = 73.25;
                                    break;
                                case "receive":
                                    G0 = 74.63;
                                    break;
                                default:
                                    throw new RuntimeException("State the direction of the communication, please. It can be either 'transmit' or 'receive'");
                            }
                            G1 = 0.0003;
                            gamma = 41.53;
                            break;
                        case "DSS-63":
                            switch (dir) {
                                case "transmit":
                                    G0 = 73.28;
                                    break;
                                case "receive":
                                    G0 = 74.66;
                                    break;
                                default:
                                    throw new RuntimeException("State the direction of the communication, please. It can be either 'transmit' or 'receive'");
                            }
                            G1 = 0.00056;
                            gamma = 44.93;
                            break;
                    }
                    break;
                default:
                    throw new RuntimeException("This antenna does not operate in the band");
            }

            double a = atm_attenuation70(band,cd,elev,antenna);
            double G = G0 - G1*Math.pow(elev-gamma,2) - a;

            return G + 20*Math.log10(f/f0);

        }

        private double atm_attenuation70(String band, double CD, double elev, String antenna) {

            double Azen = 0;
            if (band == "L" || band == "S") {
                if (CD == 0 || CD == 0.5) Azen = 0.035;
                else if (CD == 0.9) Azen = 0.036;
                else Azen = 0;
            } else if (band != "X") {
                throw new RuntimeException("Invalid band");
            }

            switch (antenna) {
                case "DSS-14":
                    if (CD == 0) {
                        Azen = 0.037;
                    } else if (CD == 0.5) {
                        Azen = 0.04;
                    } else if (CD == 0.9) {
                        Azen = 0.045;
                    } else Azen = 0;
                    break;
                case "DSS-43":
                    if (CD == 0) Azen = 0.039;
                    if (CD == 0.5) Azen = 0.047;
                    if (CD == 0.9) Azen = 0.057;
                    else Azen = 0;
                    break;
                case "DSS-63":
                    if (CD == 0) Azen = 0.038;
                    if (CD == 0.5) Azen = 0.045;
                    if (CD == 0.9) Azen = 0.058;
                    else Azen = 0;
                    break;
            }
            return Azen/Math.sin(elev*180/Math.PI);
        }

        private double hpbw70(String band) {
            switch (band) {
                case "S":
                    return 0.128;
                case "X":
                    return 0.038;
            }
            throw new RuntimeException("Wrong params");
        }

        private double ellipticity70(String band, String dir) {
            switch (band) {
                case "L":
                    return 2;
                case "S":
                    switch (dir) {
                        case "transmit":
                            return 2.2;
                        case "return":
                            return 0.6;
                    }
                case "X":
                    switch (dir) {
                        case "transmit":
                            return 1;
                        case "return":
                            return 0.8;
                    }
            }
            throw new RuntimeException("Wrong params");
        }

        private double power70(String band, String antenna, String HPM) {

            double power;
            switch (band) {
                case "S":
                    if (HPM == "off") {
                        power = 20e3;
                    } else {
                        if (antenna != "DSS-43")
                            throw new RuntimeException("High Power Mode not available for this antenna");
                        power = 100e3;
                    }
                    break;
                case "X":
                    power = 20e3;
                    break;
                default:
                    throw new RuntimeException("Invalid band");
            }
            return 10*Math.log10(power);
        }

    }




    public void transmitterParameters() {
        String band = ITUBand(this.freq, "receive");

        if (node1type == "GROUND_STATION") {

        }
    }

//    ONLY deep space
    String ITUBand(double f, String dir) {

        switch (dir) {
            case "transmit":
                if (f >= 2110e6 && f <= 2120e6) {
                    return "S";
                } else if (f >= 7145e6 && f <= 7190e6) {
                    return "X";
                } else if (f >= 34200e6 && f <= 34700e6) {
                    return "Ka";
                } else if (f >= 1000e6 && f <= 2000e6) {
                    return "L";
                }
                break;
            case "receive":
                if (f >= 2290e6 && f <= 2300e6) {
                    return "S";
                } else if (f >= 8395e6 && f <= 8450e6) {
                    return "X";
                } else if (f >= 31800e6 && f <= 32300e6) {
                    return "Ka";
                } else if (f >= 1000e6 && f <= 2000e6) {
                    return "L";
                }
                break;
        }
        throw new RuntimeException("No allocation or not supported by the DSN");
    }



}
