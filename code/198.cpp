class Solution {
public:
    int rob(vector<int>& nums) {
        int r=0,nr=0;
        for(int i=0;i<nums.size();i++){
            int nR=nr+nums[i];
            int nNR=max(nr,r);
            r=nR;
            nr=nNR;
        }
        return max(r,nr);
    }
};
