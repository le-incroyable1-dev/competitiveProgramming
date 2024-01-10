
#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

int n, m, arr[MAX_N], st[4 * MAX_N];

 
void build(int node, int start, int end, int &flag) {
    if (start == end) {
        st[node] = arr[start];
        flag = 0; // signals to take or next
        return;
    }

    int mid = (start + end) / 2;
    build(2 * node, start, mid, flag);
    build(2 * node + 1, mid + 1, end, flag);
    //st[node] = min(st[2 * node], st[2 * node + 1]);

    if(!flag){
        st[node] = st[2*node] | st[2*node + 1];
        flag = 1; // signals to take xor next
    }
    else if(flag == 1){
        st[node] = st[2*node] ^ st[2*node + 1];
        flag = 0; // signals to take or next
    }
}
 
void update(int node, int start, int end, int idx, int val, int &flag) {
    if (start == end) {
        arr[idx] = val;
        st[node] = val;
        flag = 0; // signals to take or next
        return;
    }


    int mid = (start + end) / 2;
    if (idx <= mid) update(2 * node, start, mid, idx, val, flag);
    else update(2 * node + 1, mid + 1, end, idx, val, flag);
    
    if(!flag){
        st[node] = st[2*node] | st[2*node + 1];
        flag = 1; // signals to take xor next
    }
    else if(flag == 1){
        st[node] = st[2*node] ^ st[2*node + 1];
        flag = 0; // signals to take or next
    }
}
 
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= (1 << n) ; i++) cin >> arr[i];

    int flag = -1; // not set yet
    build(1, 1, (1 << n), flag);
    
    while (m--) {
        int p, b; cin >> p >> b;

        int f = -1; // not set yet

        update(1, 1, (1 << n), p, b, f);
        cout << st[1] << "\n";
        
    }
}

int main() {
    cout << flush;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    solve();
    
}
