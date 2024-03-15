#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }


// #full-search
// #exhaustive-search
// #bit-full-search


bool dfs(vector<int> &A, int i,int target){

    // base case
    if (i == A.size()) return false;

    // include ith value
    if (target - A[i] == 0){
        return true;
    } else if (target - A[i] > 0) {
        if (dfs(A, i+1, target - A[i])) return true;
    }

    // do not include ith value
    if (dfs(A, i+1, target)) return true;

    return false;
}


int main(){

    int n, q, m;
    cin >> n;
    vector<int> A(n);
    for (auto i = A.begin(); i != A.end(); i++) {
        cin >> *i;
    }
    cin >> q;
    for (int k = 0; k < q; k++) {
        cin >> m;
        if (dfs(A, 0, m)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
