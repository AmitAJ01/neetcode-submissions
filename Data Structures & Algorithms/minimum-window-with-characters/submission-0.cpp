class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256] = {};
        int l=0, cnt=0, minLen=INT_MAX;
        int startIdx=-1;

        for(char ch: t){
            hash[ch]++;
        }

        for(int r=0; r<s.size(); r++){
            if(hash[s[r]] > 0) cnt++;
            hash[s[r]]--;

            while(cnt==t.size()){
                if(minLen > r+1-l){
                    minLen = r+1-l;
                    startIdx=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0) cnt--;
                l++;
            }
        }
        return startIdx==-1? "": s.substr(startIdx, minLen);
    }
};