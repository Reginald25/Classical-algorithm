/*
˵�����ڼ��������Ч���ã���ʽ�����й涨�˸��ֲ�ͬ��������̬��Ҳ��˱��������Ա�
�����������ܵ����ƣ�����123456789123456789�����������Ͳ����ܴ�����long�����У���
��C/C++�ȣ������ǳ���Ϊlong������߷�Ϊ����������������������̬�ĳ������������������
�׳ƴ������㡣
�ⷨһ�������޷���ʾ�������������ʹ�ö����������Ȼ��ʹ��������Ϊ���㣬�����ʽ
���Ե����������̬���Դ�����65535�������ˣ�Ϊ�˼��㷽�㼰����ʹ��ʮ��λ�Ƶ�ϰ�ߣ���
ÿһ������Ԫ�ؿ��Դ����ĸ�λ����Ҳ����0��9999������


*/

void add(int *a, int *b, int *c){
    int i, carry = 0;

    for(i = N - 1; i >= 0; i--){
        c[i] = a[i] + b[i] + carry;
        if(c[i] < 10000)
            carry = 0;
        else {
            c[i] = c[i] - 10000;//��λ
            carry = 1;
        }
    }
}

void sub(int *a, int *b, int *c){
    int i, borrow = 0;
    for(i = N - 1; i >= 0; i--)
    {
        c[i] = a[i] - b[i] - borrow;
        if(c[i] >= 0)
            borrow = 0;
        else {
            //��λ
            c[i] = c[i] + 10000;
            borrow = 1;
        }
    }
}

void mul(int *a, int *b, int *c){//bΪ����
    int i, tmp, carry = 0;
    for(i = N - 1; i >= 0; i--){
        tmp = a[i] * b + carry;
        c[i] = tmp % 10000;
        carry = tmp / 10000;
    }
}

void div(int *a, int b, int *c){//bΪ����
    int i, tmp, remain = 0;
    for(i = 0; i < N; i++){
        tmp = a[i] + remain;
        c[i] = tmp / b;
        remain = (tmp % b) * 10000;
    }
}
