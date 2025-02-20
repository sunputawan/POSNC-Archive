#include <iostream>
#include <string.h>

using namespace std;
int main(){
    char s[100];
    int a=0,e=0,ii=0,o=0,u=0;
    cout<<"Input String 1   ==> "; gets(s);
    cout<<"Length of String ==> "<<strlen(s)<<" charaters";
    cout<<"\nReverse String   ==> ";
    for(int i=strlen(s)-1;i>=0;i--) cout<<s[i];
    cout<<"\nUpper String     ==> ";
    for(int i=0;i<strlen(s);i++){
        if('a'<=s[i]&&s[i]<='z'){
            s[i]-=32;
        }
        switch(s[i]){
            case 'A':{
                a++; break;
            }
            case 'E':{
                e++; break;
            }
            case 'I':{
                ii++; break;
            }
            case 'O':{
                o++; break;
            }
            case 'U':{
                u++; break;
            }
        }
        cout<<char(s[i]);
    }
    cout<<"\n=-=-=-=-=-=-=-=-=-=\nNumber of Vowel\n";
    cout<<"=-=-=-=-=-=-=-=-=-=\n";
    cout<<"A or a = "<<a<<endl;
    cout<<"E or e = "<<e<<endl;
    cout<<"I or i = "<<ii<<endl;
    cout<<"O or o = "<<o<<endl;
    cout<<"U or u = "<<u<<endl;
    cout<<"=-=-=-=-=-=-=-=-=-=\n";
}
