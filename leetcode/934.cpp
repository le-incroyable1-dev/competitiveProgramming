//author : aurav
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double ld;
#define pii pair<ll,ll>
#define vi vector< ll >
#define vvi vector< vi >
#define vpi vector< pii >
#define vvpi vector< vpi >
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define test(t) ll t;cin>>t;while(t--)
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
int dir[5] = {0, 1, 0, -1, 0};
#define remax(a,b) (a=max((a),(b)))
//#define ln ListNode*
//#define tn TreeNode*
long long powerof2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};

class Solution {
public:
    
    vector<pair<int, int>> q;
    vector<vector<bool>> vis;
    bool found(int i, int j, vector<vector<int>> &grid){
        bool res = false;
        int n = grid.size();
        int m = grid[0].size();

        if(i-1 >= 0 && grid[i-1][j] == 2) res = true;
        if(i+1 < n && grid[i+1][j] == 2) res = true;
        if(j-1 >= 0 && grid[i][j-1] == 2) res = true;
        if(j+1 < m && grid[i][j+1] == 2) res = true;

        return res;
    }

    void mark(int i, int j, vector<vector<int>> &grid){
        grid[i][j] = 2;
        int n = grid.size();
        int m = grid[0].size();
        q.push_back({i, j});

        if(i-1 >= 0 && grid[i-1][j] == 1) mark(i-1, j, grid);
        if(i+1 < n && grid[i+1][j] == 1) mark(i+1, j, grid);
        if(j-1 >= 0 && grid[i][j-1] == 1) mark(i, j-1, grid);
        if(j+1 < m && grid[i][j+1] == 1) mark(i, j+1, grid);

        return;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vis.resize(n, vector<bool>(m, false));

        bool marked = false;
        fr(i, n){
            if(marked) break;
            fr(j, m){
                if(grid[i][j] == 1){
                    marked = true;
                    mark(i, j, grid);
                    break;
                }
            }
        }

        // fr(i, n){
        //     fr(j, m) cout << grid[i][j] << " ";
        //     cout << "\n";
        // }

        int d = 0;

        while (!q.empty()) {
            vector<pair<int, int>> q1;
            for (auto [i, j] : q) {
                for (int d = 0; d < 4; ++d) {
                    int x = i + dir[d], y = j + dir[d + 1];
                    if (min(x, y) >= 0 && max(x, y) < grid.size()) {
                        if (grid[x][y] == 1)
                            return grid[i][j] - 2;
                        if (grid[x][y] == 0) {
                            grid[x][y] = grid[i][j] + 1;
                            q1.push_back({x, y});
                        }
                    }
                }
            }
            swap(q, q1);
        }

        return -1;

    }
};
