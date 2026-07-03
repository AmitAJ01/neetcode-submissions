class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int mini=INT_MAX;
        int ans=0;
        for(int i=0; i<arr.size(); i++){
            mini = min(arr[i],mini);
            ans = max(ans, arr[i]-mini);
        }
        return ans;
    }
};
