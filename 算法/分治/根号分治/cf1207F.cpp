//https://codeforces.com/problemset/problem/1207/F

#include <bits/stdc++.h>
#define int long long 
using namespace std;

// #define int long long

const int N = 2e5 + 10;

int a[N], b[710][710];

void solve()
{
	int q;
	cin >> q;
	while (q -- )
	{
		int op, x, y;
		cin >> op >> x >> y;
		if (op == 1)
		{
			a[x] += y;
			for (int i = 1; i < 700; i ++ ) b[i][x % i] += y;
		}
		else
		{
			if (x < 700) cout << b[x][y] << '\n';
			else
			{
				int res = 0;
				for (int i = y; i <= 5e5; i += x) res += a[i];
				cout << res << '\n';
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}
}
