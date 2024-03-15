#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }


// #full-search
// #exhaustive-search
// #bit-full-search


int main(){

    int R,C;
    cin >> R >> C;
    vector<vector<int>> v(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        cins(all(v[i]));
    }

    int ans = 0;

    vector<int> comb;
    for (int bit = 0; bit < (1<<R); bit++) {
        comb.clear();

        // Create all combinations such as [0,0,0,0] --> [1,1,1,1]
        for (int i = 0; i < R; i++) {
            if (bit & (1<<i)) {
                comb.push_back(1);
            } else {
                comb.push_back(0);
            }
        }

        // Count number of ones per column
        int total = 0;
        for (int i = 0; i < C; i++) {
            int zeros = 0;
            for (int j = 0; j < R; j++) {
                if (comb[j] == 0) {
                    zeros += v[j][i]==0 ? 1 : 0;
                } else {
                    zeros += v[j][i]; // if flipped, count 1 as it will become a 0
                }
            }

            // Either flip or no flip the column
            total += max(zeros, R-zeros);
        }
        ans = max(ans, total);
    }

    cout << ans << endl;


}
