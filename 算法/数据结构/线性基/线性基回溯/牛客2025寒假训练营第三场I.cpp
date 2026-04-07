//https://ac.nowcoder.com/acm/contest/120563/I

//线性基本身就是n个数选择0，1系数序列相乘，异或获得k
//实际上线性基每一个基的意义就是等同于，若干个选择01序列相乘，最大值为该位的数。实现huo数组本应该就和前面的使用异或。
#include<bits/stdc++.h>
#define int long long 
#define pr pair<int, int>
#define endl '\n'

using namespace std;

const int N = 5e5 + 10, mod = 998244353;
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
struct liner_base{
    public: 
        vector<int> base;
        vector<int> ying;
        vector<int> huo;
        int final;
        // vector<int> ans;
    public: 
        liner_base(): base(63, 0), ying(63, -1), huo(63, 0) {};
        int insert(int x, int pl) {
            //或临时
            int tem = 0;
            for(int i = 62; i >= 0; i--){
                if(((int)1 << i) & x) {
                    if(base[i]){
                        x ^= base[i];
                        //判断子集不是简单的取或，需要进行异或
                        //需要都异或，而非取|获得子集（直接取|，只能代表该子集能够构造）
                        //在这里异或体现最简，如果是偶数次的系数，可以直接不使用该数进行构造
                        //huo[i]就代表最简可以利用前面的多少个数进行构造，如果不是最简的话，后面的final就不确定是否最简
                        //你可以试想一下如果一个异或序列，第二个使用偶数次的异或，你因此将其包括为最终的序列，明显等同于零，你没有考虑到，结果甚至可能不为0.
                        tem ^= huo[i];
                    }
                    else {
                        base[i] = x;
                        ying[i] = pl;
                        tem ^= 1 << i;
                        huo[i] = tem;
                        return 1;
                    }
                }
            }
            return 0;
        };
        int insert_(int x) {
            final = 0;
            for(int i = 62; i >= 0; i--){
                if(((int)1 << i) & x) {
                    if(base[i]){
                        x ^= base[i];
                        final ^= huo[i];
                    }
                    else {
                        // base[i] = x;
                        // ying[i] = pl;
                        return 0;
                    }
                }
            }
            return 1;
        };
};

inline void solve(){
    int n;
    cin >> n;
    vector<int> a(n, 0), b(n, 0);
    for(auto& i: a) cin >> i;
    for(auto& i: b) cin >> i;
    vector<int> t(n, 0);
    for(int i = 0; i < n; i++) t[i] = a[i] ^ b[i];
    //假设一开始选择a1 ^ a2 ^ a3 ^ ... ^ an = k;
    //if k == 0 then ans -> a
    //else pick bi to replace ai, equal to k ^ a[i] ^ b[i];
    //也就是说原题等价于能否从t数组选择若干个其异或和等于k。
    //线性基
    liner_base tt;
    for(int i = 0; i < n; i++) tt.insert(t[i], i);
    int sum = 0;
    for(auto i: a) sum ^= i;
    if(!sum) {
        for(auto i: a) cout << i << ' ';
        cout << '\n';
        return;
    }
    if(tt.insert_(sum)){
        // for(auto i: tt.ans) a[i] = b[i];
        for(int i = 62; i >= 0; i--) {
            if(((int)1 << i) & tt.final) a[tt.ying[i]] = b[tt.ying[i]];
        }
        for(auto i: a) cout << i << ' ';
        cout << '\n';
        return;
    }
    else {
        cout << -1 << '\n';
        return;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // ini();
    int t;
    cin >> t;
    // t = 1;
    while(t--) solve();
    return 0;
}