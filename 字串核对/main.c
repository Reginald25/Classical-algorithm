/*
�ִ���Ѱ�����ѣ�ʹ�ñ�����Ҳ������⣬����ο�����Ѱ�ִ��Ͳ����ˣ���ͳ��
�ִ���Ѱ�Ǵӹؼ������ִ��Ŀ�ͷ��ʼ�ȶԣ�����Knuth-Morris-Pratt ���㷨�ִ���Ѱ�����
����Ҳ��������Ҫ��ʱ���ڹ�ʽ�����ϣ�Boyer-Moore�ִ��˶Ը��ɹؼ��ֵĺ��濪ʼ�˶���
����������ǰ��������ȶԲ���������ǰ�����е�ֵǰ������һ���˶Դ���������p���ˣ�Ȼ
��ȶ��ִ���p-n+1��p��ֵ�Ƿ���ؼ�����ͬ��
����ؼ��������ظ����ֵ���Ԫ����ǰ��ֵ�ͻ����������ϵ�ֵ����ʱ��ȡǰ��ֵ��С��ֵ��
��˾Ͳ����������ܵ�λ�ã�����texture����ؼ��֣�t��ǰ��ֵӦ��ȡ�����3������ȡǰ���
7��
*/
#include "char.h"

int main(void)
{
    char str_input[80];
    char str_key[80];
    char tmp[80] = {'\0'};
    int m, n, p;
    printf("�������ַ�����");
    gets(str_input);
    printf("��������Ѱ�ؼ��֣�");
    gets(str_key);
    m = strlen(str_input);  //�����ִ�����
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
