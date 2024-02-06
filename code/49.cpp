class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int>mp;
        vector<vector<string>>ans;
        for(auto&c:strs){
            string temp=c;
            sort(temp.begin(),temp.end());
            if(mp.find(temp)!=mp.end()){
                ans[mp[temp]].push_back(c);
            }
            else{
                mp[temp]=ans.size();
                ans.push_back({c});
            }
        }
        return ans;
    }
};
