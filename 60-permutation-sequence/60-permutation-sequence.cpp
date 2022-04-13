class Solution {
public:
    string getPermutation(int n, int k) {
        
        vector<int> numbers;
        long fact=1;
        for(int i=1;i<n;i++)    
        {
            fact=fact*i;            //store factorial
            numbers.push_back(i);   //store numbers
        }
        numbers.push_back(n);
        k=k-1;      //make k zero based index
        string ans="";
        while(true)
        {
            ans=ans+to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+k/fact);
            if(numbers.size()==0)
                break;
            k=k%fact;
            fact=fact/numbers.size();
        }
        return ans;
    }
};