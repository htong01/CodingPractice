DFS/BFS: topoligical sort, 大多用BFS
1.convert words vector into a graph. 图的关系可以用hashmap来描述 map<char, set<char>>
2.simply get the result by topological sort.
https://leetcode.com/problems/alien-dictionary/discuss/157298/C%2B%2B-BFS-and-Topoligical-Sort-with-explanation
看着答案勉强能写出来而已

class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.size() == 0) return "";
        unordered_map<char, unordered_set<char> > graph;
        unordered_map<char, int> indegree;
        
        // initialize
        for(string &word:words){
            for(char &c:word)
                indegree[c] = 0;
        }
        
        // build graph
        for(int i=0;i<words.size() - 1;i++){
            string curr = words[i];
            string next = words[i+1];
            int len = min(curr.length(), next.length());
            for(int j=0;j<len;j++){
                if(curr[j] != next[j]){
                    unordered_set<char> set = graph[curr[j]];
                    if(set.find(next[j]) == set.end()){
                        graph[curr[j]].insert(next[j]);
                        indegree[next[j]]++;
                    }
                    break;
                }
            }
        }
        
        // topological sort
        string ans;
        queue<char> q;
        for(auto &e: indegree){
            if(e.second == 0)
                q.push(e.first);
        }
        while(!q.empty()){
            char cur = q.front();
            q.pop();
            ans += cur;
            
            if(graph[cur].size() != 0 ){
                for(auto &e: graph[cur]){
                    indegree[e]--;
                    if(indegree[e] == 0)
                        q.push(e);
                }
            }
        }
        return ans.length() == indegree.size() ? ans:"";
    }
};
