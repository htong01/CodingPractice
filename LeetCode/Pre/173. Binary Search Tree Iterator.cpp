Using stack, in-order traverse

class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        find(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* top = st.top();
        st.pop();
        if(top->right) find(top->right);
        return top->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }
    void find(TreeNode* root){
        TreeNode* p = root;
        while(p != NULL){
            st.push(p);
            p = p->left;
        }
    }
};
