class Solution {
public:
    int findMin(vector<int> &nums) {
        int s=0, e = nums.size()-1;
        int n=e;

        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]>nums[n]) s=mid+1;
            else e=mid-1;
        }
        return nums[s];
    }
};
