//https://codeforces.com/problemset/problem/2118/B
//一道构造题目


//一开始没有想到简单构造，每一行和每一列都是一个n排列
//没有想到循环移位

// n = 5,
// 1 2 3 4 5
// 5 1 2 3 4
// 4 5 1 2 3
// 3 4 5 1 2
// 2 3 4 5 1
//从第2行到n行第i行构造成都需要（l,r),(1,n),(1,i),(i + 1, n）
//所以需要3 * n - 3，怎么思考呢，想到每一行都需要进行（1，n），如果我删除了这个操作怎么样呢
//删除了那一个等同于构造
// n = 5
// 5 4 3 2 1
// 5 4 3 2 1
// 5 4 3 2 1
// 5 4 3 2 1
// 5 4 3 2 1
//的循环移位构造，实际上和上面那个矩阵构造的每一行每一列都是一个n排列实质是一样，等同于省下一个（1，n）
//这是佬的代码，看风格也不是我的 
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n; cin >> n;
        cout << 2*n-1 << "\n";
        for (int i = 1; i < n; i++) {
            cout << i << " " << 1 << " " << i << "\n";
            cout << i << " " << i+1 << " " << n << "\n";
        }
        cout << n << " 1 " << n << "\n";
    }
    return 0;
}