//https://ac.nowcoder.com/acm/contest/128312/D
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int qpow(int a, long long e) {
    int res = 1;
    a %= MOD;
    while (e) {
        if (e & 1) res = res * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return res;
}

struct SafeProd {
    int zero;   // 乘积里有多少个 0 因子
    int prod;   // 去掉 0 因子后的乘积
    SafeProd() : zero(0), prod(1) {}

    void mul(int x) {
        x %= MOD;
        if (x == 0) {
            ++zero;
        } else {
            prod = prod * x % MOD;
        }
    }

    void div(int x) {
        x %= MOD;
        if (x == 0) {
            --zero;
        } else {
            prod = prod * qpow(x, MOD - 2) % MOD;
        }
    }

    int val() const {
        return zero ? 0 : prod;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n + 1), pos(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;          // 数值 -> 结点编号
    }

    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> fa(n + 1);
    vector<SafeProd> dp(n + 1);

    function<void(int,int)> dfs = [&](int u, int f) {
        fa[u] = f;
        for (int v : g[u]) {
            if (v == f) continue;
            dfs(v, u);
            dp[u].mul(dp[v].val() + 1);
        }
    };

    int root = pos[0];
    dfs(root, 0);

    vector<int> used(n + 1, 0);
    SafeProd sum = dp[root];
    int ans = sum.val();
    used[root] = 1;

    for (int x = 1; x < n; ++x) {
        int u = pos[x];
        while (!used[u]) {
            used[u] = 1;
            // 去掉把 u 当成一个整体子树时的贡献
            sum.div(dp[u].val() + 1);
            // 加回 u 的每个子节点单独作为整体时的贡献
            for (int v : g[u]) {
                if (v == fa[u]) continue;
                sum.mul(dp[v].val() + 1);
            }
            u = fa[u];
        }
        ans += sum.val();
        if (ans >= MOD) ans -= MOD;
    }

    cout << ans % MOD << '\n';
    return 0;
}