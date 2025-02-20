#include <iostream>
#include <vector>
#include <cstring>

//Time Complexity = O(m+n)
using namespace std;
vector<string> x;
void swap(char &a,char &b){
    char tmp=a;
    a=b;
    b=tmp;
}
void perm(char *p,int start,int len){
    if(len==0)
        x.push_back(p);
    for(int i=0;i<len;i++){
        swap(p[start],p[start+i]);
        perm(p,start+1,len-1);
        swap(p[start],p[start+i]);
    }
}
int main(){
    char s[256];
    strcpy(s,"1234567");
    perm(s,0,strlen(s));
    for(auto i:x){
        cout<<i<<endl;
    }
}
