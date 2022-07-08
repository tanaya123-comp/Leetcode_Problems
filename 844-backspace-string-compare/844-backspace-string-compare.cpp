class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string temp1="";
        string temp2="";
        int n,m,i,j;
        n=s.length();
        m=t.length();
        
        stack<char> st;
        i=n-1;
        while(i>=0)
        {
            if(st.empty())
            {
                st.push(s[i]);
                i--;
            }
            else
            {
                if(st.top()=='#'&&s[i]!='#')
                {
                    st.pop();
                    i--;
                }
                else
                {
                    st.push(s[i]);
                    i--;
                }
            }
        }
        
        while(!st.empty())
        {
            if(st.top()!='#')
            {
               temp1=st.top()+temp1;  
            }
            st.pop();
        }
        
        i=m-1;
        while(i>=0)
        {
            if(st.empty())
            {
                st.push(t[i]);
                i--;
            }
            else
            {
                if(st.top()=='#'&&t[i]!='#')
                {
                    st.pop();
                    i--;
                }
                else
                {
                    st.push(t[i]);
                    i--;
                }
            }
        }
        
          while(!st.empty())
        {
            if(st.top()!='#')
            {
               temp2=st.top()+temp2;  
            }
            st.pop();
        }
        
        cout<<temp2<<" "<<temp1<<" "<<"\n";
        
        return temp1==temp2;
        
        
    }
};