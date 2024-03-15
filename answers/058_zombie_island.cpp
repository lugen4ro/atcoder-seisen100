#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353; // 1000000007
const int INF = 1e9;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define VIN(v,N) REP(i,N) cin >> v[i]; // Input 1-d vector
#define VIN2(v,N,M) REP(i,N) REP(j,M) cin >> v[i][j]; // Input 2-d vector
#define BITCOUNT(n) __builtin_popcountl(long(n))
#define ALL(x) (x).begin(), (x).end()
#define BC(var, lower, upper) ((var)>=lower and (var)<upper) // Boundary check of var with [lower, upper)
#define PRINT(x) cout << (x) << endl;
#define CON(x,y) x.count(y)>0 // x contains key y

template<class itr> void PRINT_ARR(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void CINS(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// #shortest-path
// #dijkstra
// #BFS
// #multi-source BFS
// #多始点幅優先探索

int main() {
    int N,M,K,S; // N:number of towns, M:number of roads, K:number of zombie towns, S:reach of danger
    cin>>N>>M>>K>>S;
    int P,Q; // P:safe price, Q:danger price
    cin >>P>>Q;

    // Input zombie towns
    queue<int> que; // BFS queue
    vector<int> dist(N);
    set<int> visited; // Meaning already in queue or processed
    REP(i, K) {
        int z;
        cin >> z;
        que.push(z-1);
        visited.insert(z-1);
    }

    // Adjacency List
    map<int, vector<int>> adj;
    REP(i, M) {
        int a,b;
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    // multi-source bfs (not one after the other ! Go out at the same time!)
    int d = 0;
    while (!que.empty()) {
        // Go through towns currently in queue
        int len = que.size();
        REP(i, len) {
            int town = que.front();
            que.pop();

            dist[town] = d;

            for(int t : adj[town]) {
                if (CON(visited,t)) continue;
                que.push(t);
                visited.insert(t);
            }
        }
        d++;
    }

    // Set cost for traveling to each city
    vector<ll> costs(N);
    REP(i, N) {
        if (dist[i] == 0) costs[i] = INF;
        else if (i == 0 or i == N-1) costs[i] = 0;
        else if (dist[i] <= S) costs[i] = Q;
        else costs[i] = P;
    }

    priority_queue<pair<ll, ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq; // Cost, Destination (prioritize min)
    pq.push(make_pair(0, 0));
    vector<ll> sp(N,-1); // Shortest path

    while (!pq.empty()) {
        pair<ll, ll> edge = pq.top();
        pq.pop();
        ll cost = edge.first;
        ll dest = edge.second;

        if (sp[dest] != -1) continue;

        sp[dest] = cost;

        // Found shelter
        if (dest == N-1) break;

        // Add edges with dest as source
        for(auto target : adj[dest]) {
            pq.push(make_pair(cost + costs[target], target));
        }
    }
    cout << sp[N-1] << endl;
}

