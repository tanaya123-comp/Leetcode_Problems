class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        stack<int> st;
        int i,siz;
        siz=s.length();
        i=0;
        while(i<siz)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(st.empty())
                {
                    st.push(i);
                }
                else if(s[st.top()]=='(')
                {
                    st.pop();
                }
                else
                {
                    st.push(i);
                }
            }
            i++;
        }
        string validString="";
        i=siz-1;
        while(i>=0)
        {
            if(s[i]==')'||s[i]=='(')
            {
                if(!st.empty()&&st.top()==i)
                {
                    st.pop();
                }
                else
                {
                    validString+=s[i];
                }
            }
            else
            {
                 validString+=s[i];
            }
            i--;
        }
        reverse(validString.begin(),validString.end());
        return validString;
    }
};