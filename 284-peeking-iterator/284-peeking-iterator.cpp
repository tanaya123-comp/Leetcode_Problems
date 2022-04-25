/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    
    vector<int> array;
    
    int arraySize;
    int ptr;
    
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        for(auto x:nums)
        {
            cout<<x<<" ";
            array.push_back(x);    
        }
        arraySize=nums.size();
        ptr=0;
        
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        
        if(ptr<arraySize)
        {
            return array[ptr];
        }
        return -1;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() 
    {
	    int x=array[ptr];
        ptr++;
        return x;
	}
	
	bool hasNext() const {
	 
        if(ptr<arraySize)
        {
            return true;
        }
        return false;
        
	}
};