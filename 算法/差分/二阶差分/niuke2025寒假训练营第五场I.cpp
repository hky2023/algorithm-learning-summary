//https://ac.nowcoder.com/acm/contest/130103/I
//差分代表变化情况，这个情况是变化一段区间都是+1，一段区间都是-1，这可以很正常想到对于阶差分数组+1，-1，
//然后进行一次前缀和，获得一个差分数组
//再一次进行差分就获得了实际的高度，唯一注意的是边界处理，边界处理比较需要仔细调试。

#include<bits/stdc++.h>
#define int long long 
#define pr pair<int, int>
#define endl '\n'

using namespace std;

const int N = 2e5 + 10, mod = 1e9 + 7;
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

// const string op = "0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";
struct op{
    int pl, f;
}p[N];
int n, m, h;
inline int check(int k){//判断前k次能否高度达到h
    vector<int> chafenchafen(n + 2, 0);
    for(int i = 1; i <= k; i++){
        int pl = p[i].pl, f = p[i].f;
        //寻找最左边
        if(pl - f < 1){
            //计算出到0要＋多少
            chafenchafen[0] += f - pl;
            chafenchafen[1] -= f - pl;
            chafenchafen[1] += 1;
            chafenchafen[pl + 1] -= 1;
            if(pl + 1 <= n) {
                chafenchafen[pl + 1] -= 1;
                if(pl + 1 + f <= n) chafenchafen[pl + 1 + f] += 1;
            }
        }
        else {
            chafenchafen[pl - f + 1] += 1;
            chafenchafen[pl + 1] -= 1;
            if(pl + 1 <= n) {
                chafenchafen[pl + 1] -= 1;
                if(pl + 1 + f <= n) chafenchafen[pl + 1 + f] += 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        chafenchafen[i] += chafenchafen[i - 1];
    }
    int flag = 0;
    for(int i = 1; i <= n; i++){
        chafenchafen[i] += chafenchafen[i - 1];
        // cout << chafenchafen[i] << ' ';
        if(chafenchafen[i] > h) flag = 1;
    }
    // cout << '\n';
    if(flag) return 1;
    else return 0;
}
inline void solve(){
    cin >> n >> m >> h;
    for(int i = 1; i <= m; i++) cin >> p[i].pl >> p[i].f;
    if(!check(m)) {
        cout << "No" << '\n';
        return;
    }
    int l = 1, r = m;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << "Yes" << '\n';
    cout << l << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // ini();
    int t;
    // cin >> t;
    t = 1;
    while(t--) solve();
    return 0;
}