//package Counting_frequences;

import java.util.Scanner;

public class Main {

    public static void main (String args []) {

        Scanner scanner = new Scanner(System.in);

        int[] e = new int[scanner.nextInt()];

        for (int i = 0; i < e.length; i++){
            e[i] = scanner.nextInt();
        }

        int x = 0;
        for (int v = 1000000000; v <= 1000001000; v++){
            for (int i = 0; i < e.length; i++){
                if (e[i] == v) x++;
            }
            if (x > 0){
                System.out.println(v + " : " + x );
                x = 0;
            }
        }

    }
}
