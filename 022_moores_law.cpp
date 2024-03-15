#include <bits/stdc++.h>
using namespace std;
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }
#define all(x) (x).begin(), (x).end()
#define rep(i, N) for(int i=0;i<(N);++i)
#define rep1(i, N) for(int i=1;i<=(N);i++)
#define ll long long

// #binary-search
// #ternary-search
// #trichotomy

// 三分法
int main(){

    double p;
    cin >> p;

    // lambda function
    auto get_time = [](double x, double p) {
        return x + (p / pow(2, x / 1.5)); 
    };

    // values for x (time)
    double left = 0;
    double right = 100; // With this time, could solve anything in 1 year
    double mid1, mid2, t1, t2;

    // Since problem requires the error to be within 10^8
    while (left < right - 1e-9) {
        mid1 = (2*left+right) / 3;
        mid2 = (left+2*right) / 3;
        t1 = get_time(mid1, p);
        t2 = get_time(mid2, p);

        if (t1 < t2) {
            // go left two thirds
            right = mid2;
        } else {
            // go right two thirds
            left = mid1;
        }
    }
    cout << fixed << setprecision(15) << t1 << endl;
}
