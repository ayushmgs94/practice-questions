class Solution {
public:
    int totalNQueens(int n) {
        int answer = 0;
        vector<bool> columnUsed(n, false);
        vector<bool> diagonal1(2 * n - 1, false);
        vector<bool> diagonal2(2 * n - 1, false);

        function<void(int)> backtrack = [&](int row) {
            if (row == n) {
                answer++;
                return;
            }

            for (int col = 0; col < n; col++) {
                int d1 = row - col + n - 1;
                int d2 = row + col;
                if (columnUsed[col] || diagonal1[d1] || diagonal2[d2]) continue;

                columnUsed[col] = diagonal1[d1] = diagonal2[d2] = true;
                backtrack(row + 1);
                columnUsed[col] = diagonal1[d1] = diagonal2[d2] = false;
            }
        };

        backtrack(0);
        return answer;
    }
};
