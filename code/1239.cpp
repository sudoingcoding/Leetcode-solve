class Solution {
public:
    bool isValid(string& currentString, unordered_map<char, int>& memo) {
        unordered_map<char, int> temp;
        for (auto& currentChar : currentString) {
            temp[currentChar]++;
            if (memo[currentChar] == 1 || temp[currentChar] > 1)
                return false;
        }
        return true;
    }

    void findMaxLen(int currentIndex, string& current, int& maxLen,
                    unordered_map<char, int>& memo, vector<string>& arr) {
        maxLen = max(maxLen, static_cast<int>(current.size()));
        if (currentIndex == static_cast<int>(arr.size()))
            return;
        for (int i = currentIndex; i < static_cast<int>(arr.size()); i++) {
            string currentString = arr[i];
            if (isValid(currentString, memo)) {
                int j = 0;
                while (j < static_cast<int>(currentString.size())) {
                    current.push_back(currentString[j]);
                    memo[currentString[j]]++;
                    j++;
                }
                findMaxLen(i + 1, current, maxLen, memo, arr);
                j = static_cast<int>(currentString.size());
                while (j--) {
                    current.pop_back();
                    memo[currentString[j]]--;
                }
            }
        }
        return;
    }

    int maxLength(vector<string>& arr) {
        int maxLen = 0;
        string current = "";
        unordered_map<char, int> memo;
        findMaxLen(0, current, maxLen, memo, arr);
        return maxLen;
    }
};
