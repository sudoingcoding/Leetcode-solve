class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>wait(n,0);
        stack<int>st;
        for(int i=n-1;i>-1;--i){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]) st.pop();
            if(!st.empty()) wait[i] = st.top()-i;
            st.push(i);
        }
        return wait;
    }
};
