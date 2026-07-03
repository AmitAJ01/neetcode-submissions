class Solution {
public:
    int f(vector<int>& arr, int sum){
        int cnt=1;
        int s=0;
        for(int i=0; i<arr.size(); i++){
            s+=arr[i];
            if(s>sum){
                cnt++;
                s=arr[i];
            }
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int s = *max_element(nums.begin(),nums.end()),
        e = accumulate(nums.begin(),nums.end(),0);

        while(s<=e){
            int mid = s+(e-s)/2;
            int sa = f(nums,mid);
            if(sa<=k) e=mid-1;
            else s=mid+1;
        }
        return s;
    }
};