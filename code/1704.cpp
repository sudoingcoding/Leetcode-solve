class Solution {
public:
    bool isVowel(char s) {
        string str = "aeiouAEIOU";
        return (str.find(s) != string::npos);
    }
    bool halvesAreAlike(string s) {
        int n = s.size(), a = 0, b = 0;
        for (int i = 0; i < n / 2; i++) {
            if (isVowel(s[i]))
                a++;
        }
        for (int i = n / 2; i < n; i++) {
            if (isVowel(s[i]))
                b++;
        }
        if (a == b)
            return true;
        return false;
    }
};
