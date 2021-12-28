class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.size(); i++) {
            char c = s[i];
            if (!st.empty()) {
                char top = st.top();
                if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{'))
                    st.pop();
                else {
                    st.push(c);
                }
            }
            else {
                st.push(c);
            }
        }
        return st.empty();
    }
};