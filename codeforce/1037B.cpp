//dp做法,错误：状态表示不清晰
#include<bits/stdc++.h>
#define int long long 

using namespace std;

inline void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 2, 0);
    // for(auto& i: v) cin >> i;
    for(int i = 1; i <= n; i++) cin >> v[i];
    vector<vector<int>> dp(n + 2, vector<int> (k + 1, 0));
    for(int i = 1; i <= n + 1; i++){
        // dp[i][0] = max(dp[i - 1][0], dp[i - 1][k] + 1);
        dp[i][0] = dp[i - 1][0];
        if(i != 1 && !v[i - 1]) dp[i][0] = max(dp[i][0], dp[i - 1][k] + 1);
        for(int j = 1; j <= k; j++){
            if(!v[i]){
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    cout << dp[n + 1][0] << endl;
}
signed main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}