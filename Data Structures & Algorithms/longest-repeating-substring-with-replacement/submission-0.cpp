class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> m;
        int l=0;
        int mf=0;
        int len=0;
        for(int r=0; r<s.size(); r++){
            m[s[r]]++;
            mf=max(mf,m[s[r]]);
            while(r-l+1-mf > k){
                m[s[l]]--;
                l++;
            }
            len=max(len,r-l+1);
        }return len;
    }
};