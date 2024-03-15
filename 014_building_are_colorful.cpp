#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }


// #full-search
// #exhaustive-search
// #bit-full-search

int main(){

    int N,K;
    cin >> N >> K;
    vector<int> a(N);
    cins(all(a));

    long long ans = numeric_limits<long long>::max();
    vector<int> v(N);
    for (int bit = 0; bit < (1<<N); bit++) {
        for (int i = 0; i < N; i++) {
            if (bit & (1<<i)) {
                v[i] = 1;
            } else {
                v[i] = 0;
            }
        }

        if (reduce(all(v)) < K ) continue; 

        int max_height = 0;
        long long cost = 0;
        for (int i = 0; i < N; i++) {
            if (v[i]) {
                // Included in combination
                // Make sure it's higher than max height
                if (a[i] <= max_height) cost += max_height - a[i] + 1;
                max_height = max(max_height+1, a[i]);
            } else {
                max_height = max(max_height, a[i]);
            }
        }
        ans = min(ans, cost);
    }
    cout << ans << endl;


}
