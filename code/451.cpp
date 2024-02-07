class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        vector<pair<int,char>>v;
        for(auto&c:s){
            mp[c]++;
        }
        for(auto&c:mp){
            v.push_back({c.second,c.first});
        }
        sort(v.rbegin(),v.rend());
        string ans="";
        for(auto&c:v){
            for(int i=0;i<c.first;i++){
                ans+=c.second;
            }
        }
        return ans;
    }
};
