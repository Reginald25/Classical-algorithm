/*
如果有一数n，其真因数（Proper factor）的总和等于n，则称之为完美数（Perfect Number），
例如以下几个数都是完美数：
6 = 1 + 2 + 3
28 = 1 + 2 + 4 + 7 + 14
496 = 1 + 2 + 4 + 8 + 16 + 31 + 62 + 124 + 248

解法：
求出一定数目的质数表
利用质数表求指定数的因式分解
利用因式分解求所有真因数和，并检查是否为完美数
*/

#include <stdio.h>
#include <stdlib.h>

#define N 1000
#define P 10000

int prime(int*);    //求质数表
int factor(int*, int, int*);    //求factor
int fsum(int*, int);   //sum to proper factor

int main(void)
{
    int ptable[N + 1] = {0};    //储存质数表
    int fact[N + 1] = {0};  //储存因式分解结果
    int count1, count2, i;

    count1 = prime(ptable);

    for( i = 0; i <= P; i++){
        count2 = factor(ptable, i , fact);
        if(i == fsum(fact, count2))
            printf("Perfect Number: %d\n", i);
    }

    printf("\n");

    return 0;
}

int prime(int* pNum)
{
    int i, j;
    int prime[N + 1];

    for(i = 2; i <= N; i++)
        prime[i] = 1;

    for(i = 2; i * i <= N; i++){
        if(prime[i] == 1){
            for(j = 2 * i; j <= N; j++){
                if(j % i == 0)
                    prime[j] = 0;
            }
        }
    }

    for(i = 2, j = 0; i < N; i++){
        if(prime[i] == 1)
            pNum[j++] = i;
    }

    return j;
}

int factor(int* table, int num, int* frecord)
{
    int i, k;
    for(i = 0, k = 0; table[i] * table[i] <= num;){
        if(num % table[i] == 0){
            frecord[k] = table[i];
            k++;
            num /= table[i];
        }
        else
            i++;
    }

    frecord[k] = num;

    return k + 1;
}

int fsum(int* farr, int c)
{
    int i, r, s, q;

    i = 0;
    r = 1;
    s = 1;
    q = 1;

    while(i < c){
        do{
            r *= farr[i];
            q += r;
            i++;
        }while(i < c-1 && farr[i-1] == farr[i]);
        s *= q;
        r = 1;
        q = 1;
    }

    return s / 2;
}
