class StockSpanner {
public:
    stack<pair<int,int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(s.empty() || price < s.top().first) s.push({price,1});
        else{
            int day=1;
            while(!s.empty() && s.top().first <= price){
                day+=s.top().second;
                s.pop();
            }
            s.push({price,day});
        }
        return s.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */