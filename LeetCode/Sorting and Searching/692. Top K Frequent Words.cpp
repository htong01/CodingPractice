和Top K frequent element解法思路相同，但写起来稍微复杂一点，priority queue max heap的时候要加一个自己写的比较的function

emplace() 和make_pair类似

class Solution {
public:
    struct Comp {
        bool operator() (const pair<int,string>& lhs, const pair<int,string>& rhs) const{
            if(lhs.first != rhs.first)
                return lhs.first < rhs.first;
            return lhs.second > rhs.second;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        for(auto w:words) map[w]++;
        
        vector<string> ans;
        priority_queue<pair<int,string>, vector<pair<int,string> >, Comp> Q;
        for(auto it:map)
            Q.emplace(it.second, it.first);
        while(k-->0 && !Q.empty()){
            ans.push_back(Q.top().second);
            Q.pop();
        }
        return ans;
    }
};
