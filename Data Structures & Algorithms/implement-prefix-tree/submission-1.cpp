class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++) children[i] = NULL;
        isTerminal = false;
    }
};

class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word){
        if(word.size()==0){
            root->isTerminal = true;
            return;
        }
        int idx = word[0] - 'a';
        TrieNode* child;
        if(root->children[idx]){
            child = root->children[idx];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[idx] = child;
        }

        insertUtil(child, word.substr(1));
    }
    void insert(string word) {
        insertUtil(root,word);
    }
    
    bool searchUtil(TrieNode* root, string word){
        if(word.size()==0){
            return root->isTerminal;
        }
        int idx = word[0]-'a';
        TrieNode* child;
        if(root->children[idx]){
            child = root->children[idx];
        }
        else return false;

        return searchUtil(child, word.substr(1));
    }
    bool search(string word) {
        return searchUtil(root, word);
    }
    
    bool prefixUtil(TrieNode* root, string word){
        if(word.size()==0){
            return true;
        }
        int idx = word[0]-'a';
        TrieNode* child;
        if(root->children[idx]){
            child = root->children[idx];
        }
        else return false;

        return prefixUtil(child, word.substr(1));
    }
    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */