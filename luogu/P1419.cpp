//原来单调队列不一定是维护（1-n）还可以（n - k———— n）的区间和最大
//原来的是维护不超过k个连续的数之和最大，利用前缀和，区间长度定为k，是固定（l，r）中的l
//现在的是维护区间长度为【s，t】，同样前缀和，区间长度为t-s
//不过是固定（l，r）中的r，区间为（r-t，r-s）
#include<bits/stdc++.h>
#define int long long 

using namespace std;
int n;
int s, t;
const int N = 1e5 + 10;
double val[N], pre[N], tem[N];
int q[N];
inline int check(double x){
    memcpy(tem, val, sizeof val);
    for(int i = 1; i <= n; i++) tem[i] -= x, pre[i] = pre[i - 1] + tem[i];
    // for(int i = 1; i <= n; i++) cout << pre[i] << ' ';
    // puts("");
    int hh = 0, tt = -1;
    double ans = -1e18;
    for(int i = 0; i <= n; i++){
        while(hh <= tt && q[hh] < i - t + s) hh++;
        while(hh <= tt && pre[q[tt]] >= pre[i]) tt--;
        q[++tt] = i;
        if(i + s <= n) ans = max(pre[i + s] - pre[q[hh]], ans);
    }
    return ans >= 0;
}
signed main(){
    cin >> n;
    cin >> s >> t;
    for(int i = 1; i <= n; i++) cin >> val[i];
    double l = -1e4, r = 1e4;
    while(r - l > 1e-6){
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(3) << l << endl;
    // cout << check(1);
    return 0;
}   