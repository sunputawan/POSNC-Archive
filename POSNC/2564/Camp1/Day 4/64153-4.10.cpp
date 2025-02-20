#include <iostream>

using namespace std;
int main(){
    int n;
    cout<<"Enter a number : "; cin>>n;
    if(n<1||n>200) {cout<<"Invalid input!"; return 0;}
    int j=0;
    for(int i=1;i<=n;i++){
        int count=0;
        j+=i;
        j%=26;
        int character=j;
        while(count!=i){
            if(character<1) character=26;
            cout<<char(character--+64);
            count++;
        }
        cout<<endl;
    }
}
