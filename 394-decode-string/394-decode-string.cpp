class Solution {
public:
    string decodeString(string s) {
        
        int len=s.length();
        stack<int> st;
        stack<char> ch;
        
        int i=0;
        while(i<len)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                string t="";
                while(i<len&&s[i]>='0'&&s[i]<='9')
                {
                    t=t+s[i];
                    i++;
                }
                int num=0;
                for(int j=0;j<t.length();j++)
                {
                  //  cout<<num<<"\n";
                 num=num*10+(t[j]-'0');   
                }
               // cout<<num<<"\n";
                st.push(num);
            }
            else if(s[i]=='[')
            {
                
                ch.push(s[i]);
                i++;
            }
            else if(s[i]>='a'&&s[i]<='z')
            {
                ch.push(s[i]);
                i++;
            }
            else if(s[i]==']')
            {
                string temp="";
                while(!ch.empty()&&ch.top()!='[')
                {
                    temp=temp+ch.top();
                    ch.pop();
                }
                ch.pop();
                
                int times=st.top();
                st.pop();
                
                reverse(temp.begin(),temp.end());
                
                
                
                for(int j=0;j<times;j++)
                {
                    for(auto x:temp)
                    {
                        ch.push(x);
                    }
                }
                i++;
            }
        }
        
        string ans="";
        while(!ch.empty())
        {
            ans=ch.top()+ans;
            ch.pop();
        }        
        
        return ans;
    }
};