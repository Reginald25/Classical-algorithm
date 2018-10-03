/*
河内之塔(Towers of Hanoi)是法国人M.Claus(Lucas)于1883年从泰国带至法国的，河内为越战时
北越的首都，即现在的胡志明市；1883年法国数学家Edouard Lucas曾提及这个故事，据说创世
纪时Benares有一座波罗教塔，是由三支钻石棒（Pag）所支撑，开始时神在第一根棒上放置64
个由上至下依由小至大排列的金盘（Disc），并命令僧侣将所有的金盘从第一根石棒移至第三根
石棒，且搬运过程中遵守大盘子在小盘子之下的原则，若每日仅搬一个盘子，则当盘子全数搬
运完毕之时，此塔将毁损，而也就是世界末日来临之时。

如果柱子标为ABC，要由A搬至C，在只有一个盘子时，就将它直接搬至C，当有两个盘
子，就将B当作辅助柱。如果盘数超过2个，将第三个以下的盘子遮起来，就很简单了，每次处
理两个盘子，也就是：A->B、A ->C、B->C这三个步骤，而被遮住的部份，其实就是进入程式
的递回处理。

*/

#include <stdio.h>

void hanoi(int n, char A, char B, char C)
{
    if(n == 1)
    {
        printf("Move sheet %d from %c to %c\n", A, B, C);
    }
    else
    {
        hanoi(n-1, A, C, B);
        printf("Move sheet %d from %c to %c\n", n, A, C);
        hanoi(n-1, B, A, C);
    }
}

int main()
{
    int n;
    printf("请输入盘数：");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
