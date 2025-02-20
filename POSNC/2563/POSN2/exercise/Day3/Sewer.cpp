#include <iostream>
char s[100][100];
int v[100][100]={};
int a,b;
using namespace std;
/*void print_array(void){
      for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}*/
void path(int i,int j){
    if(i==a-1&i==b-1)
        return;
    v[i][j]++;
    if(s[i][j]=='R'){
        path(i,j+1);
    }
    if(s[i][j]=='D'){
        path(i+1,j);
    }
    if(s[i][j]=='B'){
        path(i,j+1);
        path(i+1,j);
    }
    if(s[i][j]=='N'){
        return;
    }
}

int main(){
    cin>>a>>b;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>s[i][j];
        }
    }
    path(0,0);
    int min=9999;
    int x,y;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(v[i][j]==2&&i+j-1<min){
                min=i+j-1;
                x=i;
                y=j;
            }
        }
    }
   // print_array();
    cout<<min+2<<endl<<x+1<<" "<<y+1;
}
