package me.uxokpro1234;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    static ArrayList<Integer> dividers = new ArrayList<>();

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int a, b;
        String c;

        while (true) {

            System.out.print("Enter two natural numbers: ");

            // Incorrect data type
            if (!scanner.hasNextInt()) {
                System.out.println("Error: incorrect data type!");
                return;
            }

            a = scanner.nextInt();

            if (!scanner.hasNextInt()) {
                System.out.println("Error: incorrect data type!");
                return;
            }

            b = scanner.nextInt();
            // Invalid numbers
            if (a <= 0 || b <= 0) {
                System.out.println("Error: numbers must be natural numbers!!!");
                return;
            }

            System.out.println(a + " " + b);

            divide(a);
            divide(b);
            findDividers();

            System.out.println();
            System.out.print("Do you want to continue? Y/n: ");

            c = scanner.next();

            // Exit
            if (c.equalsIgnoreCase("n")) {
                System.out.println("Okay, goodbye!");
                break;
            }

            // Start again
            if (c.equalsIgnoreCase("y")) {
                dividers.clear();
                System.out.println();
                continue;
            }

            System.out.println("Error: please enter Y or n!");
        }

        scanner.close();
    }
    // Finds and prints divisors of a number
    static void divide(int i) {
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                dividers.add(j);
                System.out.print(j + " ");
            }
        }

        System.out.println();
    }

    // Finds common divisors
    static void findDividers() {
        System.out.print("Dividers for both numbers: ");

        for (int i = 0; i < dividers.size(); i++) {
            for (int j = i + 1; j < dividers.size(); j++) {

                if (dividers.get(i).equals(dividers.get(j))) {
                    System.out.print(dividers.get(i) + " ");
                }
            }
        }

        System.out.println();
    }
}
