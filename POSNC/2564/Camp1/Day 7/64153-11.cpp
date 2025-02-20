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
    int count=0;
    bool is_first_time = true;
    while(x!=target){
        cout<<"Enter number (1-100) : ";
        cin>>x;
        if(x==target) break;
        if(x<target) cout<<"The number is too low. Try again.";
        else if(x>target) cout<<"The number is too high. Try again.";
        is_first_time = false;
    }
    cout<<"Correct !!!";
    if(is_first_time) cout<<"\nExactly right.";
}
