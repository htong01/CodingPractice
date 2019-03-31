DFS recursion
但是upadte了原始的grid中的参数
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }
        return cnt;
    }
    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0)
            return;
        if(grid[i][j] != '1') return;
        grid[i][j] = '!';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
};
