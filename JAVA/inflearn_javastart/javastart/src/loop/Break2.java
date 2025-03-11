package loop;

public class Break2 {
    public static void main(String[] args) {
        int sum =0;
        int i =1;

        for(; ; ){
            sum +=i;
            if (sum>10){
                System.out.println("10보다 크면 종료 합이: i="+i+"sum="+sum);
                break;
            }
            // for(;;)에는 조건식이 없다 : 무한반복인데 안데 break가 있으니까 빠져나간다
            i++;
        }

    }

}
