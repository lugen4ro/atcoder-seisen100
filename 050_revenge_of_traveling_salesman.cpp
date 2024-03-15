#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> P; typedef tuple<int,int,int> T; typedef tuple<int,int,int,int> T4;
const int MOD = 998244353; 
// const int MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define RREP1(i,n) for(int i=n-1;i>=1;i--)
#define VIN(v,N) REP(i,N) cin >> v[i]; // Input 1-d vector
#define VIN2(v,N,M) REP(i,N) REP(j,M) cin >> v[i][j]; // Input 2-d vector
#define BITCOUNT(n) __builtin_popcountl(long(n))
#define ALL(x) (x).begin(), (x).end()
#define BC(var, lower, upper) ((var)>=lower and (var)<upper) // Boundary check of var with [lower, upper)
#define PRINT(x) cout << (x) << endl;
#define PRINT2(x,y) cout << (x) << " " << (y) << endl;
#define PRINT3(x,y,z) cout << (x) << " " << (y) << " " << (z) << endl;
#define PRINT4(x,y,z,a) cout << (x) << " " << (y) << " " << (z) << " " << (a) << endl;
#define PRINTD(x, precision) cout << fixed << setprecision(precision) << (x) << endl;

template<class _Ty> inline bool chmin(_Ty& a, _Ty b) { if (a > b) { a = b; return true; } return false; }
template<class _Ty> inline bool chmax(_Ty& a, _Ty b) { if (a < b) { a = b; return true; } return false; }

ll modfact(ll N, ll mod=MOD) { ll res = 1; while (N>1) { res = res * N % mod; N--; } return res; }
ll modpow(ll base, ll exp, ll mod=MOD) { ll res = 1; while (exp > 0) { if (exp & 1) res = ((res * base) % mod + mod) % mod; base = base * base % mod; exp >>= 1; } return res; }
ll moddiv(ll n, ll d, ll mod=MOD) { ll inverse = modpow(d, mod-2, mod); return (n * inverse) % mod; }
ll combinations_with_repetition(ll n, ll k, ll mod=MOD) { ll numerator = modfact(n+k-1, mod); ll denominator = (modfact(k, mod) * modfact(n-1, mod)) % mod; return moddiv(numerator, denominator, mod); }
ll combinations(ll n, ll k, ll mod=MOD) { ll numerator = modfact(n, mod); ll denominator = (modfact(k, mod) * modfact(n-k, mod)) % mod; return moddiv(numerator, denominator, mod); }

template<class itr> void PRINT_ARR(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }

/* pair */ template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const pair<_KTy, _Ty>& m) { ostr << "(" << m.first << ", " << m.second << ")"; return ostr; }
/* map */ template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const map<_KTy, _Ty>& m) { if (m.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << *m.begin(); for (auto itr = ++m.begin(); itr != m.end(); itr++) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
/* set */ template <typename _Ty> ostream& operator << (ostream& ostr, const set<_Ty>& s) { if (s.empty()) { ostr << "{ }"; return ostr; }  ostr << "{" << *(s.begin()); for (auto itr = ++s.begin(); itr != s.end(); itr++) ostr << ", " << *itr; ostr << "}"; return ostr; }
/* vector*/ template <typename _Ty> ostream& operator << (ostream& ostr, const vector<_Ty>& v) { if (v.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << v.front(); for (auto itr = ++v.begin(); itr != v.end(); itr++) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
/* list */ template <typename _Ty> ostream& operator << (ostream& ostr, const list<_Ty>& l) { if (l.empty()) { ostr << "{ }"; return ostr;  } ostr << "{" << *(l.begin()); for (auto itr = ++l.begin(); itr != l.end(); itr++) ostr << ", " << *itr; ostr << "}"; return ostr; }
/* priority queue */ template <typename _Ty> ostream& operator << (ostream& ostr, const priority_queue<_Ty>& pq) { priority_queue<_Ty> temp = pq; if (temp.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << temp.top(); temp.pop(); while (!temp.empty()) { ostr << ", " << temp.top(); temp.pop(); } ostr << "}"; return ostr; }

// #traveling-salesman
// #bit-dp

int main() {
    int N,M; cin>>N>>M; // N: number of houses, M: number of roads

    vector<vector<pair<ll, ll>>> cost(N, vector<pair<ll, ll>>(N, {LINF, -1})); // {distance, time limit}

    REP(i, M) {
        ll s,t,d,time;
        cin>>s>>t>>d>>time;
        cost[s-1][t-1] = {d,time};
        cost[t-1][s-1] = {d,time};
    }

    vector<vector<pair<ll, ll>>> dp(1<<N, vector<pair<ll, ll>>(N, {LINF, 0})); // pair = {shortest path distance, number of such paths}
    dp[0][0] = {0, 1}; // Only valid source to come from is 0, and there is no vertice travelled to yet so S = 0

    REP(S, 1<<N) {
        // 0000 -> 1111  (1<<V = 10000)
        // Since we're doing 10 and 01 before 11 we will always keep the correct order!
        REP(v, N) {
            REP(u, N) {
                // From state S house u to state SUv house v

                // source u must be in S (Unless when S=0 and we have not visited anything yet)
                if (!(S==0) and !(S & 1<<u)) continue;

                // destination v must not be in S
                if (S & (1<<v)) continue;

                // time limit check
                ll new_dist = dp[S][u].first + cost[u][v].first;
                if(new_dist > cost[u][v].second) continue;

                // Set dp[S U v][v]
                // Get overall min way to v, by calculating all paths to v from u where u is element of S
                if (dp[S|1<<v][v].first > new_dist) {
                    dp[S|1<<v][v].first = dp[S][u].first + cost[u][v].first; // distance
                    dp[S|1<<v][v].second = dp[S][u].second; // number of paths
                } else if (dp[S|1<<v][v].first == new_dist) {
                    dp[S|1<<v][v].first = dp[S][u].first + cost[u][v].first; // distance
                    dp[S|1<<v][v].second += dp[S][u].second; // number of paths
                }
            }
        }
    }

    // Visited all, and last was 0
    if (dp[(1<<N)-1][0].first == LINF) cout << "IMPOSSIBLE" << endl;
    else cout << dp[(1<<N)-1][0].first << " " << dp[(1<<N)-1][0].second << endl;;
}
