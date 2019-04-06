recursion DFS: 贼慢的方法！Runtime: 388 ms

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()) return true;
        if(board.empty() ||board[0].empty()) return false;
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j) // 注意这里是++i和++j，如果有i++会答案错的，没想明白为什么
                if(dfs(board, word, 0, i, j) ) return true;
        }
        return false;
    }
    bool dfs(vector<vector<char> >&board, string word, int k, int i, int j){
        int n = board.size();
        int m = board[0].size();
        if(i<0 || i>=n || j<0 || j>=m || word[k]!=board[i][j])
            return false;
        if(k == word.length()-1) return true;
        
        char curr = board[i][j];
        board[i][j] = '#';
        bool next = dfs(board, word, k+1, i, j+1)
            || dfs(board, word, k+1, i, j-1)
            || dfs(board, word, k+1, i+1, j)
            || dfs(board, word, k+1, i-1, j);
        board[i][j] = curr;
        return next;
     }
};
