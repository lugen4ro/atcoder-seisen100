#include <bits/stdc++.h>
using namespace std;
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }
#define all(x) (x).begin(), (x).end()
#define rep(i, N) for(int i=0;i<(N);++i)
#define rep1(i, N) for(int i=1;i<=(N);i++)
#define ll long long

// binary-search


int main(){

    int N,M;
    cin >> N >> M;
    vector<int> p(N);
    cins(all(p));

    vector<int> v;
    p.push_back(0);

    // Create all sums of combinations of 2
    rep(i, p.size()) {
        rep(j, p.size()) {
            v.push_back(p[i]+p[j]);
        }
    }

    // Binary search
    int max_score = 0;
    sort(all(v));
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > M) continue;
        auto it = lower_bound(all(v), M-v[i]);
        if (*it == M-v[i]) {
            // max score M
            cout << M << endl;
            return 0;
        } else {
            max_score = max(max_score, v[i]+*(it-1));
        }
    }

    cout << max_score << endl;
}
