写法挺简洁清晰的，是我自己写不出来的码

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return mydeserialize(data);
    }
    
    TreeNode* mydeserialize(string& data){
        if(data[0] == '#'){
            if(data.size()>1) data = data.substr(2);
            return nullptr;
        }
        else{
            TreeNode* node = new TreeNode(helper(data));
            node->left = mydeserialize(data);
            node->right = mydeserialize(data);
            return node;
        }
    }
private:
    int helper(string& data){
        int pos = data.find(',');
        int val = stoi(data.substr(0,pos));
        data = data.substr(pos+1);
        return val;
    }
};
-----------------------------------------------------------------------------------------------
Using stringstream，更快更短更强
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#") return NULL;
        stringstream s(data);
        return mydeserialize(s);
    }
    
    TreeNode* mydeserialize(stringstream& s){
        string str;
        getline(s, str, ',');
        if(str == "#") return NULL;
        else{
            TreeNode* node = new TreeNode(stoi(str));
            node->left = mydeserialize(s);
            node->right = mydeserialize(s);
            return node;
        }
        
    }
};
