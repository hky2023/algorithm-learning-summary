//https://codeforces.com/group/3phdu3ZGLS/contest/692970/my
#include<bits/stdc++.h>
#define pr pair<pair<int,int>, int>
#define prr pair<int, int>
#define int long long 

using namespace std;
const int mod = 1e9 + 7;
//vector<vector<int>> 动态分配实现太重，会影响效率
struct mat{
    int a00, a01, a10, a11;
};
// inline int zuzhuang(int a, int tim){
//     int res = 0;
//     for(int i = 0; i < tim; i++) res = res * 10 + a;
//     return res;
// }
// inline int jin(int tim){
//     int res = 1;
//     for(int i = 0; i < tim; i++) res *= 10;
//     return res;
// }
mat factory(mat a1, mat a2){
    
    mat ans = {((a1.a00 * a2.a00) % mod + (a1.a01 * a2.a10) % mod) % mod, ((a1.a00 * a2.a01) % mod + (a1.a01 * a2.a11) % mod) % mod, ((a1.a10 * a2.a00) % mod + (a1.a11 * a2.a10) % mod) % mod, ((a1.a10 * a2.a01) % mod + (a1.a11 * a2.a11) % mod) % mod};
    return ans;
}
mat quick_mi(mat a, int p){
    
    mat ans = {1, 0, 0, 1};
    mat jin = a;
    while(p){
        if(p % 2) ans = factory(ans, jin);
        p /= 2;
        jin = factory(jin, jin);
    }
    return ans;
}
inline void juzhengfactory(int tim, int num, mat& fin){
    //先将这个矩阵进行快速幂相乘。
    //然后将快速幂结果与ans相乘。
    
    mat jichu = {10, 0, num, 1};
    fin = factory(fin, quick_mi(jichu, tim));
}
inline void solve(){
    int m;
    cin >> m;
    vector<int> cnt(10, 0);
    for(auto& i: cnt) cin >> i;
    vector<int> ned(10, 0);
    int tt = m;
    //获得构造需要的数字总计数组。
    if(cnt[0] && m == 1){
        cout << 0 << '\n';
        return;
    }
    for(int i = 1; i < 10; i++) {
        if(cnt[i]) {
            ned[i] = 1;
            cnt[i] -= 1;
            tt--;
            break;
        }
    }
    for(int i = 0; i < 10 && tt; i++){
        if(tt >= cnt[i]) ned[i] += cnt[i], tt -= cnt[i];
        else {
            ned[i] += tt;
            tt = 0;
        }
    }
    // cout << "ned" << '\n';
    // for(int i = 0; i < 10; i++) cout << ned[i] << ' ';
    // cout << '\n';
    // if(ned[0] == m) {
    //     cout << 0 << '\n';
    //     return;
    // }
    //最终获得的结果。
    int ans = 0;
    for(int i = 1; i < 10; i++) {
        if(ned[i]) {
            ned[i]--;
            ans = i;
            break;
        }
    }
    // cout << "ans" << '\n';
    // cout << ans << '\n';
    // cout << "ned" << '\n';
    // for(int i = 0; i < 10; i++) cout << ned[i] << ' ';
    // cout << '\n';
    // vector<vector<int>> fin = {
    //     {ans, 1},
    //     {0, 0}
    // };
    mat fin = {ans, 1, 0, 0};
    
    for(int i = 0; i < 10; i++){
        // int ji9 = zuzhuang(i, 9);
        // int jin9 = jin(9);
        // juzhengfactory(ned[i] / 9, ji9, jin9);
        // int ji_left = zuzhuang(i, ned[i] % 9);
        // int jin_left = jin(ned[i] % 9);
        // juzhengfactory(1, ji_left, jin_left);
        juzhengfactory(ned[i], i, fin);
    }
    cout << fin.a00 << '\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}