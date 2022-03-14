class Solution {
public:
    
    vector<vector<string> > allPartitions;
    
    bool isPallindrome(string s)
    {
        int i=0;
        int j=s.length()-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    
    void getPartitions(string s,int start,int end,vector<string> strings)
    {
      //  cout<<"here"<<"\n";
        if(start>end)
        {
             allPartitions.push_back(strings);
            return;
        }
        if(s.length()==0)
        {
            allPartitions.push_back(strings);
            return;
        }
        for(int i=1;i<=end-start+1;i++)
        {
            if(isPallindrome(s.substr(start,i)))
            {
               // cout<<s.substr(start,i)<<"\n";
               // cout<<start+i<<"\n";
                //cout<<"goto->"<<s.substr(start+i)<<"\n";
                strings.push_back(s.substr(start,i));
                if(start+i<s.length())
                {
                   getPartitions(s,start+i,end,strings);
                }
                else
                {
                   allPartitions.push_back(strings);
                    return;
                }
                strings.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        
        vector<string> strings;
        
        getPartitions(s,0,s.length()-1,strings);
        
        return allPartitions;
    }
};