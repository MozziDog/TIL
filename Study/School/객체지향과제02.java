import java.util.Scanner;

class ConcertSeat {
    private Boolean empty;
    private String name;
    ConcertSeat()
    {
        empty = true;
        name = null;
    }

    public Boolean isEmpty()
    {
        return empty;
    }

    public String getName()
    {
        return name;
    }

    public Boolean MakeReservation(String EnteredName)
    {
        if(!isEmpty())
        {
            return false;
        }
        else{
            empty = false;
            name = EnteredName;
            return true;
        }
    }

    public void CancelReservation()
    {
        empty = true;
        name = null;
    }

}

class ConcertHall {
    ConcertSeat[][] seats;

    ConcertHall(int classesInHall, int seatsInClass)
    {
        seats = new ConcertSeat[classesInHall][seatsInClass];
        for(int i=0; i<classesInHall; i++)
        {
            for(int j=0; j<seatsInClass; j++)
            {
                seats[i][j] = new ConcertSeat();
            }
        }
    }

    public void ShowSeats(int classCode){
        switch(classCode)
        {
            case 0:
                System.out.print("S>> ");
                break;
            case 1:
                System.out.print("A>> ");
                break;
            case 2:
                System.out.print("B>> ");
                break;
        }
        for(int i=0; i<seats[classCode].length; i++)
        {
            if(seats[classCode][i].isEmpty())
                System.out.print("--- ");
            else
                System.out.print(seats[classCode][i].getName());
        }
        System.out.println();
        return;
    }

    public Boolean CancelReservation(int classCode, String name)
    {
        for(int i=0; i<seats[classCode].length; i++)
        {
            if(!seats[classCode][i].isEmpty()) {
                if (seats[classCode][i].getName().equals(name)) {
                    seats[classCode][i].CancelReservation();
                    return true;
                }
            }
        }
        return false;
    }

}

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ConcertHall concertHall = new ConcertHall(3, 10);
        System.out.println("명품콘서트홀 예약 시스템입니다.");
        while(true)
        {
            int inputTask, inputClassCode, inputSeatNum;
            String inputName;
            System.out.print("예약:1, 조회:2, 취소:3, 끝내기:4>>");
            inputTask=scanner.nextInt();
            switch (inputTask){
                case 1:
                    System.out.print("좌석구분 S(1), A(2), B(3)>>");
                    inputClassCode=scanner.nextInt()-1;
                    concertHall.ShowSeats(inputClassCode);
                    System.out.print("이름>>");
                    String inputname = scanner.next();
                    System.out.print("번호>>");
                    inputSeatNum = scanner.nextInt()-1;
                    if(concertHall.seats[inputClassCode][inputSeatNum].isEmpty())
                    {
                        concertHall.seats[inputClassCode][inputSeatNum].MakeReservation(inputname);
                    }
                    else{
                        System.out.println("이미 예약된 좌석입니다! 예약에 실패했습니다.");
                    }
                    break;
                case 2:
                    concertHall.ShowSeats(0);
                    concertHall.ShowSeats(1);
                    concertHall.ShowSeats(2);
                    System.out.println("<<<조회를 완료하였습니다>>>");
                    break;
                case 3:
                    System.out.print("좌석구분 S(1), A(2), B(3)>>");
                    inputClassCode=scanner.nextInt()-1;
                    concertHall.ShowSeats(inputClassCode);
                    System.out.print("이름>>");
                    inputName = scanner.next();
                    if(concertHall.CancelReservation(inputClassCode, inputName)==false)
                    {
                        System.out.println("오류가 발생했습니다. 다시 시도해주세요");
                    }
                    break;
                case 4:
                    return;
            }
        }
    }
}

