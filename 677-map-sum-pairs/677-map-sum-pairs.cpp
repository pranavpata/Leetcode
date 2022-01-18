class MapSum {
private:
    unordered_map<string, int> mpp;
public:
    MapSum() {}
    
    void insert(string key, int val) {
        mpp[key] = val;
    }
    
    int sum(string prefix) {
        int result = 0;
        for (auto el : mpp) {
            string key = el.first;
            if (key.substr(0, prefix.size()) == prefix) {
                result += mpp[key];
            }
        }
        return result;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */