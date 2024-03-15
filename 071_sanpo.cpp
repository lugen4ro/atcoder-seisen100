#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef tuple<int,int,int,int> T4;
// const int MOD = 998244353; // 1000000007
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

/* pair */ template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const pair<_KTy, _Ty>& m) { ostr << "(" << m.first << ", " << m.second << ")"; return ostr; }
/* map */ template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const map<_KTy, _Ty>& m) { if (m.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << *m.begin(); for (auto itr = ++m.begin(); itr != m.end(); itr++) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
/* set */ template <typename _Ty> ostream& operator << (ostream& ostr, const set<_Ty>& s) { if (s.empty()) { ostr << "{ }"; return ostr; }  ostr << "{" << *(s.begin()); for (auto itr = ++s.begin(); itr != s.end(); itr++) ostr << ", " << *itr; ostr << "}"; return ostr; }
/* vector*/ template <typename _Ty> ostream& operator << (ostream& ostr, const vector<_Ty>& v) { if (v.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << v.front(); for (auto itr = ++v.begin(); itr != v.end(); itr++) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
/* list */ template <typename _Ty> ostream& operator << (ostream& ostr, const list<_Ty>& l) { if (l.empty()) { ostr << "{ }"; return ostr;  } ostr << "{" << *(l.begin()); for (auto itr = ++l.begin(); itr != l.end(); itr++) ostr << ", " << *itr; ostr << "}"; return ostr; }
/* priority queue */ template <typename _Ty> ostream& operator << (ostream& ostr, const priority_queue<_Ty>& pq) { priority_queue<_Ty> temp = pq; if (temp.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << temp.top(); temp.pop(); while (!temp.empty()) { ostr << ", " << temp.top(); temp.pop(); } ostr << "}"; return ostr; }

template<class itr> void PRINT_ARR(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void CINS(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }


/******************** Power with modulo ********************/
// a^b % mod
// Time Complexity: O(logb)
// Brief: Instead of multiplying b times with a, multiply with powers of a
// ex) 3^13 --> 3^8 * 3^4 * 3^1 (because 13 = 1101)
// Restrictions: 
//  - a can be negative or positive or 0
//  - mod of negative number will be positive
ll modpow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b > 0) {
        // Do where there is a 1 in binary representation --> ex) 13 = 1101, so we will multiply with a^1, a^4, a^8
        if (b & 1) res = ((res * a) % mod + mod) % mod; // Even negative a will have positive result
        a = a * a % mod; // Will be --> a^1, a^2, a^4, a^8 ... 
        b >>= 1;
    }
    return res;
}

int main() {
    int N,Q;
    cin>>N>>Q;

    vector<int> a(N);
    VIN(a, N);

    vector<int> c(Q+2);
    c[0] = 0;
    REP(i, Q) {
        int val;
        cin >> val;
        c[i+1] = val - 1;
    }
    c[Q+1] = 0;

    ll total = 0;
    vector<ll> acc_dist(N, 0);

    // Calculate all distances
    REP(i, N-1) {
        ll dist = modpow(a[i], a[i+1], MOD);
        total = (total + dist) % MOD;
        acc_dist[i+1] = total;
    }

    ll ans = 0;
    REP(i, Q+1) {
        int source = min(c[i], c[i+1]);
        int dest = max(c[i], c[i+1]);
        ans = (ans + acc_dist[dest] - acc_dist[source]) % MOD;
    }

    // Because answer might be negative
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
}
