class Solution {
public:
    int brokenCalc(int startValue, int target) {
        
        int number_of_count=0;
        while(target>startValue)
        {
            if(target%2)
                target++;
            else
                target=target/2;
            
            number_of_count++;
        }
        
        return number_of_count+startValue-target;
        
    }
};