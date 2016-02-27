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

        System.out.println("Введите количество чисел для подсчета среднего геометрического");
        System.out.print(">> ");

        Scanner in = new Scanner(System.in);
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
