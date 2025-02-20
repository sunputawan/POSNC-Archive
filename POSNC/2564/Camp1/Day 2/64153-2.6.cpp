#include <iostream>

using namespace std;
int main(){
    char c;
    cout<<"Enter a character : ";
    cin>>c;
    if(c<65||(c>90&&c<97)||c>122){
        cout<<"error";
        return 0;
    }
    if(c<=90)
        cout<<char(c+32);
    else
        cout<<char(c-32);
}
