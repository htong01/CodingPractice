仿佛不难，但是很懵

class Solution {
private:
    unordered_map<Node*, Node*> mp;
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        
        if(mp.find(node) == mp.end()) {
            mp[node] = new Node(node->val, {});
            for(Node* n : node->neighbors)
                mp[node] -> neighbors.push_back(cloneGraph(n));
        }
        return mp[node];
    }
};
