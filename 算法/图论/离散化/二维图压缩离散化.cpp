//该题目数据量有点大，即使离散化也不行，我只是给一个参考
//https://ac.nowcoder.com/acm/contest/128312/C

//由于坐标系边界过大，1e6或者更多，关键点数较少，我们可以考虑离散化压缩
//我们需要做到的是将关键点，将炮火点，判断点以及周围8个点的横纵坐标进入离散处理
//如果不加入周围8个点的横纵坐标可能导致图的连通性质改变，不等价了。
//样例如image中的二位压缩坐标系离散化

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 将值 v 压缩到 vec 中的下标
int get_id(const vector<ll> &vec, ll v) {
    return int(lower_bound(vec.begin(), vec.end(), v) - vec.begin());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> xs, ys;
    xs.reserve(4 * n + 4 * q + 10);
    ys.reserve(4 * n + 4 * q + 10);

    struct P { ll x, y; };
    vector<P> block(n), query(q);

    // 读入障碍点
    for (int i = 0; i < n; ++i) {
        cin >> block[i].x >> block[i].y;
        ll x = block[i].x, y = block[i].y;
        // 本点以及前后一格都可能用到
        xs.push_back(x - 1);
        xs.push_back(x);
        xs.push_back(x + 1);
        ys.push_back(y - 1);
        ys.push_back(y);
        ys.push_back(y + 1);
    }

    // 读入查询点
    for (int i = 0; i < q; ++i) {
        cin >> query[i].x >> query[i].y;
        ll x = query[i].x, y = query[i].y;
        xs.push_back(x - 1);
        xs.push_back(x);
        xs.push_back(x + 1);
        ys.push_back(y - 1);
        ys.push_back(y);
        ys.push_back(y + 1);
    }

    // 加一个“外圈”边界，代表无穷远
    const ll INF_COORD = (ll)1e9 + 5;
    xs.push_back(-INF_COORD);
    xs.push_back(INF_COORD);
    ys.push_back(-INF_COORD);
    ys.push_back(INF_COORD);

    // 压缩坐标
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    int nx = (int)xs.size();
    int ny = (int)ys.size();

    // 标记格子：0 空地，1 障碍
    vector<vector<int>> blockGrid(nx, vector<int>(ny, 0));

    // 把障碍点打到压缩后的格子里
    for (int i = 0; i < n; ++i) {
        int cx = get_id(xs, block[i].x);
        int cy = get_id(ys, block[i].y);
        blockGrid[cx][cy] = 1;
    }

    // 多源 BFS：从“外圈”的所有非障碍格子开始向内灌
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    vector<vector<int>> vis(nx, vector<int>(ny, 0));
    queue<pair<int,int>> que;

    auto try_push = [&](int x, int y) {
        if (x < 0 || x >= nx || y < 0 || y >= ny) return;
        if (vis[x][y]) return;
        if (blockGrid[x][y]) return;
        vis[x][y] = 1;
        que.push({x, y});
    };

    // 四条边界作为“外部世界”
    for (int i = 0; i < nx; ++i) {
        try_push(i, 0);
        try_push(i, ny - 1);
    }
    for (int j = 0; j < ny; ++j) {
        try_push(0, j);
        try_push(nx - 1, j);
    }

    while (!que.empty()) {
        auto [x, y] = que.front(); que.pop();
        for (int k = 0; k < 4; ++k) {
            int nx2 = x + dx[k];
            int ny2 = y + dy[k];
            try_push(nx2, ny2);
        }
    }

    // 查询：如果查询点所在格子没有被外部 BFS 到，就是被封在某个圈里
    for (int i = 0; i < q; ++i) {
        int cx = get_id(xs, query[i].x);
        int cy = get_id(ys, query[i].y);
        if (vis[cx][cy]) {
            cout << "No\n";   // 能连到外界，不在炮火圈里
        } else {
            cout << "Yes\n";  // 不能连到外界，被包围在某个圈里
        }
    }

    return 0;
}