//https://ac.nowcoder.com/acm/contest/120563/J
//思路大致是这样，但是如果直接交这份代码，会96%数据过
//原因在于lg函数浮点数具有误差，如果直接使用int截取，可能会有少部分数据不通过
//如果需要确切得到floor(log(x)),(1)打表，（2）使用位运算查找最大二进制位
// 打表方式：lg[1] = 0, lg[i] = lg[i >> 1] + 1;
//二进制位 int k = 0; while(1ll << (k + 1) <= x) k++;


#include<bits/stdc++.h>
#define int long long 
#define pr pair<int, int>
#define endl '\n'

using namespace std;

const int N = 5e5 + 10, mod = 998244353;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

inline int quickmi(int a, int p){
    int ans = 1, jin = a;
    while(p){
        if(p % 2) ans = (ans * jin) % mod;
        p /= 2;
        jin = (jin * jin) % mod;
    }
    return ans;
}


inline void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < q; i++){
        int x;
        cin >> x;
        int h = (int)log2(x), hn = (int)log2(n);
        if(h != hn) cout << ((int)1 << h) << '\n';
        else {
            cout << n - ((int)1 << h) + 1 << '\n';
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // ini();
    int t;
    cin >> t;
    // t = 1;
    while(t--) solve();
    return 0;
}