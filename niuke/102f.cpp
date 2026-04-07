//这道题目是102e的进化，需要在e题目的基础上输出最佳方案
//我们的e题目使用整数划分最优方案，同时需要记录上last数组来进行还原和记录最优解
//为什么这种在动态规划背包问题中的记录last有效，如果dp[pl1]的last是由dp[pl2]更新获得
//所以pl2 < pl1, 如果在判断下一个物品时，pl2的最优解方案进行变更，dp[pl2]的last变化了
//由其最优更新得到的dp[pl1]一定会由某一个pl，其中pl < pl1,可能是pl1，也可能不是，保证了其正确
#include<bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 1e3 + 10, M = 2e5 + 10;
int ned[N];
int dp[M], la[M];
inline void solve(){
    int k;
    cin >> k;
    int pl = k;
    while(la[pl]) {
        for(int i = 0; i < la[pl]; i++) cout << 1;
        // cout << 0;
        pl = pl - ned[la[pl]];
        if(la[pl]) cout << 0;
    }
    puts("");
}
signed main(){
    for(int i = 1; i < N; i++) ned[i] = i * (i + 1) / 2;
    memset(dp, 0x3f3f3f3f, sizeof dp);
    // memset(kuai, 0, sizeof kuai);
    dp[0] = 0;

    for(int i = 1; i < N; i++){
        for(int j = ned[i]; j <= M - 1; j++) {
            // dp[j] = min(dp[j], dp[j - ned[i]] + i);
            if(dp[j] > dp[j - ned[i]] + i + 1){
                dp[j] = dp[j - ned[i]] + i + 1;
                // kuai[j] = kuai[j - ned[i]] + 1;
                la[j] = i;
            }
        }
    }
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}