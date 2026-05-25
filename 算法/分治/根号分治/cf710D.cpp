//https://codeforces.com/problemset/problem/710/D
#include <bits/stdc++.h>

using namespace std;

#define int long long
using i64 = long long;

typedef pair<int, int> PII;
typedef pair<int, char> PIC;
typedef pair<double, double> PDD;
typedef pair<int, PII> PIII;
typedef pair<int, pair<int, bool>> PIIB;

const int N = 2e9;
const int maxn = 710;
const int mod = 1e9 + 7;
const int mod1 = 954169327;
const int mod2 = 906097321;
const int INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
	int a1, b1, a2, b2, l, r;
	cin >> a1 >> b1 >> a2 >> b2 >> l >> r;
	int maxx = max(a1, a2);
	if (maxx < sqrt(N)) // 找最小公倍数
	{
		for (int i = 0; i <= maxx; i ++ )
		{
			int tmp = a1 * i + b1;
			if (abs(tmp - b2) % a2 == 0)
			{
				int lcmm = lcm(a1, a2);
				int st = max({l, b1, b2});
                //以下操作都是根据lcm等差，快速定位第一个 >= st的合法数
				if (tmp < st)
				{
					tmp += ((st - tmp) / lcmm + 1) * lcmm;
					tmp = st + (tmp - st) % lcmm;
				}
				else tmp = st + (tmp - st) % lcmm;
				if (tmp > r) continue;
                //
				cout << (r - tmp) / lcmm + 1 << '\n';
				return;
			}
		}
		cout << 0 << '\n';
	}
	else // 暴力
	{
		int ans = 0;
		if (a1 < a2) swap(a1, a2), swap(b1, b2);
		for (int i = b1; i <= r; i += a1)
		{
			if (i < l || i < b2) continue;
			if ((i - b2) % a2 == 0) ans ++ ;
		}
		cout << ans << '\n';
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
    return 0;
}
