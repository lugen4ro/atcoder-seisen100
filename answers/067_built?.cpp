#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef tuple<int,int,int,int> T4;
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


/******************** Union-Find (Disjoint-Set) ********************/
// Methods:
//  - find(int x) - Returns root parent of x
//  - _union(int x, int y) - Union trees that x and y belong to. Return false if already belonging to same tree, otherwise true.
//  - is_same_tree(int x, int y) - Returns true if x and y belong to the same tree
//  - get_num_trees(int x) - Returns the number of trees
// MUST BE 0-indexed
// Time Complexity: find / union --> O(logV),  if union every edge --> O(ElogV)
class UnionFind {

    vector<int> parent;
    vector<int> rank; // root has rank = 0
    int num_trees;

    public:

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i=0; i<n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        num_trees = n;
    }

    int find(int x) {
        int p = parent[x];
        while (p != parent[p]) {
            parent[p] = parent[parent[p]]; // Path compression
            p = parent[p];
        }
        return p;
    }

    bool is_same_tree(int x, int y) {
        // Get parent of x and y
        int p1 = find(x), p2 = find(y);

        if (p1 == p2) return true;
        else return false;
    }

    // Union is a reserved keyword in C++, so we use _union instead
    bool _union(int x, int y) {

        // Get parent of x and y
        int p1 = find(x), p2 = find(y);

        // Already belong to same set
        if (p1 == p2) return false;

        // Union the sets x and y belong to
        if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
        } else if (rank[p1] < rank[p2]) {
            parent[p1] = p2;
        } else {
            parent[p1] = p2;
            rank[p2]++;
        }
        num_trees--;
        return true;
    }

    int get_num_trees() {
        return num_trees;
    }
};

/******************** Kruskal (Minimum-Spanning-Tree) ********************/
// @param edges: vector of tuples (weight, node1, node2)
// @param  V: number of vertices
// @return: edges of MST; vector of tuples (weight, node1, node2)
// Must be a fully connected graph
// MUST BE 0-indexed (Because of UnionFind)
// Time Complexity: O(ElogE) = O(ElogV^2) = O(ElogV) for removing every edge from minHeap
ll kruskal(vector<T> &edges, int V) {

    ll ans=0;

    // Return edges of Minimum Spanning Tree 
    vector<T> mst; // Tuple --> (weight, node1, node2)

    // Initialize min heap with all edges
    priority_queue<T, vector<T>, greater<T>> pq;
    for(auto e : edges) pq.emplace(e);

    // Use UnionFind to detect loops
    UnionFind uf(V);

    while(uf.get_num_trees() > 1) {

        // Get edge with smallest weight
        auto [w,s,t] = pq.top(); pq.pop(); // weight, node1, node2

        // Add edge if s and t do not belong to same tree yet
        if (uf._union(s, t)) {
            //// PROCESS EDGE
            ans+=w;
        }
    }
    return ans;
}

int main() {

    int n;
    cin>>n;
    vector<P> v1(n);
    vector<P> v2(n);
    REP(i, n) {
        int x,y;
        cin>>x>>y;
        v1[i] = {x,i};
        v2[i] = {y,i};
    }
    sort(ALL(v1));
    sort(ALL(v2));

    vector<T> edges;
    REP(i, n-1) {
        edges.push_back({abs(v1[i].first-v1[i+1].first), v1[i].second, v1[i+1].second});
        edges.push_back({abs(v2[i].first-v2[i+1].first), v2[i].second, v2[i+1].second});
    }

    ll ans = kruskal(edges, n);
    cout << ans << endl;



}
