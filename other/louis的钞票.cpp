//思路是生成元，
#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int N = 257;
int dp[N];
signed main(){
    int n;
    cin >> n;
    vector<int> a(n, 0);
    int mod = 1e9;
    for(auto& i: a) cin >> i, mod = min(mod, i);
    for(int i = 0; i < N; i++) dp[i] = 1e18;
    //对于每一种钞票都可以用最小钞票值取余分类，分出mod个集合【0，1，... mod - 1】；
    //对于每一种钞票最多可以用mod次自身叠加获得其他%mod的值，等于mod次数是生成元
    //对于每一个md[i],如果不等于1e18,每一个>= md[i]余数等于i的数都可以用md[i] 通过加若干次mod获得，理解思路了吧。
    for(auto i: a){
        for(int j = 1; j <= mod; j++) dp[(i * j) % mod] = min(dp[(i * j) % mod], i * j); 
    }
    //这是自身通过叠加可以获得最小

    //通过已有的达到多种钞票叠加凑出最小值，类似于背包。
    for(int i = 0; i < n; i++){
        for(int j = 0; j < mod; j++){
            for(int k = 1; k <= mod; k++){
                dp[j] = min(dp[j], dp[((j - k * a[i]) % mod + mod) % mod] + k * a[i]);
            }
        }
    }
    int ans = -1;
    for(int i = 0; i < mod; i++) ans = max(ans, dp[i]);
    if(ans == 1e18) {
        cout << 0;
    }
    else cout << ans - mod;
    return 0;
}