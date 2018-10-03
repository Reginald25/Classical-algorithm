/*
�ɵؿ���ΪĦ�������֮�׶����ù�λ�ڷ�����������������ԶĲ��������ɵؿ��޵�
����ԭ��Ϊ��������������ʽ�����н��⣬�����Ի���������ķ�ʽ���жĲ�����ζ����Ȼ
�ھ�ȷ�����������ǣ���������˼������ȴ�Ǹ�ֵ��ѧϰ�ķ�ʽ��

�ɵؿ��޵Ľⷨ������������йص���Ŀ��������PIֵ����Բ�������߽��������PI
ֵ��������һ��Բ�뾶Ϊ1�������ķ�֮һԲ�����ΪPI�����������ķ�֮һԲ�������������
Ϊ1
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50000

int main(void)
{
    int i, sum = 0;
    double x, y;

    srand(time(NULL));

    for(i = 1; i < N; i++){
        x = (double) rand() / RAND_MAX;
        y = (double) rand() / RAND_MAX;
        if(( x * x + y * y) < 1)
            sum++;
    }
    printf("PI = %f\n", (double)4 * sum / N);
    return 0;
}
