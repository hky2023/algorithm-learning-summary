//错误代码，但是思路没找出什么问题
//后续再补吧
#include<bits/stdc++.h>
#define int long long 

using namespace std;


inline void solve(){
    int n, m;
    cin >> n >> m;
    if(m < n || (1 + n) * n / 2 < m) {
        cout << -1 << endl;
        return;
    }
    vector<bool> is(n + 1, 0);
    int t = m;
    int cnt = 0;
    for(int i = n; i > 1; i--){
        if(t >= i + n - cnt - 1){
            is[i] = 1;
            cnt++;
            t -= i;
        }
    }
    int tt = 0, la = 0;
    for(int i = n; i >= 1; i--){
        if(!tt && is[i]) {
            cout << i << endl;
            tt = 1;
            la = i;
        }
        else if(is[i]){
            cout << la << ' ' << i << endl;
            la = i;
        }
    }
    cout << la << ' ' << 1 << endl;
    is[1] = 1;
    la = 1;
    for(int i = n; i >= 1; i--){
        if(!is[i]){
            cout << la << ' ' << i << endl;
            la = i;
        }
    }
    // puts("");
}
signed main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}