#include <bits/stdc++.h>
using namespace std;
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }
#define all(x) (x).begin(), (x).end()
#define rep(i, N) for(int i=0;i<(N);++i)
#define rep1(i, N) for(int i=1;i<=(N);i++)
#define ll long long


int N,Q;
int p, x;
unordered_map<int, vector<int>> m;
vector<int> cnt;
set<int> visited;

void dfs(int idx, int amount) {
    if (visited.count(idx) > 0) return;
    visited.insert(idx);
    cnt[idx-1] += amount;
    for(auto i : m[idx]) {
        dfs(i, cnt[idx-1]);
    }
}

int main(){

    // Input
    cin >> N >> Q;
    int a,b;
    rep(i, N-1) {
        cin >> a >> b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    cnt.resize(N, 0);

    rep(i, Q) {
        cin >> p >> x;
        cnt[p-1] += x;
    }

    // dfs 
    dfs(1, 0);

    // Print
    output_array(all(cnt));
}
