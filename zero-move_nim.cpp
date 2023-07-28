#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

char zeroMoveNim(vector<int> p) {
    int n = p.size();
    int xv = 0;
    for(auto val : p){ val%2 == 0 ? xv ^= val-1 : xv ^= val+1; }
    
    if(xv == 0) return 'L';
    else return 'W';
}
