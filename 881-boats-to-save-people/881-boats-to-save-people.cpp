class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int siz,i,j,min_num_boats;
        siz=people.size();
        sort(people.begin(),people.end());
        min_num_boats=0;
        i=0;
        j=siz-1;
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                i++;
                j--;
                min_num_boats++;
            }
            else
            {
                j--;
                 min_num_boats++;
            }
        }
        return min_num_boats;
    }
};