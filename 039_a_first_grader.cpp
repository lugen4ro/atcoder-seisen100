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
#define vin(v, N) rep(i,N) cin >> v[i]; // Input 1-d vector
#define vin2(v, N, M) rep(i,N) rep(j,M) cin >> v[i][j]; // Input 2-d vector

// #dynamic-programming
// #knapsack

int main(){

    int N;
    cin >> N;
    vector<int> v(N);
    vin(v, N);

    vector<vector<ll>> dp(N, vector<ll>(21)); // 0 ~ 20
    dp[0][v[0]] = 1;

    for (int i = 1; i < N-1; i++) {
        for (int j = 0; j <= 20; j++) {
            int val = v[i];

            // +
            if (bc(j+val,0,21) and dp[i-1][j+val]>0) dp[i][j] += dp[i-1][j+val];

            // -
            if (bc(j-val,0,21) and dp[i-1][j-val]>0) dp[i][j] += dp[i-1][j-val];
        }
    }
    cout << dp[N-2][v[N-1]] << endl;
}
