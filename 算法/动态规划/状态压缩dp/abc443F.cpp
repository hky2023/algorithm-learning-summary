//https://atcoder.jp/contests/abc443/tasks/abc443_f
//利用同余的思想，将状态压缩使用余数（压缩不超过n个）和个位（用来还原并且单调不增）上
//厉害
#include <bits/stdc++.h>
#define int long long 
using namespace std;

signed main() {
    int n;
    cin >> n;
    const int INF = 1e9;
    vector<int> d(10 * n, INF), to(10 * n, -1);
    d[0] = 0;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int idx = q.front(); q.pop();
        int c = idx % 10, x = idx / 10;
        for (int cc = max(1LL, c); cc < 10; ++cc) {
            int xx = (10 * x + cc) % n;
            int idx2 = 10 * xx + cc;
            if (d[idx2] != INF) continue;
            d[idx2] = d[idx] + 1;
            q.push(idx2);
            to[idx2] = idx;
            if (xx == 0) {
                // 回溯输出答案
                vector<int> ans;
                int cur = idx2;
                while (cur != 0) {
                    ans.push_back(cur % 10);
                    cur = to[cur];
                }
                reverse(ans.begin(), ans.end());
                for (int v : ans) cout << v;
                cout << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}