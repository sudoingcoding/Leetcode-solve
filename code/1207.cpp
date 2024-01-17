class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>m;
        for(auto&c:arr){
            m[c]++;
        }
        unordered_set<int>s;
        for(auto&c:m){
            s.insert(c.second);
        }
        if(m.size()==s.size()) return true;
        return false;
    }
};
