package ru.whalemare;

import java.util.Random;

/**
 * Created by whalemare on 26.03.2016.
 */
public class Matrix {

    final int n; // row
    final int m; // column
    int matrix[][];

    int min = 100;
    int max = -1;

    public Matrix(int n, int m){
        this.n = n;
        this.m = m;
        this.matrix = new int[n][m];

        Random random = new Random();
        for (int i=0; i<n; i++)
            for (int j = 0; j < m; j++)
                matrix[i][j] = random.nextInt(99);
    }

    public void showMatrix(){
        for (int i=0; i<n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.printf("%4d", matrix[i][j]);
            }
            System.out.println();
        }
    }

    /**
     * В каждой строке заменить нулями все элементы, следующие (по номеру) за
     * максимальным элементом в этой строке
     */
    public void putZeroAfterMaxInRow(){
        for (int i=0; i<n; i++){
            int max = -1;
            int position = 0;

            for (int j=0; j<m; j++){
                if (matrix[i][j] > max) {
                    max = matrix[i][j];
                    position = j;
                }
            }

            if (position != m-1) {
                for (int k=position; k<m; k++){
                    matrix[i][k] = 0;
                }
            }
        }
    }

    /**
     * 5.2. в каждом столбце заменить минимальным элементом массива все элементы,
     * предшествующие (по номеру) минимальному элементу в этом столбце
     */
    public void putZeroAfterMinInColumn(){
        for (int i=0; i<n; i++){
            int min = 100;
            int position = 0;
            for (int j=0; j<m; j++){
                if (matrix[j][i] < min) {
                    min = matrix[j][i];
                    position = j;
                }
            }

            if (position != n-1)
            for (int k=position+1; k<n; k++){
                matrix[k][i] = 0;
            }
        }
    }

    public void revertRowIfFirstBiggerThenLast(){
        for (int i=0; i<n; i++) {
            int tempMatrix[][] = new int[0][n];
        }
    }

}
