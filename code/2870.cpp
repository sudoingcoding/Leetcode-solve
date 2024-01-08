class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>trk;
        for(auto & c:nums){
            trk[c]++;
        }
        int l=0;
        for(auto& c:trk){
            if(c.second==1) return-1;
            if(c.second%3==1){
                l+=2;
                l+=(c.second/3)-1;
            } 
            else {
                l+=(c.second/3);
                l+=((c.second%3)/2);
            } 
        }
        return l;
    }
};
