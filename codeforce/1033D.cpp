//组合数学，觉得很好的题目
//鸽笼原理
//同时还学到了不用打表求某一个较大参数的组合数
//还学到了除法取模需要转化为乘以逆元方法

#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int mod = 1e9 + 7, N = 1e5 + 10;
// int c[N][N];肯定会超，都1e5
//使用公式法：c[n][m] = n! / (n - m)! * m!;

// void build(){
//     c[0][0] = 1;
//     for(int i = 1; i < N; i++){
//         c[i][0] = 1;
//         for(int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
//     }    
// }
int modpower(int a, int b, int mod){
    int res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
inline void solve(){
    int a, b, k;
    cin >> a >> b >> k;
    //每一列中至少存在a个相等的元素，
    int n = (k * (a - 1) + 1) % mod;
    //列的种类，只和n个中的a个相同的有关，其他不一样不妨碍可以组合成y矩阵
    //我们只关心这a个相同的元素是什么值，什么位置有多少种不一样的方案
    //可以说是被行给约束了
    int kind = k;
    for(int i = 0; i < a; i++){
        kind *= n - i;
        kind %= mod;
        kind *= modpower((a - i) % mod, mod - 2, mod) % mod;
        kind %= mod;
    }
    // int kind = (c[n][a] * k) % mod
    int m = (kind * (b - 1) + 1) % mod;
    cout << n << ' ' << m << endl;
}
signed main(){
    // build();
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}