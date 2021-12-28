class TicTacToe {
public:
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int anti; //antidiagonal
    int size;
    
    TicTacToe(int n) {
        for (int i = 0; i < n; i++) {
            rows.push_back(0);
            cols.push_back(0);
        }
        diagonal = 0;
        anti = 0;
        size = n;
    }
    
    int move(int row, int col, int player) {
        int cur = (player == 1) ? 1 : -1;
        rows[row] += cur;
        cols[col] += cur;
        if (row == col) {
            diagonal += cur;
        }
        if (col == size - row - 1) {
            anti += cur;
        }
        if ((abs(rows[row]) == size) || (abs(cols[col]) == size) || (abs(diagonal) == size) || (abs(anti) == size)) return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */