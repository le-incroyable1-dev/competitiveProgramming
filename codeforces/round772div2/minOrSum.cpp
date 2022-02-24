#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main () {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        
        int ans = 0;

        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            ans |= x;
        }

        cout << ans << endl;

    }
}
