//这道题目的dp手法和题目很好
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 快速幂
long long power2(int x) {
    long long res = 1;
    long long base = 2;
    while (x) {
        if (x & 1) res *= base;
        base *= base;
        x >>= 1;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        // 计算左视图
        vector<int> L;
        int maxL = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > maxL) {
                L.push_back(a[i]);
                maxL = a[i];
            }
        }
        // 计算右视图
        vector<int> R;
        int maxR = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] > maxR) {
                R.push_back(a[i]);
                maxR = a[i];
            }
        }
        reverse(R.begin(), R.end());

        int m = *max_element(a.begin(), a.end());

        // dpL[i]：以i为结尾，左视图正好等于L，且i是最大值第一次出现
        vector<long long> dpL(n, 0);
        vector<long long> c(L.size() + 1, 0);
        c[0] = 1;
        for (int i = 0; i < n; ++i) {
            vector<long long> nc = c;
            for (int j = 0; j < L.size(); ++j) {
                if (a[i] == L[j]) {
                    nc[j + 1] += c[j];
                } else if (j > 0 && a[i] > L[j - 1] && a[i] < L[j]) {
                    // 不合法，跳过
                } else if (j > 0 && a[i] <= L[j - 1]) {
                    nc[j] *= 2;
                }
            }
            c = nc;
            if (a[i] == m && L.back() == m) {
                dpL[i] = c[L.size() - 1];
            }
        }

        // dpR[j]：以j为起点，右视图正好等于R，且j是最大值最后一次出现
        vector<long long> dpR(n, 0);
        vector<long long> cR(R.size() + 1, 0);
        cR[0] = 1;
        for (int i = n - 1; i >= 0; --i) {
            vector<long long> ncR = cR;
            for (int j = 0; j < R.size(); ++j) {
                if (a[i] == R[j]) {
                    ncR[j + 1] += cR[j];
                } else if (j > 0 && a[i] > R[j - 1] && a[i] < R[j]) {
                    // 不合法，跳过
                } else if (j > 0 && a[i] <= R[j - 1]) {
                    ncR[j] *= 2;
                }
            }
            cR = ncR;
            if (a[i] == m && R.back() == m) {
                dpR[i] = cR[R.size() - 1];
            }
        }

        // 枚举最大值的第一次和最后一次出现
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] != m) continue;
            for (int j = i; j < n; ++j) {
                if (a[j] != m) continue;
                int between = j - i - 1;
                ans += dpL[i] * dpR[j] * power2(between);
            }
        }
        cout << ans << endl;
    }
    return 0;
}