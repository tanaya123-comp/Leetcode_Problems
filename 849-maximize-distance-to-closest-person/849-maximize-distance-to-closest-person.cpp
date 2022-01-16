class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int n,i,j;
        n=seats.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        for(i=0;i<n;i++)
        {
            if(i==0&&seats[i]==1)
            {
                prefix[i]=0;
            }
            else if(i==0&&seats[i]==0)
            {
                prefix[i]=-1;
            }
            else if(i!=0)
            {
                if(seats[i]==1)
                {
                    prefix[i]=i;
                }
                else
                {
                    prefix[i]=prefix[i-1];
                }
            }
        }
        for(i=n-1;i>=0;i--)
        {
            if(i==n-1&&seats[i]==1)
            {
                suffix[i]=i;
            }
            else if(i==n-1&&seats[i]==0)
            {
                suffix[i]=-1;
            }
            else if(i!=n-1)
            {
                 if(seats[i]==1)
                {
                    suffix[i]=i;
                }
                else
                {
                    suffix[i]=suffix[i+1];
                }
                
            }
        }
        // for(i=0;i<n;i++)
        // {
        //     cout<<prefix[i]<<" ";
        // }
        // cout<<"\n";
        // for(i=0;i<n;i++)
        // {
        //     cout<<suffix[i]<<" ";
        // }
        int ans=INT_MIN;
        int index;
        for(i=0;i<n;i++)
        {
            int left=INT_MIN;
            int right=INT_MAX;
            if(seats[i]==0)
            {
                if(prefix[i]!=-1)
                {
                    left=prefix[i];
                }
                if(suffix[i]!=-1)
                {
                    right=suffix[i];
                }
                int left_min;
                if(left!=INT_MIN)
                    left_min=(i-left);
                else
                {
                    left_min=INT_MAX;
                }
                int right_min;
                if(right!=INT_MAX)
                    right_min=(right-i);
                else
                {
                    right_min=INT_MAX;
                }
                cout<<left_min<<" "<<right_min<<"\n";
                int short_ans;
                if(left_min<right_min)
                {
                    short_ans=left_min;
                }
                else
                {
                    short_ans=right_min;
                }
                if(ans<short_ans)
                {
                    ans=short_ans;
                    index=i;
                }
            }
        }
        return ans;
    }
};