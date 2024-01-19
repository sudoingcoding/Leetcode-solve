class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            matrix[i][j] += min({matrix[i-1][max(j-1, 0)], matrix[i-1][j], 
                                       matrix[i-1][min(j+1, static_cast<int>(matrix[0].size())-1)]});
        }
    }
    
    return *min_element(matrix.back().begin(), matrix.back().end());
    }
};
