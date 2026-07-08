class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
     //O(nlogn)   
        // sort(trips.begin(), trips.end(), 
        //     [](auto &a, auto &b){
        //         return a[1] < b[1];
        //     });
        
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        
        // int curPass = 0;
        // for(auto &trip: trips){
        //     int pas = trip[0];
        //     int start = trip[1];
        //     int end = trip[2];

        //     while(!q.empty() && q.top().first <= start){
        //         curPass -= q.top().second;
        //         q.pop();
        //     }
        //     curPass += pas;
        //     if(curPass > capacity) return false;
        //     q.push({end,pas});
        // }
        // return true;

    //O(n)
        vector<int> dif(1001,0);
        for(auto& t: trips){
            int pas = t[0];
            int from = t[1];
            int to = t[2];
            dif[from] += pas;
            dif[to] -= pas;
        }

        int cap = 0;
        for(int i=0; i<1001; i++){
            cap+=dif[i];
            if(cap>capacity) return false;
        }
        return true;
    }
};