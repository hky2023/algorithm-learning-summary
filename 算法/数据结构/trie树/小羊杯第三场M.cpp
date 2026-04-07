//https://ac.nowcoder.com/acm/contest/130462/M
//这道题目空间卡的十分紧，我的代码没有过原因在于我没有利用好前缀树的性质，求cnt，实际上只需要记录一维cnt，因为
//走到某一个行，一定是唯一个前缀到达的所以就可以使用一维字母。

#include<bits/stdc++.h>
#define pr pair<int, int>
#define int long long 

using namespace std;

const int mod = 1e9 + 7, N = 1e5 + 10;
inline int quickmi(int a, int p){
    int jin = a, ans = 1;
    while(p){
        if(p % 2) ans = (ans * jin);
        p /= 2;
        jin = (jin * jin);
    }
    return ans;
}

int trie[N * 12][26], cnt[N * 12][26];
int tem = 0;
int st = 0; //表示在trie中的起点。初始在0；
int num = 0; //num表示在trie中的字符串个数。

inline void add(char ch){
    int la_st = st;
    st = ++tem;
    trie[st][ch - 'a'] = la_st;
    cnt[st][ch - 'a'] = num;
}
inline void insert(string s){
    num++;
    int pl = st;
    for(auto i: s){
        int t = i - 'a';
        if(trie[pl][t] != -1){
            cnt[pl][t]++;
            pl = trie[pl][t];
        }
        else trie[pl][t] = ++tem, cnt[pl][t] ++, pl = trie[pl][t];
    }
}

inline int find(string s){
    int pl = st;
    int ans = 0;
    for(auto i: s){
        int t = i - 'a';
        if(trie[pl][t] == -1) break;
        ans += cnt[pl][t];
        pl = trie[pl][t];
    }
    return ans;
}
inline void solve(){
    memset(trie, -1, sizeof trie -1);
    int q;
    cin >> q;
    // string s = "";
    for(int i = 0; i < q; i++){
        int op;
        cin >> op;
        if(op == 1){
            char ss;
            cin >> ss;
            if(num) add(ss);
            // s += ss;
        }
        else if(op == 2){
            string ss;
            cin >> ss;
            reverse(ss.begin(), ss.end());
            insert(ss);
        }
        else {
            string ss;
            cin >> ss;
            reverse(ss.begin(), ss.end());
            cout << find(ss) << '\n';
        }
    }
}
signed main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}