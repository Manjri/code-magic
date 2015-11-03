#include <iostream>
#include "assert.h"
using namespace std;

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// Alphabet size (#of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// Use only 'a' through 'z' - lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')


// trie node
typedef struct trie_node{
    int value;
    struct trie_node *children[ALPHABET_SIZE];
}trie_node_t;

// trie ADT
typedef struct trie{
    int count;
    trie_node_t *root;
}trie_t;

// returns a new trie node (intialized to NULLs)
trie_node_t* getNode(){
    
    trie_node_t *pNode = NULL;
    assert(pNode = (trie_node_t*) malloc(sizeof(trie_node_t)));
    
    pNode->value = 0;
    
    for(int i=0; i<ALPHABET_SIZE; i++)
        pNode->children[i] = 0;
    
    return pNode;
}

// initializes the trie (root is a dummy node)
void initialize(trie_t *pTrie){
    pTrie->root = getNode();
    pTrie->count = 0;
}

// if not present, inserts key into trie
void insert(trie_t *pTrie, char key[]){
    
    int length = strlen(key);
    trie_node_t *pCrawl;
    
    pTrie->count++;
    pCrawl = pTrie->root;
    
    
    for(int level=0; level<length; level++){
        
        int index = CHAR_TO_INDEX(key[level]);
        
        if(pCrawl->children[index] == 0){
            pCrawl->children[index] = getNode();
        }
        
        pCrawl = pCrawl->children[index];
    }
    
    // mark the last node as leaf
    pCrawl->value = pTrie->count;
}


// returns non-zero if key is present in the trie
int search(trie_t *pTrie, char key[]){

    int length = strlen(key);
    trie_node_t *pCrawl;
    
    pCrawl = pTrie->root;
    
    for(int level=0; level<length; level++){
        
        int index = CHAR_TO_INDEX(key[level]);
        
        // this character not present, hence word isnt present
        if(pCrawl->children[index] == 0)
            return 0;
        
        pCrawl = pCrawl->children[index];
    }
    
    // make sure the word is a leaf word..eg: when the key is DOGS, we dont return true for DOG
    return (pCrawl!=0 && pCrawl->value!=0);
}


// Driver
int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    trie_t trie;
    
    char output[][32] = {"Not present in trie", "Present in trie"};
    
    initialize(&trie);
    
    // Construct trie
    for(int i = 0; i < ARRAY_SIZE(keys); i++)
    {
        insert(&trie, keys[i]);
    }
    
    // Search for different keys
    printf("%s --- %s\n", "the", output[search(&trie, "the")] );
    printf("%s --- %s\n", "these", output[search(&trie, "these")] );
    printf("%s --- %s\n", "their", output[search(&trie, "their")] );
    printf("%s --- %s\n", "thaw", output[search(&trie, "thaw")] );
    
    return 0;
}