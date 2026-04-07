//https://vjudge.net/contest/795141#problem/C
//这道题目我的思路大致可以找出一下关键点
//暴力枚举每一个0
//如果前面已经将t作为p，后面的0，遇到p就跳过，贪心角度
//每一个合法p 0 p的贡献从后往前预处理一个weight_p[i]表示从（i - n - 1）有多少个不同的非0数量。
//后面的0只需要将前面的0之间的点更新。
//唯一难度是在于还需要预处理出每一个0点位置后面第一个p出现的位置（就在这里栽了跟头，时间复杂度和空间复杂度都是O（n ^ 2）如果出现在0的数量和不同数的个数都是1e5的数量级就爆了)

//代码如下，但是mlt了，如果补mlt也会tle仔细分析一下时间复杂度和空间复杂度。
// #include<bits/stdc++.h>
// #define int long long 
// #define pr pair<int, int>

// using namespace std;

// const int mod = 1e9 + 7;
// inline int quickmi(int a, int p){
//     int ans = 1, jin = a;
//     while(p){
//         if(p % 2) ans = ans * jin;
//         p /= 2;
//         jin = jin * jin;
//     }
//     return ans;
// }

// inline void solve(){
//     int n;
//     cin >> n;
//     vector<int> a(n, 0);
//     for(auto& i: a) cin >> i;
//     vector<int> zero;
//     for(int i = 0; i < n; i++) if(!a[i]) zero.push_back(i);
//     vector<map<int, int>> mp(zero.size());
//     //完成ne数组含义
//     for(int i = (int)zero.size() - 1; i >= 0; i--){
//         int ed = n - 1;
//         if(i != (int)zero.size() - 1){
//             mp[i] = mp[i + 1];
//             ed = min(ed, zero[i + 1] - 1);
//         }
//         for(int j = ed; j >= zero[i] + 1; j--) mp[i][a[j]] = j;
//     }
//     //完成后缀有多少个不同数（每一个位置q的权值可取）
//     unordered_set<int> st;
//     vector<int> weight_q(n, 0);
//     //q为正整数
//     for(int i = n - 1; i >= 0; i--) {
//         if(a[i]) st.insert(a[i]);
//         weight_q[i] = st.size();
//     }
//     //最终
//     unordered_map<int, int> used;
//     int ans = 0;
//     for(int i = 0; i < zero.size(); i++){
//         int st = 0;
//         if(i != 0){
//             st = max(st, zero[i - 1] + 1);
//         }
//         for(int j = st; j <= zero[i] - 1; j++){
//             if(!used[a[j]]){
//                 used[a[j]] = 1;
//                 int ne = mp[i][a[j]];
//                 if(ne == 0 || ne == n - 1) continue;
//                 ans += weight_q[ne + 1];
//             }
//         }
//     }
//     cout << ans << '\n';
// }
// signed main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0), cout.tie(0);
//     int t;
//     cin >> t;
//     while(t--) solve();
//     return 0;
// }

//我过的，其实只要找到前两个相同元素就可以了
#include<bits/stdc++.h>
#define int long long 
#define pr pair<int, int>

using namespace std;

const int mod = 1e9 + 7;
inline int quickmi(int a, int p){
    int ans = 1, jin = a;
    while(p){
        if(p % 2) ans = ans * jin;
        p /= 2;
        jin = jin * jin;
    }
    return ans;
}

inline void solve(){
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(auto& i: a) cin >> i;
    vector<int> weight_q(n + 1, 0);
    unordered_set<int> st;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i]) st.insert(a[i]);
        weight_q[i] = st.size();
    }
    vector<unordered_map<int, int>> pl(2);
    int zero = -1, ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0) zero = i;
        else {
            if(pl[0].find(a[i]) == pl[0].end()) pl[0][a[i]] = i;
            else {
                if(zero > pl[0][a[i]] && pl[1].find(a[i]) == pl[1].end()) {
                    pl[1][a[i]] = i;
                    ans += weight_q[i + 1];
                }
            }
        }
    }
    cout << ans << '\n';
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}