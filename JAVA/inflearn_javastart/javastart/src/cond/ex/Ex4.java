package cond.ex;

public class Ex4 {
    public static void main(String[] args) {
        String grade="ㄹ";
        switch(grade){
            case "A":
                System.out.println("좋은 성과");
                break;
            case "B":
                System.out.println("ㄱㅊ");
                break;
            case "C":
                System.out.println("불합");
                break;
            default:
                System.out.println("학점이 아님");
        }

    }
}
