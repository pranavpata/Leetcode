class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        //X is 1, O is -1, empty space is 0
        int newB[3][3] = {};
        int total = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 'X') {
                    newB[i][j] = 1;
                    total++; 
                }
                else if (board[i][j] == 'O') {
                    newB[i][j] = -1;
                    total--;
                }
            }
        }
        
        //O played last
        cout << total;
        if (total == 0) {
            //X can't win
            for (int i = 0; i < 3; i++) {
                if (newB[i][0] + newB[i][1] + newB[i][2] == 3 ||
                   newB[0][i] + newB[1][i] + newB[2][i] == 3) return false;
            }
            
            int diag1 = 0, diag2 = 0;
            for (int i = 0; i < 3; ++i) {
                diag1 += newB[i][i];
                diag2 += newB[i][2 - i];
            }
            if (diag1 == 3 || diag2 == 3) return false;
            
            return true;
        }
        //X played last
        else if (total == 1) {
            //O can't win
            for (int i = 0; i < 3; i++) {
                if (newB[i][0] + newB[i][1] + newB[i][2] == -3 ||
                   newB[0][i] + newB[1][i] + newB[2][i] == -3) return false;
            }
            
            int diag1 = 0, diag2 = 0;
            for (int i = 0; i < 3; ++i) {
                diag1 += newB[i][i];
                diag2 += newB[i][2 - i];
            }
            if (diag1 == -3 || diag2 == -3) return false;
            
            return true;
        }
        return false;
    }
};