//二进制拆分多重背包优化
// #include<bits/stdc++.h>
// #define int long long 

// using namespace std;
// const int N = 1e2 + 10, M = 4e4 + 10;
// int n, W;
// int v[N], w[N], m[N];
// int dp[M];
// signed main(){
    
//     cin >> n >> W;
//     for(int i = 0; i < n; i++) cin >> v[i] >> w[i] >> m[i];
//     for(int i = 0; i < n; i++){
//         for(int j = 0; (1 << j) <= m[i]; j++){
//             for(int k = W; k >= (1 << j) * w[i]; k--) dp[k] = max(dp[k], dp[k - (1 << j) * w[i]] + (1 << j) * v[i]);
//             m[i] -= (1 << j);
//         }
//         if(m[i]) for(int k = W; k >= m[i] * w[i]; k--) dp[k] = max(dp[k], dp[k - m[i] * w[i]] + m[i] * v[i]);
//     }
//     cout << dp[W];
//     return 0;
// }
//单调队列优化多重背包
//时间复杂度为n * W
#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int N = 1e2 + 10, M = 4e4 + 10;
int n, W;
int v[N], w[N], m[N];
int dp[2][M];//滚动数组
int q[M];
signed main(){
    cin >> n >> W;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i] >> m[i];
    // memset(dp, 0x3f3f, sizeof dp);
    // dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        int vol = w[i], num = m[i], val = v[i];
        for(int j = 0; j < vol; j++){//j是每一组
            int hh = 0, tt = -1;
            for(int k = j; k <= W; k += vol){
                while(hh <= tt && q[hh] <= k - num * vol) hh++;
                while(hh <= tt && dp[(i % 2) ^ 1][q[tt]] + (k - q[tt]) / vol * val <= dp[(i % 2) ^ 1][k]) tt--;
                q[++tt] = k;
                if(k + vol <= W) dp[i % 2][k + vol] = dp[(i % 2) ^ 1][q[hh]] + (k + vol - q[hh]) / vol * val;
            }
        }
    }
    cout << dp[n % 2][W];
    return 0;
}