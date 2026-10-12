class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int i = 0, j = 0;

        while (true) {
            int up, down, left, right;

            if (i == 0)
                up = -1;
            else
                up = mat[i - 1][j];

            if (i == m - 1)
                down = -1;
            else
                down = mat[i + 1][j];

            if (j == 0)
                left = -1;
            else
                left = mat[i][j - 1];

            if (j == n - 1)
                right = -1;
            else
                right = mat[i][j + 1];

            if (up > mat[i][j])
                i--;
            else if (down > mat[i][j])
                i++;
            else if (left > mat[i][j])
                j--;
            else if (right > mat[i][j])
                j++;
            else
                return {i, j};
        }
    }
};