class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
      int siz,i,j;
        siz=heights.size();
        vector<int> left(siz);
        vector<int> right(siz);
        stack<int> s;
        left[0]=0;
        s.push(0);
        for(i=1;i<siz;i++)
        {
                while(!s.empty()&&heights[s.top()]>=heights[i])
                {
                    s.pop();
                }
                if(s.empty())
                {
                    left[i]=0;
                }
                else
                {
                    left[i]=s.top()+1;
                }
                s.push(i);
        }
        // for(i=0;i<siz;i++)
        // {
        //     cout<<left[i]<<"\n";
        // }
        while(!s.empty())
        {
            s.pop();
        }
        right[siz-1]=siz-1;
        s.push(siz-1);
        for(i=siz-2;i>=0;i--)
        {
             while(!s.empty()&&heights[s.top()]>=heights[i])
            {
                 
                s.pop();
            }
            if(s.empty())
            {
                right[i]=siz-1;
            }
            else
            {
                right[i]=s.top()-1;
            }
            s.push(i);
        }
        // for(i=0;i<siz;i++)
        // {
        //     cout<<right[i]<<"\n";
        // }
        int ans=INT_MIN;
        for(i=0;i<siz;i++)
        {
           // cout<<left[i]<<" "<<right[i]<<"\n";
            ans=max(ans,((right[i]-left[i]+1)*heights[i]));
        }
        return ans;
    }
};