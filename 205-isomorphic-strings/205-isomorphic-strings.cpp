class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char,char> mp;
        int arr[256]={0};
        
        int len1,len2,i;
        len1=s.length();
        len2=t.length();
        
        if(len1!=len2)
            return false;
        
        i=0;
        while(i<len1)
        {
            auto it=mp.find(s[i]);
              
          //  cout<<arr[t[i]-97]<<"\n";
            if(it==mp.end()&&arr[t[i]]==0)
            {
                  mp[s[i]]=t[i];
                int x=s[i];
    
                 arr[t[i]]=x;
            }
            else if(it==mp.end()&&(arr[t[i]]!=0))
            {
                  return false;   
            }
            else if((it!=mp.end()&&it->second!=t[i]))
                return false;
          
            
            i++;
        }
        
        return true;
        
    }
};