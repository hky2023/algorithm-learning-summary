//这道题目可以想到线性基，由于N不超过60，就可以使用ll进行状态压缩
//问可以由这一些数异或和成多少种不同的数
//利用线性基获得一队最简异或数，个数为n，然后答案就是2 ^ n
//你问我为什么？难道不会出现重复吗？我的回答就是不会
//这个最简式子类似于质因数分解中的质数，如果存在两种方案获得一个数
//其必定不是最简。
#include<bits/stdc++.h>
#define int long long 

using namespace std;

const int mod = 2008;
struct liner_base{
    public:
        liner_base(): base(61, 0) {}
        int insert(int x){
            for(int i = 60; i >= 0 && x; i--){
                if(((int)1 << i) & x){
                    if(base[i]){
                        x ^= base[i];
                    }
                    else {
                        base[i] = x;
                        return 1;
                    }
                }
            }
            return 0;
        };
        vector<int> base;
};
inline void solve(){
    int n, m;
    cin >> n >> m;
    liner_base B;
    int tim = 0;
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        int x = 0;
        for(int j = 0; j < n; j++){
            if(s[j] == 'O'){
                x = (x << 1) + 1;
            }
            else {
                x = x << 1;
            }
        }
        if(B.insert(x)) tim++;
    }
    int ans = 1;
    for(int i = 0; i < tim; i++){
        ans = (ans * 2) % mod;
    }
    cout << ans << '\n';
}
signed main(){
    int t;
    // cin >> t;
    t = 1;
    while(t--) solve();
    return 0;
}