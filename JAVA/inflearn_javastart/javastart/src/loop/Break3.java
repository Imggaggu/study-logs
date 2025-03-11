package loop;

public class Break3 {
    public static void main(String[] args) {
        int sum =0;
        int z =10;
        for(int i=1; ;i++ ){
            sum +=i;
            if (sum>10) {
                System.out.println("10보다 크면 종료 합이: i=" + i + "sum=" + sum);
                break;
            }
        }
//for 일 때는 i 재사용 불가 while은 가능
    }

}
