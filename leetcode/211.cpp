#include <bits/stdc++.h>
using namespace std;

class TrieNode{

public:

    TrieNode* child[26];
    bool word;

    TrieNode(){
        word = false;
        for(int i = 0; i < 26; ++i)
        child[i] = NULL;
    }

};

class WordDictionary {

private:
    
    TrieNode* root = new TrieNode();
    bool search(const char* word, TrieNode* node) {
        for (int i = 0; word[i] && node; i++) {
            if (word[i] != '.') {
                node = node -> child[word[i] - 'a'];
            } else {
                TrieNode* tmp = node;
                for (int j = 0; j < 26; j++) {
                    node = tmp -> child[j];
                    if (search(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }

        return node && node -> word;
    }

public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {

        TrieNode *cur = root;
        for(auto c : word){
            if(cur->child[c - 'a'] != NULL){
                cur = cur->child[c-'a'];
            }
            else{
                cur->child[c-'a'] = new TrieNode();
                cur = cur->child[c-'a'];
            }

            
        }
        cur->word = true;
    }
    
    bool search(string word) {
        return search(word.c_str(), root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
