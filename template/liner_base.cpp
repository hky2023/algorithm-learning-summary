#include<bits/stdc++.h>
#define int long long 

using namespace std;

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
}
signed main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}