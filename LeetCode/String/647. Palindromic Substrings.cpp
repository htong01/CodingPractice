/*
memset in C++: 初始化时候用
memset( void* str, int ch, size_t n);
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
bool P[n][n]; 
memset(P, false , sizeof(P)); 

DP solution: 
build a table with all possible string[start:end] combinations, storing which are palindromes and which are not (True or False). 
At any given moment, when you're checking if string[i:j] is a palindrome, you only need to know two things:

(1) Is string[i] equal to string[j]?
(2) Is string[i+1:j-1] a palindrome?
For condition (1), a simple check might do, for condition (2), you use the table. 
If both conditions are met, mark table[i][j] as True and increase your count.
分了三种情况，字母自己本身（table中的对角线），两个字母（一样），三个及以上的：DP

*/
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;
        bool table[n][n];
        memset(table, false, sizeof(table));
        for(int i=0;i<n;i++){
            table[i][i] = true;
            cnt += 1;
        }
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                table[i][i+1] = true;
                cnt += 1;
            }
        }
        for(int k=2;k<n;k++){
            for(int i=0;i<n-k;i++){
                int j = k+i;
                if(table[i+1][j-1]==true && s[i]==s[j]){
                    table[i][j] = true;
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
};
