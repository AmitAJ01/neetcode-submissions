class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(m<n) return findMedianSortedArrays(nums2, nums1);
        int s=0, e=n;

        while(s<=e){
            int cut1 = s+(e-s)/2;
            int cut2 = (n+m+1)/2 - cut1;

            int l1=INT_MIN, l2=INT_MIN,
            r1=INT_MAX, r2=INT_MAX;

            if(cut1-1>=0) l1 = nums1[cut1-1];
            if(cut2-1>=0) l2 = nums2[cut2-1];
            if(cut1<n) r1 = nums1[cut1];
            if(cut2<m) r2 = nums2[cut2];

            if(l1<=r2 && l2<=r1){
                if((n+m)%2!=0) return max(l1,l2);
                else return (max(l1,l2) + min(r1,r2))/2.0;
            }
            else if(l1>r2) e=cut1-1;
            else s=cut1+1;
        }
        return 0;
    }
};
