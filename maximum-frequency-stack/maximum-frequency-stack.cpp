class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    int maxFreq;
    
    FreqStack() {
        freq.clear();
        group.clear();
        maxFreq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        int x = freq[val];
        maxFreq = max(maxFreq, x);
        group[x].push(val);
    }
    
    int pop() {
        int result = group[maxFreq].top();
        group[maxFreq].pop();
        freq[result]--;
        if (group[maxFreq].size() == 0) {
            maxFreq--;
        }
        return result;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */