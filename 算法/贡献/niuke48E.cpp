//https://ac.nowcoder.com/acm/contest/85187/E
//这道题目暴力求会爆，很难想出来有什么好方法
//正难则反，求出每一对（i, j) (s[i] = s[j])
//其贡献即min(i + 1, n - j),这样时间复杂度是O（n^2)
//有没有什么优化方法，我们注意到相同字符随着i增长(i + 1)递增，
//（n - j）随着递减，我们可以通过这个性质使用双指针优化，类似于典型题目（在一串递增数组中找出两个相加等于k的元素（也是类似双指针））
//代码如下
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    ll total = 0;

    // 1. 统计总配对数
    for (int len = 2; len <= n; ++len) {
        total += (n - len + 1) * (len / 2);
    }

    // 2. 统计所有“相同字符对”的贡献（O(N)优化）
    ll same = 0;
    for (int c = 0; c < 26; ++c) {
        vector<int> pos;
        for (int i = 0; i < n; ++i)
            if (s[i] - 'a' == c) pos.push_back(i);
        int m = pos.size();
        if (m == 0) continue;
        vector<ll> pre(m + 1, 0);
        for (int j = 0; j < m; ++j)
            pre[j + 1] = pre[j] + (n - pos[j]);
        int k = m - 1;
        for (int j = 0; j < m; ++j) {
            while (k >= 0 && n - pos[k] < pos[j] + 1) k--;
            if (k >= j + 1) {
                same += (k - j) * (pos[j] + 1);
                same += pre[m] - pre[k + 1];
            } else {
                same += pre[m] - pre[j + 1];
            }
        }
    }

    cout << total - same << endl;
    return 0;
}