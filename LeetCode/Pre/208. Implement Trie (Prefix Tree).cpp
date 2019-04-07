应用：211， 212 
欠的债总是要还的，Trie/Prefix tree好像还挺重要，应该挺多题里都会用到的：used for retrieval of a key in a dataset of strings.
注意⚠️：C++有constructor就要写destructor，防止memory leak，而且不要一个套一个的写，所以就没在TrieNode里面加destructor，容易写乱。上学期EE200有次作业我就那么些的，被蒋老师疯狂批一顿，全给删了_(:з」∠)_


Insertion:
Time complexity : O(m), where m is the key length.
In each iteration of the algorithm, we either examine or create a node in the trie till we reach the end of the key.
Space complexity : O(m).
In the worst case newly inserted key doesn't share a prefix with the the keys already inserted in the trie. We have to add m new nodes


Search for a key:
Time complexity : O(m) 
In each step of the algorithm we search for the next key character. In the worst case the algorithm performs m operations.
Space complexity : 
O(1)

Search for a key prefix:
Time complexity : O(m) 
Space complexity : O(1)
---------------------------------------------------------------------------------------------------------------------------
class TrieNode{
public:
    TrieNode* next[26];
    bool is_word;
    TrieNode(bool b = false){
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie {
private:
    TrieNode* root;
    
    void clear(TrieNode* root){
        for(int i=0;i<26;i++){
            if(root->next[i] != NULL) clear(root->next[i]);
        }
        delete root;
    }
    
    TrieNode* find(string key){
        TrieNode* p = root;
        for(int i=0;i<key.length() && p!=NULL; ++i)
            p = p->next[key[i] - 'a'];
        return p;
    }
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode;
    }
    ~Trie() {
        clear(root);
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for(int i=0;i<word.length();++i){
            if(p->next[word[i] - 'a'] == NULL)
                p->next[word[i] - 'a'] = new TrieNode();
            p = p->next[word[i] - 'a'];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = find(word);
        return p!=NULL && p->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != NULL;
    }
};
