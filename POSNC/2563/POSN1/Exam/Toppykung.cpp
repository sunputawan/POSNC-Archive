#include <stdio.h>
#include <string.h>
struct m{
	char s[30];
	int rank;
	int enb;
};
typedef struct m STM;
int main(){
	int i,j,k,n,count=0;
	scanf("%d", &n);
	STM a[n];
	for(i=0;i<n;i++){
		scanf("%s", a[i].s);
		a[i].rank=1;
		a[i].enb=1;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j||a[j].enb==0)
				continue;
			else if(strcmp(a[i].s,a[j].s)==0){
				a[j].s[0]=123;
				a[j].enb=0;
				a[j].rank=n+1;
			}
			else{
				for(k=0;k<30;k++){
					if(a[i].s[k]>a[j].s[k]){
						a[i].rank++;
						break;
					}
					else if(a[i].s[k]<a[j].s[k])
						break;
				}
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d %d\n", i,a[i].rank);
	}
	printf("\n\n");
	for(i=1;i<=n;i++){
		for(j=0;j<n;j++){
			if(a[j].rank==i&&a[j].enb==1)
				printf("%s\n", a[j].s);
		}
	}
}
