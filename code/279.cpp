class Solution {
public:
    vector<int> v;

    int numSquares(int n) {
        if (n == 0)
            return 0;
        if (n < 0)
            return INT_MAX;
        if (v.size() <= n)
            v.resize(n + 1, -1);
        if (v[n] != -1)
            return v[n];
        int minSq = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            int sqCalc = 1 + numSquares(n - i * i);
            minSq = min(minSq, sqCalc);
        }
        return v[n] = minSq;
    }
};
