#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// #full-search
// #permutations

int main(){

    // Input
    int N;
    cin >> N;
    vector<int> x(N);
    vector<int> y(N);
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        v[i] = i;
    }

    double running_avg = 0;
    double count = 0;

    // All permutations
    do {
        double dist = 0;
        for (int i = 0; i < N-1; i++) {
            dist += sqrt(pow(x[v[i]]-x[v[i+1]], 2) + pow(y[v[i]]-y[v[i+1]], 2));
        }

        // calculate running average
        running_avg = (count/(count+1)) * running_avg + dist/(count+1);
        count += 1;

    } while(next_permutation(v.begin(), v.end()));

    // double has 15.95 digits precision so do 15
    cout << fixed << setprecision(15) << running_avg << endl;


}
