// https://codeforces.com/group/3phdu3ZGLS/contest/678612/problem/I
//离线 + 线段树寻找区间满足 >= l最靠右边的位置（优先右子树） + 从左往右扫描
#include <bits/stdc++.h>

using namespace std;

struct SegmentTree {
	int size;
	vector<int> tree;

	SegmentTree() : size(0) {}

	explicit SegmentTree(int n) {
		init(n);
	}

	void init(int n) {
		size = n;
		tree.assign(size * 4 + 5, -1);
	}

	void update(int node, int left, int right, int pos, int value) {
		if (left == right) {
			tree[node] = value;
			return;
		}
		int mid = (left + right) >> 1;
		if (pos <= mid) {
			update(node << 1, left, mid, pos, value);
		} else {
			update(node << 1 | 1, mid + 1, right, pos, value);
		}
		tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
	}

	void update(int pos, int value) {
		update(1, 1, size, pos, value);
	}

	int find_rightmost(int node, int left, int right, int limit) const {
		if (tree[node] < limit) {
			return -1;
		}
		if (left == right) {
			return left;
		}
		int mid = (left + right) >> 1;
		if (tree[node << 1 | 1] >= limit) {
			return find_rightmost(node << 1 | 1, mid + 1, right, limit);
		}
		return find_rightmost(node << 1, left, mid, limit);
	}

	int find_rightmost(int limit) const {
		return find_rightmost(1, 1, size, limit);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n + 1);
	int max_value = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		max_value = max(max_value, a[i]);
	}

	vector<vector<int>> divisors(max_value + 1);
	for (int d = 1; d <= max_value; d++) {
		for (int multiple = d; multiple <= max_value; multiple += d) {
			divisors[multiple].push_back(d);
		}
	}

	int q;
	cin >> q;
	vector<vector<pair<int, int>>> queries_by_right(n + 1);
	for (int id = 0; id < q; id++) {
		int left, right;
		cin >> left >> right;
		queries_by_right[right].push_back({left, id});
	}

	vector<int> latest(max_value + 1, -1);
	vector<int> second_latest(max_value + 1, -1);
	vector<int> answer(q);
	SegmentTree seg(max_value);

	for (int right = 1; right <= n; right++) {
		for (int d : divisors[a[right]]) {
			second_latest[d] = latest[d];
			latest[d] = right;
			seg.update(d, second_latest[d]);
		}

		for (auto [left, id] : queries_by_right[right]) {
			answer[id] = seg.find_rightmost(left);
		}
	}

	for (int id = 0; id < q; id++) {
		cout << answer[id] << '\n';
	}

	return 0;
}