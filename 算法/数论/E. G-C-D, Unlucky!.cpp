//https://codeforces.com/problemset/problem/2126/E
//这道题目我一开始的思路就有问题，我的思路是筛选排除掉不可能的，剩下的默认可以寻找到一个数组
//实际上正确的起始点就是判断该点a[i]能否存在
#include<bits/stdc++.h>
#define int long long 

using namespace std;

inline int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}
inline void solve(){
    int n;
    cin >> n;
    vector<int> p(n, 0), s(n, 0);
    for(auto& i: p) cin >> i;
    for(auto& i: s) cin >> i;
    if(s[0] != p[n - 1]){
        cout << "no" << endl;
        // cout << "pl1" << endl;
        return;
    }
    int g = s[0];//整个数组a的gcd
    for(int i = 0; i < n; i++) {
        if(gcd(p[i], s[i]) != g) {
            cout << "no" << endl; 
            // cout << "pl2" << endl;
            return;
        }
        if(i + 1 < n){
            if(p[i] % p[i + 1] || s[i + 1] % s[i]) {
                cout << "no" << endl;
                return;
            }
        }
    }

    for(int i = 0; i < n; i++){
        //最小公倍数作为a[i],
        int t = p[i] * s[i] / gcd(p[i], s[i]);
        if(i > 0 && i + 1 < n && (gcd(p[i - 1] / p[i], t / p[i]) != 1 || gcd(s[i + 1] / s[i], t / s[i]) != 1)) {
            cout << "no" << endl;
            // cout << "pl3" << endl;
            return;
        }
        else if(i > 0 && gcd(p[i - 1] / p[i], t / p[i]) != 1) {
            cout << "no" << endl;
            return;
        }
        else if(i + 1 < n && gcd(s[i + 1] / s[i], t / s[i]) != 1){
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
    
}
signed main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

