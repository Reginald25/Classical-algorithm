/*
费氏数列，例
如以下： 1、1 、2、3、5、8、13、21、34、55、89......

解法

依说明，我们可以将费氏数列定义为以下：
fn = fn-1 + fn-2 if n > 1
fn = n            if n = 0,1

*/

#include <stdio.h>
#include <stdlib.h>

#define N 20

int main()
{
    int Fib[N] = {0};
    int i;

    Fib[0] = 0;
    Fib[1] = 1;

    for(i = 2; i < N; i++)
        Fib[i] = Fib[i-1] + Fib[i-2];

    for(i = 0; i < N; i++)
        printf("%d ", Fib[i]);
    printf("\n");

    return 0;
}
