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
    int n,m;
    cin >> n >> m;
    vector<int> k(m);
    vector<vector<int>> s(m);
    vector<int> p(m);

    for (int i = 0; i < m; i++) {
        cin >> k[i];
        s[i].resize(k[i]);
        cins(all(s[i]));
    }
    cins(all(p));


    int ans = 0;

    // Bit full search
    vector<int> v(n);
    for (int bit = 0; bit < (1<<n); bit++) {

        // Create vector v with all combinations like 0,0,0,0 -> 1,1,1,1;
        for (int i = 0; i < n; i++) {
            if (bit & (1<<i)) {
                v[i] = 1;
            } else {
                v[i] = 0;
            }
        } 

        // Check if combination v fullfills condition
        int sum;
        bool valid = true;
        for (int i = 0; i < m; i++) {
            sum = 0;
            for (int j = 0; j < s[i].size(); j++) {
                sum += v[s[i][j]-1];
            }
            if (sum % 2 != p[i]) {
                valid = false;
                break;
            }
        }

        if (valid) ans += 1;
    }

    cout << ans << endl;

}
