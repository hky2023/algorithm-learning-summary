// //动态规划记录路径可以但是进行标记同时利用标记作为dp传递的
// //控制，会让dp朝着偏离预想方向发展
// #include<bits/stdc++.h>
// #define int long long 

// using namespace std;
// const int N = 1e5 + 10;
// int q[N], pre[N], dp[N];
// int n, k;
// signed main(){
//     cin >> n >> k;
//     vector<int> v(n + 5, 0);
//     for(int i = 1; i <= n; i++) cin >> v[i];
//     // for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + v[i];
//     int hh = 0, tt = -1;
//     // int ans = 0;
//     dp[1] = v[1], pre[1] = 1;
//     dp[0] = 0, pre[0] = 0;
//     for(int i = 0; i <= n; i++){
//         while(hh <= tt && q[hh] < i - 1) hh++;
//         while(hh <= tt && dp[q[tt]] <= dp[i]) tt--;
//         q[++tt] = i;
//         dp[i + 2] = dp[q[hh]] + v[i + 2];
//         pre[i + 2] = 1;
//         if(pre[i + 1] < k && dp[i + 1] + v[i + 2] > dp[i + 2]) {
//             pre[i + 2] = pre[i + 1] + 1;
//             dp[i + 2] = dp[i + 1] + v[i + 2];
//         }
//     }
//     // cout << ans;
//     for(int i = 1; i <= n; i++) cout << dp[i] << ' ' << pre[i] << endl;

//     // cout << dp[n] << ' ' << pre[n];
//     // return 0;
//     return 0;
// }