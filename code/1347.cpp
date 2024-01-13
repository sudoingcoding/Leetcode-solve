class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>count(26,0);
        for(auto&c:s){
            count[c-'a']++;
        }
        for(auto&c:t){
            count[c-'a']--;
        }
        int step=0;
        for(auto&c:count){
            if(c>0) step+=c;
        }
        return step;
    }
};
