#define ll long long
class Solution {
public:
    ll mod = 1e9 + 7;
    ll calcPair(int n, int k, vector<vector<ll>>& dp) {
        if (k == 0)
            return 1;
        if (k < 0 || n <= 0)
            return 0;
        if (dp[n][k] != -1)
            return dp[n][k];
        return dp[n][k] = (calcPair(n - 1, k, dp) + calcPair(n, k - 1, dp) -
                           calcPair(n - 1, k - n, dp) + mod) %
                          mod;
    }
    int kInversePairs(int n, int k) {
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, -1));
        return calcPair(n, k, dp);
    }
};
