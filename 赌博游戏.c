/*

˵��:һ���򵥵ĶĲ���Ϸ����Ϸ�������£�������������ӣ�����Ϊ1��6�������һ�ε���
��Ϊ7��11�������ʤ�����������Ϊ2��3��12��������䣬�����Ϊ�������������¼��һ
�εĵ����ͣ�Ȼ�����������ֱ�������͵��ڵ�һ�������ĵ����ͣ������ʤ���������֮ǰ
�����˵�����Ϊ7��������䡣
�ⷨ:��������Щ���ӣ�������ʵֻҪʹ��switch���if�����ж���׫д���ɣ�С�Ĳ�ҪŪ
��ʤ��˳�򼴿ɡ�

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WON 0
#define LOST 1
#define CONTINUE 2

int rollDice(){
    return (rand() % 6)+(rand() % 6) + 2;
}

int main(void)
{
    int firstRoll = 1;
    int gameStatus = CONTINUE;
    int die1, die2, sumOfDice;
    int firstPoint = 0;
    char c;

    srand(time(0));

    printf("Craps�Ĳ���Ϸ����Enter��ʼ��Ϸ******");

    while(1){
        getchar();

        if(firstRoll){
            sumOfDice = rollDice();
            printf("\n������������ͣ�%d\n", sumOfDice);

            switch(sumOfDice)
            {
            case 7:case 11:
                gameStatus = WON;
                break;
            case 2:case 3:case 12:
                gameStatus = LOST;
                break;
            default:
                firstRoll = 0;
                gameStatus = CONTINUE;
                firstPoint = sumOfDice;
                break;
            }
        }
        else{
            sumOfDice = rollDice();
            printf("\n������������ͣ�%d\n", sumOfDice);

            if(sumOfDice == firstPoint)
                gameStatus = WON;
            else if(sumOfDice == 7)
                gameStatus = LOST;
        }

        if(gameStatus == CONTINUE)
            puts("δ��ʤ��������һ��*****\n");
        else{
            if(gameStatus == WON)
                puts("���ʤ");
            else
                puts("�����");

            printf("����һ�Σ�");

            scanf("%c", &c);
            if(c == 'n'){
                puts("��Ϸ����");
                break;
            }
            firstRoll = 1;
        }
    }
    system("pause");
    return 0;
}
