#include <bits/stdc++.h>
using namespace std;


/*
First of all, if an−1>an, then the answer is −1 since we can't change the last two elements.

If an≥0, there exists a simple solution: perform the operation (i,n−1,n) for each 1≤i≤n−2.

Otherwise, the answer exists if and only if the initial array is sorted.

Proof:

Assume that an<0 and we can sort the array after m>0 operations.

Consider the last operation we performed (xm,ym,zm). Since all elements should be negative after 
the last operation, so azm<0 should hold before the last operation. But axm=aym−azm>aym after this, 
so the array isn't sorted in the end. By contradiction, we have proved that we can't perform any operations 
as long as an<0.
*/

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (a[n - 2] > a[n - 1]) {
            cout << -1 << endl;
        } else {
            if (a[n - 1] < 0) {
                if (is_sorted(a.begin(), a.end())) {
                    cout << 0 << endl;
                } else {
                    cout << -1 << endl;
                }
            } else {
                cout << n - 2 << endl;
                for (int i = 1; i <= n - 2; ++i) {
                    cout << i << ' ' << n - 1 << ' ' << n << endl;
                }
            }
        }
    }
}
