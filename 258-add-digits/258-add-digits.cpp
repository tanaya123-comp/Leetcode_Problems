class Solution {
public:
    int addDigits(int num) 
    {
        int sum=0;
        int n;
        while(num>=10)
        {
            n=num;
            sum=0;
            while(n>0)
            {
                sum=sum+n%10;
                n=n/10;
            }
            //sum=sum+1;
            num=sum;
        }
        return num;
    }
};