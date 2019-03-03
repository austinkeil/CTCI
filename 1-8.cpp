#include <bits/stdc++.h>

using namespace std;

void printMatrix(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void nullifyRow(int **matrix, int m, int n) {
    for (int i = 0; i < n; i++) {
        matrix[m][i] = 0;
    }
}

void nullifyColumn(int **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        matrix[i][n] = 0;
    }
}


void zero(int **matrix, int m, int n) {
    bool rowZero = false, colZero = false;

    for (int j = 0; j < n; j++){
        if (matrix[0][j] == 0) {
            rowZero = true;
        }
    }
    for (int i = 0; i < m; i++){
        if (matrix[i][0] == 0) {
            colZero = true;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int j = 1; j < n; j++) {
        if (matrix[0][j] == 0)
            nullifyColumn(matrix, m, j);
    }
    for (int i = 1; i < m; i++) {
        if (matrix[i][0] == 0)
            nullifyRow(matrix, i, n);
    }

    if (rowZero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }
    if (colZero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }

}

int main() {
    int N = 10;

    int **matrix;
    matrix = new int *[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 20;
        }
    }

    cout << "Start: " << endl;
    printMatrix(matrix, N, N);
    zero(matrix, N, N);
    cout << "Finish: " << endl;
    printMatrix(matrix, N, N);

    delete[] matrix;
}