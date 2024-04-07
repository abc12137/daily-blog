#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 计算模式串的部分匹配表（next数组）
void get_next(const char pattern[], int next[]) {
    int len = strlen(pattern);
    int i = 0;
    int j = -1;
    next[0] = -1; // next数组中第一个值为-1

    while (i < len - 1) {
        if (j == -1 || pattern[i] == pattern[j]) {
            ++i;
            ++j;
            next[i] = j; // 正确赋值为j
        } else {
            j = next[j];
        }
    }
}

// 使用KMP算法在文本串S中查找模式串T的位置
int Index_KMP(const char S[], const char T[], const int next[]) {
    int i = 0;
    int j = 0;
    int sLen = strlen(S);
    int tLen = strlen(T);

    while (i < sLen && j < tLen) {
        if (j == -1 || S[i] == T[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    if (j == tLen)
        return i - j;
    else
        return -1; // 未找到匹配位置
}
int main() {
    char S[] = "acabaabcabaabc";
    char T[] = "abcabaa";
    int tLen = strlen(T);
    // 创建并计算模式串T的部分匹配表（next数组）
    int *next = (int *)malloc(sizeof(int) * tLen);
    get_next(T, next);
    // 打印next数组的内容
    printf("模式串的部分匹配表（next数组）为：\n");
    for (int i = 0; i < tLen; ++i) {
        printf("%d ", next[i]+1);
    }
    printf("\n");
    // 在文本串S中使用KMP算法查找模式串T的位置
    int pos = Index_KMP(S, T, next);
    if (pos != -1) {
        printf("模式串在文本串中的位置为：%d\n", pos+1);
    } else {
        printf("未找到模式串在文本串中的位置\n");
    }
    free(next); // 释放next数组的内存空间
    return 0;
}
