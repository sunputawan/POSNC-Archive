#include <stdio.h>
int x,y,z,t,i;
char str[3];
int display[3];
int main(){
	printf("Please input three differentpositive integers : ");
	scanf("%d%d%d", &x,&y,&z);
	if(x==y || y==z || z==x)
	{
	 printf("The integer must be different, please try again!");
	}
	else
	{	
		if(x>y)
		{
			t=x;
			x=y;
			y=t;
		}
		if(x>z)
		{	t=x;
			x=z;
			z=t;
		}
		if(y>z)
		{	t=y;
			y=z;
			z=t;
		} 	//After this 3 command x will contain the minnimum value and z contain the maximum.
		printf("Please input a permutable \"ABC\" : ");
		scanf("%s", str);
		for(i=0;i<3;++i)
		{
			if(str[i]=='A')
				display[i]=x;
			else if(str[i]=='B')
					display[i]=y;
			else if(str[i]=='C')
					display[i]=z;
		}
		printf("%d %d %d\n", display[0],display[1], display[2]);
	}
}	
