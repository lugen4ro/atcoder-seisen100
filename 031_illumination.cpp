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
vector<point> move_six_first({{0,-1}, {-1,0}, {0,1}, {1,1}, {1,0}, {-1,1}}); 
vector<point> move_six_second({{-1,-1}, {0,-1}, {1,0}, {0,1}, {1,-1}, {-1,0}}); 
struct point_hash { public: size_t operator()(const point &p) const { return hash<string>()(to_string(p.x) + " " + to_string(p.y)); } }; // Define hash function for point so we can use unordered_set

int main(){
    int W,H;
    cin >> W >> H;
    vector<vector<int>> v(H+2, vector<int>(W+2));
    // padding bottom and top
    rep(i, W+2) {
        v[0][i] = 0; 
        v[H+1][i] = 0;
    }

    // padding left and right
    rep(i, H+2) {
        v[i][0] = 0; 
        v[i][W+1] = 0;
    }

    // input
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> v[i+1][j+1];
        }
    }

    // BFS once (since all outside should be one area because of padding)
    queue<point> que;
    set<point> visited;
    point s(0,0);
    que.push(s);
    int walls = 0;

    while (!que.empty()) {

        // Go through all items currently in the queue
        int que_size = que.size();
        for (int i = 0; i < que_size; i++) {

            // Get point from queue
            point p = que.front();
            que.pop();

            // CHECKS
            if (bcn(p.x, 0, H+2) or bcn(p.y, 0, W+2) or visited.count(p) > 0) {
                continue;
            }
            if (v[p.x][p.y] == 1) {
                walls++;
                continue;
            }

            // Add to visited
            visited.emplace(p);

            // Add adjacent points to queue
            vector<point> move;
            if (p.x % 2 == 1) move = move_six_first; 
            else move = move_six_second;
            for(auto m : move) {
                que.push(p + m);
            }
        }
    }
    cout << walls << endl;
}
