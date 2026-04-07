/*
我大致懂了，这就是为什么是从中间向两端扩展的原因吧，用t * 2 - 1，是因为除了最高不同位，更高位都相同，
如果相加也是向右移位的效果，再减1就达到了<=最高不同位都为1的效果，用2 * t - 1，可以达到，异或和除了比最高不同位更高的位数的丢失，
小数位都获得的效果，达到最优，也就是说这种求法最后比求和相差只差在比最高不同位更高的数位上面的丢失
*/
/*
时间复杂度是O（n），不是所有递归分治都是O（logn * n），这里就是O（n）的典型，每一个数都只需要遍历一次赋值
同时不要忘记主方法
*/

/*
这道题目主要分析，l和r的最高位相同部分没有任何作用，判断第一个最高位不同的数
*/
#include <iostream>
#include <vector>
using namespace std;

// 判断x的第j位
int g(int x, int j) {
    return (x >> j) & 1;
}

vector<int> a;

void solve(int l, int r, int j, int L) {
    if (l > r) return;
    if (l == r) {
        a[l - L] = r;
        return;
    }
    int mid = l;
    while (mid + 1 <= r && g(mid + 1, j) == g(l, j)) mid++;
    if (mid == r) {
        solve(l, r, j - 1, L);
        return;
    }
    int tl = mid + 1, tr = mid;
    while (tl - 1 >= l && tr + 1 <= r) {
        tl--;
        tr++;
        a[tl - L] = tr;
        a[tr - L] = tl;
    }
    solve(l, tl - 1, j - 1, L);
    solve(tr + 1, r, j - 1, L);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        int n = R - L + 1;
        a.assign(n, 0);
        solve(L, R, 29, L);
        long long ans = 0;
        for (int i = L; i <= R; ++i) {
            ans += a[i - L] | i;
        }
        cout << ans << "\n";
        for (int i = 0; i < n; ++i) cout << a[i] << " ";
        cout << "\n";
    }
    return 0;
}