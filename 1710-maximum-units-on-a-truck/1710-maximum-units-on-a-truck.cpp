bool toCompare(vector<int> a,vector<int> b)
{
    if(a[1]>b[1])
        return true;
    else if(a[1]<b[1])
    {
        return false;
    }
    if(a[0]>b[0])
        return true;
    
    return false;
    
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int siz,i,j,k;
        siz=boxTypes.size();
        
        sort(boxTypes.begin(),boxTypes.end(),toCompare);
        
        int numberOfBoxes=0;
        
        for(i=0;i<siz;i++)
        {
            if(truckSize>=boxTypes[i][0])
            {
                truckSize=truckSize-boxTypes[i][0];
                numberOfBoxes+=(boxTypes[i][0]*boxTypes[i][1]);
            }
            else
            {
                numberOfBoxes+=(truckSize*boxTypes[i][1]);
                truckSize=0;
            }
            
        }
        
        return numberOfBoxes;
        
        
    }
};