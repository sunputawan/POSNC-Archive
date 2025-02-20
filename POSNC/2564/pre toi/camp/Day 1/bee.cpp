#include <bits/stdc++.h>

using namespace std;
struct bee{
    int a,b,c;
}year[30];
int main(){
    year[0] = {1,0,1};
    for(int i=1;i<=25;i++){
        year[i].a = year[i-1].a;
        year[i].b = year[i-1].c;
        year[i].c = year[i-1].a+year[i-1].b+year[i-1].c;
    }
    int x;
    while(true){
        cin>>x;
        if(x==-1) break;
        cout<<year[x].c<<" "<<year[x].a+year[x].b+year[x].c<<endl;
    }
    return 0;
}
