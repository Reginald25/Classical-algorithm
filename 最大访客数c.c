/*

�ֽ�����һ���ͻᣬ�÷ÿ�������д����ʱ�����뿪ʱ�䣬Ϊ��������λ����Ŀ�������ȹ���
��ͬʱ������ÿ�����
�ⷨ
�����Ŀ������Щ���ӣ���ʵ�൱�򵥣����ͼ���ÿ������Ŀ�ģ�ͬʱ����ͬһ�ÿ͵�����
ʱ�����뿪ʱ�䣬������ʹ��ʽ��ø��ӣ�ֻҪ������ʱ�����뿪ʱ��ֿ�����Ϳ����ˣ���
��ÿ�i ������ʱ��Ϊx[i]�����뿪ʱ��Ϊy[i]��
�������������֮�󣬽�x[i]��y[i]�ֱ����������С���󣩣�����ܼ򵥣�ֻҪ�ȼ���ĳʱ֮
ǰ�ܹ������˶��ٷÿͣ�Ȼ���ټ�ȥĳʱ֮ǰ���뿪�ÿͣ��Ϳ������׵Ľ��������⡣

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define SWAP(x, y) {int t; t = x; x = y; y = t;}

int main(void)
{
    int x[MAX] = {0};
    int y[MAX] = {0};
    int time = 0;
    int count = 0;

    printf("\n�����������뿪ʱ��(0~24)��");
    printf("\n������10 15");
    printf("\n����-1 -1����");
    while(count < MAX){
        printf("\n>>");
        scanf("%d %d", &x[count], &y[count]);
        if(x[count] < 0)
            break;
        count++;
    }

    if(count >= MAX){
        printf("\n�������ÿ���(%d)", MAX);
        count--;
    }

    //Ԥ������
    quicksort(x, 0, count);
    quicksort(y, 0, count);

    while(time < 25){
        printf("\n%d ʱ�����ÿ����� %d", time, maxguest(x, y, count, time));
        time++;
    }

    printf("\n");

    return 0;
}

int maxguest(int x[], int y[], int count, int time)
{
    int i, num = 0;

    for(i = 0; i <= count; i++){
        if(time > x[i])
            num++;
        if(time > y[i])
            num--;
    }

    return num;
}

int partition(int number[], int left, int right){
    int i, j, s;

    s = number[right];
    i = left - 1;

    for( j = left; j < right; j++){
        if(number[j] <= s){
            i++;
            SWAP(number[i], number[j]);
        }
    }

    SWAP(number[i+1], number[right]);
    return i+1;
}

void quicksort(int number[], int left, int right){
    int q;

    if(left < right){
        q = partition(number, left, right);
        quicksort(number, left, q - 1);
        quicksort(number, q + 1, right);
    }
}
