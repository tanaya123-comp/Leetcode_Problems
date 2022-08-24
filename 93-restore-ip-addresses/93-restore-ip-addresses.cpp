class Solution {
public:
    
    vector<string> ans;
    
    bool isValid(string s)
    {
        if(s.length()==0||s.length()>3)
        {
            return false;
        }
        if(s[0]=='0'&&s.length()>1)
        {
            return false;
        }
        int num=0;
        int len,i;
        len=s.length();
        i=0;
        while(i<len)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                num=num*10+s[i]-'0';
            }
            else
            {
                return false;
            }
            i++;
        }
        if(num>=0&&num<=255)
        {
            return true;
        }
        return false;
    }
    
    void getAllIpAddress(string s,string t,int x)
    {
        if(s.length()==0&&x==4)
        {
            ans.push_back(t);
            return;
        }
        if(x>=4)
        {
            return;
        }
        int len=s.length();
        for(int i=1;i<=min(len,3);i++)
        {
            if(isValid(s.substr(0,i)))
            {
                if(t=="")
                {
                   getAllIpAddress(s.substr(i),t+s.substr(0,i),x+1); 
                }
                else
                {
                    getAllIpAddress(s.substr(i),t+"."+s.substr(0,i),x+1); 
                }
                
            }
        }
        
    }
    
    vector<string> restoreIpAddresses(string s) 
    {
        ans.clear();
        string t="";
        getAllIpAddress(s,t,0);
        return ans;
    }
};