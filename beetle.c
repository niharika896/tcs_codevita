#include <stdio.h>
#include <stdlib.h>
struct pos{
    int x,y;
    char ch;
};

int main(){
    int m,a,b,i,j,x,y;
    scanf("%d,%d,%d",&m,&a,&b);
    struct pos matrix[m][m];
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
        scanf("%d%c%d;",&matrix[i][j].x,&matrix[i][j].ch,&matrix[i][j].y);
    }
    }
    struct pos fpos;
    scanf("%d,%d",&fpos.x,&fpos.y);
    fpos.x--;fpos.y--;
    for(i=0;i<a*b;i++){
        x=fpos.x;y=fpos.y;
        fpos.x=matrix[x][y].x;
        fpos.y=matrix[x][y].y;
    }
    printf("%d,%d",++fpos.x,++fpos.y);
    return 0;
}
