class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int prod=1;
        for(int i=0; i<n; i++){
            prod*=nums[i];
            ans[i]=prod;
        }
        int right =1;

        for(int i=n-1; i>=0; i--){
            if(i==0) ans[i]=right;
            else ans[i] = ans[i-1]*right;
            right*=nums[i];
        }
        return ans;
    }
};