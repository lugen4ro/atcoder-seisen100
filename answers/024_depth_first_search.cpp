#include <bits/stdc++.h>
using namespace std;
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }
#define all(x) (x).begin(), (x).end()
#define rep(i, N) for(int i=0;i<(N);++i)
#define rep1(i, N) for(int i=1;i<=(N);i++)
#define ll long long

// DFS

int dfs(vector<vector<int>> &adj, int idx, vector<vector<int>> &ans, int time) {

    // Already discovered
    if (ans[idx-1].size() > 0) return time;

    ans[idx-1].push_back(idx); // Index
    ans[idx-1].push_back(time++); // Discover time

    rep(i, adj[idx-1].size()) {
        time = dfs(adj, adj[idx-1][i], ans, time);
    }
    ans[idx-1].push_back(time++); // Finish time

    return time;
}

int main(){

    int N;
    cin >> N;
    vector<vector<int>> adj(N);

    int idx,rank;
    rep(i, N) {
        cin >> idx >> rank;
        adj[i].resize(rank);
        rep(j, rank) {
            cin >> adj[i][j];
        }
    }

    vector<vector<int>> ans(N);
    int time = 1;
    rep(i, N) { 
        time = dfs(adj, i+1, ans, time);
    }
    rep(i, N) {
        output_array(all(ans[i]));
    }
}
