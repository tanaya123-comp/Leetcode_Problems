class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
       
        int arr[256]={0};
        int ans=0;
        int siz=s.length();
        
        int i,j;
        i=0;
        j=0;
        while(i<=j&&j<siz)
        {
            if(arr[s[j]]==0)
            {
                arr[s[j]]++;
                j++;
            }
            else
            {
                while(i<=j)
                {
                    if(s[i]==s[j])
                    {
                        arr[s[i]]--;
                        i++;
                        break;
                    }
                    arr[s[i]]--;
                    i++;
                }
                arr[s[j]]++;
                j++;
            }
            ans=max(ans,j-i);
        }
        return ans;
        
    }
};