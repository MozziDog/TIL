import java.util.Scanner;
public class Main {
    static String course [] = {"Java", "C++", "HTML5", "컴퓨터구조", "안드로이드"};
    static int score [] = {95,88,76,62,55};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input;
        int i;
        while(true)
        {
            System.out.print("과목 이름>>");
            input= scanner.next();
            if(input.equals("그만"))
            {
                return;
            }
            for(i=0; i<course.length; i++) {
                if (course[i].equals(input)) {
                    System.out.println(course[i] + "의 점수는 " + score[i]);
                    break;
                }
            }
            if(i==course.length)
            {
                System.out.println("없는 과목입니다.");
            }
        }
    }
}
