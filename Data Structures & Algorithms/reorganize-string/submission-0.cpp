class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;
        for(char ch: s){
            freq[ch]++;
        }

        priority_queue<pair<int,char>> q;
        for(auto x: freq){
            if(x.second > (s.size()+1) / 2) return "";
            q.push({x.second, x.first});
        }

        int i=0;
        int n=s.size();
        string ans="";
        char prevCh = '#';
        int prevCnt = 0;
        while(!q.empty()){
            auto [freq, ch] = q.top(); q.pop();
            ans += ch;
            freq--;

            if(prevCnt>0) q.push({prevCnt, prevCh});
            prevCnt = freq;
            prevCh = ch;
        }
        return ans;
    }
};