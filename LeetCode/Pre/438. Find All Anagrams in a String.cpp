HashMap, still like sliding window
还是挺神奇的，不知道怎么改着改着就改对了_(:з」∠)_

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> map(128,0);
        // unordered_map<char,int> map;
        for(auto c:p) map[c]++;
        vector<int> res;
        int cnt = p.length(), end = 0, begin = 0;
        while(end<s.size()){
            if(map[s[end++]]-->0) cnt--;
            while(cnt == 0) {
                if(end - begin == p.length()) res.push_back(begin);
                if(map[s[begin++]]++==0) cnt++;
            }
        }
        return res;
    }
};
