//
#include <bits/stdc++.h>
using namespace std;

// 计算前缀函数 pi（pi[i] = s[0..i] 的最长真前缀也是后缀的长度）
vector<int> prefix_function(const string &s) {
    int m = s.size();
    vector<int> pi(m);
    pi[0] = 0;
    for (int i = 1; i < m; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1]; // 回退
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

// KMP 匹配：在 text 中查找 pattern 的所有出现位置（返回 0-based 起始下标）
vector<int> kmp_search(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> res;
    if (m == 0) { // 空模式：按需要处理（这里返回所有位置）
        for (int i = 0; i <= n; ++i) res.push_back(i);
        return res;
    }
    vector<int> pi = prefix_function(pattern);
    int j = 0; // 当前模式已匹配长度
    for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j]) j = pi[j-1];
        if (text[i] == pattern[j]) ++j;
        if (j == m) {
            res.push_back(i - m + 1); // 匹配位置（0-based）
            j = pi[j-1]; // 继续寻找下一个可能匹配（允许重叠）
        }
    }
    return res;
}

// 示例用法：从 stdin 读取 text 和 pattern，输出所有匹配的 1-based 起始位置
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, pattern;
    if (!getline(cin, text)) return 0;
    if (!getline(cin, pattern)) return 0;

    vector<int> occ = kmp_search(text, pattern);
    if (occ.empty()) {
        cout << "no match\n";
    } else {
        for (int pos : occ) {
            cout << (pos + 1) << ' '; // 输出 1-based 位置
        }
        cout << '\n';
    }
    return 0;
}