#include <bits/stdc++.h>
using namespace std;
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }
#define all(x) (x).begin(), (x).end()
#define rep(i, N) for(int i=0;i<(N);++i)
#define rep1(i, N) for(int i=1;i<=(N);i++)
#define ll long long



int main(){

    int n;
    cin >> n;
    vector<vector<int>> v(n+1);
    int u,k;
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        v[u].resize(k);
        cins(all(v[u]));
    }

    queue<int> que;
    que.push(1);
    vector<int> ans(n+1, -1);
    int level = 0;

    while (!que.empty()) {
        int len = que.size();
        for (int i = 0; i < len; i++) {
            int idx = que.front();
            que.pop();
            if (ans[idx] == -1) ans[idx] = level;

            // Add adjacent nodes to queue
            for(auto j : v[idx]) {
                if (ans[j] != -1 ) continue;
                que.push(j);
            }
        }
        level++;
    }

    for (int i = 0; i < n; i++) {
        cout << i+1 << " " << ans[i+1] << endl;
    }
}
