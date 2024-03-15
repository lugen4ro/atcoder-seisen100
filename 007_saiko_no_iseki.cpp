#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// full-search
// exhaustive-search

int main(){

    int N;
    cin >> N;

    set<pair<int,int>> s;
    vector<pair<int, int>> v;
    int x,y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        v.push_back(pair(x,y));
        s.insert(pair(x,y));
    }

    int  max_surf = 0;

    // For each pair of 2 points, check if the other 2 points to make it a square exist
    // we don't have to check left and right, because we try all permutations --> 1,2 and 2,1
    for (int i = 0; i < N; i++) {
        for (int j =0; j < N; j++) {
            if (i==j) continue;
            int dx = v[i].first - v[j].first;
            int dy = v[i].second - v[j].second;

            if (s.count(make_pair(v[i].first + dy, v[i].second - dx)) 
            and s.count(make_pair(v[j].first + dy, v[j].second - dx))) {
                max_surf = max(max_surf , dx*dx + dy*dy);
            }
        }
    }
    cout << max_surf << endl;
}

