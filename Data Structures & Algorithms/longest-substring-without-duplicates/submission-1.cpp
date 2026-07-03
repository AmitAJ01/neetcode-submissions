class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        int l=0;
        unordered_map<char,int> m;
        for(int i=0; i<s.size(); i++){
            if(m.find(s[i])!=m.end()){
                l=max(l,m[s[i]]+1);
            }
            m[s[i]]=i;
            len=max(len,i-l+1);
        }
        return len;
    }
};
