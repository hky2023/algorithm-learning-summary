//https://codeforces.com/contest/2193
#include<bits/stdc++.h>
#define int long long 
#define pr pair<int, int>

using namespace std;

const int N = 3e5 + 10, mod = 1e9 + 7;
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

struct node {
    int pl, v;
}p[N];

int mn[N];
inline void solve(){
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++) mn[i] = 1e15;
    vector<int> a(n, 0);
    for(auto& i: a) cin >> i, mn[i] = 1;
    //完全背包(时间会超)
    //调和级数
    for(int i = 1; i <= n; i++){
        if(mn[i] == 1e15) continue;
        for(int j = i; j <= n && j / i <= i; j += i){
            if(mn[j / i] != 1e15) mn[j] = min(mn[j], mn[i] + mn[j / i]);
        }
    }
    for(int i = 1; i <= n; i++) if(mn[i] != 1e15) cout << mn[i] << ' '; else cout << -1 << ' ';
    cout << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while(t--) solve();
    return 0;
}