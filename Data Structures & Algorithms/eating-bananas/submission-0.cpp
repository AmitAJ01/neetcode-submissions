class Solution {
public:
    int f(vector<int>& arr, int spd){
        int hr=0;
        for(int i=0; i<arr.size(); i++){
            //time = amt/speed
            hr += (arr[i]+spd-1)/spd;
        }
        return hr;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        int e = *max_element(arr.begin(),arr.end());
        int s=1;

        while(s<=e){
            int mid = s+(e-s)/2;
            int hr = f(arr,mid);
            if(hr<=h) e=mid-1;
            else s=mid+1;
        }
        return s;
    }
};
