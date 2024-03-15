#include <bits/stdc++.h>
using namespace std;
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }
#define all(x) (x).begin(), (x).end()
#define rep(i, N) for(int i=0;i<(N);++i)
#define rep1(i, N) for(int i=1;i<=(N);i++)
#define ll long long
#define bc(var, lower, upper) (var>=lower and var<upper) // Boundary check of var with [lower, upper) --> True when within bounds
#define bcn(var, lower, upper) (var<lower or var>=upper) // Boundary check of var with [lower, upper) --> True when outside of bounds
#define bitcount(n) __builtin_popcountl(long(n))
#define vin(v, N) rep(i,R) rep(j,N) cin >> v[i][j]; // Input 1-d vector
#define vin2(v, N, M) rep(i,N) rep(j,M) cin >> v[i][j]; // Input 2-d vector

// #dynamic-programming
// #knapsack

int main(){
    int N,W;
    cin >> N >> W;
    vector<int> v(N);
    vector<int> w(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i] >> w[i];
    }

    // With top & left 0-padding
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));

    // DP
    for (int i = 1; i < N+1; i++) {
        for (int j = 1; j < W+1; j++) {
            int val = v[i-1];
            int weight = w[i-1];

            if (weight > j) {
                // Too high cost
                dp[i][j] = dp[i-1][j];
            } else {
                // To include or not include
                dp[i][j] = max(val + dp[i-1][j-weight], dp[i-1][j]);
            }
        }
    }
    cout << dp[N][W] << endl;
}
