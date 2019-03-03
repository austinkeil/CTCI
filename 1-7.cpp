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

bool rotate(int **matrix, int n, int m) {
    if (n != m) return false;
    for (int layer = 0; layer < n/2; layer++) {
//        cout << "Layer " << layer << ": " << endl;
//        printMatrix(matrix, n, m);
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; i++) {
            int offset = i - first;

            int top = matrix[first][i];

            matrix[first][i] = matrix[last-offset][first];
            matrix[last-offset][first] = matrix[last][last-offset];
            matrix[last][last-offset] = matrix[i][last];
            matrix[i][last] = top;
        }
    }
    return true;
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
            matrix[i][j] = i;
        }
    }
    cout << "Start: " << endl;
    printMatrix(matrix, N, N);
    rotate(matrix, N, N);
    cout << "Finish: " << endl;
    printMatrix(matrix, N, N);

}