bool isEqual(int arr1[26],int arr2[26])
{
    for(int i=0;i<26;i++)
    {
        if(arr1[i]!=arr2[i])
            return false;
    }
    return true;
}

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int len1,len2,i,j,k;
        len1=s.length();
        len2=p.length();
        
        int arr1[26]={0};
        int arr2[26]={0};
        
        for(i=0;i<len2;i++)
        {
            arr2[p[i]-'a']++;
        }
        
        vector<int> ans;
        
        i=0;
        j=0;
        while(j<len1)
        {
            arr1[s[j]-'a']++;
           // cout<<arr1<<" "<<arr2<<"\n";
            if(isEqual(arr1,arr2))
            {
                ans.push_back(i);
            }
            
            if(j-i+1>=len2)
            {
                while(j-i+1>=len2)
                {
                    arr1[s[i]-'a']--;
                    i++;
                }
                
            }
            j++;
            
        }
        
        return ans;
        
    }
};