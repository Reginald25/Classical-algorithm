#include "game.h"

void init()
{
    int row, col;

    for(row = 0; row < MAXROW; row++)
        for(col = 0; col < MAXCOL; col++)
            map[row][col] = DEAD;

    puts("Game of life Program");
    puts("Enter x, y where x, y is living cell");
    printf("0 <= x <= %d, 0 <= y <= %d\n", MAXROW - 1, MAXCOL - 1);
    puts("Terminate with x, y = -1, -1");

    while(1){
        scanf("%d %d", &row, &col);
        if(0 <= row && row < MAXROW && 0 <= col && col < MAXCOL)
            map[row][col] = ALIVE;
        else if(row == -1 || col == -1)
            break;
        else
            printf("(x,y) exceeds map ranage!");
    }
}

int neightbors(int row, int col)
{
    int count = 0, c, r;
    for(r = row - 1; r <= row+1; r++)
        for(c = col - 1; c <= col+1; c++){
            if(r < 0 || r >= MAXROW || c < 0 || c >= MAXCOL)
                continue;
            if(map[r][c] == ALIVE)
                count++;
    }

    if(map[row][col] == ALIVE)
        count--;
    return count;
}

void outputMap()
{
    int row, col;
    printf("\n\n%20cGame of life cell status\n");
    for(row = 0; row < MAXROW; row++){
        printf("\n%20c", ' ');
        for(col = 0; col < MAXCOL; col++)
            if(map[row][col] == ALIVE)
                putchar('#');
            else
                putchar('-');
    }
}

void copyMap()
{
    int row, col;
    for(row = 0; row < MAXROW; row++)
        for(col = 0; col < MAXCOL; col++)
            map[row][col] = newmap[row][col];
}
