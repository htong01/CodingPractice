class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<int, int> cnt;
        for(int i=0;i<s.length();i++){
            cnt[s[i]]++;
            cnt[t[i]]--;
        }
        for(auto count:cnt){
            if(count.second) return false;  // unorder_map it.first: key, it.second: value
        }
        return true;
    }
};

---------------Python Solution----------------
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dic1, dic2 = {}, {}
        for item in s:
            dic1[item] = dic1.get(item,0) + 1
        for item in t:
            dic2[item] = dic2.get(item,0) + 1
        return dic1 == dic2
