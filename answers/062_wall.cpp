#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int MOD = 998244353; // 1000000007
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


/******************** Warshall-Floyd (Shortest-Path All Pairs) ********************/
// @params adj: adjacency list with (cost, destination) --> ex) N=4, {{{111, 2}, {112, 3}}, {{44, 1}}, {{11,1}, {22,3}}}
// @return: 2-d vector of ll that contains shortest paths
// 0-indexed / 1-indexed works with both! (when 1-indexed first row and column will have to be ignored)
// Unreachable nodes will have value LINF
// vector<vector<ll>> floyd(vector<vector<P>> &adj) {
vector<vector<ll>> floyd(vector<vector<ll>> &dp) {

    // Number of vertices
    int V = dp.size();

    REP(i, V) { // For vertice i as intermediary
        REP(s, V) { // For vertice s as source
            REP(t, V) { // For vertice t as target

                // Is there a path from s over i to t?
                if (not (dp[s][i] == LINF or dp[i][t] == LINF)) {
                    // Use the shorter of an already found path or the path over i
                    dp[s][t] = min(dp[s][t], dp[s][i] + dp[i][t]);
                }
            }
        }
    }

    // OPTIONAL CHECK
    // If weights are negative, a negative loop could exist, rendering the notion of shortest path meaningless
    // If one exists, the cost to itself will become negative for nodes included in the loop
    REP(s, V) if (dp[s][s] < 0) { PRINT("NEGATIVE CYCLE"); exit(0); }

    return dp;
}

int main() {
    int H,W;
    cin>>H>>W;
    vector<vector<ll>> dp(10, vector<ll>(10));
    REP(i, 10) {
        REP(j, 10) {
            cin>>dp[i][j];
        }
    }
    auto res = floyd(dp);
    ll cost=0;
    REP(_, H) {
        REP(_, W) {
            int n;
            cin>>n;
            if (n==-1) continue;
            cost += res[n][1];
        }
    }
    cout << cost << endl;
}
