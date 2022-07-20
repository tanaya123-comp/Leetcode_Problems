class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
        vector<vector<int> > alpha(26);
        
        for(int i=0;i<s.length();i++)
        {
            alpha[s[i]-'a'].push_back(i);
        }
        
        int ans=0;
        
        for(auto x:words)
        {
            int index=-1;
            bool found=true;
            
            for(char ch:x)
            {
                auto it = upper_bound (alpha[ch - 'a'].begin (), alpha[ch - 'a'].end (), index);
                
				if (it == alpha[ch - 'a'].end ()) 
                    found = false;
				else index = *it;
            }
            if(found)
            {
                ans++;
            }
        }
        
        return ans;
    }
};