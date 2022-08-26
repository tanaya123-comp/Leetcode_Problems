class NumArray {
public:
    vector<int> num;
    
    NumArray(vector<int>& nums) {
        
        int n,i;
        n=nums.size();
        for(i=1;i<n;i++)
        {
            nums[i]=nums[i-1]+nums[i];
        }
        num=nums;
        
    }
    
    int sumRange(int left, int right) {
        if(left==0)
        {
            return num[right];
        }
        return num[right]-num[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */