package ru.whalemare;

import java.util.Scanner;

/**
 * @author НГТУ, АВТФ, АБ-421, Власов Антон Игоревич.
 * Вариант №5.
 *
 * Программа для вычисления среднего геометрического по абсолютным значениям введенной последовательности чисел.
 */
public class Main {

    public static void main(String[] args) {

        System.out.println("Выберите тип задания");
        System.out.println("1. Общее");
        System.out.println("2. Индивидуальное");

        Scanner in = new Scanner(System.in);
        int k = in.nextInt();

        /**
         * для case 1: код писал не я
         */
        switch (k){
            case 1:
                int N;
                System.out.print("Введите количество чисел N (N > 0) = ");
                N = in.nextInt();
                System.out.print("Введите число #1: ");
                int d = in.nextInt();
                int sum = d;
                int sum1 = 0; // 2 задание
                int sum2 = 0; // 3 задание
                int maxi = d;
                int mini = d;
                int j = 1; // счетчик введенных чисел
                while (j < N){
                    j = j+1;
                    System.out.print("Введите число #" + j + ": ");
                    d = in.nextInt();
                    sum += d;
                    if (d > maxi) {
                        maxi = d;
                    }
                    else if (d < mini){
                        mini = d;
                    }
                    // задание 2
                    if (d % 2 == 0)
                        sum1 += d;
                    // задание 3
                    if (j % 2 == 0)
                        sum2 += d;
                }
                System.out.println("Сумма введенных чисел равна " + sum);
                System.out.println("Максимальное значение среди них равно " + maxi);
                System.out.println("Минимальное значение среди них равно " + mini);
                double ave = sum * 1.0 / N;
                System.out.println("Среднее арифметическое этих чисел равно " + ave);
                if (maxi > Math.abs(mini)){
                    System.out.println("Максимальное(абсолютное) значение среди них равно " + maxi);
                }
                System.out.println("Сумма чётных чисел равна " + sum1);
                System.out.println("Сумма чисел с чётными номерами равна " + sum2);
                break;
            case 2:
                System.out.println("Введите количество чисел для подсчета среднего геометрического");
                System.out.print(">> ");

                int count = in.nextInt();

                int all = 1;
                for (int i=0; i<count; i++)
                {
                    System.out.println();
                    System.out.print("Введите число " + i + " >> ");
                    int number = in.nextInt();
                    number = getAbs(number);
                    all *= number;
                }

                System.out.println("Среднее геометрическое = " + getGeometricMean(all, count));
                in.close();
                break;
        }
    }

    /**
     * Возвращает абсолютное значение числа
     * @param number число, для которого необходимо вернуть абсолютное значение
     * @return int число > 0
     */
    private static int getAbs(int number){
        return number < 0 ? (number *= -1) : number;
    }

    /**
     * Возвращает среднее геометрическое
     * @param all произведение всех введенных чисел (их абсолютных значений)
     * @param count количество чисел
     * @return среднее геометрическое
     */
    private static double getGeometricMean(int all, int count){
        return Math.exp(Math.log(all)/count);
    }
}
