//https://ac.nowcoder.com/acm/contest/128312/C

//思路是将图压缩二分，将炮火点外侧部分染色成绿色，内部分染色成蓝色
//查询点的时候，如果查询点往右找，和往下找都是内圈的情况就判断其是内圈。
//可以很简单得到结论，每一个炮火连通块从左往右，从上往下枚举然后染色
//第一个枚举到的就是左上角部分，左上角部分如果将左上角空格染色成绿色就能染色该连通块的外圈
//右下角就是属于内圈了，唯一需要注意的是如果出现炮火圈包围炮火圈的情况时。
//我们可以注意到，如果出现该情况，包围其的炮火圈内外圈一定都更新完全（由于只需要左上角就能出发内外圈dfs）
//所以我们只需要向判断判断点的方法一样，如果属于内圈就跳过，不染色。
#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int LIM = 1000000; // 坐标上界（题解里就是 1e6）

// 炮火点：bomb[x] 里存这一列所有 y
vector< set<int> > bomb(LIM + 2);

// 被染色的“边界空格”：color[x][y] = 0/1（0=外侧绿，1=内侧蓝）
vector< map<int,int> > color(LIM + 2);

// 行、列上有哪些被染色的空格，用来二分找“第一个被遇到的格子”
vector< set<int> > row_has(LIM + 2), col_has(LIM + 2);

int dx4[4] = {-1, 0, 1, 0};
int dy4[4] = {0, -1, 0, 1};

// 判断一个查询点 (x, y) 是否在某个炮火圈内部
// 模拟：往右、往下走，看第一次遇到的被染色格子是绿(0)还是蓝(1)
inline bool inside(int x, int y){
    auto itx = row_has[x].lower_bound(y); // 行 x 上，第一个 y' >= y 的被染色格子
    auto ity = col_has[y].lower_bound(x); // 列 y 上，第一个 x' >= x 的被染色格子
    if(itx == row_has[x].end() || ity == col_has[y].end()) return false; // 两个方向有一个没遇到圈
    return min(color[x][*itx], color[*ity][y]); // 两个方向第一次遇到的颜色都为 1 才算在圈里
}

// DFS 把一整块“边界空格”涂成同一个颜色 c（0=外圈绿，1=内圈蓝）
void dfs(int x, int y, int c){
    color[x][y] = c;
    row_has[x].insert(y);
    col_has[y].insert(x);

    for(int k = 0; k < 4; k++){
        int xx = x + dx4[k];
        int yy = y + dy4[k];
        if(xx < 0 || yy < 0) continue;          // 题目只考虑非负坐标
        if(bomb[xx].count(yy)) continue;        // 炮火点本身不能走
        if(color[xx].count(yy)) continue;       // 已经染色过

        bool near_bomb = false;
        // 看 (xx, yy) 的 3×3 范围内是否有炮火点，有才属于“边界空格”
        for(int dx = -1; dx <= 1; dx++){
            for(int dy = -1; dy <= 1; dy++){
                if(xx + dx >= 0 && bomb[xx + dx].count(yy + dy)){
                    near_bomb = true;
                }
            }
        }
        if(near_bomb) dfs(xx, yy, c);
    }
}

void solve(){
    int n, q;
    cin >> n >> q;

    // 读入所有炮火点
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        bomb[x].insert(y);
    }

    // 枚举所有炮火点，给它周围的“边界空格”染色
    for(int x = 0; x <= LIM; x++){
        for(int y : bomb[x]){
            // 如果这个炮火点已经确定在某个炮火圈内部了，就“删掉”它：跳过
            if(inside(x, y)) continue;

            // 枚举它 8 个方向的邻格，作为边界染色的起点
            for(int dx = -1; dx <= 1; dx++){
                for(int dy = -1; dy <= 1; dy++){
                    int xx = x + dx;
                    int yy = y + dy;
                    if(xx < 0 || yy < 0) continue;
                    if(bomb[xx].count(yy)) continue;   // 不能从炮火点开始
                    if(color[xx].count(yy)) continue;  // 已经染色过

                    // 根据相对位置，决定这块边界是外圈(0)还是内圈(1)
                    int c = (min(dx, dy) >= 0 ? 1 : 0);
                    dfs(xx, yy, c);
                }
            }
        }
    }

    while(q--){
        int x, y;
        cin >> x >> y;
        cout << (inside(x, y) ? "YES" : "NO") << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}