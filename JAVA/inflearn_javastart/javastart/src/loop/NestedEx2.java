package loop;

public class NestedEx2 {
    public static void main(String[] args) {
        int rows=4;

        for(int i=1;i<=rows;i++){
            int j=1;
            while(j<=i){
                System.out.print("*");
                j++;
            }
            System.out.println();
        }
    }
}
