//https://ac.nowcoder.com/acm/contest/127023/F
#include<bits/stdc++.h>
#define int long long 
#define pr pair<int, int>
#define endl '\n'

using namespace std;

const int N = 3e5 + 10, mod = 998244353;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

inline int quickmi(int a, int p){
    int ans = 1, jin = a;
    while(p){
        if(p % 2) ans = (ans * jin) % mod;
        p /= 2;
        jin = (jin * jin) % mod;
    }
    return ans;
}
inline void solve(){
    int n, m;
    cin >> n >> m;
    int tem = 1;
    vector<vector<char>> g(n + 1, vector<char>(m + 1));
    vector<vector<int>> tag(n + 1, vector<int> (m + 1, 0));
    vector<int> num;
    num.push_back(0);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> g[i][j];
    auto bfs = [&](int x, int y)-> void{
        queue<pr> q;
        q.push({x, y});
        tag[x][y] = tem;
        int size = 1;
        
        while(q.size()){
            auto [x1, y1] = q.front(); q.pop();
            // tag[x1][y1] = tem;
            for(int i = 0; i < 4; i++){
                int xx = x1 + dx[i], yy = y1 + dy[i];
                if(xx <= n && xx >= 1 && yy <= m && yy >= 1 && !tag[xx][yy] && g[xx][yy] == '#') {
                    tag[xx][yy] = tem; 
                    size++;
                    q.push({xx, yy});
                }
            }
        }
        num.push_back(size);
        tem++;
    };
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) if(!tag[i][j] && g[i][j] == '#') bfs(i, j);
    }
    vector<int> row(n + 1, 0), col(m + 1, 0);
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 1; j <= m; j++) sum += (g[i][j] == '#');
        row[i] = m - sum;
    }
    for(int i = 1; i <= m; i++){
        int sum = 0;
        for(int j = 1; j <= n; j++) sum += (g[j][i] == '#');
        col[i] = n - sum;
    }
    unordered_set<int> st;
    int ans = 0;
    for(auto i: num) ans = max(ans, i);
    for(int i = 1; i <= n; i++){
        st.clear();
        for(int j = -1; j <= 1; j++){
            if(i + j >= 1 && i + j <= n){
                for(int k = 1; k <= m; k++) if(tag[i + j][k] != 0) st.insert(tag[i + j][k]);
            }
        }
        int sum = 0;
        for(auto e: st) sum += num[e];
        ans = max(ans, sum + row[i]);
    }
    for(int i = 1; i <= m; i++){
        st.clear();
        for(int j = -1; j <= 1; j++){
            if(i + j >= 1 && i + j <= m){
                for(int k = 1; k <= n; k++) if(tag[k][i + j] != 0) st.insert(tag[k][i + j]);
            }
        }
        int sum = 0;
        for(auto e: st) sum += num[e];
        ans = max(ans, sum + col[i]);
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    // ini();
    int t;
    // cin >> t;
    t = 1;
    while(t--) solve();
    return 0;
}