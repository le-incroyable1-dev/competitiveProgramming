#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, B, x, y;
        cin >> n >> B >> x >> y;
        long long sum = 0;
        vector<int> a;
        a[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i - 1] + x <= B)
            {
                a[i] = a[i - 1] + x;
            }
            else
            {
                a[i] = a[i - 1] - y;
            }
        }
        for (int i = 0; i <= n; i++)
        {
            sum += a[i];
        }
        cout << sum << '\n';
    }
}
