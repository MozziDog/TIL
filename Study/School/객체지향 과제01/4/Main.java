import java.util.Scanner;
abstract class Converter {
    abstract protected double convert(double src);  //추상 메소드
    abstract protected String getSrcString();   //추상 메소드
    abstract protected String getDestString();  //추상 메소드
    protected double ratio; //비율

    public void run() {
        Scanner scanner = new Scanner(System.in);
        System.out.println(getSrcString() + "을 " + getDestString() + "로 바꿉니다.");
        System.out.print(getSrcString() + "을 입력하세요>> ");
        double val = scanner.nextDouble();
        double res = convert(val);
        System.out.println("반환 결과: " + res + getDestString() + "입니다");
        scanner.close();
    }
}

class Km2MIle extends Converter {
    double exchangeRate;
    Km2MIle(double exchangeRate) { this.exchangeRate = exchangeRate; }
    protected static String srcString = "Km";
    protected static String destString = "mile";
    @Override
    protected double convert(double src) { return src / exchangeRate; }
    @Override
    protected String getSrcString() { return srcString; }
    @Override
    protected String getDestString() { return destString; }
}
public class Main {
    public static void main(String[] args) {
        Km2MIle toMile = new Km2MIle(1.6);
        toMile.run();
    }
}
