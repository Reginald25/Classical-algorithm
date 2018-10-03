#ifndef CHAR_H_INCLUDED
#define CHAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void table(char*);  //建立前进表
int search(int, char*, char*);  //搜寻关键字
void substring(char*, char*, int, int); //取出子字串

int skip[256];

#endif // CHAR_H_INCLUDED
