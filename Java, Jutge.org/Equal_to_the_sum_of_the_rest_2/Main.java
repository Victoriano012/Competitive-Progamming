package Equal_to_the_sum_of_the_rest_2;

import java.util.Scanner;

public class Main {

    public static void main (String args []) {

        Scanner scanner = new Scanner(System.in);

        for (int x = 0; x < 10; x++) {

            double[] e = new double[scanner.nextInt()];
            double s = 0;

            for (int i = 0; i < e.length; i++){
                e[i] = scanner.nextInt();
                s = s + e [i];
            }

            int ans = 0;

            for (int i = 0; i < e.length; i++){
                if (s - e[i] == e[i]){
                    ans++;
                    break;
                }
            }

            if (ans == 0) System.out.println("NO");
            else System.out.println("YES");

        }

    }
}
