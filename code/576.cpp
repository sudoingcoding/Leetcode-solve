class Solution {
public:
    int totalMoves(int startRow, int startColumn, int moves, int maxMove, int m,
                   int n, vector<vector<vector<int>>>& memo) {
        int mod = 1e9 + 7;
        if (startRow < 0 || startColumn < 0 || startRow >= m ||
            startColumn >= n) {
            if (moves <= maxMove)
                return 1;
            return 0;
        }
        if (moves >= maxMove)
            return 0;
        if (memo[startRow][startColumn][moves] != -1)
            return memo[startRow][startColumn][moves];
        memo[startRow][startColumn][moves] =
            ((totalMoves(startRow, startColumn - 1, moves + 1, maxMove, m, n,
                         memo) +
              totalMoves(startRow, startColumn + 1, moves + 1, maxMove, m, n,
                         memo)) %
                 mod +
             (totalMoves(startRow - 1, startColumn, moves + 1, maxMove, m, n,
                         memo) +
              totalMoves(startRow + 1, startColumn, moves + 1, maxMove, m, n,
                         memo)) %
                 mod) %
            mod;
        return memo[startRow][startColumn][moves];
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> memo(
            m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return totalMoves(startRow, startColumn, 0, maxMove, m, n, memo);
    }
};
