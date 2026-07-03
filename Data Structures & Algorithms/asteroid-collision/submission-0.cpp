class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> ans;
        stack<int> s;
        s.push(arr[0]);

        for(int i=1; i<arr.size(); i++){
            bool alive = true;
            while(!s.empty() && s.top()>0 && arr[i]<0){
                if(s.top() < -1*arr[i]) s.pop();
                else if(s.top() == -1*arr[i]){
                    alive=false;
                    s.pop();
                    break;
                }
                else{
                    alive=false;
                    break;
                }
            }
            if(alive) s.push(arr[i]);
        }

        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        if(ans.size()>1) reverse(ans.begin(), ans.end());
        return ans;
    }
};