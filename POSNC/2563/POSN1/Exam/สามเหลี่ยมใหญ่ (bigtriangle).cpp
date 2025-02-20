#include <stdio.h>
#include <math.h>
struct pair{
	int x;
	int y;
};
float area(int x1,int y1,int x2,int y2,int x3,int y3){
	return fabs(0.5*float((x1*y2+x2*y3+x3*y1)-(y1*x2+y2*x3+y3*x1)));
}
typedef struct pair STP;
int main(){
	int n;
	scanf("%d", &n);
	STP p[n];
	float max;
	int i,j,k;
	for(i=0;i<n;i++)
		scanf("%d %d", &p[i].x,&p[i].y);

	max=area(p[0].x,p[0].y,p[1].x,p[1].y,p[2].x,p[2].y);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(k=j+1;k<n;k++){
			//	printf("%d %d %d : %f\n",i,j,k,area(p[i].x,p[i].y,p[j].x,p[j].y,p[k].x,p[k].y));
				if(area(p[i].x,p[i].y,p[j].x,p[j].y,p[k].x,p[k].y)>max){
					max=area(p[i].x,p[i].y,p[j].x,p[j].y,p[k].x,p[k].y);
				}
			}
		}
	}
	printf("%.3f",max);
}
