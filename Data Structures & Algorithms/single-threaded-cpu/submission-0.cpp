class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        vector<vector<int>> arr(n, vector<int>(3,0));

        for(int i=0; i<n; i++){
            arr[i][0] = tasks[i][0];
            arr[i][1] = tasks[i][1];
            arr[i][2] = i;
        }
        sort(arr.begin(), arr.end());
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> q;

        long long  time = 0;
        int i=0;
        vector<int> ans;
        while(i<n || !q.empty()){
            if(q.empty() && time < arr[i][0]) time = arr[i][0];

            while(i<n && time >= arr[i][0]){
                q.push({arr[i][1],arr[i][2]});
                i++;
            }

            auto it = q.top(); q.pop();
            ans.push_back(it.second);
            time += it.first;
        }
        return ans;
    }
};