#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000; // Maximum dimensions of the matrix

int matrix[MAXN][MAXN];
int sqrtTree[32][32][MAXN / 32][MAXN / 32]; // Adjust dimensions based on sqrt(MAXN)

class Sqrt2DTree {
private:
    int rows, cols, sqrtRows, sqrtCols;

public:
    Sqrt2DTree(const vector<vector<int>>& arr) {
        rows = arr.size();
        cols = arr[0].size();
        sqrtRows = (int)sqrt(rows) + 1;
        sqrtCols = (int)sqrt(cols) + 1;

        // Initialize matrix and sqrtTree
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = arr[i][j];
                sqrtTree[i / sqrtRows][j / sqrtCols][i % sqrtRows][j % sqrtCols] = matrix[i][j];
            }
        }

        // Build sqrtTree
        for (int i = 0; i < sqrtRows; ++i) {
            for (int j = 0; j < sqrtCols; ++j) {
                for (int x = 0; x < sqrtRows; ++x) {
                    for (int y = 1; y < sqrtCols; ++y) {
                        sqrtTree[i][j][x][y] = min(sqrtTree[i][j][x][y], sqrtTree[i][j][x][y - 1]);
                    }
                }
                for (int y = 0; y < sqrtCols; ++y) {
                    for (int x = 1; x < sqrtRows; ++x) {
                        sqrtTree[i][j][x][y] = min(sqrtTree[i][j][x][y], sqrtTree[i][j][x - 1][y]);
                    }
                }
            }
        }
    }

    int query(int x1, int y1, int x2, int y2) {
        int min_value = INT_MAX;

        for (int i = x1; i <= x2; ++i) {
            int sqrt_row = i / sqrtRows;
            int sqrt_start_col = y1 / sqrtCols;
            int sqrt_end_col = y2 / sqrtCols;

            if (sqrt_start_col == sqrt_end_col) {
                for (int j = y1; j <= y2; ++j) {
                    min_value = min(min_value, matrix[i][j]);
                }
            } else {
                for (int j = y1; j < (sqrt_start_col + 1) * sqrtCols; ++j) {
                    min_value = min(min_value, matrix[i][j]);
                }
                for (int j = sqrt_start_col + 1; j < sqrt_end_col; ++j) {
                    min_value = min(min_value, sqrtTree[sqrt_row][j][i % sqrtRows][sqrtCols - 1]);
                }
                for (int j = sqrt_end_col * sqrtCols; j <= y2; ++j) {
                    min_value = min(min_value, matrix[i][j]);
                }
            }
        }

        return min_value;
    }
};

int main() {
    vector<vector<int>> arr = {
        {1, 3, 2},
        {4, 2, 5},
        {6, 7, 1}
    };

    Sqrt2DTree sqrtTree(arr);

    cout << sqrtTree.query(0, 0, 2, 2) << endl; // Output: 1 (minimum value in the entire array)
    cout << sqrtTree.query(1, 1, 2, 2) << endl; // Output: 1 (minimum value in the submatrix [1, 1] - [2, 2])

    return 0;
}
