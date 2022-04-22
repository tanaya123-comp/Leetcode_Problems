class MyHashMap {
public:
    
    vector<long long> mp;
    
    MyHashMap() {
        mp.resize(1000007);
        for(long long i=0;i<1000007;i++)
        {
            mp[i]=-1;
        }
    }
    
    void put(int key, int value) {
        mp[key]=value;
    }
    
    int get(int key) {
        return mp[key];
    }
    
    void remove(int key) {
        mp[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */