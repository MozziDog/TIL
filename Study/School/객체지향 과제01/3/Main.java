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

class Won2Dollar extends Converter {
    double exchangeRate;
    Won2Dollar(double exchangeRate) { this.exchangeRate = exchangeRate; }
    protected static String srcString = "원";
    protected static String destString = "달러";
    @Override
    protected double convert(double src) { return src / exchangeRate; }
    @Override
    protected String getSrcString() { return srcString; }
    @Override
    protected String getDestString() { return destString; }
}
public class Main {
    public static void main(String[] args) {
        Won2Dollar toDollar = new Won2Dollar(1200);
        toDollar.run();
    }
}
