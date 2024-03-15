#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }
typedef long long LL;

// #full-search
// #exhaustive-search

int A,B,C,X,Y;

int main(){

    cin >> A >> B >> C >>X >> Y;

    LL min_price = numeric_limits<long long>::max();
    for (int i = 0; i <= max(X,Y); i++) {
        LL price = max(A*(X-i), 0) + max(B*(Y-i), 0) + C*(2*i);
        min_price = min(min_price, price);
    }

    cout << min_price;
}
