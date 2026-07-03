class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> s;
        for(int i=0; i<n; i++){
            while(!s.empty() && s.top().first < temp[i]){
                int idx = s.top().second;
                s.pop();
                ans[idx] = i-idx;
            }
            s.push({temp[i],i});
        }
        return ans;
    }
};