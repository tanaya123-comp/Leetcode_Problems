class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        int n=prices.size();
        vector<int> vec(n);
        stack<int> s;
        int i;
        for(i=n-1;i>=0;i--)
        {
            if(s.empty())
            {
                vec[i]=prices[i];
                s.push(prices[i]);
            }
            else
            {
                while(!s.empty()&&s.top()>prices[i])
                {
                    s.pop();
                }
                if(s.empty())
                {
                    vec[i]=prices[i];
                    s.push(prices[i]);
                }
                else
                {
                    vec[i]=prices[i]-s.top();
                    s.push(prices[i]);
                }
            }
        }
        return vec;
    }
};