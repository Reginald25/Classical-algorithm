#include "game.h"

int main()
{
    int row, col;
    char ans;
    init();
    while(1){
        outputMap();
        for(row = 0; row < MAXROW; row++){
            for(col = 0; col < MAXCOL; col++){
                switch(neightbors(row, col))
                {
                case 0:
                case 1:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                    newmap[row][col] = DEAD;
                    break;
                case 2:
                    newmap[row][col] = map[row][col];
                    break;
                case 3:
                    newmap[row][col] = ALIVE;
                    break;
                }
            }
        }

        copyMap();
        printf("\nContinue next Generation?");
        getchar();
        ans = toupper(getchar());
        if(ans != 'Y') break;
    }

    return 0;
}
