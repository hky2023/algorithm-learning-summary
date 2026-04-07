#include<bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 1e3 + 10, M = 2e5 + 10;
int ned[N];
int dp[M], kuai[M];
inline void solve(){
    int k;
    cin >> k;
    
    cout << dp[k] + kuai[k] - 1 << endl;
}
signed main(){
    for(int i = 1; i < N; i++) ned[i] = i * (i + 1) / 2;
    memset(dp, 0x3f3f3f3f, sizeof dp);
    memset(kuai, 0, sizeof kuai);
    dp[0] = 0;

    for(int i = 1; i < N; i++){
        for(int j = ned[i]; j <= M - 1; j++) {
            // dp[j] = min(dp[j], dp[j - ned[i]] + i);
            if(dp[j] + kuai[j] > dp[j - ned[i]] + i + kuai[j - ned[i]] + 1){
                dp[j] = dp[j - ned[i]] + i;
                kuai[j] = kuai[j - ned[i]] + 1;
            }
        }
    }
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}