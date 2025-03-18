package Scope;

public class Scope3_1 {
    public static void main(String[] args) {
        int m =10;
        int temp =0; //이렇게 하면 temp가 if문 이후에도 살아남아 문제: 1.코드복잡도 2.불필요 메모리
        if(m>0){
            temp =m*2;
            System.out.println(temp);

        }
        System.out.println(m);
    }
}
