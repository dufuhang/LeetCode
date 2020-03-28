实现字典树
```cpp
class Trie {
private:
    bool isEnd;
    Trie* alphabet[26];
public:
    /** Initialize your data structure here. */
    Trie() 
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            alphabet[i] = nullptr;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        Trie* node = this;
        for (char ch : word)
        {
            if (node->alphabet[ch - 'a'] == nullptr)
            {
                node->alphabet[ch - 'a'] = new Trie();
            }
            node = node->alphabet[ch - 'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        Trie* node = this;
        for (char ch : word)
        {
            if (node->alphabet[ch - 'a'] == nullptr)
            {
                return false;
            }
            node = node->alphabet[ch - 'a'];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        Trie* node = this;
        for (char ch : prefix)
        {
            if (node->alphabet[ch - 'a'] == nullptr)
            {
                return false;
            }
            node = node->alphabet[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
 ```