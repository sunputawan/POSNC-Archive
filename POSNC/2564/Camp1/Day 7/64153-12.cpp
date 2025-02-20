#include <iostream>
#include <time.h>

using namespace std;
int roll(void){
   return rand()%6+1;
}
int main(){
    srand(time(NULL));
    int a[3];
    int sum=0;
    for(int i=0;i<3;i++){
        a[i]=roll();
        sum+=a[i];
        cout<<"dice"<<i+1<<" : "<<a[i]<<endl;
    }
    cout<<"three : "<<sum<<endl;
    if(a[0]==a[1]&&a[1]==a[2])
        cout<<"three of a kind";
    else if(sum<=10)
        cout<<"low";
    else
        cout<<"high";
}
