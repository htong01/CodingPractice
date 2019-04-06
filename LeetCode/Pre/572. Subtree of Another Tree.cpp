参考 100. Same Tree

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if(!s || !t) return false;
        return isSubtree(s->left, t) || isSubtree(s->right, t) || isEqual(s, t);
    }
    
    bool isEqual(TreeNode* s, TreeNode* t){
        if(!s && !t) return true;
        if(!s || !t) return false;
        return (s->val == t->val) && isEqual(s->left, t->left) && isEqual(s->right, t->right);
    }

};
