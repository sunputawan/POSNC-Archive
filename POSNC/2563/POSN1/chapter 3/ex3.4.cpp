#include<stdio.h>
int A,B,C,m,Y;
int main(){
	printf("Please input 3 integers (A,B,C): ");
	scanf("%d%*c%d%*c%d", &A, &B, &C);
	printf("\n\tIn case m>5, Y=Am^2+Bm+C\n\tIn case m=5, Y=Am^2-Bm-C\n\tIn case m<5, Y=Am^2+Bm\n\nPlease input \"m\" : " );
	scanf("%d", &m);
	
	if(m>5)
	{
		Y=A*m*m + B*m + C;
		printf("Y=%d", Y);
	}
	else	if(m==5)
			{
				Y=A*m*m - B*m - C;
				printf("Y=%d", Y);
			}
			else
			{
				Y=A*m*m + B*m;
				printf("Y=%d", Y);
			}
}
