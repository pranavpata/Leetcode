class RLEIterator {
private: 
    vector<int> encoding;    
    int cur = 0;
    int size;
public:
    RLEIterator(vector<int>& encoding) {
        this->encoding = encoding;
        cur = 0;
        size = encoding.size();
    }
    
    int next(int n) {
        for (;cur < size && n > 0 && encoding[cur] < n; cur += 2) {
            n -= encoding[cur];
        }
        
        int result = -1;
        
        if (cur < size && encoding[cur] >= n) {
            encoding[cur] -= n;
            result = encoding[cur + 1];
            if (encoding[cur] == 0) cur += 2;
        }
        
        return result;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */