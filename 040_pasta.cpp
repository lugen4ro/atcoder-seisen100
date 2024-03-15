#include <bits/stdc++.h>
using namespace std;
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define ll long long
#define bc(var, lower, upper) (var>=lower and var<upper) // Boundary check of var with [lower, upper) --> True when within bounds
#define bitcount(n) __builtin_popcountl(long(n))
#define vin(v, N) rep(i,N) cin >> v[i]; // Input 1-d vector
#define vin2(v, N, M) rep(i,N) rep(j,M) cin >> v[i][j]; // Input 2-d vector

// #dynamic-programming
// #knapsack

int main(){
    int N,K;
    cin >> N >> K;
    map<int, int> mp;
    for (int i = 0; i < K; i++) {
        int x,y;
        cin >> x >> y; 
        mp[x] = y;
    }

    // last 2 dimension are there to express the number of ways for each pattern of meals like 11, 23, 31 etc.
    vector<vector<vector<ll>>> dp(N+1,vector<vector<ll>>(4, vector<ll>(4)));

    // Create first slice (Only set one per column)
    rep(k, 1, 4) {
        rep(j, 1, 4) {
            if (j == k) continue;
            if (mp.count(1) > 0) {
                if (k == mp[1]) { 
                    dp[1][j][k] = 1;
                    break;
                }
            } else {
                dp[1][j][k] = 1;
                break;
            }
        }
    }

    rep(i, 2, N+1) {
        rep(j, 1, 4) {
            rep(k, 1, 4) {
                rep(l, 1, 4) {

                    // If meal specifided, skip over those that are different meals
                    if (mp.count(i)>0 and k!=mp[i]) continue;

                    // Calculate value for each cell j,k in slice i
                    if (j == k) {
                        // Same meal twice in a row
                        // Only add previous in same column if it is not same twice in a row one
                        if (k != l) dp[i][j][k] += dp[i-1][l][j];
                    } else {
                        // Not same meal twice in a row
                        dp[i][j][k] += dp[i-1][l][j];
                    }

                    dp[i][j][k] %= 10000;
                }
            }
        }
    }

    // Summarize
    ll ans = 0;
    rep(j, 1, 4) rep(k,1,4) ans += dp[N][j][k];
    cout << ans % 10000 << endl;
}



// Instead of 3d dp, expand into 2d dp 
// Instead of 3x3 grid representing last 2 meals, such as 3->1, 1->3, 2->3 etc.
// Use a length 6 array that holds [1,2,3,11,22,33] where 11 means 1->1, and 1 meaning 2->1 or 3->1

int main2(){
    int N,K;
    cin >> N >> K;
    map<int, int> mp;
    for (int i = 0; i < K; i++) {
        int x,y;
        cin >> x >> y; 
        mp[x-1] = y-1;
    }

    vector<vector<ll>> dp(N, vector<ll>(6));
    if (mp.count(0) > 0) dp[0][mp[0]] = 1;
    else {dp[0][0] = 1; dp[0][1] = 1; dp[0][2] = 1;}

    for (int i = 1; i < N; i++) {

        if (mp.count(i) > 0) {
            if (mp[i] == 0) {
                // 1
                dp[i][0] =  (dp[i-1][1] + dp[i-1][2] + dp[i-1][4] + dp[i-1][5]) % 10000;
                // 11
                dp[i][3] =  (dp[i-1][0]) % 10000;
            }
            if (mp[i] == 1) {
                // 2
                dp[i][1] =  (dp[i-1][0] + dp[i-1][2] + dp[i-1][3] + dp[i-1][5]) % 10000;
                // 22
                dp[i][4] =  (dp[i-1][1]) % 10000;
            }
            if (mp[i] == 2) {
                // 3
                dp[i][2] =  (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4]) % 10000;
                // 33
                dp[i][5] =  (dp[i-1][2]) % 10000;
            }
        } else {
            // 1
            dp[i][0] =  (dp[i-1][1] + dp[i-1][2] + dp[i-1][4] + dp[i-1][5]) % 10000;

            // 2
            dp[i][1] =  (dp[i-1][0] + dp[i-1][2] + dp[i-1][3] + dp[i-1][5]) % 10000;

            // 3
            dp[i][2] =  (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4]) % 10000;

            // 11
            dp[i][3] =  (dp[i-1][0]) % 10000;

            // 22
            dp[i][4] =  (dp[i-1][1]) % 10000;

            // 33
            dp[i][5] =  (dp[i-1][2]) % 10000;
        }
    }


    ll ans = reduce(dp[N-1].begin(), dp[N-1].end()) % 10000;
    cout << ans << endl;

}

