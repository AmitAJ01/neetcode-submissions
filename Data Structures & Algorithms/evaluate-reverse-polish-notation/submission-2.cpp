class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto ch: tokens){
            if(ch=="+"){
                int op1 = s.top(); s.pop();
                int op2 = s.top(); s.pop();
                s.push(op1+op2);
            }
            else if(ch=="-"){
                int op1 = s.top(); s.pop();
                int op2 = s.top(); s.pop();
                s.push(op2-op1);
            }
            else if(ch=="*"){
                int op1 = s.top(); s.pop();
                int op2 = s.top(); s.pop();
                s.push(op1*op2);
            }
            else if(ch=="/"){
                int op1 = s.top(); s.pop();
                int op2 = s.top(); s.pop();
                s.push(op2/op1);
            }
            else s.push(stoi(ch));
        }
        return s.top();
    }
};
