import java.util.Scanner;

abstract class Shape {
    private Shape next;
    public Shape() { next = null; }
    public void setNext(Shape obj) { next = obj; }
    public Shape getNext() { return next; }
    abstract public void draw();
}

class Line extends Shape {
    public String toString() { return "Line"; }
    public void draw() { System.out.println("Line"); }
}

class Rect extends Shape {
    public void draw() {
        System.out.println("Rect");
    }
}

class Circle extends Shape {
    public void draw() {
        System.out.println("Circle");
    }
}

class GraphicEditor {
    private Shape firstShape;
    void put(int num){
        Shape tmp = firstShape;
        if(firstShape == null)
        {
            switch(num) {
                case 1: firstShape = new Line(); return;
                case 2: firstShape = new Rect(); return;
                case 3: firstShape = new Circle(); return;
            }
        }
        while(true){
            if(tmp.getNext() == null)
                break;
            else
                tmp = tmp.getNext();
        }
        switch(num){
            case 1: tmp.setNext(new Line()); return;
            case 2: tmp.setNext(new Rect()); return;
            case 3: tmp.setNext(new Circle()); return;
        }
    }
    void Delete(int num) {
        Shape tmp1= firstShape;
        if(firstShape == null){
            System.out.println("삭제할 수 없습니다.");
            return;
        }
        Shape tmp2= null;
        int i;
        for(i=0; i<num; i++)
        {
            tmp2 = tmp1;
            if(tmp2 == null) {
                System.out.println("삭제할 수 없습니다.");
                return;
            }
            tmp1= tmp1.getNext();
        }
        if(tmp2 != null)
            tmp2.setNext(tmp1.getNext());
        tmp1 = null; //tmp1 삭제
    }
    void ShowAll() {
        Shape tmp = firstShape;
        while(tmp!=null) {
            tmp.draw();
            tmp = tmp.getNext();
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        GraphicEditor ge = new GraphicEditor();
        System.out.println("그래픽 에디터 beauty을 실행합니다.");
        while(true) {
            System.out.print("삽입(1), 삭제(2), 모두 보기(3), 종료(4)>>");
            switch(scanner.nextInt()){
                case 1:
                    System.out.print("Line(1), Rect(2), Circle(3)>>");
                    ge.put(scanner.nextInt());
                    break;
                case 2:
                    System.out.print("삭제할 도형의 위치>>");
                    ge.Delete(scanner.nextInt());
                    break;
                case 3:
                    ge.ShowAll();
                    break;
                case 4:
                    System.out.println("beauty을 종료합니다.");
                    return;
                default:
                    System.out.println("잘못된 입력입니다. 다시 입력해주세요");
            }
        }


    }
}
