class Solution {
public:
    int f(vector<int>& arr, int cap){
        int s=0;
        int d=0;
        for(int i=0; i<arr.size(); i++){
            s+=arr[i];
            if(s>=cap){
                d++;
                if(s==cap) s=0;
                else s=arr[i];
            }
        }
        if(s>0) d++;
        return d;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        int e = accumulate(arr.begin(),arr.end(),0);
        int s=*max_element(arr.begin(), arr.end());

        while(s<=e){
            int m = s+(e-s)/2;
            int d = f(arr,m);
            if(d>days) s = m+1;
            else e=m-1;
        }   
        return s;
    }
};