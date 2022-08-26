class Solution {
public:
    
    vector<int> count(int n)
    {
        vector<int> vec(10,0);
        while(n>0)
        {
            vec[n%10]++;
            n=n/10;
        }
        return vec;
    }
    
    bool reorderedPowerOf2(int n) {
        
        vector<int> vec=count(n);
        for(int i=0;i<31;i++)
        {
            if(vec==count(1<<i))
            {
                return true;
            }
        }
        return false;
    }
};