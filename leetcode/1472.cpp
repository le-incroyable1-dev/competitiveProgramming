#include <bits/stdc++.h>
using namespace std;


class mylist {
public:

    string url;
    mylist *prev, *next;

    mylist(string url){
        this->url = url;
        prev = NULL;
        next = NULL;
    }

};

class BrowserHistory {
public:

    mylist* cur;
    BrowserHistory(string homepage) {
        cur = new mylist(homepage);
    }
    
    void visit(string url) {
        mylist *vis = new mylist(url);

        cur->next = vis;
        vis->prev = cur;
        
        cur = cur->next;
    }
    
    string back(int steps) {
        while(steps > 0){
            if(cur->prev == NULL) break;
            else cur = cur->prev, steps--;
        }

        return cur->url;
    }
    
    string forward(int steps) {
        while(steps > 0){
            if(cur->next == NULL) break;
            else cur = cur->next, steps--;
        }

        return cur->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
