#include<bits/stdc++.h>
#define int long long 

using namespace std;

signed main(){
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size(), n2 = s2.size();
    // cin >> n1 >> n2;
    vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, 0));
    s1 = '0' + s1, s2 = '0' + s2;
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++) {
            dp[i][j] += dp[i - 1][j - 1]; //除去第i个和第j个元素
            dp[i][j] += dp[i][j - 1] - dp[i - 1][j - 1]; //第i个元素单独对dp[i - 1][j - 1]的个数影响
            dp[i][j] += dp[i - 1][j] - dp[i - 1][j - 1]; //第j个元素单独对dp[i - 1][j - 1]的个数影响
            if(s1[i] == s2[j]) dp[i][j] += 1 + dp[i - 1][j - 1]; //两个一起加入的影响
        }
    }
    cout << dp[n1][n2];
    return 0;
}