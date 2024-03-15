#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// #binary-search

int main(){

    // Just do binary search multiple times

    // Input
    int n, q;
    cin >> n;
    vector<int> s(n);
    cins(all(s));
    cin >> q;
    vector<int> t(q);
    cins(all(t));

    // Solution 
    int ans = 0;

    for(auto target : t) {
        if (binary_search(all(s), target)) {
            ans += 1;
        }
    }
    cout << ans << endl;

}
