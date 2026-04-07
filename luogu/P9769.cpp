//关于背包问题，二重循环内外循环顺序
//结论完全背包  既可先物品再容积，又可先容积再物品，都可以用一维dp数组，
////！！！这里结论错误，不一样，只有在求完全背包最大价值最大组合个数，最小组合个数，方案数不适用
//01背包 一维dp数组只能先物品再容积，先容积再物品只能用二维数组了（？？？）目前认为不行了
//代码
#include<bits/stdc++.h>
#define int long long 

using namespace std;
int y, n, m;
const int N = 5e6 + 10;
int dp[N];
int q[N];
signed main(){
    cin >> y >> n >> m;
    vector<int> b(m, 0);
    for(auto& i: b) cin >> i;
    memset(dp, 0x3f3f, sizeof dp);
    dp[0] = 0;
    int hh = -1, tt = 0;
    for(int i = 0; i <= y; i++){
        // for(int j = 1; j <= n && j <= i; j++) dp[i] = min(dp[i], dp[i - j] + 1);
        for(int j = 0; j < m; j++) {
            if(i % b[j] == 0) dp[i] = min(dp[i], dp[i / b[j]] + 1);
        }
        while(hh <= tt && q[hh] < i - n + 1) hh++;
        while(hh <= tt && dp[q[tt]] >= dp[i]) tt--;
        q[++tt] = i;
        dp[i + 1] = dp[q[hh]] + 1;
       //由于这里是用dp[i - n + 1] ~ dp[i]更新dp[i + 1], 所以乘法dp更新dp[i]需要先做
    }
    cout << dp[y] << endl;
    return 0;
}