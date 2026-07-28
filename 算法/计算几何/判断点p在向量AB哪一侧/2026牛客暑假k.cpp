//向量叉积应用，如果p在向量左边则ap × bp > 0 同向则 = 0, 右侧则 < 0;
#include<bits/stdc++.h>
#define int long long 
#define pr pair<int, int>

using namespace std;

inline void solve(){
    int n;
    cin >> n;
    vector<pr> v;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    for(int i = 2; i < n; i++){
        pr ap = {v[i].first - v[i - 2].first, v[i].second - v[i - 2].second};
        pr bp = {v[i].first - v[i - 1].first, v[i].second - v[i - 1].second};
        auto t = ap.first * bp.second - ap.second * bp.first;
        if(t > 0) cout << "LEFT" << ' ';
        else if(t < 0) cout << "RIGHT" << ' ';
        else cout << "STRAIGHT" << ' ';
    }
    cout << '\n';
}
signed main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}