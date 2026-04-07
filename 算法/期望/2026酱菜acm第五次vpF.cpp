//https://codeforces.com/group/3phdu3ZGLS/contest/681470/problem/F
//这道题目使用期望，通过dp进行转化，
//但是有一个特判点就是如果b = 1的情况下，dpi通过dpi - b + 1 （不能利用自身进行转化）转化就失效了
//所以需要特判b = 1的情况，这时候就是考虑如何进行分配一个获得的期望值是多少了，那个时候我是真想不出来
//有q的概率是等同于免费获得一个，这个期望就不会算了。
//但是通过ai分析获得，这是几何分布1 + q + q ^ 2 + q ^ 3 + ... = 1 / (1 - q); （这个值就是几何分布的进行次数期望
//为什么呢？不妨设x 为从当前这 1 朵普通花出发，最终总共能产出的大甜花数量的期望值。
//所以可以获得这么一个等式x = 1 + q * x; 由于必定获得一个，q概率免费返还一个，所以还要继续进入x循环中，x = 1 / （1 - q)
//所以就可以理解这个几何分布了。

#include<bits/stdc++.h>
#define pr pair<int, int>
#define int long long 

using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 10;
const int MX = 1e15 + 10;
inline int quickmi(int a, int p){
    int jin = a, ans = 1;
    while(p){
        if(p % 2) ans = (ans * jin);
        p /= 2;
        jin = (jin * jin);
    }
    return ans;
}


inline void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<vector<long double>> dp(a + 1, vector<long double>(2, 0));

    if(b == 1){
        double p = c / 100.0;
        double q = d / 100.0;
        
        double alpha = max(1.0 + p, 1.0 / (1.0 - q));
        double result = a * alpha;
        
        cout << fixed << setprecision(10) << result;
    
        return;
    }
    for(int i = b; i <= a; i++){
        double mx_0 = max(dp[i - b][0], dp[i - b][1]), mx_1 = max(dp[i - b + 1][1], dp[i - b + 1][0]);
        dp[i][1] = c * (mx_0 + 2) + (100 - c) * (mx_0 + 1);
        dp[i][0] = d * (mx_1 + 1) + (100 - d) * (mx_0 + 1);
        dp[i][1] /= 100;
        dp[i][0] /= 100;
        // cout << "i = " << i << " dp0 " << dp[i][0] << " dp1 " << dp[i][1] << '\n';
    }
    // cout << "dpb " << dp[b][0] << ' ' << dp[b][1] << '\n';
    // cout << "dpb + 1 " << dp[b + 1][0] << ' ' << dp[b + 1][1] << '\n';
    double mx = max(dp[a][0], dp[a][1]);
    cout << fixed << setprecision(15) << mx << '\n';
}
signed main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}