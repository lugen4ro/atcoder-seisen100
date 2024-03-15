#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353; // 1000000007
const int INF = 1e9;
const ll LINF = 1e18;
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define VIN(v, N) rep(i,N) cin >> v[i]; // Input 1-d vector
#define VIN2(v, N, M) REP(i,N) REP(j,M) cin >> v[i][j]; // Input 2-d vector
#define BITCOUNT(n) __builtin_popcountl(long(n))
#define ALL(x) (x).begin(), (x).end()
#define BC(var, lower, upper) ((var)>=lower and (var)<upper) // Boundary check of var with [lower, upper)
#define PRINT(x) cout << (x) << endl;

template<class itr> void PRINT_ARR(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// #warshall-floyd
// #shortest-path

int main(){

    int N,M;
    cin>>N>>M;

    vector<vector<ll>> dp(N, vector<ll>(N, LINF));

    // Input undirected graph
    REP(i, M) {
        int a,b,t; // bus stop 1, bus stop 2, time
        cin>>a>>b>>t;
        dp[a-1][b-1] = t; // change bus stops to 0-indexed
        dp[b-1][a-1] = t;
    }

    // To itself cost is 0
    REP(i,N) {
        dp[i][i] = 0;
    }

    // Warshall-Floyd
    REP(i, N) {
        // For vertice i as intermediary
        REP(s, N) {
            // For vertice j as source
            REP(t, N) {
                // For vertice t as target
                if (not (dp[s][i] == LINF or dp[i][t] == LINF)) dp[s][t] = min(dp[s][t], dp[s][i] + dp[i][t]);
            }
        }
    }

    // Get bus stops that has lowest max distance to another bus stop
    ll min_max_dist = LINF;
    REP(i, N) {
        ll max_dist = 0;
        REP(j, N) {
            if (i != j) max_dist = max(max_dist, dp[i][j]);
        }
        min_max_dist = min(min_max_dist, max_dist);
    }
    cout << min_max_dist << endl;
}
