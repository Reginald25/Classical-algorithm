#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

/*
生命游戏（game of life）为1970年由英国数学家J. H. Conway所提出，某一细胞的邻居包
括上、下、左、右、左上、左下、右上与右下相邻之细胞，游戏规则如下：
孤单死亡：如果细胞的邻居小于一个，则该细胞在下一次状态将死亡。
拥挤死亡：如果细胞的邻居在四个以上，则该细胞在下一次状态将死亡。
稳定：如果细胞的邻居为二个或三个，则下一次状态为稳定存活。
复活：如果某位置原无细胞存活，而该位置的邻居为三个，则该位置将复活一细胞。

生命游戏的规则可简化为以下，并使用CASE比对即可使用程式实作：
邻居个数为0、1、4、5、6、7、8时，则该细胞下次状态为死亡。
邻居个数为2时，则该细胞下次状态为复活。
邻居个数为3时，则该细胞下次状态为稳定。
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXROW 10
#define MAXCOL 25
#define DEAD 0
#define ALIVE 1

int map[MAXROW][MAXCOL], newmap[MAXROW][MAXCOL];

void init();
int neightbors(int, int);
void outputMap();
void copyMap();

#endif // GAME_H_INCLUDED
