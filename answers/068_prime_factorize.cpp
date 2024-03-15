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

// #prime-factorization

// Prime factorize
// @param N: number to prime factorize
// @return: vector of prime factors in ascending order --> ex) [2,2,2,3,5,7]
vector<ll> prime_factorize(ll N) {

    vector<ll> res;
    for (ll a = 2; a * a <= N; ++a) {

        // Not a factor
        if (N % a != 0) continue;

        while (N % a == 0) {
            res.push_back(a);
            N /= a;
        }
    }

    // Last remaining prime factor
    if (N != 1) res.push_back(N);
    return res;
}

int main() {
    int n;
    cin>>n;
    cout << n << ": ";
    vector<ll> ans = prime_factorize(n);
    PRINT_ARR(ALL(ans));
}
