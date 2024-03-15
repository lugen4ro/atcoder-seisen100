#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// #binary-search

int main(){

    // Inputs
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n);
    cins(all(a));
    cins(all(b));
    cins(all(c));

    // Solution
    long long ans = 0;

    sort(all(a));
    sort(all(b));
    sort(all(c));

    vector<long long> prefix_sum(n);

    // a and b
    for (int i = 0; i < n; i++) {

        // number of elements smaller than b[i] in a
        auto lb = lower_bound(all(a), b[i]);
        auto tmp = (lb) - a.begin(); 

        if (i==0) {
            prefix_sum[i] = tmp;
        } else {
            prefix_sum[i] = prefix_sum[i-1] + tmp;
        }
    }

    // b and c
    for (int i = 0; i < n; i++) {
        auto lb = lower_bound(all(b), c[i]);

        // If not no combination
        if (lb-b.begin() > 0) {
            ans += prefix_sum[lb-b.begin()-1];
        }
    }

    cout << ans << endl;

    



}
