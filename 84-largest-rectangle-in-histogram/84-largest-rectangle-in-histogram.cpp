class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
       vector<int> nsr, nsl;
        stack<int> st1, st2;
        
        for(int i=0; i<heights.size(); i++) {
            while(!st1.empty() && heights[st1.top()] >= heights[i])
                st1.pop();
            if(st1.empty())
                nsl.push_back(-1);
            else
                nsl.push_back(st1.top());
            
            st1.push(i);
        }
        
        for(int i=heights.size()-1; i>=0; i--) {
            while(!st2.empty() && heights[st2.top()] >= heights[i])
                st2.pop();
            if(st2.empty())
                nsr.push_back(heights.size());
            else
                nsr.push_back(st2.top());
            
            st2.push(i);
        }
        reverse(nsr.begin(), nsr.end());
        
        vector<int> width;
        
        for(int i=0; i<heights.size(); i++) {
            width.push_back((nsr[i]-nsl[i]-1) * heights[i]);
        }
        
        return *max_element(width.begin(), width.end());
    }
};