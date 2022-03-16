class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
            stack<int> st;
            int n=pushed.size();
            int i,j,k;
            i=1;
            j=0;
            st.push(pushed[0]);
            while(i<n&&j<n)
            {
                if(!st.empty()&&st.top()==popped[j])
                {
                    st.pop();
                    j++;
                }
                else
                {
                    st.push(pushed[i]);
                    i++;
                }
            }
            while(j<n)
            {
                if(!st.empty()&&st.top()==popped[j])
                {
                    st.pop();
                    j++;
                }
                else
                {
                    return false;
                }
            }
            if(i==n&&j==n&&st.empty())
                return true;
            else
                return false;
    }
};