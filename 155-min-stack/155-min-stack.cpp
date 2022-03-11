class MinStack {
public:
    
    stack<int> mainStack;
    stack<int> minStack;
    
    
    MinStack() {
        while(!mainStack.empty())
        {
            mainStack.pop();
        }
        while(!minStack.empty())
        {
            minStack.pop();
        }
        
    }
    
    void push(int val) {
        
       
        if(mainStack.empty())
        {
             mainStack.push(val);
            minStack.push(val);
        }
        else if(minStack.top()>val)
        {
             mainStack.push(val);
            minStack.push(val);
        }
        else
        {
            mainStack.push(val);
            int x=minStack.top();
            minStack.push(x);
        }
        
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
        int val=mainStack.top();
        return val;
    }
    
    int getMin() {
        int mini=minStack.top();
        return mini;
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