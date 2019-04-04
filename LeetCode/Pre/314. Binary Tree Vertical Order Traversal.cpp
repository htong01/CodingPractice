HashMap, BFS

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root == NULL) return res;
        
        map<int, vector<int> > mp;
        queue<pair<int, TreeNode*> > q;
        q.push(make_pair(0, root));
        while(!q.empty()){
            TreeNode* t = q.front().second;
            int temp = q.front().first;
            q.pop();
            mp[temp].push_back(t->val);
            if(t->left)
                q.push(make_pair(temp-1, t->left));
            if(t->right)
                q.push(make_pair(temp+1, t->right));
        }
        
        for(auto &v:mp)
            res.push_back(v.second);
        return res;
    }
};
