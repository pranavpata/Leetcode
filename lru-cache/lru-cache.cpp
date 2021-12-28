class LRUCache {
private:
    unordered_map<int, pair<int, list<int>::iterator>> data;
    list<int> usage;
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (data.count(key) == 0) {
            return -1;
        }
        int val = data[key].first;
        auto it = data[key].second;
        usage.splice(usage.begin(), usage, it);
        data[key].second = usage.begin(); 
        
        return val;
    }
    
    void put(int key, int value) {
        if (data.count(key) == 0)
        {
            usage.insert(usage.begin(), key);
            data[key] = make_pair(value, usage.begin());                
        }
        else
        {
            data[key].first = value;
            usage.splice(usage.begin(), usage, data[key].second);  
            data[key].second = usage.begin();  
        } 
        
        // remove the least recently used
        if (data.size() > cap)
        {
            int key = usage.back();
            data.erase(key);
            usage.pop_back();
        }        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */