package space;

public interface CommunicationStrategy {

    public double get_loss(String band, double freq, Body self, Body other);
    public double get_HPBW(String band, double freq, Body self, Body other);
    public double get_Pt(String band, double freq, Body self, Body other);
    public double get_Gt(String band, double freq, Body self, Body other);
    public double get_Gr(String band, double freq, Body self, Body other);
    public double get_ARt(String band, double freq, Body self, Body other);
    public double get_ARr(String band, double freq, Body self, Body other);
    public double get_Tamw(String band, double freq, Body self, Body other);
    public double get_SNRmin(String band, double freq, Body self, Body other);

}

