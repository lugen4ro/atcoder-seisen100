#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// #binary-search

int main(){

    // Input
    int dist, n, m;
    cin >> dist >> n >> m;
    vector<int> k(m), d(n);
    d[0] = 0;
    cins(d.begin()+1, d.end()); // places of shops
    cins(all(k)); // places of orders

    // Solution
    int ans = 0;

    // Sort shops
    sort(all(d));
    d.push_back(dist); // add main shop

    for(auto target : k) {
        auto lb = lower_bound(all(d), target);

        if (*lb - target > target - *(lb-1)) {
            ans += target - *(lb-1);
        } else {
            ans += *lb - target;
        }
    }

    cout << ans << endl;

    



}
