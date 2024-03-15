#include <bits/stdc++.h>
using namespace std;
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }
#define all(x) (x).begin(), (x).end()
#define rep(i, N) for(int i=0;i<(N);++i)
#define rep1(i, N) for(int i=1;i<=(N);i++)
#define ll long long

// #binary-search
// #binary-search-range

/* 
    Utilize binary search for range to find optimal value
    This allows halfing the search space everytime
    Just set a value and examine if it is possible to achieve
*/

int main(){

   // Inputs
    int N;
    cin >> N;
    vector<int> h(N),s(N);
    rep(i,N) cin >> h[i] >> s[i];

    // Solution
    ll left = 0, right = 1e15;
    ll mid;

    while (left < right){

        // Can we achieve a score of mid?
        mid = (left + right) / 2;

        vector<ll> v;
        bool possible = true;
        rep(i, N) {
            // time where ballon will be equal to or less than mid
            // So, if shot down within breach_time, it's fine
            if (mid < h[i]) possible = false; // Cannot be caught later since -0.341 --> 0 as integer
            ll breach_time = (mid - h[i]) / s[i];
            v.push_back(breach_time);
        }

        // Check if possible
        sort(all(v));
        rep(i, N){
            if (v[i] < i) {
                possible = false;
                break;
            }
        }

        if (possible) right = mid;
        else left = mid + 1;
    }

    // left == right, so both is fine here
    // mid is wrong because the last change could have been left = mid + 1 --> mid = left-1
    cout << right << endl;

}
