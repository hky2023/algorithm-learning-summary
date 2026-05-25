//https://codeforces.com/contest/2227/problem/G

#include<bits/stdc++.h>
#define pr pair<int, int>
#define int long long 

using namespace std;
const int mod = 1e9 + 7;

class BIT{
    public:
        
        void add(int pl, int t){//在pl位置增加t并且维护树状数组
            for(pl; pl <= size_; pl += lowbit(pl)){
                tree_[pl] += t;
            }
        }
        int query(int pl){ //查询1-pl的前缀和
            int ans = 0;
            for(pl; pl; pl -= lowbit(pl)) ans += tree_[pl];
            return ans;
        }
        BIT(int size) : size_(size), tree_(size + 10, 0) {}
        
    private: 
        int size_;
        vector<int> tree_;
        int lowbit(int x) { return -x & x; }
};

inline void solve(){
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(auto& i: a) cin >> i;
    vector<int> pre(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        if(i % 2) pre[i] = pre[i - 1] + a[i - 1];
        else pre[i] = pre[i - 1] - a[i - 1];
    }
    //交错前缀和。
    // vector<int> ji, ou;
    // for(int i = 0; i <= n; i++) if(i % 2) ji.push_back(pre[i]); else ou.push_back(pre[i]);
    // //如果有重复元素会怎么样？需要去重吗？
    // //不需要，去重了也可以，但是没有必要

    // sort(ji.begin(), ji.end());
    // sort(ou.begin(), ou.end());
    // int n1 = ji.size(), n2 = ou.size();
    // auto find1 = [&](int x){
    //     int l = 0, r = n1 - 1;
    //     while(l < r){
    //         int mid = l + r >> 1;
    //         if(ji[mid] >= x) r = mid;
    //         else l = mid + 1;
    //     }
    //     return l + 1;
    // };
    // auto find2 = [&](int x){
    //     int l = 0, r = n2 - 1;
    //     while(l < r){
    //         int mid = l + r >> 1;
    //         if(ou[mid] >= x) r = mid;
    //         else l = mid + 1;
    //     }
    //     return l + 1;
    // };
    vector<int> lisan;
    for(int i = 0; i <= n; i++) lisan.push_back(pre[i]);
    int nn = lisan.size();
    sort(lisan.begin(), lisan.end());

    auto find = [&](int x){
        int l = 0, r = nn - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(lisan[mid] >= x) r = mid;
            else l = mid + 1;
        }
        return l + 1;
    };
    // cout << "lisan" << '\n';
    // for(auto i: lisan) cout << i << ' ';
    // cout << '\n';
    // cout << "pre" << '\n';
    // for(auto i: pre) cout << i << ' ';
    // cout << '\n';
    BIT t1(nn), t2(nn);
    int ans = 0;
    for(int i = 0; i <= n; i++){
        //奇数应该找偶数，因为这是前缀和，你比大小就表示是相差
        // cout << "i = " << i << '\n';
        if(i % 2){
            int pl = find(pre[i]);
            // cout << "t2.query" << t2.query(pl - 1) << '\n';
            ans += t2.query(pl - 1);
            t1.add(pl, 1);
        }
        //偶数应该找奇数
        else {
            int pl = find(pre[i]);
            // cout << "t1.query" << t1.query(pl) << '\n';
            ans += (i + 1) / 2 - t1.query(pl);
            t2.add(pl, 1);
        }
    }
    cout << ans << '\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}