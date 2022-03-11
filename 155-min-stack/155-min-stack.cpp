class MinStack {
public:
    
    stack<long long> s;
    long long minele;
    
    MinStack() {
        
    }
    
    void push(int val) {
        long long val1=val;
        if(s.empty())
        {
            s.push(val1);
            minele=val1;
        }
        else if(val1<minele)
        {
            //long long val1=val;
            s.push((2*val1)-minele);
            minele=val1;
        }
        else
        {
            s.push(val1);
        }
    }
    
    void pop() {
        
        long long t=s.top();
        s.pop();
        
        if(t<minele)
        {
            minele=2*minele-t;
        }
    }
    
    int top() {
        
        if(s.top()>minele)
        {
            return s.top();
        }
        else
        {
            return minele;
        }
        
    }
    
    int getMin() {
        return minele;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */