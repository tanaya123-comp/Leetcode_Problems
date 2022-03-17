class Solution {
public:
    int scoreOfParentheses(string s) 
    {
        //https://leetcode.com/problems/score-of-parentheses/discuss/141975/c%2B%2B-solution-using-stack-(5ms)-detail-explained
        
        stack<int> st;
        st.push(0);
        int len=s.length(),i,j;
        i=0;
        while(i<len)
        {
            if(s[i]=='(')
                st.push(0);
            else
            {
                int temp_val=st.top();
                st.pop();
                int val=0;
                if(temp_val>0)
                {
                    val=2*temp_val;
                }
                else
                {
                    val=1;
                }
                st.top()+=val;
            }
            i++;
        }
        return st.top();
    }
};