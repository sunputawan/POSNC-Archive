#include <iostream>

using namespace std;
int main(){
    char c = 'A';
    int line=0;
    int size,length,width;
    cin>>size>>length>>width;
    while(line!=width){
        c='A'+line;
        if(c>='Z'+1)
            c-=26;
        for(int i=0;i<length;i++){
            if(c=='A'+size||c=='Z'+1){
                c='A';
            }
            cout<<c;
            c++;

        }
        line++;
        cout<<endl;
    }
}
