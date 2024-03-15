#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// #full-search
// #permutations

int main(){

    // Input
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    cins(all(p));
    cins(all(q));

    vector<int> v;
    for (int i = 1; i < n+1; i++) {
        v.push_back(i);
    }

    int a,b;
    int count = 1;
    do {
        if (p == v){
            a = count;
        }
        if (q == v){
            b = count;
        }
        count++;
    } while(next_permutation(v.begin(), v.end()));

    cout << abs(a-b) << endl;



}
