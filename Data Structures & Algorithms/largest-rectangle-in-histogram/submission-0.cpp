class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> s;
        int area=0;

        for(int i=0; i<arr.size(); i++){
            while(!s.empty() && arr[s.top()]>arr[i]){
                int idx = s.top(); s.pop();
                int nse = i;
                int pse = s.empty()?-1: s.top();
                area = max(area, arr[idx]*(nse-pse-1));
            }
            s.push(i);
        }
        while(!s.empty()){
            int nse=arr.size();
            int idx = s.top(); s.pop();
            int pse = s.empty()?-1: s.top();
            area = max(area, arr[idx]*(nse-pse-1));
        }
        return area;
    }
};
