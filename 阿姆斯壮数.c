/*
����λ�������У�����153��������13 + 53 + 33 = 153������������֮ΪArmstrong������д��һ
��ʽ�ҳ����е���λ��Armstrong����

Armstrong����Ѱ�ң���ʵ����������ν�һ�����ַֽ�Ϊ��λ����ʮλ������λ��......����ֻ
Ҫʹ�ó�������������Ϳ����ˣ���������inputΪabc����
a = input / 100
b = (input%100) / 10
c = input % 10

*/

#include <stdio.h>
#include <time.h>
#include <math.h>

int main(void)
{
    int a, b, c;
    int input;

    printf("Ѱ��Armstrong��: \n");

    for(input = 100; input <= 999; input++){
        a = input / 100;
        b = (input % 100) / 10;
        c = input % 10;
        if(a * a * a + b * b * b + c * c * c == input)
            printf("%d ", input);
    }

    printf("\n");

    return 0;
}
