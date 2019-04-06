DP题

class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.empty() && p.empty()) return true;
                
        int m = s.size(), n = p.size();
        vector<vector<bool> > table(m+1, vector<bool>(n+1, false));
        table[0][0] = true;
        for(int i=1;i<=m;i++)
            table[i][0] = false;
        for(int j=1;j<=n;j++)
            table[0][j] = j>1 && p[j-1] == '*' && table[0][j-2];
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1] != '*')
                    table[i][j] = table[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.');
                else
                    table[i][j] = table[i][j-2] || ((s[i-1] == p[j-2] || p[j-2]=='.') && table[i-1][j]);
            }
        }
        return table[m][n];
    }
};
