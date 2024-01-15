class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losses;
        set<int>win;
        for (auto& c : matches) {
            losses[c[1]]++;
            win.insert(c[0]);
        }
        vector<int>noL;
        vector<int>oneL;
        for(auto&c:win){
            if(losses[c]==0) noL.push_back(c);
        }
        for(auto&c:losses){
            if(c.second==1) oneL.push_back(c.first);
        }
        sort(oneL.begin(),oneL.end());
        return {noL,oneL};
    }
};
