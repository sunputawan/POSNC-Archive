#include <iostream>

using namespace std;
int main(){
    int n;
    cout<<"Enter a number : "; cin>>n;
    if(n<1||n>200) {cout<<"Invalid input!"; return 0;}
    int j=0;
    for(int i=1;i<=n;i++){
        int count=0;
        while(count!=i){
            if(j=='Z'+1-65) j='A'-65;
            cout<<char((j++)+65)<<" ";
            count++;
        }
        cout<<endl;
    }
}
