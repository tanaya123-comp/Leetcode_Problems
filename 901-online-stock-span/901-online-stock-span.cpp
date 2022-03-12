class StockSpanner {
public:
    
    stack<pair<int,int> > s;
    int index;
    
    StockSpanner() {
        
        index=-1;
        while(!s.empty())
        {
            s.pop();
        }
    }
    
    int next(int price) {
        
        index++;
        
        while(!s.empty()&&s.top().second<=price)
        {
            s.pop();
        }
        
        if(s.empty())
        {
            s.push({index,price});
            return index+1;
        }
            int result=s.top().first;
            s.push({index,price});
            return index-result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */