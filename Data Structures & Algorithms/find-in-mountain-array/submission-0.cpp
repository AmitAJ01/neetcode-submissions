/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int bs(int target, MountainArray &mountainArr, int s, int e, bool asc){
        while(s<=e){
            int mid = s+(e-s)/2;
            int el = mountainArr.get(mid);
            if(el==target) return mid;
            if(asc){
                if(el>target) e=mid-1;
                else s=mid+1;
            }
            else{
                if(el>target) s=mid+1;
                else e=mid-1;
            }

        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int s=0, n=mountainArr.length(), e=n-1;
        int peak=-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)) s=mid+1;
            else e=mid-1;
        }
        peak=s;
        int ans = bs(target,mountainArr,0,peak,true);
        if(ans!=-1) return ans;
        return bs(target,mountainArr,peak+1,n-1,false);
    }
};