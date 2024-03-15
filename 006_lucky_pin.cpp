#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
template<class itr> void output_array(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr start, itr goal){ for(auto i = start; i != goal; i++){ cin >> (*i); } }

// #full-search
// #exhaustive-search

int N;
string S;

int main(){

    cin >> N >> S;
    set<tuple<char,char,char>> s;
    set<char> s1, s2;
    for (int i = 0; i < N; i++) {
        if (s1.count(S[i]) == 1) continue;
        s2.clear();
        for (int j = i+1; j < N; j++) {
            if (s2.count(S[j]) == 1) continue;
            for (int k = j+1; k < N; k++) {
                s.insert(make_tuple(S[i], S[j], S[k]));
            }
            s2.insert(S[j]);
        }
        s1.insert(S[i]);
    }
    cout << s.size();


        

}
