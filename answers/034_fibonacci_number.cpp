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
    int n;
    cin >> n;

    vector<ll> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n+1; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n] << endl;
}
