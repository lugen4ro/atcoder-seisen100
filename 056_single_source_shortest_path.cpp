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

// #dijkstra
// #shortest-path

int main(){
    int V,E,r;
    cin >> V >> E >> r;
    map<int, vector<pair<int, int>>> adj;
    REP(i, E) {
        int s,t,d;
        cin>>s>>t>>d;
        adj[s].push_back(make_pair(d,t));
    }
    vector<vector<ll>> v(E, vector<ll>(3));
    VIN2(v, E, 3);

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // Cost, Destination
    pq.push(make_pair(0, r));
    vector<ll> ans(V,-1);

    while (!pq.empty()) {
        pair<int, int> edge = pq.top();
        pq.pop();
        int cost = edge.first;
        int dest = edge.second;

        if (ans[dest] != -1) continue;

        ans[dest] = cost;

        // Add edges with dest as source
        for(auto edge : adj[dest]) {
            pq.push(make_pair(edge.first+cost, edge.second));
        }
    }

    // Print solution
    REP(i, V) {
        if (ans[i]==-1) {
            cout << "INF" << endl;
        } else {
            cout << ans[i] << endl;
        }
    }
}


