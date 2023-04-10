#include <bits/stdc++.h>
using namespace std;

struct node{

    node* next[26];
    int end;

    node(){
        end = 0;
        for(int i = 0; i < 26; ++i) next[i] = NULL;
    }

};

class Trie{

public:

    node *root;

    Trie(){ root = new node();}

    void insert(string word){
        node* cur = root;
        for(auto c : word){
            if(cur->next[c-'a'] == NULL) cur->next[c-'a'] = new node();
            cur = cur->next[c-'a'];
            
            cur->end++;
        }
        
        return;
    }

    string get_pre(string word){
        node* cur = root;
        string pre = "";
        for(auto c : word){
            cur = cur->next[c-'a'];
            pre += c;
            if(cur->end == 1) return pre;
            //return if only one word(current) was seen upto this sequence of characters
        }

        return pre;
    }


};

vector<string> prefix(vector<string> &a) {

    Trie* t = new Trie();
    vector<string> sup;  //shortest unique prefix for each word
    
    for(auto word : a) t->insert(word);
    for(auto word : a) sup.push_back(t->get_pre(word));

    return sup;
}
