// //求导解法
// #include<bits/stdc++.h>
// #define int long long 
// #define pr pair<double, double>

// using namespace std;

// signed main(){
//     int n;
//     cin >> n;
//     vector<pr> v(n, {0, 0});
//     for(auto& i: v) cin >> i.first >> i.second;
//     double ans = 0;
//     //表达式求导后等于零只有一个解，一定是开口向上的类型，如果开口大于等于0可选，否则选择0.
//     for(int i = 1; i < n; i++){
//         double e = sqrt(pow(v[i].first - v[i - 1].first, 2) + pow(v[i].second - v[i - 1].second, 2));
//         double k = max(0., -log2(1.0 / log(2) / e));
//         //这里的定义域别忘记了，k >= 0.;
//         ans += 2 * k + 2 * e / pow(2, k);
//         // cout << k << endl;
//     }
//     cout << fixed << setprecision(6) << ans << endl;
//     return 0;
// }


//三分法求解。

#include<bits/stdc++.h>
#define int long long 
#define pr pair<double, double>

using namespace std;

signed main(){
    int n;
    cin >> n;
    vector<pr> v(n, {0, 0});
    for(auto& i: v) cin >> i.first >> i.second;
    auto cacu = [&](double k, double e){
        return k * 2 + 2 * e / pow(2, k);
    };
    double ans = 0;
    for(int i = 1; i < n; i++){
        double e = sqrt(pow(v[i].first - v[i - 1].first, 2) + pow(v[i].second - v[i - 1].second, 2));
        double l = -402.4922, r = -l;
        while(r - l > 1e-6){
            double lf = l / 3 * 2 + r / 3, rg = l / 3 + r / 3 * 2;
            auto ll = cacu(lf, e), rr = cacu(rg, e);
            if(ll > rr) l = lf;
            else if(ll < rr) r = rg;
            else l = lf, r = rg;
        }
        double k = max(0., l);
        ans += cacu(k, e);
    }
    // int ans = 0;
    cout << fixed << setprecision(8) << ans << endl;
    return 0;
}
