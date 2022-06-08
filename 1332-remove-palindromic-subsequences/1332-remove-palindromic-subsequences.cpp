class Solution {
public:
    
    bool isPallindrome(string s)
    {
        int i,j;
        i=0;
        j=s.length()-1;
        while(i<=j)
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
    
    int removePalindromeSub(string s) {
        
        if(isPallindrome(s))
        {
            return 1;
        }
        else
        {
            return 2;
        }
        
        
        
    }
};