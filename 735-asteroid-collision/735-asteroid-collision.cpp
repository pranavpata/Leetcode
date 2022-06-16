class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        bool done = false;
        for (int ast: asteroids) {
            done = false;
            while (!st.empty() && st.top() > 0 && ast < 0) {
                int neg = -ast;
                if (st.top() < neg) {
                    st.pop();
                    continue;
                }
                else if (st.top() == neg) {
                    st.pop();
                }
                done = true;
                break;
            }
            if (!done) st.push(ast);
        }
        
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};