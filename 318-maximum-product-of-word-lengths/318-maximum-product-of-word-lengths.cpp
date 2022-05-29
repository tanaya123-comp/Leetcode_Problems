class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        int len=words.size();
        int i,j,k;
        vector<int> maxLen(words.size(),0);
        int ans=0;
        for(i=0;i<len;i++)
        {
            for(auto x:words[i])
            {
                maxLen[i]|=1<<(x-'a');
            }
            
            for(j=0;j<i;j++)
            {
                if(!(maxLen[i]&maxLen[j]))
                {
                    if(ans<words[i].length()*words[j].length())
                    ans=words[i].length()*words[j].length();
                }
            }
        }
        return ans;
        
        
    }
};