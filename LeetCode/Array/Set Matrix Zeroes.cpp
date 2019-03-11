// 最直接的解法，time O(m*n), space O(1)
// 但是在设置matrix[i][j] = INT_MAX;的时候可能遇到本身即为INT_MAX的情况，作弊解法

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return;
        int n = matrix[0].size();
        if(n == 0) return;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0) matrix[i][j] = INT_MAX;
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == INT_MAX){
                    for(int t=0;t<m;t++) if(matrix[t][j] != INT_MAX) matrix[t][j] = 0;
                    for(int t=0;t<n;t++) if(matrix[i][t] != INT_MAX) matrix[i][t] = 0;
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// ----------------------------------Another solution in Python --------------------------------
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        m = len(matrix)
        if m==0:
            return
        n = len(matrix[0])
        
        row_zero = False
        for i in range(m):
            if matrix[i][0] == 0:
                row_zero = True
        column_zero = False
        for j in range(n):
            if matrix[0][j] == 0:
                column_zero = True
                
        for i in range(1,m):
            for j in range(1,n):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        
        for i in range(1,m):
            if matrix[i][0] == 0:
                for j in range(1,n):
                    matrix[i][j] = 0
        for j in range(1,n):
            if matrix[0][j] == 0:
                for i in range(1,m):
                    matrix[i][j] = 0
        
        if row_zero:
            for i in range(m):
                matrix[i][0] = 0
        if column_zero:
            for j in range(n):
                matrix[0][j] = 0
