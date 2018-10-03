/*

运算时由后序式的前方开始读取，遇到运算元先存入堆叠，如果遇到运算子，
则由堆叠中取出两个运算元进行对应的运算，然后将结果存回堆叠，
如果运算式读取完毕，那么堆叠顶的值就是答案了， 例如我们计算12+34+*这个运算式（也就是
(1+2)*(3+4)）：
1 1
2 1 2
+ 3 // 1+2 后存回
3 3 3
4 3 3 4
+ 3 7 // 3+4 后存回
* 21 // 3 * 7 后存回

*/

#include <stdio.h>
#include <stdlib.h>


void evalPf(char*);
double cal(double, char, double);



int main(void)
{
    char input[80];
    printf("输入后序式：");
    scanf("%s", input);
    evalPf(input);
    return 0;
}

void evalPf(char* postfix){
    double stack[80] = {0.0};
    char temp[2];
    char token;
    int top = 0, i = 0;

    temp[1] = '\0';

    while(1){
        token = postfix[i];
        switch(token)
        {
        case '\0':
            printf("ans = %f\n", stack[top]);
            return;
        case '+':
        case '-':
        case '*':
        case '/':
            stack[top-1] = cal(stack[top], token, stack[top-1]);
            top--;
            break;
        default:
            if(top < sizeof(stack) / sizeof(float)){
                temp[0] = postfix[i];
                top++;
                stack[top] = atof(temp);
            }
            break;
        }
        i++;
    }
}

double cal(double p1, char op, double p2)
{
    switch(op)
    {
    case '+':
        return p1 + p2;
    case '-':
        return p1 - p2;
    case '*':
        return p1 * p2;
    case '/':
        return p1 / p2;
    }
}
