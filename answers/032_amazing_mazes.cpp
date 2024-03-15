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
    struct hash
    {
        size_t operator()(const point& point) const
        {
            size_t xHash = std::hash<int>()(point.x);
            size_t yHash = std::hash<int>()(point.y) << 1;
            return xHash ^ yHash;
        }
    };
};
vector<point> move_cross({{0,1}, {0,-1}, {1,0}, {-1,0}}); // Move left, right, top, bottom
struct point_hash { public: size_t operator()(const point &p) const { return hash<string>()(to_string(p.x) + " " + to_string(p.y)); } }; // Define hash function for point so we can use unordered_set

int main(){

    int W,H;
    cin >> W >> H;
    while(!(W==0 and H==0)){

        vector<vector<int>> hori(H, vector<int>(W-1));
        vector<vector<int>> vert(H-1, vector<int>(W));
        for (int i = 0; i < 2*H-1; i++) {
            if (i % 2 == 0) {
                // horizontal input
                for (int j = 0; j < W-1; j++) {
                    cin >> hori[i/2][j];
                }
            } else {
                // vertical input
                for (int j = 0; j < W; j++) {
                    cin >> vert[i/2][j];
                }
            }
        }

        queue<point> que;
        point start = {0,0};
        que.push(start);
        set<point> visited;
        int level = 1;
        bool finish = false;

        while (!que.empty()) {

            // Go through all items currently in the queue
            int que_size = que.size();
            for (int i = 0; i < que_size; i++) {

                // Get point from queue
                point p = que.front();
                que.pop();

                // Is goal?
                if (p == point(H-1,W-1)) {
                    cout << level << endl;
                    finish = true;
                    break;
                }

                // Add adjacent points to queue
                for(auto m : move_cross) {

                    // Check if valid
                    if (bcn((p+m).x, 0, H) or bcn((p+m).y, 0, W) or visited.count(p+m)>0) continue;

                    // horizontal move possible ?
                    if (abs(m.y)>0 and hori[p.x][min(p.y, p.y+m.y)] == 1) continue; 

                    // vertical move possible ?
                    if (abs(m.x)>0 and vert[min(p.x, p.x + m.x)][p.y] == 1) continue; 

                    // Can move to
                    que.push(p + m);

                    // Add to visited
                    visited.emplace(p + m);
                }
            }
            if (finish) break;
            level++;
        }
        if (!finish) cout << 0 << endl; // No path
        cin >> W >> H;
    }
}
