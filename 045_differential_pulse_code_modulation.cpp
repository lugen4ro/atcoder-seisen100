#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> P; typedef tuple<int,int,int> T; typedef tuple<int,int,int,int> T4;
// const int MOD = 998244353; 
const int MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<(n+1);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define RREP1(i,n) for(int i=n;i>=1;i--)
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

int main() {
    int N,M;
    cin>>N>>M;
    while (N!=0) {
        vector<int> codebook(M);
        VIN(codebook, M);
        int signal[N];
        VIN(signal, N);
        int ans = 0;

        vector<vector<int>> dp(N+1, vector<int>(256, INF));
        dp[0][128] = 0;
        REP1(i, N) {
            REP(j, 256) {
                REP(k, M) {
                    if (BC(j-codebook[k], 0 , 256)) dp[i][j] = min(dp[i][j], (signal[i-1] - j)*(signal[i-1] - j) + dp[i-1][j-codebook[k]]);
                }

                // for 0 & 255 only because of clipping 
                if (j==255) {
                    // might be moving from any of j - max_move to 255 because of clipping
                    int max_move = *max_element(ALL(codebook));
                    REP(l, max_move+1) {
                        dp[i][j] = min(dp[i][j], (signal[i-1] - j)*(signal[i-1] - j) + dp[i-1][j-l]);
                    }
                }
                if (j==0) {
                    // might be moving from any of j - max_move to 255 because of clipping
                    int min_move = *min_element(ALL(codebook));
                    REP(l, -min_move+1) {
                        dp[i][j] = min(dp[i][j], (signal[i-1] - j)*(signal[i-1] - j) + dp[i-1][j+l]);
                    }
                }
            }
        }
        PRINT(*min_element(ALL(dp[N])));
        cin>>N>>M;
    }
}
