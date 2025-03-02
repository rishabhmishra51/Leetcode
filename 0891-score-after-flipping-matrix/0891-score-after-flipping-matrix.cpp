class Solution {
public:

       int matrixScore(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 0) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }

    for (int j = 1; j < m; j++) {
        int countOnes = 0;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == 1) countOnes++;
        }
        int countZeros = n - countOnes;

        if (countZeros > countOnes) {
            for (int i = 0; i < n; i++) {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int rowValue = 0;
        for (int j = 0; j < m; j++) {
            rowValue = (rowValue << 1) | grid[i][j];
        }
        sum += rowValue;
    }

    return sum;


    }
};