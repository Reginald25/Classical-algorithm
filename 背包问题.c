/*
������һ�������ĸ������ɴ�8�����ϣ���ڱ�����װ�븺�ط�Χ�ڿɵ�֮�ܼ���
Ʒ��

���������ǹ�����ѻ������⣬Ҫ����ѻ��������ʹ�á���̬�滮����Dynamic
programming�����ӿռ��Ͽ�ʼ��ÿ����һ��Ԫ�ؾ�������ý׶ε���ѽ⣬ֱ�����е�Ԫ�ؼ�
���������У����õ��ľ�����ѽ⡣
�Ա�������Ϊ��������ʹ����������value��item��value��ʾĿǰ����ѽ�����֮�ܼۣ�item��
ʾ���һ������������ˮ���������и�����1��8�ı���8��������ÿ������������ѽ⡣
*/

#include <stdio.h>
#include <stdlib.h>

#define LIMIT 8 //��������
#define N 5     //��Ʒ����
#define MIN 1   //��С����

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

    object a[] = {{"����", 4, 4500},
                  {"ƻ��", 5, 5700},
                  {"����", 2, 2250},
                  {"��ݮ", 1, 1100},
                  {"���", 6, 6700}};

    for (i = 0; i < N; i++){
        for(s = a[i].size; s <= LIMIT; s++){
            p = s - a[i].size;
            newvalue = value[p] + a[i].price;
            if(newvalue > value[s]){//�ҵ��׶����Ž�
                value[s] = newvalue;
                item[s] = i;
            }
        }
    }

    printf("��Ʒ\t�۸�\n");
    for(i = LIMIT; i >= MIN; i = i - a[item[i]].size){
        printf("%s\t%d\n", a[item[i]].name, a[item[i]].price);
    }

    printf("�ϼ�\t%d\n", value[LIMIT]);

    return 0;
}
