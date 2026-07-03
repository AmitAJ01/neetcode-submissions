class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string s=strs[0];
        string t=strs[n-1];
        int i=0, j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++,j++;
            }
            else{
                break;
            }
        }
        return t.substr(0,j);
    }
};