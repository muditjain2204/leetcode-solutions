class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        // Search for the starting character
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int index) {
        // Base case: found all characters
        if (index == word.length()) {
            return true;
        }
        
        // Boundary checks and character match check
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }
        
        // Mark cell as visited by temporarily modifying it
        char temp = board[i][j];
        board[i][j] = '#';
        
        // Explore 4 directions (Up, Down, Left, Right)
        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);
        
        // Backtrack: restore original character
        board[i][j] = temp;
        
        return found;
    }
};