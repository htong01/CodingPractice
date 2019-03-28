// Top k 系列，hashmap

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        for(auto c:s) map[c]++;
        
        auto comp = [&map] (char a, char b){
            return map[a]>map[b] || (map[a]==map[b] && a>b);
        };
        
        sort(s.begin(),s.end(),comp);
        return s;
    }
};
