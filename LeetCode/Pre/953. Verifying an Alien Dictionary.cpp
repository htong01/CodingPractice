没有很明白题目在问啥

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int map[26];
        for(int i=0;i<26;i++)
            map[order[i]-'a'] = i;
        for(auto &word:words){               // word和c都要加reference，不然会有test case不过的！为什么哦！！永远都弄不明白C++的指针和内存
            for(auto &c:word)
                c = map[c-'a'];
        }
        return is_sorted(words.begin(),words.end());
    }
};
