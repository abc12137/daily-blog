# 统计0-n中1出现的个数
## 问题描述
输入一个整数 n，求从 1 到 n 这 n个整数的十进制表示中出的次数。
例如输入 12，从 1到 12这些整数中包含 “1”的数字有 1，10，11和 12，其中 “1”一共出现了 5 次。
# 思路分析 
# 时间复杂度
采用按位求解，时间复杂度显然为O(log(10n)),比暴力求解的时间复杂度O(n*log10n)显然优化了不少。




