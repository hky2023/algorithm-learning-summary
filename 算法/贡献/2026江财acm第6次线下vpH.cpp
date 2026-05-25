//https://codeforces.com/group/3phdu3ZGLS/contest/691656/problem/H
#include<bits/stdc++.h>
#define pr pair<int, int>
#define PI 3.1415926
#define int long long 

using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 10;
const int MX = 1e15 + 10;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
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
    string s;
    cin >> s;
    int n = s.length();
    s = ' ' + s;
    vector<vector<int>> tim(n + 1, vector<int> (2, 0));
    //tim表示所有包含i的时间奇偶性次数，
    if(s[1] == '0') tim[1][0]++;
    else tim[1][1]++;
    for(int i = 2; i <= n; i++){
        if(s[i] == '0'){
            tim[i][0]++;
            tim[i][0] += tim[i - 1][1] + tim[i - 1][0];
        }
        else {
            tim[i][1]++;
            tim[i][1] += tim[i - 1][1] + tim[i - 1][0];
        }
    }
    //tim表示的是i前面有多少个点到达i的奇偶性个数，分别通过奇偶性个数与i位置0或者1以及后面点个数获得每一个点的贡献值。
    // for(int i = 1; i <= n; i++) {
    //     cout << "i" << i << '\n';
    //     cout << tim[i][0] << ' ' << tim[i][1] << '\n';
    // }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == '0'){
            ans += tim[i - 1][0] * 2 * (n - i + 1) + tim[i - 1][1] * (n - i + 1) + 2 * (n - i + 1);
        }
        else {
            ans += tim[i - 1][1] * 2 * (n - i + 1) + tim[i - 1][0] * (n - i + 1) + n - i + 1;
        }
    }
    cout << ans << '\n';
    // cout << '\n' << '\n';
}
signed main(){
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}