/*
��ʿ���߷��������Ͽ���ʹ�õݻ�����������Ǵ��\�ĵݻ���ά�ȴ�ʱ�൱û��Ч�ʣ�
һ�������Ľⷨ��J.C. Warnsdorff��1823��������򵥵�˵���Ƚ����ѵ�λ�����꣬��������·
�Ϳ���ˣ���ʿ��Ҫ�ߵ���һ������Ϊ��һ����ѡ��ʱ�������ߵĲ������ٵ�һ��������ʹ�����
�������ڲ�ʹ�õݻص�����£������нϸߵĻ����ҳ��߷����Ҳ����߷��Ļ���Ҳ���еģ�

*/

#include <stdio.h>

int board[8][8] = {0};

int main(void){
    int startx, starty;
    int i, j;
    printf("������ʼ�㣺");
    scanf("%d %d", &startx, &starty);

    if(travel(startx, starty)){
        printf("������ɣ�\n");
    }
    else{
        printf("����ʧ�ܣ�\n");
        }

    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            printf("%2d", board[i][j]);
        }
        putchar('\n');
    }

    return 0;
}

int travel(int x, int y){
    //��Ӧ��ʿ���ߵİ˸�����
    int ktmove1[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int ktmove2[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    //������һ���ĳ�·
    int nexti[8] = {0};
    int nextj[8] = {0};
    //��¼��·�ĸ���
    int exists[8] = {0};
    int i, j, k, m, l;
    int tmpi, tmpj;
    int count, min, tmp;

    i = x;
    j = y;
    board[i][j] = 1;

    for(m = 2; m <= 64; m++){
        for(l = 0; l < 8; l++)
            exists[1] = 0;

        l = 0;

        //��̽�˸�����
        for(k = 0; k < 8; k++){
            tmpi = i + ktmove1[k];
            tmpj = j + ktmove2[k];

            //����Ǳ߽��ˣ�������
            if(tmpi < 0 || tmpj <0 || tmpi > 7 || tmpj > 7)
                continue;

            //������������ߣ���¼����

            if(board[tmpi][tmpj] == 0){
                nexti[l] = tmpi;
                nextj[l] = tmpj;
                //���ߵķ����һ��
                l++;
            }
        }

        count = l;
        //������ߵķ���Ϊ0��������
        if(count == 0){
            return 0;
        }
        else if(count == 1){
            //ֻ��һ�����ߵķ���
            //����ֱ�������ٳ�·�ķ���
            min = 0;
        }
        else{
            //�ҳ���һ��λ�õĳ�·��
            for(l = 0; l < count; l++){
                for(k = 0; k < 8; k++){
                    tmpi = nexti[l] + ktmove1[k];
                    tmpj = nextj[l] + ktmove2[k];
                    if(tmpi < 0 || tmpj < 0 || tmpi > 7 ||tmpj > 7){
                        continue;
                    }
                    if(board[tmpi][tmpj] == 0)
                        exists[l]++;
                }
            }

            tmp = exists[0];
            min = 0;
            //�ӿ��ߵķ�����Ѱ�����ٳ�·�ķ���
            for(l = 1; l < count; l++){
                if(exists[l] < tmp){
                    tmp = exists[l];
                    min = l;
                }
            }
        }

        //�����ٳ�·�ķ���
        i = nexti[min];
        j = nextj[min];
        board[i][j] = m;
    }

    return l;
}
