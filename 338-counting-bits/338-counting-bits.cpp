class Solution {
public:
    vector<int> countBits(int n) {
        
//         vector<int> vec;
//         int i;
//         for(i=0;i<=n;i++)
//         {
//             int count=0;
//             while(i>0)
//             {
//                 count=count+i%2;
//                 i=i/2;
//             }
//             vec.push_back(count);
//         }
//         return vec;
        vector<int> ans;
		vector<int> count(n+1,0);
        ans.push_back(0);
        for(int i=1;i<=n;i++)
        {
            count[i]=1+count[i&(i-1)];
            ans.push_back(count[i]);
        }
        return ans;
    }
};