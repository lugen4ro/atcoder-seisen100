#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// #full-search
// #exhaustive-search

int main(){

    // All combinations
    // O(n^3)

    int n,x;
    cin >> n >> x;
    while(!(n==0 and x==0)) {

        int count = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <= n; j++) {
                for (int k = j+1; k <= n; k++) {
                    if(i+j+k == x) count++;
                }
            }
        }
        cout << count << endl;
        cin >> n >> x;
    }
}

