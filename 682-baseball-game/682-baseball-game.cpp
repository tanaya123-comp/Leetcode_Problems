class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        stack<int> s;
        int len,i,x;
        len=ops.size();
        for(i=0;i<len;i++)
        {
            if(ops[i]=="D")
            {
                x=s.top();
                s.push(2*x);
            }
            else if(ops[i]=="C")
            {
                s.pop();
            }
            else if(ops[i]=="+")
            {
                x=s.top();
                s.pop();
                int j=x+s.top();
                s.push(x);
                s.push(j);
            }
            else
            {
                if(ops[i][0]=='-')
                {
                    
                   // s.push(-1*(ops[i][1]-'0'));
                    x=0;
                    int j=1;
                    while(j<ops[i].length())
                    {
                        x=x*10+(ops[i][j]-'0');
                        j++;
                    }
                    s.push(-1*x);
                }
                else
                {
                    x=0;
                    int j=0;
                    while(j<ops[i].length())
                    {
                        x=x*10+(ops[i][j]-'0');
                        j++;
                    }
                    s.push(x);
                }
            }
        }
        
        int sum=0;
        while(!s.empty())
        {
          //  cout<<s.top()<<"\n";
            sum=sum+s.top();
            s.pop();
        }
        return sum;
    }
};