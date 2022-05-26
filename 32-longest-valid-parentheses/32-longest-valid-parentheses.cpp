class Solution {
public:
    int longestValidParentheses(string s) 
    {
        stack<pair<char,int> > st;
        int i,ans,len;
        len=s.length();
        i=0;
        ans=0;
        while(i<len)
        {
            if(s[i]=='(')
            {
                st.push(make_pair(s[i],i));
            }
            else
            {
                if(st.empty())
                {
                    st.push(make_pair(s[i],i));
                }
                else if(st.top().first=='(')
                {
                    st.pop();
                    if(st.empty())
                    {
                        ans=max(ans,i+1);
                    }
                    else
                    {
                        ans=max(ans,i-st.top().second);
                    }
                }
                else
                {
                      st.push(make_pair(s[i],i));
                }
            }
            i++;
        }
        return ans;
    }
};