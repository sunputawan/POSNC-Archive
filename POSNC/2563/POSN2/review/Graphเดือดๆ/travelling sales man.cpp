#include <iostream>

using namespace std;
int edges[]={0,1,4,6,7,
             1,0,5,3,4,
             4,5,0,0,2,
             6,3,0,0,1,
             7,4,2,1,0};
int main(){
    int lower_bound=((1+4)+(1+3)+(2+4)+(1+3)+(1+2))/2;
    cout<<lower_bound;
}
