class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        
        int len=password.length(),i,j;
        if(len<8)
        {
            return false;
        }
        bool isLower,isUpper,isDigit,isSpecial;
        isLower=false;
        isUpper=false;
        isDigit=false;
        isSpecial=false;
        
        for(i=0;i<len;i++)
        {
            if(password[i]>='a'&&password[i]<='z')
                isLower=true;
            if(password[i]>='A'&&password[i]<='Z')
                isUpper=true;
            if(password[i]>='0'&&password[i]<='9')
                isDigit=true;
            if(password[i]=='!'||password[i]=='@'||password[i]=='$'||password[i]=='%'||password[i]=='#'||password[i]=='^'||password[i]=='&'||password[i]=='*'||password[i]=='('||password[i]==')'||password[i]=='-'||password[i]=='+')
            {
               isSpecial=true; 
            }
        }
        
        for(i=1;i<len;i++)
        {
            if(password[i]==password[i-1])
                return false;
        }
        
    return isLower&&isUpper&&isDigit&&isSpecial;
        
    }
};