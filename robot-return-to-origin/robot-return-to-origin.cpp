class Solution {
public:
    bool judgeCircle(string moves) {
        int ans[4] = {0,0,0,0};
        
        for (int i = 0; i < moves.size(); i++) {
            switch(moves[i]) {
                case 'U':
                    ans[0]++;
                    break;
                case 'D':
                    ans[1]++;
                    break;
                case 'L':
                    ans[2]++;
                    break;
                case 'R':
                    ans[3]++;
                    break;
            }
        }
        
        return ((ans[0] == ans[1]) && (ans[2] == ans[3]));
    }
};