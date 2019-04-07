// Brute force solution: O(n^3) in time complexity
// Divide and Conquer method can reduce time complexity T(N) = 8T(N/2) + O(N^2), which also lead to O(n^3)
#include <iostream> 
#include <algorithm>
using namespace std; 

int main() 
{ 
    // int mat1[][2] = { { 2, 4 }, { 3, 4 } }; 
    // int mat2[][2] = { { 1, 2 }, { 1, 3 } }; 
    // int m1 = 2, m2 = 2, n1 = 2, n2 = 2; 

    int m1 = 50, m2 = 60, n1 = 60, n2 = 100;
	int mat1[m1][m2];
	memset(mat1, 1, m1*m2*sizeof(int) );
	int mat2[n1][n2];
	memset(mat2, 1, n1*n2*sizeof(int) );

	int x, i, j; 
    int res[m1][n2]; 
    for (i = 0; i < m1; i++)  { 
        for (j = 0; j < n2; j++){ 
            res[i][j] = 0; 
            for (x = 0; x < m2; x++) 
                res[i][j] += mat1[i][x] * mat2[x][j];  
        } 
    } 
    // print the result matrix
    for (i = 0; i < m1; i++){ 
        for (j = 0; j < n2; j++)
            cout << res[i][j] << " ";  
        cout << "\n"; 
    } 

    return 0; 
} 