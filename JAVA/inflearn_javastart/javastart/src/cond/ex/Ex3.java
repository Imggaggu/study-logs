package cond.ex;

public class Ex3 {
    public static void main(String[] args) {
        int dollar=13;

        int won;

        if (dollar<0){
            System.out.println("잘못된 금액입니다.");
        }else if (dollar==0){
            System.out.println("환전할 금액이 없습니다");
        }else{
            won=dollar*1300;
            System.out.println(won+"원으로 환전가능합니다.");
        }
    }
}
