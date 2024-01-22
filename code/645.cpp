class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> corr;
        int n = nums.size(), D = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            corr[nums[i]]++;
            if (corr[nums[i]] == 2) D = nums[i];
            sum += nums[i];
        }
        int es = n * (n + 1) / 2;
        int mn = abs(es - (sum - D));
        return {D, mn};
    }
};
