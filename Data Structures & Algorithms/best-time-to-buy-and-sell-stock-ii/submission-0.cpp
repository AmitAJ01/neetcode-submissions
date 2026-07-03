class Solution {
public:
    int f(vector<int>& arr, int i, int buy,vector<vector<int>>& dp){
        if(i==arr.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;
        if(buy){
            profit = max(-arr[i]+f(arr,i+1,0,dp), f(arr,i+1,1,dp));
        }
        else{
            profit = max(arr[i]+f(arr,i+1,1,dp), f(arr,i+1,0,dp));
        }
        return dp[i][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(prices,0,1,dp);
    }
};