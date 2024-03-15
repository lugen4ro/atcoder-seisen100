#include <bits/stdc++.h>
using namespace std;

/* ---------------------- Constants / Aliases ---------------------- */
template <class T> using V = std::vector<T>; // V instead of vector
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef tuple<int,int,int,int> T4;
// const int MOD = 998244353; 
const int MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;

/* ---------------------- Print ---------------------- */
/* pair */ template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const pair<_KTy, _Ty>& m) { ostr << "(" << m.first << ", " << m.second << ")"; return ostr; }
/* map */ template <typename _KTy, typename _Ty> ostream& operator << (ostream& ostr, const map<_KTy, _Ty>& m) { if (m.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << *m.begin(); for (auto itr = ++m.begin(); itr != m.end(); itr++) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
/* set */ template <typename _Ty> ostream& operator << (ostream& ostr, const set<_Ty>& s) { if (s.empty()) { ostr << "{ }"; return ostr; }  ostr << "{" << *(s.begin()); for (auto itr = ++s.begin(); itr != s.end(); itr++) ostr << ", " << *itr; ostr << "}"; return ostr; }
/* vector*/ template <typename _Ty> ostream& operator << (ostream& ostr, const vector<_Ty>& v) { if (v.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << v.front(); for (auto itr = ++v.begin(); itr != v.end(); itr++) { ostr << ", " << *itr; } ostr << "}"; return ostr; }
/* list */ template <typename _Ty> ostream& operator << (ostream& ostr, const list<_Ty>& l) { if (l.empty()) { ostr << "{ }"; return ostr;  } ostr << "{" << *(l.begin()); for (auto itr = ++l.begin(); itr != l.end(); itr++) ostr << ", " << *itr; ostr << "}"; return ostr; }
/* priority queue */ template <typename _Ty> ostream& operator << (ostream& ostr, const priority_queue<_Ty>& pq) { priority_queue<_Ty> temp = pq; if (temp.empty()) { ostr << "{ }"; return ostr; } ostr << "{" << temp.top(); temp.pop(); while (!temp.empty()) { ostr << ", " << temp.top(); temp.pop(); } ostr << "}"; return ostr; }
/* PRINT helper */ template <typename Arg1> void myprint(Arg1&& arg1) { std::cout <<  arg1 << std::endl; }
/* PRINT helper */ template <typename Arg1, typename... Args> void myprint(Arg1&& arg1, Args&&... args) { std::cout << arg1 << " "; myprint(args...); }
/* DEBUG helper */ template <typename Arg1> void mydebug(const char* name, Arg1&& arg1) { std::cout << name << " = " << arg1 << std::endl; }
/* DEBUG helper */ template <typename Arg1, typename... Args> void mydebug(const char* names, Arg1&& arg1, Args&&... args) { const char* comma = strchr(names + 1, ','); std::cout.write(names, comma - names) << " = " << arg1; mydebug(comma, args...); }

/* ---------------------- Macros ---------------------- */
#define PRINT(...) myprint(__VA_ARGS__) // Print a variable number of parameter values seperated with spaces
#define DEBUG(...) mydebug(#__VA_ARGS__, __VA_ARGS__) // Print a variable number of parameters with the parameter name and value
#define REP_(i, a_, b_, a, b, ...) for (int i = (a), lim = (b); i < lim; i++) // Set lim once so b doesn't get evaluated every time
#define REP(i, ...) REP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__) // (i,5) -> (i,5,5,0,5) so a=0,b=5   (i,5,10) -> (i,5,10,5,10,0,5,10) so a=5,b=10
#define RREP_(i, a_, b_, a, b, ...) for (int i = (b)-1, lim = (a); i >= lim; i--) // specify range in same way as REP, but iterate in reverse order
#define RREP(i, ...) RREP_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define BITCOUNT(n) __builtin_popcountl(long(n))
#define ALL(x) (x).begin(), (x).end()
#define BC(var, lower, upper) ((var)>=lower and (var)<upper) // Boundary check of var with [lower, upper)

/* ---------------------- Input ---------------------- */
template<class... T> void input(T&... a){ (cin >> ... >> a); }
#define INT(...) int __VA_ARGS__; input(__VA_ARGS__) // Declare and input multiple int
#define LL(...) long long __VA_ARGS__; input(__VA_ARGS__) // Declare and input multiple long long
template<typename T> istream& operator >> (istream& is, vector<T>& vec){ for(T& x: vec) is >> x; return is; }// input vector with just cin>>

/* ---------------------- QOL Functions---------------------- */
ll modfact(ll N, ll mod=MOD) { ll res = 1; while (N>1) { res = res * N % mod; N--; } return res; }
ll modpow(ll base, ll exp, ll mod=MOD) { ll res = 1; while (exp > 0) { if (exp & 1) res = ((res * base) % mod + mod) % mod; base = base * base % mod; exp >>= 1; } return res; }
ll moddiv(ll n, ll d, ll mod=MOD) { ll inverse = modpow(d, mod-2, mod); return (n * inverse) % mod; }
ll combinations_with_repetition(ll n, ll k, ll mod=MOD) { ll numerator = modfact(n+k-1, mod); ll denominator = (modfact(k, mod) * modfact(n-1, mod)) % mod; return moddiv(numerator, denominator, mod); }
ll combinations(ll n, ll k, ll mod=MOD) { ll numerator = modfact(n, mod); ll denominator = (modfact(k, mod) * modfact(n-k, mod)) % mod; return moddiv(numerator, denominator, mod); }
template<class _Ty> inline bool chmin(_Ty& a, _Ty b) { if (a > b) { a = b; return true; } return false; }
template<class _Ty> inline bool chmax(_Ty& a, _Ty b) { if (a < b) { a = b; return true; } return false; }
template<class itr> void PRINT_ARR(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }

/* ---------------------- CONSTRUCTOR ---------------------- */
// Constructor function which is executed before main()
__attribute__((constructor)) static void setup_io() noexcept {
    std::ios_base::sync_with_stdio(false); // Do not sync iostream with cstdio for improved speed
    std::cin.tie(nullptr); // Do not tie cin to cout and flush before every input for improved speed
    std::cout << std::fixed << std::setprecision(10); // Set precision when printing floats
}


//////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// Template END //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

// #DP
// #LIS (Longest-Increasing-Subsequence)
// #LDS (Longest-Decreasing-Subsequence)

int main() {
    INT(N);
    V<int> v(N);
    cin>>v;

    V<int> dp(N+1, -INF); // dp[i] := value of tail of LDS with length i; If multiple are length i, maximum value
    dp[0] = INF;
    REP(i, N) {
        auto larger_or_equal = upper_bound(dp.begin(), dp.begin() + i + 1, v[i], greater<int>()) - 1;
        int length =  larger_or_equal - dp.begin();
        chmax(dp[length+1], v[i]);
    }
    int lds = 0;
    RREP(i, N+1) if(dp[i] != -INF) {lds = i; break;}
    PRINT(lds);

}
