# 什么时候需要使用SOS求超集子集？
> (SOS)例如求超集和 $g[\text{mask}] = \sum_{\text{sup} \supseteq \text{mask}} a[\text{sup}]$

> (非sos，可以利用直接从小到大或者从大到小枚举mask，然后枚举相差一个bit的数进行更新类似hamilton)例如求超集最大最小 $g[\text{mask}] = \max_{\text{sup} \supseteq \text{mask}} a[\text{sup}]$

---
可能到这里就有点眉目了，差别就在于max能重复计算，而求超集和就只能计算一次，不能重复计数。

## 非sos算法的方法
```cpp
for(int mask = (1 << m) - 1; mask >= 0; mask--)
    for(int bit = 0; bit < m; bit++){
        if(mask & (1 << bit)) merge(dp[mask], dp[mask ^ (1 << bit)]);
    }

```
## 为什么说sos类型题目不能使用非sos方法呢？
举例mask: 00 01 10 11

求超集和按照非sos方法，11 -> 10, 11 -> 01, 然后10 -> 00, 01 -> 00。最终00的超集和多了一个11，所以说这个更新是有问题的。更偏向于一种路径和。

## sos算法的方法
```cpp
for(int bit = 0; bit < m; bit++){
    for(int mask = 0; mask < 1 << m; mask++){
        if(mask & (1 << bit)) continue;
        merge(dp[mask], dp[mask | (1 << bit)]);
    }
}
```
## 为什么sos算法能够做到不重计数呢

sos算法更偏向于对于bit分组。实际上就是寻找两个数之间的1的个数差异来更新，确保在某一次bit加上它一次。枚举到bit，mask的实际意义是mask前bit位不同的超集之和。

举例：mask1:11101, mask2:00000

使用这个方法mask2何时能加入mask1呢？实际上bit等于4的时候才可以加入一个mask1，为何？mask2当bit = 4时，dp[00000] += dp[10000]。

00000 <- 10000 <- 11000 <- 11100 <- 11101