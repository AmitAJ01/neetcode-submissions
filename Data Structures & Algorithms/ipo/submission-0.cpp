class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minCap;
        priority_queue<int> maxProfit;

        int n = capital.size();
        for(int i=0; i<n; i++){
            minCap.push({capital[i],profits[i]});
        }

        while(k--){
            while(!minCap.empty() && minCap.top().first<=w){
                maxProfit.push(minCap.top().second);
                minCap.pop();
            }
            if(maxProfit.empty()) break;

            w+=maxProfit.top();
            maxProfit.pop();
        }
        return w;
    }
};