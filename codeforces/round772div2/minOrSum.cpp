#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
The answer is a1|a2|⋯|an. Here is the proof:

Let m=a1|a2|⋯|an. After an operation, the value m won't change.

Since, a1|a2|⋯|an ≤ a1+a2+⋯+an, the sum of the array has a lower bound of m. 
And this sum can be constructed easily: for all i∈[1,n−1], set ai+1 to ai|ai+1 and ai to 0.
*/

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
