#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int N = 30;
int sum[N];//chafen前缀和
int mn[N]; //差分数组

inline void solve(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    memset(mn, 0, sizeof mn);
    for(int i = 0; i < n; i++) {
        // sum[a[i] - 'a'] ++;
        mn[a[i] - 'a' + 1] += 1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= 27; j++) sum[j] = sum[j - 1] + mn[j];
        if(!sum[b[i] - 'a']){
            if(!sum[b[i] - 'a' + 1]){
                cout << "No" << endl;
                return;
            }
            else {
                mn[b[i] - 'a' + 1]--;
            }
        }
        else{
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}
signed main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}