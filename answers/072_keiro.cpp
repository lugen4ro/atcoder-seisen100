#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353; // 1000000007
const int INF = 1e9;
const ll LINF = 1e18;

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

// #gyakugen
// #modular-inverse

// Calculate a^b % mod
// Time Complexity: O(logb)
// Instead of multiplying b times with a, multiply with powers of a
// ex) 3^13 --> 3^8 * 3^4 * 3^1 (because 13 = 1101)
ll modpow(ll a, ll b, ll mod) {
    ll res = 1;

    while (b > 0) {
        // Do where there is a 1 in binary representation --> ex) 13 = 1101, so we will multiply with a^1, a^4, a^8
        if (b & 1) res = res * a % mod;
        a = a * a % mod; // Will be --> a^1, a^2, a^4, a^8 ... 
        b >>= 1;
    }
    return res;
}

// Factorial with modulo
// N=0 will return 1
ll modfact(ll N, ll mod) {
    ll res = 1;
    while (N>1) {
        res = res * N % mod;
        N--;
    }
    return res;
}

int main() {
    int W,H;
    cin>>W>>H;
    const ll mod = 1000000007;

    // Solve mathematically
    // Solution is (n+m)!/(n!m!) where n=W-1, m=H-1
    // Because we do division after modulo, we need to use the inverse element 
    // a^-1 = a^(p-2)

    ll top = modfact(W+H-2, mod);
    ll bottom = modfact(W-1, mod) * modfact(H-1, mod) % mod;
    ll inverse_bottom = modpow(bottom, mod-2, mod);
    ll ans = top * inverse_bottom % mod;

    cout << ans << endl;

}
