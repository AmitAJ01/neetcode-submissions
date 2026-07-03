class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0);
        int n = s1.size();
        for(char ch: s1){
            freq1[ch-'a']++;
        }
        
        vector<int> freq2(26,0);
        int l=0;
        for(int r=0; r<s2.size(); r++){
            freq2[s2[r]-'a']++;
            if(r-l+1 > n){
                freq2[s2[l]-'a']--;
                l++;
            }
            if(freq1==freq2) return true;
        }
        return false;
    }
};