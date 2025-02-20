#include <stdio.h>
int i,j,m,n,g;
void gcd()
{
	for(i=1;i<=m;i++)
	{
		if(m%i==0)
			for(j=1;j<=n;j++)
				if(n%j==0)
					if(i==j)
						g=i;
	}
	printf("The great common divisor of m and n : %d", g);
}
int main(){
	printf("Please input m,n in form (m,n) :");
	scanf("%d%*c%d", &m,&n);
	gcd();
}


