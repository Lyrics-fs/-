#include"head.h"

/*
* vector<int> arr(10,0);
* int i = 178;
* int numIndex = i / 32;
* int bitIndex = i % 32;
* 第i位的状态
* int s = ((arr[numIndex] >> bitIndex) & 1)
* 将第i位改成1
* arr[numIndex] = arr[numIndex] | (1 << bitIndex);
* 将第i位改成0
* arr[numIndex] = arr[numIndex] & (~(1 << bitIndex));
* 
* 
* n = 样本量
* p = 失误率
* m = - (n * ln(p)) / (ln(2) * ln(2)) 需要占用的字节数
* k = ln(2) * (m / n) 预期使用的哈希函数
* p真 = (1 - e ^ (n * k真 / m真)) ^ k真 真实失误率 
*/