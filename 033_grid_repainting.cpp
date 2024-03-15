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

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> v(H, vector<char>(W));
    int count = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> v[i][j];
            if (v[i][j] == '#') count++;
        }
    }

    queue<point> que;
    que.push(point(0,0));
    set<point> visited;
    int level = 0;

    while (!que.empty()) {

        // Go through all items currently in the queue
        int que_size = que.size();
        for (int i = 0; i < que_size; i++) {

            // Get point from queue
            point p = que.front();
            que.pop();

            // Is goal?
            if (p == point(H-1,W-1)) {
                cout << (H*W - count - level - 1) << endl;
                return 0;
            }

            // Add adjacent points to queue if valid
            for(auto m : move_cross) {

                // Next point
                point np = p + m;

                // Check if valid
                if (bcn(np.x, 0, H) or bcn(np.y, 0, W) or visited.count(np)>0 or v[np.x][np.y]=='#') continue;

                visited.emplace(np);
                que.push(p + m);
            }
        }
        level++;
    }
    // No way
    cout <<  -1 << endl;
}
