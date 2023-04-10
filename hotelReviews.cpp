#include <bits/stdc++.h>
using namespace std;


//Trie
class tn{
public:

    tn *next[26];
    bool end;

    tn(){
        for(int i = 0; i < 26; ++i) next[i] = NULL;
        end = false;
    }
};

void insert(tn *root, string word){
    tn *cur = root;

    for(int i = 0; i < word.length(); ++i){
        if(cur->next[word[i]-'a'] == NULL) cur->next[word[i]-'a'] = new tn();
        cur = cur->next[word[i]-'a'];
    }
    
    cur->end = true;
}

int good_count(tn*root, string review){
    int cnt = 0;

    tn* cur = root;
    stringstream s(review);
    string word;

    while(getline(s, word, '_')){
        for(int i = 0; i < word.length(); ++i){
            if(!cur->next[word[i]-'a']) break;
            else cur = cur->next[word[i]-'a'];
        }

        if(cur->end) ++cnt;
    }

    return cnt;
}

vector<int> solve(string s, vector<string> &b) {

    tn* root = new tn();
    vector<pair<int, int>> v;
    stringstream ss(s);
    string cur;

    while(getline(ss, cur, '_')) insert(root, cur);
    
    for(int i = 0; i < b.size(); ++i){
        string review = b[i];
        int cnt = good_count(root, review);
        //cout << i << " " << cnt << " \n";
        v.emplace_back((-1*cnt), i);
    }

    sort(v.begin(), v.end());
    vector<int> ans;

    for(auto p : v) ans.push_back(p.second);
    return ans;
}
