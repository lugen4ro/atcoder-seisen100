#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// #full-search
// #exhaustive-search

int main(){

    int m;
    cin >> m;
    vector<int> xp(m), yp(m);
    for (int i = 0; i < m; i++) {
        cin >> xp[i] >> yp[i];
    }

    int n;
    cin >> n;
    set<pair<int, int>> st;
    vector<int> xs(n), ys(n);
    for (int i = 0; i < n; i++) {
        cin >> xs[i] >> ys[i];
        st.insert(make_pair(xs[i], ys[i]));
    }

    // for each star in the sky, check if it is a match
    for (int i = 0; i < n; i++) {
        int dx = xs[i] - xp[0];
        int dy = ys[i] - yp[0];

        // check if other stars exist
        bool flag = true;
        for (int j = 0; j < m; j++) {
            if (st.count(make_pair(xp[j]+dx, yp[j]+dy)) == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << dx << " " << dy << endl;
            return 0;
        }
    }
}

