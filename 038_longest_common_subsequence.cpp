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
// #LCS

int main(){
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        string x,y;
        cin >> x >> y;

        int Y = y.size() + 1, X = x.size() + 1;

        // dp[i][j] stores the LCS between the sub-strings ending with index i and j
        vector<vector<int>> dp(Y, vector<int>(X, 0));

        for (int i = 1; i < Y; i++) {
            for (int j = 1; j < X; j++) {
                if (x[j-1] == y [i-1]) dp[i][j] = 1 + dp[i-1][j-1]; // Matching characters
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // No match
            }
        }
        cout << dp[Y-1][X-1] << endl;
    }
}
