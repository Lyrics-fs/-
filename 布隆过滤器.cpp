#include"head.h"

/*
* vector<int> arr(10,0);
* int i = 178;
* int numIndex = i / 32;
* int bitIndex = i % 32;
* ��iλ��״̬
* int s = ((arr[numIndex] >> bitIndex) & 1)
* ����iλ�ĳ�1
* arr[numIndex] = arr[numIndex] | (1 << bitIndex);
* ����iλ�ĳ�0
* arr[numIndex] = arr[numIndex] & (~(1 << bitIndex));
* 
* 
* n = ������
* p = ʧ����
* m = - (n * ln(p)) / (ln(2) * ln(2)) ��Ҫռ�õ��ֽ���
* k = ln(2) * (m / n) Ԥ��ʹ�õĹ�ϣ����
* p�� = (1 - e ^ (n * k�� / m��)) ^ k�� ��ʵʧ���� 
*/