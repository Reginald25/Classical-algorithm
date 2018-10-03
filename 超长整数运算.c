/*
说明基于记忆体的有效运用，程式语言中规定了各种不同的资料型态，也因此变数所可以表
达的最大整数受到限制，例如123456789123456789这样的整数就不可能储存在long变数中（例
如C/C++等），我们称这为long数，这边翻为超长整数（避免与资料型态的长整数翻译混淆），或
俗称大数运算。
解法一个变数无法表示超长整数，则就使用多个变数，当然这使用阵列最为方便，假设程式
语言的最大资料型态可以储存至65535的数好了，为了计算方便及符合使用十进位制的习惯，让
每一个阵列元素可以储存四个位数，也就是0到9999的数。


*/

void add(int *a, int *b, int *c){
    int i, carry = 0;

    for(i = N - 1; i >= 0; i--){
        c[i] = a[i] + b[i] + carry;
        if(c[i] < 10000)
            carry = 0;
        else {
            c[i] = c[i] - 10000;//进位
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
            //借位
            c[i] = c[i] + 10000;
            borrow = 1;
        }
    }
}

void mul(int *a, int *b, int *c){//b为乘数
    int i, tmp, carry = 0;
    for(i = N - 1; i >= 0; i--){
        tmp = a[i] * b + carry;
        c[i] = tmp % 10000;
        carry = tmp / 10000;
    }
}

void div(int *a, int b, int *c){//b为除数
    int i, tmp, remain = 0;
    for(i = 0; i < N; i++){
        tmp = a[i] + remain;
        c[i] = tmp / b;
        remain = (tmp % b) * 10000;
    }
}
