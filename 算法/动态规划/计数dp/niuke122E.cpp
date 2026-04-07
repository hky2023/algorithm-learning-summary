//https://ac.nowcoder.com/acm/contest/125083/E
#include<bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 2e5 + 10, mod = 1e9 + 7;

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
    vector<int> dp(n + 1, 0);
    //使用双指针维护一个数据结构，将一个区块（元素都相同）的标记到区块首
    vector<int> flag(n + 1, -1);
    for(int i = 1; i <= n;){
        int j = i;
        while(j <= n && a[j] == a[i]) flag[j++] = i;
        i = j;
    }
    for(int i = 1; i <= n; i++){
        if(a[i] <= i - flag[i] + 1) dp[i] = dp[i - a[i]] + 1;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans += dp[i];
    cout << ans << endl;
}
signed main(){
    int t;
    cin >> t;
    // t = 1;
    while(t--) solve();
    return 0;
}