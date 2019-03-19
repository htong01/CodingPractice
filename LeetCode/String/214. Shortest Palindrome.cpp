class Solution {
public:
    string shortestPalindrome(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int n = s.size();
        int i;
        for(i=n;i>=0;i--){
            if(s.substr(0,i) == s2.substr(n-i))
                break;
        }
        return s2.substr(0,n-i) + s;
    }
};
