#include <stdio.h>
char ch[12] = {'A','B','C','D','E','F','G','H','I','J','K','L'};
char *p;

int main(void)
{
  int x,y;
  p = ch;
  for(x=0;x<12;x++)
  {
  	y = x%3;
  	if ((x%4)<2)
  	{
     	p++;
     	printf("%c",*p++);
  	}
  	else
  	p++;
  	switch(y)
  	{
        	case 1 : p++;
                 	break;
        	case 2 : p--;
                 	break;
  	}
  }
  return 0;
}
