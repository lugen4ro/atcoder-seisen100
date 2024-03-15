#include <bits/stdc++.h>
using namespace std;
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }
#define all(x) (x).begin(), (x).end()
#define rep(i, N) for(int i=0;i<(N);++i)
#define rep1(i, N) for(int i=1;i<=(N);i++)
#define ll long long

// #DFS


int w,h;
set<pair<int,int>> visited;
vector<vector<int>> v;
int ans;



int dfs(int r, int c) {

    // Out of bounds / Already visited / Sea
    if (!(r >= 0 and r < h and c >= 0 and c < w) or (visited.count(make_pair(r,c)) > 0) or (v[r][c]==0)) return 0;

    // Add to visited
    visited.insert(make_pair(r,c));

    vector<vector<int>> move = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    for(auto m : move) {
        dfs(r+m[0], c+m[1]);
    }

    // 1 island
    return 1;
}


int main(){

    cin >> w >> h;
    while (!(w==0 and h==0)) {

        // Input
        v.resize(h, vector<int>(w));
        rep(i, h) cins(all(v[i]));

        // Count
        rep(i, h) {
            rep(j, w) {
                ans += dfs(i, j);
            }
        }
        cout << ans << endl;

        // Clean up and prep for next
        v.clear();
        visited.clear();
        ans = 0;
        cin >> w >> h;
    }
}
