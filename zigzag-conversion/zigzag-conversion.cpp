class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ans = "";
        int x = 2*numRows - 2, y = 0;
        for(int i = 0; i < numRows; i++) {
            int j = i;
            int flag = true;
            while(j < s.size()) {
                ans += s[j];
                if(x != 0 && (flag || y == 0)) j += x;
                else j += y;
                flag = !flag;
            }
            x -= 2;
            y += 2;
        }
        return ans;
    }
};