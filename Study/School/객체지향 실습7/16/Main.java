import java.util.Scanner;
public class Main {
    private static String str[]={"가위", "바위", "보"};
    public static void main(String[] args) {
        String input;
        int playersAnswer=0, comsAnswer;
        Scanner scanner = new Scanner(System.in);
        System.out.println("컴퓨터와 가위 바위 보 게임을 합니다");
        while(true)
        {
            System.out.print("가위 바위 보!>>");
            input = scanner.next();
            if(input.equals("그만"))
            {
                System.out.println("게임을 종료합니다...");
                return;
            }
            int i;
            for(i=0; i<str.length; i++)
            {
                if(str[i].equals(input))
                {
                    playersAnswer=i;
                    break;
                }
            }
            if(i==str.length)
            {
                playersAnswer=3;
            }
            comsAnswer=(int)(Math.random()*3);
            if(playersAnswer==3)
            {
                System.out.println("가위, 바위, 보 중에서 하나를 입력해주세요.");
            }
            else {
                System.out.print("사용자 = " + str[playersAnswer] + " , 컴퓨터 = " + str[comsAnswer] + ", ");
                if ((playersAnswer - comsAnswer== 1)||(playersAnswer - comsAnswer == -2)) {
                    System.out.println("사용자가 이겼습니다.");
                }
                else if (playersAnswer - comsAnswer == 0) {
                    System.out.println("비겼습니다.");
                }
                else if ((playersAnswer - comsAnswer == 2)||(playersAnswer - comsAnswer == -1)) {
                    System.out.println("사용자가 졌습니다");
                }
            }
        }
    }
}
