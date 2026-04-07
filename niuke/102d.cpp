#include<bits/stdc++.h>
#define int long long 

using namespace std;
const int N = 5e2 + 10;
int pre[N];
inline int get(int l, int r){
    return pre[r] - pre[l - 1];
}
signed main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '0' + s;
    for(int i = 1; i < n + 1; i++) pre[i] = pre[i - 1] + (s[i] == '1');
    //0101
    //枚举三段分界线
    int ans = n;
    for(int i = 2; i < n + 1; i++){
        for(int j = i + 1; j < n + 1; j++){
            for(int k = j + 1; k < n + 1; k++){
                int t1 = get(1, i - 1);//0区间
                int t2 = get(i, j - 1);//1区间
                int t3 = get(j, k - 1);//0区间
                int t4 = get(k, n);//1区间
                //0101;
                int sum1 = 0;
                sum1 += t1;
                sum1 += j - i - t2;
                sum1 += t3;
                sum1 += n - k + 1 - t4;
                ans = min(ans, sum1);
                //1010;
                int sum2 = 0;
                sum2 += i - 1 - t1;
                sum2 += t2;
                sum2 += k - j - t3;
                sum2 += t4;
                ans = min(ans, sum2);
            }
        }
    }   
    cout << ans << endl;
    return 0;
}