/*

˵����
ƽ����ʹ�õ�����ʽ����Ҫ�ǽ�����Ԫ���������ӵ����ԣ�����a+b/d������ʽ�ӣ����
֮Ϊ����Infix����ʾʽ������������˵��������ʽ�Ӻ�������⣬�����ڵ���ִ��ָ��ʱ��
��˳��ģ����������ʾʽʱ���޷�ֱ�ӽ������㣬�������һ���ж�������Ⱥ�˳������
���뽫�����ʾʽת��Ϊ��һ�ֱ�ʾ������

���������
������ķ�ʽ���������ʽ�൱�ļ򵥣������������Ե�����Ԫ���Ⱥ�˳��ȫ����������
Ȼ�����е�������ȡ��Ϊ�����ӽ��������ӣ������ڲ����ſ�ʼ�������ȥ�����е�������
�Ϳ�����ɺ����ʾʽ�����磺
a+b*d+c/d => ((a+(b*d))+(c/d)) -> bd*+cd/+
���Ҫ�ó�ʽ����������ת���������ʹ�öѵ������㷨�ܼ򵥣�ֱ�������Ļ�����ʹ�û�
Ȧ��ȡ������ʽ����Ԫ��������Ԫֱ��������ѵ��������������ţ� ISP>ICP�Ļ�ֱ�������
���е������ӣ�������������ѵ��е��������������š�

*/

#include <stdio.h>
#include <stdlib.h>

int postfix(char*); //����ת����
int priority(char); //��������������˳��

int main(void)
{
    char input[80];

    printf("������������ʽ��");
    scanf("%s", input);
    postfix(input);

    return 0;
}

int postfix(char* infix)
{
    int i = 0, top = 0;
    char stack[80] ={'\0'};
    char op;

    while(1){
        op = infix[i];

        switch(op)
        {
        case '\0':
            while(top > 0) {
                printf("%c", stack[top]);
                top--;
            }
            printf("\n");
            return 0;
            //�����Ӷѵ�
        case '(':
            if(top < (sizeof(stack) / sizeof(char))){
                top++;
                stack[top] = op;
               }
               break;
        case '+':
        case '-':
        case '*':
        case '/':
            while(priority(stack[top]) >= priority(op)){
                printf("%c", stack[top]);
                top--;
            }

            //����ѵ�
            if(top < (sizeof(stack) / sizeof(char))){
                top++;
                stack[top] = op;
            }
            break;
            //�����������
        case ')':
            while(stack[top] != '('){
                    printf("%c", stack[top]);
                    top--;
                  }
                  top--;    //�������
                  break;
                  //����Ԫֱ�����
        default:
            printf("%c", op);
            break;
        }
        i++;
    }
}

int priority(char op)
{
    int p;

    switch(op)
    {
    case '+':
    case '-':
        p = 1;
        break;
    case '*':
    case '/':
        p = 2;
        break;
    default:
        p = 0;
        break;
    }

    return p;
}
