class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        int i=0, j=0;
        while(j<n){
            if(arr[i]!=arr[j]){
                i++;
                arr[i]=arr[j];
            }else j++;
        } 
        return i+1;
    }
};