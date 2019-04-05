Graph的题就是BFS/DFS
DFS solution: 红蓝交替着一层层涂颜色
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        for(int i=0;i<n;i++){
            if(!color[i]){
                color[i] = 1;
                queue<int> todo;
                todo.push(i);
                while(!todo.empty()){
                    int node = todo.front();
                    todo.pop();
                    for(int neighbour: graph[node]){
                        if(!color[neighbour]){
                            color[neighbour] = -color[node];
                            todo.push(neighbour);
                        }
                        else if(color[neighbour] == color[node])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
