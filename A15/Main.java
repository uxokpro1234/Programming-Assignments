package me.uxokpro1234.D6;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {

            try {
                System.out.println("\nA15 - Triangle Heights");
                System.out.println("Enter the coordinates of the three vertices.");

                System.out.print("A x: ");
                double x1 = Double.parseDouble(scanner.nextLine());

                System.out.print("A y: ");
                double y1 = Double.parseDouble(scanner.nextLine());

                System.out.print("B x: ");
                double x2 = Double.parseDouble(scanner.nextLine());

                System.out.print("B y: ");
                double y2 = Double.parseDouble(scanner.nextLine());

                System.out.print("C x: ");
                double x3 = Double.parseDouble(scanner.nextLine());

                System.out.print("C y: ");
                double y3 = Double.parseDouble(scanner.nextLine());

                //calculate the three side lengths
                double a = distance(x2, y2, x3, y3);
                double b = distance(x1, y1, x3, y3);
                double c = distance(x1, y1, x2, y2);

                //calculate the triangle area
                double area = triangleArea(x1, y1, x2, y2, x3, y3);

                //check whether the three points form a valid triangle
                if (area == 0) {
                    System.out.println("Error: The three points do not form a triangle.");
                } else {

                    // Calculate heights using h = 2A / side
                    double hA = (2 * area) / a;
                    double hB = (2 * area) / b;
                    double hC = (2 * area) / c;

                    System.out.println("\nResults:");
                    System.out.printf("Height from vertex A: %.4f%n", hA);
                    System.out.printf("Height from vertex B: %.4f%n", hB);
                    System.out.printf("Height from vertex C: %.4f%n", hC);
                }

            } catch (NumberFormatException e) {
                System.out.println("Error: Invalid input. Please enter numbers only.");
            }

            //ask whether the user wants to run the program again
            System.out.print("\nRun the program again? (y/n): ");
            String answer = scanner.nextLine();

            if (!answer.equalsIgnoreCase("y")) {
                break;
            }
        }

        scanner.close();
        System.out.println("Program finished.");
    }

    //calculates the distance between two points
    public static double distance(double x1, double y1, double x2, double y2) {
        return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
    }

    //calculates the area of the triangle using the determinant formula
    public static double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) {
        return Math.abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
    }
}
