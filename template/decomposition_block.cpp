#include<bits/stdc++.h>
#define int long long 

using namespace std;
class block{ //！！！该模板以0为开始，如果需要预处理请自行处理。
    public:
        block(vector<int> aa, int size): a(aa), size_(size){
            len = sqrt(size_);
            block_num = size_ / len;
            if(size_ % len) block_num ++; 
            for(int i = 0; i < block_num; i++) block_sum.push_back(0);
            for(int i = 0; i < size_; i++) block_sum[i / len] += a[i];            
        }   
        vector<int> a;
        vector<int> block_sum;
        int size_; //数组大小
        int len; //块大小
        int block_num;//块数量
};
inline void solve(){
}
signed main(){
    int t;
    // cin >> t;
    t = 1;
    while(t--) solve();
    return 0;
}