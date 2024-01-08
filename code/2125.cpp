class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<long long int>v;
        for(auto & c:bank){
            long long int p=0;
            for(auto& s:c){
                if(s=='1')p++;
            }
            if(p!=0)v.push_back(p);
        }
        long long int sum=0;
        for(int i=1;i<v.size();i++){
            sum+=v[i]*v[i-1];
        }
        return sum;
    }
};
