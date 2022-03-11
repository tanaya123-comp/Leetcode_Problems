class LRUCache {
public:
        
    class node 
    {
            
        public:
        int key;
        int value;
        node* next;
        node* prev;
        
        node(int key,int value)
        {
            this->key=key;
            this->value=value;
        }
        
    };
    
    node* tail,*head;
    int capacity;
    unordered_map<int,node*> mp;
    
    LRUCache(int capacity) 
    {
        this->capacity=capacity;
        head=new node(-1,-1);
        tail=new node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    void deleteNode(node* reqNode)
    {
        node* prev=reqNode->prev;
        node* next=reqNode->next;
        prev->next=next;
        next->prev=prev;
    }
    
    void addNode(node* reqNode)
    {
        node* headNext=head->next;
        reqNode->next=headNext;
        headNext->prev=reqNode;
        head->next=reqNode;
        reqNode->prev=head;
    }
    
    int get(int key) 
    {
        if(mp.find(key)!=mp.end())
        {
            node* reqNode=mp[key];
            int val=reqNode->value;
            mp.erase(key);
            deleteNode(reqNode);
            addNode(reqNode);
            mp[key]=head->next;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key)==mp.end())
        {
            node* newNode=new node(key,value);
            if(mp.size()<capacity)
            {
                addNode(newNode);
                mp.insert({key,newNode});
            }
            else
            {
                node* lruNode=tail->prev;
                deleteNode(lruNode);
                mp.erase(lruNode->key);
                addNode(newNode);
                mp.insert({key,newNode});
            }
        }
        else
        {
            node* updateNode=mp[key];
            deleteNode(updateNode);
           addNode(new node(key,value));
            mp[key]=head->next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */