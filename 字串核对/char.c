#include "char.h"

void table(char *key)
{
    int k, n;
    n = strlen(key);
    for(k = 0; k <= 255; k++)
        skip[k] = n;
    for(k = 0; k < n - 1; k++)
        skip[key[k]] = n - k - 1;
}

int search(int p, char* input, char* key)
{
    int i, m, n;
    char tmp[80] = {'\0'};
    m = strlen(input);
    n = strlen(key);

    while(p < m){
        substring(input, tmp, p - n + 1, p);
        if(!strcmp(tmp, key))//比较两字串是否相同
            return p - n + 1;
        p += skip[input[p]];
    }

    return -1;
}

void substring(char *text, char *tmp, int s, int e)
{
    int i, j;
    for(i = s, j = 0; i <= e; i++, j++)
        tmp[j] = text[i];
    tmp[j] = '\0';
}
