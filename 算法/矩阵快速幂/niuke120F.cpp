//https://ac.nowcoder.com/acm/contest/123788/F
//但是通过97.5%？？
#include<bits/stdc++.h>
#define int long long 

using namespace std;

const int mod = 998244353;

inline int quickmi(int a, int p){
    int ans = 1, jin = a;
    while(p){
        if(p % 2) ans = (ans * jin) % mod;
        p /= 2;
        jin = (jin * jin) % mod;
    }
    return ans;
}
//适合所有的（1，2）（2，2），能够进行的矩阵乘法
inline auto multi_matrix(vector<vector<int>> a, vector<vector<int>> b){
    vector<vector<int>>  c(a.size(), vector<int>(b[0].size(), 0));
    for(int i = 1; i < a.size(); i++){
        for(int j = 1; j < b[0].size(); j++){
            for(int k = 1; k < a[0].size(); k++){
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    return c;
}

inline auto quickmi_matrix(vector<vector<int>> a, int p){
    //a是方阵
    int n = a.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for(int i = 1; i < n; i++){
        ans[i][i] = 1;
    }
    //定义ans和，jin
    auto jin = a;
    while(p){
        if(p % 2) ans = multi_matrix(ans, jin);
        p /= 2;
        jin = multi_matrix(jin, jin);
    }
    return ans;
}
inline void solve(){
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    //计算完整的x有多少个
    int tim = r / n - (l + n - 2) / n;
    //计算x的mod,获得了x的mod
    int x = 0;
    for(int i = 0; i < s.length(); i++) x = (x * 10 + s[i] - '0') % mod;
    // cout << "x" << x << endl;
    //计算10的n次方为a
    int a = quickmi(10, n);
    //矩阵快速幂
    vector<vector<int>> ju(2 + 1, vector<int>(2 + 1, 0));
    ju[1][1] = a, ju[1][2] = x, ju[2][1] = 0, ju[2][2] = 1;
    vector<vector<int>> g(3, vector<int>(2, 0));
    g[1][1] = 0, g[2][1] = 1;
    //注意是左乘；
    g = multi_matrix(quickmi_matrix(ju, tim) , g);
    // cout << "g[1][1]" << g[1][1] << endl;
    //获得了g[1][1]就是中间这一些数的mod
    //现在计算前面l的mod值
    l--;
    int pl = l - l / n * n;
    int tem = 0;
    if(pl != 0){
        for(int i = pl; i < n; i++) tem = (tem * 10 + s[i] - '0') % mod;
    }
    // cout << "tem" << tem << endl;
    //计算l和中间
    tem = (tem * quickmi(10, tim * n) + g[1][1]) % mod;
    //合并剩下的r
    int pr = r - r / n * n;
    int tem1 = 0;
    if(pr != 0){
        for(int i = 0; i < pr; i++) tem1 = (tem1 * 10 + s[i] - '0') % mod;
    }
    tem = (tem * quickmi(10, pr) + tem1) % mod;
    cout << tem << endl;
}
signed main(){
    int t;
    // cin >> t;
    t = 1;
    while(t--) solve();
    return 0;
}