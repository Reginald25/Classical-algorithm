/*
字串搜寻本身不难，使用暴力法也可以求解，但如何快速搜寻字串就不简单了，传统的
字串搜寻是从关键字与字串的开头开始比对，例如Knuth-Morris-Pratt 演算法字串搜寻，这个
方法也不错，不过要花时间在公式计算上；Boyer-Moore字串核对改由关键字的后面开始核对字
串，并制作前进表，如果比对不符合则依前进表中的值前进至下一个核对处，假设是p好了，然
后比对字串中p-n+1至p的值是否与关键字相同。
如果关键字中有重复出现的字元，则前进值就会有两个以上的值，此时则取前进值较小的值，
如此就不会跳过可能的位置，例如texture这个关键字，t的前进值应该取后面的3而不是取前面的
7。
*/
#include "char.h"

int main(void)
{
    char str_input[80];
    char str_key[80];
    char tmp[80] = {'\0'};
    int m, n, p;
    printf("请输入字符串：");
    gets(str_input);
    printf("请输入搜寻关键字：");
    gets(str_key);
    m = strlen(str_input);  //计算字串长度
    n = strlen(str_key);
    table(str_key);
    p = search(n-1, str_input, str_key);

    while(p != -1){
        substring(str_input, tmp, p, m);
        printf("%s\n", tmp);
        p = search(p+n+1, str_input, str_key);
    }

    printf("\n");
    return 0;
}
