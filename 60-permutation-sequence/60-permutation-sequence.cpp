class Solution {
public:
    
    string getNextPermutation(string s)
    {
        int i,j,n;
        n=s.length();
        
        j=n-2;
        while(j>=0&&(s[j+1]-'0')<(s[j]-'0'))
        {
            j--;
        }
        
       // cout<<j<<"\n";
        
        i=n-1;
      //  j=j-1;
        while(i>j&&(s[i]-'0')<(s[j]-'0'))
        {
            i--;
        }
       // cout<<i<<"\n";
        
        swap(s[i],s[j]);
        
       // cout<<s<<"\n";
        
        i=n-1;
        j=j+1;
        while(j<=i)
        {
            swap(s[j],s[i]);
            i--;
            j++;
        }
        
        //cout<<s<<"\n";
        
        return s;
    }
    
    string getPermutation(int n, int k) 
    {
            
        string s="";
        
        for(int i=1;i<=n;i++)
        {
            s=s+to_string(i);
        }
        
     //   cout<<s<<"\n";
        
        for(int i=1;i<k;i++)
        {
            s=getNextPermutation(s);
        }
        
        return s;
    }
};