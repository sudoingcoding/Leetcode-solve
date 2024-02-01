class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 2; i < n; i += 3) {
            if (nums[i] - nums[i - 2] > k)
                return {};
            result.push_back({nums[i - 2], nums[i - 1], nums[i]});
        }
        return result;
    }
};
