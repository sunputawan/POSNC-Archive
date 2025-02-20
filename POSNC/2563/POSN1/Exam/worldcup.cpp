#include <stdio.h>
struct score{
	char name[20];
	int t[4];
	int point;
	int goal;
	int goaled;
	int rank;
}team[4];
void swaprank(int *,int *);
int main(){
	int i,j;
	for(i=0;i<4;i++){
		scanf("%s", team[i].name);
		team[i].point=0;
		team[i].rank=4;
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			scanf("%d", &team[i].t[j]);
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(i==j)
				continue;
			else if(team[i].t[j]>team[j].t[i])
				team[i].point+=3;
			else if(team[i].t[j]==team[j].t[i])
				team[i].point++;
		}
	}
	for(i=0;i<4;i++)
		for(j=0;j<4;j++){
			team[i].goal+=team[i].t[j];
			team[i].goaled+=team[j].t[i];
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(i==j)
				continue;
			int *x,*y;
			x=&team[i].rank;
			y=&team[j].rank;
			if(team[i].point>team[j].point){
					team[i].rank--;
			}
			else if(team[i].point==team[j].point){
				if((team[i].goal-team[i].goaled)>(team[j].goal-team[j].goaled)){
					team[i].rank--;
				}
				else if((team[i].goal-team[i].goaled)==(team[j].goal-team[j].goaled)){
					if(team[i].goal>team[j].goal){
						team[i].rank--;
					}
				}
			}
		}
	}
	for(i=1;i<=4;i++){
		for(j=0;j<4;j++){
			if(team[j].rank==i){
				printf("%s %d\n", team[j].name,team[j].point);
			}
		}
	}
}
void swaprank(int *a,int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
