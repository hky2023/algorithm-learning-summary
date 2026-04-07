//二维单调队列题目
//理想的正方形，寻找一个n * n的矩阵之中极差最小
//我自己的思路是遍历行i，再遍历列j，将（i，j）作为正方形右上角
//维护一个大小n * n的单调队列，每次退出进入1 * n大小的矩阵
//时间复杂度为（a * b * n）但是还是过不了

////正确答案的单调队列是先对每一行作长度为1 * n的单调队列记录下来，
////整合n * n的最大最小值就是再对记录的二维数组的列做长度为n的单调队列
////这样整合后的答案就是n * n的矩阵大小的最大最小值了
#include<bits/stdc++.h>
#define int long long 
#define pr pair<int, int>

using namespace std;
const int N = 1e3 + 10;
int a, b, n;
int gra[N][N];
pr qx[N * N], qn[N * N];
signed main(){
    
    cin >> a >> b >> n;
    for(int i = 0; i < a; i ++) 
        for(int j = 0; j < b; j++) cin >> gra[i][j];
    int ans = 1e18;
    for(int i = 0; i <= a - n; i++){
        int hx = 0, tx = -1;
        int hn = 0, tn = -1;
        for(int j = 0; j < b; j++){
            while(hx <= tx && qx[hx].second < j - n + 1) hx++;
            while(hn <= tn && qn[hn].second < j - n + 1) hn++;
            for(int k = 0; k < n; k++) {
                while(hx <= tx && gra[qx[tx].first][qx[tx].second] <= gra[i + k][j]) tx--;
                while(hn <= tn && gra[qn[tn].first][qn[tn].second] >= gra[i + k][j]) tn--;
                qx[++tx] = {i + k, j};
                qn[++tn] = {i + k, j};
            }
            if(j - n + 1 >= 0) ans = min(ans, gra[qx[hx].first][qx[hx].second] - gra[qn[hn].first][qn[hn].second]);
        }
    }
    cout << ans;
    return 0;
}