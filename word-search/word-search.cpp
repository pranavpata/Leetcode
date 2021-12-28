class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(isSearched(board, word, i, j))
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isSearched(vector<vector<char>>& board, string word, int i, int j)
    {
        if(word.empty()) 
            return true;
        if(i >= board.size() || j >= board[0].size() || i < 0 || j < 0)
            return false;
        if(word[0] == board[i][j])
        {
            board[i][j] = '@'; 
            if(isSearched(board, word.substr(1), i-1, j) ||    
              isSearched(board, word.substr(1), i+1, j) ||      
              isSearched(board, word.substr(1), i, j-1)||       
              isSearched(board, word.substr(1), i, j+1))       
                return true;
            board[i][j] = word[0]; 
        }
        return false;
    }
};