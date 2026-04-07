//https://codeforces.com/group/3phdu3ZGLS/contest/680387
//状态压缩，集合dp，f[s]数组记录集合为s的长度，实际上有s了，那么长度就是s的1的个数了。
//然后设计dp[s]表示状态为s的子集长度最长是多少。最后整合起来就是dp[s] + dp[s ^ (2 ^ m - 1)];
//这个dp转移方法类似于hamilton回路。