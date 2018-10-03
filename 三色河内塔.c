//error unslove

#include <stdio.h>

void hanoi (int disks, char source, char temp, char target){
    if(disks == 1){
        printf("move disk from %c to %c\n", source, target);
        printf("move disk from %c to %c\n", source, target);
        printf("move disk from %c to %c\n", source, target);
    }
    else
    {
        hanoi(disks - 1, source, target, temp);
        hanoi(1, source, temp, target);
        hanoi(disks - 1, temp, source, target);
    }
}

void hanoi3colors(int disks)
{
    char source = 'A';
    char temp = 'B';
    char target = 'C';
    int i;
    if(disks == 3){
        printf("move disk from %c to %c\n", source, temp);
        printf("move disk from %c to %c\n", source, temp);
        printf("move disk from %c to %c\n", source, target);
        printf("move disk from %c to %c\n", temp, target);
        printf("move disk from %c to %c\n", temp, source);
        printf("move disk from %c to %c\n", target, temp);
    }
    else {
        hanoi(disks/3-1, source, temp, target);
        printf("move disk from %c to %c\n", source, temp);
        printf("move disk from %c to %c\n", source, temp);
        printf("move disk from %c to %c\n", source, temp);

        hanoi(disks/3-1, target, temp, source);
        printf("move disk from %c to %c\n", temp, target);
        printf("move disk from %c to %c\n", temp, target);
        printf("move disk from %c to %c\n", temp, target);

        hanoi(disks/3-1, source, target, temp);
        printf("move disk from %c to %c\n", target, source);
        printf("move disk from %c to %c\n", target, source);

        hanoi(disks/3-1, temp, source, target);
        printf("move disk from %c to %c\n", source, temp);

        for(i = disks / 3 - 1; i > 0; i--){
            if(i > 1){
                hanoi(i-1, target, source, temp);
            }
            printf("move disk from %c to %c\n",target, source);
            printf("move disk from %c to %c\n",target, source);
            if(i > 1){
                hanoi(i - 1, temp, source, target);
            }
            printf("move disk from %c to %c\n", source, temp);
        }
    }
}

int main() {
    int n;
    printf("«Î ‰»Î≈Ã ˝£∫");
    scanf("%d", &n);

    hanoi3colors(n);
    return 0;
}
