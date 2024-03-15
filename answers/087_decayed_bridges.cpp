#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353; // 1000000007
const int INF = 1e9;
const ll LINF = 1e18;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
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
    vector<ll> size; // size of the component
    int num_components;

    public:
    ll fuben;
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n);
        size.resize(n, 1);
        for (int i=0; i<n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        num_components = n;
        fuben = 1LL * n * (n-1) / 2;
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

        // update fuben
        fuben -= size[p1] * size[p2];

        // Union the sets x and y belong to
        if (rank[p1] > rank[p2]) {
            parent[p2] = p1;
            size[p1]+=size[p2];
        } else if (rank[p1] < rank[p2]) {
            parent[p1] = p2;
            size[p2]+=size[p1];
        } else {
            parent[p1] = p2;
            rank[p2]++;
            size[p2]+=size[p1];
        }

        num_components--;
        return true;
    }

    int getNumComponents() {
        return num_components;
    }
};


int main() {
    int N,M;
    cin>>N>>M;
    vector<ll> va(M);
    vector<ll> vb(M);

    REP(i, M) {
        int a,b;
        cin>>a>>b;
        va[i] = a-1; // Make 0-indexded
        vb[i] = b-1;
    }

    UnionFind uf(N);
    vector<ll> ans(M);
    RREP(i, M) {
        ans[i] = uf.fuben;
        uf._union(va[i], vb[i]);
    }
    REP(i, M) {
        cout << ans[i] << endl;
    }
}
