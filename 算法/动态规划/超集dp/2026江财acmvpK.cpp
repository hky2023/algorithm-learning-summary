// https://codeforces.com/group/3phdu3ZGLS/contest/678612/problem/K
//等等哦，还有一个疑问就是关于这个超集dp，我感觉更新顺序不是仅仅i从(1 << m) - 1, 到0然后i--吧，我柑橘遍历顺序应该是更像按层遍历，也就是bfs顺序更新dp，毕竟要保证和dp的上一个只和此时的i只多了一个1并且保证最优
//这个方法是叫做什么sos吗，那我也不能理解啊?你这个方法，即使是分轮，我感觉也是这个位为1的最大值是肯定正确的啊，也应该是从大到小吧？
//按位 SOS + dp寻找超集，寻找子集
// #include <bits/stdc++.h>

// using namespace std;

// struct BestTwo {
// 	int first = -1;
// 	int second = -1;
// };

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(nullptr);

// 	int n, m;
// 	cin >> n >> m;

// 	vector<int> masks(n + 1), ones(n + 1);
// 	for (int i = 1; i <= n; i++) {
// 		string s;
// 		cin >> s;
// 		int mask = 0;
// 		for (int bit = 0; bit < m; bit++) {
// 			if (s[bit] == 'Y') {
// 				mask |= (1 << bit);
// 			}
// 		}
// 		masks[i] = mask;
// 		ones[i] = __builtin_popcount(mask);
// 	}

// 	auto better = [&](int lhs, int rhs) -> bool {
// 		if (lhs == -1) {
// 			return false;
// 		}
// 		if (rhs == -1) {
// 			return true;
// 		}
// 		if (ones[lhs] != ones[rhs]) {
// 			return ones[lhs] > ones[rhs];
// 		}
// 		return lhs < rhs;
// 	};

// 	auto insert_candidate = [&](BestTwo &state, int id) {
// 		if (id == -1 || state.first == id || state.second == id) {
// 			return;
// 		}
// 		if (better(id, state.first)) {
// 			state.second = state.first;
// 			state.first = id;
// 		} else if (better(id, state.second)) {
// 			state.second = id;
// 		}
// 	};

// 	auto merge_state = [&](BestTwo &target, const BestTwo &source) {
// 		insert_candidate(target, source.first);
// 		insert_candidate(target, source.second);
// 	};

// 	int full = (1 << m) - 1;
// 	vector<BestTwo> dp(1 << m);
// 	for (int i = 1; i <= n; i++) {
// 		insert_candidate(dp[masks[i]], i);
// 	}

//         //按位分轮
//         //在固定某一轮 bit 时，转移源 dp[mask | (1 << bit)] 在这一轮不会被修改，所以内层顺序无所谓
//         //遍历到bit到i，mask = j时的含义就是前i - 1个bit，我实现了最优转移。
// 	for (int bit = 0; bit < m; bit++) {
// 		for (int mask = 0; mask <= full; mask++) {
// 			if ((mask >> bit) & 1) {
// 				continue;
// 			}
// 			merge_state(dp[mask], dp[mask | (1 << bit)]);
// 		}
// 	}

// 	int best_score = -1;
// 	pair<int, int> best_pair = {INT_MAX, INT_MAX};
// 	for (int i = 1; i <= n; i++) {
// 		int need = full ^ masks[i];
// 		int j = dp[need].first;
// 		if (j == i) {
// 			j = dp[need].second;
// 		}
// 		if (j == -1) {
// 			continue;
// 		}

// 		int score = __builtin_popcount(masks[i] & masks[j]);
// 		pair<int, int> current_pair = {min(i, j), max(i, j)};
// 		if (score > best_score || (score == best_score && current_pair < best_pair)) {
// 			best_score = score;
// 			best_pair = current_pair;
// 		}
// 	}

// 	if (best_score == -1) {
// 		cout << "No\n";
// 	} else {
// 		cout << best_pair.first << ' ' << best_pair.second << '\n';
// 	}

// 	return 0;
// }

//其实我认为还有一种就是将mask从大到小，按层更新dp，按照1的个数进行分层，然后时间复杂度应该也是
//O（30 * （2 ^ 20))时间复杂度是够的。
