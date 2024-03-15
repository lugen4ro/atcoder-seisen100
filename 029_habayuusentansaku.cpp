#include <bits/stdc++.h>
using namespace std;
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }
#define all(x) (x).begin(), (x).end()
#define rep(i, N) for(int i=0;i<(N);++i)
#define rep1(i, N) for(int i=1;i<=(N);i++)
#define ll long long
#define vin(v, N) rep(i,R) rep(j,N) cin >> v[i][j]; // Input 1-d vector
#define vin2(v, N, M) rep(i,N) rep(j,M) cin >> v[i][j]; // Input 2-d vector
#define bc(var, lower, upper) (var>=lower and var<upper) // Boundary check of var with [lower, upper) --> True when within bounds
#define bcn(var, lower, upper) (var<lower or var>=upper) // Boundary check of var with [lower, upper) --> True when outside of bounds
#define bitcount(n) __builtin_popcountl(long(n))

// #BFS

struct point {
    int x; int y;
    point(int x=0, int y=0) : x(x), y(y) {}
    point operator + (const point& p) const {return point(x + p.x, y + p.y);}
    point operator - (const point& p) const {return point(x - p.x, y - p.y);}
    bool operator == (const point& p) const {if (x == p.x and y == p.y) return true; else return false;}
    bool operator != (const point& p) const {if (x != p.x or y != p.y) return true; else return false;}
    bool operator < (const point& p) const {if (x < p.x or (x==p.x and y<p.y)) return true; else return false;} // For set (ordered)
};
vector<point> move_cross({{0,1}, {0,-1}, {1,0}, {-1,0}}); // Move left, right, top, bottom
vector<point> move_diag({{0,1}, {0,-1}, {1,0}, {-1,0}, {-1,-1}, {-1,1}, {1,-1}, {1,1}}); // Move all directions including diagonally
struct point_hash { public: size_t operator()(const point &p) const { return hash<string>()(to_string(p.x) + " " + to_string(p.y)); } }; // Define hash function for point so we can use unordered_set

int main(){

    // Input
    int R,C;
    point s,g;
    cin >> R >> C;
    cin >> s.y >> s.x;
    cin >> g.y >> g.x;
    s = s - point(1,1);
    g = g - point(1,1);
    vector<vector<char>> v(R, vector<char>(C));
    vin2(v,R,C);

    queue<point> que;
    que.push(s);
    // unordered_set<point, point_hash> visited;
    set<point> visited;
    int level = 0;

    while (!que.empty()) {

        // Go through all items currently in the queue
        int que_size = que.size();
        for (int i = 0; i < que_size; i++) {

            // Get point from queue
            point p = que.front();
            que.pop();

            // Check if valid
            if (bcn(p.x, 0, C) or bcn(p.y, 0, R) or visited.count(p)>0 or v[p.y][p.x]!='.') continue;

            // Add to visited
            visited.emplace(p);

            // Is goal?
            if (p == g) {
                cout << level << endl;
                return 0;
            }

            // Add adjacent points to queue
            for(auto m : move_cross) {
                que.push(p + m);
            }
        }
        level++;
    }
}
