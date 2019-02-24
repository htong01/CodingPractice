// DP解法https://leetcode.com/problems/longest-palindromic-substring/discuss/147548/Direct-c%2B%2B-DP

// O(n^2) for both time and space complexity

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n <= 1) return s;
        bool P[n][n] = {false};
        // initialize top right half of P[n][n]
        for(int x=0;x<n;x++){
            P[x][x] = true;
            if(x==n-1) break; // right bottom corner
            P[x][x+1] = (s[x]==s[x+1]);
        }
        // dp
        for(int i=n-1;i>=0;--i){
            for(int j=i+2;j<n;++j){
                P[i][j] = (P[i+1][j-1] && s[i]==s[j]); // P[i][j] = (s[i]==s[j]); 会在整个string本身就满足条件时报错
            }
        }
        
        // get max
        int max = 0;
        string maxstr = "";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(P[i][j] == true && (j-i+1)>max){
                    max = j-i+1;
                    maxstr = s.substr(i,j-i+1);
                }
            }
        }
        return maxstr;
        
    }
};
