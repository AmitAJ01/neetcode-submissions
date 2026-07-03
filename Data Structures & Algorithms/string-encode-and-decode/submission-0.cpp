class Solution {
public:

    string encode(vector<string>& arr) {
        string s="";
        for(string str: arr){
            s += to_string(str.size()) + '#'+str;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string temp = "";
        int i=0;
        
        while(i<s.length()){
            int j=i;
            while(s[j]!='#') j++;
            int len = stoi(s.substr(i,j-i));

            ans.push_back(s.substr(j+1,len));
            i = j+len+1;
            
        }
        return ans;
    }
};
