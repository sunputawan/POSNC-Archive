#include <iostream>

using namespace std;
int tower_of_hanoi(int n){
    if(n==1)
        return 1;
    else
        return 2*tower_of_hanoi(n-1)+1;
}
int main(){
    int n;
    cin>>n;
    cout<<tower_of_hanoi(n);
}
