class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;
        for(auto c:s) m[c]++;
        for(int i=0;i<s.length();i++) 
            if(m[s[i]]==1) return i;
        return -1;
    }
};
/*
-----------Python Solution-----------------
class Solution:
    def firstUniqChar(self, s: str) -> int:
        for i in range(len(s)):
            c = s[i]
            if s.count(c) == 1:
                return i
        return -1
        
*/
