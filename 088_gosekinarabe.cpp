#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353; // 1000000007
const int INF = 1e9;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define VIN(v, N) REP(i,N) cin >> v[i]; // Input 1-d vector
#define VIN2(v, N, M) REP(i,N) REP(j,M) cin >> v[i][j]; // Input 2-d vector
#define BITCOUNT(n) __builtin_popcountl(long(n))
#define ALL(x) (x).begin(), (x).end()
#define BC(var, lower, upper) ((var)>=lower and (var)<upper) // Boundary check of var with [lower, upper)
#define PRINT(x) cout << (x) << endl;

template<class itr> void PRINT_ARR(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void CINS(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// #run-length compression

int main() {
    int n;
    cin>>n;
    vector<pair<int, int>> v(1, {-1, 0}); // Initialize with -1 (won't match with 0 or 1)
    int pos = 0; // position of last item
    FOR(i, 1, n+1) {
        int c;
        cin>>c; // 0 is white, 1 is black

        if (i%2==1) {
            // Odd number --> Just place stone
            if (v[pos].first==c) v[pos].second++;
            else {
                v.push_back(make_pair(c, 1));
                pos++;
            }
        } else {
            // Even number --> Flip if necessary
            if (v[pos].first==c) v[pos].second++;
            else {
                if (pos >= 1) {
                    // Flip
                    v[pos-1] = make_pair(c, v[pos-1].second+v[pos].second+1);
                    v.pop_back();
                    pos--;
                } else {
                    v[pos] = make_pair(c, v[pos].second+1);
                }
            }
        }
    }
    int ans=0;
    REP(i, v.size()) if (v[i].first==0) ans+=v[i].second;
    cout << ans << endl;
}
