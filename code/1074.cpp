class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r = 0, m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        unordered_map<int, int> count;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                count = {{0, 1}};
                int cur = 0;
                for (int k = 0; k < m; k++) {
                    cur += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    r += count.find(cur - target) != count.end() ? count[cur - target] : 0;
                    count[cur]++;
                }
            }
        }
        return r;
    }
};
