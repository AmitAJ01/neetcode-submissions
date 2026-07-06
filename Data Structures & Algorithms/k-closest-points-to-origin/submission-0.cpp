class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long,int>> q;
        for(int i=0; i<points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            long long dist = 1LL*(x*x) + 1LL*(y*y);
            q.push({dist,i});
            if(q.size()>k) q.pop();
        }
        vector<vector<int>> ans;
        while(!q.empty()){
            int i = q.top().second;
            ans.push_back(points[i]);
            q.pop();
        }
        return ans;
    }
};