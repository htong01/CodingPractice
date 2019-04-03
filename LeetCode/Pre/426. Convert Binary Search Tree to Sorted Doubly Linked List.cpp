In-order traversal
题目上配图有挺多帮助的，看着图想左右
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        Node* prev = NULL;
        Node* head = NULL;
        inOrder(prev, head, root);
        prev->right = head; 
        head->left = prev;
        return head;
    }
    void inOrder(Node* &prev, Node* &head, Node* root){
        if(!head && !root->left){
            prev = root;
            head = root;
        }
        Node* left = root->left;
        Node* right = root->right;
        if(left) inOrder(prev, head, left);
        prev->right = root;
        root->left = prev;
        prev = root;
        if(right) inOrder(prev, head, right);
    }
};
