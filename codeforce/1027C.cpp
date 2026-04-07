//最长上升子序列，注意二分的边界，要把不合适的边界排除掉，第26行代码就是
#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int N = 2e5 + 10;
int dp[N];
int tt = -1;
inline void solve(){
    int n;
    cin >> n;
    tt = -1;
    vector<int> v(n, 0);
    for(auto& i: v) cin >> i;
    auto erfen = [&](int x){
        int l = 0, r = tt;
        while(l < r){
            int mid = l + r >> 1;
            if(dp[mid] >= x) r = mid;
            else l = mid + 1;
        }
        return l;
    };
    for(int i = 0; i < n; i++){
        if(!i || dp[tt] + 1 < v[i]) dp[++tt] = v[i];
        else if(dp[tt] + 1 == v[i]) continue;
        else{
            int pl = erfen(v[i]);
            // cout << v[i] << ' ' << dp[0] << endl;
            if(!pl || pl && v[i] - dp[pl - 1] >= 2){
                // cout << "dpfrom" << pl << "change" << endl;
                dp[pl] = v[i];
            }
            
        }
        // for(int i = 0; i <= tt; i++) cout << dp[i] << ' ';
        // puts("");
    }
    cout << tt + 1 << endl;
}
signed main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}