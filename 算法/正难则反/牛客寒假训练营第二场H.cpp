//https://ac.nowcoder.com/acm/contest/128312/H

#include<bits/stdc++.h>
#define int long long 
#define pr pair<int, int>
#define endl '\n'

using namespace std;

const int N = 5e5 + 10, mod = 998244353;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

inline int quickmi(int a, int p){
    int ans = 1, jin = a;
    while(p){
        if(p % 2) ans = (ans * jin) % mod;
        p /= 2;
        jin = (jin * jin) % mod;
    }
    return ans;
}

inline void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> pre(n + 1, 0);
    unordered_map<int, int> mp;
    vector<int> dp(n + 1, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(mp[a[i]] == 0){
            mp[a[i]] = i;
            pre[i] = 0;
        }
        else pre[i] = mp[a[i]], mp[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        // ans += (i - pre[i]) * (n + 1 - i);
        // ans += (i - pre[i]) - 1;
        ans += (1 + n + 1 - i) * (n + 1 - i) / 2 * (i - pre[i]);
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // ini();
    int t;
    cin >> t;
    // t = 1;
    while(t--) solve();
    return 0;
}