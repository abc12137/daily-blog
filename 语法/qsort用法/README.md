## April 14
## qsort()用法：
qsort是stdlib.h中的函数，因此使用前需要声明：
#include<stdlib.h>
qsort函数包含四个参数，分别是：
1.数组名  2.元素个数（从前往后计算）3.数组元素所占字节（int，double，char等所占字节）4.排序原则（递增，递减，奇偶交叉等）
qsort(nums,numsSize,sizeof(type),compare);
cmp函数的参数需要以const void *a,const void *b的形式来定义，表示a和b的类型是未确定的，在return中进行强制类型转换为int型。*(int*)a-*(int*)b表示以递增顺序，若想以递减只需将a和b换位。
int cmp(const void *a,const void *b) {
	return *(int*)a-*(int*)b;
}
qsort(num, n, sizeof(int), cmp);//升序
需要注意浮点数会存在精度损失的问题，所以我们需要通过比较，来返回1或-1，以确定是增序还是降序。
