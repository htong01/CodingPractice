Implentation of Trie/Prefix Tree
Search()没写明白，剩下都是照着208抄了
而且跑的贼慢，time and space complexity都是垫底的_(:з」∠)_

class TrieNode {
public:
    bool is_word;
    TrieNode* next[26];
    TrieNode(bool b = false){
        is_word = b;
        memset(next, 0, sizeof(next));
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode;
    }
    ~WordDictionary() {
        clear(root);
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for(int i=0;i<word.length();++i){
            if(p->next[word[i] - 'a'] == NULL)
                p->next[word[i]-'a'] = new TrieNode;
            p = p->next[word[i] - 'a'];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, root);
    }
private:
    TrieNode* root;
    
    void clear(TrieNode* root){
        for(int i=0;i<26;i++){
            if(root->next[i] != NULL) clear(root->next[i]);
        }
        delete root;
    }
    bool search(string word, int pos, TrieNode* root) {
        if(pos == word.length()) return root->is_word;
        if(word[pos] != '.'){
            if(!root->next[word[pos]-'a']) return false;
            if(pos==word.length()-1 && root->next[word[pos]-'a']->is_word)
                return true;
            return search(word,pos+1,root->next[word[pos]-'a']);
        }
        else{
            for(TrieNode* p : root->next){
                if(p){
                    if(pos == word.length()-1 && p->is_word) return true;
                    if(search(word, pos+1, p) ) return true;
                }
            }
            return false;
        }
    }
};
