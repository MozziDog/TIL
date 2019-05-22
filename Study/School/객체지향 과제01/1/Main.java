class TV
{
    private int size;
    public TV(int size){this.size = size;}
    protected int getSize() {return size;}
}

class ColorTV extends TV
{
    private int color;
    public ColorTV(int size, int color){
        super(size);
        this.color = color;
    }
    protected int getColor() {return color;}
    void printProperty(){
        System.out.println(getSize()+"인치 "+getColor()+"컬러");
    }
}

public class Main {

    public static void main(String[] args) {
        ColorTV myTV = new ColorTV(32, 1024);
        myTV.printProperty();
    }
}
