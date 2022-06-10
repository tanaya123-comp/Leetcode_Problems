class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> vec;
        int siz=numbers.size();
        int i,j;
        i=0;
        j=siz-1;
        while(i<j)
        {
            if(numbers[i]+numbers[j]<target)
            {
                i++;
            }
            else if(numbers[i]+numbers[j]>target)
            {
                j--;
            }
            else
            {
                vec.push_back(i+1);
                vec.push_back(j+1);
                break;
            }
        }
        return vec;
        
    }
};