class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>trk;
        for(auto& c:nums){
            trk[c]++;
        }
        int x=0;
        for(auto& c:trk){
            x=max(c.second,x);
        }
        vector<int>row;
        vector<vector<int>>re(x,row);
        for(auto& c:trk){
            for(int i=0;i<c.second;i++){
                re[i].push_back(c.first);
            }
        }
        return re;
    }
};
