Find out the longest length of subarrays with at most 2 different numbers Pre/README.md里面的template就能解

Sliding window(hash map)

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> mp;
        int cnt = 0, end = 0, begin = 0, d = 0;
        while(end < tree.size()){
            if(mp[tree[end++]]++ == 0) cnt++;
            while(cnt > 2){
                if(mp[tree[begin++]]-- == 1) cnt--;
            }
            d = max(d, end-begin);
        }
        return d;
    }
};
