//没必要这么复杂，直接将所有权值从大到小排序，然后从大到小判断周围4个点是否存在先手必败太，如果有就是先手必胜，否则先手必败
//由于比他大的数一定在他之前确定状态，所以更新正确。
#include<bits/stdc++.h>
#define int long long 
#define pr pair<int, int>

using namespace std;

const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
inline void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int> (m + 1, 0));
    vector<vector<int>> is(n + 1, vector<int> (m + 1, 0));
    vector<vector<int>> num(n + 1, vector<int> (m + 1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> g[i][j];
    vector<pr> fnl;
    //多源bfs；
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            int fg = 1;
            int cnt = 0;
            for(int k = 0; k < 4; k++) {
                int xx = i + dx[k], yy = j + dy[k];
                if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && g[xx][yy] > g[i][j]) fg = 0, cnt++;
            }
            if(fg) fnl.push_back({i, j});
            num[i][j] = cnt;
        }
        //zheli
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++) cout << num[i][j] << ' ';
    //     cout << '\n';
    // }
    priority_queue<pair<int, pair<int, pair<int, int>>>, vector<pair<int, pair<int, pair<int, int>>>>, greater<pair<int, pair<int, pair<int, int>>>>> q;
    for(auto i: fnl) q.push({0, {0, i}});
    while(q.size()){
        auto t = q.top();
        q.pop();
        int x = t.second.second.first, y = t.second.second.second;
        int tem = t.second.first, tt = t.first;
        //1可以赢
        if(tem) is[x][y] = 1;
        if(tt != 0) break;
        for(int i = 0; i < 4; i++){
            int xx = x + dx[i], yy = y + dy[i];
            //不做标记总共也就不超过4 * m * n
            if(xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
                if(g[xx][yy] < g[x][y]) {
                    --num[xx][yy];
                    is[xx][yy] = (1 ^ tem) | is[xx][yy];
                    q.push({num[xx][yy], {is[xx][yy], {xx, yy}}});
                }
            }
        }
    }
    int qq;
    cin >> qq;
    for(int i = 0; i < qq; i++){
        int r, c;
        cin >> r >> c;
        if(is[r][c]) cout << "First" << '\n';
        else cout << "Second" << '\n';
    }
}   
signed main(){
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}