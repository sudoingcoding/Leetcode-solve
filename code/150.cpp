class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>nums;
        for(auto&c:tokens){
            if(isdigit(c[0]) || (c.size() > 1 && isdigit(c[1])))nums.push(stoi(c));
            else if(c[0]=='+') {
                int a=nums.top();
                nums.pop();
                int b=nums.top();
                nums.pop();
                int c=b+a;
                nums.push(c);
            }
            else if(c[0]=='-'){
                int a=nums.top();
                nums.pop();
                int b=nums.top();
                nums.pop();
                int c=b-a;
                nums.push(c);
            }
            else if(c[0]=='*'){
                int a=nums.top();
                nums.pop();
                int b=nums.top();
                nums.pop();
                int c=b*a;
                nums.push(c);
            }
            else if(c[0]=='/'){
                int a=nums.top();
                nums.pop();
                int b=nums.top();
                nums.pop();
                int c=b/a;
                nums.push(c);
            }
        }
        return nums.top();
    }
};
