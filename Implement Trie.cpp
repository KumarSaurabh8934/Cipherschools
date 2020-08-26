class Trie_node {
    public :
        vector <Trie_node*> next;
        bool end;
    
        Trie_node()
        {
            next = vector<Trie_node*>(26, NULL);
            end = false;
        }
};

class Trie {
public:
    Trie_node* root;
    
    /** Initialize your data structure here. */
    Trie() 
    {
        root = new Trie_node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        Trie_node* node = root;
        
        for(auto c : word)
        {
            if(node->next[c-'a'] == NULL)
                node->next[c-'a'] = new Trie_node();
            node = node->next[c-'a'];
        }
        
        node->end = true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        Trie_node* node = root;
        for(auto c : word)
        {
            if(node->next[c-'a'] == NULL)
                return false;
            
            node = node->next[c-'a'];
        }
        
        if(node->end == true and node!= NULL)
            return true;
        else
            return false;
    }
    

    {
        Trie_node* node = root;
        
        for(auto c: prefix)
        {
            if(node->next[c-'a'] == NULL)
                return false;
            
            node = node->next[c-'a'];
        }
        
        return true;
        
    }
};
