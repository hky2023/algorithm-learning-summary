//https://codeforces.com/problemset/problem/2121/D

//这道题目思路是，先进行排序，排序后从1-n遍历如果a[i] > b[i],交换a[i],b[i]
//怎么保证这一定是正确的呢？如何保证b[i] > a[i - 1]和 a[i] > b[i - 1];
//a[i] > b[i - 1]简单可以看出，因为b[i] > b[i - 1],
//b[i] > a[i - 1], 多一步，b[i - 1] > a[i - 1], b[i] > b[i - 1]

//那么好我们需要怎么实现排序符合题目的邻近交换呢，并且最多O(n ^ 2),
//答案就是逆序对的冒泡排序，完美适配这一道题目的交换，

//这个是佬的代码
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (a[j - 1] > a[j]) {
                    swap(a[j - 1], a[j]);
                    ans.push_back({1, j});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (b[j - 1] > b[j]) {
                    swap(b[j - 1], b[j]);
                    ans.push_back({2, j});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                ans.push_back({3, i + 1});
            }
        }
        cout << ans.size() << '\n';
        for (auto [x, y] : ans) cout << x << " " << y << '\n';
    }
    return 0;
}
