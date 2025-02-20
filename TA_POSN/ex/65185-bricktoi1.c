#include <stdio.h>
char a[25][25];
int main()
{
    int n,m,i,j,brick;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++)
            scanf(" %c", &a[i][j]);
    }
    for(j=0; j<m; j++) {
        scanf("%d", &brick);
        for(i=0; i<n && a[i][j]!='O'; i++);
        while(i-- && brick--)
            a[i][j] = '#';
    }
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
/*
8 5
.....
.....
.OO..
.....
.O...
...O.
.....
.....
1 1 3 2 0
*/