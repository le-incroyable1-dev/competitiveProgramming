#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> v){

    bool flag = false;

    int cur;
    int nxt;
    int nxt2;

    int changes = 0;

    for(int i = 0; i < v.size()-2; i++){

        cur = v.at(i);
        nxt = v.at(i+1);
        nxt2 = v.at(i+2);

        if(i == v.size()-3){
            if(cur < nxt){
                if(nxt > nxt2){
                    v.at(i+2) = nxt;
                    changes++;
                    continue;
                }
            }
        }

        if(cur < nxt)
        flag = true;
        else if(cur > nxt){
            
            if(flag){
                if(nxt2 > cur)
                v.at(i+1) = nxt2;
                else
                v.at(i+1) = cur;

                changes++;
            }

            flag = false;
        }
        else{
            flag = false;
            continue;
        }
    }

    cout << changes << endl;

    for(auto val : v)
    cout << val << " ";

    cout << endl;

}

int main () {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> v;

        int ele;

        for(int i = 0; i < n; i++){
            cin >> ele;
            v.push_back(ele);
        }

        solve(v);

    }

    return 0;
}
