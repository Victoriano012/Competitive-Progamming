import java.math.BigInteger;

public class PM {

    static BigInteger m = new BigInteger("1000000000000000031");

    public static long pow(long a){
        if(a == 0) return 1;
        BigInteger aux = BigInteger.valueOf(pow(a/2));
        aux = aux.multiply(aux);
        aux = aux.mod(m);
        if(a%2 == 0) return aux.longValue();
        aux = aux.multiply(BigInteger.valueOf(42));
        aux = aux.mod(m);
        return aux.longValue();
    }
  
    public static void main() 
    {
  
        long Ans = 300;
        int a = 200;

        for(int i = 1000000; i > a; i--){
            Ans = pow(Ans);
        }
  
        System.out.println(Ans);
    } 
} 