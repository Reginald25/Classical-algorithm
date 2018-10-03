#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, n;

    printf("ÇëÊäÈëÕûÊı£º");
    scanf("%d", &n);
    printf("%d = ", n);

    for(i = 2; i * i <= n;){
        if(n % i ==0)
        {
            printf("%d * ", i);
            n /= i;
        }
        else
            i++;
    }

    printf("%d\n", n);

    return 0;
}
