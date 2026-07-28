//你的模板可以使用template写啊。
//一维树状数组单点修改，区间查询
//二维树状数组单点修改，矩阵查询
//一维树状数组区间修改，区间查询



//我去niubi ！！！这个树状数组的思路和规则，我完全理解了，蛙去，到底是什么神人
//可以创建出这样一个数据结构？？完全太强了吧，太强了

//先说tree[i] 表示的不是区间[1 - i]的和，但是query(i)却是[1 - i]的和
//tree[i]的含义，或者说树状数组数据结构的含义：!!! 区间[i - lowbit(i) + 1, i]的总和 !!!, 但是区间大小是lowbit(i).
//所以我们可以利用query寻找到[1 - i]的所有数的和，
//但是为什么向上+ lowbit就可以找到所有区间包括i的呢？
//反证法：假设 加上的（1 << e) & i == 0， 如果e < lowbit(i), 那么区间的左端点恰好是i + 1
//如果e > lowbit(i), 那么区间左端点甚至 > i + 1, 所以我们要寻找到包含i的区间就需要让lowbit 进位将区间扩大，就可以包含 lowbit了。
#include<bits/stdc++.h>
#define int long long 

using namespace std;

class BIT{
    public:
        
        void add(int pl, int t){//在pl位置增加t并且维护树状数组
            for(pl; pl <= size_; pl += lowbit(pl)){
                tree_[pl] += t;
            }
        }
        int query(int pl){ //查询1-pl的前缀和
            int ans = 0;
            for(pl; pl; pl -= lowbit(pl)) ans += tree_[pl];
            return ans;
        }
        BIT(int size) : size_(size), tree_(size + 10, 0) {}
        
    private: 
        int size_;
        vector<int> tree_;
        int lowbit(int x) { return -x & x; }
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