class Solution {
public:
    bool isAnagram(string s, string t) {
        int alph[26]={0};
        for(auto ch: s){
            alph[ch-'a']++;
        }
        for(auto ch: t){
            alph[ch-'a']--;
        }
        for(int i=0; i<26; i++){
            if(alph[i]!=0) return false;
        }
        return true;
    }
};
