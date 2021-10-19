package Intervals_3;

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
                System.out.print("= , [");
                System.out.print(a);
                System.out.print(",");
                System.out.print(b);
                System.out.println("]");
            }
            else{
                if (b < d){
                    System.out.print("1 , [");
                    System.out.print(a);
                    System.out.print(",");
                    System.out.print(b);
                    System.out.println("]");
                }
                else {
                    System.out.print("2 , [");
                    System.out.print(c);
                    System.out.print(",");
                    System.out.print(d);
                    System.out.println("]");
                }
            }

        }
        else{
            if (a < c){

                if (b < d){
                    System.out.print("? , [");
                    if (b >= c){
                        System.out.print(c);
                        System.out.print(",");
                        System.out.print(b);
                        System.out.println("]");
                    }else{
                        System.out.println("]");
                    }
                }
                else{
                    System.out.print("2 , [");
                    System.out.print(c);
                    System.out.print(",");
                    System.out.print(d);
                    System.out.println("]");
                }

            }
            else{

                if (b > d){
                    System.out.print("? , [");
                    if (a <= d){
                        System.out.print(a);
                        System.out.print(",");
                        System.out.print(d);
                        System.out.println("]");
                    }else{
                        System.out.println("]");
                    }
                }
                else{
                    System.out.print("1 , [");
                    System.out.print(a);
                    System.out.print(",");
                    System.out.print(b);
                    System.out.println("]");
                }
            }
        }
    }
}

