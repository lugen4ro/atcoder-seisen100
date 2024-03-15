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

    int V,E;
    cin>>V>>E;

    vector<vector<ll>> dp(V, vector<ll>(V, LINF));

    // Input directed graph
    REP(i, E) {
        int s,t,d;
        cin>>s>>t>>d; // directed graph
        dp[s][t] = d;
    }

    // To itself cost is 0
    REP(i, V) {
        dp[i][i] = 0;
    }

    REP(i, V) {
        // For vertice i as intermediary
        REP(s, V) {
            // For vertice j as source
            REP(t, V) {
                // For vertice t as target
                if (not (dp[s][i] == LINF or dp[i][t] == LINF)) dp[s][t] = min(dp[s][t], dp[s][i] + dp[i][t]);
            }
        }
    }

    // Loop with a total negative cost exists
    // Equivalent to cost to itself is negative
    REP(i, V) {
        if (dp[i][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            exit(0);
        }
    }

    // Print
    REP(s, V) {
        REP(t, V) {
            if (dp[s][t] == LINF) {
                cout << "INF";
            } else {
                cout << dp[s][t];
            }
            if (t!=V-1) cout << " ";
        }
        cout << endl;
    }
}
