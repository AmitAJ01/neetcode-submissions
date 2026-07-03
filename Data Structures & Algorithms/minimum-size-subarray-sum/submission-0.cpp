class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len=INT_MAX, l=0, r=0 ;
        long long sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(target<=sum){
                len = min(len,r+1-l);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        if(len==INT_MAX) return 0;
        return len;
    }
};