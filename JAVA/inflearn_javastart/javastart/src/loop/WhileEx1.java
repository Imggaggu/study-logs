package loop;

public class WhileEx1 {
    public static void main(String[] args) {
        int count=1;
        while(count<11){
            System.out.println(count);
            ++count;
        }// scope2강의_ while문의 단점 count 가 계속 살아남을 수밖에 없다.
    }
}
