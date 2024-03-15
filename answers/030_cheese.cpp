#include <bits/stdc++.h>
using namespace std;
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }
#define all(x) (x).begin(), (x).end()
#define rep(i, N) for(int i=0;i<(N);++i)
#define rep1(i, N) for(int i=1;i<=(N);i++)
#define ll long long
#define bc(var, lower, upper) (var>=lower and var<upper) // Boundary check of var with [lower, upper) --> True when within bounds
#define bcn(var, lower, upper) (var<lower or var>=upper) // Boundary check of var with [lower, upper) --> True when outside of bounds
#define bitcount(n) __builtin_popcountl(long(n))
#define vin(v, N) rep(i,R) rep(j,N) cin >> v[i][j]; // Input 1-d vector
#define vin2(v, N, M) rep(i,N) rep(j,M) cin >> v[i][j]; // Input 2-d vector

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
    int H,W,N;
    cin >> H >> W >> N;
    vector<vector<char>> v(H, vector<char>(W));

    point s;
    vector<point> factories;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            v[i][j] = c; 
            if (c != '.' and c != 'X') {
                if (c == 'S') s = {i,j};
                else factories.push_back({i,j});
            }
        }
    }

    // Do BFS N times
    queue<point> que;
    set<point> visited;
    int level = 0;

    for (int n = 1; n < N+1; n++) {
        // Search for factory n

        visited.clear();
        queue<point>().swap(que); // Empty queue
        que.emplace(s);
        bool found = false;

        // BFS
        while (!que.empty()) {

            // Go through all items currently in the queue
            int que_size = que.size();
            for (int i = 0; i < que_size; i++) {

                // Get point from queue
                point p = que.front();
                que.pop();

                // Check if valid
                if (bcn(p.x, 0, H) or bcn(p.y, 0, W) or visited.count(p)>0 or v[p.x][p.y]=='X') continue;

                // Add to visited
                visited.emplace(p);

                // Is goal?
                if (v[p.x][p.y] - '0' == n) {
                    found = true;
                    s = p; // next start is this point
                    break;
                }

                // Add adjacent points to queue
                for(auto m : move_cross) {
                    que.push(p + m);
                }
            }
            if (found) break;
            level++;
        }
    }
    cout << level << endl;
}
