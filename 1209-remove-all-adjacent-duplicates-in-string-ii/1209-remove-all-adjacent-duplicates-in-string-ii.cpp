class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
       int n = s.length();
        stack<pair<char, int>> st;
        
        for(int i=0; i<n; i++) {
            if(st.empty()) {
                st.push({s[i], 1});
            }
            else {
                pair<char, int> curr = st.top();
                
                if(curr.first == s[i]) {
                    // check for frequency of adjacent
                    if(curr.second + 1 == k) {
                        // remove k duplicate
                        int cnt = k - 1;
                        while(cnt--) {
                            st.pop();
                        }
                        
                        // do not push the current
                    }
                    else {
                        st.push({s[i], curr.second+1});
                    }
                }
                else {
                    // adj chars are NOT equal
                    st.push({s[i], 1});
                }
            }
        }
        
        string res = "";
        while(!st.empty()) {
            res += st.top().first;
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};