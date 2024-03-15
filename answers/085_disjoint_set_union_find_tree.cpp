#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353; // 1000000007
const int INF = 1e9;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define VIN(v, N) REP(i,N) cin >> v[i]; // Input 1-d vector
#define VIN2(v, N, M) REP(i,N) REP(j,M) cin >> v[i][j]; // Input 2-d vector
#define BITCOUNT(n) __builtin_popcountl(long(n))
#define ALL(x) (x).begin(), (x).end()
#define BC(var, lower, upper) ((var)>=lower and (var)<upper) // Boundary check of var with [lower, upper)
#define PRINT(x) cout << (x) << endl;

template<class itr> void PRINT_ARR(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void CINS(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// #ruisekiwa
// #prefix-sum

class UnionFind {
    // 0-indexed

    vector<int> parent;
    vector<int> rank;
    int num_components;

    public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i=0; i<n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        num_components = n;
    }

    int find(int x) {
        int p = parent[x];
        while (p != parent[p]) {
            parent[p] = parent[parent[p]]; // Path compression
            p = parent[p];
        }
        return p;
    }

    bool isSameComponent(int x, int y) {
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
        num_components--;
        return true;
    }

    int getNumComponents() {
        return num_components;
    }
};


int main() {
    int n,q;
    cin>>n>>q;
    UnionFind uf(n);
    REP(i, q) {
        int com,x,y;
        cin>>com>>x>>y;
        if (com == 0) {
            // Unite
            uf._union(x, y);

        } else {
            // Same
            if (uf.isSameComponent(x, y)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}
