class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=nums.size()-1;
        int j=i;
        while(j>=0){
            if(nums[j]==val){
                swap(nums[i],nums[j]);
                i--;
            }
            j--;
        }
        return i+1;
    }
};