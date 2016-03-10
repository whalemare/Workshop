package ru.whalemare;

import java.util.Random;
import java.util.Scanner;

public class Main {

    /**
     * @author НГТУ, АВТФ, АБ-421, Власов А.И.
     * определяет номер элемента в массиве, суммы элементов слева и справа от которого
     * различаются на минимально возможную величину (элементы – целые числа)
     */
    public static void main(String[] args) {

        System.out.println("Введите количество элементов: ");
        System.out.println(">> ");

        Scanner in = new Scanner(System.in);
        int array[] = initArray(in.nextInt());
        System.out.println("Сформированный массив");

        getPosition(array);
    }

    /**
     * Генерирует массив размерностью 1, с размером = length, элемент в массиве от 0 до 99
     *
     * @param length - размер массива
     * @return готовый массив
     */
    private static int[] initArray(int length) {
        Random random = new Random();
        int array[] = new int[length];
        for (int i = 0; i < length; i++) {
            array[i] = random.nextInt(100);
            System.out.println("[" + i + "] = " + array[i]);
        }
        return array;
    }

    private static int getPosition(int array[]) {
        int position = -1;
        int delta = -1;
        int min = 100 * array.length;
        int summLeft = 0;
        int summRight = 0;

        for (int i = 0; i < array.length; i++) {
            if (i != 0)
                summLeft += array[i - 1];
            else
                summLeft = 0;

            if (i == array.length - 1) {
                break;
            } else {
                summRight = getRightSum(array, i);
//                System.out.println("Cчетчик: " + i + ". Сумма слева: " + summLeft + ". Сумма справа: " + summRight);
                delta = Math.abs(summLeft - summRight);
//                System.out.println("Дельта: " + delta);
//                System.out.println("Темп: " + min);
                if (delta < min) {
//                    System.out.println("delta<min == " + (delta<min));
                    min = delta;
                    position = i;
                } else {
//                    System.out.println("delta<min == " + (delta<min));
                }
//                System.out.println("=======");
            }
        }
        System.out.println("Позиция: " + position + ". Разница: " + min);

        return position;
    }

    private static int getLeftSum(int array[], int position) {
        int left = 0;
        for (int i = 0; i < position; i++)
            left += array[i];
        return left;
    }

    private static int getRightSum(int array[], int position) {
        int right = 0;
        for (int i = (position + 1); i < array.length; i++) {
            right += array[i];
        }
        return right;
    }

}
