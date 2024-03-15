#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// #full-search
// #exhaustive-search

int main(){

    string S;
    cin >> S;

    int L = 0;
    int max_len = 0;
    for (int R = 0; R < S.size(); R++) {
        if (S[R] == 'A' || S[R] == 'C' || S[R] == 'G' || S[R] == 'T') {
            max_len = max(max_len, R+1-L);
        } else {
            L = R+1;
        }
    }

    cout << max_len;
    

}
