#ifndef CHAR_H_INCLUDED
#define CHAR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void table(char*);  //����ǰ����
int search(int, char*, char*);  //��Ѱ�ؼ���
void substring(char*, char*, int, int); //ȡ�����ִ�

int skip[256];

#endif // CHAR_H_INCLUDED
