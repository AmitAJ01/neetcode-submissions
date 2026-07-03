class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string s: strs){
            vector<int> freq(26,0);
            for(auto x: s){
                freq[x-'a']++;
            }
            string key = "";
            for(int i: freq) key += '*' + to_string(i);
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto x: mp) ans.push_back(x.second);
        return ans;
    }
};
