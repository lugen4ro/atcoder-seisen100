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

ll modfact(ll N, ll mod=MOD) { ll res = 1; while (N>1) { res = res * N % mod; N--; } return res; }
ll modpow(ll base, ll exp, ll mod=MOD) { ll res = 1; while (exp > 0) { if (exp & 1) res = ((res * base) % mod + mod) % mod; base = base * base % mod; exp >>= 1; } return res; }
ll moddiv(ll n, ll d, ll mod=MOD) { ll inverse = modpow(d, mod-2, mod); return (n * inverse) % mod; }
ll combinations_with_repetition(ll n, ll k, ll mod=MOD) { ll numerator = modfact(n+k-1, mod); ll denominator = (modfact(k, mod) * modfact(n-1, mod)) % mod; return moddiv(numerator, denominator, mod); }
ll combinations(ll n, ll k, ll mod=MOD) { ll numerator = modfact(n, mod); ll denominator = (modfact(k, mod) * modfact(n-k, mod)) % mod; return moddiv(numerator, denominator, mod); }

/* pair */ template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const pair<_KTy, _Ty>& m) { ostr << "(" << m.first << ", " << m.second << ")"; return ostr; }
/* map */ template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const map<_KTy, _Ty>& m) { if (m.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << *m.begin(); for (auto itr = ++m.begin(); itr != m.end(); itr++) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
/* set */ template <typename _Ty> ostream& operator << (ostream& ostr, const set<_Ty>& s) { if (s.empty()) { ostr << "{ }"; return ostr; }  ostr << "{" << *(s.begin()); for (auto itr = ++s.begin(); itr != s.end(); itr++) ostr << ", " << *itr; ostr << "}"; return ostr; }
/* vector*/ template <typename _Ty> ostream& operator << (ostream& ostr, const vector<_Ty>& v) { if (v.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << v.front(); for (auto itr = ++v.begin(); itr != v.end(); itr++) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
/* list */ template <typename _Ty> ostream& operator << (ostream& ostr, const list<_Ty>& l) { if (l.empty()) { ostr << "{ }"; return ostr;  } ostr << "{" << *(l.begin()); for (auto itr = ++l.begin(); itr != l.end(); itr++) ostr << ", " << *itr; ostr << "}"; return ostr; }
/* priority queue */ template <typename _Ty> ostream& operator << (ostream& ostr, const priority_queue<_Ty>& pq) { priority_queue<_Ty> temp = pq; if (temp.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << temp.top(); temp.pop(); while (!temp.empty()) { ostr << ", " << temp.top(); temp.pop(); } ostr << "}"; return ostr; }

// #ruisekiwa
// #imos
// #prefix-sum

int main() {
    int N,M;
    cin>>N>>M;
    vector<int> imos(N);
    int prev,next;
    cin >> prev;
    REP(i, M-1) {
        cin>>next;
        imos[min(next,prev)]++;
        imos[max(next,prev)]--;
        prev = next;
    }

    vector<T> cost(N);
    REP1(i, N-1) {
        int ticket,ic,ic_init;
        cin>>ticket>>ic>>ic_init;
        cost[i] = {ticket, ic, ic_init};
    }

    ll ans = 0;
    REP1(i, N-1) {
        imos[i] = imos[i-1] + imos[i];
        auto [ticket, ic, ic_init] = cost[i];

        ll price_ticket = 1LL * imos[i] * ticket;
        ll price_ic = 1LL * imos[i] * ic + ic_init;
        ans += min(price_ic, price_ticket);
    }
    cout << ans << endl;
}
