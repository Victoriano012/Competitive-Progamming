package Intervals_2;

import java.util.Scanner;

public class Main {

    public static void main (String args []){

        Scanner scanner = new Scanner(System.in);

        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int d = scanner.nextInt();

        if (a == c){

            if (b == d){
                System.out.println("=");
            }
            else{
                if (b < d){
                    System.out.println("1");
                }
                else {
                    System.out.println("2");
                }
            }

        }
        else{
            if (a < c){

                if (b < d){
                    System.out.println("?");
                }
                else{
                    System.out.println("2");
                }

            }
            else{

                if (b > d){
                    System.out.println("?");
                }
                else{
                    System.out.println("1");
                }
            }
        }
    }
}
