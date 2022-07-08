class Solution {
public:
    string getHint(string secret, string guess) {
        
        int n,m,i,j;
        n=secret.length();
        m=guess.length();
        
        int bulls=0;
        int cows=0;
        int arr[10]={0};
        
        for(i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
            {
                bulls++;
                secret[i]='#';
            }
            else
            {
                arr[guess[i]-'0']++;
            }
        }
        
        for(i=0;i<n;i++)
        {
            if(secret[i]!='#')
            {
                if(arr[secret[i]-'0']>0)
                {
                    arr[secret[i]-'0']--;
                    cows++;
                }
            }
        }
        
        return to_string(bulls)+"A"+to_string(cows)+"B";
        
    }
};