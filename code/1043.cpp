class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(k);
        for (int i = 1; i <= n; i++) {
            int curMax = 0, best = 0, j = 1;
            while (j <= k && i - j >= 0) {
                curMax = max(curMax, arr[i - j]);
                best = max(best, dp[(i - j) % k] + curMax * j);
                ++j;
            }
            dp[i % k] = best;
        }
        return dp[n % k];
    }
};
