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

    int n,k;
    cin>>n>>k;

    // Adjacency list
    map<int, vector<pair<int, int>>> adj;

    REP(_, k) {

        // Input
        int type;
        cin>>type;
        if (type == 1) {
            // New Route
            int c,d,e;
            cin>>c>>d>>e; // island c & d, cost is e
            adj[c].push_back(make_pair(e,d));
            adj[d].push_back(make_pair(e,c));
        } else {
            // Check min cost
            int a,b;
            cin>>a>>b;

            // Shortest path
            vector<ll> sp(n+1,-1);

            // Priority Queue to get min cost edge
            priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // Cost, Destination

            // Push starting island
            pq.push(make_pair(0, a));

            bool canReach = false;

            while (!pq.empty()) {
                pair<int, int> edge = pq.top();
                pq.pop();
                int cost = edge.first;
                int dest = edge.second;

                if (dest == b) {
                    // Found shortest path to destination
                    canReach = true;
                    cout << cost << endl;
                    break;
                }

                if (sp[dest] != -1) continue;

                sp[dest] = cost;

                // Add edges with dest as source
                for(auto edge : adj[dest]) {
                    pq.push(make_pair(edge.first+cost, edge.second));
                }
            }
            if (!canReach) cout << -1 << endl;
        }
    }
}
