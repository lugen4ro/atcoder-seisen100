#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef tuple<int, int, int, int> T4;
// const int MOD = 998244353;
const int MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e18;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP1(i, n) for (int i = 1; i < (n + 1); i++)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
#define RREP1(i, n) for (int i = n; i >= 1; i--)
#define VIN(v, N) REP(i, N) cin >> v[i];                  // Input 1-d vector
#define VIN2(v, N, M) REP(i, N) REP(j, M) cin >> v[i][j]; // Input 2-d vector
#define BITCOUNT(n) __builtin_popcountl(long(n))
#define ALL(x) (x).begin(), (x).end()
#define BC(var, lower, upper)                                                  \
    ((var) >= lower and                                                        \
     (var) < upper) // Boundary check of var with [lower, upper)
#define PRINT(x) cout << (x) << endl;
#define PRINT2(x, y) cout << (x) << " " << (y) << endl;
#define PRINT3(x, y, z) cout << (x) << " " << (y) << " " << (z) << endl;
#define PRINT4(x, y, z, a)                                                     \
    cout << (x) << " " << (y) << " " << (z) << " " << (a) << endl;
#define PRINTD(x, precision)                                                   \
    cout << fixed << setprecision(precision) << (x) << endl;

ll modfact(ll N, ll mod = MOD) {
    ll res = 1;
    while (N > 1) {
        res = res * N % mod;
        N--;
    }
    return res;
}
ll modpow(ll base, ll exp, ll mod = MOD) {
    ll res = 1;
    while (exp > 0) {
        if (exp & 1)
            res = ((res * base) % mod + mod) % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}
ll moddiv(ll n, ll d, ll mod = MOD) {
    ll inverse = modpow(d, mod - 2, mod);
    return (n * inverse) % mod;
}
ll combinations_with_repetition(ll n, ll k, ll mod = MOD) {
    ll numerator = modfact(n + k - 1, mod);
    ll denominator = (modfact(k, mod) * modfact(n - 1, mod)) % mod;
    return moddiv(numerator, denominator, mod);
}
ll combinations(ll n, ll k, ll mod = MOD) {
    ll numerator = modfact(n, mod);
    ll denominator = (modfact(k, mod) * modfact(n - k, mod)) % mod;
    return moddiv(numerator, denominator, mod);
}

template <class itr> void PRINT_ARR(itr start, itr goal) {
    string ans;
    for (auto i = start; i != goal; i++)
        ans += to_string(*i) + " ";
    if (!ans.empty())
        ans.pop_back();
    cout << ans << endl;
}

/* pair */ template <typename _KTy, typename _Ty>
ostream &operator<<(ostream &ostr, const pair<_KTy, _Ty> &m) {
    ostr << "(" << m.first << ", " << m.second << ")";
    return ostr;
}
/* map */ template <typename _KTy, typename _Ty>
ostream &operator<<(ostream &ostr, const map<_KTy, _Ty> &m) {
    if (m.empty()) {
        ostr << "{ }";
        return ostr;
    }
    ostr << "{" << *m.begin();
    for (auto itr = ++m.begin(); itr != m.end(); itr++) {
        ostr << ", " << *itr;
    }
    ostr << "}";
    return ostr;
}
/* set */ template <typename _Ty>
ostream &operator<<(ostream &ostr, const set<_Ty> &s) {
    if (s.empty()) {
        ostr << "{ }";
        return ostr;
    }
    ostr << "{" << *(s.begin());
    for (auto itr = ++s.begin(); itr != s.end(); itr++)
        ostr << ", " << *itr;
    ostr << "}";
    return ostr;
}
/* vector*/ template <typename _Ty>
ostream &operator<<(ostream &ostr, const vector<_Ty> &v) {
    if (v.empty()) {
        ostr << "{ }";
        return ostr;
    }
    ostr << "{" << v.front();
    for (auto itr = ++v.begin(); itr != v.end(); itr++) {
        ostr << ", " << *itr;
    }
    ostr << "}";
    return ostr;
}
/* list */ template <typename _Ty>
ostream &operator<<(ostream &ostr, const list<_Ty> &l) {
    if (l.empty()) {
        ostr << "{ }";
        return ostr;
    }
    ostr << "{" << *(l.begin());
    for (auto itr = ++l.begin(); itr != l.end(); itr++)
        ostr << ", " << *itr;
    ostr << "}";
    return ostr;
}
/* priority queue */ template <typename _Ty>
ostream &operator<<(ostream &ostr, const priority_queue<_Ty> &pq) {
    priority_queue<_Ty> temp = pq;
    if (temp.empty()) {
        ostr << "{ }";
        return ostr;
    }
    ostr << "{" << temp.top();
    temp.pop();
    while (!temp.empty()) {
        ostr << ", " << temp.top();
        temp.pop();
    }
    ostr << "}";
    return ostr;
}

/******************** Prime Factorization ********************/
// @param N: number to prime factorize --> ex) 840
// @return: vector of prime factors in ascending order --> ex) [2,2,2,3,5,7]
vector<ll> prime_factorize(ll N) {

    vector<ll> res;
    for (ll a = 2; a * a <= N; ++a) {

        // Not a factor
        if (N % a != 0)
            continue;

        while (N % a == 0) {
            res.push_back(a);
            N /= a;
        }
    }

    // Last remaining prime factor
    if (N != 1)
        res.push_back(N);
    return res;
}

int main() {
    int N;
    cin >> N;
    auto v = prime_factorize(2 * N);
    // PRINT(v);
    int k = 0;
    for (int bit = 0; bit < (1 << v.size()) / 2; bit++) {
        int a = 1, b = 1;
        for (int i = 0; i < v.size(); i++) {
            if (bit & (1 << i)) {
                a *= v[i];
            } else {
                b *= v[i];
            }
        }
        if (max(a, b) - min(a, b) == 1) {
            k = max(a, b);
            break;
        }
    }

    // No answer
    if (k == 0) {
        cout << "No" << endl;
        exit(0);
    }

    cout << "Yes" << endl;
    cout << k << endl;

    // k sets with k-1 items each is the answer
    vector<int> used(N + 1); // 1-indexed
    vector<vector<int>> tup(k, vector<int>(k - 1));
    // iota(tup[0].begin(), tup[0].begin()+k-1, 1);
    int unused_val = 1;
    REP(i, k) {
        // Creating each set
        REP(j, i) {
            // Going through all previous sets to pick one number to share
            REP(l, k - 1) {
                // Going through each number in this set
                if (used[tup[j][l]] == 0) {
                    tup[i][j] = tup[j][l];
                    used[tup[j][l]]++;
                    break;
                }
            }
        }
        // Add unused number
        FOR(j, i, k - 1) { tup[i][j] = unused_val++; }
    }
    REP(i, k) {
        cout << k - 1 << " ";
        PRINT_ARR(tup[i].begin(), tup[i].end());
    }
}
