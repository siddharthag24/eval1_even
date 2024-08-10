#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> getCofactor(const vector<vector<int>>& mat, int p, int q, int n) {
    vector<vector<int>> temp(n - 1, vector<int>(n - 1));
    int i = 0, j = 0;

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if (row != p && col != q) {
                temp[i][j++] = mat[row][col];
                if (j == n - 1) {
                    j = 0;
                    ++i;
                }
            }
        }
    }

    return temp;
}
int determinant(const vector<vector<int>>& mat, int n) {
    int det = 0;
    if (n == 1) {
        return mat[0][0];
    }
    if (n == 2) {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    }
    int sign = 1;
    for (int f = 0; f < n; ++f) {
        vector<vector<int>> temp = getCofactor(mat, 0, f, n);
        det += sign * mat[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }
    return det;
}
int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    cout << "Enter the elements of the matrix row-wise:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }
cout << "The determinant of the matrix is: " << determinant(mat, n) << endl;
    return 0;
}

