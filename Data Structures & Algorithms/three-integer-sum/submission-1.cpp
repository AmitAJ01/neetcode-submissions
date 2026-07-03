class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n=arr.size();
        vector<vector<int>> ans;
        for(int i=0; i<n-1; i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum = arr[i]+arr[j]+arr[k];
                if(sum==0){
                    ans.push_back({arr[i],arr[j],arr[k]});
                    j++,k--;
                    while(arr[j-1]==arr[j] && j<k)j++;
                    while(arr[k+1]==arr[k] && j<k) k--;
                }
                else if(sum>0) k--;
                else j++;
            }
        }
        return ans;
    }
};
