package Reverse_of_sequences;

import java.util.Scanner;

public class Main {

    public static void main (String args []){

        Scanner scanner = new Scanner(System.in);

        for (int x = 0; x < 10; x++) {
            int[] a = new int[scanner.nextInt()];

            for (int i = 0; i < a.length; i++) {
                a[i] = scanner.nextInt();
            }
            for (int i = a.length - 1; i > 0; i--) {
                System.out.print(a[i] + " ");
            }
            if (a.length > 0) {
                System.out.print(a[0]);
            }
            System.out.println();
        }
    }
}