//https://ac.nowcoder.com/acm/contest/126647/E
#include<bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 1e6 + 10, mod = 998244353;
const double PI = 3.14159265358979324;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
struct node {
    int x, y, a, b;
};

inline void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<vector<int>>> gra(n + 1, vector<vector<int>> (m + 1, vector<int>(2, 0)));
    for(int i = 0; i < k; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        gra[x1][y1][1] = gra[x2][y2][0] = 1;
    }
    //状态设计dp[n][m][3][2], (n, m)表示坐标，[3]中的0表示没有使用时停，1表示已经使用时停的第一秒，2表示用完时停2秒，[2]中的0表示偶时刻，1表示奇时刻
    vector<vector<vector<vector<int>>>> is(n + 1, vector<vector<vector<int>>> (m + 1, vector<vector<int>> (4, vector<int> (2, 0))));
    vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>> (m + 1, vector<vector<int>> (4, vector<int> (2, 1e9))));
    dp[1][1][0][1] = 0;
    queue<node> q;
    q.push({1, 1, 0, 1}), is[1][1][0][1] = 1;
    while(q.size()){
        auto t = q.front();
        q.pop();
        int x = t.x, y = t.y, a = t.a, b = t.b;
        is[x][y][a][b] = 0;
        //b1不选择使用
        if(!a || a == 2){
            int b1 = b ^ 1;
            for(int i = 0; i < 4; i++){
                int xx = x + dx[i], yy = y + dy[i];
                if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && !gra[xx][yy][b1]){
                    if(dp[xx][yy][a][b1] > dp[x][y][a][b] + 1){
                        dp[xx][yy][a][b1] = dp[x][y][a][b] + 1;
                        if(!is[xx][yy][a][b1]) {
                            is[xx][yy][a][b1] = 1;
                            q.push({xx, yy, a, b1});
                        }
                    }
                }
            }
        }
        if(a >= 0 && a < 2) {
            for(int i = 0; i < 4; i++){
                int xx = x + dx[i], yy = y + dy[i];
                if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && !gra[xx][yy][b]){
                    if(dp[xx][yy][a + 1][b] > dp[x][y][a][b] + 1){
                        dp[xx][yy][a + 1][b] = dp[x][y][a][b] + 1;
                        if(!is[xx][yy][a + 1][b]) {
                            is[xx][yy][a + 1][b] = 1;
                            q.push({xx, yy, a + 1, b});
                        }
                    }
                }
            }
        }
    }
    int ans = min(dp[n][m][0][0], min(dp[n][m][0][1], min(dp[n][m][1][0], min(dp[n][m][1][1], min(dp[n][m][2][0], dp[n][m][2][1])))));
    if(ans == 1e9){
        cout << -1 << '\n';
    }
    else cout << ans << '\n';

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}