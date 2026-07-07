class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> m;
        for(auto x: tasks){
            m[x]++;
        }
        priority_queue<int> q;
        for(auto x: m){
            q.push(x.second);
        }

        int time=0;
        while(!q.empty()){
            int cycle = n+1;
            int i=0;
            vector<int> temp;
            while(i<cycle && !q.empty()){
                int cnt = q.top(); q.pop();

                cnt--;
                if(cnt>0) temp.push_back(cnt);
                i++, time++;
            }

            for(auto it: temp) q.push(it);

            if(q.empty()) break;

            time+= cycle-i;
        }
        return time;
    }
};
