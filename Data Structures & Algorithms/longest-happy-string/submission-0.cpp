class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> q;
        if(a>0) q.push({a,'a'});
        if(b>0) q.push({b,'b'});
        if(c>0) q.push({c,'c'});

        string ans = "";
        while(!q.empty()){
            auto [cnt, ch] = q.top(); q.pop(); //check if first ch se 3 consecutive na ho
            if (ans.size() >= 2 && ans.back() == ch && ans[ans.size()-2] == ch){ //if ho to take 2nd ch
                if(q.empty()) break; //agr 2nd ch na ho to khtm tata byebye
                auto [cnt2, ch2] = q.top(); q.pop();
                ans+=ch2;
                cnt2--;
                if(cnt2>0) q.push({cnt2,ch2});
                q.push({cnt,ch});
            }
            else{ //verna agr 3 consecutive na bano to simply ans ko aur aage banao
                ans+=ch;
                cnt--;
                if(cnt>0) q.push({cnt,ch});
            }
        }
        return ans;
    }
};