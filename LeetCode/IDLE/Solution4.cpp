// Longest common substring
// Dynamic programing solution

// Time complexity is O(m*n)
// Space complexity is O(n)
#include <string>
#include <iostream>
using namespace std; 
  
string LCSubStr(string X, string Y) 
{ 
    int m = X.length(); 
    int n = Y.length(); 
    int result = 0; 
    int end; 
    int len[2][n]; 
    int currRow = 0; 

     for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            if (i == 0 || j == 0) { 
                len[currRow][j] = 0; 
            } 
            else if (X[i - 1] == Y[j - 1]) { 
                len[currRow][j] = len[1 - currRow][j - 1] + 1; 
                if (len[currRow][j] > result) { 
                    result = len[currRow][j]; 
                    end = i - 1; 
                } 
            } 
            else { 
                len[currRow][j] = 0; 
            } 
        } 
        // Make current row as previous row and 
        // previous row as new current row. 
        currRow = 1 - currRow; 
    } 
  
    // If no common substring, print -1. 
    if (result == 0) { 
        return "-1"; 
    } 
    // Longest common substring
    return X.substr(end - result + 1, result); 
} 

int main() 
{ 
    string str1 = "abbcdefffde";
    string str2 = "ccddeffab";
    cout << LCSubStr(str1, str2) << endl; 
    return 0; 
} 
