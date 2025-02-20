#include <iostream>
#include <time.h>

using namespace std;
int random(int l,int h){
    return rand()%h+l;
}
int main(){
    srand(time(NULL));
    int x=0;
    int target = random(1,100);
    int count=-1;
    while(x!=target){
        cout<<"Enter number (1-100) : ";
        cin>>x; count++;
    }
    cout<<"you guessed "<<count<<" time(s) wrong.";
}
