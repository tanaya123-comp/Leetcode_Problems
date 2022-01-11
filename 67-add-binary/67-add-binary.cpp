class Solution {
public:
    string addBinary(string a, string b) 
    {
        int n,m,i,j,k;
        n=a.length();
        m=b.length();
        i=n-1;
        j=m-1;
        int carry=0;
        int sum=0;
        string ans="";
        while(i>=0&&j>=0)
        {
            sum=(a[i]-'0')+(b[j]-'0')+carry;
            if(sum==0)
            {
                carry=0;
                ans='0'+ans;
            }
            else if(sum==1)
            {
                carry=0;
                ans='1'+ans;
            }
            else if(sum==2)
            {
                carry=1;
                ans='0'+ans;
            }
            else if(sum==3)
            {
                carry=1;
                ans='1'+ans;
            }
            i--;
            j--;
        }
        while(i>=0)
        {
            sum=(a[i]-'0')+carry;
             if(sum==0)
            {
                carry=0;
                ans='0'+ans;
            }
            else if(sum==1)
            {
                carry=0;
                ans='1'+ans;
            }
            else if(sum==2)
            {
                carry=1;
                ans='0'+ans;
            }
             else if(sum==3)
            {
                carry=1;
                ans='1'+ans;
            }
            i--;
        }
         while(j>=0)
        {
            sum=(b[j]-'0')+carry;
             if(sum==0)
            {
                carry=0;
                ans='0'+ans;
            }
            else if(sum==1)
            {
                carry=0;
                ans='1'+ans;
            }
            else if(sum==2)
            {
                carry=1;
                ans='0'+ans;
            }
              else if(sum==3)
            {
                carry=1;
                ans='1'+ans;
            }
            j--;
        }
        if(carry==1)
        {
            ans='1'+ans;
        }
        return ans;
        
    }
};