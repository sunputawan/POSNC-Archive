#include <iostream>

using namespace std;
int main(){
    FILE *fp;
    fp = fopen("001.txt","w");
    for(int i=0;i<10;i++){
        int x;
        scanf("%d", &x);
        fprintf(fp,"%d\n",x);
    }
    fclose(fp);
}
