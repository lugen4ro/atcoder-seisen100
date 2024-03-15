#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// #full-search
// #exhaustive-search
// #bit-full-search

int main(){

    // Input
    int N,M;
    cin >> N >> M;
    set<pair<int, int>> st;
    int x,y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        st.emplace(make_pair(x-1,y-1));
    }

    unsigned long ans = 0;

    vector<int> v;
    for (int bit = 0; bit < (1<<N); bit++) {

        // Create index combination like (0,2,3)
        v.clear();
        for (int i = 0; i < N; i++) {
            if (bit & (1<<i)) {
                v.push_back(i);
            }
        }

        // Check if condition is met (Everybody knows each other)
        bool valid = true;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i+1; j < v.size(); j++) {
                if (!st.count(make_pair(v[i], v[j]))) valid = false;
            }
        }

        if (valid) ans = max(ans, v.size());
    }

    cout << ans << endl;


}
