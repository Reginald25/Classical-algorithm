/*
������һ�����ӣ������к졢�ס���������ɫ�����ӣ���������ϵ�������ɫ��û��˳����
ϣ����֮���࣬������Ϊ�����ס����˳��Ҫ����ƶ������Ż����٣�ע����ֻ����������
�����������������һ��ֻ�ܵ����������ӡ�

�ⷨ��
��һ���������ƶ����ڳ�ʽ��Ҳ����ζֻ��ʹ��һ�����У�����ʹ������������������������
��Ľⷨ�ܼ򵥣��������Լ�����һ�����ƶ����ӣ������ӿ�ͷ���У�������ɫ��ǰ�ƣ�����
��ɫ�����м䣬������ɫ�����ƣ�������ʾ��
ֻ��Ҫ���ƶ��������ٵĻ�����Ҫ��Щ���ɣ�
���ͼ��W���ڵ�λ��Ϊ��ɫ����W+1����ʾδ����Ĳ�����������ɫȺ�顣
���W����Ϊ��ɫ����B��W��Ԫ�ضԵ�����B��W�����+1����ʾ����Ⱥ�鶼����һ��Ԫ�ء�
���W���ڵ�λ���Ǻ�ɫ����W��R��������RҪ��1����ʾδ����Ĳ��ݼ�1��

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLUE 'b'
#define WHITE 'w'
#define RED 'r'

#define SWAP(x,y) { char temp;\
                    temp = color[x];\
                    color[x] = color[y];\
                    color[y] = temp;}

int main()
{
    char color[] = {'r', 'w', 'b', 'w', 'w', 'b', 'r', 'b', 'w','r', '\0'};

    int wFlag = 0;
    int bFlag = 0;
    int rFlag = strlen(color) - 1;
    int i;

    for(i = 0; i < strlen(color); i++)
        printf("%c", color[i]);
    printf("\n");

    while(wFlag <= rFlag){
        if(color[wFlag] == WHITE)
            wFlag++;
        else if(color[wFlag] == BLUE){
            SWAP(bFlag, wFlag);
            bFlag++; wFlag++;
        }
        else{
            while(wFlag < rFlag && color[rFlag] == RED)
                rFlag--;
            SWAP(rFlag, wFlag);
            rFlag--;
        }
    }

    for(i = 0; i < strlen(color); i++)
        printf("%c", color[i]);
    printf("\n");

    return 0;
}
