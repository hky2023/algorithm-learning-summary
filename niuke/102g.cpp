//我觉得线段树
#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int N = 2e5 + 10;
int pre[N];
inline int get(int l, int r){
    return pre[r] - pre[l - 1];
}
signed main(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n, 0);
    for(auto& i: v) cin >> i;
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + v[i - 1];
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        if(get(l, r) == (1 + (r - l + 1) / 2) * ((r - l + 1) / 2)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}