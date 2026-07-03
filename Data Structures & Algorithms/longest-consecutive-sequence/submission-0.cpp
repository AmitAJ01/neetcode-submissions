class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        // if(n==0) return 0;
        unordered_set<int> st;
        for(int x: nums) st.insert(x);

        int ans=0;
        for(auto it: st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                while(st.find(it+1)!=st.end()){
                    cnt++;
                    it++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};
