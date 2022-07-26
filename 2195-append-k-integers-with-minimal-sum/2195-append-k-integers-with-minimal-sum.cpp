class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        
       long long res = (long long)k * (k + 1) / 2;
    for (int n : set<int>(begin(nums), end(nums)))
        if (n <= k)
            res += (++k) - n;
    return res;
    }
};