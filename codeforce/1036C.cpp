#include<bits/stdc++.h>
#define int long long 

using namespace std;

inline int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}
inline void solve(){
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(auto& i: v) cin >> i;
    int gd = 0;
    int dn = -1, up = 1e16;
    for(int i = 1; i < n; ){
        while(i < n && v[i] >= v[i - 1]) i++;
        int j = i - 1;
        while(j >= 0 && v[j] > v[i]) j--;
        for(int t = j + 1; t < i; t++){
            if(!gd) gd = v[t];
            else gd = gcd(gd, v[t]);
        }
        if(dn == -1){
            dn = v[j + 1] / v[j];
        }
        else dn = max(dn, v[j + 1] / v[j]);
        if(up == 1e16){
            up = v[i - 1] / v[i];
        }
        else up = min(up, v[i - 1] / v[i]);
        i++;
    }
    for(int i = dn; i <= up; i++) {
        if(gd % i == 0) {
            cout << i << endl;
            return;
        }
    }
    cout << "无结果" << endl;
}
signed main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}