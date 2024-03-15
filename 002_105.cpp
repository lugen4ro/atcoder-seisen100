#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// #full-search
// #exhaustive-search

int N;

int main(){

    cin >> N;
    int ans = 0;
    for (int n = 1; n <= N; n=n+2) {
        int count = 0;
        for (int x = 1; x <= n ; x++) {
            if (n % x == 0) count++;
        }
        if (count == 8) ans += 1;
    }
    cout << ans;

}

