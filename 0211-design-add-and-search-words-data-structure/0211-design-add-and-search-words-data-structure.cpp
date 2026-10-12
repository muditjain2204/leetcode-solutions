class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEndOfWord;
        
        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    
    TrieNode* root;
    
    bool searchHelper(string& word, int index, TrieNode* node) {
        for (int i = index; i < word.length(); i++) {
            char ch = word[i];
            
            if (ch == '.') {
                // If it's a dot, try searching all non-null child nodes
                for (int j = 0; j < 26; j++) {
                    if (node->children[j] != nullptr) {
                        if (searchHelper(word, i + 1, node->children[j])) {
                            return true;
                        }
                    }
                }
                return false;
            } else {
                int idx = ch - 'a';
                if (node->children[idx] == nullptr) {
                    return false;
                }
                node = node->children[idx];
            }
        }
        return node->isEndOfWord;
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */