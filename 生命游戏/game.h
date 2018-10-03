#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

/*
������Ϸ��game of life��Ϊ1970����Ӣ����ѧ��J. H. Conway�������ĳһϸ�����ھӰ�
���ϡ��¡����ҡ����ϡ����¡���������������֮ϸ������Ϸ�������£�
�µ����������ϸ�����ھ�С��һ�������ϸ������һ��״̬��������
ӵ�����������ϸ�����ھ����ĸ����ϣ����ϸ������һ��״̬��������
�ȶ������ϸ�����ھ�Ϊ����������������һ��״̬Ϊ�ȶ���
������ĳλ��ԭ��ϸ��������λ�õ��ھ�Ϊ���������λ�ý�����һϸ����

������Ϸ�Ĺ���ɼ�Ϊ���£���ʹ��CASE�ȶԼ���ʹ�ó�ʽʵ����
�ھӸ���Ϊ0��1��4��5��6��7��8ʱ�����ϸ���´�״̬Ϊ������
�ھӸ���Ϊ2ʱ�����ϸ���´�״̬Ϊ���
�ھӸ���Ϊ3ʱ�����ϸ���´�״̬Ϊ�ȶ���
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
