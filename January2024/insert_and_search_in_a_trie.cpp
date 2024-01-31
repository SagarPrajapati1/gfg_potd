// trie node
/*
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
*/
class Solution
{
    public:
        //Function to insert string into TRIE.
        void insert(struct TrieNode *root, string key)
        {
            // code here
            int n = key.size();
            TrieNode * newNode = root;
            for(int i = 0; i < n; i++) {
                int ind = key[i]- 'a';
                if(newNode -> children[ind] == NULL) {
                    newNode -> children[ind] = new TrieNode();
                }
                newNode = newNode -> children[ind];
            }
            newNode -> isLeaf = 1;
        }
        
        //Function to use TRIE data structure and search the given string.
        bool search(struct TrieNode *root, string key) 
        {
            // code here
            
            int n = key.size();
            TrieNode *newNode = root;
            for(int i = 0; i < n; i++) {
                int ind = key[i]-'a';
                if(newNode -> children[ind] == NULL) return 0;
                
                newNode = newNode -> children[ind];
            }
            return (newNode -> isLeaf == 1);
            
        }
};
