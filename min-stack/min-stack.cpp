class MinStack {
private:
    stack<int> data;
    stack<pair<int, int>> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        data.push(val);
        if (minStack.empty() || val < minStack.top().first) {
            minStack.push(make_pair(val, 1));
        }
        else if (val == minStack.top().first) {
            minStack.top().second++;
        }
    }
    
    void pop() {
        if (data.top() == minStack.top().first) {
            minStack.top().second--;
        }
        if (minStack.top().second == 0) {
            minStack.pop();
        }
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return minStack.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */