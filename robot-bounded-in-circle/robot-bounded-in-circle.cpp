class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dir = 0; // 0 is north, 1 is east, 2 is south, 3 is west
        int x = 0; int y = 0; //starting robot position
        
        char c;
        for (int i = 0; i < instructions.size(); i++) {
            c = instructions[i];
            if (c == 'G') {
                if (dir == 0) {
                    y++;
                }
                else if (dir == 1) {
                    x++;
                }
                else if (dir == 2) {
                    y--;
                }
                else {
                    x--;
                }
            }
            else if (c== 'L') {
                dir = (dir+3)%4;
            }
            else {
                dir = (dir + 1)%4;
            }
        }
        
        return x == 0 && y == 0 || dir != 0;
    }
};