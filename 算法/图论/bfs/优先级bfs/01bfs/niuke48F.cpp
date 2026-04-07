//https://ac.nowcoder.com/acm/contest/85187/F

//01bfs思路是如果有权值是0和1的移动方式，不能和仅仅bfs使用queue了
//如果将0权和1权都放到队列尾部，这样就打破了按层遍历的最优bfs了，所以0权就应该放到队列前端
//1就应该放到队列后面
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 1e9;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> g(h, vector<int>(w));
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            cin >> g[i][j];

    vector<vector<int>> dp(h, vector<int>(w, INF));
    vector<vector<vector<int>>> es(h, vector<vector<int>>(w));
    unordered_map<int, vector<pii>> cnt;

    // 预处理每个格子的所有质因数
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int v = g[i][j];
            for (int k = 2; k * k <= v; ++k) {
                if (v % k == 0) {
                    cnt[k].emplace_back(i, j);
                    es[i][j].push_back(k);
                    while (v % k == 0) v /= k;
                }
            }
            if (v > 1) {
                cnt[v].emplace_back(i, j);
                es[i][j].push_back(v);
            }
        }
    }

    deque<tuple<int, int, int, int>> dq; // (op, y, x, cost)
    dp[0][0] = 0;
    dq.emplace_back(0, 0, 0, 0);
    unordered_map<int, int> used; // 质因数是否已用

    while (!dq.empty()) {
        auto [op, y, x, c] = dq.front(); dq.pop_front();
        if (op == 0) {
            // 普通移动
            if (y + 1 < h && dp[y + 1][x] > c + 1) {
                dp[y + 1][x] = c + 1;
                dq.emplace_back(0, y + 1, x, c + 1);
            }
            if (x + 1 < w && dp[y][x + 1] > c + 1) {
                dp[y][x + 1] = c + 1;
                dq.emplace_back(0, y, x + 1, c + 1);
            }
            // 传送门
            for (int v : es[y][x]) {
                if (!used.count(v)) {
                    used[v] = c;
                    dq.emplace_front(1, v, 0, c); // op=1表示传送门
                }
            }
        } else {
            // 传送门扩展
            for (auto [ty, tx] : cnt[y]) {
                if (dp[ty][tx] > c + 1) {
                    dp[ty][tx] = c + 1;
                    dq.emplace_back(0, ty, tx, c + 1);
                }
            }
        }
    }
    cout << dp[h - 1][w - 1] << endl;
    return 0;
}