#include <stdio.h>

int mtx[8][8]={}, pre_x, pre_y;
int d[16] = {1, 2, 1, -2, -1, 2, -1, -2, 2, 1, 2, -1, -2, 1, -2, -1};

void expansion(int x, int y){
    for(int i = 0; i < 8; i++){
        if(x + d[2*i] == pre_x && y + d[2*i+1] == pre_y) //若走到了目標
            continue;
        else if(x + d[2*i] < 0 || x + d[2*i] > 7 || y + d[2*i+1] < 0 || y + d[2*i+1] > 7) //若超出格子邊界
            continue;
        else if(mtx[x + d[2*i]][y + d[2*i+1]] != 0 && mtx[x + d[2*i]][y + d[2*i+1]] <= mtx[x][y] + 1) //若已走過且步數小於上一步+1
            continue;
        else 
            mtx[x + d[2*i]][y + d[2*i+1]] = mtx[x][y] + 1;
        expansion(x + d[2*i], y + d[2*i+1]);
    }
}

int main(){
    int x1, y1, x2, y2;
    scanf("%d %d\n%d %d", &x1, &y1, &x2, &y2);
    pre_x = x1;
    pre_y = y1;
    expansion(x1, y1);
    printf("%d\n", mtx[x2][y2]);
}