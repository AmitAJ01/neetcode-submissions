class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int,stack<int>> st;
    int maxf;
    FreqStack() {
        maxf=0;
    }
    
    void push(int val) {
        freq[val]++;
        int curfreq = freq[val];
        if(curfreq>maxf) maxf=curfreq;
        st[curfreq].push(val);
    }
    
    int pop() {
        int ans = st[maxf].top();
        st[maxf].pop();
        freq[ans]--;

        if(st[maxf].empty()) maxf--;

        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */