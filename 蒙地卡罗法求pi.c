/*
蒙地卡罗为摩洛哥王国之首都，该国位于法国与义大利国境，以赌博闻名。蒙地卡罗的
基本原理为以乱数配合面积公式来进行解题，这种以机率来解题的方式带有赌博的意味，虽然
在精确度上有所疑虑，但其解题的思考方向却是个值得学习的方式。

蒙地卡罗的解法适用于与面积有关的题目，例如求PI值或椭圆面积，这边介绍如何求PI
值；假设有一个圆半径为1，所以四分之一圆面积就为PI，而包括此四分之一圆的正方形面积就
为1
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
