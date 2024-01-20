#define ll long long int
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        int n=arr.size(),mod=1e9+7;
        vector<ll>dp(n,-1);
        stack<int>stack;
        ll ans=0;
        for(int i=0;i<n;i++){
            while(!stack.empty()&& arr[i]<=arr[stack.top()]) stack.pop();
            if(!stack.empty()){
                int j=stack.top();
                dp[i]=dp[j]+arr[i]*(i-j);
            }
            else dp[i]=arr[i]*(i+1);
            stack.push(i);
            ans=(ans+dp[i])%mod;
        }
        return ans;
    }
};
