#include <iostream>

using namespace std;
int I=0,V=0,X=0,L=0,C=0;
void hundred(int x){
    switch(x){
        case 3:
            C++;
        case 2:
            C++;
        case 1:
            C++;
    }
}
void ten(int x){
    switch(x){
        case 9:{
            C++;
            X++;
            break;
        }
        case 4:{
            L++;
            X++;
            break;
        }
        case 8:
            X++;
        case 7:
            X++;
        case 6:
            X++;
        case 5:{
            L++;
            break;
        }
        case 3:
            X++;
        case 2:
            X++;
        case 1:
            X++;
    }
}
void one(int x){
    switch(x){
        case 9:{
            X++;
            I++;
            break;
        }
        case 4:{
            V++;
            I++;
            break;
        }
        case 8:
            I++;
        case 7:
            I++;
        case 6:
            I++;
        case 5:{
            V++;
            break;
        }
        case 3:
            I++;
        case 2:
            I++;
        case 1:
            I++;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int tmp=i;
        hundred(i/100);
        i%=100;
        ten(i/10);
        i%=10;
        one(i);
        i=tmp;
    }
    cout<<I<<" "<<V<<" "<<X<<" "<<L<<" "<<C;
}
