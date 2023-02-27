#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;

        int N = n*m;

        vector<int> g[N];

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){

                int index = m*i + j;

                if(i-1 >= 0) g[index].push_back(m*(i-1)+j);
                if(j-1 >= 0) g[index].push_back(m*i + j-1);
                if(i+1 < n) g[index].push_back(m*(i+1) + j);
                if(j+1 < m) g[index].push_back(m*i + j+1);

            }
        }

        vector<bool> processed(N, false);
        vector<int> time(N, INT_MAX);

        time[0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0});
        //int time = 0;

        while(!pq.empty()){

            vector<int> cur = pq.top(); pq.pop();

            int cur_time = cur[0];
            int cur_node = cur[1];

            if(processed[cur_node]) continue;
            processed[cur_node] = true;

            //cout << cur_node << " " << cur_time << " -" << "\n";


            for(auto v : g[cur_node]){



                int i = v/m;
                int j = v%m;

                //cout << i << " " << j << "\n";

                int next_time = cur_time + 1;

                if(next_time >= grid[i][j]){

                    if(time[v] > next_time){
                        time[v] = next_time;
                        pq.push({time[v], v});
                    }

                }
                else{
                    int rem_time = grid[i][j] - next_time;
                    next_time += rem_time + (rem_time%2!=0);

                    if(time[v] > next_time){
                        time[v] = next_time;
                        pq.push({time[v], v});
                    }
                }

                continue;


            }

            continue;
        }



        //for(auto val : time) cout << val << " "; cout << "\n";

        int ans = time[N-1];
        return ans;


    }
};
