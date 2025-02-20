#include <iostream>
#include <string.h>

using namespace std;
int main(){
    int num=0,con=0,vow=0;
    char s[1000];
    cout<<"Enter string : "; cin>>s;
    for(int i=0;i<strlen(s);i++){
        if('0'<=s[i]&&s[i]<='9') num++;
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
            vow++;
            continue;
        }
        if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
            vow++;
            continue;
        }
        if(('A'<=s[i]&&s[i]<='Z')||('a'<=s[i]&&s[i]<='z')) con++;
    }
    cout<<"Length : "<<strlen(s)<<endl;
    cout<<"Number : "<<num<<endl;
    cout<<"Consonant : "<<con<<endl;
    cout<<"Vowel : "<<vow<<endl;
}
