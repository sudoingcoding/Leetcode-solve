class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        if(set(word1.begin(),word1.end())!=set(word2.begin(),word2.end())) return false;
        vector<int>w1(26),w2(26);
        for(int i=0;i<word1.size();i++){
            w1[word1[i]-'a']++;
            w2[word2[i]-'a']++;
        }
        sort(w1.begin(),w1.end());
        sort(w2.begin(),w2.end());
        return w1==w2;
    }
};
