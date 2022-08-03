class MyCalendar {
public:
    
    vector<pair<int,int> > vec;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) 
    {
        if(vec.size()==0)
        {
            vec.push_back({start,end});
            return true;
        }
        
        int low,high,mid;
        low=0;
        high=vec.size()-1;
        
        while(low<=high)
        {
            mid=(low+high)/2;
            if(vec[mid].second<start)
            {
                low=mid+1;
            }
            else if(vec[mid].first>end)
            {
                high=mid-1;
            }
            else if(vec[mid].second==start)
            {
                low=mid+1;
            }
            else if(vec[mid].first==end)
            {
                high=mid-1;
            }
            else
            {
                return false;
            }
        }
        vec.push_back({start,end});
        sort(vec.begin(),vec.end());
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */