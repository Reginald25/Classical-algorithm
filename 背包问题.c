/*
假设有一个背包的负重最多可达8公斤，而希望在背包中装入负重范围内可得之总价物
品。

背包问题是关于最佳化的问题，要解最佳化问题可以使用「动态规划」（Dynamic
programming），从空集合开始，每增加一个元素就先求出该阶段的最佳解，直到所有的元素加
入至集合中，最后得到的就是最佳解。
以背包问题为例，我们使用两个阵列value与item，value表示目前的最佳解所得之总价，item表
示最后一个放至背包的水果，假设有负重量1～8的背包8个，并对每个背包求其最佳解。
*/

#include <stdio.h>
#include <stdlib.h>

#define LIMIT 8 //重量限制
#define N 5     //物品种类
#define MIN 1   //最小重量

struct body {
    char name[20];
    int size;
    int price;
};

typedef struct body object;

int main(void)
{
    int item[LIMIT+1] = {0};
    int value[LIMIT+1] = {0};
    int newvalue, i, s, p;

    object a[] = {{"李子", 4, 4500},
                  {"苹果", 5, 5700},
                  {"橘子", 2, 2250},
                  {"草莓", 1, 1100},
                  {"甜瓜", 6, 6700}};

    for (i = 0; i < N; i++){
        for(s = a[i].size; s <= LIMIT; s++){
            p = s - a[i].size;
            newvalue = value[p] + a[i].price;
            if(newvalue > value[s]){//找到阶段最优解
                value[s] = newvalue;
                item[s] = i;
            }
        }
    }

    printf("物品\t价格\n");
    for(i = LIMIT; i >= MIN; i = i - a[item[i]].size){
        printf("%s\t%d\n", a[item[i]].name, a[item[i]].price);
    }

    printf("合计\t%d\n", value[LIMIT]);

    return 0;
}
