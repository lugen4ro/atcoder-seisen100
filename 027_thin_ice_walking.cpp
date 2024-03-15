#include <bits/stdc++.h>
using namespace std;
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }
#define all(x) (x).begin(), (x).end()
#define rep(i, N) for(int i=0;i<(N);++i)
#define rep1(i, N) for(int i=1;i<=(N);i++)
#define ll long long

// #binary-search

int N, M;
vector<vector<int>> v;
int ans = 0;
set<pair<int,int>> visited;

void dfs(int r, int c, int len) {

    // Invalid
    if ((r<0 or c<0 or r>=N or c>=M) or (v[r][c] == 0) or (visited.count(make_pair(r,c)) > 0)) return;

    // Add this one
    len += 1;
    visited.insert(make_pair(r, c));
    ans = max(ans, len);

    vector<vector<int>> move = {{-1,0},{0,-1},{1,0},{0,1}};
    for(auto m : move) {
        dfs(r+m[0], c+m[1], len);
    }

    visited.erase(make_pair(r,c));
}

int main(){

    cin >> M >> N;
    v.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        cins(all(v[i]));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dfs(i,j,0);
            visited.clear();
        }
    }
    cout << ans << endl;



    
}
