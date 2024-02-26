#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'findConnectedComponents' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER_ARRAY d as parameter.
 */
using ll = long long;

vector<ll> rankv;
vector<ll> par;

void make_sets(){
    par.resize(64, 0); rankv.resize(64, 0);
    int n = par.size();
    for(int i = 0; i < n; ++i){
        par[i] = i;
    }
    return;
}

int find_set(int v){
    if(v == par[v]) return v;
    else return par[v] = find_set(par[v]);
}

void union_sets(int a, int b){
    a = find_set(a); b = find_set(b);
    if(a == b) return;
    if(rankv[a] < rankv[b])  swap(a, b); par[b] = a;
    if(rankv[a] == rankv[b]) rankv[a]++;
}


int findConnectedComponents(vector<long> d) {
    
    ll n = d.size();
    ll ans = 0;
    for(ll mask = 0; mask < (1 << n); ++mask){
        //mask represents a subset
        make_sets();

        for(int i = 0; i < 2; ++i){
            for(ll i = 0; i < n; ++i){
                if( mask >> i == 0) continue;
                if( ( (mask >> i) & 1 ) == 0) continue;
                
                ll num = d[i]; 
                ll mark = -1;
                for(ll i = 0; i < 64; ++i){
                    
                        if(num >> i == 0) continue;
                        if( ( (num >> i) & 1 ) == 0 ) continue;
                        if(mark == -1) { mark = i; continue; }
                        union_sets(i, mark);
                    
                }
            }
        }

        unordered_set<int> s;
        for(auto x : par) s.insert(x);
        ll sz = s.size();
        ans += sz;
    }
    
    return int(ans);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string d_count_temp;
    getline(cin, d_count_temp);

    int d_count = stoi(ltrim(rtrim(d_count_temp)));

    string d_temp_temp;
    getline(cin, d_temp_temp);

    vector<string> d_temp = split(rtrim(d_temp_temp));

    vector<long> d(d_count);

    for (int i = 0; i < d_count; i++) {
        long d_item = stol(d_temp[i]);

        d[i] = d_item;
    }

    int components = findConnectedComponents(d);

    fout << components << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
