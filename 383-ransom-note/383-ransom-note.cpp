class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int arr1[26]={0};
        int arr2[26]={0};
        
        for(auto x:ransomNote)
        {
            arr1[x-'a']++;
        }
        
        for(auto x:magazine)
        {
            arr2[x-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(arr1[i]>0)
            {
                if(arr1[i]>arr2[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};