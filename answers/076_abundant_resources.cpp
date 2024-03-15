#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353; // 1000000007
const int INF = 1e9;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define VIN(v, N) REP(i,N) cin >> v[i]; // Input 1-d vector
#define VIN2(v, N, M) REP(i,N) REP(j,M) cin >> v[i][j]; // Input 2-d vector
#define BITCOUNT(n) __builtin_popcountl(long(n))
#define ALL(x) (x).begin(), (x).end()
#define BC(var, lower, upper) ((var)>=lower and (var)<upper) // Boundary check of var with [lower, upper)
#define PRINT(x) cout << (x) << endl;

template<class itr> void PRINT_ARR(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void CINS(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// #ruisekiwa
// #prefix-sum

int main() {
    int N;
    cin>>N;
    vector<ll> prefix_sum(N+1); // sum up to and including the index one
    ll sum = 0;
    REP(i, N) {
        int a;
        cin>>a;
        sum += a;
        prefix_sum[i+1] = sum;
    }

    for (int k = 1; k < N+1; k++) {
        ll max_val = 0;
        for (int i = 1; i+k-1 < N+1; i++) {
            max_val = max(max_val, prefix_sum[i+k-1] - prefix_sum[i-1]);
        }
        cout << max_val << endl;
    }
}
