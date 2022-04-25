class UndergroundSystem {
public:
    
    unordered_map<int,pair<string,int> > mp;
    
    unordered_map<string,pair<int,int> > totalDuration;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) 
    {
        mp[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        pair<string,int> ST=mp[id];
      //  cout<<stationTime.first<<" "<<stationTime.second<<"\n";
        string journey=ST.first+"->"+stationName;
        int startTime=ST.second;
        int endTime=t;
        if(totalDuration.find(journey)==totalDuration.end())
        {
            totalDuration[journey]={endTime-startTime,1};
        }
        else
        {
            pair<int,int> temp=totalDuration[journey];
            temp.first=temp.first+endTime-startTime;
            temp.second++;
            totalDuration[journey]=temp;
        }
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
         string journey=startStation+"->"+endStation;
        int totalTime=totalDuration[journey].first;
        int totalPeople=totalDuration[journey].second;
        return (double)totalTime/(double)totalPeople;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */