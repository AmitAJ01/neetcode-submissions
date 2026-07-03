class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> num;
        string cur="";
        int k=0;

        for(char c: s){
            if(isdigit(c)) k = k*10 + (c-'0');
            else if(c=='['){
                st.push(cur);
                num.push(k);
                cur="";
                k=0;
            }
            else if(c==']'){
                string temp = cur;
                cur = st.top(); st.pop();
                int cnt = num.top(); num.pop();

                for(int i=0; i<cnt; i++){
                    cur += temp;
                }
                // st.push(cur);
            }
            else cur+=c;
        }
        return cur;
    }
};
