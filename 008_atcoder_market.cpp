#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// #full-search
// #exhaustive-search

int main(){
    // The best entrance/exit will always be the middle point
    // Because moving from there to left or right we will always increase or keep the total dist

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        ans += abs(a[i] - b[i]);
    }

    sort(all(a));
    sort(all(b));

    // in 
    int in = n / 2;
    for (int i = 0; i < n; i++) {
        ans += abs(a[in] - a[i]);
        ans += abs(b[in] - b[i]);
    }
    cout << ans;
}
