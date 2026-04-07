//https://ac.nowcoder.com/acm/contest/126636/G
#include<bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 2e5 + 10, mod = 998244353;
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

int trie[N * 4][2], cnt[N * 4];
int idex = 1;
int n, k;

void insert(string s){
    int pl = 0;
    for(int i = 0; i < s.length(); i++){
        int t = s[i] - '0';
        auto& x = trie[pl][t];
        if(!x) x = idex++;
        pl = x;
    }
    cnt[pl]++;
}
int s[N];
void dfs(int pl, int cnnt, int x){
    if(cnnt == k) {
        for(int i = 0; i < x; i++) cout << s[i];
        exit(0);
    }
    if(cnnt > k) return;
    for(int i = 0; i < 2; i++){
        if(!trie[pl][i]) continue;
        else {
            s[x++] = i;
            dfs(trie[pl][i], cnnt + cnt[trie[pl][i]], x);
            x--;
        }
    }
}
inline void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insert(s);
    }   
    dfs(0, 0, 0);
    cout << -1 << endl;
}
signed main(){
    int t;
    // cin >> t;
    t = 1;
    while(t--) solve();
    return 0;
}