//线性基就是可以通过建造一个基数组
//这个数组一般是base[60]表示longlong二进制长度
//有性质如下base[i]中的数字最高位就是i位置
//用处，
//1.快速寻找能否使用一个数组中的子序列中异或和等于k
//2.tanxin快速寻找数组中子序列最大异或和
//3.tanxin寻找数组中子序列最小异或和
//4.求第k小的异或和值
//这个第4个题目其实挺简单的，稍微想想就差不多了，实际上是对基础获得的线性基进行操作，操作基础不超过60 * 60，
//从大到小查找base，如果base[i], 除了第i位置是1，更小位置j有一个1且那个位置对应的base[j]也非零，需要让base[i] ^= base[j];
//实际上操作之后还是线性基，这个时候我们脑子很容易知道什么数是第k小异或和的数了，比如1，3，5
//1：就是从小到大第一个非零base，001
//3：就是从小到大第一个非零base，和第二个非零base异或和，011
//5：就是从小到大第一个非零base，和第三个非零base异或和，101
//所以之后 求第k个小的数：将k先转成二进制，假如 k 的第 i位为 1， ans 就异或上线性基中第 i 个元素
//等等
//这里有一个blog讲的特别好
//https://blog.csdn.net/a_forever_dream/article/details/83654397?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522187f819a99d0f82d302dcb852807eb1d%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=187f819a99d0f82d302dcb852807eb1d&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-83654397-null-null.142^v102^control&utm_term=%E7%BA%BF%E6%80%A7%E5%9F%BA&spm=1018.2226.3001.4187
