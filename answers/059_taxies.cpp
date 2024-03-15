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


/******************** BFS ********************/
// @params adj: adjacency list --> ex) N=4, {{2,4}, {1}, {1,4}, {2,3}}
// @params source: starting node --> ex) 0
// 0-indexed / 1-indexed works with both!
vector<int> bfs(vector<vector<int>> &adj, int source, int reach) {

    vector<int> ans;

    // Create queue and initialize with source
    queue<int> que;
    que.push(source);

    // Depth of search
    int level = 0;

    // Track visited nodes, so we don't add the same node multiple times to the queue
    set<int> visited;

    while(!que.empty()) {
        int len_que = que.size();
        REP(i, len_que) {
            int node = que.front(); que.pop();

            //// PROCESS NODE ////
            // do something with node here
            if (node != source) ans.push_back(node);

            // Add adjacent nodes to queue
            for(auto next : adj[node]) {
                //// CONDITIONS ////
                // Skip nodes already processed or added to queue
                if (visited.count(next)>0) continue;

                // Add to queue
                que.push(next);
                visited.insert(next);
            }
        }
        level++;
        if (level > reach) break;
    }
    return ans;
}


/******************** Dijkstra (Shortest-Path Single Source) ********************/
// @params adj: adjacency list with (cost, destination) --> ex) N=4, {{{111, 2}, {112, 3}}, {{44, 1}}, {{11,1}, {22,3}}}
// @params node: Starting node --> ex) 0
// 0-indexed / 1-indexed works with both! (when 1-indexed sp[0] will be -1)
// Time Complexity: O(ElogE) --> For every edge we take logE time to remove it from the Heap
vector<ll> dijkstra(vector<vector<P>> &adj, int source) {

    // Min heap
    priority_queue<P, vector<P>, greater<P>> pq; // Pair --> (Cost, Destination)
    pq.push({0, source});

    // Keep track of already visited nodes
    set<int> visited;

    // Store shortest path here (Unreachable nodes will have value -1)
    vector<ll> sp(adj.size(), -1);

    while (!pq.empty()) {

        // Get edge with best cost
        auto [cost, dest] = pq.top(); pq.pop();

        // Skip already visited
        if (visited.count(dest)>0) continue;

        // Found cost of shortest path to dest
        sp[dest] = cost;

        // Mark visited
        visited.insert(dest);

        // Add edges coming out of dest
        for(auto edge : adj[dest]) {
            pq.push({cost + edge.first, edge.second});
        }
    }
    return sp;
}


int main() {
    int N,K;
    cin>>N>>K;
    vector<P> taxi(N+1);
    REP1(i, N) cin>>taxi[i].first>>taxi[i].second;
    vector<vector<int>> roads(N+1);
    REP(_, K) {
        int s,t;
        cin >> s >> t;
        roads[s].push_back(t);
        roads[t].push_back(s);
    }

    // Build adjacency list with BFS since we can travel farther than just to the next town
    vector<vector<P>> adj(N+1);

    REP1(i, N) {
        // For every town i
        const auto &dests = bfs(roads, i, taxi[i].second);
        for(auto d : dests) {
            adj[i].push_back({taxi[i].first, d});
        }
    }

    const auto &ans = dijkstra(adj, 1);
    cout << ans[ans.size()-1] << endl;
}

