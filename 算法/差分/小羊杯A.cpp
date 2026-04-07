//https://ac.nowcoder.com/acm/contest/130462/A
//关于差分复原至少需要多少次操作,还是写过很多这种题目



#include<bits/stdc++.h>
#define pr pair<int, int>
#define int long long 

using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 10;
inline int quickmi(int a, int p){
    int jin = a, ans = 1;
    while(p){
        if(p % 2) ans = (ans * jin);
        p /= 2;
        jin = (jin * jin);
    }
    return ans;
}

inline void solve(){
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(auto& i: a) cin >> i;
    vector<int> v;
    for(int i = n / 2; i < n; i++) v.push_back(a[i] - a[n - i - 1]);
    for(int i = (int)v.size() - 1; i >= 1; i--) v[i] = v[i] - v[i - 1];
    // cout << "chafen" << '\n';
    // for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    // cout << '\n';
    int ans = 0, pre = v[0];
    for(int i = 1; i < v.size(); i++){
        if(pre * v[i] < 0) ans += min(abs(pre), abs(v[i]));
        pre += v[i];
        // cout << "ans =" << ans << '\n';
    }
    ans += abs(pre);
    cout << ans << '\n';
}
signed main(){
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}