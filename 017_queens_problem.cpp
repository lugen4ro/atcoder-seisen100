#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// #full-search
// #permutations

int main(){

    // Input
    int k;
    cin >> k;
    vector<int> x(k), y(k);
    for (int i = 0; i < k; i++) {
        cin >> x[i] >> y[i];
    }

    vector<int> v(8);
    for (int i = 0; i < 8; i++) {
        v[i] = i;
    }

    set<pair<int, int>> st;
    do {
        // Insert all points into set
        st.clear();
        for (int i = 0; i < 8; i++) {
            st.insert(make_pair(i, v[i])); // r, c
        }

        // Check if the k points are in there
        bool valid = true;
        for (int i = 0; i < k; i++) {
            if (!st.count(make_pair(x[i], y[i]))) valid = false;
        }

        if (!valid) continue;

        // All k points are included, so check if no diagonally overlap
        valid = true;
        vector<pair<int, int>> move = {{1,1}, {1,-1}, {-1,-1}, {-1,1}};
        for(auto p : st) {
            for(auto m : move) {
                int nx = p.first + m.first;
                int ny = p.second + m.second;
                while (nx>=0 and nx<8 and ny>=0 and ny<8) {
                    if (st.count(make_pair(nx, ny))) valid = false;
                    nx = nx + m.first;
                    ny = ny + m.second;
                }
            }
        }
        if (valid) {
            // Found solution
            // Sorted set so should be in order of (0,4), (1,2) ...
            for(auto p : st) {
                for (int i = 0; i < p.second; i++) {
                    cout << ".";
                }
                cout << "Q";
                for (int i = p.second+1; i < 8; i++) {
                    cout << ".";
                }
                cout << endl;
            }
            exit(0);
        }

    } while(next_permutation(all(v)));




}
