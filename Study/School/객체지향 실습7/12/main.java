public class main {

    public static void main(String[] args) {
        int answer = 0;
        for(int i=0; i<args.length; i++) {
            try {
                answer += Integer.parseInt(args[i]);
            } catch (NumberFormatException nfe) {
                //do nothing
            }
        }
        System.out.println(answer);
    }
}
