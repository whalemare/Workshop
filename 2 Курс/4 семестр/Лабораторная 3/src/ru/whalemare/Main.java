package ru.whalemare;

public class Main {

    public static void main(String[] args) {

        Matrix matrix = new Matrix(4, 4);

        matrix.showMatrix();

        matrix.revertRowIfFirstBiggerThenLast();
//        matrix.putZeroAfterMaxInRow();
//        matrix.putZeroAfterMinInColumn();

        matrix.showMatrix();
    }
}
