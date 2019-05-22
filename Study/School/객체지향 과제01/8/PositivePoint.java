import java.nio.file.attribute.PosixFileAttributeView;

class Point {
    private int x, y;
    public Point(int x, int y) { this.x = x; this.y = y; }
    public int getX() { return x; }
    public int getY() { return y; }
    protected void move(int x, int y) { this.x = x; this.y = y; }
}

public class PositivePoint extends Point{
    public PositivePoint(int x, int y) {
        super(0, 0);
        move(x, y);
    }
    public PositivePoint() {
        super(0, 0);
    }
    public void move(int x, int y) {
        if((x<0)||(y<0))
            return;
        else
            super.move(x, y);
    }
    public String toString(){
        return "(" + getX() + "," + getY() + ")의 점";
    }
    public static void main(String[] args) {
        PositivePoint p = new PositivePoint();
        p.move(10, 10);
        System.out.println(p.toString() + "입니다.");

        p.move(-5, 5);
        System.out.println(p.toString() + "입니다.");

        PositivePoint p2 = new PositivePoint(-10, -10);
        System.out.println(p2.toString() + "입니다.");
    }
}

