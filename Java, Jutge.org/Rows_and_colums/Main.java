package Rows_and_colums;

import java.util.Scanner;

public class Main {

    public static void main(String args[]) {

        Scanner scanner = new Scanner(System.in);

        int x = scanner.nextInt();
        int y = scanner.nextInt();

        int[][] a = new int[x][y];

        for (int i = 0; i < x; i++) {
            for (int b = 0; b < y; b++) {
                a[i][b] = scanner.nextInt();
            }
        }

        for (int i = 0; i < 10; ++i) {
            String p = scanner.next();
            if (p == "row") {
                int b = scanner.nextInt();
                System.out.print("row " + b + ": ");
                for (int j = 0; j < y - 1; ++j) {
                    System.out.print(a[b][j] + " ");
                }
                System.out.println(a[b][y - 1]);
            } else {
                if (p == "column") {
                    int b = scanner.nextInt();
                    System.out.print("column " + b + ": ");
                    for (int j = 0; j < x - 1; ++j) {
                        System.out.print(a[j][b] + " ");
                    }
                    System.out.println(a[x - 1][b]);
                } else {
                    int b = scanner.nextInt();
                    int c = scanner.nextInt();
                    System.out.print("element " + b + " " + c + ": ");
                    System.out.println(a[b][c]);
                }
            }
        }
    }
}
