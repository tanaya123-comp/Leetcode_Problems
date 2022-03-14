class Solution {
public:
    string simplifyPath(string s) {
        
        string ans="";
        stack<string> st;
        int n,i,j;
        n=s.length();
        i=0;
        while(i<n)
        {
            if(s[i]=='/')
            {
                //single slash
                i++;
            }
            else if(s[i]=='.'&&(i+1)<n&&s[i+1]=='/')
            {
                //single .
                i++;
            }
            else if(s[i]=='.'&&(i+1)==n)
            {
                //single .
                i++;
            }
            else if(s[i]=='.'&&(i+1)<n&&s[i+1]=='.')
            {
                // for ..
                if(((i+2)<n&&s[i+2]=='/')||(i+2)==n)
                {
                    if(!st.empty())
                    {
                        st.pop();
                    }
                    i++;
                }
                else
                {
                    string temp="";
                    while(i<n&&s[i]!='/')
                    {
                        temp=temp+s[i];
                        i++;
                    }
                    st.push(temp);
                }
            }
            else
            {
                string temp="";
                    while(i<n&&s[i]!='/')
                    {
                        temp=temp+s[i];
                        i++;
                    }
                    st.push(temp);
            }
        }
        
        if(st.empty())
        {
            return "/";
        }
        
        while(!st.empty())
        {
            string temp=st.top();
            st.pop();
            
            ans="/"+temp+ans;
           
        }
        
        
        
        
        return ans;
    }
};