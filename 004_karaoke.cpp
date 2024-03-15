#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }
typedef long long ll;

// #full-search
// #exhaustive-search

int main(){

    int N,M;
    cin >> N >> M;
    vector<vector<int>> v (N, vector<int> (M));

    for (int i = 0; i < N; i++) {
        cins(v[i].begin(), v[i].end());
    }


    ll total_max = 0;
    for (int i = 0; i < M; i++) {
        for (int j = i+1; j < M; j++) {
            // For every song combination check the score
            ll score = 0;
            for (int s = 0; s < N; s++) {
                score += max(v[s][i], v[s][j]);
            }
            total_max = max(total_max, score);
        }
    }
    cout << total_max;
}
