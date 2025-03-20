package casting;

public class Casting1 {
    public static void main(String[] args) {
        int intValue = 10;
        long longValue;
        double doubleValue;

        longValue = intValue; //int -> long
        System.out.println("longValue:"+longValue);

        doubleValue = intValue; //int -> double
        System.out.println("doubleValue:"+doubleValue);

        doubleValue = 20L; //long -> double
        System.out.println("doubleValue2:"+doubleValue);
    }
}

//doublevalue=(double) intvalue
//doublevalue=(double) 10 //변수값읽기 이렇게 앞에 더블이라고 적어주면 형변환이 된다
//doublevalue = 10.0 //자동으로 형 변환이 된다
// doublevalue=intvalue//생략해도  작은거를 큰거에 넣으면 자동형변환됨