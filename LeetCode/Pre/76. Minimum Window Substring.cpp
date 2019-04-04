Sliding Window的题，就用两个pointer, left and right来创建window
Hashmap来存第一个string window里出现字母的次数，循环完再来check第二个string里的字母是否出现过
但要怎么判断往左移or右移？
且大概也不是O(n)解

先把t里的存了！再过一遍s看是不是都出现过！！！

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c:t) map[c]++;
        int cnt = t.length();
        int begin = 0, end = 0, d = INT_MAX, head = 0;
        while(end < s.length()){
            if(map[s[end++]] --> 0) cnt--;
            while(cnt == 0){ // valid
                if(end-begin < d) d = end - (head=begin);
                if(map[s[begin++]]++ == 0) cnt++;
            }
        }
        return d == INT_MAX ? "":s.substr(head, d);
    }
};
