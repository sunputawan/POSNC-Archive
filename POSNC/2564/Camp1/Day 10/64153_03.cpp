#include <iostream>

using namespace std;
int main(){
    FILE *fp1,*fp2,*fp3;
    fp1 = fopen("001.txt","r");
    fp2 = fopen("002.txt","r");
    fp3 = fopen("003.txt","w");

    for(int i=0;i<10;i++){
        int x,y;
        fscanf(fp1,"%d",&x);
        fscanf(fp2,"%d",&y);
        fprintf(fp3,"%d\n",x+y);
        //cout<<x<<" "<<y<<endl;
    }
}
