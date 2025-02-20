#include <iostream>
#include <vector>
using namespace std;
int a[400][400];
int x,y,m,n;
int count = 0;
vector<int> cnt;
void printarr(void){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            printf("%2d ",a[i][j]);
        cout<<endl;
    }
    cout<<endl;
}
void seek(int x,int y,char from){
    if(x<0||x>=m||y<0||y>=n) return;
    count++;
    int cur = a[x][y];

    if(cur==11){
        a[x][y] = 0;
        if(from=='u'){
            y--;
            from ='r';
        }
        if(from=='l'){
            x--;
            from ='d';
        }
    }
    if(cur==12){
        a[x][y] = 0;
        if(from=='u'){
            y++;
            from ='l';
        }
        if(from=='r'){
            x--;
            from ='d';
        }
    }
    if(cur==13){
        a[x][y] = 0;
        if(from=='l'){
            x++;
            from ='u';
        }
        if(from=='d'){
            y--;
            from ='r';
        }
    }
    if(cur==14){
        a[x][y] = 0;
        if(from=='d'){
            y++;
            from ='l';
        }
        if(from=='r'){
            x++;
            from ='u';
        }
    }
    if(cur==21){
        a[x][y] = 0;
        if(from=='u'){
            x++;
        }
        if(from=='d'){
            x--;
        }
    }
    if(cur==22){
        a[x][y] = 0;
        if(from=='l'){
            y++;
        }
        if(from=='r'){
            y--;
        }
    }
    if(cur==31){
        if(from=='l'){
            a[x][y] = 21;
            y++;
        }
        if(from=='u'){
            a[x][y] = 22;
            x++;
        }
        if(from=='r'){
            a[x][y] = 21;
            y--;
        }
        if(from=='d'){
            a[x][y] = 22;
            x--;
        }
    }
    seek(x,y,from);
}
void initializeTop(int x,int y){
    count = 0;
    seek(x,y,'u');
    cnt.push_back(count);
}
void initializeLeft(int x,int y){
    count = 0;
    seek(x,y,'l');
    cnt.push_back(count);
}
void initializeRight(int x,int y){
    count = 0;
    seek(x,y,'r');
    cnt.push_back(count);
}
void initializeBottom(int x,int y){
    count = 0;
    seek(x,y,'d');
    cnt.push_back(count);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int j=0;j<n;j++){
        if(a[0][j]==11||a[0][j]==12||a[0][j]==21||a[0][j]==31)
            initializeTop(0,j);
    }
    for(int j=0;j<n;j++){
        if(a[m-1][j]==13||a[m-1][j]==14||a[m-1][j]==21||a[m-1][j]==31)
            initializeBottom(m-1,j);
    }

    for(int i=0;i<m;i++){
        if(a[i][0]==11||a[i][0]==13||a[i][0]==22||a[i][0]==31)
            initializeLeft(i,0);
    }
    for(int i=0;i<m;i++){
        if(a[i][n-1]==12||a[i][n-1]==14||a[i][n-1]==22||a[i][n-1]==31)
            initializeRight(i,n-1);
    }


    cout<<cnt.size()<<endl;
    for(int i:cnt)
        cout<<i<<" ";
}
